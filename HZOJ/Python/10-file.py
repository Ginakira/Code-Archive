#!/usr/bin/env python
# coding=utf-8

# 文件的写入
file = open('./input', 'w', encoding='utf-8')
file.write("Hello world\n")
file.writelines(["This is the ", " second line."])
file.close()
