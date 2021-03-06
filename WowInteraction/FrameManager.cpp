#include "stdafx.h"

#include "FrameManager.h"
using namespace Tools;

vector<Frame*> FrameManager::frames = vector<Frame*>();
float FrameManager::screen_heigth = 0;
float FrameManager::screen_width = 0;
Frame FrameManager::QuestScrollFrame;
Frame FrameManager::AllQuestButtonFrame;
Frame FrameManager::QuestListFrame;
void FrameManager::InitKnownFrames()
{
	unsigned base_frame;
	unsigned current;
	ClearFrames();
	try
	{
		base_frame = Process::ReadRel<unsigned>(WowOffsets2::FrameManager2::FrameBase);
		current = Process::Read<unsigned>(base_frame + WowOffsets2::FrameManager2::FirstFrame);
	}
	catch (MemoryReadException e)
	{
		throw FrameEnumerationException();
	}
	while (current)
	{
		try
		{
			Frame * frame = new Frame(current);
			if (frame->GetName() == "QuestScrollFrame")
			{
				QuestScrollFrame = *frame;
			}
			frames.push_back(frame);
			current = Process::Read<unsigned>(current + Process::Read<unsigned>(base_frame + WowOffsets2::FrameManager2::NextFrame) + 4);
		}
		catch (MemoryReadException e)
		{
			break;
		}
	}
	AllQuestButtonFrame=*QuestScrollFrame.GetChildren()[1];
	QuestListFrame= *QuestScrollFrame.GetChildren()[3];

}
FrameManager::FrameManager(void)
{

}


FrameManager::~FrameManager(void)
{
}
vector <Frame*> & FrameManager::GetFrames()
{
	return frames;
}
void FrameManager::EnumAllFrames()
{
	unsigned base_frame;
	unsigned current;
	ClearFrames();
		try
		{
			base_frame = Process::ReadRel<unsigned>(WowOffsets2::FrameManager2::FrameBase);
			current = Process::Read<unsigned>(base_frame + WowOffsets2::FrameManager2::FirstFrame);

		}
		catch (MemoryReadException e)
		{
			throw FrameEnumerationException();
		}
		while (current)
		{
			try
			{
				Frame * frame = new Frame(current);
				frames.push_back(frame);
				current = Process::Read<unsigned>(current + WowOffsets2::FrameManager2::NextFrame);
			}
			catch (MemoryReadException e)
			{
				break;
			}
		}
}
void FrameManager::DumpAllFramesNames()
{
	cout << "Frame Names " << frames.size() << endl;
	for (auto frame : frames)
	{
		cout << frame->GetName() << endl;
	}
	cout << frames.size();
}
void FrameManager::ClearFrames()
{
	for (auto frame : frames)
	{
		delete frame;
	}
	frames.clear();
}
void FrameManager::FindParents()
{
	unsigned parent_ptr;
	for (auto frame : frames)
	{
		for (auto frame2 : frames)
		{
			parent_ptr = Process::Read<unsigned>(frame->GetBase() + WowOffsets2::FrameManager2::FrameParent);
			if (parent_ptr == frame2->GetBase())
			{
				frame->SetParent(frame2);
				break;
			}
		}
	}
}
float FrameManager::GetScreenWidth(bool refresh)
{
	if (!screen_width || refresh)
	{
		screen_width = Process::ReadRel<float>(WowOffsets2::FrameManager2::ScreenWidth);
	}
	return screen_width;
}
float FrameManager::GetScreenHeigth(bool refresh)
{
	if (!screen_heigth || refresh)
	{
		screen_heigth = Process::ReadRel<float>(WowOffsets2::FrameManager2::ScreenHeight);
	}
	return screen_heigth;
}
Frame * FrameManager::FindFrameByName(const string &  name, bool refresh)
{
	if (frames.size()==0 ||  refresh)
		EnumAllFrames();
	for (auto frame : frames)
	{
		if (frame->GetName() == name)
		{

			return frame;
		}
	}
	return 0;
}
Frame * FrameManager::FindFrameByAddress(unsigned address)
{
	for (auto frame : frames)
	{
		if (address == frame->GetBase())
		{
			return frame;
		}
	}
	return 0;
}

Frame * FrameManager::FindFrameByBorders(float bottom, float top, float left, float right)
{
	for (auto frame : frames)
	{
		if (bottom == frame->GetBottom() && top == frame->GetTop() && left == frame->GetLeft() && right == frame->GetRight())
		{
			return frame;
		}
	}
	return nullptr;
}

shared_ptr<Region> FrameManager::FindRegionWithText(wstring text)
{
	for (auto frame : frames)
	{
		for (auto & region : frame->GetRegions())
		{
			if (region->GetWText() == text)
			{
				return region;
			}
		}
	}
	return nullptr;
}


