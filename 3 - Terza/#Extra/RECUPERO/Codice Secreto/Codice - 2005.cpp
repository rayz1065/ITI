#include <iostream>
#include <fstream>

using namespace std;

int prendi();
int elabora();


int main(){
	prendi();
	return 0;
}

int elabora(char carattere[],int n_elemento){
	char in[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
	char out[]={'E','C','D','F','I','G','H','J','O','K','L','M','N','P','U','Q','R','S','T','V','Y','W','X','Z','A','B','b','c','d','f','i','g','h','j','o','k','l','m','n','p','u','q','r','s','t','v','y','w','x','z','a','b','1','2','3','4','5','6','7','8','9','0'};
	for (int i=0;i<62;i++) {
		if (carattere[n_elemento]==in[i]){
			carattere[n_elemento]=out[i];
			return 2;
		}
	}
	return 0;
}

int prendi(){
	int n_righe=0;
	string stringa;
	char carattere[80];
	
	ifstream fin;
	fin.open ("input.txt");
	ofstream fout;
	fout.open ("output.txt");
	
	fin>>n_righe;
	getline(fin,stringa);
	for (int i=0;i<n_righe;i++){
		getline(fin,stringa);
		cout<<stringa<<endl; cout<<"# ";
		for (int j=0;j<80;j++){
			carattere[j]=stringa[j];
			if (carattere[j]=='\0') break;
			elabora(carattere,j);
			cout<<carattere[j];
			fout<<carattere[j];
		}
		cout<<endl;
		fout<<endl;
	}
	fin.close();	
	fout.close();
	return 0;
}

