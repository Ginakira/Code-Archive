#include "Vector.h"
#include <iostream>

Vector::Vector() {
    size = 100;
    length = 0;
    data = (int *)malloc(sizeof(int) * size);
}

Vector::Vector(int size_num) {
    size = size_num;
    length = 0;
    data = (int *)malloc(sizeof(int) * size);
}

void Vector::expand() {
    size *= 2;
    data = (int *)realloc(data, sizeof(int) * size);
    return;
}

void Vector::insert(int index, int val) {
    if (index < 0 || index > length) return;
    if (length >= size) expand();
    for (int i = length; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = val;
    return;
}

int Vector::search(int val) {
    for (int i = 0; i < length; ++i) {
        if (data[i] == val) return i;
    }
    return -1;
}

void Vector::delete_element(int index) {
    if (index < 0 || index >= length) return;
    for (int i = index; i < length; ++i) {
        data[i] = data[i + 1];
    }
    return;
}

void Vector::output() {
    std::cout << "Output: [";
    for (int i = 0; i < length; ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << data[i];
    }
    std::cout << "]\n";
    return;
}