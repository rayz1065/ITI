/*Intersezione di vettori*/
#include <iostream>
using namespace std;

int main(){
	int a[10],b[10],c[20], min[3], max[3], som[3]={0,0,0};
	float med[3];
	for(int i=0;i<10;i++){
		cout<<endl<<"Inserisci il "<<i+1<<"° elemento del primo vettore:";
		cin>>a[i];
		cout<<endl<<"Inserisci il "<<i+1<<"° elemento del secondo vettore:";
		cin>>b[i];
		c[i*2]=a[i];
		c[(i*2)+1]=b[i];
		
		som[0]+=a[i];
		som[1]+=b[i];
		
		if (i==0){
			min[0]=a[0];
			min[1]=b[0];
			min[2]=c[0];
			
			max[0]=a[0];
			max[1]=b[0];
			max[2]=c[0];
		} else {
			if (min[0]>a[i]) min[0]=a[i];
			if (min[1]>b[i]) min[1]=b[i];
			
			if (max[0]<a[i]) max[0]=a[i];
			if (max[1]<b[i]) max[1]=b[i];
		}
	}
	
	if(max[0]>max[1]) max[2]=max[0]; else max[2]=max[1];
	if(min[0]<min[1]) min[2]=min[0]; else min[2]=min[1];
	
	som[2]=som[0]+som[1];
	
	med[0]=(float)som[0]/10;
	med[1]=(float)som[1]/10;
	med[2]=(float)som[2]/20;
	
	cout<<endl<<endl<<"Minimo:"<<endl;
	for(int i=0;i<3;i++) cout<<min[i]<<' ';
	cout<<endl<<endl<<"Massimo:"<<endl;
	for(int i=0;i<3;i++) cout<<max[i]<<' ';
	cout<<endl<<endl<<"Somma:"<<endl;
	for(int i=0;i<3;i++) cout<<som[i]<<' ';
	cout<<endl<<endl<<"Media:"<<endl;
	for(int i=0;i<3;i++) cout<<med[i]<<' ';
	
	cout<<endl<<endl<<"c:"<<endl;
	for(int i=0;i<20;i++) cout<<c[i]<<' ';
	return 0;
}
