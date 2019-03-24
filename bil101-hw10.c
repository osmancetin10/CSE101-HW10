						/***************************/
						/*                         */
						/*      Osman Çetin        */
						/*       161044069         */
						/*          HW-10          */
						/*                         */
						/***************************/
#include <stdio.h>
#include <time.h>/*random sayı atayan kütüphane*/
#include <stdlib.h>/*random sayı atayan kütüphane*/


#define BOYUT 6 /*Buradan dizinin boyutunu değiştirebiliriz*/


int eleman();/*eleman adlı fonksiyonumuzun prototipidir*/
void boy(int ciko[]);/*boy adlı fonksiyonumuzun prototipidir*/
void yarisma(int ciko[]);/*yarisma adlı fonksiyonumuzun prototipidir*/
/*Bu programımız mehmet ile ayşenin bayramda toplayıp da paylaşamadığı çikolataları düzenlenen yarışma ile paylaştırılmasını sağlayan bir hakemlik sistemidir. Çikolata boylarına göre yarışma yapılır. Kim daha çok yemişse o galip gelir ve program bunu açıklar*/

int main(){
	srand(time(NULL)); /*random sayı atamaya yarayan fonksiyon*/
	int i,ciko[BOYUT];
	for(i=0;i<BOYUT;i++){/*bu döngümüzün amacı çikolata dizimize rasgele değerler atamaktır*/ 
		ciko[i]=eleman();/*rasgele değer atamayı eleman adlı fonksiyon sağlar*/
	}
	
	boy(ciko);/*çikolata boylarının ekrana yazdırılması için bu fonksiyon çağrılır*/
	
	yarisma(ciko);/*yarışmayı başlatmak için bu fonksiyonumuzu çağırırız*/
	return 0;
}

int eleman(){/*Bu fonksiyonun amacı her çalıştığında rasgele sayı üretmektir*/
	int eleman=0;
	eleman=rand()%11+1;/* "%11+1" olarak belirlememizin sebebi çikolata boylarının 1-11 kapalı aralığında istenmesidir*/
	return eleman;
}

void boy(int ciko[]){/*bu fonksiyonun amacı çikolata boylarını ekrana yazdırmaktır*/
	printf("Çikolata Boyları ==>");
	for(int i=0;i<BOYUT;i++){
		printf("%d ",ciko[i]);
	} 
}		

void yarisma(int ciko[]){/*Bu fonksiyonumuz iki kişi arasındaki yarışmada sayaç ve hakemlik görevi yapıp galibi ilan etmeye yarar*/
	int i=0,j=BOYUT-1,k=0,mehmet,ayse;	
		while(ciko[i]>=0 && i<BOYUT && k==0){/*bu döngümüzün amacı çikolata boylarını sıfırdan büyük tutmak(her azalmadan sonra), dizimizin elemanları içinde sınırlı kalmaktır ve toplamda 5 durumu ele alır*/
			if(ciko[i]>1){/*eğer mehmet yediği çikolatanın boyu birden büyükse bu koşul uygulanır ve boy iki azaltılır*/
				ciko[i]=ciko[i]-2;
			}
			else if(ciko[i] == 0){/*eğer mehmetin yediği çikolatanın boyu sıfıra eşitse bir sonraki çikolataya geçilmesi sağlanır*/
				if(ciko[i+1]!=1){
					ciko[i+1]=ciko[i+1]-2;
					i++;
				}			
				else{/*eğer bir sonraki çikolatanın boyu 1 ise kendive kendinden bir sonraki çikolatanın boyu bir azaltılır*/ 
					ciko[i+1]--;
					ciko[i+2]--;
				}
			}
			else if(ciko[i] == 1 && i+1!=j){/*eğer mehmetin yediği çikolatanın boyu bire eşitse kendi ve kendinden bir sonraki çikolatanın boyu 1 azaltılır*/  
				ciko[i]--;
				ciko[i+1]--;
				i++;
			}		
			if(i!=j-1){/*son iki çikolatanın kalmama durumu ele alınmıştır*/
				if(ciko[j]>=1){/*eğer ayşenin yediği çikolatanın boyu birden büyükse çikolatanın boyu bir azaltılır*/
					ciko[j]--;
				}
				else if(ciko[j]==0){/*ayşenin yediği çikolatanın boyu sıfıra eşitse bir sonraki çikolatanın boyu 1 azaltılır*/
					ciko[j-1]--;
					j--;
				}
			}
			else/*eğer son iki çikolata kalmışsa yarışma sonlandırılır*/
				k++;		
		}
	mehmet=i+1;/*mehmetin yediği çikolata sayısı*/
	ayse=(BOYUT-1)-i;/*ayşenin yediği çikolata sayısı*/
	printf("\nMehmet:%d",mehmet);/*mehmetin yediği çikolata sayısını ekrana yazdırır*/
	printf("\nAyse:%d",ayse);/*ayşenin yediği çikolata sayısını ekrana yazdırır*/
	printf("\nKazanan:");/*kazananı ekrana yazdırır*/
	if(mehmet>ayse)/*eğer mehmetin yediği çikolata sayısı daha fazla ise galip mehmettir*/
		 printf("Mehmet\n");
	else if(mehmet<ayse)/*eğer ayşenin yediği çikolata sayısı daha fazla ise galip ayşedir*/
		printf("Ayse\n");
	else/*eğer ikisi de eşit sayıda çikolata yemişse yarışma berabere sonuçlanmıştır*/
		printf("Berabere\n");	 
}
