def encrypt(text, shift):
    result = ""

    for ch in text:
        if ch.isupper():
            result += chr((ord(ch) - ord('A') + shift) % 26 + ord('A'))
        elif ch.islower():
            result += chr((ord(ch) - ord('a') + shift) % 26 + ord('a'))
        else:
            result += ch

    return result


def decrypt(text, shift):
    result = ""

    for ch in text:
        if ch.isupper():
            result += chr((ord(ch) - ord('A') - shift) % 26 + ord('A'))
        elif ch.islower():
            result += chr((ord(ch) - ord('a') - shift) % 26 + ord('a'))
        else:
            result += ch

    return result


text = input()
shift = int(input())

shift = shift % 26

encrypted = encrypt(text, shift)
print("Encrypted message:", encrypted)

decrypted = decrypt(encrypted, shift)
print("Decrypted message:", decrypted)

Hello World
3

Encrypted message: Khoor Zruog
Decrypted message: Hello World
