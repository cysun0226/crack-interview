/**
* How would you design a stack which, in addition to push and pop, 
* has a function min which returns the minimum element? 
* - Push, pop and min should all operate in 0(1) time. 
*/

#include <vector>
#include <iostream>

using namespace std;

class MinStack {
    private:
        vector<int> data_stack;
        vector<int> min_stack;

	public:
		MinStack() {
		}
		
		void push(int x) {
            data_stack.push_back(x);
            // check if the input smaller than the min_top
            if (min_stack.size() == 0 || x < min_stack.back()) {
				min_stack.push_back(x);
			}
		}
		
		void pop() {
			// int pop_value = data_stack.back();
			if (data_stack.back() == min_stack.back()) {
				min_stack.pop_back();
			}
			data_stack.pop_back();
		}
		
		int top() {
			return data_stack.back();
		}
		
		int getMin() {
			return min_stack.back();
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