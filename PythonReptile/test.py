class Test:
    def __init__ (self, name, age):
        self.name = name
        self.age = age

    def hello(self):
        print("Hello World!\n")

p = Test('xxbb', 124)
p.hello()
print(p.name)
print(p.age)