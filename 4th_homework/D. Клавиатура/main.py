n = int(input())
resourse_keys = list(map(int, input().split()))
k = int(input())
sequence_of_pressed_keys = list(map(int, input().split()))
pressed_keys = [0] * n
for pressed_key in sequence_of_pressed_keys:
    pressed_keys[pressed_key - 1] += 1
for i in range(n):
    if pressed_keys[i] > resourse_keys[i]:
        print("YES")
    else:
        print("NO")
