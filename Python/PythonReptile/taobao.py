import requests
import re

def getHTMLText(url, usr_headers):
    try:
        r = requests.get(url, timeout = 30, headers = usr_headers)
        r.raise_for_status()
        r.encoding = r.apparent_encoding
        return r.text
    except:
        return "ERRO"

def parsePage(lst, html):
    try:
        plt = re.findall(r'\"view_price\"\:\"[\d\.]\"', html)
        tlt = re.findall(r'\"raw_title\"\:\".*?\"', html)
        for i in range(len(plt)):
            price = eval(plt[i].split(':')[1])
            title = eval(tlt[i].split(':')[1])
            lst.append([title, price])
    except:
        print('')

def printList(lst):
    tpl = "{:4}\t{:8}\t{:16}"
    print(tpl.format("序号", "价格", "名称"))
    count = 0
    for g in lst:
        count += 1
        print(tpl.format(count, g[1], g[0]))

def main():
    usr_headers = {
        "Cookie":'cna=gfqsE0HqPHQCAQG8rGCgB427; sca=328a67f3; tbsa=9a07d12d6388f1a148ec58d5_1549863987_20; atpsida=31333ff7d902c41a6a085574_1549863987_20; atpsidas=6e08e2652f2ad02aff9e10d8_1549863987_20; cad=OYyYLJjYn7J2MqsGPbJs0LbkPbaXyKdY+b/EyxS/ALE=0001; cap=61fc; cnaui=2678437150; aui=2678437150',
        "User-Agent":'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/72.0.3626.96 Safari/537.36'
    }
    keyword = input("请输入要搜索的商品内容：")
    depth = int(input("请输入搜索深度："))
    start_url = "https://s.taobao.com/search?q=" + keyword
    infoList = []
    for i in range(depth):
        try:
            url = start_url + "&s=" + str(i*44)
            html = getHTMLText(url, usr_headers)
            parsePage(infoList, html)
        except:
            continue
    printList(infoList)

input()
main()