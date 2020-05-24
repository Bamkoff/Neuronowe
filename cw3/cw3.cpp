//

#include <iostream>


using namespace std;

double sgn(double a)
{
	if(a<0) return -1;
	else return 1;
}


int main()
{
	double Z[4][25];
	double w[25][25];
	double x[25];
	
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<25;j++)
		{
			Z[i][j]=-1;
		}
	}
	
	Z[0][6]=1;
	Z[0][7]=1;
	Z[0][8]=1;
	Z[0][11]=1;
	Z[0][13]=1;
	Z[0][16]=1;
	Z[0][17]=1;
	Z[0][18]=1;
	Z[1][6]=1;
	Z[1][7]=1;
	Z[1][12]=1;
	Z[1][17]=1;
	Z[2][1]=1;
	Z[2][2]=1;
	Z[2][3]=1;
	Z[2][6]=1;
	Z[2][8]=1;
	Z[2][11]=1;
	Z[2][13]=1;
	Z[2][16]=1;
	Z[2][17]=1;
	Z[2][18]=1;
	Z[3][2]=1;
	Z[3][7]=1;
	Z[3][12]=1;
	Z[3][17]=1;
	Z[3][22]=1;
	
	for(int i=0;i<25;i++)
	{
		for(int j=0;j<25;j++)
		{
			w[i][j]=Z[0][i]*Z[0][j]+Z[1][i]*Z[1][j];	
		}
	}
	
	/*
	for(int i=0;i<25;i++)
	{
		for(int j=0;j<25;j++)
		{
			cout<<" "<<w[i][j]<<" ";	
		}
		cout<<endl;
	}
	for(int j=0;j<25;j++)
	{
		if(Z[3][j]==1) cout<<"*";
		else cout<<"_";
		if((j+1)%5 == 0) cout<<endl;
	}
	*/
	
	//ZAD.1
	
	for(int i=0;i<25;i++)
	{
		x[i]=0;
		for(int j=0;j<25;j++)
		{
			x[i] += w[i][j]*Z[0][j];
		}
	}
	
	for(int i=0;i<25;i++)
	{
		if(sgn(x[i])==1) cout<<"*";
		else cout<<"-";
		if((i+1)%5==0) cout<<endl; 
	}
	
	cout<<endl<<endl;
	
	for(int i=0;i<25;i++)
	{
		x[i]=0;
		for(int j=0;j<25;j++)
		{
			x[i] += w[i][j]*Z[1][j];
		}
	}
	
	for(int i=0;i<25;i++)
	{
		if(sgn(x[i])==1) cout<<"*";
		else cout<<"-";
		if((i+1)%5==0) cout<<endl; 
	}
	
	cout<<endl<<endl;
	
	//ZAD.2
	
	for(int i=0;i<25;i++)
	{
		x[i]=0;
		for(int j=0;j<25;j++)
		{
			x[i] += w[i][j]*Z[2][j];
		}
	}
	
	for(int i=0;i<25;i++)
	{
		if(sgn(x[i])==1) cout<<"*";
		else cout<<"-";
		if((i+1)%5==0) cout<<endl; 
	}
	
	cout<<endl<<endl;
	
	for(int i=0;i<25;i++)
	{
		x[i]=0;
		for(int j=0;j<25;j++)
		{
			x[i] += w[i][j]*Z[3][j];
		}
	}
	
	for(int i=0;i<25;i++)
	{
		if(sgn(x[i])==1) cout<<"*";
		else cout<<"-";
		if((i+1)%5==0) cout<<endl; 
	}
	
	
	return 0;
}
