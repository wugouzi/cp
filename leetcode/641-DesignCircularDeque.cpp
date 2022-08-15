//
// Created by wu on 2022/8/15.
//
#include "leetcode.h"
class MyCircularDeque {
public:
    int head, tail, siz, msiz;
    vector<int> vec;
    MyCircularDeque(int k) {
        vec.resize(k);
        int head = 0, tail = 0, size = 0;
        int msiz = k;
    }

    bool insertFront(int value) {
        if (siz < msiz) {
            siz++;
            head = (head - 1 + msiz) % msiz;
            vec[head] = value;
            return true;
        }
        return false;
    }

    bool insertLast(int value) {
        if (siz < msiz) {
            siz++;
            vec[tail] = value;
            tail = (tail + 1) % msiz;
            return true;
        }
        return false;
    }

    bool deleteFront() {
        if (siz > 0) {
            siz--;
            head = (head + 1) % msiz;
            return true;
        }
        return false;
    }

    bool deleteLast() {
        if (siz > 0) {
            siz--;
            tail = (tail - 1 + msiz) % msiz;
            return true;
        }
        return false;
    }

    int getFront() {
        return vec[head];
    }

    int getRear() {
        return vec[(tail-1+msiz)%msiz];
    }

    bool isEmpty() {
        return siz == 0;
    }

    bool isFull() {
        return siz == msiz;
    }
};

int main(void) {
    MyCircularDeque myCircularDeque(3);
    myCircularDeque.insertLast(1);  // return True
    myCircularDeque.insertLast(2);  // return True
    myCircularDeque.insertFront(3); // return True
    myCircularDeque.insertFront(4); // return False, the queue is full.
    cout << myCircularDeque.getRear();      // return 2
    myCircularDeque.isFull();       // return True
    myCircularDeque.deleteLast();   // return True
    myCircularDeque.insertFront(4); // return True
    myCircularDeque.getFront();     // return 4

}
