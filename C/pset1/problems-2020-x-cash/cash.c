#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    //declare float disini agar jadi universal
    float change;
    //prompt user agar tidak memasukkan akan negative
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0.00);
    //mengintegerkan dan membulatkan float
    int dollar = round(change * 100);
    //membuat counter berapa banyak coin
    //ditulis 0 agar bisa di counter++
    int counter = 0;
    //bila dollar diatas 24 maka gunakan pecahan 25 dan hitung counter+1
    while (dollar > 24)
    {
        dollar = dollar - 25;
        counter++;
    }
    //bila dollar diatas 9 maka gunakan pecahan 10
    while (dollar > 9)
    {
        dollar = dollar - 10;
        counter++;
    }
    //bila dollar diatas 4 maka gunakan pecahan 5
    while (dollar > 4)
    {
        dollar = dollar - 5;
        counter++;
    }
    //bila dollar diatas 0 maka gunakan pecahan 1
    while (dollar > 0)
    {
        dollar = dollar - 1;
        counter++;
    }
    //print banyak coin di layar
    printf("%i\n", counter);
}