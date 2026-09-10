text = input()
key = int(input())

rail = [[""] * len(text) for _ in range(key)]

row = 0
direction = 1

for i in range(len(text)):
    rail[row][i] = text[i]

    if row == key - 1:
        direction = -1
    elif row == 0:
        direction = 1

    row += direction

encrypted = ""

for i in range(key):
    for j in range(len(text)):
        if rail[i][j]:
            encrypted += rail[i][j]

print("Encrypted:", encrypted)

row = 0
direction = 1

for i in range(len(text)):
    rail[row][i] = "*"

    if row == key - 1:
        direction = -1
    elif row == 0:
        direction = 1

    row += direction

k = 0

for i in range(key):
    for j in range(len(text)):
        if rail[i][j] == "*":
            rail[i][j] = encrypted[k]
            k += 1

decrypted = ""
row = 0
direction = 1

for i in range(len(text)):
    decrypted += rail[row][i]

    if row == key - 1:
        direction = -1
    elif row == 0:
        direction = 1

    row += direction

print("Decrypted:", decrypted)

Enter the text: HELLOWORLD
Enter number of rails: 3

Encrypted: HOLELWRDLO
Decrypted: HELLOWORLD
