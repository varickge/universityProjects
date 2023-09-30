#ifndef STACK_H
#define STACK_H

#include <iostream>

typedef double Type;


class Stack {
    private:
        Type* stackPtr;
        int size;
        int top;

        bool isEmpty() {
        return top == 0;
        }

        bool isFull() {
            return top == size;
        }
    
    public:
        Stack(int arrSize){
            size = arrSize;
            top = 0;
            stackPtr = new Type[size];
            // stackPtr[size] = new Type[size];
            std::cout << "In Construtor" << std::endl;
        }

        ~Stack(){
            delete[] stackPtr;
            std::cout << "In Destrutor" << std::endl;
        }

        bool push(Type newMember){
            if(isFull()){
                std::cout << "Stack is full." << std::endl;
                return 0;
            }

            stackPtr[top] = newMember;
            top++;
            return 1;
        }

        bool pop(Type* retPtr) {
            if (isEmpty()) {
                std::cout << "Stack is empty." << std::endl;
                return false;
            }

            top--;
            *retPtr = stackPtr[top];
            return true;
        }

};

#endif