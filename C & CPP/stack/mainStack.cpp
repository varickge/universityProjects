#include <iostream>
#include "Stack.h"

int main() {
    int stackSize = 5; // Adjust the stack size as needed
    Stack myStack(stackSize);

    std::cout << "Pushing elements onto the stack:" << std::endl;
    for (int i = 1; i <= stackSize; ++i) {
        if (myStack.push(static_cast<Type>(i))) {
            std::cout << "Pushed: " << i << std::endl;
        } else {
            std::cout << "Failed to push: " << i << std::endl;
        }
    }

    std::cout << "Popping elements from the stack:" << std::endl;
    for (int i = 0; i < stackSize; ++i) {
        Type poppedValue;
        if (myStack.pop(&poppedValue)) {
            std::cout << "Popped: " << poppedValue << std::endl;
        } else {
            std::cout << "Failed to pop. Stack is empty." << std::endl;
        }
    }

    return 0;
}
