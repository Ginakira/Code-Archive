if __name__ == '__main__':
    import string
    fp = open('text1.txt','r')
    a = fp.read()
    fp.close()
 
    fp = open('text2.txt','r')
    b = fp.read()
    fp.close()
 
    fp = open('text3.txt','w')
    l = list(a + b)
    l.sort()
    s = ''
    s = s.join(l)
    fp.write(s)
    fp.close()
    fp = open('text3.txt','r')
    print(fp.read())
    fp.close
