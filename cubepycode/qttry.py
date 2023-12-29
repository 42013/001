import sys
import time
import serial
import datetime
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QLabel
from PyQt5.QtGui import QPixmap, QFont
from PyQt5.QtCore import QTimer

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
    packet = b''

    if isinstance(data, int):
        hex_data = hex(data)[2:]
        packet = frame_start + bytes.fromhex(hex_data) + frame_end
        ser.write(packet)
        time.sleep(0.1)
    else:
        for char in data:
            packet = frame_start + char.encode('utf-8') + frame_end
            ser.write(packet)
            time.sleep(0.02)

class MyWindow(QWidget):
    def __init__(self):
        super().__init__()

        self.initUI()

    def initUI(self):
        self.data_list = []  # 用于存储清零计时的数据

        font = QFont()
        font.setPointSize(20)
        font.setBold(True)

        self.setWindowTitle('cubetimer')
        self.setFixedSize(1500, 1000)
        self.setGeometry(100, 100, 400, 300)
        self.setStyleSheet("background-color: rgb(126, 126, 122);")

        self.countlabel = QLabel('计时次数: 0', self)
        self.countlabel.setFont(font)
        self.countlabel.setGeometry(1000, 600, 250, 80)
        self.countlabel.setStyleSheet("background-color: #4682B4; color:(26, 226, 152) ;"
                                   " font-size: 30px; font-family: Arial;")

        self.timelabel = QLabel('00:00 S', self)
        self.timelabel.setFont(font)
        self.timelabel.setGeometry(1100, 50, 150, 80)

        pixmap1 = QPixmap('D:\\QTproject\\title\\colock.jpg')
        self.label = QLabel(self)
        self.label.setGeometry(500, 0, pixmap1.width(), pixmap1.height())
        self.label.setPixmap(pixmap1)

        pixmap = QPixmap('D:\\QTproject\\title\\OIP-C.jpg')
        self.label = QLabel(self)
        self.label.setGeometry(0, 0, pixmap.width(), pixmap.height())
        self.label.setPixmap(pixmap)

        self.button = QPushButton('清零', self)
        self.button.setGeometry(1000, 200, 150, 100)
        self.button.clicked.connect(self.buttonthree)
        self.button.setStyleSheet("background-color: #4682B4; color:(26, 226, 152) ;"
                                  " font-size: 30px; font-family: Arial;")

        self.serial_button = QPushButton('发送消息', self)
        self.serial_button.setGeometry(1200, 200, 150, 100)
        self.serial_button.clicked.connect(self.sendSerialMessage)
        self.serial_button.setStyleSheet("background-color: #4682B4; color:(26, 226, 152) ; "
                                         "font-size: 30px; font-family: Arial;")

        self.re_button = QPushButton('复位', self)
        self.re_button.setGeometry(1350, 300, 150, 100)
        self.re_button.clicked.connect(self.sendreposition)
        self.re_button.setStyleSheet("background-color: #4682B4; color:(26, 226, 152) ; "
                                         "font-size: 30px; font-family: Arial;")

        self.button1 = QPushButton('计时', self)
        self.button1.setGeometry(1000, 400, 150, 100)
        self.button1.clicked.connect(self.buttonone)
        self.button1.setStyleSheet("background-color: #4682B4; color: yellow; font-size: 30px; font-family: Arial;")

        self.button2 = QPushButton('暂停', self)
        self.button2.setGeometry(1200, 400, 150, 100)
        self.button2.clicked.connect(self.buttontwo)
        self.button2.setStyleSheet("background-color: #4682B4; color:(26, 226, 152) ;"
                                  " font-size: 30px; font-family: Arial;")

        self.timer = QTimer(self)
        self.timer.timeout.connect(self.updateTime)
        self.flag = False
        self.flag0 = False
        self.countflag = False
        self.count = 0

    def buttonClicked(self):
        current_time = datetime.datetime.now()
        time_str = current_time.strftime('%Y-%m-%d %H:%M:%S')
        self.label.setText(time_str)

    def buttonone(self):
        if not self.flag0:
            self.countflag = False
            self.start_time = time.time()
            self.flag0 = True
        if not self.flag and self.flag0:
            self.flag = True
            self.countflag = True
            self.timer.start(10)

    def buttontwo(self):
        if self.flag:
            self.timer.stop()
            self.flag = False
    def buttonthree(self):
        self.timer.stop()
        self.flag = False
        self.flag0 = False
        if self.countflag:
            self.count += 1
            self.data_list.append(f'计时{self.count}: {self.elapsed_time:.2f} S')
            self.start_time = 0
            self.elapsed_time = 0
            self.timelabel.setText("00:00 S")
            self.countlabel.setText(f'计时次数: {self.count}')

        # 限制数据列表长度为10
        if len(self.data_list) > 10:
            del self.data_list[0]

        # 在这里更新界面显示清零计时的数据
        print(self.data_list)

    def updateTime(self):
        self.end_time = time.time()
        self.elapsed_time = self.end_time - self.start_time
        self.timelabel.setText(f"0{self.elapsed_time:.2f} S")

    def sendSerialMessage(self):
        ser = serial.Serial('COM22', 9600)
        input_string = "B Q A W Z W l W L S A D f r U r b u l f W"
        string_length = len(input_string.split())
        print(f"String Length: {string_length}")
        send_packet(ser, string_length)
        for char in input_string.split():
            send_packet(ser, char)

        ser.close()

    def sendreposition(self):
        ser = serial.Serial('COM21', 9600)
        ser.write(b'\x01')
        ser.close()

def timer():
    app = QApplication(sys.argv)
    window = MyWindow()
    window.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    timer()
