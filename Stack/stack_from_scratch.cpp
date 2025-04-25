#include <bits/stdc++.h>
using namespace std;

class Stack
{   
    int top;
    int* arr;
    int capacity=100;

    public:
        Stack(int limit){

            capacity=limit;
            arr=new int[capacity];
            top=-1;
        }
        void push(int val)
        {
            if(top> capacity-1)
            {
                cout<< "Stack Full";
                return;
                
            }
            arr[++top]=val;
            cout<<"Pushed: "<<arr[top]<<endl;
        }

        void pop()
        {
            if(top< 0)
            {
                cout<< "Stack Underflow";
                return;
            }
            cout<<"Popped: " << arr[top]<<endl;
            top--;
        }

        void peek()
        {
            if(top< 0)
            {
                cout<< "Stack is Empty";
                return;
            }
            cout<<"Peeked: " << arr[top]<<endl;
        }

        bool isEmpty(){
            return top==-1;
        }

        int size(){
            return capacity;
        }

};

int main() {

    Stack s(200);
    s.push(5);
    s.push(10);
    s.peek();
    s.pop();
    bool empty=s.isEmpty();
    cout<<empty<<endl;
    int size=s.size();
    cout<<size<<endl;

    return 0;
}