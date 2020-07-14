#!/usr/bin/env python
# codeing=utf-8

MAX_N = 2000000
prime = [0 for i in range(MAX_N + 5)]


for i in range(2, MAX_N + 1):
    if prime[i] == 0:
        prime[0] += 1
        prime[prime[0]] = i
    for j in range(1, prime[0] + 1):
        if prime[j] * i > MAX_N:
            break
        prime[prime[j] * i] = 1
        if i % prime[j] == 0:
            break


print("Prime count: ", prime[0])
print(prime[prime[0]])
