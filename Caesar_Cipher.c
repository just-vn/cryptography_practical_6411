#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char text[], int shift)
{
    int i;
    for (i = 0; text[i] != '\0'; i++)
    {
        if (isupper(text[i]))
            text[i] = (text[i] - 'A' + shift) % 26 + 'A';
        else if (islower(text[i]))
            text[i] = (text[i] - 'a' + shift) % 26 + 'a';
    }
}

void decrypt(char text[], int shift)
{
    int i;
    for (i = 0; text[i] != '\0'; i++)
    {
        if (isupper(text[i]))
            text[i] = (text[i] - 'A' - shift + 26) % 26 + 'A';
        else if (islower(text[i]))
            text[i] = (text[i] - 'a' - shift + 26) % 26 + 'a';
    }
}

int main()
{
    char text[100];
    int shift;

    printf("Enter the message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key (shift): ");
    scanf("%d", &shift);

    shift = shift % 26;

    encrypt(text, shift);
    printf("\nEncrypted message: %s", text);

    decrypt(text, shift);
    printf("Decrypted message: %s", text);

    return 0;
}

Enter the message: Hello World
Enter the key (shift): 3

Encrypted message: Khoor Zruog
Decrypted message: Hello World
