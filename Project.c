#include <stdio.h>
#include <math.h>
#define MAX 10
#define SIZE 100

void Bisection();
void Regula_Falsi();
void Newton_Rapshon();
void matris_Tersi();
void Gauss_Jordan();
void Gauss_Seidal();
void Sayisal_Turev();
void Simpson();
void Trapez();
void Gregory_Enterpolasyonu();
float Fx(float , int , float []);
float F1x(float , int , float []);

int main(){
	int choice, devam = 1;;
	
	
	while(devam == 1){
		
		printf("<==========Sayisal Analiz Final Projesi==========>\n\n");
		printf("\t1 -Bisection\n");
		printf("\t2 -Regula-Falsi\n");
		printf("\t3 -Newton-Rapshon\n");
		printf("\t4 -NxN'lik bir matrisin tersi\n");
		printf("\t5 -Gauss Eleminasyon\n");
		printf("\t6 -Gauss Seidal\n");
		printf("\t7 -Sayisal Turev (merkezi, ileri ve geri)\n");
		printf("\t8 -Simpson yontemi\n");
		printf("\t9 -Trapez yontemi\n");
		printf("\t10-Gregory Newton Enterpolasyonu\n");
		printf("\t0 -cikis\n\n");
		printf("<================================================>\n");
		printf("lutfen menuden bir secim yapiniz : ");
		scanf("%d", &choice);
		
		system("cls");
		
		switch(choice){
			case 1:
				Bisection();
				break;
			case 2:
				Regula_Falsi();
				break;
			case 3:
				Newton_Rapshon();
				break;
			case 4:
				matris_Tersi();
				break;
			case 5:
				Gauss_Jordan();
				break;
			case 6:
				Gauss_Seidal();
				break;
			case 7:
				Sayisal_Turev();
				break;
			case 8:
				Simpson();
				break;
			case 9:
				Trapez();
				break;
			case 10:
				Gregory_Enterpolasyonu();
				break;	
			case 0:
				devam = 0;
				break;	
			default:
				printf("\n\thatali secim lutfen bir daha deneyin\n");
				break;	
			
		}
	}
	
	return 0;
}

void Bisection(){
	system("cls");
	
	float katsayilar[MAX];
    float a, b, c, Fa, Fb, Fc = 1;
    float ep = 0.01, hata = 1;
    int i, derece, count = 0;

	printf("<==========Bisection Yontami==========>\n\n");
    printf("fonksiyon kacinci derece : ");
    scanf("%d", &derece);

    for(i=derece;i>=0;i--){
        printf("%d. dereceden x'in katsayisini giriniz :", i);
        scanf("%f", &katsayilar[i]);
    }

    printf("aralik giriniz [a,b]: ");
    scanf("%f %f", &a, &b);
    
    printf("epsilon degeri giriniz : ");
    scanf("%f", &ep);

    Fa = Fx(a,derece,katsayilar);
    Fb = Fx(b,derece,katsayilar);
	
	if(Fa * Fb <= 0 && b>a){
		
		if(Fa*Fb != 0){
		    i = 1;
		    hata = (b-a)/(2*i);
		    while (Fa * Fb < 0 && hata > ep){
		        c = (a+b)/2;
		        hata = (b-a)/(2*i);
		        i *= 2;
		        count ++;
		
		        Fa = Fx(a,derece,katsayilar);
		        Fb = Fx(b,derece,katsayilar);
		        Fc = Fx(c,derece,katsayilar);
		
		        if(Fa*Fc > 0){
		            a = c;
		        }else if(Fb*Fc > 0){
		            b = c;
		        }
		    }
		}else{
			if(Fa == 0){
				c = a;
			}else{
				c = b;
			}
		}
	
	    printf("kok(c) = %f\nintrasyon = %d", c, count);
		
	}else{
		printf("Error: F(a) * F(b) < 0 ve b > a olmali\n");
	}
	printf("\n\n");
	system("pause");
	system("cls");
}

