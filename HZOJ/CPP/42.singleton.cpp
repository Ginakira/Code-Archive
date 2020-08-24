/************************************************************
    File Name : 42.singleton.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/22 16:08:15
************************************************************/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <mutex>
#include <string>
#include <vector>
using namespace std;

// // 懒汉模式
// class Singleton {
//    public:
//     static Singleton *getInstance() {
//         if (single == nullptr) {
//             single = new Singleton();
//         }
//         return single;
//     }

//    private:
//     static Singleton *single;
//     Singleton() = default;
//     Singleton(const Singleton &) = default;
//     ~Singleton() { delete single; }
// };

// Singleton *Singleton::single = nullptr;

// // 饿汉模式
// class SingletonHungry {
//    public:
//     static SingletonHungry *getInstance() { return single; }

//    private:
//     static SingletonHungry *single;
//     SingletonHungry() = default;
//     SingletonHungry(const SingletonHungry &) = default;
//     ~SingletonHungry() { delete single; }
// };

// SingletonHungry *SingletonHungry::single = new SingletonHungry();

// // 加锁的懒汉模式
// class Singleton {
//    public:
//     static Singleton *getInstance() {
//         std::unique_lock<mutex> lock(m_mutex);
//         if (single == nullptr) {
//             single = new Singleton();
//         }
//         return single;
//     }

//    private:
//     static Singleton *single;
//     static std::mutex m_mutex;
//     Singleton() = default;
//     Singleton(const Singleton &) = default;
//     ~Singleton() { delete single; }
// };

// Singleton *Singleton::single = nullptr;
// std::mutex Singleton::m_mutex;

// 双重判断加锁的懒汉模式(终极版本)
class Singleton {
   public:
    static Singleton *getInstance() {
        if (single == nullptr) {
            std::unique_lock<mutex> lock(m_mutex);
            if (single == nullptr) {
                single = new Singleton();
            }
        }
        return single;
    }

   private:
    static Singleton *single;
    static std::mutex m_mutex;
    Singleton() = default;
    Singleton(const Singleton &) = default;
    ~Singleton() { delete single; }
};

Singleton *Singleton::single = nullptr;
std::mutex Singleton::m_mutex;

int main() {
    Singleton *p = Singleton::getInstance();
    return 0;
}