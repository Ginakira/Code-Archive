#!/usr/bin/env python
# coding=utf-8

import math


# def circle(r):
#     result = math.pi * r * r
#     return result


r = float(input("Radius of circle:"))
# print("Area of circle: %.2f" % circle(r))
result = lambda r: math.pi * r * r
print("Area of circle: %.2f" % result(r))
