#include "stdafx.h"



void WMO::_move(WMO & other)
{
	MapObject::swap(other);
	bounding_box = other.bounding_box;
	position = other.position;
	uuid = other.uuid;
	other.uuid = 0;
	skip = other.skip;
}

WMO::WMO(string filename, unsigned uuid, Position position) :
	MapObject(filename),
	uuid(uuid), position(position)
{
	skip = false;
	WMORoot root = WMORoot(this->filename);
	this->position.coords = Vector3(this->position.coords.x, -this->position.coords.z, this->position.coords.y);
	parts = vector<WMOPart>();
	for (auto &group : root.GetWMOGroups())
	{
		parts.push_back(WMOPart(group, *this));
	}
	for (auto &part : parts)
	{
			//part.Rotate();
	}
	for (auto &part : parts)
	{
		vertex_count += part.GetVertexCount();
		index_count += part.GetIndexCount();
	}
	unsigned vc = 0;
	unsigned ic = 0;
	rvertices = new float[vertex_count * 3];
	indices = new int[index_count];
	for (auto &part : parts)
	{
		part.Rotate();
		for (unsigned long i = 0; i < part.GetVertexCount(); i++)
		{
			rvertices[vc] = part.GetVertices()[i].position.x + this->position.coords.x;
			rvertices[vc + 1] = part.GetVertices()[i].position.z + this->position.coords.z;
			rvertices[vc + 2] = part.GetVertices()[i].position.y + this->position.coords.y;
			vc += 3;
		}
	}
	//Rotate();
	unsigned vert_offset = 0;
	for (auto &part : parts)
	{
		for (unsigned long i = 0; i < part.GetIndexCount();i+=3)
		{
			indices[ic] = part.GetIndices()[i+2] + vert_offset;
			indices[ic+1] = part.GetIndices()[i+1] + vert_offset;
			indices[ic+2] = part.GetIndices()[i] + vert_offset;
			ic += 3;
		}
		vert_offset += part.GetVertexCount();
	}
	

	rcCalcBounds(rvertices, vertex_count, bounding_box.GetArrayMin(), bounding_box.GetArrayMax());
	//vector<float> points = vector<float>();
	//for (auto &part : parts)
	//{
	//	points.push_back(part.GetBoundingBox().up.x);
	//	points.push_back(part.GetBoundingBox().up.y);
	//	points.push_back(part.GetBoundingBox().up.z);
	//	points.push_back(part.GetBoundingBox().down.x);
	//	points.push_back(part.GetBoundingBox().down.y);
	//	points.push_back(part.GetBoundingBox().down.z);
	//}
	//rcCalcBounds(&points[0], points.size() / 3, bounding_box.GetArrayMin(), bounding_box.GetArrayMax());



}

WMO::WMO(WMO && right):parts(std::move(right.parts))
{

	//_move(right);
	bounding_box = right.bounding_box;
	MapObject::operator=(move(right));
	position = right.position;
	uuid = right.uuid;
	right.uuid = 0;
	skip = right.skip;

}


WMO::~WMO()
{
	parts.clear();
}

WMO & WMO::operator=(WMO && right)
{
	//_move(right);
	bounding_box = right.bounding_box;
	MapObject::operator=(move(right));
	position = right.position;
	uuid = right.uuid;
	right.uuid = 0;
	skip = right.skip;
	return *this;
}
