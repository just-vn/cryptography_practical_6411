key = input().upper()
text = input().upper().replace("J", "I")

matrix = []

for ch in key + "ABCDEFGHIKLMNOPQRSTUVWXYZ":
    if ch.isalpha() and ch not in matrix:
        matrix.append(ch)

matrix = [matrix[i:i+5] for i in range(0, 25, 5)]

prepared = ""
i = 0

while i < len(text):
    a = text[i]

    if i + 1 < len(text):
        b = text[i + 1]

        if a == b:
            prepared += a + "X"
            i += 1
        else:
            prepared += a + b
            i += 2
    else:
        prepared += a + "X"
        i += 1


def process(text, decrypt=False):
    result = ""

    for i in range(0, len(text), 2):
        a, b = text[i], text[i + 1]

        for r in range(5):
            for c in range(5):
                if matrix[r][c] == a:
                    r1, c1 = r, c
                if matrix[r][c] == b:
                    r2, c2 = r, c

        shift = -1 if decrypt else 1

        if r1 == r2:
            result += matrix[r1][(c1 + shift) % 5]
            result += matrix[r2][(c2 + shift) % 5]
        elif c1 == c2:
            result += matrix[(r1 + shift) % 5][c1]
            result += matrix[(r2 + shift) % 5][c2]
        else:
            result += matrix[r1][c2]
            result += matrix[r2][c1]

    return result


print("Matrix:")
for row in matrix:
    print(*row)

encrypted = process(prepared)
decrypted = process(encrypted, True)

print("Prepared plaintext:", prepared)
print("Encrypted text:", encrypted)
print("Decrypted text:", decrypted)

Enter the key: MONARCHY
Enter the plaintext: INSTRUMENTS

Prepared plaintext: INSTRUMENTSX
Encrypted text: GATLMZCLRQXA
Decrypted text: INSTRUMENTSX
