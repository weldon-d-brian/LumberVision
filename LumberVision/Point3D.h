// Original from http://www.terathon.com/code/vector3d.html

#include "Vector3D.h"

//forward declare
Origin3D_ Origin3D;

class Point3D : public Vector3D
{
public:

	Point3D() {}

	Point3D(float r, float s, float t) : Vector3D(r, s, t) {}

	Point3D& operator =(const Vector3D& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
		return (*this);
	}

	Point3D& operator *=(float t)
	{
		x *= t;
		y *= t;
		z *= t;
		return (*this);
	}

	Point3D& operator /=(float t)
	{
		float f = 1.0F / t;
		x *= f;
		y *= f;
		z *= f;
		return (*this);
	}

	Point3D& operator &=(const Vector3D& v)
	{
		x *= v.x;
		y *= v.y;
		z *= v.z;
		return (*this);
	}

	Point3D operator -(void) const
	{
		return (Point3D(-x, -y, -z));
	}

	Point3D operator +(const Vector3D& v) const
	{
		return (Point3D(x + v.x, y + v.y, z + v.z));
	}

	Point3D operator -(const Vector3D& v) const
	{
		return (Point3D(x - v.x, y - v.y, z - v.z));
	}

	Vector3D operator -(const Point3D& p) const
	{
		return (Vector3D(x - p.x, y - p.y, z - p.z));
	}

	Point3D operator *(float t) const
	{
		return (Point3D(x * t, y * t, z * t));
	}

	Point3D operator /(float t) const
	{
		float f = 1.0F / t;
		return (Point3D(x * f, y * f, z * f));
	}

	Point3D operator &(const Vector3D& v) const
	{
		return (Point3D(x * v.x, y * v.y, z * v.z));
	}
};


inline Vector3D operator *(float t, const Vector3D& v)
{
	return (Vector3D(t * v.x, t * v.y, t * v.z));
}

inline Point3D operator *(float t, const Point3D& p)
{
	return (Point3D(t * p.x, t * p.y, t * p.z));
}

inline float Dot(const Vector3D& v1, const Vector3D& v2)
{
	return (v1 * v2);
}

inline Vector3D Cross(const Vector3D& v1, const Vector3D& v2)
{
	return (v1 % v2);
}

inline float Magnitude(const Vector3D& v)
{
	return (sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline float InverseMag(const Vector3D& v)
{
	return (1.0F / sqrtf(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline float SquaredMag(const Vector3D& v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}


struct Origin3D_
{
	const Point3D& operator +(const Vector3D& v)
	{
		return (static_cast<const Point3D&>(v));
	}

	Point3D operator -(const Vector3D& v)
	{
		return (Point3D(-v.x, -v.y, -v.z));
	}
};


extern Origin3D_ Origin3D;