#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
	double xs[25];
	double x[25];
	double u[25];
	double c[25][25];
	double theta[25];
	double w[25][25];
	double temp;
	
	for(int i=0;i<25;i++)
	{
		x[i] = rand()%2;
		xs[i] = 0;
	}
	
	for(int i=0;i<25;i++)
	{
		if(i%5==0) cout<<endl;
		if(x[i] == 1) cout<<"*";
		if(x[i] == 0) cout<<"#";
	}
	cout<<endl;
		system("pause>NULL");
		system("cls");
	
	xs[6] = 1;
	xs[7] = 1;
	xs[12] = 1;
	xs[17] = 1;
	xs[22] = 1;
	
	for(int i=0;i<25;i++)
	{
		theta[i] = 0;
		for(int j=0;j<25;j++)
		{
			if(i == j) c[i][j] = 0;
			else c[i][j] = (xs[i]-0.5)*(xs[j]-0.5);	
			theta[i] += c[i][j];
		}
	}
	
	for(int i=0;i<25;i++)
		{
			
			for(int j=0;j<25;j++)
			{
			 	w[i][j] = 2 * c[i][j];
			}
		}
	
	for(int k=0;k<3;k++)
	{	
		
		for(int i=0;i<25;i++)
		{
			temp = 0;
			for(int j=0;j<25;j++)
			{
				temp += w[i][j]*x[j];
			}
			u[i] = temp - theta[i];
		}
		
		for(int i=0;i<25;i++)
		{
			if(u[i]>0) x[i] = 1;
			else if(u[i]<0) x[i] = 0;
		}
		
		for(int i=0;i<25;i++)
		{
			if(i%5==0) cout<<endl;
			if(x[i] == 1) cout<<"*";
			if(x[i] == 0) cout<<"#";
		}
		
		cout<<endl;
		system("pause>NULL");
		system("cls");
	}
	
	return 0;
}
