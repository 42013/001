import numpy as np
import os
import time
from sklearn import svm
import joblib
import cv2 as cv
from sklearn.model_selection import train_test_split  # 添加导入

def read_all_data():
    file_path = 'D:\match0\picture\mod'
    cName = ['U', 'L', 'F', 'R', 'B', 'D']
    # 得到一个图像文件名列表flist
    i = 0
    for c in cName:

        train_data_path = os.path.join(file_path, c)
        # 获取文件夹下的所有图片路径列表写的
        flist_ = get_file_list(train_data_path)

        if i == 0:
            dataMat, dataLabel = read_and_convert(flist_)
        else:
            dataMat_, dataLabel_ = read_and_convert(flist_)
            # 按轴axis0连接array组成一个新的array
            dataMat = np.concatenate((dataMat, dataMat_), axis=0)
            dataLabel = np.concatenate((dataLabel, dataLabel_), axis=0)
            # print(dataMat.shape)
        # print(len(dataLabel))
        i += 1

    return dataMat, dataLabel

def read_and_convert(imgFileList):
    dataLabel = []  # 存放类标签
    # 计算图像个数
    dataNum = len(imgFileList)
    # dataNum * 1875 的矩阵
    dataMat = np.zeros((dataNum, 1200))  # 1875
    for i in range(dataNum):
        imgNameStr = imgFileList[i]
        # 得到 颜色_编号.jpg
        imgName = get_img_name_str(imgNameStr)
        # 得到 类标签(颜色) 如  B_5.jpg
        classTag = imgName.split(".")[0].split("_")[0]
        dataLabel.append(classTag)
        dataMat[i, :] = img2vector(imgNameStr)

    return dataMat, dataLabel

def get_file_list(path):
    file_list = []
    # 获取path路径下的所有文件名
    for file_name in os.listdir(path):
        fin_path = os.path.join(path, file_name)
        if (fin_path.endswith('.jpg')):
            file_list.append(fin_path)

    return file_list

# 按文件路径拆分并取最后一个元素，即图像文件名
def get_img_name_str(imgPath):
    return imgPath.split(os.path.sep)[-1]
# 将图像转换为向量
def img2vector(imgFile):
    img = cv.imread(imgFile, 1)
    img = cv.resize(img, (20, 20))
    img_arr = np.array(img)
    # 对图像进行归一化
    img_normlization = img_arr/255
    # 1 * 1875 向量
    img_arr2 = np.reshape(img_normlization, (1, -1))
    return img_arr2


def create_svm(dataMat, dataLabel, path):
    clf = svm.SVC(C=1.0, kernel='rbf')
    # 开始训练模型
    dataMat, X_test, dataLabel, y_test = train_test_split(dataMat, dataLabel, test_size=0.2, random_state=42)
    rf = clf.fit(dataMat, dataLabel)
    # 存储训练好的模型
    joblib.dump(rf, path)
    accuracy = clf.score(X_test, y_test)
    print(f'模型准确度：{accuracy}')
    return clf

if __name__ == '__main__':
    st = time.perf_counter()
    path = 'D:\match0\model\model3' #模板文件存放的位置
    dataMat, dataLabel = read_all_data()
    model_path = os.path.join(path, 'svm_cube.model')
    create_svm(dataMat, dataLabel, model_path)
    et = time.perf_counter()
    print("Training spent {:.4f}s.".format((et - st)))
