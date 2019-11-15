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
    std::cout << "Expand successful.\n";
    return;
}

void Vector::insert(int index, int val) {
    if (index < 0 || index > length) {
        std::cout << "Insert failed! Index:" << index << std::endl;
        return;
    }
    if (length >= size) expand();
    for (int i = length; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = val;
    length++;
    std::cout << "Insert successful " << val << " at idnex " << index
              << std::endl;
    return;
}

int Vector::search(int val) {
    for (int i = 0; i < length; ++i) {
        if (data[i] == val) return i;
    }
    return -1;
}

int Vector::len() { return length; }

void Vector::delete_element(int index) {
    if (index < 0 || index >= length) {
        std::cout << "Delete failed! Index" << index << std::endl;
        return;
    }
    for (int i = index; i < length; ++i) {
        data[i] = data[i + 1];
    }
    length--;
    std::cout << "Delete successful:(index)" << index << std::endl;
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