void Regula_Falsi(){
	system("cls");
	
	float katsayilar[MAX];
    float a, b, c, Fa, Fb, Fc = 1;
    float ep = 0.01, hata,x;
    int i, derece, count = 0;

	printf("<==========Regula-Falsi Yontami==========>\n\n");
    printf("fonksiyon kacinci derece : ");
    scanf("%d", &derece);

    for(i=derece;i>=0;i--){
        printf("%d. dereceden x'in katsayisini giriniz :", i);
        scanf("%f", &katsayilar[i]);
    }

    printf("aralik giriniz [a,b]: ");
    scanf("%f %f", &a, &b);
    
    printf("epsilon degeri giriniz : ");
    scanf("%f", &ep);

    Fa = Fx(a,derece,katsayilar);
    Fb = Fx(b,derece,katsayilar);
    
    if(Fa * Fb <= 0 && b>a){
    	
    	if(Fa*Fb != 0){
		    i = 1;
		    hata = (b-a)/(2*i);
		    while (hata > ep){
		        x = c;
		        hata = (b-a)/(2*i);
		        i *= 2;
		        count ++;
		
		        Fa = Fx(a,derece,katsayilar);
		        Fb = Fx(b,derece,katsayilar);
		        
		        c = (b*Fa - a*Fb)/(Fa-Fb);
		        
		        Fc = Fx(c,derece,katsayilar);
		
		        if(Fa*Fc > 0){
		            a = c;
		        }else if(Fb*Fc > 0){
		            b = c;
		        }
		        
		    }
		}else{
			if(Fa == 0){
				c = a;
			}else{
				c = b;
			}
		}
	    printf("c = %f \nintrasyon = %d\n", c, count);
	
	}else{
		printf("Error: F(a) * F(b) < 0 ve b > a olmali\n");
	}
	printf("\n\n");
	system("pause");
	system("cls");
}

void Newton_Rapshon(){
	system("cls");
	
	float katsayilar[MAX];
	float x1, x2, hata = 1, ep=0.1;
	float Fa, m;
	int derece, count = 0;
	int i;
	
	printf("<==========Newton Rapshon Yontami==========>\n\n");
	printf("fonksiyon kacinci derece : ");
    scanf("%d", &derece);

    for(i=derece;i>=0;i--){
        printf("%d. dereceden x'in katsayisini giriniz :", i);
        scanf("%f", &katsayilar[i]);
    }
    
    printf("baslangic degeri giriniz : ");
    scanf("%f", &x1);
    
    Fa = Fx(x1,derece,katsayilar);
	m = F1x(x1,derece,katsayilar);
    
    do{
    	Fa = Fx(x1,derece,katsayilar);
	    m = F1x(x1,derece,katsayilar);
	    
	    x2 = x1-(Fa/m);
	    
	    hata = fabs(x2-x1);
	    x1 = x2;
	    count++;
    	
	}while(hata>ep);
	
	printf("kok = %f degeri = %f itrasyon = %d", x1, Fa, count);

	printf("\n\n");
	system("pause");
	system("cls");	
}

void matris_Tersi(){
	system("cls");
	
	/*
	NOT: matrisin kosegen elmankari 0'dan farkli olmali
	*/
	
	float matrix[SIZE][SIZE], inv_matrix[SIZE][SIZE];
	int n, err = 0;
	int i,j,k;
	
	printf("<==========Matrisin Tersi Bulma==========>\n\n");
	printf("matris mertebesini giriniz : ");
	scanf("%d", &n);

//matris okuma	
	printf("matris elemanlarini giriniz\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%f", &matrix[i][j]);
		}
		if(matrix[i][i] == 0){
			err = 1;
		}
	}

	if(err == 0){
	
	//birim matrisi saga ekleyip degeleri 0 ve 1 atama	
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i==j){
					inv_matrix[i][j] = 1;
				}else{
					inv_matrix[i][j] = 0;
				}
			}
		}
	
	//gauss jordan kurali ile invers
		for(i=0;i<n;i++){
			for(k=0;k<n;k++){
			    if(k!=i){
				    matrix [i][k] /= matrix[i][i];   
				}
				inv_matrix[i][k] /= matrix[i][i];
			}
			matrix [i][i] = 1; // matrix[i][i] /= matrix[i][i]; == 1
			
			for(j=0;j<n;j++){
				if(j != i){
					for(k=0;k<n;k++){
						if(k!=i){
							matrix[j][k] -= matrix[j][i]*matrix[i][k];
						}
						inv_matrix[j][k] -= matrix[j][i]*inv_matrix[i][k];
					}
					matrix[j][i] = 0;
				}
			}
		}
	//inversi yazdirma
		printf("\ninvers matris\n");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				printf("%7.4f ", inv_matrix[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("Error: matrisin kosegen elmankari 0'dan farkli olmali!");
	}
	printf("\n\n");
	system("pause");
	system("cls");
}

