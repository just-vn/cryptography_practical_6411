def encrypt(text, key, n):
    temp = ""

    for i in range(n):
        for j in range(0, len(text), n):
            if j + key[i] < len(text):
                temp += text[j + key[i]]

    return temp


def decrypt(text, key, n):
    temp = [""] * len(text)
    k = 0

    for i in range(n):
        for j in range(0, len(text), n):
            if j + key[i] < len(text):
                temp[j + key[i]] = text[k]
                k += 1

    return "".join(temp)


text = input()
n = int(input())

key = list(map(int, input().split()))

text = encrypt(text, key, n)
text = encrypt(text, key, n)

print("Encrypted:", text)

text = decrypt(text, key, n)
text = decrypt(text, key, n)

print("Decrypted:", text)

Enter message: HELLOWORLD
Enter number of columns: 5
Enter column order: 2 0 4 1 3

Encrypted: LROEHLWLOD
Decrypted: HELLOWORLD
