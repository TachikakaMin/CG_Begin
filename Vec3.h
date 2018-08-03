#ifndef VEC3_H
#define VEC3_H
// 两个向量间 * 默认为叉乘
struct Vec3
{
	float x,y,z;
	Vec3(float a,float b,float c):x(a),y(b),z(c){}
	Vec3():x(0),y(0),z(0){}
	Vec3& operator=(const Vec3& b)
	{
		x=b.x;y=b.y;z=b.z;
		return *this;
	}
	Vec3 operator+(const Vec3& b) const
	{
		Vec3 ans;
		ans.x = x+b.x;
		ans.y = y+b.y;
		ans.z = z+b.z;
		return ans;
	}
	Vec3& operator+=(const Vec3& b)
	{
		x += b.x;
		y += b.y;
		z += b.z;
		return *this;
	}
	Vec3 operator-(const Vec3& b) const
	{
		Vec3 ans;
		ans.x = x-b.x;
		ans.y = y-b.y;
		ans.z = z-b.z;
		return ans;
	}
	Vec3& operator-=(const Vec3& b)
	{
		x-=b.x;
		y-=b.y;
		z-=b.z;
		return *this;
	}

	Vec3 operator/(const float& b) const
	{
		Vec3 ans;
		ans.x =x / b;
		ans.y =y / b;
		ans.z =z / b;
		return ans;
	}

	Vec3& operator/=(const float& b)
	{
		x /= b;
		y /= b;
		z /= b;
		return *this;
	}

	Vec3 operator*(const float& b) const
	{
		Vec3 ans;
		ans.x =x * b;
		ans.y =y * b;
		ans.z =z * b;
		return ans;
	}
	Vec3& operator*=(const float& b)
	{
		x *= b;
		y *= b;
		z *= b;
		return *this;
	}
	
	Vec3 operator*(const Vec3& b) const
	{
		Vec3 ans;
		ans.x = y*b.z - z*b.y;
		ans.y = z*b.x - x*b.z;
		ans.z = x*b.y - y*b.x;
		return ans;
	}

	Vec3& operator*=(const Vec3& b)
	{
		float nx = y*b.z - z*b.y;
		float ny = z*b.x - x*b.z;
		float nz = x*b.y - y*b.x;
		x = nx;y=ny;z=nz;
		return *this;
	}


	bool operator==(const Vec3& b) const
	{
		if (abs(x-b.x)+abs(y-b.y)+abs(z-b.z)<1e-7) return 1;
		return 0;
	}

	Vec3 cross(const Vec3& b) const
	{
		Vec3 ans;
		ans.x = y*b.z - z*b.y;
		ans.y = z*b.x - x*b.z;
		ans.z = x*b.y - y*b.x;
		return ans;
	}


	float dot(const Vec3& b) const
	{
		return x*b.x+y*b.y+z*b.z;
	}

};


#endif