void Gauss_Jordan(){
	system("cls");
	
	float matrix[SIZE][SIZE], coz_matrix[SIZE];
	int n, err = 0;
	int i,j,k;
	
	printf("<==========Gauss Jordan Yontami==========>\n\n");
	printf("katsayilar matrisi mertebesini giriniz (denklem sayisi) : ");
	scanf("%d", &n);

//matris okuma	
	for(i=0;i<n;i++){
		printf("%d. denklemin degisken katsyilarini giriniz : \n",i+1);
		for(j=0;j<n;j++){
			scanf("%f", &matrix[i][j]);
		}
		if(matrix[i][i] == 0){
			err = 1;
		}
	}

	if(err == 0){

		printf("sonuc degeleri giriniz\n");
		for(i=0;i<n;i++){
			printf("c%d:",i+1);
			scanf("%f", &coz_matrix[i]);
		}
	
	//gauss jordan kurali ile cozum
		for(i=0;i<n;i++){
			for(k=0;k<n;k++){
			    if(k!=i){
				    matrix [i][k] /= matrix[i][i];   
				}
			}
			coz_matrix[i] /= matrix[i][i];
			matrix [i][i] = 1;
			for(j=0;j<n;j++){
				if(j != i){
					for(k=0;k<n;k++){
						if(k!=i){
							matrix[j][k] -= matrix[j][i]*matrix[i][k];
						}
					}
					coz_matrix[j] -= matrix[j][i]*coz_matrix[i];
					matrix[j][i] = 0;
				}
			}
		}
	
		printf("\ncozum :\n");
		for(i=0;i<n;i++){
				printf("x%d = %.2f\n", i+1, coz_matrix[i]);
		}
	}else{
		printf("Error: matrisin kosegen elmankari 0'dan farkli olmali!");	
	}
	
	printf("\n\n");
	system("pause");
	system("cls");
}

void Gauss_Seidal(){
	system("cls");
	
	float matris[SIZE][SIZE], sonuclar[SIZE], degerler[SIZE], farklar[SIZE];
	float tmp;
	int n;
	int devam = 1;
	float toplam, hata = 0.001;
	int i, j;
		
	printf("<==========Gauss Seidal Yontami==========>\n\n");
	printf("katsayilar matrisi mertebesini giriniz (denklem sayisi) : ");
	scanf("%d", &n);
	
	for(i=0;i<n;i++){
		printf("%d. denklemin bilinmeyen katsyilarini giriniz : \n",i+1);
		for(j=0;j<n;j++){
			scanf("%f", &matris[i][j]);
		}
	}
	
	printf("sonuc degeleri giriniz\n");
	for(i=0;i<n;i++){
		printf("c%d:",i+1);
		scanf("%f", &sonuclar[i]);
	}
	
	printf("baslangic degeleri giriniz\n");
	for(i=0;i<n;i++){
		printf("x%d:",i+1);
		scanf("%f", &degerler[i]);
	}
	
	printf("hata degeri giriniz : ");
	scanf("%f", &hata);

	while(devam == 1){
		
		for(i=0;i<n;i++){
			toplam = 0;
			for(j=0;j<n;j++){
				if(i!=j){
					toplam += matris[i][j]*degerler[j];
				}
			}
			tmp = degerler[i];
			degerler[i] = (sonuclar[i] - toplam)/matris[i][i];
			farklar[i] = fabs(degerler[i]-tmp);
		}
		
		
		i=0;
		devam = 0;
		while(i<n && devam == 0){
			if(farklar[i]>hata){
				devam = 1;
			}
			i++;	
		}
		
	}
	
	for(i=0;i<n;i++){
		printf("x%d = %f\n", i+1, degerler[i]);
	}
	
	printf("\n\n");
	system("pause");
	system("cls");
}

void Sayisal_Turev(){
	system("cls");
	
	float katsayilar[MAX];
	float x, h, DF;
	int i, derece;
	
	printf("<==========Sayisal Turev==========>\n\n");
	printf("fonksiyon kacinci derece : ");
    scanf("%d", &derece);

    for(i=derece;i>=0;i--){
        printf("%d. dereceden x'in katsayisini giriniz :", i);
        scanf("%f", &katsayilar[i]);
    }
    
    printf("turevini bulmak istediginiz noktayi giriniz : ");
    scanf("%f", &x);
    
    printf("h degerini giriniz : ");
    scanf("%f", &h);
    
    
    DF = (Fx(x,derece,katsayilar) - Fx(x-h,derece,katsayilar))/h;
	printf("geri farklar ile turev    \t= %.2f\n\n", DF);

	DF = (Fx(x+h,derece,katsayilar) - Fx(x,derece,katsayilar))/h;
	printf("ileri farklar ile turev   \t= %.2f\n\n", DF);
	
	DF = (Fx(x+h,derece,katsayilar) - Fx(x-h,derece,katsayilar))/(2*h);
	printf("merkezi farklar ile turev \t= %.2f\n\n", DF);
	
	printf("\n\n");
	system("pause");
	system("cls");
}

