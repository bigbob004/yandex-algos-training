lst = list(map(int, input().split()))

counter = 0
for i in range(1, len(lst) - 1):
    if lst[i - 1] < lst[i] and lst[i] > lst[i + 1]:
        counter += 1

print(counter)
