import os
import sys
import platform


def main():
    if len(sys.argv) != 2:
        print("Usage: {} <gain-dB>".format(sys.argv[0]))
        sys.exit(1)
    gain_db = int(sys.argv[1])

    # Store all *.mp4 files path under source directory
    source_dir = os.path.join(os.path.dirname(__file__), "source")
    output_dir = os.path.join(os.path.dirname(__file__), "target")

    if platform.system().lower == "windows":
        ffmpeg_path = os.path.join(os.path.dirname(__file__), "bin/ffmpeg.exe")
    else:
        ffmpeg_path = "ffmpeg"
    source_files = [f for f in os.listdir(source_dir) if f.endswith(".mp4")]
    print(f"Source files count: {len(source_files)}")

    # Execute ffmpeg command to change gain of all *.mp4 files
    # Command: ffmpeg -i {filename} -af volume=15dB -vcodec copy {output_filename}
    for source_file in source_files:
        output_file = os.path.basename(source_file).replace(
            ".mp4", "_gained.mp4")
        cmd = f"{ffmpeg_path} -i {source_dir}/{source_file} -af volume={gain_db}dB -vcodec copy {output_dir}/{output_file}"
        print(cmd)
        os.system(cmd)


if __name__ == "__main__":
    main()