#!/usr/bin/env python
# coding=utf-8

"""
    File Name : 13-urllib.py
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/07/17 11:10:47
"""

# urllib的使用

import urllib.request

# 向一个指定的URL发送请求 获取响应
response = urllib.request.urlopen("http://www.haizeix.com")

# 获取响应内容
content = response.read().decode('utf-8')
fo = open('./haizei.html', 'w', encoding='utf-8')
print(content, file=fo)
fo.close()

# 响应头信息
print(response.headers)

# 状态码
print(response.status)
