#pragma once

namespace Utils
{
	const float PI = 3.14159265358979323846f;
	template<class T>
	struct Point2D
	{
		T X;
		T Y;
		Point2D() :X(0), Y(0) {}
		Point2D(T x, T y) :X(x), Y(y) {}
		bool operator==(const Point2D & right)
		{
			return (this->X == right.X && this->Y == right.Y);
		}
		bool operator!=(const Point2D & right)
		{
			return (this->X != right.X || this->Y != right.Y);
		}
		Point2D operator -(const Point2D & right)
		{
			return Point2D(this->X - right.X, this->Y - right.Y);
		}
		Point2D operator +(const Point2D & right)
		{
			return Point2D(this->X + right.X, this->Y + right.Y);
		}
		Point2D operator -=(const Point2D & right)
		{
			return Point2D(this->X - right.X, this->Y - right.Y);
		}
		Point2D operator +=(const Point2D & right)
		{
			return Point2D(this->X + right.X, this->Y + right.Y);
		}

	};
	using Point2DI = Point2D<int>;
	using Point2DF = Point2D<float>;
	struct Vector3
	{
		float x;
		float y;
		float z;
		Vector3()
		{
			x = 0;
			y = 0;
			z = 0;
		}
		Vector3(float x, float y, float z) :x(x), y(y), z(z) {}
		Vector3 operator+(const Vector3 &right)
		{
			return Vector3(this->x + right.x, this->y + right.y, this->z + right.z);
		}
		Vector3 operator-(const Vector3 &right)
		{
			return Vector3(this->x - right.x, this->y - right.y, this->z - right.z);
		}

		Vector3 operator*(const float  &right)
		{
			return Vector3(this->x*right, this->y*right, this->z*right);
		}
		bool  operator==(const Vector3 &right)
		{
			return x == right.x && y == right.y && z==right.z;
		}
		bool  operator!=(const Vector3 &right)
		{
			return x != right.x || y != right.y || z != right.z;
		}
		Point2D<float> To2D()
		{
			return Point2D<float>(x, y);
		}
	};
	/*
	struct Vector3
	{
	float x;
	float y;
	float z;
	};
	*/
	struct Position
	{
		Vector3 coords;
		Vector3 rotation;
		Position() {};
		Position(Vector3 coords, Vector3 rotation) : coords(coords), rotation(rotation) {}
	};
}