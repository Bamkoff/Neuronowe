#include <iostream>
#include <math.h>
#define EPSILON 0.00001
#define BETA 1
#define STALA_C 0.1

double fun(double u)
{
	double tym = pow(M_E, -BETA*u);
	tym = tym + 1;
	return 1/tym;
}

double poch_fun(double u)
{
	double tym = 1-fun(u);
	return BETA * fun(u) * tym;
}

using namespace std;

int main()
{
	double u[4][3];
	
	u[0][0] = 0;
	u[0][1] = 0;
	u[0][2] = 1;
	
	u[1][0] = 1;
	u[1][1] = 0;
	u[1][2] = 1;
	
	u[2][0] = 0;
	u[2][1] = 1;
	u[2][2] = 1;
	
	u[3][0] = 1;
	u[3][1] = 1;
	u[3][2] = 1;
	
	double w[2][3];
	double w_new[2][3];
	
	w[0][0] = 0;
	w[0][1] = 1;
	w[0][2] = 2;
	
	w[1][0] = 0;
	w[1][1] = 1;
	w[1][2] = 2;
	
	double s[3];
	double s_new[3];
	
	s[0] = 0;
	s[1] = 1;
	s[2] = 2;
	
	double x[4][3];
	
	x[0][2] = 1;
	x[1][2] = 1;
	x[2][2] = 1;
	x[3][2] = 1;
	
	double z[4];
	z[0] = 0;
	z[1] = 1;
	z[2] = 1;
	z[3] = 0;
	
	double y[4];
	
	double E_S[3];
	double E_W[2][3];
	
	double y_z = 0;
	
	bool warunek;
	
	do
	{
		warunek = 0;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<3;j++)
			{
				E_W[i][j] = 0;
				E_S[j] = 0;
			}
		}
		
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<2;j++)
			{
				x[i][j] = fun(w[j][0]*u[i][0] + w[j][1]*u[i][1] + w[j][2]);
			}
		}
		
		for(int i=0;i<4;i++)
		{
			y[i] = fun(s[0] * x[i][0] + s[1] * x[i][1] + s[2]);
		}
		
		
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<3;j++)
			{
				for(int a=0;a<4;a++)
				{
					y_z = y[a] - z[a];
					E_W[i][j] += y_z * poch_fun(s[0] * x[a][0] + s[1] * x[a][1] + s[2] * x[a][2]) * s[i] * poch_fun(w[i][0]*u[a][0] + w[i][1]*u[a][1] + w[i][2]*u[a][2]) * u[a][j];
				}
			}
		}
		
		for(int j=0;j<3;j++)
		{
			for(int a=0;a<4;a++)
			{
				y_z = y[a] - z[a];
				E_S[j] += y_z * poch_fun(s[0] * x[a][0] + s[1] * x[a][1] + s[2] * x[a][2]) * x[a][j];
			}
		}
		
		for(int i=0;i<3;i++)
		{
			s_new[i] = s[i] - STALA_C * E_S[i];		
		} 
	
		for(int i=0;i<2;i++)
		{
				
			for(int j=0;j<3;j++)
			{
				w_new[i][j] = w[i][j] - STALA_C * E_W[i][j];
			}
		}
				
		
		for(int j=0;j<3;j++)
		{
			if(s_new[j] > s[j])
			{
				if(s_new[j] - s[j] >= EPSILON) warunek = 1;
			}
			else
			{
				if(s[j] - s_new[j] >= EPSILON) warunek = 1;
			}
			
			for(int i=0;i<2;i++)
			{
				if(w_new[i][j] > w[i][j])
				{
					if(w_new[i][j] - w[i][j] >= EPSILON) warunek = 1;
				}
				else
				{
					if(w[i][j] - w_new[i][j] >= EPSILON) warunek = 1;
				}
			}
		}
		
	if(warunek)
	{
		for(int j=0;j<3;j++)
		{
			s[j] = s_new[j];
			for(int i=0;i<2;i++)
			{
				w[i][j] = w_new[i][j];
			}
		}
	}
	
	}while(warunek);
	
	for(int i=0;i<3;i++)
	{
		cout<<"S["<<i+1<<"] = "<<s[i]<<", ";
	}
	cout<<endl;
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"W["<<i+1<<"]["<<j+1<<"] = "<<w[i][j]<<", ";
		}
		cout<<endl;
	}
	for(int i=0;i<4;i++)
	{
		cout<<"y["<<i+1<<"] = "<<y[i]<<", ";
	}
	
	return 0;
}
