import sys
from PyQt5.QtWidgets import QApplication, QWidget, QPushButton, QMessageBox, QLineEdit
from PyQt5.QtGui import QIcon
from random import randint


class Example(QWidget):
    def __init__(self):
        super().__init__()
        self.gui()
        self.num = randint(1, 100)

    def gui(self):
        self.setGeometry(300, 300, 300, 220)
        self.setWindowTitle("PMR-猜数字")
        self.setWindowIcon(QIcon('favicon.ico'))

        self.bt1 = QPushButton('Guess', self)
        self.bt1.setGeometry(115, 150, 70, 30)
        self.bt1.setToolTip('<b>Press it guess.</b>')
        self.bt1.clicked.connect(self, showMessage)

        self.text = QLineEdit('Input number', self)
        self.text.selectAll()
        self.setFocus()
        self.text.setGeometry(80, 50, 150, 30)

        self.show()

    def showMessage(self):
        guessnumber = int(self.text.text())
        print(self.num)

        if guessnumber > self.num:
            QMessageBox.about(self, 'Guess', 'Too Big!')
            self.text.setFocus()
        elif guessnumber < self.num:
            QMessageBox.about(self, 'Guess', 'Too Samll!')
            self.text.setFocus()
        else:
            QMessageBox.about(self, 'Congratulations', 'Right! Next ')
            self.num = randint(1, 100)
            self.text.clear()
            self.text.setFocus()

    def closeEvent(self, event):
        reply = QMessageBox.question(self, 'Confirm', 'Exit?', QMessageBox.Yes | QMessageBox.No, QMessageBox.No)
        if reply == QMessageBox.Yes:
            event.accept()
        else:
            event.ignore()


if __name__ == '__main__':

    app = QApplication(sys.argv)
    ex = Example()
    sys.exit(app.exec_())