#!/usr/bin/env python
# coding=utf-8

fo = open("./input", "r+")
print("Filename: ", fo.name)

string = "\nwww.haizeix.com"

fo.seek(0, 2)  # 表示./input的结尾
line = fo.write(string)

fo.seek(0)
for index in range(3):
    line = next(fo)
    print("File lineno {} : {}\n".format(index, line))

fo.close()
