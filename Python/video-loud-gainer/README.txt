# 使用说明

1. 将压缩包解压到一个文件夹下，解压完后，左键选中解压出来的 video-loud-gainer 文件夹；
2. 按住 Shift，点击鼠标右键，选择在此处打开 Powershell 窗口（Win11需要先点显示更多选项再点打开 Powershell ）；
3. 将你要提升音量的视频文件拷贝至 source 文件夹中；
4. 在第二步弹出来的窗口输入 python3 gainer.py 你想要提高的音量分贝数（如 python3 gainer.py 15代表统一提升15分贝）；
5. 等待程序执行，音量提升后的视频文件将会生成在 target 文件夹下，文件名以 *_gained.mp4 为结尾。