/*
*	10 numeri e riordinali in modo decrescente
*/


#include <cstdlib>
#include <iostream>
using namespace std;

void crescente(int array[],int n_elementi){ // Descending order
	int c;
	for(int i=0;i<n_elementi;i++) // For each element
		{
			for(int j=i;(j+1)<n_elementi;j++) // For each next element
				{
					if (array[i]<array[j+1]) // Swap if array[element]<array[next element]
						{
							c=array[i];
							array[i]=array[j+1];
							array[j+1]=c;
						}
				}
		}
}

void decrescente(int array[],int n_elementi){ // Increasing order
	int c;
	for(int i=0;i<n_elementi;i++) // For each element
		{
			for(int j=i;(j+1)<n_elementi;j++) // For each next element
				{
					if (array[i]>array[j+1]) // Swap if array[element]>array[next element]
						{
							c=array[i];
							array[i]=array[j+1];
							array[j+1]=c;
						}
				}
		}
}

int main()
{	
	int N_of_el=10, array[256];
	srand(time(NULL));
	bool autom=0;
	cout<<"     - SELECTION SORT -"<<endl;
	
	cout<<"                                       no | yes"<<endl; // Auto-compiler?
	cout<<"Do you want an automatic compilation? ( 0 | 1 )"<<endl; 
	cin>>autom;
	
	if (autom==0)
		{
			for(int i=0;i<N_of_el;i++) // Auto-compiler=false
				{
					cout<<endl<<"Put the "<<i+1<<" number: "; // 
					cin>>array[i];
				}
		}
	else
		{
			cout<<endl<<"Input Array:"<<endl; 
			for(int i=0;i<N_of_el;i++) // Auto-compiler=true
				{
					array[i]=rand()%101; //randomizer
					cout<<array[i]<<"\t";
				}		
		}
		
	crescente(array,N_of_el);
	cout<<endl<<endl<<"Increasing order Array:"<<endl;; // Output array
	for(int i=0;i<N_of_el;i++)
		{
			cout<<array[i]<<"\t";
		}
			
	decrescente(array,N_of_el);
	cout<<endl<<endl<<"Descending order Array:"<<endl;; // Output array
	for(int i=0;i<N_of_el;i++)
		{
			cout<<array[i]<<"\t";
		}
	return 0;
}

