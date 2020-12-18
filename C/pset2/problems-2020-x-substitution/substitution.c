#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    //Cek banyak argumen tidak boleh tidak ada dan lebih dari satu
    if (argc < 2 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    //menghitung banyak char
    int counter = 0;

    //mengeceh apakah char alphabet sambil menghitung banyak char
    for (int i = 0; argv[1][i] != '\0' ; i++)
    {
        counter++;
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Key must only contain alphabetics character.\n");
            return 1;
        }
    }

    //bila char bukan 26 beri peringatan
    if (counter != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    //mengecek char double
    for (int i = 0; argv[1][i] != '\0' ; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            if (argv[1][i] == toupper(argv[1][(i + j + 1) % 26]) || argv[1][i] == tolower(argv[1][(i + j + 1) % 26]))
            {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }

    //membuat key
    int key[26];
    for (int i = 0; argv[1][i] != '\0' ; i++)
    {
        if (isupper(argv[1][i]) != 0)
        {
            key[i] = argv[1][i] - (65 + i);
        }

        else
        {
            key[i] = argv[1][i] - (97 + i);
        }
    }

    //meminta user memasukkan text
    string pt = get_string("plaintext: ");
    //membuat array ciphertext 
    int cp [strlen(pt)];
    //merubah plaintext ke ciphertext sesuai key
    for (int i = 0; pt[i] != '\0'; i++)
    {
        if (isupper(pt[i]) != 0)
        {
            cp[i] = ((pt[i] - 65 + key[pt[i] - 65]) % 26) + 65;
        }

        else if (islower(pt[i]) != 0)
        {
            cp[i] = ((pt[i] - 97 + key[pt[i] - 97]) % 26) + 97;
        }

        else
        {
            cp[i] = pt[i];
        }
    }

    //print ciphertext di layar
    printf("ciphertext: ");
    for (int i = 0; pt[i] != '\0'; i++)
    {
        printf("%c", cp[i]);
    }
    printf("\n");
}