import sys
from PyQt5.QtWidgets import QApplication
from admin import MainWindow

app = QApplication(sys.argv)

decoder = MainWindow()

sys.exit(app.exec_())