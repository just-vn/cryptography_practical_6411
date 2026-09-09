#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char plaintext[100], ciphertext[100];
    char key[27] = "QWERTYUIOPASDFGHJKLZXCVBNM";
    int i;

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    /* Encryption */
    for (i = 0; plaintext[i] != '\0'; i++)
    {
        if (isupper(plaintext[i]))
            ciphertext[i] = key[plaintext[i] - 'A'];
        else if (islower(plaintext[i]))
            ciphertext[i] = tolower(key[plaintext[i] - 'a']);
        else
            ciphertext[i] = plaintext[i];
    }

    ciphertext[i] = '\0';

    printf("\nEncrypted text: %s", ciphertext);

    /* Decryption */
    for (i = 0; ciphertext[i] != '\0'; i++)
    {
        if (isupper(ciphertext[i]))
        {
            int j;
            for (j = 0; j < 26; j++)
            {
                if (key[j] == ciphertext[i])
                {
                    plaintext[i] = 'A' + j;
                    break;
                }
            }
        }
        else if (islower(ciphertext[i]))
        {
            int j;
            for (j = 0; j < 26; j++)
            {
                if (tolower(key[j]) == ciphertext[i])
                {
                    plaintext[i] = 'a' + j;
                    break;
                }
            }
        }
        else
            plaintext[i] = ciphertext[i];
    }

    plaintext[i] = '\0';

    printf("Decrypted text: %s", plaintext);

    return 0;
}

Enter the plaintext: HELLO WORLD

Encrypted text: ITSSG VGKSR
Decrypted text: HELLO WORLD
