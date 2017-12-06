// Ordinamento con procedure
#include <iostream>
using namespace std;

void ordina(int& a, int& b){
	int t;
	if (a>b){
		t=a;
		a=b;
		b=t;
	}
}

int main()
{
	int et1,et2,et3;
	cout<<"Immetti le 3 età:"<<endl;
	cin>>et1;
	cin>>et2;
	cin>>et3;
	ordina(et1,et2);
	ordina(et1,et3);
	ordina(et2,et3);
	cout<<"Piccolo: "<<et1<<endl;
	cout<<"Medio: "<<et2<<endl;
	cout<<"Grande: "<<et3<<endl;
	return 0;
}

