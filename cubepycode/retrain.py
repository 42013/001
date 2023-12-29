import cv2
import time
import serial
import joblib
import keyboard
import kociemba
import colorcube as col
# import qttry

q = 0
p = 0
count1 = 0
count2 = 0
count3 = 0
count4 = 0
change = 1
see = 0
confirmation = 0
confirmation1 = 0
confirmation2 = 0
confirmation3 = 0
confirmation4 = 0
confirmation5 = 0

points1 = [(102 + q, 28 + p), (139 + q, 66 + p), (180 + q, 102 + p), (60 + q, 67 + p), (95 + q, 105 + p),
           (145 + q, 142 + p), (18 + q, 98 + p), (53 + q, 138 + p), (101 + q, 174 + p)]
points2 = [(92 + q, 32 + p), (133 + q, 75 + p), (175 + q, 111 + p), (50 + q, 76 + p), (94 + q, 115 + p),
           (138 + q, 150 + p), (8 + q, 115 + p), (48 + q, 155 + p), (93 + q, 193 + p)]
points3 = [(20 + q, 108 + p), (56 + q, 100 + p), (102 + q, 88 + p), (20 + q, 170 + p), (55 + q, 166 + p),
           (102 + q, 162 + p), (20 + q, 228 + p), (56 + q, 229 + p), (102 + q, 235 + p)]
points4 = [(164 + q, 83 + p), (164 + q, 160 + p), (164 + q, 234 + p), (215 + q, 91 + p), (218 + q, 163 + p),
           (215 + q, 231 + p), (255 + q, 102 + p), (258 + q, 166 + p), (258 + q, 230 + p)]
points5 = [(164 + q, 83 + p), (164 + q, 160 + p), (164 + q, 234 + p), (215 + q, 91 + p), (218 + q, 163 + p),
           (215 + q, 231 + p), (255 + q, 102 + p), (258 + q, 166 + p), (258 + q, 230 + p)]
points6 = [(164 + q, 83 + p), (164 + q, 160 + p), (164 + q, 234 + p), (215 + q, 91 + p), (218 + q, 163 + p),
           (215 + q, 231 + p), (255 + q, 102 + p), (258 + q, 166 + p), (258 + q, 230 + p)]

points01 = [(20 + q, 108 + p), (56 + q, 100 + p), (102 + q, 88 + p), (20 + q, 170 + p), (55 + q, 166 + p),
            (102 + q, 162 + p), (20 + q, 228 + p), (56 + q, 229 + p), (102 + q, 235 + p),
            (164 + q, 83 + p), (164 + q, 160 + p), (164 + q, 234 + p), (215 + q, 91 + p), (218 + q, 163 + p),
            (215 + q, 231 + p), (255 + q, 102 + p), (258 + q, 166 + p), (258 + q, 230 + p)]

# 步骤1：加载训练好的SVM模型
model_path = 'D:\\match0\\model\\model1\\svm_cube.model'  # 替换为你的模型文件路径
clf = joblib.load(model_path)

# 打开串口
ser = serial.Serial('COM22', 9600, timeout=0.5)


def recv(ser0):
    while True:
        data = ser0.read_all()
        if data == '':
            continue
        else:
            break
    return data


def send_packet(ser0, data):
    frame_start = b'\xff'
    frame_end = b'\xfe'
    packet = b''  # 初始化 packet 变量

    # 如果 data 是整数，表示数据包长度
    if isinstance(data, int):
        hex_data = format(data, '02x')  # 将整数转换为两位十六进制字符串
        packet = frame_start + bytes.fromhex(hex_data) + frame_end
        ser0.write(packet)
        time.sleep(0.1)  # 添加延时，以确保 STM32 单片机能够正确接收长度信息
    else:
        # 发送每个字符
        for char in data:
            packet = frame_start + char.encode('utf-8') + frame_end
            ser0.write(packet)
            time.sleep(0.02)  # 添加延时，以确保 STM32 单片机能够逐个字符正确接收

