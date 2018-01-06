// Data una matrice 3x4, ordinarla in ordine crescente e decrescente.
#include <cstdlib>
#include <iostream>
using namespace std;

void crescente(int matrix[][256],int n_righe,int n_colonne){ // Increasing order
	int W;
	for(int r=0;r<n_righe;r++){ // For each row
		for(int c=0;c<n_colonne;c++){ // For each element
			for(int s=(c+1);s<n_colonne;s++){ // For each next element
				if (matrix[r][c]>matrix[r][s]){ // Swap if matrix[element]>matrix[next element]
					W=matrix[r][c];
					matrix[r][c]=matrix[r][s];
					matrix[r][s]=W;
				}
			}
		}
	}
}

void decrescente(int matrix[][256],int n_righe,int n_colonne){ // Descending order
	int W;
	for(int r=0;r<n_righe;r++){ // For each row
		for(int c=0;c<n_colonne;c++){ // For each element
			for(int s=(c+1);s<n_colonne;s++){ // For each next element
				if (matrix[r][c]<matrix[r][s]){ // Swap if matrix[element]<matrix[next element]
					W=matrix[r][c];
					matrix[r][c]=matrix[r][s];
					matrix[r][s]=W;
				}
			}
		}
	}
}

int main(){	
	int n_colonne=4, n_righe=3, matrix[256][256];
	bool autom=0;
	srand(time(NULL));
	
	cout<<"     - SELECTION SORT -"<<endl;
	cout<<"                                       no | yes"<<endl; // Auto-compiler?
	cout<<"Do you want an automatic compilation? ( 0 | 1 )"<<endl; 
	cin>>autom;
	
	if(autom==0){
		for(int r=0;r<n_righe;r++){ // Auto-compiler=false
				for(int c=0;c<n_colonne;c++){
					cout<<endl<<"Put the "<<r+1<<" number of the "<<c+1<<" collon: "; // manual
					cin>>matrix[r][c];
				}
			}
		} else {
			cout<<endl<<"Input Matrix:"<<endl; 
			for(int r=0;r<n_righe;r++){ // Auto-compiler=false
				for(int c=0;c<n_colonne;c++){
					matrix[r][c]=rand()%101; //randomizer
					cout<<matrix[r][c]<<"\t";
				}
				cout<<endl;
			}	
		}
		
	crescente(matrix,n_righe,n_colonne);
	
	cout<<endl<<endl<<"Increasing order Matrix:"<<endl; // Output matrix
	for(int r=0;r<n_righe;r++){
		for(int c=0;c<n_colonne;c++){
			cout<<matrix[r][c]<<"\t";
		}
		cout<<endl;
	}
			
	decrescente(matrix,n_righe,n_colonne);
	cout<<endl<<endl<<"Descending order Matrix:"<<endl; // Output matrix
	for(int r=0;r<n_righe;r++){
		for(int c=0;c<n_colonne;c++){
			cout<<matrix[r][c]<<"\t";
		}
		cout<<endl;
	}
	return 0;
}

