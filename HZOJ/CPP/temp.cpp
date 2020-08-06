/*************************************************************************
        > File Name: 28.move_constructor.cpp
        > Author: huguang
        > Mail: hug@haizeix.com
        > Created Time: 四  8/ 6 09:40:35 2020
 ************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
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
    string(const string &s) {
        cout << "copy constructor, " << this << endl;
        this->__buff_size = s.__buff_size;
        this->__length = s.__length;
        this->buff = new char[this->__buff_size];
        strcpy(this->buff, s.buff);
    }
    string(string &&s) {
        cout << "move constructor, " << this << endl;
        this->__buff_size = s.__buff_size;
        this->__length = s.__length;
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
    const char *c_str() const { return buff; }
    string operator+(const string &s) {
        cout << "string : operator+, " << this << endl;
        int size = this->__length + s.__length + 1;
        char *temp = new char[size];
        strcpy(temp, this->buff);
        strcat(temp, s.buff);
        return temp;
    }
    int size() { return this->__length; }
    ~string() {
        cout << "string : destructor, " << this << endl;
        if (this->buff) delete this->buff;
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
    haizei::string s1 = "hello world", s2 = ", haizei", s3 = ", harbin.";
    cout << "==== s4 begin ====" << endl;
    haizei::string s4 = s1 + s2 + s3;
    cout << "==== s4 end ====" << endl;
    cout << s1 << endl;
    haizei::string s5 = s4;
    cout << s4 << endl;
    cout << s5 << endl;
    s4[3] = '=';
    cout << s4 << endl;
    cout << s5 << endl;
    s1[3] = '6';
    cout << s1 << endl;
    cout << s1 + s2 + s3 << endl;
    for (int i = 0; i < s1.size(); i++) {
        cout << s1[i] << endl;
    }
    return 0;
}
