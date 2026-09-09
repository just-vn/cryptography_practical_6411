#include <stdio.h>
#include <string.h>

void encrypt(char text[], int key[], int n)
{
    char temp[100];
    int i, j, k = 0, len = strlen(text);

    for(i = 0; i < n; i++)
        for(j = 0; j < len; j += n)
            if(j + key[i] < len)
                temp[k++] = text[j + key[i]];

    temp[k] = '\0';
    strcpy(text, temp);
}

void decrypt(char text[], int key[], int n)
{
    char temp[100];
    int i, j, k = 0, len = strlen(text);

    for(i = 0; i < n; i++)
        for(j = 0; j < len; j += n)
            if(j + key[i] < len)
                temp[j + key[i]] = text[k++];

    temp[len] = '\0';
    strcpy(text, temp);
}

int main()
{
    char text[100];
    int key[10], n, i;

    printf("Enter message: ");
    scanf("%s", text);

    printf("Enter number of columns: ");
    scanf("%d", &n);

    printf("Enter column order: ");
    for(i = 0; i < n; i++)
        scanf("%d", &key[i]);

    /* First transposition */
    encrypt(text, key, n);

    /* Second transposition */
    encrypt(text, key, n);

    printf("Encrypted: %s\n", text);

    /* Reverse second transposition */
    decrypt(text, key, n);

    /* Reverse first transposition */
    decrypt(text, key, n);

    printf("Decrypted: %s\n", text);

    return 0;
}

Enter message: HELLOWORLD
Enter number of columns: 5
Enter column order: 2 0 4 1 3

Encrypted: LROEHLWLOD
Decrypted: HELLOWORLD
