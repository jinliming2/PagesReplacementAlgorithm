#pragma once
/**
 * 队列节点
 */
template <typename T>
struct QueueNode {
    T data;
    QueueNode<T>* pNext;
};

/**
 * 队列
 */
template <typename T>
class Queue {
public:
    //队列
    Queue();
    //析构函数
    ~Queue();
    //是否为空
    bool isEmpty() const;
    //队头节点
    T& getHead() const;
    //队尾节点
    T& getTail() const;
    //入队
    Queue<T>& enqueue(const T& node);
    //出队
    Queue<T>& dequeue();
    //出队
    Queue<T>& dequeue(T& node);
private:
    //头节点
    QueueNode<T>* head;
    //尾节点
    QueueNode<T>* tail;
};

//构造函数
template <typename T>
inline Queue<T>::Queue() {
    head = tail = new QueueNode<T>;
    head->pNext = nullptr;
}

//析构函数
template <typename T>
inline Queue<T>::~Queue() {
    while(!isEmpty()) {
        dequeue();
    }
    delete head;
}

//是否为空
template<typename T>
inline bool Queue<T>::isEmpty() const {
    return head->pNext == nullptr;
}

//队头节点
template<typename T>
inline T & Queue<T>::getHead() const {
    if(isEmpty()) {
        throw "Empty Queue!";
    } else {
        return head->pNext->data;
    }
}

//队尾节点
template<typename T>
inline T & Queue<T>::getTail() const {
    if(isEmpty()) {
        throw "Empty Queue!";
    } else {
        return tail->data;
    }
}

//入队
template<typename T>
inline Queue<T>& Queue<T>::enqueue(const T & node) {
    tail->pNext = new QueueNode<T>;
    tail = tail->pNext;
    tail->data = node;
    tail->pNext = nullptr;
    return *this;
}

//出队
template<typename T>
inline Queue<T>& Queue<T>::dequeue() {
    if(isEmpty()) {
        return *this;
    }
    QueueNode<T>* temp = head->pNext;
    head->pNext = temp->pNext;
    delete temp;
    return *this;
}

//出队
template<typename T>
inline Queue<T>& Queue<T>::dequeue(T & node) {
    if(isEmpty()) {
        return *this;
    }
    QueueNode<T>* temp = head->pNext;
    node = temp->data;
    head->pNext = temp->pNext;
    delete temp;
    return *this;
}
