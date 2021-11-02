/**
* How would you design a stack which, in addition to push and pop, 
* has a function min which returns the minimum element? 
* - Push, pop and min should all operate in 0(1) time. 
*/

#include <stack>
#include <iostream>

using namespace std;

class MinStack {
    private:
        stack<int> data_stack;
        stack<int> min_stack;

	public:
		MinStack() {
		}
		
		void push(int x) {
			data_stack.push(x);
            // check if the input smaller than the min_top
            if (min_stack.empty() || x <= min_stack.top()) {
				min_stack.push(x);
			}
		}
		
		void pop() {
			if (data_stack.top() == min_stack.top()) {
				min_stack.pop();
			}
			data_stack.pop();
		}
		
		int top() {
			return data_stack.top();
		}
		
		int getMin() {
			return min_stack.top();
		}
};


// main
int main() {
	MinStack minStack = MinStack();
	minStack.push(4);
	minStack.push(8);
	cout << minStack.getMin() << endl;
	cout << minStack.top() << endl;
	minStack.push(3);
	minStack.push(2);
	cout << minStack.getMin() << endl;
	minStack.pop();
	cout << minStack.getMin() << endl;

	return 0;
}