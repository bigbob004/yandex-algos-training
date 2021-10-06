def analys_of_sequence(lst, N):
    answer = []
    for start in range(N):
        i = start
        j = N - 1
        while i <= j and lst[i] == lst[j]:
            i += 1
            j -= 1
        if i > j:
            for q in range(start - 1, -1, -1):
                answer.append(lst[q])
            return answer


N = int(input())
lst = list(map(int, input().split()))
ans = analys_of_sequence(lst, N)
print(len(ans))
print(*ans)
