#!/usr/bin/env python
# coding=utf-8

# 多态

# 父类/基类
class Animal(object):
    def __init__(self, name):
        self.name = name

    def say(self):
        print("{} is an Animal, it can say!".format(self.name))


# 子类/派生类
class Cat(Animal):
    def say(self):
        print("{} is a Cat, it can meow!!".format(self.name))


class Dog(Animal):
    def say(self):
        print("{} is a Dog, it can bark!!!".format(self.name))


# 动物叫的方法
def Animal_say(animal):
    animal.say()


Animal_say(Animal("unknown"))
Animal_say(Dog("berk"))
Animal_say(Cat("moew"))
