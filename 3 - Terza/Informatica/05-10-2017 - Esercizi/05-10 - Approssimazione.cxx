#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a,b,Pb,Pa,Ra,Rb,A,B;
		
	cin>>a;
	cin>>b;
	
	Pa=pow(a,b);
	Pb=pow(b,a);
	Ra=sqrt(a);
	Rb=sqrt(b);
	
	A=floor(a);
	A=a-A;
	B=floor(b);
	B=b-B;
	
	if (A>=0.5)
	{
		A=ceil(a);
	}
	else
	{
		A=floor(a);
	}
	
	if (B>=0.5)
	{
		B=ceil(b);
	}
	else
	{
		B=floor(b);
	}
	
	cout<<"A^B="<<Pa<<"\nB^A="<<Pb<<"\nRadice Quadrata di A="<<Ra<<"\nRadice Quadrata di B="<<Rb<<"\nArrotondamento di A="<<A<<"\nArrotondamento di B="<<B<<endl;
	
	return 0;
}
