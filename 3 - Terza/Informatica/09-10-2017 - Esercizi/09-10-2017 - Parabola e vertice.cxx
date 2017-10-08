//Testato con https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float a,b,c,XV,YV;
	const float PiGreco=3.14;
	const float PesoSpecifico=3.4;
	cout<<"Data la funzione \033[32my=ax²+bx+c\033[0m,\n inserire a"<<endl;
	cin>>a;
	cout<<"Inserire b"<<endl;
	cin>>b;
	cout<<"Inserire c"<<endl;
	cin>>c;
	
	if (a==0)
	{
		cout<<"\033[31ma non può essere 0\033[0m"<<endl;
		return 0;
	}
		
	if (b==0)
	{
		XV=0;
	}
	else
	{
		XV=2*a;
		XV=-b/XV;
	}
	YV=pow(XV,2);
	YV*=a;
	YV+=b*XV;
	YV+=c;
	
	
	cout<<"Il vertice sarà in cordinate "<<XV<<";"<<YV<<endl;
	return 0;
}