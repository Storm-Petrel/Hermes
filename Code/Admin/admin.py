from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QMessageBox
from PyQt5.QtGui import QIcon, QPixmap
from ui_admin import Ui_MainWindow
import requests
from PIL import Image
from PIL.ImageQt import ImageQt

Key = "AIzaSyDAPnKQJwXhgqTLznH3JthGhVnrLBuu6p0"

def getcenter(points):
    x, y = zip(*points)
    center = (max(x) + min(x)) / 2., (max(y) + min(y)) / 2.
    return center

class MainWindow(QtWidgets.QMainWindow, Ui_MainWindow):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        self.show()

        self.verificar.clicked.connect(self.load)

    def load(self):
        if not self.lineEdit.text():
            QMessageBox().warning(self, "Erro!", "Digite a placa de um veículo cadastrado!",
                                  QMessageBox.Ok)
            return
        url = "https://stormpetrel.mybluemix.net/getCar?_id="+self.lineEdit.text()
        r = requests.get(url)
        data = r.json()
        if data == None:
            QMessageBox().warning(self, "Erro!", "Veículo não cadastrado!", QMessageBox.Ok)
            return
        alerta = "Alerta: "+data["alerta"]
        self.alerta.setText(alerta)
        senha = "Senha: "+data["senha"]
        self.senha.setText(senha)

        points = [(float(data["cerca_1_lat_0"]), float(data["cerca_1_lon_0"])),
                  (float(data["cerca_1_lat_1"]), float(data["cerca_1_lon_1"])),
                  (float(data["cerca_1_lat_2"]), float(data["cerca_1_lon_2"])),
                  (float(data["cerca_1_lat_3"]), float(data["cerca_1_lon_3"]))]
        center = getcenter(points)
        url = """https://maps.googleapis.com/maps/api/staticmap?center={},{}&zoom=11&scale=1&size=350x350&maptype=roadmap&format=png&visual_refresh=true&markers=size:mid%7Ccolor:0xff0000%7Clabel:%7C{},{}&path=color%3ared%7Cweight:1%7Cfillcolor%3ablank%7C{},{}%7C{},{}%7C{},{}%7C{},{}%7C{},{}&key={}""".format(
            center[0], center[1], data["atual_lat"],data["atual_lon"],data["cerca_ativa_0_lat"],
            data["cerca_ativa_0_lon"], data["cerca_ativa_1_lat"], data["cerca_ativa_1_lon"], data["cerca_ativa_2_lat"],
            data["cerca_ativa_2_lon"], data["cerca_ativa_3_lat"], data["cerca_ativa_3_lon"], data["cerca_ativa_0_lat"],
            data["cerca_ativa_0_lon"], Key)
        im = Image.open(requests.get(url, stream=True).raw)
        im2 = ImageQt(im)
        pixmap = QPixmap.fromImage(im2)
        self.img_status.setPixmap(pixmap)





        if "cerca_1" in data:
            cerca1 = "Cerca: "+data["cerca_1"]
            self.cerca_1.setText(cerca1)
            points = [(float(data["cerca_1_lat_0"]), float(data["cerca_1_lon_0"])),
                      (float(data["cerca_1_lat_1"]), float(data["cerca_1_lon_1"])),
                      (float(data["cerca_1_lat_2"]), float(data["cerca_1_lon_2"])),
                      (float(data["cerca_1_lat_3"]), float(data["cerca_1_lon_3"]))]
            center = getcenter(points)
            url = """https://maps.googleapis.com/maps/api/staticmap?center={},{}&zoom=11&scale=1&size=200x200&maptype=roadmap&format=png&visual_refresh=true&path=color%3ared%7Cweight:1%7Cfillcolor%3ablank%7C{},{}%7C{},{}%7C{},{}%7C{},{}%7C{},{}&key={}""".format(
                    center[0], center[1], data["cerca_1_lat_0"],
                    data["cerca_1_lon_0"], data["cerca_1_lat_1"], data["cerca_1_lon_1"], data["cerca_1_lat_2"],
                    data["cerca_1_lon_2"], data["cerca_1_lat_3"], data["cerca_1_lon_3"], data["cerca_1_lat_0"],
                    data["cerca_1_lon_0"], Key)
            im = Image.open(requests.get(url, stream=True).raw)
            im2 = ImageQt(im)
            pixmap = QPixmap.fromImage(im2)
            self.img_cerca_1.setPixmap(pixmap)

        if "cerca_2" in data:
            cerca2 = "Cerca: "+data["cerca_2"]
            self.cerca_2.setText(cerca2)
            points = [(float(data["cerca_2_lat_0"]), float(data["cerca_2_lon_0"])),
                      (float(data["cerca_2_lat_1"]), float(data["cerca_2_lon_1"])),
                      (float(data["cerca_2_lat_2"]), float(data["cerca_2_lon_2"])),
                      (float(data["cerca_2_lat_3"]), float(data["cerca_2_lon_3"]))]
            center = getcenter(points)
            url = """https://maps.googleapis.com/maps/api/staticmap?center={},{}&zoom=11&scale=1&size=200x200&maptype=roadmap&format=png&visual_refresh=true&path=color%3ared%7Cweight:1%7Cfillcolor%3ablank%7C{},{}%7C{},{}%7C{},{}%7C{},{}%7C{},{}&key={}""".format(
                    center[0], center[1], data["cerca_2_lat_0"],
                    data["cerca_2_lon_0"], data["cerca_2_lat_1"], data["cerca_2_lon_1"], data["cerca_2_lat_2"],
                    data["cerca_2_lon_2"], data["cerca_2_lat_3"], data["cerca_2_lon_3"], data["cerca_2_lat_0"],
                    data["cerca_2_lon_0"], Key)
            im = Image.open(requests.get(url, stream=True).raw)
            im2 = ImageQt(im)
            pixmap = QPixmap.fromImage(im2)
            self.img_cerca_2.setPixmap(pixmap)

        if "cerca_3" in data:
            cerca3 = "Cerca: "+data["cerca_3"]
            self.cerca_3.setText(cerca3)
            points = [(float(data["cerca_3_lat_0"]), float(data["cerca_3_lon_0"])),
                      (float(data["cerca_3_lat_1"]), float(data["cerca_3_lon_1"])),
                      (float(data["cerca_3_lat_2"]), float(data["cerca_3_lon_2"])),
                      (float(data["cerca_3_lat_3"]), float(data["cerca_3_lon_3"]))]
            center = getcenter(points)
            url = """https://maps.googleapis.com/maps/api/staticmap?center={},{}&zoom=11&scale=1&size=200x200&maptype=roadmap&format=png&visual_refresh=true&path=color%3ared%7Cweight:1%7Cfillcolor%3ablank%7C{},{}%7C{},{}%7C{},{}%7C{},{}%7C{},{}&key={}""".format(
                    center[0], center[1], data["cerca_3_lat_0"],
                    data["cerca_3_lon_0"], data["cerca_3_lat_1"], data["cerca_3_lon_1"], data["cerca_3_lat_2"],
                    data["cerca_3_lon_2"], data["cerca_3_lat_3"], data["cerca_3_lon_3"], data["cerca_3_lat_0"],
                    data["cerca_3_lon_0"], Key)
            im = Image.open(requests.get(url, stream=True).raw)
            im2 = ImageQt(im)
            pixmap = QPixmap.fromImage(im2)
            self.img_cerca_3.setPixmap(pixmap)

        if "cerca_4" in data:
            cerca4 = "Cerca: "+data["cerca_4"]
            self.cerca_4.setText(cerca4)
            points = [(float(data["cerca_4_lat_0"]), float(data["cerca_4_lon_0"])),
                      (float(data["cerca_4_lat_1"]), float(data["cerca_4_lon_1"])),
                      (float(data["cerca_4_lat_2"]), float(data["cerca_4_lon_2"])),
                      (float(data["cerca_4_lat_3"]), float(data["cerca_4_lon_3"]))]
            center = getcenter(points)
            url = """https://maps.googleapis.com/maps/api/staticmap?center={},{}&zoom=11&scale=1&size=200x200&maptype=roadmap&format=png&visual_refresh=true&path=color%3ared%7Cweight:1%7Cfillcolor%3ablank%7C{},{}%7C{},{}%7C{},{}%7C{},{}%7C{},{}&key={}""".format(
                    center[0], center[1], data["cerca_4_lat_0"],
                    data["cerca_4_lon_0"], data["cerca_4_lat_1"], data["cerca_4_lon_1"], data["cerca_4_lat_2"],
                    data["cerca_4_lon_2"], data["cerca_4_lat_3"], data["cerca_4_lon_3"], data["cerca_4_lat_0"],
                    data["cerca_4_lon_0"], Key)
            im = Image.open(requests.get(url, stream=True).raw)
            im2 = ImageQt(im)
            pixmap = QPixmap.fromImage(im2)
            self.img_cerca_4.setPixmap(pixmap)