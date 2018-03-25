#include <iostream>
#include <fstream>
using namespace std;


int main() {
	int T,N,n_fibo=1, pn_fibo=1, swap, n=0,m=0;
	bool R[200];
	
	ifstream fin;
	fin.open("input.txt");
	fin>>T;
	ofstream fout;
	fout.open("output.txt");
	
	for(int i=0;i<T;i++){
		fin>>N;
		n_fibo=1; pn_fibo=1; n=0, m=0;
		for (int j=0;j<200;j++){
			R[j]=0;
		}
		do{
			cout<<n_fibo<<endl; //D
			swap=n_fibo;
			n_fibo+=pn_fibo;
			pn_fibo=swap;	
			n++;
		} while(n_fibo<=N);
		cout<<"#"<<N<<endl; //D
		for (int j=n+1; j!=0; j--){
			if ((N-n_fibo)>=0) {
				N-=n_fibo;
				R[j]=1;
				cout<<n_fibo<<"+"; //D
				m++;
			}
			swap=pn_fibo;
			pn_fibo=n_fibo-pn_fibo;
			n_fibo=swap;
		}
		cout<<"0"<<endl<<endl; //D
		fout<<"Case #"<<i+1<<": ";
		for (int j=0;j<n+1;j++) {
			fout<<R[j];
		}
		fout<<endl;
	}
	fin.close();
	fout.close();
	
	return 0;
}
