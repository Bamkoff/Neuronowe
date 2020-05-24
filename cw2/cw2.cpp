#include <iostream>
#define STALA_C 0.1


using namespace std;

double f(double u[26], double w[26])
{
	double a=0;
	for(int i=0;i<26;i++)
	{
		a+=u[i]*w[i];
	}
	if(a<0) return 0;
	else return 1;
}

double wartosc_z(int t)
{
	t = (t-1)%5;
	if(t==0||t==1||t==2) return 1;
	else if(t==3||t==4) return 0;
}

int main()
{
	double u[5][26];
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<25;j++)
		{
			u[i][j]=0; 		
		}
		u[i][25]=1;
	}
	u[0][6]=1;
	u[0][7]=1;
	u[0][12]=1;
	u[0][17]=1;
	u[0][22]=1;
	u[1][2]=1;
	u[1][3]=1;
	u[1][8]=1;
	u[1][13]=1;
	u[2][5]=1;
	u[2][6]=1;
	u[2][11]=1;
	u[2][16]=1;
	u[2][21]=1;
	u[3][6]=1;
	u[3][7]=1;
	u[3][8]=1;
	u[3][11]=1;
	u[3][13]=1;
	u[3][16]=1;
	u[3][17]=1;
	u[3][18]=1;
	u[4][10]=1;
	u[4][11]=1;
	u[4][12]=1;
	u[4][15]=1;
	u[4][17]=1;
	u[4][20]=1;
	u[4][21]=1;
	u[4][22]=1;
	
	double w[26];
	for(int i=0;i<26;i++)
	{
		w[i] = 1;
	}
	double w_tym[26];
	double z;
	double y;
	int t=1;
	int counter=0;
	while(counter!=5)
	{
		z = wartosc_z(t);
		y = f(u[(t-1)%5],w);
		//cout<<"wartosc z:"<<z<<", wartosc y:"<<y<<endl;
		for(int j=0;j<26;j++)
		{
			w[j] = w[j] + STALA_C*(z-y)*u[(t-1)%5][j];
		}
		if(z==y) counter++;
		else counter=0;
		t=t+1;	
	}
	cout<<"czas przeznaczony na wyliczenie: "<<t<<endl;
	cout<<"wyliczony wektor w:"<<endl<<endl;
	for(int i=0;i<26;i++)
	{
		cout<<w[i]<<endl;
	}
	
	return 0;
}
