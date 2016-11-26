#pragma once
#include "WowWorldsData\WowWorldsData.h" 


class CTX :public rcContext
{
public:
	CTX() :rcContext() {}
	virtual void doLog(const rcLogCategory category, const char* msg, const int len)
	{
		cout << msg << endl;
	}
};



class GlobalNavMesh
{
	BoundingBox bbox;
	NavConfig config;
	dtNavMesh * nav_mesh;

	unsigned char* m_triareas=nullptr;
	rcHeightfield* m_solid=nullptr;
	rcCompactHeightfield* m_chf = nullptr;
	rcContourSet* m_cset = nullptr;
	rcPolyMesh* m_pmesh = nullptr;
	rcPolyMeshDetail* m_dmesh = nullptr;
	rcConfig m_cfg;
	CTX * m_ctx = nullptr;
	vector<rcPolyMesh*> poly_meshes;

	Area * area;


	unsigned char * BuildTileMesh(int x, int y, const float* bmin, const float* bmax, int & dataSize);
	void Cleanup();

public:
	GlobalNavMesh();
	~GlobalNavMesh();
	void InitConfig();
	void Start(int x, int y);
	void AddTile(Point2D<int> coordinates);
	inline dtNavMesh * GetNavMesh() { return nav_mesh; }
	inline vector<rcPolyMesh*> & GetPolyMeshes() { return poly_meshes; }
};

