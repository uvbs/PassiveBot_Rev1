#pragma once
#include "ADTCache.h"
#include "ChunkCache.h"
#include "Area.h"
using namespace std;


class Chunk;

class Area;
class ADTWorker
{
	static vector <shared_ptr<ADT>> adts;
public:
	static Chunk * GetChunk(Area * area,Location & location, Point2D<int> block_coordinates, Point2D<int>coordinates,bool save=false);
	static shared_ptr<ADT>  GetADT(Location & location, Point2D<int> coordinates);
	static void Clear();
};

