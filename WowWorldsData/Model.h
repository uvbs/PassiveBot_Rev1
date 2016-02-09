#pragma once
#include "Utils.h"

using namespace Utils;


class ModelVertBase
{
	
protected:
	Utils::Graphics::Vertex * vertices;
	unsigned long vertex_count;
	
	
public:
	Position position;
	float * rvertices = 0;
	ModelVertBase(ModelVertBase && right);
	ModelVertBase(void);
	~ModelVertBase(void);
	ModelVertBase & operator=(ModelVertBase && right);
	virtual Utils::Graphics::Vertex * GetVertices() { return vertices; }
	virtual unsigned long GetVertexCount() { return vertex_count; }
	virtual Position GetPosition() { return position; }
	void SetPosition(Position position) { this->position = position; }
	inline void SetPosition(Vector3 & position) { this->position.coords = position; }
	virtual void Rotate();
	virtual void Rescale(float scale);
};
class ModelIndBase
{
	
protected:
	int * indices;
	unsigned long index_count;
public:
	ModelIndBase(ModelIndBase && right)
	{
		indices = right.indices;
		index_count = right.index_count;
		right.indices = nullptr;
		right.index_count = 0;
	}
	ModelIndBase(void)
	{
		indices = 0;
		index_count = 0;

	}
	~ModelIndBase(void)
	{
		delete [] indices;
		indices = 0;
		index_count = 0;
	}
	ModelIndBase & operator=(ModelIndBase && right)
	{
		indices = right.indices;
		index_count = right.index_count;
		right.indices = nullptr;
		right.index_count = 0;
		return *this;
	}
	virtual int * GetIndices() { return indices; }
	virtual unsigned long GetIndexCount() { return index_count; }
};
class Model
{
	


	void _move(Model & other);
public:
	Utils::Graphics::Vertex * vertices;
	unsigned long vertex_count=0;
	int * indices;
	unsigned long index_count=0;
	Position position;
	float * rvertices = 0;
	virtual Utils::Graphics::Vertex * GetVertices() { return vertices; }
	virtual unsigned long GetVertexCount() { return vertex_count; }
	virtual Position GetPosition() { return position; }
	void SetPosition(Position position) { this->position = position; }
	inline void SetPosition(Vector3 & position) { this->position.coords = position; }
	virtual void Rotate();
	virtual void Rescale(float scale);
	virtual int * GetIndices() { return indices; }
	virtual unsigned long GetIndexCount() { return index_count; }

	string name;
	Utils::Graphics::BoundingBox bounding_box;
	Model();
	Model(Utils::Graphics::BoundingBox bounding_box);
	~Model();
	Model(Model&) = delete;
	Model & operator=(Model &) = delete;

	Model & operator=(Model && right);
	inline Utils::Graphics::BoundingBox & GetBoundingBox() {return bounding_box;}
};


