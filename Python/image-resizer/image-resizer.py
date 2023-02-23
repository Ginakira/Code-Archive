# Author: Ginakira

import os.path

from PIL import Image


def main():
    print("***** 请将要转换的图片放置在 img 文件夹下，转换后的图片将生成到 out 文件夹下 *****")
    target_size_str = input("请输入目标图片宽高，如 900 600（如果宽高相等，只输入一个数字即可，直接回车为 512 512）：")
    target_sizes = target_size_str.split()
    target_sizes_len = len(target_sizes)
    input_dir = "img"
    output_dir = "out"

    # Parse target size
    target_w: int = 512
    target_h: int = 512
    if target_sizes_len >= 1:
        target_w = target_h = int(target_sizes[0])
    if target_sizes_len >= 2:
        target_h = int(target_sizes[1])

    # Check directories
    print(f"目标图片尺寸：{target_w} * {target_h}")
    if not os.path.exists(input_dir):
        os.mkdir(input_dir)
    if not os.path.exists(output_dir):
        os.mkdir(output_dir)

    input_files = os.listdir(input_dir)
    input_files_cnt = len(input_files)
    print(f"待转换文件 {input_files_cnt} 个：")
    for i, filename in enumerate(input_files):
        print(f"转换中({i + 1}/{input_files_cnt})...  {filename}")
        img = Image.open(os.path.join(input_dir, filename))
        img_resized = img.resize((target_w, target_h))
        img_resized.save(os.path.join(output_dir, filename))
    input("转换完成！按任意键退出")


if __name__ == '__main__':
    main()
