import requests
from bs4 import BeautifulSoup
import bs4
import time

def getHTMLText(url):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "ERR"

def fillUnivList(ulist, html):
    soup = BeautifulSoup(html, "html.parser")
    for tr in soup.find("tbody").children:
        if isinstance(tr, bs4.element.Tag):
            tds = tr('td')
            ulist.append([tds[0].string, tds[1].string, tds[3].string])

def printUnivList(ulist, num):
    tplt = "{0:^10}\t{1:{3}^10}\t{2:^10}"
    print(tplt.format("排名", "学校名称", "总分", chr(12288)))
    for i in range(num):
        u = ulist[i]
        print(tplt.format(u[0], u[1], u[2], chr(12288)))
    print("成功获取{}条学校信息".format(i+1))

def main():
    uinfo = []
    url = "http://www.zuihaodaxue.com/zuihaodaxuepaiming" + input("请输入查询年份：") + ".html"
    num = int(input("请输入查询条目数："))
    start = time.time()
    html = getHTMLText(url)
    fillUnivList(uinfo, html)
    last = time.time()
    printUnivList(uinfo, num)
    end = time.time()
    print("获取信息用时{0:.2f}秒，程序总用时{1:.2f}秒".format(last - start, end - start))

main()