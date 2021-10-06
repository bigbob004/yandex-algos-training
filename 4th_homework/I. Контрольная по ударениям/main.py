def Add_word_to_dict(word, dict):
    accents = [False] * len(word)
    for i in range(len(word)):
        asci_number = ord(word[i])
        if 65 <= asci_number <= 90:
            lower_word = word.lower()
            if lower_word not in dict:
                dict[lower_word] = accents
            dict[lower_word][i] = True
            break


def Parse_word_from_text(word):
    accents = 0
    count_of_accents = 0
    for i in range(len(word)):
        if count_of_accents > 1:
            break
        asci_number = ord(word[i])
        if 65 <= asci_number <= 90:
            accents = i
            count_of_accents += 1
    if count_of_accents == 0 or count_of_accents > 1:
        accents = -1
    return (accents, word.lower())


def Is_there_mistake(word, Petya_accent, dict):
    if Petya_accent == -1:
        return 1
    if word not in dict:
        return 0
    if dict[word][Petya_accent]:
        return 0
    else:
        return 1


count_of_mistakes = 0
dict_accents = {}
N = int(input())
for _ in range(N):
    word = input()
    Add_word_to_dict(word, dict_accents)
text = input()
for word in text.split():
    Petya_accent, word = Parse_word_from_text(word)
    count_of_mistakes += Is_there_mistake(word, Petya_accent, dict_accents)
print(count_of_mistakes)
