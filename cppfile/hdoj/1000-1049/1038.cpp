#include<cstdio>
#include<cstdlib>
#define pai 3.1415927
int main()
{
	int revolution,trip=0;
	float d,t;
	scanf("%f %d %f",&d,&revolution,&t);
	while(1)
	{
		trip++; 
		if(revolution==0)
		  {
		  	break;
		  }
		float temp,distance,v;
		temp=d*pai*revolution;
		distance=temp/(12*5280);
		v=distance*3600/t;
		printf("Trip #%d: %.2f %.2f\n",trip,distance,v);
		scanf("%f %d %f",&d,&revolution,&t);
	}
}