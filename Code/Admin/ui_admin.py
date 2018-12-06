# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'mainwindow.ui'
#
# Created by: PyQt5 UI code generator 5.10.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 600)
        self.centralWidget = QtWidgets.QWidget(MainWindow)
        self.centralWidget.setStyleSheet("background-color: rgb(38, 38, 38)\n"
"")
        self.centralWidget.setObjectName("centralWidget")
        self.verificar = QtWidgets.QPushButton(self.centralWidget)
        self.verificar.setGeometry(QtCore.QRect(330, 70, 151, 23))
        self.verificar.setStyleSheet("QPushButton {\n"
"  background-color: rgb(255, 151, 57);\n"
"  color: white; \n"
"  border: 1px solid gray;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}")
        self.verificar.setObjectName("verificar")
        self.label_carros = QtWidgets.QLabel(self.centralWidget)
        self.label_carros.setGeometry(QtCore.QRect(290, 10, 241, 21))
        self.label_carros.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.label_carros.setAlignment(QtCore.Qt.AlignCenter)
        self.label_carros.setObjectName("label_carros")
        self.status_atual = QtWidgets.QLabel(self.centralWidget)
        self.status_atual.setGeometry(QtCore.QRect(130, 200, 101, 21))
        self.status_atual.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.status_atual.setAlignment(QtCore.Qt.AlignCenter)
        self.status_atual.setObjectName("status_atual")
        self.img_status = QtWidgets.QLabel(self.centralWidget)
        self.img_status.setGeometry(QtCore.QRect(10, 230, 350, 350))
        self.img_status.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.img_status.setText("")
        self.img_status.setObjectName("img_status")
        self.img_cerca_1 = QtWidgets.QLabel(self.centralWidget)
        self.img_cerca_1.setGeometry(QtCore.QRect(370, 140, 200, 200))
        self.img_cerca_1.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.img_cerca_1.setText("")
        self.img_cerca_1.setObjectName("img_cerca_1")
        self.cerca_1 = QtWidgets.QLabel(self.centralWidget)
        self.cerca_1.setGeometry(QtCore.QRect(415, 110, 100, 21))
        self.cerca_1.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.cerca_1.setAlignment(QtCore.Qt.AlignCenter)
        self.cerca_1.setObjectName("cerca_1")
        self.img_cerca_2 = QtWidgets.QLabel(self.centralWidget)
        self.img_cerca_2.setGeometry(QtCore.QRect(590, 140, 200, 200))
        self.img_cerca_2.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.img_cerca_2.setText("")
        self.img_cerca_2.setObjectName("img_cerca_2")
        self.cerca_2 = QtWidgets.QLabel(self.centralWidget)
        self.cerca_2.setGeometry(QtCore.QRect(635, 110, 100, 21))
        self.cerca_2.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.cerca_2.setAlignment(QtCore.Qt.AlignCenter)
        self.cerca_2.setObjectName("cerca_2")
        self.img_cerca_3 = QtWidgets.QLabel(self.centralWidget)
        self.img_cerca_3.setGeometry(QtCore.QRect(370, 380, 200, 200))
        self.img_cerca_3.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.img_cerca_3.setText("")
        self.img_cerca_3.setObjectName("img_cerca_3")
        self.cerca_3 = QtWidgets.QLabel(self.centralWidget)
        self.cerca_3.setGeometry(QtCore.QRect(415, 350, 100, 21))
        self.cerca_3.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.cerca_3.setAlignment(QtCore.Qt.AlignCenter)
        self.cerca_3.setObjectName("cerca_3")
        self.img_cerca_4 = QtWidgets.QLabel(self.centralWidget)
        self.img_cerca_4.setGeometry(QtCore.QRect(590, 380, 200, 200))
        self.img_cerca_4.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.img_cerca_4.setText("")
        self.img_cerca_4.setObjectName("img_cerca_4")
        self.cerca_4 = QtWidgets.QLabel(self.centralWidget)
        self.cerca_4.setGeometry(QtCore.QRect(635, 350, 100, 21))
        self.cerca_4.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.cerca_4.setAlignment(QtCore.Qt.AlignCenter)
        self.cerca_4.setObjectName("cerca_4")
        self.alerta = QtWidgets.QLabel(self.centralWidget)
        self.alerta.setGeometry(QtCore.QRect(30, 120, 321, 21))
        self.alerta.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.alerta.setAlignment(QtCore.Qt.AlignCenter)
        self.alerta.setObjectName("alerta")
        self.senha = QtWidgets.QLabel(self.centralWidget)
        self.senha.setGeometry(QtCore.QRect(30, 160, 321, 21))
        self.senha.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.senha.setAlignment(QtCore.Qt.AlignCenter)
        self.senha.setObjectName("senha")
        self.lineEdit = QtWidgets.QLineEdit(self.centralWidget)
        self.lineEdit.setGeometry(QtCore.QRect(330, 40, 151, 20))
        self.lineEdit.setStyleSheet("background-color:rgb(255, 255, 255);\n"
"border: 1px solid gray;")
        self.lineEdit.setObjectName("lineEdit")
        MainWindow.setCentralWidget(self.centralWidget)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "ADMIN"))
        self.verificar.setText(_translate("MainWindow", "Verificar"))
        self.label_carros.setText(_translate("MainWindow", "Digite a Placa do Carro que Deseja Verificar:"))
        self.status_atual.setText(_translate("MainWindow", "Status Atual"))
        self.cerca_1.setText(_translate("MainWindow", "Cerca 1"))
        self.cerca_2.setText(_translate("MainWindow", "Cerca 2"))
        self.cerca_3.setText(_translate("MainWindow", "Cerca 3"))
        self.cerca_4.setText(_translate("MainWindow", "Cerca 4"))
        self.alerta.setText(_translate("MainWindow", "Alerta:"))
        self.senha.setText(_translate("MainWindow", "Senha:"))

