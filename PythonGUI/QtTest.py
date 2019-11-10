import sys
from PyQt5.QtWidgets import QApplication, QMainWindow
from test import *


class NewWindow(QMainWindow, Ui_MainWindow):
    def __init__(self, parent = None):
        super(NewWindow, self).__init__(parent)
        self.setupUi(self)


if __name__ == '__main__':
    pmr = QApplication(sys.argv)
    myWin = NewWindow()
    myWin.show()
    sys.exit(pmr.exec_())
