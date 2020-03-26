# Read from the file file.txt and output the tenth line to stdout.
# 先head再tail是错的 比如文件只有9行
# 所以先拿从第十行往后的所有内容，再拿出第一行即可
cat file.txt | tail - n + 10 | head - n 1
