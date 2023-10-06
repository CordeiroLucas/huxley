#include <stdio.h>

float med(float x, float y, float z) 
{
	return (x+y+z)/3;
}

float med_pond(float x, float y, float z, float p1, float p2, float p3)
{
	return (x*p1 + y*p2 + z*p3)/(p1+p2+p3);
}

int main(void) 
{
	float x, y, z;

	scanf("%f %f %f", &x, &y, &z);
	printf("%.2f\n", med(x,y,z));
	printf("%.2f\n", med_pond(x,y,z,2,2,3));
	printf("%.2f", med_pond(x,y,z,1,2,2));

	return 0;
}
