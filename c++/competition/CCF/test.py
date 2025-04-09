'''
Author: cgp 2986779260@qq.com
Date: 2024-09-10 09:33:34
LastEditors: cgp 2986779260@qq.com
LastEditTime: 2024-09-10 09:34:51
FilePath: \CCF\test.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import cv2

# 打开默认摄像头（索引通常是0）
cap = cv2.VideoCapture(0)

# 检查摄像头是否成功打开
if not cap.isOpened():
    raise IOError("Cannot open webcam")

while True:
    # 读取一帧图像
    ret, frame = cap.read()
    
    if not ret:
        print("Can't receive frame (stream end?). Exiting ...")
        break
    
    # 显示图像
    cv2.imshow('Webcam', frame)
    
    # 按 'q' 键退出循环
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 释放摄像头资源并关闭窗口
cap.release()
cv2.destroyAllWindows()