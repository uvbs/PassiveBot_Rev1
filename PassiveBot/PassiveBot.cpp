// PassiveBot.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include "AutoItX3_DLL.h"
//#include "boost\thread\thread.hpp"
#include <thread>
#include <random>
using namespace std;
using namespace Wow;
using namespace Utils;
using namespace Tools;

void workerFunc(MapFrame * frame,Position pos)  
{  
	
	frame->go();
	frame->SetCamera(pos);

}
void init_static()
{
	Utils::Geometry::Transformer3D::Transformer3D();
	Game::LocationBase::Init();
}

int main(int argc, wchar_t * argv[])
{
	init_static();
	setlocale( LC_ALL,"Russian" );
	Sleep(5000);

	

	BotInteractor::StartGame("lissek7@ya.ru", "lebmat2762066", L"���������");
	MapFrame frame = MapFrame();
	frame.SetArea(BotInteractor::GetArea());
	thread thr = thread(workerFunc, &frame, ObjectManager::GetPlayer()->GetPosition());
	thr.detach();

	//GameManager::RotatePlayer(ObjectManager::FindUnitByName(L"�����")->GetPosition().coords);
	//BotInteractor::GoToPoint(*ObjectManager::FindUnitByName(L"����"));

	
	default_random_engine generator;
	uniform_int_distribution<int> distribution(0, ObjectManager::GetUnitsList()->size()-1);
	while (1)
	{
		/*int random_variable = distribution(generator);
		Unit * unit = (*ObjectManager::GetUnitsList())[random_variable];
		wcout << unit->GetName() << endl;;
		BotInteractor::GoToPoint(*unit);*/
		BotInteractor::PulseCheck();
		Sleep(50);
	}


	while (1)
	{
		Sleep(100);
	}
	
	
	//cin >> pos;

	return 0;

}

