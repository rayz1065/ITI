#include <iostream>
using namespace std;
int eta(int a)
{
int e;
const int m=2017;
e=m-a;
return e;
}
int main()
{
int anno;
cout<<"Immetti l'anno di nascita"<<endl;
cin>>anno;
cout<<"la persona inserita ha "<<eta(anno)<<" anni."<<endl;
return 0;
}
