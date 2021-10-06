key_to_word = {}

N = int(input())
for i in range(N):
    key, word = input().split()
    key_to_word[key] = word
    key_to_word[word] = key
argument = input()
print(key_to_word[argument])
