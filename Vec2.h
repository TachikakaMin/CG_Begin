#ifndef VEC2_H
#define VEC2_H
// 两个向量间 * 默认为叉乘
struct Vec2
{
	float x,y;
	Vec2(float a,float b):x(a),y(b){}
	Vec2():x(0),y(0){}
	Vec2& operator=(const Vec2& b)
	{
		x=b.x;y=b.y;
		return *this;
	}
	Vec2 operator+(const Vec2& b) const
	{
		Vec2 ans;
		ans.x = x+b.x;
		ans.y = y+b.y;
		return ans;
	}
	Vec2& operator+=(const Vec2& b)
	{
		x += b.x;
		y += b.y;
		return *this;
	}
	Vec2 operator-(const Vec2& b) const
	{
		Vec2 ans;
		ans.x = x-b.x;
		ans.y = y-b.y;
		return ans;
	}
	Vec2& operator-=(const Vec2& b)
	{
		x-=b.x;
		y-=b.y;
		return *this;
	}

	Vec2 operator/(const float& b) const
	{
		Vec2 ans;
		ans.x =x / b;
		ans.y =y / b;
		return ans;
	}

	Vec2& operator/=(const float& b)
	{
		x /= b;
		y /= b;
		return *this;
	}

	Vec2 operator*(const float& b) const
	{
		Vec2 ans;
		ans.x =x * b;
		ans.y =y * b;
		return ans;
	}
	Vec2& operator*=(const float& b)
	{
		x *= b;
		y *= b;
		return *this;
	}

	float operator*(const Vec2& b) const 
	{
		float ans;
		ans = x*b.y-y*b.x;
		return ans;
	}

	bool operator==(const Vec2& b) const
	{
		if (abs(x-b.x)+abs(y-b.y)<1e-6) return 1;
		return 0;
	}

	float cross(const Vec2& b) const
	{
		return x*b.y-y*b.x;
	}

	float dot(const Vec2& b) const
	{
		return x*b.x+y*b.y;
	}
};

#endif