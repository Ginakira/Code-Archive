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
        self.kw = input('Keyword： ')
        self.base_url = 'https://tieba.baidu.com/f'
        self.page_num = 1
        self.header = {'User-Agent': 'Mozilla/5.0 (Macintosh;\
            Intel Mac OS X 10_15_6) AppleWebKit/537.36 \
            (KHTML, like \Gecko) Chrome/84.0.4147.89 \
            Safari/537.36 Edg/84.0.522.40'}
        self.title = ''

    def parse_text(self, url, params=None):
        # 发送请求 获取相应内容
        req = requests.get(url, headers=self.header, params=params)
        return req.text

    def parse_byte(self, url, params=None):
        req = requests.get(url, headers=self.header, params=params)
        return req.content

    def page(self, content):
        # 解析每一页
        print("\rThe spider is crawling the {}-th page".format(self.page_num), end='')
        self.page_num += 1
        pattern = re.compile(
            r'<a rel="noreferrer" href="(/p/\d+?)" title=".+?" target="_blank" class="j_th_tit .*?">(.+?)</a>')
        url_title = pattern.findall(content)
        for url, title in url_title:
            self.title = title
            self.detail('https://tieba.baidu.com' + url)
            # 保存标题
            self.save_title()
            # 判断下一页
        next_url = re.findall(r'<a href="(.*?)".*?>下一页&gt;</a>', content)
        if next_url:
            next_url = 'https:' + next_url[0]
            content = self.parse_text(url=next_url)
            self.page(content)
        else:
            print('Spdier crawl over. Total page: {}'.format(self.page_num))

    def detail(self, url):
        # 每一个帖子的详情
        content = self.parse_text(url=url)
        urls = re.findall(r'<img class="BDE_Image".*?src="(.*?)".*?', content)
        for url in urls:
            self.save_img(url=url)

    def save_title(self):
        # 保存标题
        with open('./texts/tieba_{}.txt'.format(self.kw), 'a', encoding='utf-8') as file:
            file.write('p{}_{}'.format(self.page_num, self.title))
            file.write('\n')

    def save_img(self, url):
        content = self.parse_byte(url=url)
        image_path = './images/{}_{}.jpg'.format(self.page_num, self.title)
        try:
            with open(image_path, 'wb') as file:
                file.write(content)
        except:
            print('Image write failed.')

    def start(self):
        # 启动爬虫
        print('Spider started.')
        content = self.parse_text(url=self.base_url, params={
            'kw': self.kw, 'ie': 'utf-8', 'fr': 'search'})
        self.page(content)


if __name__ == '__main__':
    spider = TiebaSpider()
    spider.start()
