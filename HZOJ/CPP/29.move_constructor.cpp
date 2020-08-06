/************************************************************
    File Name : 29.move_constructor.cpp
    Author: Ginakira
    Mail: ginakira@outlook.com
    Github: https://github.com/Ginakira
    Created Time: 2020/08/06 09:40:54
************************************************************/
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

namespace haizei {
class string {
   public:
    string() {
        cout << "string : default constructor, " << this << endl;
        this->__buff_size = 10;
        this->buff = new char[this->__buff_size];
        this->__length = 0;
    }

    string(const char *str) {
        cout << "string : const char constructor, " << this << endl;
        this->__buff_size = strlen(str) + 1;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, str);
        this->__length = this->__buff_size - 1;
    }

    string(const string &s)
        : __length(s.__length), __buff_size(s.__buff_size), __end(s.__end) {
        cout << "string : copy constructor, " << this << endl;
        this->buff = new char[this->__buff_size];
        strncpy(this->buff, s.buff, s.__length);
    }

    string(string &&s)
        : __length(s.__length), __buff_size(s.__buff_size), __end(s.__end) {
        cout << "string : move constructor, " << this << endl;
        this->buff = s.buff;
        s.buff = nullptr;
    }

    char &at(int ind) {
        if (ind < 0 || ind >= __length) {
            cout << "String Error : out of range" << endl;
            return __end;
        }
        return this->operator[](ind);
    }

    char &operator[](int ind) { return buff[ind]; }

    char *c_str() const { return buff; }

    string operator+(const string &s) {
        cout << "string : operator +, " << this << endl;
        int size = this->__length + s.__length + 1;
        char *temp = new char[size];
        strcpy(temp, this->buff);
        strcat(temp, s.buff);
        return temp;
    }

    int size() { return this->__length; }

    ~string() {
        cout << "string : destructor, " << this << endl;
        if (this->buff) {
            delete this->buff;
        }
    }

   private:
    int __length, __buff_size;
    char *buff;
    char __end;
};
}  // namespace haizei

ostream &operator<<(ostream &out, const haizei::string &s) {
    out << s.c_str();
    return out;
}

int main() {
    haizei::string s1 = "Hello world", s2 = ", haizei", s3 = ", harbin.";
    cout << "==== s4 begin ====" << endl;
    haizei::string s4 = s1 + s2 + s3;
    cout << s4 << endl;
    cout << "==== s4 end ====" << endl;
    haizei::string s5 = s4;
    cout << "s4 : " << s4 << endl;
    s5[3] = '+';
    cout << "s5 : " << s5 << endl;
    cout << "s4(after)" << s4 << endl;

    cout << s1 << endl;
    s1[3] = '6';
    cout << s1 << endl;
    cout << s1 + s2 + s3 << endl;
    for (int i = 0; i < s1.size(); ++i) {
        cout << s1[i] << endl;
    }
    return 0;
}