#include <stdio.h>
#include <stdlib.h>

void DosyaYazdir();
void BubbleSort(int dizi[], int boyut);
int AralarindaAsal(int x, int y);

int main()
{
    DosyaYazdir();
    return 0;
}
void DosyaYazdir()
{
    int HP=100;
    int EngelSayisi;
    int ParkurUzunlugu;
    int *EngelMetre;
    int i, S;
    FILE *Xurvivor;

    srand(time(0));
    ParkurUzunlugu=50+rand()%50;
    EngelSayisi=2+rand()%3;

    EngelMetre= (int *) malloc(sizeof(int)*EngelSayisi);

    if(EngelMetre==NULL)
    {
        printf("Yetersiz bellek alani!\a");
        exit(1);
    }

    for(i=0; i<EngelSayisi; i++)
        EngelMetre[i]=5+rand()%(ParkurUzunlugu-5);

    BubbleSort(EngelMetre, EngelSayisi);

    Xurvivor=fopen("log.txt" , "w");

    if(Xurvivor==NULL)
    {
        printf("log.txt dosyasi acilamadi!\a");
        exit(1);
    }

    fprintf(Xurvivor, "Yarisma Basladi !!!\n");
    fprintf(Xurvivor, "Yarismaci HP = %d\n",HP);

    for(i=0; i<EngelSayisi; i++)
    {
        fprintf(Xurvivor, "Yarismaci %d. metreye kadar bir engelle karsilasmadi.\n",EngelMetre[i]);
        fprintf(Xurvivor, "%d. metrede bir engel var. ",EngelMetre[i]);

        S= AralarindaAsal(EngelMetre[i], HP);

        if(S==1)
        {
            fprintf(Xurvivor, "%d ve %d aralarinda asal degildir.\n",HP ,EngelMetre[i]);
        }

        else
        {
            fprintf(Xurvivor, "%d ve %d aralarinda asaldir.\n",HP ,EngelMetre[i]);
            HP-=EngelMetre[i];
        }

        fprintf(Xurvivor, "Yarismaci HP = %d\n",HP);

        if(HP<=0)
            break;
    }

    if(HP<=0)
        fprintf(Xurvivor, "Uzgunum !!! Yarismayi tamamlayamadin.");

    else
    {
        fprintf(Xurvivor, "Yarismaci %d. metreye kadar bir engelle karsilasmadi.\n",ParkurUzunlugu);
        fprintf(Xurvivor, "Tebrikler !!! Yarismayi %d HP ile bitirdiniz.",HP);
    }

    fclose(Xurvivor);
    free(EngelMetre);
}
void BubbleSort(int dizi[], int boyut)
{
    int i, j, temp;

    for(i=0; i<boyut-1; i++)
    {
        for(j=0; j<boyut-1; j++)
        {
            if(dizi[j]>dizi[j+1])
            {
                temp=dizi[j];
                dizi[j]=dizi[j+1];
                dizi[j+1]=temp;
            }
        }
    }
}
int AralarindaAsal(int x, int y)
{
   int i, ks, a;

   if(y<x)
        ks=y;

   else
        ks=x;

   for(i=2; i<=ks; i++)
   {
       if(y%i==0 && x%i==0)
       {
           a=1;
           break;
       }

       else
            a=2;
    }

   return a;
}
