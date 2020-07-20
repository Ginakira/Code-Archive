#!/usr/bin/env python
# coding=utf-8

#!/usr/bin/env python
# coding=utf-8

"""
    @file   baidu_tieba.py
    @author Ginakira
    @mail   ginakira@outlook.com
    @github https://github.com/Ginakira
    @date   2020/07/20 10:27:47
    @desc   爬取百度贴吧
"""

import requests
import re


# 贴吧爬虫
class TiebaSpider:
    def __init__(self):
        self.kw = input('Keyword：')
        self.base_url = 'https://tieba.baidu.com/f'
        self.page_num = 1
        self.header = {'User-agent': 'Mozilla/5.0 (Macintosh;\
            Intel Mac OS X 10_15_6) AppleWebKit/537.36 \
            (KHTML, like \Gecko) Chrome/84.0.4147.89 \
            Safari/537.36 Edg/84.0.522.40'}
        self.title = ''

    def parse_text(self, url, params=None):
        # 发送请求 获取相应内容
        req = requests.get(url, header=self.header, params=params)
        return req.text

    def parse_byte(self, url, params=None):
        req = requests.get(url, header=self.header, params=params)
        return req.content

    def page(self, content):
        # 解析每一页
        print("The spider is crawling the {}-th page".format(self.page_num))
        self.page_num += 1
        pattern = re.compile()

    def save_title(self):
        # 保存标题
        with open('./texts/tieba_{}.txt'.format(self.kw), 'a', encoding='utf-8') as file:
            file.write(self.title)
            file.write('\n')

    def save_img(self, url):
        content = self.base_url(url=url)
        image_path = './images/{}'.format(self.title)
        with open(image_path, 'wb') as file:
            file.write(content)

    def start(self):
        # 启动爬虫
        print('Spider started.')
        content = self.parse_text(url=self.base_url, params={
            'kw': self.kw, 'ie': 'utf-8', 'fr': 'search'})
        self.page(content)


if __name == '__main__':
    spider = TiebaSpider()
    spider.start()