void Simpson(){
	system("cls");
	
	float katsayilar[MAX];
	float a, b, h, I;
	int n, derece;
	int i;
	
	printf("<==========Simpson 1/3 Yontami==========>\n\n");
	printf("fonksiyon kacinci derece : ");
    scanf("%d", &derece);

    for(i=derece;i>=0;i--){
        printf("%d. dereceden x'in katsayisini giriniz :", i);
        scanf("%f", &katsayilar[i]);
    }
    
    printf("integralini bulmak istediginiz araligi giriniz [a,b]: ");
    scanf("%f %f", &a, &b);
    
    printf("aralikta parca sayisini giriniz (cift sayi olmali): ");
    scanf("%d", &n);
    
    h = (b-a)/n;
    I= (Fx(a,derece,katsayilar) + Fx(b,derece,katsayilar));

	for(i=1;i<n;i++){
		if(i%2==1){
			I += 4*Fx(a+(h*i),derece,katsayilar);
		}else{
			I += 2*Fx(a+(h*i),derece,katsayilar);
		}
		//printf("integral = %.2f\n", I*h/3);
	}
	I *= (h/3);
	printf("integral = %.4f\n", I);
	
	printf("\n\n");
	system("pause");
	system("cls");
}

void Trapez(){
	system("cls");
	
	float katsayilar[MAX];
	float a, b, h, I;
	int n, derece;
	int i;
	
	printf("<==========Trapez Yontami==========>\n\n");
	printf("fonksiyon kacinci derece : ");
    scanf("%d", &derece);

    for(i=derece;i>=0;i--){
        printf("%d. dereceden x'in katsayisini giriniz :", i);
        scanf("%f", &katsayilar[i]);
    }
    
    printf("integralini bulmak istediginiz araligi giriniz [a,b]: ");
    scanf("%f %f", &a, &b);
    
    printf("aralikta parca sayisini giriniz : ");
    scanf("%d", &n);
    
    h = (b-a)/n;
    I= (Fx(a,derece,katsayilar) + Fx(b,derece,katsayilar))/2;
    for(i=1;i<n;i++){
    	I += Fx(a+(h*i),derece,katsayilar);
	}
	I *= h;
	printf("integral = %.2f\n", I);
	
	
	printf("\n\n");
	system("pause");
	system("cls");
}

void Gregory_Enterpolasyonu(){
	system("cls");
	
	float x_ler[SIZE], y_ler[SIZE][SIZE] = {0};
	float x, h, payda, faktoryel, tmp;
	float sonuc;
	int n, m, count, devam = 1;
	int i, j;
	
	printf("<==========Gregory Newton Enterpolasyonu==========>\n\n");
	printf("kac tane X degeri var : ");
	scanf("%d", &n);
	
	printf("ilk X degeri : ");
	scanf("%f", &x_ler[0]);
	
	printf("X degerleri arasindaki fark (h) : ");
	scanf("%f", &h);
	
	for(i=1;i<n;i++){
		x_ler[i] = x_ler[i-1] + h;
	}
	
	for(i=0;i<n;i++){
		printf("f(%.1f) Y degeri giriniz giriniz : ",x_ler[i]);
		scanf("%f", &y_ler[i][0]);
	}
	
	printf("bulmak istediginiz X degeri giriniz : ");
	scanf("%f", &x);
	
	m = 1;
	while(devam == 1 && m<n){
		
		for(i=0;i<n-1;i++){
			y_ler[i][m] = y_ler[i+1][m-1] - y_ler[i][m-1];
		}
		i=0;
		devam = 0;
		while(i<n-m-2 && devam == 0){
			if( (y_ler[i][m]) != (y_ler[i+1][m]) ){
				devam = 1;
			}
			i++;	
		}
		m++;
	}
	
	printf("\n");
	for(i=0;i<n;i++){
		j = 0;
		while(j<n-i && j<m){
			printf("%8.2f | ",y_ler[i][j]);
			j++;
		}
		printf("\n");
	}

	sonuc = 0;
	faktoryel = 1;
	for(i=0;i<m;i++){
		if(i!=0){
			faktoryel *= i;
		}
		tmp = 1;
		for(j=0;j<i;j++){
			tmp *= (x-x_ler[j]);
		}
		sonuc += (y_ler[0][i] * tmp) / (pow(h,i)*faktoryel);
	}
	
	printf("\n\nsonuc = %.1f\n", sonuc);
	
	printf("\n\n");
	system("pause");
	system("cls");
}

float Fx(float x, int derece, float katsayilar []){
    int i;
    float F = 0;

    for(i=derece;i>=0;i--){
        F += katsayilar[i]*pow(x,i);
    }

    return F;
}

float F1x(float x, int derece, float katsayilar[]){
	int i;
	float F = 0;
	
	for(i=derece;i>0;i--){
		F += katsayilar[i]*i*pow(x,i-1);
	}
	
	return F;
}

