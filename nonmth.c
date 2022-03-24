#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

int main(){
    setlocale(LC_ALL, "Turkish");
    int secenek; // Geometrik þekillerde seçim yapmak için. 
    float kenar1, kenar2, kenar3, kenar4, kenar5; // Kenarortay teoremlerinde kullanýldý.
    float kenar1kare, kenar2kare, kenar3kare, kenar4kare, kenar5kare; // Kenarortay teoremlerinde kullanýldý.
    float kenar2fark, kenar1fark, kenar3fark; // Üçgende açý-kenar baðýntýlarýnda kullanýldý.
    float kenar2top, kenar1top, kenar3top; // Üçgende açý-kenar baðýntýlarýnda kullanýldý.
    float hae; // Yükseklik ve açýortayýn arasýndaki açý.
    char tepenok; // Üçgende tepe noktasý belirlemek için kullanýldý.
    int secenek2, secenek3; // Açýortaylar için ^.
    char alansecim[3]={'N','E','I'}; // Üçgende alan için.
    int secenek5; // Kenarortay hesaplama yöntemleri için.
    int secim; // Öklid baðýntýsý için.
    float a, b, c, h, p, k; // Öklid baðýntýsý için.
    char secenek4[3]={'a','b','c'}; // Kenarortaylarda kullanýldý.^
    float utaban;
    float yukseklik;
    float alan, u;
    float cevre;
    float utabankare;
    float yukseklikkare;
    float hipotenuskare;
    float ikizkenar;
    // Üçgenler ile ilgili hesaplamalarýn deðiþkenleri.^
    float aci;
    float aci2;
    float acisonuc;
    float disaci;
    float disaci2;
    char acilar[2]={'A','N'};
    // Açýlar ile ilgili hesaplamalarýn deðiþkenleri.^
    float taban;
    float kenar;
    float kenarkare;

    char s[4]={'u','d','b','a'};
    printf("Hesaplama yapmak istediðiniz þeklin baþ harfini giriniz [u,d,b,a]: ");
    scanf("%s",&s);

    if (*s == 'u'){
        printf("\n1.Secenek : Dik üçgenle ilgili uzunluk ve alan hesaplamalarýný içerir.\n");
        printf("2.Secenek : Üçgende alan hesaplamasýna gider.\n");
        printf("3.Secenek : Üçgende açý/açý ortay ile ilgili hesaplamalar yapar.\n");
        printf("4.Secenek : Üçgende kenarortay hesaplamasý yapar.\n");
        printf("5.Secenek : Üçgende açý/kenar baðýntýlarýný kullanarak size bilinmeyen bir kenarýn alabileceði maks. ve min. deðerleri söyler.\n");
        printf("6.Secenek : Muhteþem üçlü hesaplamasý yapar.\n");
        printf("7.Secenek : Öklid Baðýntýlarýnda hesaplama yapmanýza olanak saðlar.\n");

        printf("8.Secenek : Ýkizkenar üçgenle ilgili bilgileri içerir.\n");
        printf("9.Secenek : Eþkenar üçgenle ilgili bilgileri içerir.\n");
        printf("\n Seçenek seçiniz: ");
        scanf("%d",&secenek);

        switch (secenek){
            case 1: // Dik žžgenler; ikizkenar dik žžgenler ve dik žžgenler olmak žzere iki ayrž blokta incelenir.
                printf("\nDik olmayan açýlardan birisini giriniz: ");
                scanf("%f",&aci);
                if(aci==45){
                    printf("\nGirilen açý bilgisine göre 'ikizkenar dik üçgen' üzerinde iþlem yapýlacaktýr.\n");
                    printf("\nÝkizkenarlardan birisinin uzunluðunu giriniz:m ");
                    scanf("%f",&ikizkenar);
                    printf("\nHipotenüs uzunluðu: %.1f KÖK 2 m'dir.",ikizkenar);
                    alan = ikizkenar*ikizkenar/2;
                    printf("\nAlan: %.1f m^2'dir.",alan);
                    cevre = ikizkenar*2;
                    printf("\nÇevre: %.1f+%.1f KÖK 2 m'dir.",cevre,ikizkenar);
                    break;
                }
            
                else if (aci>=1 && aci<=89){
                    printf("\nBu normal bir dik üçgendir.\n");
                    printf("\nTaban uzunluðunu giriniz:m ");
                    scanf("%f",&utaban);
                    printf("Yukseklik uzunlugunu giriniz:m ");
                    scanf("%f",&yukseklik);
                    alan = utaban*yukseklik/2;
                    utabankare = utaban*utaban;
                    yukseklikkare = yukseklik*yukseklik;
                    hipotenuskare = utabankare+yukseklikkare;
                    cevre = utaban + yukseklik + sqrt(hipotenuskare);
                    printf("\nHipotenüs deðeri: %.1f m'dir\n",sqrt(hipotenuskare));
                    printf("Alan deðeri: %.1f m^2'dir.\n",alan);
                    printf("Çevre deðeri: %.1f m'dir.",cevre);
                    break;
                }

                else{
                    printf("\nTek açýsý zaten 90žolan bir üçgenin diðer bir açýsý %džolamaz.",aci);
                }
                break;
            case 3: // Ažž hesaplamasž yapžlžr.
                printf("\nAçýortay teoremleri ile mi, normal açý hesaplamasý mý yapacaksýnýz [A/N]:  ");
                scanf("%s",&acilar);
                if (*acilar=='A'){
                    printf("\n1.Seçenek :Ýç içežüçgenlerde iç açýžortay kuralýný kullanarak tepe açýsýžbulmanýzý saðlar.\n");
                    printf("2.Seçenek :Tabanlarýndan ters þekilde birbirine yapýþmýþžüçgenlerde (dörtgene benzeyen) dýþ açýortay kuralýný kullanarak zýt iki tepedeki açýlarý bulmanýzý saðlar.\n");
                    printf("3.Seçenek :Bir ABC üçgeninde tepe noktasýndan tabana inen yükseklik doðrusu [AH] ile açýortay doðrusunun [AE] arasýndaki açýyý m(HAE)'i hesaplar.\n");
                    printf("4.Seçenek :ABC üçgeninde; [BP] iç açý ortay ise, [PC] ABC üçgenindeki C açýsýnýn dýþ açýortayý ise PBC üçgeninde m(P)'i hesaplar.\n");
                    printf("\n6.Seçenek :Ýç Açý ortay Teoremi ile ABC üçgeninin kenar uzunluklarýný hesaplar.\n");
                    printf("7.Seçenek :Ýç Açý ortay Teoremi ile ABC üçgeninde [AN] iç açý ortay doðrusunun uzunluðunu hesaplar.\n");
                    printf("\n8.Seçenek :Dýþ Açýžortay Teoremi ile ABC üçgeninin kenar uzunluklarýný hesaplar.\n");
                    printf("9.Seçenek :Dýþ Açýžortay Teoremi ile ABC ve ABN üçgeninde [AN] dýþ açýortay doðrusunun uzunluðunu hesaplar.\n");
                    printf("\nSeçenek seçiniz: ");
                    scanf("%d",&secenek2);
                    switch (secenek2){
                    
                    case 1:
                        printf("\nABC üçgeninin içinde DBC üçgeni vardýr. [BD] ve [CD] iç açýžortaylardýr.\n");
                        printf("\nHesaplamak istediðiniz tepenin açýsýný tek harf þeklinde yazýnýz [D/A]: "), scanf("%s",&tepenok);
                        if(tepenok=='A'){
                            do{
                                printf("\nm(D) açýsýný giriniz, bilmiyorsanýz '0' giriniz: "), scanf("%f",&aci2);
                                if(aci2==0) printf("m(D) açýsýnýn dýþ açýsýný giriniz: "), scanf("%f",&disaci2), aci2=180-disaci2;
                                if(aci2<=90){ printf("\nm(A) açýsý 0žveya 0ž'den küçük olamaz.\n");}
                                if(aci2==180){ printf("\nm(A) açýsý tek baþýna 180ž olamaz.\n");}
                            }while(aci2<=90 || aci2==180);
                            aci=2*aci2-180 ,printf("m(A) %.1fž'dir.",aci);
                        }
                        else if(tepenok=='D'){ 
                            do{
                                printf("\nm(A) açýsýný giriniz, bilmiyorsanýz '0' giriniz:ž "), scanf("%f",&aci);
                                if(aci==0) printf("m(A) açýsýnýn dýþ açýsýný giriniz: "), scanf("%f",&disaci), aci=180-disaci;
                                if(aci==180){printf("m(D) açýsý tek baþýna 180ž olamaz.");}
                            }while(aci==180);
                            aci2=aci/2+90 ,printf("m(D) %.1fž'dir.",aci2);
                        }
                        break;
                    case 2:
                        printf("\nABC Üçgeninin tabanýna ters bir þekilde yapýpžm(FBC) üçgeni vardýr; [BF] ve [CF] ABC üçgeninin dýþžaçý ortaylarýdýr.\n");
                        printf("\nHesaplamak istediðiniz tepenin açýsýnýn tek harf þeklinde yazýnýz [F/A]: "), scanf("%s",&tepenok);
                        if(tepenok=='A'){
                            do{
                                printf("\nm(F) açýsýný giriniz, bilmiyorsanýz '0' giriniz: "), scanf("%f",&aci2);
                                if(aci2==0) printf("m(F) açýsýnýn dýþ açýsýný giriniz: "), scanf("%f",&disaci2), aci2=180-disaci2;
                                if(aci2>=90){printf("\nm(A) açýsý 0žveya 0'den küçük olamaz. Tekrar deðer giriniz ya da programžsonlandýrýnýz. (CTRL+C)");}
                            }while(aci2>=90);
                            aci=180-2*aci2 ,printf("m(A) %.1fž'dir.",aci);
                        }
                        else if(tepenok=='F'){
                            do{ 
                                printf("\nm(A) ažžsžnžn dežerini giriniz:ž "), scanf("%f",&aci);
                                if(aci==0) printf("m(A) ažžsžnžn džž ažžsžnž giriniz: "), scanf("%f",&disaci), aci=180-disaci;
                                if(aci==180){printf("\nm(F) açýsý tek baþýna 0ž olamaz. Tekrar deðer giriniz ya da programý sonlandýrýnýz. (CTRL+C)");}
                            }while(aci==180);
                            aci2=90-aci/2 ,printf("m(F) %.1fž'dir.",aci2);
                        }
                        break;
                    case 3:
                        do{
                            printf("\nm(B) açýsýný giriniz bilmiyorsanýz '0' giriniz: ");
                            scanf("%f",&aci);
                            if(aci==0) printf("m(B) açýsýnýn dýþ açýsýný giriniz: "), scanf("%f",&disaci), aci=180-disaci;
                            if(aci==180){printf("m(B) açýsýný tek baþýna 180 olamaz.");}

                            printf("\nm(C) açýsýný giriniz: bilmiyorsanýz '0' giriniz: ");
                            scanf("%f",&aci2);
                            if(aci2==0) printf("m(C) açýsýný dýþ açýsýný giriniz: "), scanf("%f",&disaci2), aci2=180-disaci2;
                            if(aci2==180){printf("m(C) açýsý tek baþýna 180 olamaz.");}
                        }while(aci==180 || aci2==180);

                        hae=(aci-aci2)/2;
                        acisonuc=abs(hae); 
                        printf("\n\nFormžl : m(HAE) = |m(B) - m(C)|/2\n");
                        printf("|%.1f - %.1f|/2 = %.1f",aci,aci2,acisonuc); 
                        break;

                    case 4:
                        printf("\nHesaplamak istediðiniz tepenin açýsýný tek harf þeklinde yazýnýz [P/A]: "), scanf("%s",&tepenok);
                        if(tepenok=='A'){
                            do{
                                printf("\nm(P) açýsýný giriniz, bilmiyorsanýz '0' giriniz:ž "), scanf("%f",&aci2);
                                if(aci2==0) printf("m(P) açýsýnýn dýþ açýsýný giriniz: "), scanf("%f",&disaci2), aci2=180-disaci2;
                                if(aci2>=90 || aci2==180){ printf("m(A) veya m(P) açýsý 180žveya 180'den büyük olamaz.");}
                            }while(aci2>=90 || aci2==180);
                            aci=aci2*2 ,printf("\nm(A) %.1fž'dir.",aci);
                        }
                        else if(tepenok=='P'){
                            do{
                            printf("\nm(A) açýsýnýn deðerini giriniz, bilmiyorsanýz '0' giriniz:ž "), scanf("%f",&aci);
                            if(aci==0) printf("m(A) açýsýnýn dýþ açýsýný giriniz: "), scanf("%f",&disaci), aci=180-disaci;
                            if(aci==180){ printf("m(A) açýsý 180 olamaz.");}
                            }while(aci==180);
                            aci2=aci/2 ,printf("\nm(P) %.1fž'dir.",aci2);
                        }
                        break;
                    case 6:
                        printf("\n1:[AB], 2:[AC], 3:[NB], 4:[NC]");
                        printf("\nABC üçgeninde [AN] iç açýortay doðrusudur ve hesaplamak istediðiniz kenarý giriniz [1/2/3/4]: ");
                        scanf("%d",&secenek3);
                        if(secenek3==1){
                            do{
                                printf("\n[AC] kenarýnýn uzunluðunu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar2==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[NB] kenarýnýn uzunlužunu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar3==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[NC] kenarýnýn uzunlužunu giriniz:m ");
                                scanf("%f",&kenar4);
                                if(kenar4==0){printf("Kenar uzunluðu 0 m olamaz.");}
                            }while(kenar2==0 || kenar3==0 || kenar4==0);
                            kenar1=kenar2*kenar3/kenar4;
                            printf("\n[AB] kenarýnýn uzunluðu %.1f cm'dir.",kenar1);
                            break;
                        }
                        else if(secenek3==2){
                            do{
                                printf("\n[AB] kenarýnýn uzunluðunu giriniz:m ");
                                scanf("%f",&kenar1);
                                if(kenar1==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[NB] kenarýnýn uzunlužunu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar3==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[NC] kenarýnýn uzunlužunu giriniz:m ");
                                scanf("%f",&kenar4);
                                if(kenar4==0){printf("Kenar uzunluðu 0 m olamaz.");}
                            }while(kenar1==0 || kenar3==0 || kenar4==0);
                            kenar2=kenar1*kenar4/kenar3;
                            printf("\n[AC] kenarýnýn uzunluðu %.1f m'dir.",kenar2);
                            break;
                        }
                        else if(secenek3==3){
                            do{
                                printf("\n[AB] kenarýnýn uzunluðunu giriniz:m ");
                                scanf("%f",&kenar1);
                                if(kenar1==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[AC] kenarýnýn uzunlužunu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar2==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[NC] kenarýnýn uzunlužunu giriniz:m ");
                                scanf("%f",&kenar4);
                                if(kenar4==0){printf("Kenar uzunluðu 0 m olamaz.");}
                            }while(kenar1==0 || kenar2==0 || kenar4==0);
                            kenar3=kenar1*kenar4/kenar2;
                            printf("\n[AC] kenarýnýn uzunluðu %.1f m'dir.",kenar3);
                            break;
                        }
                        else if(secenek3==4){
                            do{
                                printf("\n[AB] kenarýnýn uzunluðunu giriniz:m ");
                                scanf("%f",&kenar1);
                                if(kenar1==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[AC] kenarýnýn uzunluðunu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar2==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[NB] kenarýnýn uzunluðunu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar3==0){printf("Kenar uzunluðu 0 m olamaz.");}
                            }while(kenar1==0 || kenar2==0 || kenar3==0);
                            kenar4=kenar2*kenar3/kenar1;
                            printf("\n[AC] kenarýnýn uzunluðu %.1f m'dir.",kenar4);
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
                            if(kenar1<=0 || kenar2<=0 || kenar3<=0 || kenar4<=0){printf("\nKenar deðerlerinden birisine 0 veya negatif bir deðer girdiniz. Lütfen tekrar deneyiniz veya programý sonlandýrýnýz. (CTRL+C)\n");}
                        }while(kenar1<=0 || kenar2<=0 || kenar3<=0 || kenar4<=0);
                        kenar5=kenar1*kenar2-kenar3*kenar4;
                        if(kenar5==0){printf("\nKenar deðeri 0 veya negatif olamaz."); break;}
                        printf("\n[AN] iç açýortay doðrusunun uzunluðu %.2f m'dir.",sqrt(abs(kenar5)));
                        break;
                    case 8:
                        printf("\n1:[AB], 2:[AC], 3:[BN], 4:[CN]");
                        printf("\nABC ve ABN üçgendir; [AN] dýþ açýortay doðrusudur ve hesaplamak istediðiniz kenarý giriniz [1/2/3/4]: ");
                        scanf("%d",&secenek3);
                        if(secenek3==1){
                            do{
                                printf("\n[AC] kenarýnýn uzunluðunu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar2==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[BN] kenarýnýn uzunlužunu giriniz: ");
                                scanf("%f",&kenar3);
                                if(kenar3==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[CN] kenarýnýn uzunlužunu giriniz: ");
                                scanf("%f",&kenar4);
                                if(kenar4==0){printf("Kenar uzunluðu 0 m olamaz.");}
                            }while(kenar2==0 || kenar3==0 || kenar4==0);
                            kenar1=kenar3*kenar4/kenar2;
                            printf("\n[AB] kenarýnýn uzunluðu %.1f m'dir.",kenar1);
                            break;
                        }
                        else if(secenek3==2){
                            do{
                                printf("\n[AB] kenarýnýn uzunluðunu giriniz:m ");
                                scanf("%f",&kenar1);
                                if(kenar2==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[BN] kenarýnýn uzunluðunu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar3==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[CN] kenarýnýn uzunluðunu giriniz:m ");
                                scanf("%f",&kenar4);
                                if(kenar4==0){printf("Kenar uzunluðu 0 m olamaz.");}
                            }while(kenar1==0 || kenar3==0 || kenar4==0);
                            kenar2=kenar3*kenar4/kenar1;
                            printf("\n[AC] kenarýnýn uzunluðu %.1f m'dir.",kenar2);
                            break;
                        }
                        else if(secenek3==3){
                            do{
                                printf("\n[AB] kenarýnýn uzunluðunu giriniz:m ");
                                scanf("%f",&kenar1);
                                if(kenar1==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[AC] kenarýnýn uzunluðunu giriniz: ");
                                scanf("%f",&kenar2);
                                if(kenar2==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[CN] kenarýnýn uzunluðunu giriniz: ");
                                scanf("%f",&kenar4);
                                if(kenar4==0){printf("Kenar uzunluðu 0 m olamaz.");}
                            }while(kenar1==0 || kenar2==0 || kenar4==0);
                            kenar3=kenar1*kenar2/kenar4;
                            printf("\n[BN] kenarýnýn uzunluðu %.1f m'dir.",kenar3);
                            break;
                        }
                        else if(secenek3==4){
                            do{
                                printf("\n[AB] kenarýnýn uzunluðunu giriniz:m ");
                                scanf("%f",&kenar1);
                                if(kenar1==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[AC] kenarýnýn uzunlužunu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar2==0){printf("Kenar uzunluðu 0 m olamaz.");}
                                printf("[BN] kenarýnýn uzunlužunu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar3==0){printf("Kenar uzunluðu 0 m olamaz.");}
                            }while(kenar1==0 || kenar2==0 || kenar3==0);
                            kenar4=kenar1*kenar2/kenar3;
                            printf("\n[CN] kenarýnýn uzunluðu %.1f m'dir.",kenar4);
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
                            if(kenar1<=0 || kenar2<=0 || kenar3<=0 || kenar4<=0){printf("\nKenar deðerlerinden birisine 0 veya negatif bir deðer girdiniz. Lütfen tekrar deneyiniz veya programý sonlandýrýnýz. (CTRL+C)\n");}
                        }while(kenar1<=0 || kenar2<=0 || kenar3<=0 || kenar4<=0);
                        kenar5=kenar1*kenar2-kenar4*kenar3;
                        if(kenar5==0){printf("\nKenar deðeri 0 veya negatif olamaz."); break;}
                        printf("\n[AN] dýþ açýortay doðrusunun uzunluðu %.2f m'dir.",sqrt(abs(kenar5)));
                        break;
                    default:
                        printf("Geçersiz bir seçenek seçtiniz!");
                        break;
                    }
                }
                else if(*acilar=='N'){
                    printf("\nAçý giriniz, bilmiyorsanýz '0' deðerini giriniz:ž ");
                    scanf("%f",&aci);
                    printf("Ýkincil açýyý giriniz, bilmiyorsannýz '0' deðerini giriniz:ž ");
                    scanf("%f",&aci2);

                    if (aci==0 && aci2==0){
                        printf("\nBilmediðiniz birinci açýnýn dýþ açý deðerini giriniz:ž ");
                        scanf("%f",&disaci);
                        aci=180-disaci;
                        printf("\nBilmediðiniz ikinci açýnýn dýþ açý deðerini giriniz:ž ");
                        scanf("%f",&disaci2);
                        aci2=180-disaci2;
                    }

                    else if (aci==0 || aci2==0){
                        if(aci==0) printf("\nBirinci açýnýn dýþ açý deðerini giriniz:ž "), scanf("%f",&disaci), aci=180-disaci;
                    
                        if(aci2==0) printf("\nÝkinci açýnýn dýþ açý deðerini giriniz:ž "), scanf("%f",&disaci2), aci2=180-disaci2;

                    }
                    acisonuc=180-aci-aci2;
                    printf("\nBilinmeyen 3.açý %.1fž'dir. ",acisonuc);
                }
                break;

            case 2: // žžgende alan hesaplamasž.
                printf("Eþkenar, ikizkenar, uzunluklarý bilinen normal bir üçgen arasýnda seçim yapýnýz [N/I/E]: ");
                scanf("%s",&alansecim);
                if (*alansecim=='N'){
                    do{
                        printf("\nABC žžgeni ižin; ");
                        printf("\n[AB] kenarýnýn uzunluðunu giriniz:m ");
                        scanf("%f",&kenar1);
                        if(kenar1<=0){printf("Kenar uzunluðu 0 m olamaz.");}
                        printf("[BC] kenarýnýn uzunlužunu giriniz:m ");
                        scanf("%f",&kenar2);
                        if(kenar2<=0){printf("Kenar uzunluðu 0 m olamaz.");}
                        printf("[CA] kenarýnýn uzunlužunu giriniz:m ");
                        scanf("%f",&kenar3);
                        if(kenar3<=0){printf("Kenar uzunluðu 0 m olamaz.");}
                    }while(kenar1<=0 || kenar2<=0 || kenar3<=0);
                    kenar4=kenar3+kenar2+kenar1; // Kenarlarž toplamamžz lazžm. Ardžndan ikiye bžlžp "u" dežerini bulmalžyžz.
                    u=kenar4/2;
                    printf("\nABC üçgeninin alaný %.4f m^2'dir .",sqrt(u*(u-kenar1)*(u-kenar2)*(u-kenar3)));
                }
                else if (*alansecim=='I'){
                    printf("\nTaban uzunluðunu giriniz:m ");
                    scanf("%f",&utaban);
                    printf("Yükseklik uzunluðunu giriniz:m ");
                    scanf("%f",&yukseklik);
                    alan = utaban*yukseklik/2;
                    printf("\nAlan deðeri: %.2f m^2'dir.\n",alan);
                }
                else if (*alansecim=='E'){
                    printf("\nTaban uzunluðunu giriniz:m ");
                    scanf("%f",&utaban);
                    utabankare=utaban*utaban;
                    alan = utabankare/4;
                    printf("\nAlan deðeri: %.2f KÖK 3žm^2'dir.\n",alan);
                }
                break;
            case 4: // Kenarortay uzunlužunu bulmamžzž sažlar.
                printf("\nABC üçgeninde hangi kenara inen kenarortayý hesaplamak istersiniz [a,b,c]: ");
                scanf("%s",&secenek4);
                if(*secenek4=='a'){
                    printf("\n1.Seçenek :Kenarortay Teoremi;\n2.Seçenek :G aðýrlýk merkezi, A açýsý 90 ise;\n3.Seçenek :G aðýrlýk merkezi, G açýsý 90 ise;\n");
                    printf("\nHangi seçenek ile hesaplama yapmak istersiniz: ");
                    scanf("%d",&secenek5);
                    switch (secenek5){
                        case 1:
                            do{
                                printf("\na kenar uzunluðunu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("b kenar uzunluðunu giriniz:m ");
                                scanf("%f",&kenar2);
                                printf("c kenar uzunluðunu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar2<=0 || kenar3<=0){printf("\nKenar deðerlerinden birisine 0 veya negatif bir deðer girdiniz. Lütfen tekrar deneyiniz veya programý sonlandýrýnýz. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0 || kenar3<=0);

                            kenar1kare=(kenar1*kenar1)/2;
                            kenar2kare=kenar2*kenar2;
                            kenar3kare=kenar3*kenar3;
                            kenar4kare=(kenar2kare+kenar3kare-kenar1kare)/2;
                            if(kenar4kare==0){printf("\nKenar deðeri 0 veya negatif olamaz."); break;}
                            printf("\nV(a) doðrusunun uzunluðu %.4f m'dir.",sqrt(kenar4kare));
                            break;
                        case 2:
                            do{
                                printf("\nA açýsý 90 olmak üzere;");
                                printf("\nV(b) kenarortay uzunluðunu giriniz:m ");
                                scanf("%f",&kenar2);
                                printf("V(c) kenarortay uzunluðunu giriniz:m ");
                                    scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar2<=0){printf("\nKenar deðerlerinden birisine 0 veya negatif bir deðer girdiniz. Lütfen tekrar deneyiniz veya programý sonlandýrýnýz. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0);

                            kenar2kare=kenar2*kenar2;
                            kenar3kare=kenar3*kenar3;
                            kenar1kare=(kenar2kare+kenar3kare)/5;
                            printf("\nV(a) doðrusunun uzunluðu %.4f m'dir.",sqrt(kenar1kare));
                            break;
                        case 3:
                            do{
                                printf("\nG açýsý 90 olmak üzere;");
                                printf("\nV(b) kenarortay uzunluðunu giriniz:m ");
                                scanf("%f",&kenar2);
                                printf("V(c) kenarortay uzunluðunu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar2<=0){printf("\nKenar deðerlerinden birisine 0 veya negatif bir deðer girdiniz. Lütfen tekrar deneyiniz veya programý sonlandýrýnýz. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0);

                            kenar2kare=kenar2*kenar2;
                            kenar3kare=kenar3*kenar3;
                            kenar1kare=kenar2kare+kenar3kare;
                            printf("\nV(a) doðrusunun uzunluðu %.4f m'dir.",sqrt(kenar1kare));
                            break;
                        default:
                            printf("Geçersiz bir seçenek seçtiniz.");
                            break;
                    }
                }
                else if(*secenek4=='b'){
                    printf("\n\n1.Seçenek :Kenarortay Teoremi;\n2.Seçenek :G aðýrlýk merkezi, A açýsý 90 ise;\n3.Seçenek :G aðýrlýk merkezi, G açýsý 90 ise;\n");
                    printf("\nHangi seçenek ile hesaplama yapmak istersiniz: ");
                    scanf("%d",&secenek5);
                    switch (secenek5){
                        case 1:
                            do{
                                printf("\na kenar uzunluðunu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("b kenar uzunluðunu giriniz:m ");
                                scanf("%f",&kenar2);
                                printf("c kenar uzunluðunu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar2<=0 || kenar3<=0){printf("\nKenar deðerlerinden birisine 0 veya negatif bir deðer girdiniz. Lütfen tekrar deneyiniz veya programý sonlandýrýnýz. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0 || kenar3<=0);
                            kenar1kare=kenar1*kenar1;
                            kenar2kare=(kenar2*kenar2)/2;
                            kenar3kare=kenar3*kenar3;
                            kenar2kare=(kenar1kare+kenar3kare-kenar2kare)/2;
                            if(kenar2kare==0){printf("\nKenar deðeri 0 veya negatif olamaz."); break;}
                            printf("\nV(b) doðrusunun uzunluðu %.4f m'dir.",sqrt(kenar2kare));
                            break;
                        case 2:
                            do{
                                printf("\nA açýsý 90 olmak üzere;");
                                printf("\nV(a) kenarortay uzunluðunu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("V(c) kenarortay uzunluðunu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar3<=0){printf("\nKenar deðerlerinden birisine 0 veya negatif bir deðer girdiniz. Lütfen tekrar deneyiniz veya programž sonlandýrýnýz. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar3<=0);
                            kenar1kare=(kenar1*kenar1)*5;
                            kenar3kare=kenar3*kenar3;
                            kenar2kare=kenar1kare-kenar3kare;
                            if(kenar2kare==0){printf("\nKenar deðeri 0 veya negatif olamaz."); break;}
                            printf("\nV(b) doðrusunun uzunluðu %.4f m'dir.",sqrt(kenar2kare));
                            break;
                        case 3:
                            do{
                                printf("\nG açýsý 90 olmak üzere;");
                                printf("\nV(a) kenarortay uzunluðunu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("V(c) kenarortay uzunluðunu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar3<=0){printf("\nKenar dežerlerinden birisine 0 veya negatif bir dežer girdiniz. Lžtfen tekrar deneyiniz veya programž sonlandžržnžz. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar3<=0);

                            kenar1kare=kenar1*kenar1;
                            kenar3kare=kenar3*kenar3;
                            kenar2kare=kenar1kare-kenar3kare;
                            if(kenar2kare==0){printf("\nKenar deðeri 0 veya negatif olamaz."); break;}
                            printf("\nV(b) doðrusunun uzunluðu %.4f m'dir.",sqrt(kenar2kare));
                            break;
                        default:
                            printf("Geçersiz bir seçenek seçtiniz.");
                            break;
                    }
                }
                else if(*secenek4=='c'){
                    printf("\n\n1.Seçenek :Kenarortay Teoremi;\n2.Seçenek :G aðýrlýk merkezi, A açýsýž90 ise;\n3.Seçenek :G aðýrlýk merkezi, G açýsý 90 ise;\n");
                    printf("\nHangi seçenek ile hesaplama yapmak istersiniz: ");
                    scanf("%d",&secenek5);
                    switch (secenek5){
                        case 1:
                            do{
                                printf("\na kenar uzunluðunu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("b kenar uzunluðunu giriniz:m ");
                                scanf("%f",&kenar2);
                                printf("c kenar uzunluðunu giriniz:m ");
                                scanf("%f",&kenar3);
                                if(kenar1<=0 || kenar2<=0 || kenar3<=0){printf("\nKenar deðerlerinden birisine 0 veya negatif bir deðer girdiniz. Lütfen tekrar deneyiniz veya programž sonlandýrýnýz. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0 || kenar3<=0);
                            kenar1kare=kenar1*kenar1;
                            kenar2kare=kenar2*kenar2;
                            kenar3kare=(kenar3*kenar3)/2;
                            kenar3kare=(kenar1kare+kenar2kare-kenar3kare)/2;
                            if(kenar3kare==0){printf("\nKenar deðeri 0 veya negatif olamaz."); break;}
                            printf("\nV(c) doðrusunun uzunluðu %.4f m'dir.",sqrt(kenar3kare));
                            break;
                        case 2:
                            do{
                                printf("\nA ažžsž 90ž olmak žzere;");
                                printf("\nV(a) kenarortay uzunluðunu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("V(b) kenarortay uzunluðunu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar1<=0 || kenar2<=0){printf("\nKenar deðerlerinden birisine 0 veya negatif bir deðer girdiniz. Lütfen tekrar deneyiniz veya programý sonlandýrýnýz. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0);

                            kenar1kare=(kenar1*kenar1)*5;
                            kenar2kare=kenar2*kenar2;
                            kenar3kare=kenar1kare-kenar2kare;
                            if(kenar3kare==0){printf("\nKenar deðeri 0 veya negatif olamaz."); break;}
                            printf("\nV(c) doðrusunun uzunluðu %.4f m'dir.",sqrt(kenar3kare));
                            break;
                        case 3:
                            do{
                                printf("\nG ažžsž 90ž olmak žzere;");
                                printf("\nV(a) kenarortay uzunluðunu giriniz:m ");
                                scanf("%f",&kenar1);
                                printf("V(b) kenarortay uzunluðunu giriniz:m ");
                                scanf("%f",&kenar2);
                                if(kenar1<=0 || kenar2<=0){printf("\nKenar deðerlerinden birisine 0 veya negatif bir deðer girdiniz. Lütfen tekrar deneyiniz veya programý sonlandýrýnýz. (CTRL+C)\n");}
                            }while(kenar1<=0 || kenar2<=0);

                            kenar1kare=kenar1*kenar1;
                            kenar2kare=kenar2*kenar2;
                            kenar3kare=kenar1kare-kenar2kare;
                            if(kenar3kare==0){printf("\nKenar deðeri 0 veya negatif olamaz."); break;}
                            printf("\nV(c) doðrusunun uzunluðu %.4f m'dir.",sqrt(kenar3kare));
                            break;
                        default:
                            printf("Gecersiz bir secenek sectiniz.");
                            break;
                    }
                }
                break;
            case 5: // Ažž kenar bažžntžlaržndan yararlanarak bir kenaržn alabileceži dežer aralžžžnž hesaplar.
                printf("\nHangi kenarý hesaplamak istersiniz [a,b,c]: ");
                scanf("%s",&secenek4);
                if(*secenek4=='a'){
                    do{
                        printf("\nb kenarýnýn uzunluðunu giriniz:m ");
                        scanf("%f",&kenar2);
                        printf("c kenarýnýn uzunluðunu giriniz:m ");
                        scanf("%f",&kenar3);
                        if(kenar2==0 || kenar3==0){printf("\nKenar deðeri 0 veya negatif olamaz.");}
                    }while(kenar2==0 || kenar3==0);
                    printf("\n\nFormül: b+c > a > |b-c|");
                    kenar1fark=kenar2-kenar3;
                    kenar1top=kenar2+kenar3;
                    kenar1fark=abs(kenar1fark);
                    printf("\nSonuç: %.1f > a > %.1f",kenar1top,kenar1fark);
                }
                else if(*secenek4=='b'){
                    do{
                        printf("\na kenarýnýn uzunluðunu giriniz:m ");
                        scanf("%f",&kenar1);
                        printf("c kenarýnýn uzunluðunu giriniz:m ");
                        scanf("%f",&kenar3);
                        if(kenar1==0 || kenar3==0){printf("\nKenar deðeri 0 veya negatif olamaz.");}
                    }while(kenar1==0 || kenar3==0);
                    printf("\n\nFormül: a+c > b > |a-c|");
                    kenar2fark=kenar1-kenar3;
                    kenar2top=kenar1+kenar3;
                    kenar2fark=abs(kenar2fark);
                    printf("\nSonuç: %.1f > a > %.1f",kenar2top,kenar2fark);
                }
                else if(*secenek4=='c'){
                    do{
                        printf("\na kenarýnýn uzunluðunu giriniz:m ");
                        scanf("%f",&kenar1);
                        printf("b kenarýnýn uzunluðunu giriniz:m ");
                        scanf("%f",&kenar2);
                        if(kenar1==0 || kenar2==0){printf("\nKenar deðeri 0 veya negatif olamaz.");}
                    }while(kenar1==0 || kenar2==0);
                    printf("\n\nFormül: a+b > c > |a-b|");
                    kenar3fark=kenar1-kenar2;
                    kenar3top=kenar1+kenar2;
                    kenar3fark=abs(kenar3fark);
                    printf("\nSonuç: %.1f > a > %.1f",kenar3top,kenar3fark);
                }
                break;
            case 6: // Muhteþem üçlü hesaplamasý yapar.
                printf("\nDikten inen doðru tabaný iki eþ parçaya bölüyorsa inen [AD] doðrusunun uzunluðu ikiye bölünen kenarlardan bir tanesidir.");
                printf("\nTaban uzunluðunu giriniz:m ");
                scanf("%f",&taban);
                taban=taban/2;
                printf("Dikten inen kenarortay uzunluðu: %f m'dir.",taban);
                break;

            case 7: // Öklid hesaplamasý yapmamýzý saðlar.
                printf("\nÖklid teoremlerine hoþgeldiniz. ABC üçgeninde [AH] yükseklik olmak üzere;");
                printf("\n1 [AH], 2 [AB], 3 [AC], 4 [BC]");
                printf("\nHangi kenar ile iþlem yapmak istiyorsunuz: ");
                scanf("%d",&secim);
                if (secim==1){
                    printf("[BH] deðerini giriniz:m ");
                    scanf("%d",&p);
                    printf("[HC] deðerini giriniz:m ");
                    scanf("%d",&k);
                    h=p*k;
                    printf("\nYükseklik deðeri %d m'dir.",sqrt(h));
                }
                else if (secim==2){
                    printf("[BH] deðerini giriniz:m ");
                    scanf("%d",&p);
                    printf("[BC] deðerini giriniz:m ");
                    scanf("%d",&a);
                    c=p*a;
                    printf("\n[AB] deðeri %d m'dir.",sqrt(c));
                }
                else if (secim==3){
                    printf("[HC] deðerini giriniz:m ");
                    scanf("%d",&k);
                    printf("[BC] deðerini giriniz:m ");
                    scanf("%d",&a);
                    b=k*a;
                    printf("\n[AC] deðeri %f m'dir.",sqrt(b));
                }
                break;

            case 8: // Ýkizkenar üçgenlerle ilgili bilgiler verilir.
                printf("\nDik açýdan inen yükseklik hem açýortay, hem de kenarortaydýr. Kýsaca bir doðru parçasý 3 iþlev kazanýr.\n");
                printf("Bir üçgende ayný doðru parçasý hem yükseklik hem kenarortay olursa bu üçgen ikizkenar üçgendir.\n");
                printf("Bir üçgende ayný doðru parçasý hem yükseklik hem de açýortay oluyorsa bu üçgen ikizkenar üçgendir.\n");
                printf("Bir üçgende ayný doðru parçasý hem açýortay hem de kenarortay oluyorsa bu üçgen ikizkenar üçgendir.\n");
                break;

            case 9: // Eþkenar üçgenlerle ilgili bilgiler verilir.
                printf("\nTüm kenar uzunluklarý eþit olan üçgene eþkenar üçgen denir.\n");
                printf("Eþkenar üçgenin iç açýlarýnýn ölçüleri 60'dýr.'\n");
                break;

            default:
                printf("Geçersiz bir seçenek seçtiniz.");
                break;
        }
    }
    else if (*s == 'd'){
        printf("\nDüzlemde doðrusal olmayan dört noktanýn ikiþerli birleþtirilmesiyle oluþan þekle dörtgen denir.\n");
        printf("\n1.Secenek :Kare\n");
        printf("2.Secenek :Ýkizkenaryamuk\n");
        printf("3.Secenek :Deltoid\n");
        printf("4.Secenek :Eþkenar Dörtgen\n");
        printf("5.Secenek :Paralelkenar\n");
        printf ("\nSeçenek seçiniz: ");
        scanf("%d",&secenek);
        switch (secenek){
        case 1:
        	do { 
            	printf("\nTek kenar uzunluðunu giriniz:m ");
            	scanf("%f",&kenar);	
            	if (kenar==0){printf ("\nKenar uzunluðu 0 olamaz. Tekrar deðer giriniz.");} 
        	}while (kenar==0);
        	alan=kenar*kenar;
            cevre=kenar*4;
            printf("Alan deðeri %.1f m^2'dir.\n",alan);
            printf("Çevre deðeri %.1f m'dir.",cevre);
            break;
        case 2: 
        	do { 
	        	printf("\nABCD ikizkenaryamuðunda [DH] yükseklik, [AB] taban olmak üzere; ");
	           	printf("\n[DH] uzunluðunu giriniz:m ");
	           	scanf("%f",&yukseklik);
	           	printf("\n[HB] uzunluðunu giriniz:m ");
	           	scanf("%f",&kenar);
	           	printf("\n[AH] uzunluðunu giriniz:m ");
	           	scanf("%f",&kenar1);
	           	if (kenar==0){printf ("Kenar uzunluðu 0 olamaz. Tekrar deðer giriniz.\n");}
    		}while (kenar==0);
        	alan=yukseklik*kenar;
        	yukseklikkare==yukseklik*yukseklik;
        	kenar1kare==kenar*kenar;
        	kenar2==sqrt(yukseklikkare+kenar1kare);
        	cevre=(2*kenar2)+(2*kenar1)+2*(kenar-kenar1);
        	if(cevre==0){printf("\nKenar dežeri 0 veya negatif olamaz."); break;}
           	printf("\nAlan deðeri %.1f m^2'dir.",alan);
           	printf("\nÇevre deðeri %.1f m'dir.\n",cevre);
			break;
			case 3:
				printf  ("Görsellik gerektirdiði için hesaplanamýyor.");
				break;
			case 4:
				do {
					printf ("\nABCD eþkenar dörtgeninde tek kenar uzunluðunu giriniz:m ");
					scanf ("%f",&kenar);
					printf ("\n[AC] uzunluðunu giriniz:m ");
					scanf ("%f",&kenar1);
					printf ("\n[BD] uzunluðunu giriniz:m ");
					scanf ("%f",&kenar2);
				if (kenar==0){printf ("Kenar uzunluðu 0 olamaz. Tekrar deðer giriniz.\n");}	
				}while (kenar==0);
				alan=(kenar1*kenar2)/2;
				cevre=kenar*4;
				printf ("\nAlan deðeri %.1f m^2'dir",alan);
				printf ("\nÇevre deðeri %.1f m'dir",cevre);
				break;
			case 5:
				do {
					printf ("\nGeniþ kenarýn uzunluðunu giriniz:m ");
					scanf ("%f",&kenar);
					printf ("Kýsa kenarýn uzunluðunu giriniz:m ");
					scanf ("%f",&kenar1);
					printf ("Geniþ kenara inen yüksekliðin uzunluðunu giriniz:m ");
					scanf ("%f",&kenar2);
				if (kenar==0){printf ("\nKenar uzunluðu 0 olamaz.Tekrar deðer giriniz.");}	
				}while (kenar==0);
				alan=kenar*kenar2;
				cevre=(kenar*2)+(kenar1*2);
				printf ("\nAlan deðeri %.1f m^2'dir.",alan);
				printf ("\nÇevre deðeri %.1f m'dir.",cevre);
				break;
        default:
            printf("Geçersiz bir seçenek seçtiniz.");
            break;
        }
    } 
    else if (*s == 'b'){
            printf("\nTek kenar uzunluðunu giriniz:m ");
            scanf("%f",&kenar);

            printf("Yükseklik deðerini giriniz:m ");
            scanf("%f",&yukseklik);
            
            alan = 5*kenar*yukseklik/2;
            cevre = kenar*5;
            
            printf("\nAlan deðeri: %.1f m^2'dir.\n",alan);
            printf("Çevre deðeri: %.1f m'dir.",cevre);

    }
    else if (*s == 'a'){
            printf("\nTek kenar uzunluðunu giriniz:m ");
            scanf("%f",&kenar);

            kenarkare = kenar*kenar;
            alan = (3*kenarkare)/2;

            cevre = kenar*6;
            printf("\nAlan deðeri: %.1f m^2'dir.\n",alan);
            printf("Çevre deðeri: %.1f m'dir.\n",cevre);
            
    }
    else{
        printf("Geçersiz bir þekil girdiniz. Programý sonlandýrýp tekrar deneyiniz.\n");
    }
    printf("\n\nProgramý sonlandýrmak için herhangi bir tuþa basýnýz.");
    getchar();
    getchar();
    return 0;
}
