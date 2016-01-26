#pragma once
#include "MapFrame.h"
#include "WowWorldsData\NavArea.h"
#include "MutableArea.h"
#include <thread>
#include <mutex>
using namespace std;



class WorldViewer
{

	MapFrame frame;
	thread frame_thread;
	mutex area_mutex;
	MutableArea area;
public:
	WorldViewer(Location * location, Point2D<int> block_coordinates, Point2D<int> coordinates, int radius);
	WorldViewer(WorldViewer && other);
	~WorldViewer();
	void ShowMap();
	void Update(Location * location, Point2D<int> block_coordinates, Point2D<int> coordinates);
	WorldViewer & operator=(WorldViewer && other);
};
