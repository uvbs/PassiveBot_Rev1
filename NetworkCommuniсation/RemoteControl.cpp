#include "stdafx.h"
#include "RemoteControl.h"


RemoteControl::RemoteControl():RemoteControl("127.0.0.1", 8001)
{
	

}

RemoteControl::RemoteControl(string address, unsigned short port)
{
	server = NetworkCommunicatorServer(address,port);
	recieved_packet = nullptr;
	packet_to_send = nullptr;
	packet_to_send_size = 0;
}


RemoteControl::~RemoteControl()
{
}

void RemoteControl::ProcessRequest()
{
	on_receive_mutex.lock();
	if (recieved_packet)
	{
		cout << "PROCESS_REQUEST" << endl;
		packet_to_send = ProcessRequest(recieved_packet);
		
		delete [] recieved_packet;
		recieved_packet = nullptr;
	}
	on_receive_mutex.unlock();
	
	
}

char ** RemoteControl::ProcessPacket(char * packet,unsigned & size)
{
	on_receive_mutex.lock();
	recieved_packet = packet;
	on_receive_mutex.unlock();
	bool release = false;
	while (!release )
	{
		on_receive_mutex.lock();
		if (!recieved_packet)
		{
			release = true;
		}
		on_receive_mutex.unlock();
		cout << "WAINTING!!!!!!!" << endl;
		Sleep(1);
	}
	cout << "continue!!!" << endl;
	size = packet_to_send_size;
	return &packet_to_send;
}

char * RemoteControl::ProcessRequest(char * packet)
{
	//unsigned type = packet->type;
	unsigned type = *reinterpret_cast<unsigned*>(packet + 4);
	char * reply = nullptr;
	switch (type)
	{
	case Request::PlayerPosition:
	{
		PlayerPositionReply * rp = new PlayerPositionReply;
		rp->header.size = sizeof(*rp);
		Position pos = ObjectManager::GetPlayer()->GetPosition();
		rp->position = pos.coords;
		rp->rotation = pos.rotation;
		reply = reinterpret_cast<char*>(rp);
		packet_to_send_size = rp->header.size;
		break;
	}
	case Request::TargetInfo:
	{
		TargetObjectInfoReply * rp = new TargetObjectInfoReply;
		rp->header.size = sizeof(*rp);
		WowObject * obj = ObjectManager::GetTargetObject();
		if (obj)
		{
			rp->type = obj->GetType();
			rp->guid = *obj->GetGuid();
			rp->entity_id = obj->GetID();
			wstring  name = obj->GetName();
			rp->name.length = name.size() * 2;
			memcpy(rp->name.str, name.c_str(), (name.size() + 1) * 2);
			rp->position = obj->GetPosition();
			
		}
		else
		{
			rp->type = 0;
		}
		reply = reinterpret_cast<char*>(rp);
		packet_to_send_size = rp->header.size;
		break;
	}
	case Request::Logout:
	{
		BoolRequestResult * rp = new BoolRequestResult;
		rp->header.size = sizeof(*rp);
		rp->result = AddonInteractor::Logout();
		reply = reinterpret_cast<char*>(rp);
		packet_to_send_size = rp->header.size;
		break;
	}
	case Request::TargetQuestGiverQuestList:
	{
		TargerQuestGiverQuestListReply * rp = new TargerQuestGiverQuestListReply;
		rp->header.size = sizeof(*rp);
		TargerQuestGiverInteractionResult result= AddonInteractor::GetCurrentInteractionQuests();
		rp->count = result.infos.size();
		if (rp->count)
		{
			for (int i = 0; i < result.infos.size(); i++)
			{
				rp->list[i].name.length = result.infos[i].title.size() * 2;
				memcpy(rp->list[i].name.str, result.infos[i].title.c_str(), (result.infos[i].title.size() + 1) * 2);
			}
			if (result.quest_detail_triggered)
			{
				rp->quest_detail_triggered = 1;
				rp->id = result.infos[0].id;
			}
		}
		reply = reinterpret_cast<char*>(rp);
		packet_to_send_size = rp->header.size;
		break;
	}
	case Request::SelectQuestFromList:
	{
		SelectFromQuestListReply *rp = new SelectFromQuestListReply;
		rp->header.size = sizeof(*rp);
		SelectedGossipQuestInfo info= AddonInteractor::GetSelectedQuest();
		rp->id = info.id;
		memcpy(rp->name.str, info.title.c_str(), (info.title.size() + 1) * 2);
		reply = reinterpret_cast<char*>(rp);
		packet_to_send_size = rp->header.size;
		break;
	}
	case Request::TargetEntityID:
		TargetEntityIDReply * rp = new TargetEntityIDReply;
		rp->header.size = sizeof(*rp);
 		WowObject * obj = ObjectManager::GetTargetObject();
		if (obj)
			rp->id = obj->GetID();
		else
			rp->id = 0;
		reply = reinterpret_cast<char*>(rp);
		packet_to_send_size = rp->header.size;
		break;
	}
	return reply;
}
void RemoteControl::Start()
{
	server_thread = thread(&NetworkCommunicatorServer::Start, server,this);
	server_thread.detach();
	//server.Start(this);
}


