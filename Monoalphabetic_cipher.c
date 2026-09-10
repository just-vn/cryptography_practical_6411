key = input().upper()
text = input()

encrypted = ""

for ch in text:
    if ch.isupper():
        encrypted += key[ord(ch) - ord('A')]
    elif ch.islower():
        encrypted += key[ord(ch) - ord('a')].lower()
    else:
        encrypted += ch

print("Encrypted text:", encrypted)

decrypted = ""

for ch in encrypted:
    if ch.isupper():
        decrypted += chr(key.index(ch) + ord('A'))
    elif ch.islower():
        decrypted += chr(key.lower().index(ch) + ord('a'))
    else:
        decrypted += ch

print("Decrypted text:", decrypted)

Enter the plaintext: HELLO WORLD

Encrypted text: ITSSG VGKSR
Decrypted text: HELLO WORLD
