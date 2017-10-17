#include <iostream>
#include <string>
using namespace std;

void loop(string u)
{
	for (int i=0; i<3; i++)
	{
		cout<<u;
	}
}

int main()
{
	string a;
	cin>>a;
	loop(a);
	return 0;
}
