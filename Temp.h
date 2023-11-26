#ifndef STACK_TEMPLATE
#define STACK_TEMPLATE

#include <iostream>
#include <exception>

template <class T>
class TStack {
    public:
        TStack() {
            size = 64;
            top = -1;
            array = new T[size];
        }

        TStack(int maxSize) {
            size = maxSize;
            top = -1;
            array = new T[size];
        }

        ~TStack() {
            std::cout << "garbage collection" << std::endl;
            delete[] array;
        }

        void push(T data) {
            if(isFull()) {
                throw std::runtime_error("Stack is full");
            }
            array[++top] = data;
        }

        T pop() {
            if(isEmpty()) {
                throw std::runtime_error("Stack is empty, nothing to pop");
            }
            return array[top--];
        }

        T peek() {
            return array[top];
        }

        int getSize() {
            return top + 1;
        }

        bool isFull() {
            return getSize() == size;
        }

        bool isEmpty() {
            return top == -1;
        }

    private:
        T *array;
        int size;
        int top;
};

#endif