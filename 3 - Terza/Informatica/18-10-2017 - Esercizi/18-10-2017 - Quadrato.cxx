#include <iostream>
using namespace std;

float perimetro(float l)
{
	float p;
	p=4*l;
	return p;
}

float area(float l)
{
	float a;
	a=l*l;
	return a;
}

int main()
{
	float lato,perimetro,area;
	cout<<"Immetti le dimensioni del lato del tuo quadrato";
	cin>>lato;
	perimetro=perimetro(lato);
	area=area(lato);
	cout<<"Il perimetro del tuo quadrato sarà di "<<perimetro<<" cm";
	cout<<"L'area del tuo quadrato sarà di "<<area<< "cm^2";
	return 0;
}
