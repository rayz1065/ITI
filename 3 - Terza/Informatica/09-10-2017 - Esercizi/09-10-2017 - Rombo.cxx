//Testato con https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float d1,d2,P,A,l;
	cout<<"Inserire la prima diagonale del rombo in cm"<<endl;
	cin>>d1;
	cout<<"Inserire la seconda diagonale del rombo in cm"<<endl;
	cin>>d2;
	
	A=d1*d2/2;
	d1/=2;
	d2/=2;
	
	l=pow(d1,2);
	l+=pow(d2,2);
	l=sqrt(l);
	
	P=4*l;
	
	cout<<"L'area del rombo sarà di "<<A<<"cm², mentre il perimetro sarà di "<<P<<"cm"<<endl;
	return 0;
}