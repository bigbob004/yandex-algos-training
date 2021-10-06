def search_first_and_second_positive_max(lst):
    max1 = max2 = lst[1]
    for i in range(1, len(lst)):
        if lst[i] > max1:
            max2 = max1
            max1 = lst[i]
        if lst[i] > max2:
            max2 = lst[i]
    return (max2, max1)

def search_first_and_second_negative_max(lst):
    max1 = max2 = lst[1]
    for i in range(1, len(lst)):
        if lst[i] > max1:
            max2 = max1
            max1 = lst[i]
    return (max2, max1)


lst = list(map(int, input().split()))
print(*search_first_and_second_max(lst))
