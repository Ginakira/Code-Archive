#include <iostream>

template <class Type>
class Vector {
   private:
    Type size, length;
    Type *data;

   public:
    Vector();
    Vector(int size_num);
    void expand();
    void insert(int index, Type val);
    int search(Type val);
    void delete_element(int index);
    int len();
    void output();
};

template <class Type>
Vector<Type>::Vector() {
    size = 100;
    length = 0;
    data = (Type *)malloc(sizeof(Type) * size);
}

template <class Type>
Vector<Type>::Vector(int size_num) {
    size = size_num;
    length = 0;
    data = (Type *)malloc(sizeof(Type) * size);
}

template <class Type>
void Vector<Type>::expand() {
    size *= 2;
    data = (Type *)realloc(data, sizeof(Type) * size);
    std::cout << "Expand successful.\n";
    return;
}

template <class Type>
void Vector<Type>::insert(int index, Type val) {
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
    std::cout << "Insert successful " << val << " at index " << index
              << std::endl;
    return;
}

template <class Type>
int Vector<Type>::search(Type val) {
    for (int i = 0; i < length; ++i) {
        if (data[i] == val) return i;
    }
    return -1;
}

template <class Type>
int Vector<Type>::len() {
    return length;
}

template <class Type>
void Vector<Type>::delete_element(int index) {
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

template <class Type>
void Vector<Type>::output() {
    std::cout << "Output: [";
    for (int i = 0; i < length; ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << data[i];
    }
    std::cout << "]\n";
    return;
}