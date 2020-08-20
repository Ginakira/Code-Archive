/************************************************************
    File Name : 39.visitor.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/20 10:48:08
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Cat;
class Dog;
class Mouse;
class Bat;

class Animal {
   public:
    class IVisitor {
       public:
        virtual void visit(Cat *) = 0;
        virtual void visit(Dog *) = 0;
        virtual void visit(Mouse *) = 0;
        virtual void visit(Bat *) = 0;
    };
    virtual void Accpet(IVisitor *) = 0;
    virtual ~Animal(){};
};

class Cat : public Animal {
   public:
    virtual void Accpet(IVisitor *vis) {
        vis->visit(this);
        return;
    }
};

class Dog : public Animal {
   public:
    virtual void Accpet(IVisitor *vis) {
        vis->visit(this);
        return;
    }
};

class Mouse : public Animal {
   public:
    virtual void Accpet(IVisitor *vis) {
        vis->visit(this);
        return;
    }
};

class Bat : public Animal {
   public:
    virtual void Accpet(IVisitor *vis) {
        vis->visit(this);
        return;
    }
};

class AnimalCout : public Animal::IVisitor {
   public:
    virtual void visit(Cat *obj) { cout << "this is cat" << endl; }
    virtual void visit(Dog *obj) { cout << "this is dog" << endl; }
    virtual void visit(Mouse *obj) { cout << "this is mouse" << endl; }
    virtual void visit(Bat *obj) { cout << "this is bat" << endl; }
};

int main() {
    srand(time(0));
    Animal *arr[10];
    for (int i = 0; i < 10; ++i) {
        switch (rand() % 4) {
            case 0:
                arr[i] = new Cat();
                break;
            case 1:
                arr[i] = new Dog();
                break;
            case 2:
                arr[i] = new Mouse();
                break;
            case 3:
                arr[i] = new Bat();
                break;
        }
    }

    /** 功能目标：根据对象原本的类型完成功能映射
     * 在中大型工程中：
     * 如果增加了一个子类，但可能忘写了对应子类的分支判断（功能的映射）。
     * 此时仍然可以通过编译，可以运行，但逻辑是不正确的。
     * 除此之外，如果使用这种方式做父类到子类的功能转换，平均要做n/2次分支预测
     *
     * 访问者模式就是为了解决这种需求的：根据父类指针指向对象的原本类型做功能映射
     * 1. 在父类中增加访问者的接口
     * 2. 在访问者接口添加纯虚函数visit
     *参数分别是各子类对象的指针。visit实现的就是对应的映射的功能逻辑
     * 3.
     *在访问者接口添加纯虚函数Accept。参数是IVisitor指针，在子类中重写这个方法，传入this
     * 4.
     *写一个继承自IVisitor的类，重写visit方法，在visit方法中实现具体映射出的功能逻辑
     * 5.
     *主函数定义一个这个继承自IVisitor类的对象，调用父类指针的Accept，将这个对象地址传进去
     *
     * 也就是，将一组功能逻辑转换为一个类。
     * 时间复杂度：O(1)
     **/
    // for (int i = 0; i < 10; ++i) {
    //     if (dynamic_cast<Cat *>(arr[i])) {
    //         cout << "this is a cat" << endl;
    //     } else if (dynamic_cast<Dog *>(arr[i])) {
    //         cout << "this is a dog" << endl;
    //     } else if (dynamic_cast<Mouse *>(arr[i])) {
    //         cout << "this is a mouse" << endl;
    //     } else if (dynamic_cast<Bat *>(arr[i])) {
    //         cout << "this is a bat" << endl;
    //     }
    // }

    AnimalCout vis;
    for (int i = 0; i < 10; ++i) {
        arr[i]->Accpet(&vis);
    }
    return 0;
}