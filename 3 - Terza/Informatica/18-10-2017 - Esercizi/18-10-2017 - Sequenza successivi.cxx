#include <iostream>
using namespace std;

void successivi(int n)
{
	int m;
	for (int i=1;i<6;i++)
	{
		m=n+i;
		cout<<m<<endl;
	}
}

int main()
{
	int n;
	cout<<"Immetti il tuo numero"<<endl;
	cin>>n;
	successivi(n);
	return 0;
}
