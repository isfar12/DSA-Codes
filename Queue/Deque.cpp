#include<bits/stdc++.h>
using namespace std;

class Deque {
private:
    vector<int> data;

public:
    void pushFront(int val) {
        data.insert(data.begin(), val);
    }

    void pushBack(int val) {
        data.push_back(val);
    }

    void popFront() {
        if (!data.empty())
            data.erase(data.begin());
    }

    void popBack() {
        if (!data.empty())
            data.pop_back();
    }

    int front() const {
        return data.empty() ? -1 : data.front();
    }

    int back() const {
        return data.empty() ? -1 : data.back();
    }

    bool isEmpty() const {
        return data.empty();
    }

    int size() const {
        return data.size();
    }
};

int main() {
    Deque dq;
    dq.pushBack(10);
    dq.pushFront(20);
    dq.pushBack(30);
    cout << "Front: " << dq.front() << endl;
    cout << "Back: " << dq.back() <<endl;
    dq.popFront();
    dq.popBack();
    cout << "Size after pops: " << dq.size() << endl;
    return 0;
}