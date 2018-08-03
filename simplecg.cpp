#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include "Vec2.h"
#include "Vec3.h"
using namespace std;



int main()
{
	Vec3 a(1,0,0);
	Vec3 b;
	b.x=0;
	b.y=1;
	b.z=0;
	b =b*2*a;
	printf("%f %f %f\n",b.x,b.y,b.z);
	return 0;
}