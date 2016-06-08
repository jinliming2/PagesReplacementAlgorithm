#pragma once
#include <cstring>
template <typename T>
/**
 * 栈
 */
class Stack {
public:
    //栈
    Stack(const unsigned int size = 10, const unsigned int increase = 10);
    //析构函数
    ~Stack();
    //取容量
    unsigned int size() const;
    //是否为空
    bool isEmpty() const;
    //是否已满
    bool isFull() const;
    //取栈顶
    T& getTop() const;
    //取栈底
    T& getBottom() const;
    //入栈
    Stack<T>& push(const T& node);
    //出栈
    Stack<T>& pop();
    //出栈
    Stack<T>& pop(T& node);
    //清空
    Stack<T>& clear();
private:
    //栈地址
    T* stack;
    //顶部地址
    unsigned int top;
    //栈容量
    unsigned int max;
    //自动扩充大小
    unsigned int increase;
    //自动扩充
    void inc();
};

//构造函数
template <typename T>
inline Stack<T>::Stack(const unsigned int size, const unsigned int increase) {
    this->max = size;
    this->increase = increase;
    this->top = -1;
    this->stack = new T[max];
}

//析构函数
template <typename T>
inline Stack<T>::~Stack() {
    delete[] stack;
}

//取容量
template<typename T>
inline unsigned int Stack<T>::size() const {
    return max;
}

//是否为空
template<typename T>
inline bool Stack<T>::isEmpty() const {
    return top == -1;
}

//是否已满
template<typename T>
inline bool Stack<T>::isFull() const {
    return top == max - 1;
}

//取栈顶
template<typename T>
inline T & Stack<T>::getTop() const {
    if(isEmpty()) {
        throw "Empty Stack!";
    }
    return stack[top];
}

//取栈底
template<typename T>
inline T & Stack<T>::getBottom() const {
    if(isEmpty()) {
        throw "Empty Stack!";
    }
    return stack[0];
}

//入栈
template<typename T>
inline Stack<T>& Stack<T>::push(const T & node) {
    if(isFull()) {
        inc();
    }
    stack[++top] = node;
    return *this;
}

//出栈
template<typename T>
inline Stack<T>& Stack<T>::pop() {
    if(!isEmpty()) {
        top--;
    }
    return *this;
}

//出栈
template<typename T>
inline Stack<T>& Stack<T>::pop(T & node) {
    if(!isEmpty()) {
        node = stack[top--];
    }
    return *this;
}

//清空
template<typename T>
inline Stack<T>& Stack<T>::clear() {
    top = -1;
    return *this;
}

//自动扩充
template<typename T>
inline void Stack<T>::inc() {
    T* temp = new T[max + increase];
    memcpy(temp, stack, max * sizeof(T));
    delete[] stack;
    max += increase;
    stack = temp;
}
