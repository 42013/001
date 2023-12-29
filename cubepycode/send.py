import serial
import keyboard

i = 0
# 串口初始化
ser = serial.Serial('COM22', 9600)  # 替换为你的串口端口和波特率


def recv(serial):
    while True:
        data = serial.read_all()
        if data == '':
            continue
        else:
            break
        sleep(0.02)
    return data


def send(send_data):
    if serial.isOpen():
        serial.write(send_data.encode('utf-8'))  # 编码
        print("发送成功", send_data)
    else:
        print("发送失败！")



def set_global_var(key):
    global i

    if key.name == '+':
        i = 0
        print("point", i)


def on_key_press(event):
    set_global_var(event)


keyboard.on_press(on_key_press)
while True:
    if i == 0:
        # 接受用户输入的十六进制数据
        hex_input = input("请输入十六进制数据 (例如: 01 02 03)：")

        # 将用户输入的字符串转换为十六进制字节
        data_to_send = bytes.fromhex(hex_input.replace(" ", ""))

        # 发送数据
        ser.write(data_to_send)

        # 读取并显示接收到的数据
        # received_data = ser.read(1)  # 10表示要读取的字节数
        # print(f'Received Data: {received_data.hex()}')
        i = 1

# 关闭串口
ser.close()
