#include <stdio.h>
#include <string.h>

int main()
{
    char text[100], rail[10][100];
    int key, len, i, j, row = 0, dir = 1, k = 0;

    printf("Enter the text: ");
    scanf("%s", text);

    printf("Enter number of rails: ");
    scanf("%d", &key);

    len = strlen(text);

    /* Encryption */
    for(i = 0; i < key; i++)
        for(j = 0; j < len; j++)
            rail[i][j] = '\0';

    row = 0;
    for(i = 0; i < len; i++)
    {
        rail[row][i] = text[i];
        if(row == key-1) dir = -1;
        if(row == 0) dir = 1;
        row += dir;
    }

    printf("Encrypted: ");
    for(i = 0; i < key; i++)
        for(j = 0; j < len; j++)
            if(rail[i][j])
                printf("%c", rail[i][j]);

    /* Decryption */
    row = 0; dir = 1;

    for(i = 0; i < len; i++)
    {
        rail[row][i] = '*';
        if(row == key-1) dir = -1;
        if(row == 0) dir = 1;
        row += dir;
    }

    k = 0;
    for(i = 0; i < key; i++)
        for(j = 0; j < len; j++)
            if(rail[i][j] == '*' )
                rail[i][j] = text[k++];

    printf("\nDecrypted: ");
    row = 0; dir = 1;

    for(i = 0; i < len; i++)
    {
        printf("%c", rail[row][i]);
        if(row == key-1) dir = -1;
        if(row == 0) dir = 1;
        row += dir;
    }

    return 0;
}

Enter the text: HELLOWORLD
Enter number of rails: 3

Encrypted: HOLELWRDLO
Decrypted: HELLOWORLD
