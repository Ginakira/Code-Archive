if __name__ == '__main__':
    filename = input('filename: \n')
    fp = open(filename,"w")
    ch = input("输入字符串:\n")
    while ch != '#':
        fp.write(ch)
        ch = input('')
    fp.close()
