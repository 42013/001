import cv2
import os

order1 = ['U', 'D', 'B', 'L', 'F', 'R']
order2 = ['U', 'D', 'R', 'B', 'L', 'F']
order3 = ['U', 'D', 'F', 'R', 'B', 'L']
order4 = ['U', 'D', 'L', 'F', 'R', 'B']

order5 = ['D', 'U']

orderother1 = ['B', 'F', 'D', 's', 'U', 's']
orderother2 = ['F', 'B', 's', 'D', 's', 'U']
orderother3 = ['R', 'L', 'U', 's', 'D', 's']
orderother4 = ['L', 'R', 's', 'U', 's', 'D']
points1 = [(275, 160), (230, 200), (195, 240), (235, 120), (195, 160), (155, 200), (195, 80), (155, 120), (110, 160)]
points2 = [(215, 90), (255, 130), (295, 170), (175, 130), (215, 170), (255, 210), (130, 170), (175, 210), (215, 250)]
points3 = [(323, 248), (290, 255), (245, 265), (320, 180), (285, 180), (241, 185), (320, 115), (283, 108), (241, 104)]
points4 = [(192, 269), (150, 262), (115, 250), (189, 185), (145, 185), (115, 186), (189, 102), (150, 110), (115, 115)]
points5 = [(323, 248), (290, 255), (245, 265), (320, 180), (285, 180), (241, 185), (320, 115), (283, 108), (241, 104)]
points6 = [(192, 269), (150, 262), (115, 250), (189, 185), (145, 185), (115, 186), (189, 102), (150, 110), (115, 115)]
count0 = 0
def crop_image_by_points(image, points,count):
    # 计算点集的包围框
    x, y = points[count]

    # 在这里你可以添加对 x, y, width, 和 height 的调整，以适应你的需求

    # 使用包围框的坐标来裁剪图像
    roi = image[y:y + 25, x:x + 25]

    return roi


output_folder1 = "D:\\match0\\picture\\mod1\\U"
output_folder2 = "D:\\match0\\picture\\mod1\\D"
output_folder3 = "D:\\match0\\picture\\mod1\\L"
output_folder4 = "D:\\match0\\picture\\mod1\\R"
output_folder5 = "D:\\match0\\picture\\mod1\\B"
output_folder6 = "D:\\match0\\picture\\mod1\\F"
if not os.path.exists(output_folder1):
    os.makedirs(output_folder1)
if not os.path.exists(output_folder2):
    os.makedirs(output_folder2)
if not os.path.exists(output_folder3):
    os.makedirs(output_folder3)
if not os.path.exists(output_folder4):
    os.makedirs(output_folder4)
if not os.path.exists(output_folder5):
    os.makedirs(output_folder5)
if not os.path.exists(output_folder6):
    os.makedirs(output_folder6)



cap1 = cv2.VideoCapture(0, cv2.CAP_DSHOW)
cap1.set(cv2.CAP_PROP_BRIGHTNESS, 100)  # U面
cap1.set(cv2.CAP_PROP_FRAME_WIDTH, 300)
cap1.set(cv2.CAP_PROP_FRAME_HEIGHT, 300)

# cap2 = cv2.VideoCapture(0, cv2.CAP_DSHOW)
# cap2.set(cv2.CAP_PROP_BRIGHTNESS, 0)  # U面
# cap2.set(cv2.CAP_PROP_FRAME_WIDTH, 300)
# cap2.set(cv2.CAP_PROP_FRAME_HEIGHT, 300)
#
# cap3 = cv2.VideoCapture(2, cv2.CAP_DSHOW)
# cap3.set(cv2.CAP_PROP_BRIGHTNESS, 0)  #亮度
#
# cap4 = cv2.VideoCapture(1, cv2.CAP_DSHOW)
# cap4.set(cv2.CAP_PROP_BRIGHTNESS, 0)  #亮度


while True:
    # 读取每一帧
    ret1, frame1 = cap1.read()
    # ret2, frame2 = cap2.read()
    # ret3, frame3 = cap3.read()
    # ret4, frame4 = cap4.read()
    # frame3 = cv2.resize(frame3, (400, 350))
    # frame3r = cv2.rotate(frame3, cv2.ROTATE_90_COUNTERCLOCKWISE)  # 逆时针旋转90度
    # frame4 = cv2.resize(frame4, (400, 350))
    # frame4r = cv2.rotate(frame4, cv2.ROTATE_90_COUNTERCLOCKWISE)  # 逆时针旋转90度
    # 步骤2：准备待识别的图像
    if count0 <= 8:
        for i in range(9):
            # 裁剪图像
            Roi = crop_image_by_points(frame1, points1, i)

            # 构建输出文件路径
            output_path = os.path.join(output_folder1, f"U_{i}.jpg")

            # 保存裁剪后的图像
            cv2.imwrite(output_path, Roi)

            # 显示裁剪后的图像
            cv2.imshow("Cropped Image", Roi)
            count0 += 1
    # if count0 <= 17:
    #     for i in range(9):
    #         # 裁剪图像
    #         Roi = crop_image_by_points(frame2, points2, i)
    #
    #         # 构建输出文件路径
    #         output_path = os.path.join(output_folder2, f"D_{i}.jpg")
    #
    #         # 保存裁剪后的图像
    #         cv2.imwrite(output_path, Roi)
    #
    #         # 显示裁剪后的图像
    #         cv2.imshow("Cropped Image", Roi)
    #         count0 += 1
    # if count0 <= 26:
    #     for i in range(9):
    #         # 裁剪图像
    #         Roi = crop_image_by_points(frame3, points3, i)
    #
    #         # 构建输出文件路径
    #         output_path = os.path.join(output_folder3, f"B_{i}.jpg")
    #
    #         # 保存裁剪后的图像
    #         cv2.imwrite(output_path, Roi)
    #
    #         # 显示裁剪后的图像
    #         cv2.imshow("Cropped Image", Roi)
    # if count0 <= 35:
    #     for i in range(9):
    #         # 裁剪图像
    #         Roi = crop_image_by_points(frame3, points4, i)
    #
    #         # 构建输出文件路径
    #         output_path = os.path.join(output_folder4, f"L_{i}.jpg")
    #
    #         # 保存裁剪后的图像
    #         cv2.imwrite(output_path, Roi)
    #
    #         # 显示裁剪后的图像
    #         cv2.imshow("Cropped Image", Roi)
    # if count0 <= 44:
    #     for i in range(9):
    #         # 裁剪图像
    #         Roi = crop_image_by_points(frame4, points5, i)
    #
    #         # 构建输出文件路径
    #         output_path = os.path.join(output_folder5, f"F_{i}.jpg")
    #
    #         # 保存裁剪后的图像
    #         cv2.imwrite(output_path, Roi)
    #
    #         # 显示裁剪后的图像
    #         cv2.imshow("Cropped Image", Roi)
    # if count0 <= 53:
    #     for i in range(9):
    #         # 裁剪图像
    #         Roi = crop_image_by_points(frame4, points6, i)
    #
    #         # 构建输出文件路径
    #         output_path = os.path.join(output_folder6, f"R_{i}.jpg")
    #
    #         # 保存裁剪后的图像
    #         cv2.imwrite(output_path, Roi)
    #
    #         # 显示裁剪后的图像
    #         cv2.imshow("Cropped Image", Roi)


        # 按 'q' 键退出循环
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# 释放摄像头资源
cap1.release()

# 关闭所有窗口
cv2.destroyAllWindows()