#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, z, w, g;
    long double c_Zero =  299792458; //c_Zero (boşlukta ışık hızı, m/s cinsinden)
    long double f; //f (frekans)
    long double lamda_Zero; //lamda_Zero (lamda değeri)
    long double T; //T (periyod)
    long double faz_Grad; //faz_Grad (Faz açsı grad cinsinden)
    long double s; //s (devir sayısı)
    long double n_g; //Grup kırılma indisi (ng)
    long double t_ussu; //Islak hava sıcaklığı santigrad cinsinden
    long double E_ussu; //E üssü değeri mmHg cinsinden
    long double P; //P (mmHg) hava basıncı değeri
    long double e; //e değeri kısmi su buharı basıncı mmHg cinsinden
    long double t; //t (kuru sıcaklık) santigrad cinsinden
    long double n_I; //n_ı değeri
    long double c; //c değeri m/s cinsinden
    long double lamda; //Ortamdaki lamda değeri Mikrometre(µm) cinsinden
    long double n_m; //Mikro dalga kırılma indisi (nm)
    long double C; //Düzeltme sonrası c
    long double Essen_Froome; //Essen ve Froome eşitliği
    long double gidis_donus; //Işığın gidiş-dönüş zamanı
    long double isik_hizi; //Ortamın ışık hızı
    long double Delta; //Alet ile reflektör arası mesafe
    long double fg; //Gönderilen frekans mHz
    long double fA; //Alınan frekans mHz
    long double delta_t; //Seyahat süresi
    long double Lamda; //Dalga boyu m cinsinde
    long double faz_farki_4, faz_farki_3, faz_farki_2, faz_farki_1; //Faz farkları
    long double Li_4, Li_3, Li_2, Li_1; //Li değerleri

    printf("###ELEKTRONİK UZUNLUK ÖLÇMELERİ HESAPLAMALARI!!!###\n");

    // Neyi hesaplatmak istediğini sor.
    printf("1 => ELEKTROMANYETİK DALGALARIN TEMELLERİ!!!\n");
    printf("2 => KIRILMA İNDİSİ (n)!!!\n");
    printf("3 => MİKRO DALGALARIN KIRILMA İNDİSİ (n)!!!\n");
    printf("4 => ELEKTRONİK UZUNLUK ÖLÇMELERİ YÖNTEMLERİ!!!\n");
    printf("Hangisi: ");
    scanf("%d", &y);
    if (y == 1) {
        printf("\n1 => Frekans hesaplaması,\n");
        printf("2 => Periyod hesaplaması,\n");
        printf("3 => Faz açısı hesaplaması,\n");
        printf("Hesaplamak istediğin işlemi tuşla: ");
        scanf("%d", &x);
    }
    else if (y == 2) {
        printf("\n1 => Grup kırılma indisi (ng) hesaplanması,\n");
        printf("2 => E üssü hesaplanması mmHg cinsinden,\n");
        printf("3 => e değerinin hesaplanması mmHg cinsinden,\n");
        printf("4 => n_I değeri hesaplanması,\n");
        printf("5 => c değerinin hesaplanması m/s cinsinden,\n");
        printf("6 => Ortamdaki lamda değerinin hesaplanması,\n");
        printf("Hesaplamak istediğin işlemi tuşla: ");
        scanf("%d", &z);
    }
    else if (y == 3) {
        printf("\n1 => E üssü hesaplanması mmHg cinsinden,\n");
        printf("2 => e değerinin hesaplanması mmHg cinsinden,\n");
        printf("3 => Mikro dalga kırılma indisi (nm) hesaplanması,\n");
        printf("4 => Essen ve Froome düzeltmesi ve hızı,\n");
        printf("Hesaplamak istediğin işlemi tuşla: ");
        scanf("%d", &w);
    }
    else if(y == 4) {
        printf("\n1 => İmpuls yöntemi (Pulse) m cinsinden,\n");
        printf("2 => Doppler yöntemi m cinsinden,\n");
        printf("4 => Faz farkı yöntemi m cinsinden,\n");
        printf("Hesaplamak istediğin işlemi tuşla: ");
        scanf("%d", &g);
    }

    // ELEKTROMANYETİK DALGALARIN TEMELLERİ!!!
    if (y == 1) {
        printf("\n###ELEKTROMANYETİK DALGALARIN TEMELLERİ!!!###\n");
        // Frekans hesaplanması, GHz cinsinden.
        printf("lamda_Zero değerini Mikrometre(µm) cinsinden gir: ");
        scanf("%Lf", &lamda_Zero);
        f = c_Zero / (lamda_Zero * pow(10, -6));
        if (x == 1) {
            printf("f: %Lf GHz\n", f);
        }
        // Periyod (T) hesaplaması, ns cinsinden.
        T = 1 / (f * pow(10, -9));
        if (x == 2) {
            printf("T: %.25Lf nanosaniye\n", T);
        }
        // Faz açısı hesaplanması grad cinsinden.
        printf("Işığın boşlukta aldığı yolu (s) metre cinsinden giriniz: ");
        scanf("%Lf", &s);
        faz_Grad = s / (lamda_Zero * pow(10, -6));
        faz_Grad = faz_Grad * 400;
        long double ceill(long double faz_Grad);
        long double a = 400;
        faz_Grad = fmod(faz_Grad, a);
        if (x == 3) {
            printf("faz_Grad: %.4Lf grad\n", faz_Grad);
        }
    }

    // KIRILMA İNDİSİ (n) (Bir dalganın ortamdaki yavaşlama katsayısı)
    else if (y == 2) {
        printf("\n###KIRILMA İNDİSİ (n)!!!###\n");
        // Grup Kırılma İndisi (ng) hesaplanması
        printf("lamda_Zero değerini Mikrometre(µm) cinsinden gir: ");
        scanf("%Lf", &lamda_Zero);
        printf("t_ussu değerini santigrad cinsinden gir: ");
        scanf("%Lf", &t_ussu);
        printf("P değerini mmHg cinsinden giriniz: ");
        scanf("%Lf", &P);
        printf("t (kuru sıcaklık) santigrad cinsinden gir: ");
        scanf("%Lf", &t);
        n_g = ((287.604 + (4.8864 / pow(lamda_Zero, 2)) + (0.0680 / pow(lamda_Zero, 4))) / pow(10, 6)) + 1;
        if (z == 1) {
            printf("n_g: %.20Lf\n", n_g);
        }
        // E üssü hesaplanması mmHg cinsinden
        E_ussu = pow(10, (((7.5 * t_ussu) / (237.3 + t_ussu)) + 0.6609));
        if (z == 2) {
            printf("E_ussu: %.13Lf mmHg\n", E_ussu);
        }
        // e değerinin hesaplanması mmHg cinsinden
        e = E_ussu - 0.5 * (t - t_ussu) * (P / 755);
        if (z == 3) {
            printf("e: %.13Lf mmHg\n", e);
        }
        // n_I değeri hesaplanması
        n_I = 1 + ((0.35947 * (n_g - 1) * P) / (273.2 + t)) - ((1.5026 * e * pow(10, -5)) / (273.2 + t));
        if (z == 4) {
            printf("n_I: %.13LF\n", n_I);
        }
        // c değerinin hesabı m/s cinsinden
        c = c_Zero / n_I;
        if (z == 5) {
            printf("c: %Lf m/s\n", c);
        }
        // Ortamdaki lamda değerinin hesaplanması Mikrometre(µm) cinsinden
        lamda = (lamda_Zero / n_I) * pow(10, 3);
        if (z == 6) {
            printf("lamda: %.13Lf nanometre\n", lamda);
        }
    }

    // MİKRO DALGALARIN KIRILMA İNDİSİ (nm)!!!
    else if (y == 3) {
        // E üssü değerinin hesaplanması mmHg cinsinden
        printf("t_ussu değerini santigrad cinsinden gir: ");
        scanf("%Lf", &t_ussu);
        E_ussu = pow(10, (((7.5 * t_ussu) / (237.3 + t_ussu)) + 0.6609));
        if (w == 1) {
            printf("E_ussu: %Lf mmHg\n", E_ussu);
        }
        // e değerinin hesaplanması mmHg cinsinden
        printf("t (kuru sıcaklık) santigrad cinsinden gir: ");
        scanf("%Lf", &t);
        printf("P değerini mmHg cinsinden giriniz: ");
        scanf("%Lf", &P);
        e = E_ussu - 0.5 * (t - t_ussu) * (P / 755);
        if (w == 2) {
            printf("e: %.13Lf mmHg\n", e);
        }
        // n_m değerinin hesaplanması
        n_m = (((103.49 / (273.2 + t)) * (P - e) + (86.26 / (273.2 + t)) * (1 + (5748 / (273.2 + t))) * e) / pow(10, 6)) + 1;
        if (w == 3) {
            printf("n_m: %.20Lf\n", n_m);
            C = c_Zero * n_m;
            printf("C düzeltme öncesi: %Lf m/s\n", C);
        }
        // Essen ve Froome eşitliği düzetlmesi Lamda0 = 8 mm ve e = 10 mmHg ise
        Essen_Froome = n_m + 0.5 * pow(10, -6);
        if (w == 4) {
            printf("Essen ve Froome eşitliği düzeltmesi: %.13Lf\n", Essen_Froome);
            C = c_Zero * Essen_Froome;
            printf("C düzeltme sonrası: %Lf m/s\n", C);
        }
    }

    // ELEKTRONİK UZUNLUK ÖLÇMELERİ YÖNTEMLERİ
    else if(y == 4) {
        // İmpuls yöntemi (Pulse) hesaplama
        if(g == 1){
            printf("Işığı gidiş-dönüş seyahat süresi saniye cinsinde: ");
            scanf("%Lf", &gidis_donus);
            printf("Ortamın ışık hızı m/s cinsinde: ");
            scanf("%Lf", &isik_hizi);
            Delta = (0.5) * gidis_donus * isik_hizi;
            printf("Delta mesafe değeri %.13Lf m\n", Delta);
        }
        // Doppler yöntemi hesaplama
        if(g == 2) {
            printf("Gönderilen sinyalin frekansı mHz cinsinde: ");
            scanf("%Lf", &fg);
            printf("Yansıtıcıdan dönen sinyalin frekansı mHz cinsinde: ");
            scanf("%Lf", &fA);
            printf("Seyahat süresi saniye cinside: ");
            scanf("%Lf", &delta_t);
            printf("Lamda değeri m cinsinde: ");
            scanf("%Lf", &Lamda);
            Delta = (0.5) * ((fA - fg) * 1000000) * Lamda * delta_t;
            printf("Delta mesafe değeri %.13Lf m\n", Delta);
        }
        // Faz Farkı Yöntemi
        if (g == 4) {
            printf("  |  li  |  Ui (m)  |  li * Ui (m)  \n");
            printf("4 | ");
            scanf("%Lf", &faz_farki_4);
            printf("3 | ");
            scanf("%Lf", &faz_farki_3);
            printf("2 | ");
            scanf("%Lf", &faz_farki_2);
            printf("1 | ");
            scanf("%Lf", &faz_farki_1);
            Li_4 = faz_farki_4 * 10000;
            Li_3 = faz_farki_3 * 1000;
            Li_2 = faz_farki_2 * 100;
            Li_1 = faz_farki_1 * 10;
            printf("\nTaploda gösterimi => \n");
            printf("  |     li    |  Ui (m)  |  li * Ui (m)  \n");
            printf("-------------------------------------------\n");
            printf("4 | %Lf  |   10000  |     %.5Lf     \n", faz_farki_4, Li_4);
            printf("3 | %Lf  |    1000  |     %.5Lf     \n", faz_farki_3, Li_3);
            printf("2 | %Lf  |     100  |     %.5Lf     \n", faz_farki_2, Li_2);
            printf("1 | %Lf  |      10  |     %.5Lf     \n", faz_farki_1, Li_1);
            Li_4 = floorl(Li_4 / 1000);
            Li_3 = floorl(Li_3 / 100);
            Li_2 = floorl(Li_2 / 10);
            printf("Se %.0Lf%.0Lf%.0Lf%.13Lf m\n", Li_4, Li_3, Li_2, Li_1);
        }
    }
}
