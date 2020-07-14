#!/usr/bin/env python
# coding=utf-8

class Student(object):
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def show(self):
        print("{} : {}".format(self.name, self.age))


stu1 = Student("Jack", 23)
stu2 = Student("Bob", 34)

stu1.show()
stu2.show()
