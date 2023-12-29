import cv2
import numpy as np

num = ['s', 's', 's', 's', 's', 's', 's', 's', 's']
num1 = ['s', 's', 's', 's', 's', 's', 's', 's', 's']
num2 = ['s', 's', 's', 's', 's', 's', 's', 's', 's']
num3 = ['s', 's', 's', 's', 's', 's', 's', 's', 's']
num4 = ['s', 's', 's', 's', 's', 's', 's', 's', 's']
num5 = ['s', 's', 's', 's', 's', 's', 's', 's', 's']


def extract_features(image0):
    img_arr = np.array(image0)
    # 对图像进行归一化
    img_normlization = img_arr / 255
    # 1 * 1875 向量
    img_arr2 = np.reshape(img_normlization, (1, -1))
    return img_arr2


def convert_to_lowercase(instruction):
    # 定义转换规则
    conversion_rules = {
        'U2': 'u',
        'D2': 'd',
        'B2': 'b',
        'L2': 'l',
        'F2': 'f',
        'R2': 'r',
        "U'": 'Q',
        "D'": 'W',
        "B'": 'E',
        "L'": 'A',
        "F'": 'S',
        "R'": 'Z'
    }

    # 替换特定大写表示法为小写
    for key, value in conversion_rules.items():
        instruction = instruction.replace(key, value)

    return instruction


def crop_image_by_points(image, points, count):
    # 计算点集的包围框
    x, y = points[count]
    roi = image[y:y + 25, x:x + 25]

    return roi


def crop_image(image, points, size):
    # 计算点集的包围框
    x, y = points
    roi = image[y:y + size, x:x + size]

    return roi




def colortag(num0, cou, c):
    if num0 == 0:
        if cou != 4:
            if c == 'U':
                num[cou] = 'U'
            elif c == 'D':
                num[cou] = 'D'
            elif c == 'L':
                num[cou] = 'L'
            elif c == 'R':
                num[cou] = 'R'
            elif c == 'B':
                num[cou] = 'B'
            elif c == 'F':
                num[cou] = 'F'
        else:
            num[cou] = 'U'
    if num0 == 1:
        if cou != 4:
            if c == 'U':
                num1[cou] = 'U'
            elif c == 'D':
                num1[cou] = 'D'
            elif c == 'L':
                num1[cou] = 'L'
            elif c == 'R':
                num1[cou] = 'R'
            elif c == 'B':
                num1[cou] = 'B'
            elif c == 'F':
                num1[cou] = 'F'
        else:
            num1[cou] = 'D'
    if num0 == 2:
        if cou != 4:
            if c == 'U':
                num2[cou] = 'U'
            elif c == 'D':
                num2[cou] = 'D'
            elif c == 'L':
                num2[cou] = 'L'
            elif c == 'R':
                num2[cou] = 'R'
            elif c == 'B':
                num2[cou] = 'B'
            elif c == 'F':
                num2[cou] = 'F'
        else:
            num2[cou] = 'B'
    if num0 == 3:
        if cou != 4:
            if c == 'U':
                num3[cou] = 'U'
            elif c == 'D':
                num3[cou] = 'D'
            elif c == 'L':
                num3[cou] = 'L'
            elif c == 'R':
                num3[cou] = 'R'
            elif c == 'B':
                num3[cou] = 'B'
            elif c == 'F':
                num3[cou] = 'F'
        else:
            num3[cou] = 'L'
    if num0 == 4:
        if cou != 4:
            if c == 'U':
                num4[cou] = 'U'
            elif c == 'D':
                num4[cou] = 'D'
            elif c == 'L':
                num4[cou] = 'L'
            elif c == 'R':
                num4[cou] = 'R'
            elif c == 'B':
                num4[cou] = 'B'
            elif c == 'F':
                num4[cou] = 'F'
        else:
            num4[cou] = 'F'

    if num0 == 5:
        if cou != 4:
            if c == 'U':
                num5[cou] = 'U'
            elif c == 'D':
                num5[cou] = 'D'
            elif c == 'L':
                num5[cou] = 'L'
            elif c == 'R':
                num5[cou] = 'R'
            elif c == 'B':
                num5[cou] = 'B'
            elif c == 'F':
                num5[cou] = 'F'
        else:
            num5[cou] = 'R'


def point(frame, points):
    for coord in points:
        img = cv2.circle(frame, coord, 3, (0, 0, 255), 5)
    return img