# def send_packet(ser, data):
#     frame_start = b'\xff'
#     frame_end = b'\xfe'
#     packet = b''  # 初始化 packet 变量
#
#     # 如果 data 是整数，表示数据包长度
#     if isinstance(data, int):
#         hex_data = hex(data)[2:]  # 将整数转换为十六进制字符串并去掉开头的 '0x'
#         packet = frame_start + bytes.fromhex(hex_data) + frame_end
#         ser.write(packet)
#         time.sleep(0.1)  # 添加延时，以确保 STM32 单片机能够正确接收长度信息
#     else:
#         # 发送每个字符
#         for char in data:
#             packet = frame_start + char.encode('utf-8') + frame_end
#             ser.write(packet)
#             time.sleep(0.02)  # 添加延时，以确保 STM32 单片机能够逐个字符正确接收
#     print(packet)


def set_global_var(key):
    global change
    global count3  # 可改变量，调试用
    global see
    global q
    global p

    if key.name == 'a':
        q += 1
        print("q:", q)
    elif key.name == 'd':
        q -= 1
        print("q:", q)
    elif key.name == 'w':
        p += 1
        print("p:", p)
    elif key.name == 's':
        p -= 1
        print("p:", p)
    elif key.name == 'g':
        # p = 0
        # q = 0
        # print("clear")
        see = 1
        print("see")
    elif key.name == '*':
        change = 0
    elif key.name == '+':
        count3 += 1
        print("count", count3)
    elif key.name == '-':
        count3 -= 1
        print("count", count3)
    elif key.name == '/':
        ser.write(b'\x01')


def on_key_press(event):
    set_global_var(event)


keyboard.on_press(on_key_press)

cap1 = cv2.VideoCapture(4, cv2.CAP_DSHOW)  # 4
cap1.set(cv2.CAP_PROP_BRIGHTNESS, 0)  # U面
cap1.set(cv2.CAP_PROP_FRAME_WIDTH, 300)
cap1.set(cv2.CAP_PROP_FRAME_HEIGHT, 300)

cap2 = cv2.VideoCapture(3, cv2.CAP_DSHOW)  # 3
cap2.set(cv2.CAP_PROP_BRIGHTNESS, 100)  # U面
cap2.set(cv2.CAP_PROP_FRAME_WIDTH, 300)
cap2.set(cv2.CAP_PROP_FRAME_HEIGHT, 300)

cap3 = cv2.VideoCapture(1, cv2.CAP_DSHOW)  # 1
cap3.set(cv2.CAP_PROP_BRIGHTNESS, 0)  # 亮度
cap3.set(cv2.CAP_PROP_FRAME_WIDTH, 400)
cap3.set(cv2.CAP_PROP_FRAME_HEIGHT, 350)

cap4 = cv2.VideoCapture(0, cv2.CAP_DSHOW)  # 0
cap4.set(cv2.CAP_PROP_BRIGHTNESS, 0)  # 亮度
cap4.set(cv2.CAP_PROP_FRAME_WIDTH, 350)
cap4.set(cv2.CAP_PROP_FRAME_HEIGHT, 400)

