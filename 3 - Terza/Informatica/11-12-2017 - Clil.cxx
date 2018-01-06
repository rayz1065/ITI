/*
 Selection sort
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main()
{	
	int N_of_el, array[256], c;
	srand(time(NULL));
	bool autom=0;
	cout<<"     - SELECTION SORT -"<<endl;
	
	cout<<"Put the number of elements: "; // Number of elements
	cin>>N_of_el;
	
	if (N_of_el>256) // Array limit 
		{
			cout<<endl<<"ERROR:\nYou put too many elements."<<endl;
			return 0;
		}
	
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
		
	for(int i=0;i<N_of_el;i++) // For each element
		{
			for(int j=i;(j+1)<N_of_el;j++) // For each next element
				{
					if (array[i]>array[j+1]) // Swap if array[element]>array[next element]
						{
							c=array[i];
							array[i]=array[j+1];
							array[j+1]=c;
						}
				}
		}
	
	cout<<endl<<endl<<"Output Array:"<<endl;; // Output array
	for(int i=0;i<N_of_el;i++)
		{
			cout<<array[i]<<"\t";
		}
	return 0;
}

