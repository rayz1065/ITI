//Testato con https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float r,h,A,V,P;
	const float PiGreco=3.14;
	const float PesoSpecifico=3.4;
	cout<<"Inserire il raggio del proprio cilindro in cm"<<endl;
	cin>>r;
	cout<<"Inserire l'altezza del proprio cilindro in cm"<<endl;
	cin>>h;
	
	A=pow(r,2);
	A*=PiGreco;
	
	V=A*h;
	
	P=V*PesoSpecifico;
	
	cout<<"Il peso del cilindro sarà di "<<P<<"g"<<endl;
	return 0;
}