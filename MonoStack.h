#ifndef MONOSTACK_H
#define MONOSTACK_H

#include <iostream>
using namespace std;

template <class T>
class MonoStack
{
public:
    MonoStack(){
        mSize = 64;
        top = -1;
        arr = new T[mSize];
        dir = 'i';
    } //Default constructor
    MonoStack(int maxSize, char o){
        mSize = maxSize;
        top = -1;
        arr = new T[mSize];
        if(tolower(o) == 'i' || tolower(o) == 'd'){
            dir = o;
        } else {
            throw runtime_error("Invalid direction");
        }
    } //Overloaded constructor
    ~MonoStack(){
        delete[] arr;
    } //Destructor
    void push(T newData){
        if (isFull()) {
            throw runtime_error("stack is full");
        }
        if (isEmpty()){
            arr[++top] = newData;
        }
        else{
            if(dir == 'i'){
                incPush(newData);
            } else {
                decPush(newData);
            }
        }
    } //Add object to stack
    T pop(){
        if (isEmpty()){
            throw runtime_error("stack is empty");
        } else {
            return arr[top--];
        }
    } //Remove object from stack and return it
    T peek(){
        if (isEmpty()){
            throw runtime_error("stack is empty");
        } else {
            return arr[top];
        }} //AKA top(), return top object without removing it
    int size(){
        return (top + 1);
    } //Return number of objects on stack
    bool isFull(){
        return (top == (mSize - 1));
    } //Check if stack is empty
    bool isEmpty(){
        return (top == -1);
    } //Check if stack is full
    

private:
    T* arr;
    int mSize;
    int top;
    char dir;
    void incPush(T data){
        while(peek() > data){
            pop();
            if(isEmpty()){
            arr[++top] = data;
            return;
        }
        }
        if(peek() != data){
            arr[++top] = data;
        }
    }
    void decPush(T data){
        while(peek() < data){
            pop();
            if(isEmpty()){
            arr[++top] = data;
            return;
        }
        }
        if(peek() != data){
            arr[++top] = data;
        }
    }
};

#endif