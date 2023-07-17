# Author: Ginakira

import os.path
import re

punctuation_map = {
    '，': '\n', # ENTER
    '。': '.',
    '！': '!',
    '？': '?',
    '：': ':',
    '；': ';',
    '“': '"',
    '”': '"',
    '‘': "'",
    '’': "'",
    '（': '(',
    '）': ')',
    '【': '[',
    '】': ']',
    '《': '<',
    '》': '>',
    '—': '-',
    '·': '·',
    '、': '、', # DO NOT change
    '…': '...',
    '￥': '$',
    '％': '%',
    '＃': '#',
    '＆': '&',
    '＊': '*',
    '＠': '@',
    '＋': '+',
    '－': '-',
    '÷': '/',
    '×': '*',
    '～': '~',
    '｜': '|',
    '＝': '=',
    '＜': '<',
    '＞': '>',
    '＾': '^',
    '＄': '$',
    '＂': '"',
    '＇': "'",
    '［': '[',
    '］': ']',
    '｛': '{',
    '｝': '}',
    '—': '-',
    '－': '-',
    '＿': '_',
    '＼': '\\',
    '｀': '`',
    '｟': '⦅',
    '｠': '⦆',
    '｢': '“',
    '｣': '”',
    '〈': '<',
    '〉': '>',
    '「': '“',
    '」': '”',
    '『': '‘',
    '』': '’',
    '【': '[',
    '】': ']',
    '〔': '[',
    '〕': ']',
    '—': '-',
    '…': '...',
    '‖': '||',
    '︱': '|',
    '︳': '|',
    '︴': '|',
    '﹏': '_',
    '︶': '/',
    '︿': '^',
    '﹀': '^',
    '︹': '(',
    '︺': ')',
    '︼': '[',
    '︽': ']',
    '︻': '{',
    '︾': '}',
    '︷': '/',
    '︸': '\\',
    '︱': '|',
    '︳': '|',
    '︴': '|',
    '﹁': '┌',
    '﹂': '┐',
    '﹃': '└',
    '﹄': '┘',
    '︙': '...',
    '﹔': ';',
    '﹕': ':',
    '﹖': '?',
    '﹗': '!',
    '（': '(',
    '）': ')',
    '﹙': '(',
    '﹚': ')',
    '〔': '[',
    '〕': ']',
    '【': '[',
    '】': ']',
    '﹛': '{',
    '﹜': '}',
    '“': '"',
    '”': '"',
    '‘': "'",
    '’': "'",
    '《': '<',
    '》': '>',
    '‹': '<',
    '›': '>',
    '〖': '[',
    '〗': ']',
    '』': '’',
    '『': '‘',
    '｛': '{',
    '｝': '}',
    '﹫': '@',
    '＠': '@',
    '﹩': '$',
    '＄': '$',
    '﹪': '%',
    '％': '%',
    '﹡': '*',
    '＊': '*',
    '﹦': '=',
    '＝': '=',
    '﹠': '&',
    '＆': '&',
    '﹟': '#',
    '＃': '#',
    '﹡': '*',
    '＊': '*',
    '﹩': '$',
    '＄': '$',
    '﹪': '%',
    '％': '%',
    '﹦': '=',
    '＝': '=',
    '﹠': '&',
    '＆': '&',
    '﹟': '#',
    '＃': '#',
    '﹑': ',',
    '︰': ':',
    '﹔': ';',
    '﹕': ':',
    '﹖': '?',
    '﹗': '!',
    '﹍': '-',
    '﹎': '-',
    '﹏': '_',
    '﹐': ',',
    '﹑': ',',
    '﹒': '.',
    '·': '·',
    '﹔': ';',
    '﹕': ':',
    '﹖': '?',
    '﹗': '!',
    '﹘': '-',
    '﹟': '#',
    '﹠': '&',
    '﹡': '*',
    '﹢': '+',
    '﹣': '-',
    '﹤': '<',
    '﹥': '>',
    '﹦': '=',
    '﹨': '\\',
    '﹩': '$',
    '﹪': '%',
    '﹫': '@',
    '～': '~',
    '｜': '|',
}

input_file_path = 'in'
output_file_path = 'out'

def remove_parentheses(text: str):
    pattern = r'\([^()]*\)'
    return re.sub(pattern, '', text)

def remove_blank_line(text: str):
    lines = text.splitlines()
    non_empty_lines = [line.strip() for line in lines if line.strip()]
    return '\n'.join(non_empty_lines)


def convert_file(filename: str):
    with open(f"{input_file_path}/{filename}", "r", encoding="utf-8") as file:
        content = file.read()

    translated_content = content.translate(str.maketrans(punctuation_map))

    # Remove parentheses
    translated_content = remove_parentheses(translated_content)

    # Remove blank line
    translated_content = remove_blank_line(translated_content)

    with open(f"{output_file_path}/{filename}", 'w', encoding='utf-8') as output_file:
        output_file.write(translated_content)

def main():
    print("========== 将要转换的文档放在 in 文件夹下 ==========")
    print("========== 转换后的文档将被放在 out 文件夹下 ==========")
    if not os.path.exists(input_file_path):
        os.mkdir(input_file_path)
    if not os.path.exists(output_file_path):
        os.mkdir(output_file_path)

    input_files = os.listdir(input_file_path)
    input_files_cnt = len(input_files)
    print(f"待转换文件 {input_files_cnt} 个：")
    for i, filename in enumerate(input_files):
        print(f"转换中({i + 1}/{input_files_cnt})...  {filename}")
        convert_file(filename)
    input("转换完成！按任意键退出")

if __name__ == "__main__":
    main()