#!/usr/bin/env python
# coding=utf-8

"""
    File Name: 14-requests.py
    Author:    Ginakira
    Mail:      ginakira@outlook.com
    Github:    https://github.com/Ginakira
    Created:   2020/07/19 11:57:46
    Description: 使用Requests发送请求和携带参数
"""

import requests

url = "http://www.baidu.com/"

r = requests.get(url)
r.encoding = 'utf-8'
print(r.text)

print("With params:", url + 's')

# 带参数get请求
r = requests.get(url + 's', params={'wd': 'haizei'})
print(r.url)
r.encoding = 'utf-8'
print(r.text)

# post请求
r = requests.post(url, data={'k': 'v'})
r.encoding = 'utf-8'
print(r.text)
