#include <stdio.h>
#include <math.h>

int main()
{
    int x, y, z;
    long double c_Zero =  299792458; //c_Zero (boşlukta ışık hızı, m/s cinsinden)
    long double f, lamda_Zero; //f (frekans), lamda_Zero (lamda değeri)
    long double T; //T (periyod)
    long double faz_Grad, s; //faz_Grad (Faz açsı grad cinsinden), s (devir sayısı)
    long double n_g = //Grup kırılma indisi (ng)

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
        printf("\n1 => Grup kırılma indisi,\n");
        printf("2 => blaa blaaa\n");
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
    }

}
