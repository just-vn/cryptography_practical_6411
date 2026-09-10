def mod_inverse(a):
    for i in range(1, 26):
        if (a * i) % 26 == 1:
            return i
    return -1


text = input()

key = []
for i in range(2):
    key.append(list(map(int, input().split())))

det = key[0][0] * key[1][1] - key[0][1] * key[1][0]
det = det % 26

inv_det = mod_inverse(det)

if inv_det == -1:
    print("Invalid key matrix! Decryption is not possible.")
else:
    clean = ""

    for ch in text:
        if ch.isalpha():
            clean += ch.upper()

    if len(clean) % 2 != 0:
        clean += "X"

    encrypted = ""

    for i in range(0, len(clean), 2):
        x = ord(clean[i]) - ord('A')
        y = ord(clean[i + 1]) - ord('A')

        a = (key[0][0] * x + key[0][1] * y) % 26
        b = (key[1][0] * x + key[1][1] * y) % 26

        encrypted += chr(a + ord('A'))
        encrypted += chr(b + ord('A'))

    print("Encrypted text:", encrypted)

    inv_key = [
        [(key[1][1] * inv_det) % 26, (-key[0][1] * inv_det) % 26],
        [(-key[1][0] * inv_det) % 26, (key[0][0] * inv_det) % 26]
    ]

    decrypted = ""

    for i in range(0, len(encrypted), 2):
        x = ord(encrypted[i]) - ord('A')
        y = ord(encrypted[i + 1]) - ord('A')

        a = (inv_key[0][0] * x + inv_key[0][1] * y) % 26
        b = (inv_key[1][0] * x + inv_key[1][1] * y) % 26

        decrypted += chr(a + ord('A'))
        decrypted += chr(b + ord('A'))

    print("Decrypted text:", decrypted)
    
Enter the plaintext: HELP
Enter the 2x2 key matrix:
3 3
2 5

Encrypted text: HIAT
Decrypted text: HELP