while True:
    # 读取每一帧
    ret1, frame1r = cap1.read()
    ret2, frame2r = cap2.read()
    ret3, frame3r = cap3.read()
    ret4, frame4r = cap4.read()
    frame1 = cv2.rotate(frame1r, cv2.ROTATE_90_COUNTERCLOCKWISE)  # 逆时针旋转90度
    frame2 = cv2.rotate(frame2r, cv2.ROTATE_90_CLOCKWISE)  # 顺时针旋转90度
    frame3 = cv2.rotate(frame3r, cv2.ROTATE_90_CLOCKWISE)  # 顺时针旋转90度
    frame4 = cv2.rotate(frame4r, cv2.ROTATE_90_COUNTERCLOCKWISE)  # 逆时针旋转90度
    # 步骤2：准备待识别的图像
    start_time = time.time()  # 获取开始时间
    if ret1 and ret2 and ret3 and ret4:
        # if ret4:
        # points4 = [(164 + q, 83 + p), (215 + q, 91 + p), (255 + q, 102 + p), (164 + q, 160 + p), (218 + q, 163 + p),
        #            (258 + q, 166 + p), (164 + q, 234 + p), (215 + q, 231 + p), (258 + q, 230 + p)]
        # img = cv2.circle(frame3, points4[count3], 3, (0, 125, 255), 5)
        # cv2.imshow('show', img)
        # Roi = col.crop_image_by_points(img, points4, count3)
        # cv2.imshow('roi', Roi)
        # # Roi2 = col.crop_image_by_points(pimg2, points2, count2)
        # # cv2.imshow('ROI', Roi2)


        pimg1 = col.crop_image(frame1, (30, 135), 220)
        pimg2 = col.crop_image(frame2, (20, 125), 220)
        pimg1 = col.point(pimg1, points1)
        pimg2 = col.point(pimg2, points2)
        frame3 = col.point(frame3, points01)
        cv2.imshow('one', pimg1)
        cv2.imshow('two', pimg2)
        cv2.imshow('three', frame3)
        cv2.imshow('four', frame4)
        if see == 1:
            if count1 <= 8:
                img1 = cv2.circle(pimg1, points1[count1], 3, (0, 125, 255), 5)
                Roi1 = col.crop_image_by_points(pimg1, points1, count1)
                # cv2.imshow('roi1', Roi1)
                features = col.extract_features(Roi1)
                print(f'特征数量: {len(features[0])}')
                predicted_color = clf.predict(features)
                # 输出预测的颜色类别
                print(f'预测的颜色类别: {predicted_color}')
                col.colortag(0, count1, predicted_color)
                print("count1", count1)
                print("num", col.num)
                confirmation += 1
                if confirmation > 2:
                    count1 += 1
                    confirmation = 0
            if count2 <= 8:
                img2 = cv2.circle(pimg2, points2[count2], 3, (0, 125, 255), 5)
                Roi2 = col.crop_image_by_points(pimg2, points2, count2)
                # 使用坐标来裁剪图像
                # cv2.imshow('roi2', Roi2)
                features = col.extract_features(Roi2)
                print(f'特征数量: {len(features[0])}')
                predicted_color = clf.predict(features)
                # 输出预测的颜色类别
                print(f'预测的颜色类别: {predicted_color}')
                col.colortag(1, count2, predicted_color)
                print("count2", count2)
                print("num1", col.num1)
                confirmation1 += 1
                if confirmation1 > 2:
                    count2 += 1
                    confirmation1 = 0
            if count3 <= 8:
                img3 = cv2.circle(frame3, points3[count3], 3, (0, 125, 255), 5)  # 传入圆心信息，并画在原图上
                Roi3 = col.crop_image_by_points(frame3, points3, count3)
                # 使用坐标来裁剪图像
                # cv2.imshow('roi3', Roi3)
                features = col.extract_features(Roi3)
                print(f'特征数量: {len(features[0])}')
                predicted_color = clf.predict(features)
                # 输出预测的颜色类别
                print(f'预测的颜色类别: {predicted_color}')
                col.colortag(2, count3, predicted_color)
                print("count3", count3)
                print("num2", col.num2)
                confirmation2 += 1
                if confirmation2 > 2:
                    count3 += 1
                    confirmation2 = 0
            elif 8 < count3 <= 17:
                img4 = cv2.circle(frame3, points4[count3 - 9], 3, (0, 125, 255), 5)  # 传入圆心信息，并画在原图上
                Roi4 = col.crop_image_by_points(frame3, points4, count3 - 9)
                # 使用坐标来裁剪图像
                # cv2.imshow('roi4', Roi4)
                features = col.extract_features(Roi4)
                print(f'特征数量: {len(features[0])}')
                predicted_color = clf.predict(features)
                # 输出预测的颜色类别
                print(f'预测的颜色类别: {predicted_color}')
                col.colortag(3, count3 - 9, predicted_color)
                print("count3", count3)
                print("num3", col.num3)
                confirmation3 += 1
                if confirmation3 > 2:
                    count3 += 1
                    confirmation3 = 0
            if count4 <= 8:
                img5 = cv2.circle(frame4, points5[count4], 3, (0, 125, 255), 5)  # 传入圆心信息，并画在原图上
                Roi5 = col.crop_image_by_points(frame4, points5, count4)
                # 使用坐标来裁剪图像
                # cv2.imshow('roi5', Roi5)
                features = col.extract_features(Roi5)
                print(f'特征数量: {len(features[0])}')
                predicted_color = clf.predict(features)
                # 输出预测的颜色类别
                print(f'预测的颜色类别: {predicted_color}')
                col.colortag(4, count4, predicted_color)
                print("count4", count4)
                print("num4", col.num4)
                confirmation4 += 1
                if confirmation4 > 2:
                    count4 += 1
                    confirmation4 = 0
            elif 8 < count4 <= 17:
                img6 = cv2.circle(frame4, points6[count4 - 9], 3, (0, 125, 255), 5)  # 传入圆心信息，并画在原图上
                Roi6 = col.crop_image_by_points(frame4, points6, count4 - 9)
                # 使用坐标来裁剪图像
                # cv2.imshow('roi6', Roi6)
                features = col.extract_features(Roi6)
                print(f'特征数量: {len(features[0])}')
                predicted_color = clf.predict(features)
                # 输出预测的颜色类别
                print(f'预测的颜色类别: {predicted_color}')
                col.colortag(5, count4 - 9, predicted_color)
                print("count4", count4)
                print("num5", col.num5)
                confirmation5 += 1
                if confirmation5 > 2:
                    count4 += 1
                    confirmation5 = 0
            if change == 1 and count1 + count2 + count3 + count4 == 54:
                print("num", col.num)
                print("num1", col.num1)
                print("num2", col.num2)
                print("num3", col.num3)
                print("num4", col.num4)
                print("num5", col.num5)
            if change == 0 and count1 + count2 + count3 + count4 == 54:
                see = 2
        if see == 2:
            # print("ready")
            see = 3
        if see == 3:
            # re1 = ''.join(col.num5) + ''.join(col.num4) + ''.join(col.num1) + ''.join(col.num3)
            # original_string = ''.join(col.num) + ''.join(re1) + ''.join(col.num2)
            # result = f"'{original_string}'"
            # print(result)
            result = 'FLBUULFFLFDURRDBUBUUDDFFBRDDBLRDRFLLRLRULFUDRRBDBBBUFL'
            results = kociemba.solve(result)
            # 转换为小写表示法
            output_string = col.convert_to_lowercase(results)
            # 输出结果
            print(output_string)
            output_string = ' '.join(output_string)
            string_length = len(output_string.split())
            print(f"String Length: {string_length}")

            # 发送字符串的长度
            send_packet(ser, string_length)

            # 拆分字符串并发送
            for char in output_string.split():
                send_packet(ser, char)
            end_time1 = time.time()
            timecount0 = end_time1 - start_time
            print(timecount0)
            data = recv(ser)
            if data.strip():  # 检查是否为空
                print(data)
                end_time2 = time.time()
                timecount1 = end_time2 - end_time1
                print(timecount0 + timecount1)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
# ser.close()
cap1.release()
cap2.release()
cap3.release()
cap4.release()
cv2.destroyAllWindows()
print("num", col.num)
print("num1", col.num1)
print("num2", col.num2)
print("num3", col.num3)
print("num4", col.num4)
print("num5", col.num5)
