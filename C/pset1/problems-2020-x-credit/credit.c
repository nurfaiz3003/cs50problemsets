#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long number = 0;
    //Memaksa User Masukkan digit positif
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    //Declare data types
    long digita = 0;
    long digitb = 0;
    long suma = 0;
    long sumb = 0;
    int counter = 0;
    //sum digit genap dari belakang lalu kali 2, count digit
    for (long x = 100; ((number * 10) / x) > 1 ; x = x * 100)
    {
        digita = ((number % x) / (x / 10)) * 2;
        //bila 2 digit, pisahkan digit lalu tambahkan
        if (digita > 9)
        {
            long digit1 = digita % 10;
            long digit2 = digita / 10;
            suma = suma + digit1 + digit2;
            counter++;
        }
        //bila 1 digit, langsung sum
        else
        {
            suma = suma + digita;
            counter++;
        }
    }

    //sum ganjil dari belakang, count digit
    for (long x = 10; ((number * 10) / x) > 1 ; x = x * 100)
    {
        digitb = ((number % x) / (x / 10));
        sumb = sumb + digitb;
        counter++;
    }
    
    //checksum remainder
    int checksum = (suma + sumb) % 10;
    
    //membuat pangkat dari counter
    long power = pow(10, counter);
    //untuk 1 digit depan
    long fd = (number % power) / (power / 10);
    //untuk 2 digit depan
    long sd = (number / (power / 100));
    
    //condition tiap kartu
    if (checksum == 0 && (counter == 16 || counter == 13) && fd == 4)
    {
        printf("VISA\n");
    }
    else if (checksum == 0 && counter == 16 && sd > 50 && sd < 56)
    {
        printf("MASTERCARD\n");
    }
    else if (checksum == 0 && counter == 15 && (sd == 34 || sd == 37))
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}