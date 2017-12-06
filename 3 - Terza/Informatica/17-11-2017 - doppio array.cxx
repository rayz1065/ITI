#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
	float INCASSI[12][31], MEDIA[12], MAX[12], MIN[12];
	float MEDIA_anno=0, MAX_anno, MIN_anno;
	int anno, c=0;
	srand(time(NULL));
	
	string mese[12]={"gennaio", "febbraio", "marzo", "aprile", "maggio", "giugno", "luglio", "agosto", "settembre", "ottobre", "novembre", "dicembre"};
	cout<<"Immetti l'anno corrente:"<<endl;
	cin>>anno;
	
	for(int i=0;i<12;i++){ //Input incassi
		for(int j=0;(j<31&&(i==0||i==2||i==4||i==6||i==7||i==9||i==11))||(j<30&&(i==3||i==5||i==8||i==10))||(i==1&&((j<29&&((anno%4==0&&anno%100!=0)||anno%400==0))||(j<28&&((anno%100==0&&anno%400!=0)||anno%4!=0))));j++){
			cout<<"Immetti l'incasso del "<<j+1<<' '<<mese[i]<<' '<<anno<<':'<<endl;
			// cin>>INCASSI[i][j];
			INCASSI[i][j]=rand()%100+1;
			
			cout<<endl;
			
			MEDIA_anno+=INCASSI[i][j]; //Somma incassi annui
			c++; //Numero giorni annui
		}
		cout<<endl;
	}
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl; //Pulisce la console
	
	for(int i=0;i<12;i++){
		if (i==0||i==2||i==4||i==6||i==7||i==9||i==11){ //31 giorni
			MIN[i]=INCASSI[i][0]; //Minimo incasso mensile
			for (int j=1; j<31; j++){
				if (MIN[i]>INCASSI[i][j]){
					MIN[i]=INCASSI[i][j];
				}
			}
			MAX[i]=INCASSI[i][0]; //Massimo incasso mensile
			for (int j=1; j<31; j++){
				if (MAX[i]<INCASSI[i][j]){
					MAX[i]=INCASSI[i][j];
				}
			}
			for (int j=0; j<31; j++){ //Media incassi mensile
				MEDIA[i]+=INCASSI[i][j];
			}
			MEDIA[i]/=12;
		}
		if (i==3||i==5||i==8||i==10){ //30 giorni
			MIN[i]=INCASSI[i][0]; //Minimo incasso mensile
			for (int j=1; j<30; j++){
				if (MIN[i]>INCASSI[i][j]){
					MIN[i]=INCASSI[i][j];
				}
			}
			MAX[i]=INCASSI[i][0]; //Massimo incasso mensile
			for (int j=1; j<30; j++){
				if (MAX[i]<INCASSI[i][j]){
					MAX[i]=INCASSI[i][j];
				}
			}
			for (int j=0; j<30; j++){ //Media incassi mensile
				MEDIA[i]+=INCASSI[i][j];
			}
			MEDIA[i]/=12;
		}
		if (i==1&&((anno%4==0&&anno%100!=0)||anno%400==0)){ //29 giorni
			MIN[i]=INCASSI[i][0]; //Minimo incasso mensile
			for (int j=1; j<29; j++){
				if (MIN[i]>INCASSI[i][j]){
					MIN[i]=INCASSI[i][j];
				}
			}
			MAX[i]=INCASSI[i][0]; //Massimo incasso mensile
			for (int j=1; j<29; j++){
				if (MAX[i]<INCASSI[i][j]){
					MAX[i]=INCASSI[i][j];
				}
			}
			for (int j=0; j<29; j++){ //Media incassi mensile
				MEDIA[i]+=INCASSI[i][j];
			}
			MEDIA[i]/=12;
		}
		if (i==1&&((anno%100==0&&anno%400!=0)||anno%4!=0)){ //28 giorni
			MIN[i]=INCASSI[i][0]; //Minimo incasso mensile
			for (int j=1; j<28; j++){
				if (MIN[i]>INCASSI[i][j]){
					MIN[i]=INCASSI[i][j];
				}
			}
			MAX[i]=INCASSI[i][0]; //Massimo incasso mensile
			for (int j=1; j<28; j++){
				if (MAX[i]<INCASSI[i][j]){
					MAX[i]=INCASSI[i][j];
				}
			}
			for (int j=0; j<28; j++){ //Media incassi mensile
				MEDIA[i]+=INCASSI[i][j];
			}
			MEDIA[i]/=12;
		}
	}
	
	MIN_anno=MIN[0]; //Minimo incasso annuo
	for (int i=1; i<12; i++){
		if (MIN_anno>MIN[i]){
			MIN_anno=MIN[i];
		}
	}
	
	MAX_anno=MAX[0]; //Massimo incasso annuo
	for (int i=1; i<12; i++){
		if (MAX_anno<MIN[i]){
			MAX_anno=MIN[i];
		}
	}
	
	
	for(int i=0;i<12;i++){ //Output
		cout<<"L'incasso medio mensile di "<<mese[i]<<" è stato di €"<<MEDIA[i]<<endl;
		cout<<"L'incasso massimo mensile di "<<mese[i]<<" è stato di €"<<MAX[i]<<endl;
		cout<<"L'incasso minimo mensile di "<<mese[i]<<" è stato di €"<<MIN[i]<<endl<<endl;
	}
	
	cout<<"L'incasso massimo annuo è stato di €"<<MAX_anno<<endl;
	cout<<"L'incasso minimo annuo è stato di €"<<MIN_anno<<endl;
	cout<<"L'incasso totale annuo è stato di €"<<MEDIA_anno<<endl;
	MEDIA_anno/=c; //Media incassi annua
	cout<<"L'incasso medio annuo è stato di €"<<MEDIA_anno<<endl;
	
return 0;
}

/*	
 * 	FOR FORMATTATO:
 * 	(j<31&&
 * 		(i==0||i==2||i==4||i==6||i==7||i==9||i==11)
 * 	)
 *	||
 *	(j<30&&
 * 		(i==3||i==5||i==8||i==10)
 * 	)
 * 	||
 * 	(i==1&&
 * 		(
 * 			(j<29&&
 * 				(
 * 					(anno%4==0&&anno%100!=0)||
 * 					anno%400==0
 * 				)
 * 			)||
 * 			(j<28&&
 * 				(
 * 					(anno%100==0&&anno%400!=0)||
 * 					anno%4!=0
 * 				)
 * 			)
 * 		)
 * 	)
 */
