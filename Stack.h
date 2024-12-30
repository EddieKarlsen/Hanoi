#ifndef STACK_H 
#define STACK_H

#include <iostream>

class Stack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* top;

public:
    Stack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Pinnen är tom!" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Pinnen är tom!" << std::endl;
            return -1;
        }
        return top->data;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

};

#endif
