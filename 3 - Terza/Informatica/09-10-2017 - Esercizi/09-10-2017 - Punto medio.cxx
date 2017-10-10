#include <iostream>
using namespace std;

int main()
{
	float x1,y1,x2,y2,xm,ym;
	cout<<"Inserire le coordinate del primo punto"<<endl;
	cin>>x1;
	cin>>y1;
	cout<<"Inserire le coordinate del secondo punto"<<endl;
	cin>>x2;
	cin>>y2;
	
	xm=(x1+x2)/2;
	ym=(y1+y2)/2;

	cout<<"Il punto medio sarà a coordinate "<<xm<<";"<<ym<<endl;
	return 0;
}
