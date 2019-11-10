if __name__ == '__main__':
    filename = input('filename: \n')
    fp = open(filename,"w")
    ch = input("ÊäÈë×Ö·û´®:\n")
    while ch != '#':
	fp.write('\n')
        fp.write(ch)
        ch = input('')
    fp.close()
