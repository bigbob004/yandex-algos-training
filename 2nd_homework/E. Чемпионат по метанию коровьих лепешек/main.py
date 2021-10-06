#1. Собрать позиции победителей в один список
#2. Собрать позиции "пятёрок" в один список
#3. Найти ту самую "пятёрку"
#4. Найти кол-во эл-ов, которые больше нашей "пятёрки"


N = int(input())


def search_pos_of_winner(lst):
    winner_pos = 0
    for i in range(1, N):
        if lst[i] > lst[winner_pos]:
            winner_pos = i
    return winner_pos


def is_last_digit_five(number):
    return number % 10 == 5


def is_neighboring_number_less(neighbor, number):
    if neighbor < number:
        return True
    return False


def pos_of_Vasya(lst, winner_pos):
    answer = -1
    for i in range(0, N - 1):
        if is_last_digit_five(lst[i]) and is_neighboring_number_less(lst[i + 1], lst[i]):
            if winner_pos < i and (answer == -1 or lst[i] > lst[answer]):
                answer = i
    return answer


answer = 0
lst = list(map(int, input().split()))
win_pos = search_pos_of_winner(lst)
Vasya = pos_of_Vasya(lst, win_pos)
if Vasya != -1:
    for item in lst:
        if item > lst[Vasya]:
            answer += 1
    answer += 1
print(answer)
