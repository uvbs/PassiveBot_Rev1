#include "stdafx.h"

namespace Utils
{
	Point2D<int> WorldPositionToBlockCoords(Vector3 position)
	{
		return Point2D<int>(floor((32.0f - (position.x / (Metrics::BlockSize)))),floor((32.0f - (position.y / (Metrics::BlockSize)))));
	}
	Point2D<float> BlockCoordsToWorldPosition(Point2D<int> coords)
	{
		return Point2D<float>((32-coords.X)*Metrics::BlockSize,(32-coords.Y)*Metrics::BlockSize);
	}
	Point2D<int> WorldPositionToChunkCoords(Vector3 position)
	{
		Point2D<int> block_coords=WorldPositionToBlockCoords(position);
		Point2D<float> block_position=BlockCoordsToWorldPosition(block_coords);
		Point2D<int> r = Point2D<int>(floor(abs(position.x-block_position.X)/Metrics::ChunkSize),floor(abs(position.y-block_position.Y)/Metrics::ChunkSize));
		return r;
	}
	Point2D<int> ToGlobalChunkCoords(Point2D<int> & block_coordinates, Point2D<int> & coordinates)
	{

		return Point2D<int>(block_coordinates.X*16+coordinates.X,block_coordinates.Y+coordinates.Y);
	}

	Point2DI AbsPositionToBlockCoords(Vector3 & position)
	{
		return Point2DI((int)(position.x / Metrics::BlockSize), (int)(position.z / (Metrics::BlockSize)));
	}
	namespace Game
	{
		vector<Location> LocationBase::locations=vector<Location>();
		bool LocationBase::initialized=false;
		void LocationBase::Add(Location & loc)
		{
			locations.push_back(loc);
		}
		void LocationBase::Clear()
		{
			/*for (auto loc:locations)
			{
				delete loc;
			}*/
			locations.clear();
			locations.shrink_to_fit();
		}
		void LocationBase::Init()
		{
			locations.push_back(Location("Kalimdor",1));
			initialized=true;
		}
		bool LocationBase::IsInitialized()
		{
			return initialized;
		}
		Location & LocationBase::Get(string name)
		{
			for (auto &loc:locations)
			{
				if (loc.name==name)
				{
					return loc;
				}
			}
			throw exception(("Location:" + name + " not found").c_str());
		}
		Location & LocationBase::Get(unsigned id)
		{
			for (auto &loc:locations)
			{
				if (loc.id==id)
				{
					return loc;
				}
			}
			throw exception(("Location:" + to_string(id) + " not found").c_str());
		}

	}
	namespace Graphics
	{
		
	};
	namespace Geometry
	{
		boost::numeric::ublas::matrix<float> Transformer3D::rotation_matrix_X= boost::numeric::ublas::matrix<float>(4, 4);
		boost::numeric::ublas::matrix<float> Transformer3D::rotation_matrix_Y = boost::numeric::ublas::matrix<float>(4, 4);
		boost::numeric::ublas::matrix<float> Transformer3D::rotation_matrix_Z = boost::numeric::ublas::matrix<float>(4, 4);

		Transformer3D::Transformer3D()
		{
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					rotation_matrix_X(i, j) = 0;
					rotation_matrix_Y(i, j) = 0;
					rotation_matrix_Z(i, j) = 0;
				}
			}
			
			rotation_matrix_X(0,0) = 1.0f;
			rotation_matrix_X(3, 3) = 1.0f;
			rotation_matrix_Y(1, 1) = 1.0f;
			rotation_matrix_Y(3, 3) = 1.0f;
			rotation_matrix_Z(2, 2) = 1.0f;
			rotation_matrix_Z(3, 3) = 1.0f;
	
		}

		Vector3F Transformer3D::Rotate(float angle, AngleValueType value, Axis axis)
		{
			return Vector3F(0, 0, 0);
		}
		 void Transformer3D::SetRotationAngle(Axis axis, float angle)
		{
			switch (axis)
			{
			case Axis::X:
				rotation_matrix_X(1, 1) = cos(angle);
				rotation_matrix_X(1, 2) = sin(angle);
				rotation_matrix_X(2, 1) = -sin(angle);
				rotation_matrix_X(2, 2) = cos(angle);
				break;
			case Axis::Y:
				rotation_matrix_Y(0, 0) = cos(angle);
				rotation_matrix_Y(0, 2) = sin(angle);
				rotation_matrix_Y(2, 0) = -sin(angle);
				rotation_matrix_Y(2, 2) = cos(angle);
				break;
			case Axis::Z:
				rotation_matrix_Z(0, 0) = cos(angle);
				rotation_matrix_Z(0, 1) = sin(angle);
				rotation_matrix_Z(1, 0) = -sin(angle);
				rotation_matrix_Z(1, 1) = cos(angle);
				break;

			}
		}
		 bool BoundingBox::IsInside2D(Vector3 point)
		 {
			 return ((up.x <= point.x && up.y <= point.y) && (down.x >= point.x && down.y >= point.y));
		 }
	};
}

Vector3 Utils::Metrics::ConvertFromGameCoords(Vector3 point)
{
	return  Vector3(Metrics::MapMidPoint - point.x, point.z, Metrics::MapMidPoint - point.y);
}

Geometry::BoundingBox Utils::Metrics::ConvertFromGameCoords(Geometry::BoundingBox & bb)
{
	Geometry::BoundingBox rbb;
	rbb.up = ConvertFromGameCoords(bb.up);
	rbb.down = ConvertFromGameCoords(bb.down);
	return rbb;
}
