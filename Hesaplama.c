#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, z;
    long double c_Zero =  299792458; //c_Zero (boşlukta ışık hızı, m/s cinsinden)
    long double f; //f (frekans)
    long double lamda_Zero; //lamda_Zero (lamda değeri)
    long double T; //T (periyod)
    long double faz_Grad; //faz_Grad (Faz açsı grad cinsinden)
    long double s; //s (devir sayısı)
    long double n_g; //Grup kırılma indisi (ng)
    long double E_ussu; //E üssü değeri mmHg cinsinden
    long double P; //P (mmHg) hava basıncı değeri
    long double e; //e değeri mmHg cinsinden

    printf("###ELEKTRONİK UZUNLUK ÖLÇMELERİ HESAPLAMALARI!!!###\n");

    // Neyi hesaplatmak istediğini sor.
    printf("1 => ELEKTROMANYETİK DALGALARIN TEMELLERİ!!!\n");
    printf("2 => KIRILMA İNDİSİ (n)!!!\n");
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
        printf("4 => blaa blaa\n");
        printf("Hesaplamak istediğin işlemi tuşla: ");
        scanf("%d", &z);
    }

    // ELEKTROMANYETİK DALGALARIN TEMELLERİ!!!
    if (y == 1) {
        printf("\n###ELEKTROMANYETİK DALGALARIN TEMELLERİ!!!###\n");
        // Frekans hesaplanması, GHz cinsinden.
        printf("lamda_Zero değerini Mikrometre(µm) cinsinden gir: ");
        scanf("%Lf", &lamda_Zero);
        f = c_Zero / (lamda_Zero * pow(10, -6));
        if (x == 1) {
            printf("f: %Lf GHz cinsinden.\n", f);
        }
        // Periyod (T) hesaplaması, ns cinsinden.
        T = 1 / (f * pow(10, -9));
        if (x == 2) {
            printf("T: %.25Lf ns cinsinden.\n", T);
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
            printf("faz_Grad: %.4Lf grad.\n", faz_Grad);
        }
    }

    // KIRILMA İNDİSİ (n) (Bir dalganın ortamdaki yavaşlama katsayısı)
    else if (y == 2) {
        printf("\n###KIRILMA İNDİSİ (n)!!!###\n");
        // Grup Kırılma İndisi (ng) hesaplanması
        printf("lamda_Zero değerini Mikrometre(µm) cinsinden gir: ");
        scanf("%Lf", &lamda_Zero);
        n_g = ((287.604 + (4.8864 / pow(lamda_Zero, 2)) + (0.0680 / pow(lamda_Zero, 4))) / pow(10, 6)) + 1;
        if (z == 1) {
            printf("n_g: %.20Lf\n", n_g);
        }
        // E üssü hesaplanması mmHg cinsinden
        E_ussu = pow(10, (((7.5 * 9) / (273.15 + 9)) + 0.6609));
        if (z == 2) {
            printf("E_ussu: %Lf mmHg\n", E_ussu);
        }
        // e değerinin hesaplanması mmHg cinsinden
        printf("P değerini mmHg cinsinden giriniz: ");
        scanf("%Lf", &P);
        e = E_ussu - 0.5 * (12-9) * (P / 755);
        if (z == 3) {
            printf("e: %Lf\n", e);
        }
    }

}
