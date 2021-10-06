#решение с использование словаря
""""
N = int(input())
wdth_to_hght = {}
for i in range(N):
    width, height = map(int, input().split())
    if width not in wdth_to_hght:
        wdth_to_hght[width] = height
    elif wdth_to_hght[width] < height:
        wdth_to_hght[width] = height
print(sum(wdth_to_hght.values()))
"""""

#решение без словаря, но не проходит лимит по памяти(((
N = int(input())
lst_of_bricks = []
max_width = 0
for i in range(N):
    brick = list(map(int, input().split()))
    if brick[0] > max_width:
        max_width = brick[0]
    lst_of_bricks.append(brick)
wdth_to_hght = [0] * max_width
for wdth, hght in lst_of_bricks:
    if wdth_to_hght[wdth - 1] < hght:
        wdth_to_hght[wdth - 1] = hght
print(sum(wdth_to_hght))
