asc = 0
eq = 1
desc = 2
signs = [False] * 3

a = int(input())
b = int(input())

#Сбор признаков
while b ! = -2e9:
 signs[asc] = signs[asc] or (a < b)
 signs[eq] = signs[eq] or (a == b)
 signs[desc] = signs[desc] or (a > b)


"""
N = int(input())
lst = list(map(int, input().split()))
x = int(input())


answer = lst[0]
for i in range(1, len(lst)):
    if abs(lst[i] - x) < abs(answer - x):
        answer = lst[i]


print(answer)
"""