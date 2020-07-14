#!/usr/bin/env python
# coding=utf-8


# 类的继承

# 父类(基类)
class Animal(object):
    def __init__(self, name):
        self.name = name

    def run(self):
        print("{} is running...".format(self.name))


# 子类（派生类）
class Cat(Animal):
    def __init__(self, name, color):
        # 调用父类构造方法
        super().__init__(name)
        self.color = color

    def show(self):
        print("name = {}, color = {}".format(self.name, self.color))


# 子类
class Dog(Animal):
    # 如果不显示声明子类的构造方法 则默认调用父类构造方法

    # 重写父类方法
    def run(self):
        print("{} is running quickly...!!".format(self.name))


cat = Cat("Meow", "white")
cat.run()
cat.show()

dog = Dog("Bark")
dog.run()
