#Дан список. Определите, является ли он монотонно возрастающим
#(то есть верно ли, что каждый элемент этого списка больше предыдущего).
#Выведите YES, если массив монотонно возрастает и NO в противном случае.

lst = list(map(int, input().split()))

is_increasing = True
for i in range(0, len(lst) - 1):
    if lst[i] >= lst[i + 1]:
       is_increasing = False
       break
if is_increasing:
    print("YES")
else:
    print("NO")
