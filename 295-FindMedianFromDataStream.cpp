//
// Created by wu on 2022/3/26.
//

#include "leetcode.h"

class MedianFinder {
public:
    priority_queue<int> qmax;
    priority_queue<int, vector<int>, greater<int>> qmin;
    MedianFinder() {
    }

    void addNum(int num) {
        if (qmax.empty() || num < qmax.top()) {
            qmax.push(num);
            if (qmax.size()>qmin.size()+1) {
                int tp = qmax.top();
                qmax.pop();
                qmin.push(tp);
            }
        } else {
            qmin.push(num);
            if (qmin.size()>qmax.size()+1) {
                int tp = qmin.top();
                qmin.pop();
                qmax.push(tp);
            }
        }
    }

    double findMedian() {
        if (qmin.size() == qmax.size())
            return (qmin.top()+qmax.top()) / 2.0;
        else if (qmin.size() < qmax.size())
            return qmax.top();
        else
            return qmin.top();
    }
};

int main(void) {
    MedianFinder tp;
    tp.addNum(1);
    tp.addNum(2);
    tp.addNum(3);
    cout << tp.findMedian();
}