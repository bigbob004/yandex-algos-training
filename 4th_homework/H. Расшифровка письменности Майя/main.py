#from itertools import permutations

"""
def count_of_occurrences(s, subs):
    counter = 0
    for i in range(len(s) - len(subs) + 1):
        flag = True
        for j in range(len(subs)):
            if s[i + j] != subs[j]:
                flag = False
                break
        if flag:
            counter += 1
    return counter


def my_permutations(subs):
    lst_of_permutants = {''.join(item) for item in permutations(subs)}
    return lst_of_permutants
"""


def check_window(begin, end, dict_subs, sequence_of_symbols, buf_dict):
    for i in range(begin, end):
        if sequence_of_symbols[i] in dict_subs:
            if sequence_of_symbols[i] not in buf_dict:
                buf_dict[sequence_of_symbols[i]] = 0
            if buf_dict[sequence_of_symbols[i]] < dict_subs[sequence_of_symbols[i]]:
                buf_dict[sequence_of_symbols[i]] += 1
            else:
                return (False, i)
        else:
            return (False, i)
    return (True, end)


def count_of_occurrences(dict, len_g, sequence_of_symbols):
    ans = 0
    begin = 0
    end = len_g
    buf_dict = {}
    while True:
        res, ending_symbol = check_window(begin, end, dict, sequence_of_symbols, buf_dict)
        if res:
            ans += 1
            buf_dict[sequence_of_symbols[len_g - 1]] -= 1
            begin = ending_symbol
            end = ending_symbol + 1
            if begin == len(sequence_of_symbols):
                break
        else:
            buf_dict = {}
            begin = ending_symbol + 1
            end = begin + len_g
            if begin >= len(sequence_of_symbols) - len_g + 1:
                break
    return ans


def count_of_symbol_occurrences(subs):
    dict = {}
    for symbol in subs:
        if symbol not in dict:
            dict[symbol] = 0
        dict[symbol] += 1
    return dict


len_g, len_S = map(int, input().split())
g = input()
S = input()
symbol_to_count = count_of_symbol_occurrences(g)
print(count_of_occurrences(symbol_to_count, len_g, S))
