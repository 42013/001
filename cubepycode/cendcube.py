import keyboard
import serial
import time

flag = 0

start_time = time.time()  # 获取开始时间

my_list = list([1, 2, 3, 4, 5])


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


def recv(ser):
    while True:
        data = ser.read_all()
        if data == '':
            continue
        else:
            break
    return data


def send_packet(ser, data):
    frame_start = b'\xff'
    frame_end = b'\xfe'
    packet = b''  # 初始化 packet 变量

    # 如果 data 是整数，表示数据包长度
    if isinstance(data, int):
        hex_data = format(data, '02x')  # 将整数转换为两位十六进制字符串
        packet = frame_start + bytes.fromhex(hex_data) + frame_end
        ser.write(packet)
        time.sleep(0.1)  # 添加延时，以确保 STM32 单片机能够正确接收长度信息
    else:
        # 发送每个字符
        for char in data:
            packet = frame_start + char.encode('utf-8') + frame_end
            ser.write(packet)
            time.sleep(0.02)  # 添加延时，以确保 STM32 单片机能够逐个字符正确接收


def set_global_var(key):
    global flag
    if key.name == '+':
        ser.write(b'\x01')
        flag = 2


def on_key_press(event):
    set_global_var(event)


keyboard.on_press(on_key_press)

# 打开串口
ser = serial.Serial('COM22', 9600, timeout=0.1)
input_string = convert_to_lowercase("R' D2 R' U2 R F2 D B2 U' R F' U R2 D L2 D' B2 R2 B2 U' B2")
# input_string = convert_to_lowercase("U D2")
# 输出结果
print(input_string)
# 待发送的字符串
while True:
    if flag == 0:
        string_length = len(input_string.split())
        print(f"String Length: {string_length}")

        # 发送字符串的长度
        send_packet(ser, string_length)

        # 拆分字符串并发送
        for char in input_string.split():
            send_packet(ser, char)
        flag = 1
    # for i in range(21):
    if flag == 1:
        data = recv(ser)
        if data.strip():  # 检查是否为空
            print(data)
            end_time = time.time()
            timecount0 = end_time - start_time
            print(timecount0)
            flag = 2
            break
ser.close()
print("关闭串口")
