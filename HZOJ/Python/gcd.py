#!/usr/bin/env python
# coding=utf-8

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


a = int(input("A:"))
b = int(input("B:"))
print(gcd(a, b))
