#include <iostream>

class MyStack {
    queue<int> que;
public:
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        return que.pop();
    }

    /** Get the top element. */
    int top() {
        return que.top();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

 int main()
 {
     int input[5] = {1, 2, 3, 4, 5};
     MyStack mystack = new MyStack;

     for(int i = 0; i < 5; i++) {
         mystack.push(input[i]);
     }

     std::cout << " " << mystack.top() << std::endl;
     std::cout << " " << mystack.pop() << std::endl;

     return 0;
 }