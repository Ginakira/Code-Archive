import requests
from bs4 import BeautifulSoup
import re
import traceback

def getHTMLText(url, code = 'utf-8'):
    try:
        r = requests.get(url)
        r.raise_for_status()
        r.encoding = code
        return r.text
    except:
        return ""

def getStockList(lst, stock_URL):
    html = getHTMLText(stock_URL, "GB2312")
    soup = BeautifulSoup(html, 'html.parser')
    a = soup.find_all('a')
    for i in a:
        try:
            href = i.attrs['href']
            lst.append(re.findall(r'[s][zh]\d{6}', href)[0])
        except:
            continue

def getStockInfo(lst, stock_URL, fpath):
    count = 0
    failcount = 0
    for stock in lst:
        url = stock_URL + stock + '.html'
        html = getHTMLText(url)
        try:
            if html == '':
                continue
            infoDict = {}
            soup = BeautifulSoup(html, 'html.parser')
            stockInfo = soup.find('div', attrs={'class':'stock-bets'})
            #获取股票名字
            name = stockInfo.find_all(attrs={'class':'bets-name'})[0]
            infoDict.update({'股票名称': name.text.split()[0]})
            #获取其他信息
            keyList = stockInfo.find_all('dt')
            valList = stockInfo.find_all('dd')
            for i in range(len(keyList)):
                key = keyList[i].text
                val = valList[i].text
                infoDict[key] = val
            #写入文件
            with open(fpath, 'a', encoding='utf-8') as f:
                f.write(str(infoDict) + '\n')
                count += 1
                print("\r未获取到信息：{}/{}�?    ".format(failcount, len(lst)) + "当前爬取进度：{:.2f}%  ".format(count*100/len(lst)) + '�?'*int((count*100/len(lst))), end='')
        except:
            count += 1
            failcount += 1
            print("\r未获取到信息：{}/{}�?    ".format(failcount, len(lst)) + "当前爬取进度：{:.2f}%  ".format(count*100/len(lst)) + '�?'*int((count*100/len(lst))), end='')
            continue

def main():
    stock_list_url = 'http://quote.eastmoney.com/stocklist.html'
    stock_info_url = 'https://gupiao.baidu.com/stock/'
    output_file = 'D:/OwnBaiduStockInfo.txt'
    stock_list = []
    getStockList(stock_list, stock_list_url)
    getStockInfo(stock_list, stock_info_url, output_file)

main()