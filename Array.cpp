#include <iostream>

class Array {
public:
    Array(int* ptr, int size)
        : ptr(ptr)
        , size(size) {}

    ~Array() {
        delete[] ptr;
    }

    Array(const Array& other)
        : size(other.size) {
        ptr = new int[size];
        for (int i = 0; i < size; i++) {
            ptr[i] = other.ptr[i];
        }
    }

    Array& operator=(const Array& other) {
        if (this == &other) {
            return *this;
        }

        delete[] ptr;
        ptr = new int[other.size];
        size = other.size;
        for (int i = 0; i < size; i++) {
            ptr[i] = other.ptr[i];
        }

        return *this;
    }

    int& operator[](int index) {
        return ptr[index];
    }

    int gen_element(int);

    void push_back(int value) {
        int* temp = new int[size + 1];
        for (int i = 0; i < size; i++) {
            temp[i] = ptr[i];
        }
        temp[size] = value;
        delete[] ptr;
        ptr = temp;
        size++;
    }

    void pop_back() {
        if (size > 0) {
            int* temp = new int[size - 1];
            for (int i = 0; i < size - 1; i++) {
                temp[i] = ptr[i];
            }
            delete[] ptr;
            ptr = temp;
            size--;
        }
    }

private:
    int* ptr;
    int size;
};
