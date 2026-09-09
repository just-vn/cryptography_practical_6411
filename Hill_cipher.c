#include <stdio.h>
#include <string.h>
#include <ctype.h>

int modInverse(int a)
{
    int i;
    for (i = 1; i < 26; i++)
    {
        if ((a * i) % 26 == 1)
            return i;
    }
    return -1;
}

int main()
{
    char text[100];
    int key[2][2];
    int invKey[2][2];
    int i, j, k;
    int len;
    int det, invDet;

    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    /* Remove newline */
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the 2x2 key matrix:\n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &key[i][j]);
        }
    }

    /* Calculate determinant */
    det = key[0][0] * key[1][1] - key[0][1] * key[1][0];
    det = (det % 26 + 26) % 26;

    invDet = modInverse(det);

    if (invDet == -1)
    {
        printf("Invalid key matrix! Decryption is not possible.\n");
        return 0;
    }

    /* Encryption */
    len = strlen(text);

    /* Convert to uppercase and remove spaces */
    char clean[100];
    int n = 0;

    for (i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            clean[n++] = toupper(text[i]);
        }
    }

    clean[n] = '\0';

    /* Add X if length is odd */
    if (n % 2 != 0)
    {
        clean[n++] = 'X';
        clean[n] = '\0';
    }

    char encrypted[100];

    for (i = 0; i < n; i += 2)
    {
        int x = clean[i] - 'A';
        int y = clean[i + 1] - 'A';

        encrypted[i] =
            (key[0][0] * x + key[0][1] * y) % 26 + 'A';

        encrypted[i + 1] =
            (key[1][0] * x + key[1][1] * y) % 26 + 'A';
    }

    encrypted[n] = '\0';

    printf("\nEncrypted text: %s\n", encrypted);

    /* Find inverse key matrix
       Inverse of [a b]
                  [c d]
       = invDet * [ d -b]
                   [-c  a]
    */

    invKey[0][0] = (key[1][1] * invDet) % 26;
    invKey[0][1] = (-key[0][1] * invDet) % 26;
    invKey[1][0] = (-key[1][0] * invDet) % 26;
    invKey[1][1] = (key[0][0] * invDet) % 26;

    /* Make values positive */
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            invKey[i][j] = (invKey[i][j] + 26) % 26;
        }
    }

    /* Decryption */
    char decrypted[100];

    for (i = 0; i < n; i += 2)
    {
        int x = encrypted[i] - 'A';
        int y = encrypted[i + 1] - 'A';

        decrypted[i] =
            (invKey[0][0] * x + invKey[0][1] * y) % 26 + 'A';

        decrypted[i + 1] =
            (invKey[1][0] * x + invKey[1][1] * y) % 26 + 'A';
    }

    decrypted[n] = '\0';

    printf("Decrypted text: %s\n", decrypted);

    return 0;
}

Enter the plaintext: HELP
Enter the 2x2 key matrix:
3 3
2 5

Encrypted text: HIAT
Decrypted text: HELP

