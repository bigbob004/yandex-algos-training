def My_Sort(value):
    return (-words_to_count[value], value)

f = open('input.txt', 'r')
words_to_count = {}
for line in f:
    for word in line.split():
        if word not in words_to_count:
            words_to_count[word] = 0
        words_to_count[word] += 1
sorted_list_of_keys = sorted(words_to_count.keys(), key=My_Sort)
print(sorted_list_of_keys[0])
f.close()
