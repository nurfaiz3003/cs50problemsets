#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    //Memaksa User untuk hanya memasukkan angka 1 sampai 8
    do
    {
        n = get_int("Positive Number: ");
    }
    while (n < 1 || n > 8);
    //Loop per barisan
    for (int i = 0; i < n; i++)
    {
        //Loop untuk spasi
        for (int j = 0; j < n - (i + 1); j++)
        {
            printf(" ");
        }
        //Loop untuk # kiri
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        //Membuat Gap
        printf("  ");
        //Loop untuk # kanan
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        //Melanjutkan ke baris baru
        printf("\n");
    }
}