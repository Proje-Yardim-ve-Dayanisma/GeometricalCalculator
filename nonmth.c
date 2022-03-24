#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

int main(){
    setlocale(LC_ALL, "Turkish");
    int secenek; // Geometrik �ekillerde se�im yapmak i�in. 
    float kenar1, kenar2, kenar3, kenar4, kenar5; // Kenarortay teoremlerinde kullan�ld�.
    float kenar1kare, kenar2kare, kenar3kare, kenar4kare, kenar5kare; // Kenarortay teoremlerinde kullan�ld�.
    float kenar2fark, kenar1fark, kenar3fark; // ��gende a��-kenar ba��nt�lar�nda kullan�ld�.
    float kenar2top, kenar1top, kenar3top; // ��gende a��-kenar ba��nt�lar�nda kullan�ld�.
    float hae; // Y�kseklik ve a��ortay�n aras�ndaki a��.
    char tepenok; // ��gende tepe noktas� belirlemek i�in kullan�ld�.
    int secenek2, secenek3; // A��ortaylar i�in ^.
    char alansecim[3]={'N','E','I'}; // ��gende alan i�in.
    int secenek5; // Kenarortay hesaplama y�ntemleri i�in.
    int secim; // �klid ba��nt�s� i�in.
    float a, b, c, h, p, k; // �klid ba��nt�s� i�in.
    char secenek4[3]={'a','b','c'}; // Kenarortaylarda kullan�ld�.^
    float utaban;
    float yukseklik;
    float alan, u;
    float cevre;
    float utabankare;
    float yukseklikkare;
    float hipotenuskare;
    float ikizkenar;
    // ��genler ile ilgili hesaplamalar�n de�i�kenleri.^
    float aci;
    float aci2;
    float acisonuc;
    float disaci;
    float disaci2;
    char acilar[2]={'A','N'};
    // A��lar ile ilgili hesaplamalar�n de�i�kenleri.^
    float taban;
    float kenar;
    float kenarkare;

    char s[4]={'u','d','b','a'};
    printf("Hesaplama yapmak istedi�iniz �eklin ba� harfini giriniz [u,d,b,a]: ");
    scanf("%s",&s);

    if (*s == 'u'){
        printf("\n1.Secenek : Dik ��genle ilgili uzunluk ve alan hesaplamalar�n� i�erir.\n");
        printf("2.Secenek : ��gende alan hesaplamas�na gider.\n");
        printf("3.Secenek : ��gende a��/a�� ortay ile ilgili hesaplamalar yapar.\n");
        printf("4.Secenek : ��gende kenarortay hesaplamas� yapar.\n");
        printf("5.Secenek : ��gende a��/kenar ba��nt�lar�n� kullanarak size bilinmeyen bir kenar�n alabilece�i maks. ve min. de�erleri s�yler.\n");
        printf("6.Secenek : Muhte�em ��l� hesaplamas� yapar.\n");
        printf("7.Secenek : �klid Ba��nt�lar�nda hesaplama yapman�za olanak sa�lar.\n");

        printf("8.Secenek : �kizkenar ��genle ilgili bilgileri i�erir.\n");
        printf("9.Secenek : E�kenar ��genle ilgili bilgileri i�erir.\n");
        printf("\n Se�enek se�iniz: ");
        scanf("%d",&secenek);

        switch (secenek){
            case 1: // Dik ��genler; ikizkenar dik ��genler ve dik ��genler olmak �zere iki ayr� blokta incelenir.
                printf("\nDik olmayan a��lardan birisini giriniz: ");
                scanf("%f",&aci);
                if(aci==45){
                    printf("\nGirilen a�� bilgisine g�re 'ikizkenar dik ��gen' �zerinde i�lem yap�lacakt�r.\n");
                    printf("\n�kizkenarlardan birisinin uzunlu�unu giriniz:m ");
                    scanf("%f",&ikizkenar);
                    printf("\nHipoten�s uzunlu�u: %.1f K�K 2 m'dir.",ikizkenar);
                    alan = ikizkenar*ikizkenar/2;
                    printf("\nAlan: %.1f m^2'dir.",alan);
                    cevre = ikizkenar*2;
                    printf("\n�evre: %.1f+%.1f K�K 2 m'dir.",cevre,ikizkenar);
                    break;
                }
            
                else if (aci>=1 && aci<=89){
                    printf("\nBu normal bir dik ��gendir.\n");
                    printf("\nTaban uzunlu�unu giriniz:m ");
                    scanf("%f",&utaban);
                    printf("Yukseklik uzunlugunu giriniz:m ");
                    scanf("%f",&yukseklik);
                    alan = utaban*yukseklik/2;
                    utabankare = utaban*utaban;
                    yukseklikkare = yukseklik*yukseklik;
                    hipotenuskare = utabankare+yukseklikkare;
                    cevre = utaban + yukseklik + sqrt(hipotenuskare);
                    printf("\nHipoten�s de�eri: %.1f m'dir\n",sqrt(hipotenuskare));
                    printf("Alan de�eri: %.1f m^2'dir.\n",alan);
                    printf("�evre de�eri: %.1f m'dir.",cevre);
                    break;
                }

                else{
                    printf("\nTek a��s� zaten 90�olan bir ��genin di�er bir a��s� %d�olamaz.",aci);
                }
                break;
            case 3: // A�� hesaplamas� yap�l�r.
                printf("\nA��ortay teoremleri ile mi, normal a�� hesaplamas� m� yapacaks�n�z [A/N]:  ");
                scanf("%s",&acilar);
                if (*acilar=='A'){
                    printf("\n1.Se�enek :�� i�e���genlerde i� a���ortay kural�n� kullanarak tepe a��s��bulman�z� sa�lar.\n");
                    printf("2.Se�enek :Tabanlar�ndan ters �ekilde birbirine yap��m�����genlerde (d�rtgene benzeyen) d�� a��ortay kural�n� kullanarak z�t iki tepedeki a��lar� bulman�z� sa�lar.\n");
                    printf("3.Se�enek :Bir ABC ��geninde tepe noktas�ndan tabana inen y�kseklik do�rusu [AH] ile a��ortay do�rusunun [AE] aras�ndaki a��y� m(HAE)'i hesaplar.\n");
                    printf("4.Se�enek :ABC ��geninde; [BP] i� a�� ortay ise, [PC] ABC ��genindeki C a��s�n�n d�� a��ortay� ise PBC ��geninde m(P)'i hesaplar.\n");
                    printf("\n6.Se�enek :�� A�� ortay Teoremi ile ABC ��geninin kenar uzunluklar�n� hesaplar.\n");
                    printf("7.Se�enek :�� A�� ortay Teoremi ile ABC ��geninde [AN] i� a�� ortay do�rusunun uzunlu�unu hesaplar.\n");
                    printf("\n8.Se�enek :D�� A���ortay Teoremi ile ABC ��geninin kenar uzunluklar�n� hesaplar.\n");
                    printf("9.Se�enek :D�� A���ortay Teoremi ile ABC ve ABN ��geninde [AN] d�� a��ortay do�rusunun uzunlu�unu hesaplar.\n");
                    printf("\nSe�enek se�iniz: ");
                    scanf("%d",&secenek2);
                    switch (secenek2){
                    
                    case 1:
                        printf("\nABC ��geninin i�inde DBC ��geni vard�r. [BD] ve [CD] i� a���ortaylard�r.\n");
                        printf("\nHesaplamak istedi�iniz tepenin a��s�n� tek harf �eklinde yaz�n�z [D/A]: "), scanf("%s",&tepenok);
                        if(tepenok=='A'){
                            do{
                                printf("\nm(D) a��s�n� giriniz, bilmiyorsan�z '0' giriniz: "), scanf("%f",&aci2);
                                if(aci2==0) printf("m(D) a��s�n�n d�� a��s�n� giriniz: "), scanf("%f",&disaci2), aci2=180-disaci2;
                                if(aci2<=90){ printf("\nm(A) a��s� 0�veya 0�'den k���k olamaz.\n");}
                                if(aci2==180){ printf("\nm(A) a��s� tek ba��na 180� olamaz.\n");}
                            }while(aci2<=90 || aci2==180);
                            aci=2*aci2-180 ,printf("m(A) %.1f�'dir.",aci);
                        }
                        else if(tepenok=='D'){ 
                            do{
                                printf("\nm(A) a��s�n� giriniz, bilmiyorsan�z '0' giriniz:� "), scanf("%f",&aci);
                                if(aci==0) printf("m(A) a��s�n�n d�� a��s�n� giriniz: "), scanf("%f",&disaci), aci=180-disaci;
                                if(aci==180){printf("m(D) a��s� tek ba��na 180� olamaz.");}
                            }while(aci==180);
                            aci2=aci/2+90 ,printf("m(D) %.1f�'dir.",aci2);
                        }
                        break;
                    case 2:
                        printf("\nABC ��geninin taban�na ters bir �ekilde yap�p�m(FBC) ��geni vard�r; [BF] ve [CF] ABC ��geninin d���a�� ortaylar�d�r.\n");
                        printf("\nHesaplamak istedi�iniz tepenin a��s�n�n tek harf �eklinde yaz�n�z [F/A]: "), scanf("%s",&tepenok);
                        if(tepenok=='A'){
                            do{
                                printf("\nm(F) a��s�n� giriniz, bilmiyorsan�z '0' giriniz: "), scanf("%f",&aci2);
                                if(aci2==0) printf("m(F) a��s�n�n d�� a��s�n� giriniz: "), scanf("%f",&disaci2), aci2=180-disaci2;
                                if(aci2>=90){printf("\nm(A) a��s� 0�veya 0'den k���k olamaz. Tekrar de�er giriniz ya da program�sonland�r�n�z. (CTRL+C)");}
                            }while(aci2>=90);
                            aci=180-2*aci2 ,printf("m(A) %.1f�'dir.",aci);
                        }
                        else if(tepenok=='F'){
                            do{ 
                                printf("\nm(A) a��s�n�n de�erini giriniz:� "), scanf("%f",&aci);
                                if(aci==0) printf("m(A) a��s�n�n d�� a��s�n� giriniz: "), scanf("%f",&disaci), aci=180-disaci;
                                if(aci==180){printf("\nm(F) a��s� tek ba��na 0� olamaz. Tekrar de�er giriniz ya da program� sonland�r�n�z. (CTRL+C)");}
                            }while(aci==180);
                            aci2=90-aci/2 ,printf("m(F) %.1f�'dir.",aci2);
                        }
                        break;
                    case 3:
                        do{
                            printf("\nm(B) a��s�n� giriniz bilmiyorsan�z '0' giriniz: ");
                            scanf("%f",&aci);
                            if(aci==0) printf("m(B) a��s�n�n d�� a��s�n� giriniz: "), scanf("%f",&disaci), aci=180-disaci;
                            if(aci==180){printf("m(B) a��s�n� tek ba��na 180 olamaz.");}

                            printf("\nm(C) a��s�n� giriniz: bilmiyorsan�z '0' giriniz: ");
                            scanf("%f",&aci2);
                            if(aci2==0) printf("m(C) a��s�n� d�� a��s�n� giriniz: "), scanf("%f",&disaci2), aci2=180-disaci2;
                            if(aci2==180){printf("m(C) a��s� tek ba��na 180 olamaz.");}
                        }while(aci==180 || aci2==180);

                        hae=(aci-aci2)/2;
                        acisonuc=abs(hae); 
                        printf("\n\nForm�l : m(HAE) = |m(B) - m(C)|/2\n");
                        printf("|%.1f - %.1f|/2 = %.1f",aci,aci2,acisonuc); 
                        break;

                    case 4:
                        printf("\nHesaplamak istedi�iniz tepenin a��s�n� tek harf �eklinde yaz�n�z [P/A]: "), scanf("%s",&tepenok);
                        if(tepenok=='A'){
                            do{
                                printf("\nm(P) a��s�n� giriniz, bilmiyorsan�z '0' giriniz:� "), scanf("%f",&aci2);
                                if(aci2==0) printf("m(P) a��s�n�n d�� a��s�n� giriniz: "), scanf("%f",&disaci2), aci2=180-disaci2;
                                if(aci2>=90 || aci2==180){ printf("m(A) veya m(P) a��s� 180�veya 180'den b�y�k olamaz.");}
                            }while(aci2>=90 || aci2==180);
                            aci=aci2*2 ,printf("\nm(A) %.1f�'dir.",aci);
                        }
                        else if(tepenok=='P'){
                            do{
                            printf("\nm(A) a��s�n�n de�erini giriniz, bilmiyorsan�z '0' giriniz:� "), scanf("%f",&aci);
                            if(aci==0) printf("m(A) a��s�n�n d�� a��s�n� giriniz: "), scanf("%f",&disaci), aci=180-disaci;
                            if(aci==180){ printf("m(A) a��s� 180 olamaz.");}
                            }while(aci==180);
                            aci2=aci/2 ,printf("\nm(P) %.1f�'dir.",aci2);
                        }
                        break;
                    case 6:
                        printf("\n1:[AB], 2:[AC], 3:[NB], 4:[NC]");
                        printf("\nABC ��geninde [AN] i� a��ortay do�rusudur ve hesaplamak istedi�iniz kenar� giriniz [1/2/3/4]: ");
                        scanf("%d",&secenek3);
                        if(secenek3==1){
                            do{
                                printf("\n[AC] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar2==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[NB] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar3==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[NC] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar4);
                                if(kenar4==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                            }while(kenar2==0 || kenar3==0 || kenar4==0);
                            kenar1=kenar2*kenar3/kenar4;
                            printf("\n[AB] kenar�n�n uzunlu�u %.1f cm'dir.",kenar1);
                            break;
                        }
                        else if(secenek3==2){
                            do{
                                printf("\n[AB] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar1);
                                if(kenar1==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[NB] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar3==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[NC] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar4);
                                if(kenar4==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                            }while(kenar1==0 || kenar3==0 || kenar4==0);
                            kenar2=kenar1*kenar4/kenar3;
                            printf("\n[AC] kenar�n�n uzunlu�u %.1f m'dir.",kenar2);
                            break;
                        }
                        else if(secenek3==3){
                            do{
                                printf("\n[AB] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar1);
                                if(kenar1==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[AC] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar2==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[NC] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar4);
                                if(kenar4==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                            }while(kenar1==0 || kenar2==0 || kenar4==0);
                            kenar3=kenar1*kenar4/kenar2;
                            printf("\n[AC] kenar�n�n uzunlu�u %.1f m'dir.",kenar3);
                            break;
                        }
                        else if(secenek3==4){
                            do{
                                printf("\n[AB] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar1);
                                if(kenar1==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[AC] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar2==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[NB] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar3==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                            }while(kenar1==0 || kenar2==0 || kenar3==0);
                            kenar4=kenar2*kenar3/kenar1;
                            printf("\n[AC] kenar�n�n uzunlu�u %.1f m'dir.",kenar4);
                            break;
                        }
                        break;
                    case 7:
                        do{
                            printf("\n1 [AB]:m ");
                            scanf("%f",&kenar1);
                            printf("\n2 [AC]:m ");
                            scanf("%f",&kenar2);
                            printf("\n3 [NB]:m ");
                            scanf("%f",&kenar3);
                            printf("\n4 [NC]:m ");
                            scanf("%f",&kenar4);
                            if(kenar1<=0 || kenar2<=0 || kenar3<=0 || kenar4<=0){printf("\nKenar de�erlerinden birisine 0 veya negatif bir de�er girdiniz. L�tfen tekrar deneyiniz veya program� sonland�r�n�z. (CTRL+C)\n");}
                        }while(kenar1<=0 || kenar2<=0 || kenar3<=0 || kenar4<=0);
                        kenar5=kenar1*kenar2-kenar3*kenar4;
                        if(kenar5==0){printf("\nKenar de�eri 0 veya negatif olamaz."); break;}
                        printf("\n[AN] i� a��ortay do�rusunun uzunlu�u %.2f m'dir.",sqrt(abs(kenar5)));
                        break;
                    case 8:
                        printf("\n1:[AB], 2:[AC], 3:[BN], 4:[CN]");
                        printf("\nABC ve ABN ��gendir; [AN] d�� a��ortay do�rusudur ve hesaplamak istedi�iniz kenar� giriniz [1/2/3/4]: ");
                        scanf("%d",&secenek3);
                        if(secenek3==1){
                            do{
                                printf("\n[AC] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar2==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[BN] kenar�n�n uzunlu�unu giriniz: ");
                                scanf("%f",&kenar3);
                                if(kenar3==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[CN] kenar�n�n uzunlu�unu giriniz: ");
                                scanf("%f",&kenar4);
                                if(kenar4==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                            }while(kenar2==0 || kenar3==0 || kenar4==0);
                            kenar1=kenar3*kenar4/kenar2;
                            printf("\n[AB] kenar�n�n uzunlu�u %.1f m'dir.",kenar1);
                            break;
                        }
                        else if(secenek3==2){
                            do{
                                printf("\n[AB] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar1);
                                if(kenar2==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[BN] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar3==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[CN] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar4);
                                if(kenar4==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                            }while(kenar1==0 || kenar3==0 || kenar4==0);
                            kenar2=kenar3*kenar4/kenar1;
                            printf("\n[AC] kenar�n�n uzunlu�u %.1f m'dir.",kenar2);
                            break;
                        }
                        else if(secenek3==3){
                            do{
                                printf("\n[AB] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar1);
                                if(kenar1==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[AC] kenar�n�n uzunlu�unu giriniz: ");
                                scanf("%f",&kenar2);
                                if(kenar2==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[CN] kenar�n�n uzunlu�unu giriniz: ");
                                scanf("%f",&kenar4);
                                if(kenar4==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                            }while(kenar1==0 || kenar2==0 || kenar4==0);
                            kenar3=kenar1*kenar2/kenar4;
                            printf("\n[BN] kenar�n�n uzunlu�u %.1f m'dir.",kenar3);
                            break;
                        }
                        else if(secenek3==4){
                            do{
                                printf("\n[AB] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar1);
                                if(kenar1==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[AC] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar2==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                                printf("[BN] kenar�n�n uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar3==0){printf("Kenar uzunlu�u 0 m olamaz.");}
                            }while(kenar1==0 || kenar2==0 || kenar3==0);
                            kenar4=kenar1*kenar2/kenar3;
                            printf("\n[CN] kenar�n�n uzunlu�u %.1f m'dir.",kenar4);
                            break;
                        }
                        break;
                    case 9:                 
                        do{
                            printf("\n1 [AB]:m ");
                            scanf("%f",&kenar1);
                            printf("\n2 [AC]:m ");
                            scanf("%f",&kenar2);
                            printf("\n3 [BN]:m ");
                            scanf("%f",&kenar4);
                            printf("\n4 [BC]:m ");
                            scanf("%f",&kenar3);
                            if(kenar1<=0 || kenar2<=0 || kenar3<=0 || kenar4<=0){printf("\nKenar de�erlerinden birisine 0 veya negatif bir de�er girdiniz. L�tfen tekrar deneyiniz veya program� sonland�r�n�z. (CTRL+C)\n");}
                        }while(kenar1<=0 || kenar2<=0 || kenar3<=0 || kenar4<=0);
                        kenar5=kenar1*kenar2-kenar4*kenar3;
                        if(kenar5==0){printf("\nKenar de�eri 0 veya negatif olamaz."); break;}
                        printf("\n[AN] d�� a��ortay do�rusunun uzunlu�u %.2f m'dir.",sqrt(abs(kenar5)));
                        break;
                    default:
                        printf("Ge�ersiz bir se�enek se�tiniz!");
                        break;
                    }
                }
                else if(*acilar=='N'){
                    printf("\nA�� giriniz, bilmiyorsan�z '0' de�erini giriniz:� ");
                    scanf("%f",&aci);
                    printf("�kincil a��y� giriniz, bilmiyorsann�z '0' de�erini giriniz:� ");
                    scanf("%f",&aci2);

                    if (aci==0 && aci2==0){
                        printf("\nBilmedi�iniz birinci a��n�n d�� a�� de�erini giriniz:� ");
                        scanf("%f",&disaci);
                        aci=180-disaci;
                        printf("\nBilmedi�iniz ikinci a��n�n d�� a�� de�erini giriniz:� ");
                        scanf("%f",&disaci2);
                        aci2=180-disaci2;
                    }

                    else if (aci==0 || aci2==0){
                        if(aci==0) printf("\nBirinci a��n�n d�� a�� de�erini giriniz:� "), scanf("%f",&disaci), aci=180-disaci;
                    
                        if(aci2==0) printf("\n�kinci a��n�n d�� a�� de�erini giriniz:� "), scanf("%f",&disaci2), aci2=180-disaci2;

                    }
                    acisonuc=180-aci-aci2;
                    printf("\nBilinmeyen 3.a�� %.1f�'dir. ",acisonuc);
                }
                break;

            case 2: // ��gende alan hesaplamas�.
                printf("E�kenar, ikizkenar, uzunluklar� bilinen normal bir ��gen aras�nda se�im yap�n�z [N/I/E]: ");
                scanf("%s",&alansecim);
                if (*alansecim=='N'){
                    do{
                        printf("\nABC ��geni i�in; ");
                        printf("\n[AB] kenar�n�n uzunlu�unu giriniz:m ");
                        scanf("%f",&kenar1);
                        if(kenar1<=0){printf("Kenar uzunlu�u 0 m olamaz.");}
                        printf("[BC] kenar�n�n uzunlu�unu giriniz:m ");
                        scanf("%f",&kenar2);
                        if(kenar2<=0){printf("Kenar uzunlu�u 0 m olamaz.");}
                        printf("[CA] kenar�n�n uzunlu�unu giriniz:m ");
                        scanf("%f",&kenar3);
                        if(kenar3<=0){printf("Kenar uzunlu�u 0 m olamaz.");}
                    }while(kenar1<=0 || kenar2<=0 || kenar3<=0);
                    kenar4=kenar3+kenar2+kenar1; // Kenarlar� toplamam�z laz�m. Ard�ndan ikiye b�l�p "u" de�erini bulmal�y�z.
                    u=kenar4/2;
                    printf("\nABC ��geninin alan� %.4f m^2'dir .",sqrt(u*(u-kenar1)*(u-kenar2)*(u-kenar3)));
                }
                else if (*alansecim=='I'){
                    printf("\nTaban uzunlu�unu giriniz:m ");
                    scanf("%f",&utaban);
                    printf("Y�kseklik uzunlu�unu giriniz:m ");
                    scanf("%f",&yukseklik);
                    alan = utaban*yukseklik/2;
                    printf("\nAlan de�eri: %.2f m^2'dir.\n",alan);
                }
                else if (*alansecim=='E'){
                    printf("\nTaban uzunlu�unu giriniz:m ");
                    scanf("%f",&utaban);
                    utabankare=utaban*utaban;
                    alan = utabankare/4;
                    printf("\nAlan de�eri: %.2f K�K 3�m^2'dir.\n",alan);
                }
                break;
            case 4: // Kenarortay uzunlu�unu bulmam�z� sa�lar.
                printf("\nABC ��geninde hangi kenara inen kenarortay� hesaplamak istersiniz [a,b,c]: ");
                scanf("%s",&secenek4);
                if(*secenek4=='a'){
                    printf("\n1.Se�enek :Kenarortay Teoremi;\n2.Se�enek :G a��rl�k merkezi, A a��s� 90 ise;\n3.Se�enek :G a��rl�k merkezi, G a��s� 90 ise;\n");
                    printf("\nHangi se�enek ile hesaplama yapmak istersiniz: ");
                    scanf("%d",&secenek5);
                    switch (secenek5){
                        case 1:
                            do{
                                printf("\na kenar uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("b kenar uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar2);
                                printf("c kenar uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar2<=0 || kenar3<=0){printf("\nKenar de�erlerinden birisine 0 veya negatif bir de�er girdiniz. L�tfen tekrar deneyiniz veya program� sonland�r�n�z. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0 || kenar3<=0);

                            kenar1kare=(kenar1*kenar1)/2;
                            kenar2kare=kenar2*kenar2;
                            kenar3kare=kenar3*kenar3;
                            kenar4kare=(kenar2kare+kenar3kare-kenar1kare)/2;
                            if(kenar4kare==0){printf("\nKenar de�eri 0 veya negatif olamaz."); break;}
                            printf("\nV(a) do�rusunun uzunlu�u %.4f m'dir.",sqrt(kenar4kare));
                            break;
                        case 2:
                            do{
                                printf("\nA a��s� 90 olmak �zere;");
                                printf("\nV(b) kenarortay uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar2);
                                printf("V(c) kenarortay uzunlu�unu giriniz:m ");
                                    scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar2<=0){printf("\nKenar de�erlerinden birisine 0 veya negatif bir de�er girdiniz. L�tfen tekrar deneyiniz veya program� sonland�r�n�z. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0);

                            kenar2kare=kenar2*kenar2;
                            kenar3kare=kenar3*kenar3;
                            kenar1kare=(kenar2kare+kenar3kare)/5;
                            printf("\nV(a) do�rusunun uzunlu�u %.4f m'dir.",sqrt(kenar1kare));
                            break;
                        case 3:
                            do{
                                printf("\nG a��s� 90 olmak �zere;");
                                printf("\nV(b) kenarortay uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar2);
                                printf("V(c) kenarortay uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar2<=0){printf("\nKenar de�erlerinden birisine 0 veya negatif bir de�er girdiniz. L�tfen tekrar deneyiniz veya program� sonland�r�n�z. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0);

                            kenar2kare=kenar2*kenar2;
                            kenar3kare=kenar3*kenar3;
                            kenar1kare=kenar2kare+kenar3kare;
                            printf("\nV(a) do�rusunun uzunlu�u %.4f m'dir.",sqrt(kenar1kare));
                            break;
                        default:
                            printf("Ge�ersiz bir se�enek se�tiniz.");
                            break;
                    }
                }
                else if(*secenek4=='b'){
                    printf("\n\n1.Se�enek :Kenarortay Teoremi;\n2.Se�enek :G a��rl�k merkezi, A a��s� 90 ise;\n3.Se�enek :G a��rl�k merkezi, G a��s� 90 ise;\n");
                    printf("\nHangi se�enek ile hesaplama yapmak istersiniz: ");
                    scanf("%d",&secenek5);
                    switch (secenek5){
                        case 1:
                            do{
                                printf("\na kenar uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("b kenar uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar2);
                                printf("c kenar uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar2<=0 || kenar3<=0){printf("\nKenar de�erlerinden birisine 0 veya negatif bir de�er girdiniz. L�tfen tekrar deneyiniz veya program� sonland�r�n�z. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0 || kenar3<=0);
                            kenar1kare=kenar1*kenar1;
                            kenar2kare=(kenar2*kenar2)/2;
                            kenar3kare=kenar3*kenar3;
                            kenar2kare=(kenar1kare+kenar3kare-kenar2kare)/2;
                            if(kenar2kare==0){printf("\nKenar de�eri 0 veya negatif olamaz."); break;}
                            printf("\nV(b) do�rusunun uzunlu�u %.4f m'dir.",sqrt(kenar2kare));
                            break;
                        case 2:
                            do{
                                printf("\nA a��s� 90 olmak �zere;");
                                printf("\nV(a) kenarortay uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("V(c) kenarortay uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar3<=0){printf("\nKenar de�erlerinden birisine 0 veya negatif bir de�er girdiniz. L�tfen tekrar deneyiniz veya program� sonland�r�n�z. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar3<=0);
                            kenar1kare=(kenar1*kenar1)*5;
                            kenar3kare=kenar3*kenar3;
                            kenar2kare=kenar1kare-kenar3kare;
                            if(kenar2kare==0){printf("\nKenar de�eri 0 veya negatif olamaz."); break;}
                            printf("\nV(b) do�rusunun uzunlu�u %.4f m'dir.",sqrt(kenar2kare));
                            break;
                        case 3:
                            do{
                                printf("\nG a��s� 90 olmak �zere;");
                                printf("\nV(a) kenarortay uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("V(c) kenarortay uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar3<=0){printf("\nKenar de�erlerinden birisine 0 veya negatif bir de�er girdiniz. L�tfen tekrar deneyiniz veya program� sonland�r�n�z. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar3<=0);

                            kenar1kare=kenar1*kenar1;
                            kenar3kare=kenar3*kenar3;
                            kenar2kare=kenar1kare-kenar3kare;
                            if(kenar2kare==0){printf("\nKenar de�eri 0 veya negatif olamaz."); break;}
                            printf("\nV(b) do�rusunun uzunlu�u %.4f m'dir.",sqrt(kenar2kare));
                            break;
                        default:
                            printf("Ge�ersiz bir se�enek se�tiniz.");
                            break;
                    }
                }
                else if(*secenek4=='c'){
                    printf("\n\n1.Se�enek :Kenarortay Teoremi;\n2.Se�enek :G a��rl�k merkezi, A a��s��90 ise;\n3.Se�enek :G a��rl�k merkezi, G a��s� 90 ise;\n");
                    printf("\nHangi se�enek ile hesaplama yapmak istersiniz: ");
                    scanf("%d",&secenek5);
                    switch (secenek5){
                        case 1:
                            do{
                                printf("\na kenar uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("b kenar uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar2);
                                printf("c kenar uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar2<=0 || kenar3<=0){printf("\nKenar de�erlerinden birisine 0 veya negatif bir de�er girdiniz. L�tfen tekrar deneyiniz veya program� sonland�r�n�z. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0 || kenar3<=0);
                            kenar1kare=kenar1*kenar1;
                            kenar2kare=kenar2*kenar2;
                            kenar3kare=(kenar3*kenar3)/2;
                            kenar3kare=(kenar1kare+kenar2kare-kenar3kare)/2;
                            if(kenar3kare==0){printf("\nKenar de�eri 0 veya negatif olamaz."); break;}
                            printf("\nV(c) do�rusunun uzunlu�u %.4f m'dir.",sqrt(kenar3kare));
                            break;
                        case 2:
                            do{
                                printf("\nA a��s� 90� olmak �zere;");
                                printf("\nV(a) kenarortay uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("V(b) kenarortay uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar1<=0 || kenar2<=0){printf("\nKenar de�erlerinden birisine 0 veya negatif bir de�er girdiniz. L�tfen tekrar deneyiniz veya program� sonland�r�n�z. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0);

                            kenar1kare=(kenar1*kenar1)*5;
                            kenar2kare=kenar2*kenar2;
                            kenar3kare=kenar1kare-kenar2kare;
                            if(kenar3kare==0){printf("\nKenar de�eri 0 veya negatif olamaz."); break;}
                            printf("\nV(c) do�rusunun uzunlu�u %.4f m'dir.",sqrt(kenar3kare));
                            break;
                        case 3:
                            do{
                                printf("\nG a��s� 90� olmak �zere;");
                                printf("\nV(a) kenarortay uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("V(b) kenarortay uzunlu�unu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar1<=0 || kenar2<=0){printf("\nKenar de�erlerinden birisine 0 veya negatif bir de�er girdiniz. L�tfen tekrar deneyiniz veya program� sonland�r�n�z. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0);

                            kenar1kare=kenar1*kenar1;
                            kenar2kare=kenar2*kenar2;
                            kenar3kare=kenar1kare-kenar2kare;
                            if(kenar3kare==0){printf("\nKenar de�eri 0 veya negatif olamaz."); break;}
                            printf("\nV(c) do�rusunun uzunlu�u %.4f m'dir.",sqrt(kenar3kare));
                            break;
                        default:
                            printf("Gecersiz bir secenek sectiniz.");
                            break;
                    }
                }
                break;
            case 5: // A�� kenar ba��nt�lar�ndan yararlanarak bir kenar�n alabilece�i de�er aral���n� hesaplar.
                printf("\nHangi kenar� hesaplamak istersiniz [a,b,c]: ");
                scanf("%s",&secenek4);
                if(*secenek4=='a'){
                    do{
                        printf("\nb kenar�n�n uzunlu�unu giriniz:m ");
                        scanf("%f",&kenar2);
                        printf("c kenar�n�n uzunlu�unu giriniz:m ");
                        scanf("%f",&kenar3);
                        if(kenar2==0 || kenar3==0){printf("\nKenar de�eri 0 veya negatif olamaz.");}
                    }while(kenar2==0 || kenar3==0);
                    printf("\n\nForm�l: b+c > a > |b-c|");
                    kenar1fark=kenar2-kenar3;
                    kenar1top=kenar2+kenar3;
                    kenar1fark=abs(kenar1fark);
                    printf("\nSonu�: %.1f > a > %.1f",kenar1top,kenar1fark);
                }
                else if(*secenek4=='b'){
                    do{
                        printf("\na kenar�n�n uzunlu�unu giriniz:m ");
                        scanf("%f",&kenar1);
                        printf("c kenar�n�n uzunlu�unu giriniz:m ");
                        scanf("%f",&kenar3);
                        if(kenar1==0 || kenar3==0){printf("\nKenar de�eri 0 veya negatif olamaz.");}
                    }while(kenar1==0 || kenar3==0);
                    printf("\n\nForm�l: a+c > b > |a-c|");
                    kenar2fark=kenar1-kenar3;
                    kenar2top=kenar1+kenar3;
                    kenar2fark=abs(kenar2fark);
                    printf("\nSonu�: %.1f > a > %.1f",kenar2top,kenar2fark);
                }
                else if(*secenek4=='c'){
                    do{
                        printf("\na kenar�n�n uzunlu�unu giriniz:m ");
                        scanf("%f",&kenar1);
                        printf("b kenar�n�n uzunlu�unu giriniz:m ");
                        scanf("%f",&kenar2);
                        if(kenar1==0 || kenar2==0){printf("\nKenar de�eri 0 veya negatif olamaz.");}
                    }while(kenar1==0 || kenar2==0);
                    printf("\n\nForm�l: a+b > c > |a-b|");
                    kenar3fark=kenar1-kenar2;
                    kenar3top=kenar1+kenar2;
                    kenar3fark=abs(kenar3fark);
                    printf("\nSonu�: %.1f > a > %.1f",kenar3top,kenar3fark);
                }
                break;
            case 6: // Muhte�em ��l� hesaplamas� yapar.
                printf("\nDikten inen do�ru taban� iki e� par�aya b�l�yorsa inen [AD] do�rusunun uzunlu�u ikiye b�l�nen kenarlardan bir tanesidir.");
                printf("\nTaban uzunlu�unu giriniz:m ");
                scanf("%f",&taban);
                taban=taban/2;
                printf("Dikten inen kenarortay uzunlu�u: %f m'dir.",taban);
                break;

            case 7: // �klid hesaplamas� yapmam�z� sa�lar.
                printf("\n�klid teoremlerine ho�geldiniz. ABC ��geninde [AH] y�kseklik olmak �zere;");
                printf("\n1 [AH], 2 [AB], 3 [AC], 4 [BC]");
                printf("\nHangi kenar ile i�lem yapmak istiyorsunuz: ");
                scanf("%d",&secim);
                if (secim==1){
                    printf("[BH] de�erini giriniz:m ");
                    scanf("%d",&p);
                    printf("[HC] de�erini giriniz:m ");
                    scanf("%d",&k);
                    h=p*k;
                    printf("\nY�kseklik de�eri %d m'dir.",sqrt(h));
                }
                else if (secim==2){
                    printf("[BH] de�erini giriniz:m ");
                    scanf("%d",&p);
                    printf("[BC] de�erini giriniz:m ");
                    scanf("%d",&a);
                    c=p*a;
                    printf("\n[AB] de�eri %d m'dir.",sqrt(c));
                }
                else if (secim==3){
                    printf("[HC] de�erini giriniz:m ");
                    scanf("%d",&k);
                    printf("[BC] de�erini giriniz:m ");
                    scanf("%d",&a);
                    b=k*a;
                    printf("\n[AC] de�eri %f m'dir.",sqrt(b));
                }
                break;

            case 8: // �kizkenar ��genlerle ilgili bilgiler verilir.
                printf("\nDik a��dan inen y�kseklik hem a��ortay, hem de kenarortayd�r. K�saca bir do�ru par�as� 3 i�lev kazan�r.\n");
                printf("Bir ��gende ayn� do�ru par�as� hem y�kseklik hem kenarortay olursa bu ��gen ikizkenar ��gendir.\n");
                printf("Bir ��gende ayn� do�ru par�as� hem y�kseklik hem de a��ortay oluyorsa bu ��gen ikizkenar ��gendir.\n");
                printf("Bir ��gende ayn� do�ru par�as� hem a��ortay hem de kenarortay oluyorsa bu ��gen ikizkenar ��gendir.\n");
                break;

            case 9: // E�kenar ��genlerle ilgili bilgiler verilir.
                printf("\nT�m kenar uzunluklar� e�it olan ��gene e�kenar ��gen denir.\n");
                printf("E�kenar ��genin i� a��lar�n�n �l��leri 60'd�r.'\n");
                break;

            default:
                printf("Ge�ersiz bir se�enek se�tiniz.");
                break;
        }
    }
    else if (*s == 'd'){
        printf("\nD�zlemde do�rusal olmayan d�rt noktan�n iki�erli birle�tirilmesiyle olu�an �ekle d�rtgen denir.\n");
        printf("\n1.Secenek :Kare\n");
        printf("2.Secenek :�kizkenaryamuk\n");
        printf("3.Secenek :Deltoid\n");
        printf("4.Secenek :E�kenar D�rtgen\n");
        printf("5.Secenek :Paralelkenar\n");
        printf ("\nSe�enek se�iniz: ");
        scanf("%d",&secenek);
        switch (secenek){
        case 1:
        	do { 
            	printf("\nTek kenar uzunlu�unu giriniz:m ");
            	scanf("%f",&kenar);	
            	if (kenar==0){printf ("\nKenar uzunlu�u 0 olamaz. Tekrar de�er giriniz.");} 
        	}while (kenar==0);
        	alan=kenar*kenar;
            cevre=kenar*4;
            printf("Alan de�eri %.1f m^2'dir.\n",alan);
            printf("�evre de�eri %.1f m'dir.",cevre);
            break;
        case 2: 
        	do { 
	        	printf("\nABCD ikizkenaryamu�unda [DH] y�kseklik, [AB] taban olmak �zere; ");
	           	printf("\n[DH] uzunlu�unu giriniz:m ");
	           	scanf("%f",&yukseklik);
	           	printf("\n[HB] uzunlu�unu giriniz:m ");
	           	scanf("%f",&kenar);
	           	printf("\n[AH] uzunlu�unu giriniz:m ");
	           	scanf("%f",&kenar1);
	           	if (kenar==0){printf ("Kenar uzunlu�u 0 olamaz. Tekrar de�er giriniz.\n");}
    		}while (kenar==0);
        	alan=yukseklik*kenar;
        	yukseklikkare==yukseklik*yukseklik;
        	kenar1kare==kenar*kenar;
        	kenar2==sqrt(yukseklikkare+kenar1kare);
        	cevre=(2*kenar2)+(2*kenar1)+2*(kenar-kenar1);
        	if(cevre==0){printf("\nKenar de�eri 0 veya negatif olamaz."); break;}
           	printf("\nAlan de�eri %.1f m^2'dir.",alan);
           	printf("\n�evre de�eri %.1f m'dir.\n",cevre);
			break;
			case 3:
				printf  ("G�rsellik gerektirdi�i i�in hesaplanam�yor.");
				break;
			case 4:
				do {
					printf ("\nABCD e�kenar d�rtgeninde tek kenar uzunlu�unu giriniz:m ");
					scanf ("%f",&kenar);
					printf ("\n[AC] uzunlu�unu giriniz:m ");
					scanf ("%f",&kenar1);
					printf ("\n[BD] uzunlu�unu giriniz:m ");
					scanf ("%f",&kenar2);
				if (kenar==0){printf ("Kenar uzunlu�u 0 olamaz. Tekrar de�er giriniz.\n");}	
				}while (kenar==0);
				alan=(kenar1*kenar2)/2;
				cevre=kenar*4;
				printf ("\nAlan de�eri %.1f m^2'dir",alan);
				printf ("\n�evre de�eri %.1f m'dir",cevre);
				break;
			case 5:
				do {
					printf ("\nGeni� kenar�n uzunlu�unu giriniz:m ");
					scanf ("%f",&kenar);
					printf ("K�sa kenar�n uzunlu�unu giriniz:m ");
					scanf ("%f",&kenar1);
					printf ("Geni� kenara inen y�ksekli�in uzunlu�unu giriniz:m ");
					scanf ("%f",&kenar2);
				if (kenar==0){printf ("\nKenar uzunlu�u 0 olamaz.Tekrar de�er giriniz.");}	
				}while (kenar==0);
				alan=kenar*kenar2;
				cevre=(kenar*2)+(kenar1*2);
				printf ("\nAlan de�eri %.1f m^2'dir.",alan);
				printf ("\n�evre de�eri %.1f m'dir.",cevre);
				break;
        default:
            printf("Ge�ersiz bir se�enek se�tiniz.");
            break;
        }
    } 
    else if (*s == 'b'){
            printf("\nTek kenar uzunlu�unu giriniz:m ");
            scanf("%f",&kenar);

            printf("Y�kseklik de�erini giriniz:m ");
            scanf("%f",&yukseklik);
            
            alan = 5*kenar*yukseklik/2;
            cevre = kenar*5;
            
            printf("\nAlan de�eri: %.1f m^2'dir.\n",alan);
            printf("�evre de�eri: %.1f m'dir.",cevre);

    }
    else if (*s == 'a'){
            printf("\nTek kenar uzunlu�unu giriniz:m ");
            scanf("%f",&kenar);

            kenarkare = kenar*kenar;
            alan = (3*kenarkare)/2;

            cevre = kenar*6;
            printf("\nAlan de�eri: %.1f m^2'dir.\n",alan);
            printf("�evre de�eri: %.1f m'dir.\n",cevre);
            
    }
    else{
        printf("Ge�ersiz bir �ekil girdiniz. Program� sonland�r�p tekrar deneyiniz.\n");
    }
    printf("\n\nProgram� sonland�rmak i�in herhangi bir tu�a bas�n�z.");
    getchar();
    getchar();
    return 0;
}
