#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //Berhenti kalo tidak ada key
    if (argc < 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Berhenti bila key lebih dari satu
    if (argv[2] != 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //mengecek digit dari argumen key
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    //buat variable integer key
    int key = atoi(argv[1]);
    //bila key negative
    if (key < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //pengecekan key selesai
    printf("Success\n");

    //meminta user masukkan text
    string plaintext = get_string("plaintext: ");
    
    //loop untk mengganti character
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (isupper(plaintext[i]) != 0)
        {
            plaintext[i] = ((((plaintext[i] - 65) + key)) % 26) + 65;
        }

        if (islower(plaintext[i]) != 0)
        {
            plaintext[i] = ((((plaintext[i] - 97) + key)) % 26) + 97;
        }
    }

    //print hasil ciphertext
    printf("ciphertext: %s\n", plaintext);
    return 0;
}