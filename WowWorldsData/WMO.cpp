#include "stdafx.h"
#include "WMO.h"

void WMO::_move(WMO & other)
{
	MapObject::swap(other);
	bounding_box = other.bounding_box;
	position = other.position;
	uuid = other.uuid;
	other.uuid = 0;
}

WMO::WMO(string filename, unsigned uuid, Position & position):
	MapObject(filename),
	uuid(uuid)// ,position(position)
{
	//this->position = position;
	WMORoot root = WMORoot(this->name);
	this->position.coords = Vector3(position.coords.z, position.coords.x, position.coords.y);
	this->position.rotation = Vector3(position.rotation.z, position.rotation.x, position.rotation.y);
	for (auto &group : root.GetGroups())
	{
		vertex_count += group.GetVertexCount();
		index_count += group.GetIndexCount();
	}
	vertices = new float[vertex_count * 3];
	indices = new int[index_count];
	unsigned vc = 0;
	unsigned ic = 0;
	unsigned offset = 0;
	float * gvertices = nullptr;
	for (auto &group : root.GetGroups())
	{
		//memcpy(vertices + offset, group.GetVertices(), group.GetVertexCount() * 12);
		gvertices = group.GetVertices();
		for (unsigned i = 0; i < group.GetVertexCount()*3; i += 3)
		{
			vertices[offset+i] = gvertices[i];
			vertices[offset+i+1] = gvertices[i+2];
			vertices[offset+i+2] = gvertices[i+1];
		}




		offset += group.GetVertexCount() * 3;


		//for (unsigned long i = 0; i < group.vertex_count; i++)
		//{
		//	rvertices[vc] = group.vertices[i].x;// +this->position.coords.x;
		//	rvertices[vc + 1] = group.vertices[i].y;// +this->position.coords.z;
		//	rvertices[vc + 2] = group.vertices[i].z;// +this->position.coords.y;
		//	vc += 3;
		//}
	}
	//vertices = nullptr;
	Rotate();
	for (unsigned i = 0; i < vertex_count * 3; i += 3)
	{
		vertices[i]+= this->position.coords.x;
		vertices[i+1]+= this->position.coords.z;
		vertices[i+2] += this->position.coords.y;
	}
	unsigned vert_offset = 0;
	for (auto &group : root.GetGroups())
	{
		for (unsigned long i = 0; i < group.GetIndexCount(); i += 3)
		{
			indices[ic] = group.GetIndices()[i+2] + vert_offset;
			indices[ic + 1] = group.GetIndices()[i + 1] + vert_offset;
			indices[ic + 2] = group.GetIndices()[i] + vert_offset;
			ic += 3;
		}
		vert_offset += group.GetVertexCount();
	}




	//for (auto &part : parts)
	//{
	//		part.Rotate();
	//}
	//unsigned vc = 0;
	//unsigned ic = 0;
	//rvertices = new float[vertex_count * 3];
	//indices = new int[index_count];
	//for (auto &part : parts)
	//{
	//	//part.Rotate();
	//	for (unsigned long i = 0; i < part.GetVertexCount(); i++)
	//	{
	//		rvertices[vc] = part.GetVertices()[i].position.x + this->position.coords.x;
	//		rvertices[vc + 1] = part.GetVertices()[i].position.z + this->position.coords.z;
	//		rvertices[vc + 2] = part.GetVertices()[i].position.y + this->position.coords.y;
	//		vc += 3;
	//	}
	//}
	//unsigned vert_offset = 0;
	//for (auto &part : parts)
	//{
	//	for (unsigned long i = 0; i < part.GetIndexCount();i+=3)
	//	{
	//		indices[ic] = part.GetIndices()[i+2] + vert_offset;
	//		indices[ic+1] = part.GetIndices()[i+1] + vert_offset;
	//		indices[ic+2] = part.GetIndices()[i] + vert_offset;
	//		ic += 3;
	//	}
	//	vert_offset += part.GetVertexCount();
	//}
	

	rcCalcBounds(vertices, vertex_count, bounding_box.GetArrayMin(), bounding_box.GetArrayMax());
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

WMO::WMO(WMO && right)
{

	//_move(right);
	bounding_box = right.bounding_box;
	MapObject::operator=(move(right));
	position = right.position;
	uuid = right.uuid;
	right.uuid = 0;

}


WMO::~WMO()
{
}

WMO & WMO::operator=(WMO && right)
{
	//_move(right);
	bounding_box = right.bounding_box;
	MapObject::operator=(move(right));
	position = right.position;
	uuid = right.uuid;
	right.uuid = 0;
	return *this;
}
