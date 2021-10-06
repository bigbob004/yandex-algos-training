f = open('input.txt', 'r')
list_of_words = []
words_to_count = {}
for line in f:
    for word in line.split():
        list_of_words.append(word)
        if word not in words_to_count:
            words_to_count[word] = 0
        words_to_count[word] += 1
answer = [0] * len(list_of_words)
for i in range(len(list_of_words) - 1, -1, -1):
    answer[i] = words_to_count[list_of_words[i]] - 1
    words_to_count[list_of_words[i]] -= 1
print(*answer)
f.close()
