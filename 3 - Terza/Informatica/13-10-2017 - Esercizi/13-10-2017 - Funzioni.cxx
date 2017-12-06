#include <iostream>
#include <cmath>
using namespace std;

float primo_grado (float m, float q){
	float x;
	if (m!=0){
		x=-q/m;
		
	} else if (q==0) {
		x= 1.17549e-38+1;
	} else {
		x=1.17549e-38+2;
	}
	return x;
}

float delta (float a, float b, float c){
	float d;
	d=pow(b,2);
	d-=4*a*c;
	return d;
}

float secondo_grado (float a, float b, float d, bool s){
	float x;
	x=-b;
	if (s==1){
		x+=sqrt(d);
		x/=2*a;
	} else {
		x-=sqrt(d);
		x/=2*a;
	}
	return x;
}



int main(){
	float a,b,c,d,x,x1,x2;
	cout<<"Data la funzione \033[32my=ax²+bx+c\033[0m,\n inserire a b c"<<endl;
	cin>>a;
	cin>>b;
	cin>>c;
	
	if (a==0){
		x=primo_grado(b,c);
		
		if (x==1.17549e-38+1) {
			cout<<"La funzione inserita non è di secondo grado e ha valore impossibile"<<endl;
		} else if (x==1.17549e-38+2) {
			cout<<"La funzione inserita non è di secondo grado e ha valore indeterminato"<<endl;
		} else {
			cout<<"La funzione inserita non è di secondo grado, ma se risolta come funzione di primo grado, x="<<x<<endl;
		}
		return 0;
	}
	
	d=delta(a,b,c);
	if (d<0){
		cout<<"La funzione inserita non ammette soluzioni"<<endl;
		return 0;
	}
	
	x1=secondo_grado(a,b,d,0);
	x2=secondo_grado(a,b,d,1);
	
	if (d==0) {
		cout<<"La funzione inserita avrà 2 soluzioni reali e coincidenti di valore "<<x1<<endl;
		return 0;
	}
	
	cout<<"La funzione inserita avrà 2 soluzioni reali e distinte di valore "<<x1<<" e "<<x2<<endl;
	return 0;
}
