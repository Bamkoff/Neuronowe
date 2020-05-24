#include <iostream>
#include <stdlib.h> 
#define STALE_C 0.01
#define EPSILON 0.00001

using namespace std;

double fun (double x, double y, double z)
{
	double w = (2*x*x);
	w = w + (2*y*y);
	w = w + (z*z);
	w = w - (2*x*y);
	w = w - (2*y*z);
	w = w - (2*x);
	return w + 3;
}

double poch_x (double x, double y)
{
	double w = 4*x;
	w = w - 2*y;
	return w - 2;
}

double poch_x2 (double x, double y)
{
	double w = x*x;
	w = w + x;
	w = w - 2;
	w = w * 12;
	w = w * x;
	return w;
}

double poch_y (double x, double y, double z)
{
	double w = -2*x;
	w = w + (4*y);
	w = w - (2*z);
	return w;
}

double poch_y2 (double x, double y)
{
	double w = 24*y;
	w = w - 24;
	return w;
}

double poch_z (double y, double z)
{
	double w = (2*z);
	w = w - (2*y);
	return w;
}

double fun2 (double x, double y)
{
	double w = (3*x*x*x*x);
	w = w + (4*x*x*x);
	w = w - (12*x*x);
	w = w + (12*y*y);
	w = w - (24*y);
	return w;
}

int main()
{
	double x_old[3];
	double x_new[3];
	double warunek = 0;
	double x_old2[2];
	double x_new2[2];
	
	x_old[0] = rand() % 20 - 10;
	x_old[1] = rand() % 20 - 10;
	x_old[2] = rand() % 20 - 10;
	
	x_old2[0] = 2;
	x_old2[1] = 3;
	
	x_new[0] = x_old[0] - (STALE_C * poch_x(x_old[0],x_old[1]));
	x_new[1] = x_old[1] - (STALE_C * poch_y(x_old[0],x_old[1], x_old[2]));
	x_new[2] = x_old[2] - (STALE_C * poch_z(x_old[1],x_old[2]));
	
	for(int i=0;i<3;i++)
		{
			if(x_new[i] > x_old[i]) warunek += x_new[i] - x_old[i];
			else warunek += x_old[i] - x_new[i];
		}
	
	while (warunek >= EPSILON)
	{
		for(int i=0;i<3;i++)
		{
			x_old[i] = x_new[i];
		}
		
		x_new[0] = x_old[0] - (STALE_C * poch_x(x_old[0],x_old[1]));
		x_new[1] = x_old[1] - (STALE_C * poch_y(x_old[0],x_old[1], x_old[2]));
		x_new[2] = x_old[2] - (STALE_C * poch_z(x_old[1],x_old[2]));
		
		warunek = 0;
		for(int i=0;i<3;i++)
		{
			if(x_new[i] > x_old[i]) warunek += x_new[i] - x_old[i];
			else warunek += x_old[i] - x_new[i];
		}	
	}
	
	
	//----------------------------------
	
	x_new2[0] = x_old2[0] - (STALE_C * poch_x2(x_old2[0],x_old2[1]));
	x_new2[1] = x_old2[1] - (STALE_C * poch_y2(x_old2[0],x_old2[1]));
	warunek = 0;
	
	for(int i=0;i<2;i++)
		{
			if(x_new2[i] > x_old2[i]) warunek += x_new2[i] - x_old2[i];
			else warunek += x_old2[i] - x_new2[i];
		}
	
	while (warunek >= EPSILON)
	{
		for(int i=0;i<2 ;i++)
		{
			x_old2[i] = x_new2[i];
		}
		
		x_new2[0] = x_old2[0] - (STALE_C * poch_x2(x_old2[0],x_old2[1]));
		x_new2[1] = x_old2[1] - (STALE_C * poch_y2(x_old2[0],x_old2[1]));
		
		warunek = 0;
		for(int i=0;i<2;i++)
		{
			if(x_new2[i] > x_old2[i]) warunek += x_new2[i] - x_old2[i];
			else warunek += x_old2[i] - x_new2[i];
		}	
	}
	
	cout<<"x= "<<x_new[0]<<", y= "<<x_new[1]<<", z="<<x_new[2]<<endl;
	cout<<"f(x_new) = "<< fun(x_new[0],x_new[1],x_new[2])<<endl;
	cout<<"x= "<<x_new2[0]<<", y= "<<x_new2[1]<<endl;
	cout<<"f2(x_new2) = "<< fun2(x_new2[0],x_new2[1]);
	
	return 0;
}
