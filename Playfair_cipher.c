#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

/* Create the 5x5 Playfair matrix */
void generateMatrix(char key[])
{
    int used[26] = {0};
    int i, j, k = 0;
    char ch;

    /* I and J are treated as the same letter */
    used['J' - 'A'] = 1;

    /* Add key letters */
    for (i = 0; key[i] != '\0'; i++)
    {
        ch = toupper(key[i]);

        if (ch < 'A' || ch > 'Z')
            continue;

        if (ch == 'J')
            ch = 'I';

        if (!used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    /* Add remaining alphabet letters */
    for (ch = 'A'; ch <= 'Z'; ch++)
    {
        if (!used[ch - 'A'])
        {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}

/* Display the matrix */
void displayMatrix()
{
    int i, j;

    printf("\nPlayfair Matrix:\n");

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

/* Find position of a character */
void findPosition(char ch, int *row, int *col)
{
    int i, j;

    if (ch == 'J')
        ch = 'I';

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

/* Encrypt or decrypt a pair */
void processPair(char a, char b, char *x, char *y, int decrypt)
{
    int r1, c1, r2, c2;

    findPosition(a, &r1, &c1);
    findPosition(b, &r2, &c2);

    if (r1 == r2)
    {
        /* Same row */
        if (!decrypt)
        {
            *x = matrix[r1][(c1 + 1) % 5];
            *y = matrix[r2][(c2 + 1) % 5];
        }
        else
        {
            *x = matrix[r1][(c1 + 4) % 5];
            *y = matrix[r2][(c2 + 4) % 5];
        }
    }
    else if (c1 == c2)
    {
        /* Same column */
        if (!decrypt)
        {
            *x = matrix[(r1 + 1) % 5][c1];
            *y = matrix[(r2 + 1) % 5][c2];
        }
        else
        {
            *x = matrix[(r1 + 4) % 5][c1];
            *y = matrix[(r2 + 4) % 5][c2];
        }
    }
    else
    {
        /* Rectangle rule */
        *x = matrix[r1][c2];
        *y = matrix[r2][c1];
    }
}

/* Prepare plaintext for encryption */
void prepareText(char input[], char output[])
{
    int i, j = 0;
    char a, b;

    for (i = 0; input[i] != '\0'; i++)
    {
        if (isalpha(input[i]))
        {
            a = toupper(input[i]);

            if (a == 'J')
                a = 'I';

            if (input[i + 1] != '\0')
            {
                int next = i + 1;

                while (input[next] != '\0' && !isalpha(input[next]))
                    next++;

                if (input[next] != '\0')
                {
                    b = toupper(input[next]);

                    if (b == 'J')
                        b = 'I';

                    if (a == b)
                    {
                        output[j++] = a;
                        output[j++] = 'X';
                    }
                    else
                    {
                        output[j++] = a;
                        output[j++] = b;
                        i = next;
                    }
                }
                else
                {
                    output[j++] = a;
                    output[j++] = 'X';
                }
            }
            else
            {
                output[j++] = a;
                output[j++] = 'X';
            }
        }
    }

    output[j] = '\0';
}

int main()
{
    char key[100];
    char plaintext[100];
    char prepared[200];
    char encrypted[200];
    char decrypted[200];

    int i;
    char x, y;

    printf("Enter the key: ");
    scanf("%s", key);

    getchar();

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    generateMatrix(key);
    displayMatrix();

    /* Prepare plaintext */
    prepareText(plaintext, prepared);

    /* Encryption */
    for (i = 0; prepared[i] != '\0'; i += 2)
    {
        processPair(prepared[i], prepared[i + 1],
                    &encrypted[i], &encrypted[i + 1], 0);
    }

    encrypted[i] = '\0';

    printf("\nPrepared plaintext: %s", prepared);
    printf("\nEncrypted text: %s", encrypted);

    /* Decryption */
    for (i = 0; encrypted[i] != '\0'; i += 2)
    {
        processPair(encrypted[i], encrypted[i + 1],
                    &decrypted[i], &decrypted[i + 1], 1);
    }

    decrypted[i] = '\0';

    printf("\nDecrypted text: %s\n", decrypted);

    return 0;
}

Enter the key: MONARCHY
Enter the plaintext: INSTRUMENTS

Prepared plaintext: INSTRUMENTSX
Encrypted text: GATLMZCLRQXA
Decrypted text: INSTRUMENTSX
