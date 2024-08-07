import os
from mutagen.mp4 import MP4

def clear_mp4_metadata(directory):
    for root, dirs, files in os.walk(directory):
        for file in files:
            if file.lower().endswith('.mp4'):
                file_path = os.path.join(root, file)
                try:
                    video = MP4(file_path)
                    video.clear()  # 清空所有描述性属性
                    video.save()
                    print(f"Cleared metadata for: {file_path}")
                except Exception as e:
                    print(f"Failed to clear metadata for {file_path}: {e}")

# 调用函数，传入要遍历的文件夹路径
clear_mp4_metadata('.\\')