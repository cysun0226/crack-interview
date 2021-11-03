/**
* Implement a data structure SetOfStacks composed of several stacks and
* creates a new stack once the previous one exceeds capacity. 
* SetOfStacks. push () and SetOfStacks. pop () should behave identically to a single stack
* (that is, pop ( ) should return the same values as it would if there were just a single stack).
* FOLLOW UP:  Implement a function popAt (int index) which performs a pop operation on a specific sub-stack. 
* https://leetcode.com/problems/dinner-plate-stacks/
*/

#include <iostream>
#include <stack>
#include <vector>
// #include <algorithm>
using namespace std;

class SetOfStacks {
    private:
        vector<stack<int> > stack_set;
        int threshold;
        vector<int> avail_stack; // record the non-empty stacks

	public:
		/** Initialize Your Data Structure Here */
		SetOfStacks(int thres) {
			threshold = thres;
            stack_set.push_back(stack<int>()); // init stack
		}
		
		void push(int x) {
            int push_idx = (avail_stack.empty()) ? stack_set.size()-1 : -avail_stack.front();
            
            stack_set[push_idx].push(x);

            if (stack_set[push_idx].size() >= threshold){
                // update the avail_stack
                if (!avail_stack.empty()){
                    pop_heap(avail_stack.begin(), avail_stack.end());
                    avail_stack.pop_back();
                }
                    
                // all is full, create a new stack
                else{
                    stack_set.push_back(stack<int>());
                }
            }            
		}
		
		int pop() {
            if (stack_set.empty()) {
                return -1;
            }

            while (stack_set.back().empty()) {
                stack_set.pop_back();
            }

            int pop_value = stack_set.back().top();
            stack_set.back().pop();
			if (stack_set.back().empty()) {
                stack_set.pop_back();
            }
            
            return pop_value;
		}
		
		int popAt(int index) {
            if (index >= stack_set.size()){
                return -1;
            }
            if (stack_set.at(index).empty()){
                return -1;
            }

			int pop_value = stack_set.at(index).top();
            stack_set.at(index).pop();

            // update avail_stack
            avail_stack.push_back(-index);
            push_heap(avail_stack.begin(), avail_stack.end());

            return pop_value;
		}
};

int main() {
    // algo moon case
    // SetOfStacks setOfStacks = SetOfStacks(2);
    // setOfStacks.push(4);
    // setOfStacks.push(5);
    // cout << setOfStacks.pop() << endl;   
    // setOfStacks.push(3);
    // setOfStacks.push(8);
    // setOfStacks.push(2);
    // cout << setOfStacks.popAt(0) << endl;
    // setOfStacks.push(10);
    // cout << setOfStacks.popAt(0) << endl;
    // cout << setOfStacks.pop() << endl;

    // leetcode 1
    SetOfStacks setOfStacks = SetOfStacks(2);
    for(int i = 1; i < 6; i++) {
        setOfStacks.push(i);
    }
    cout << setOfStacks.popAt(0) << endl;
    setOfStacks.push(20);
    setOfStacks.push(21);
    cout << setOfStacks.popAt(0) << endl;
    cout << setOfStacks.popAt(2) << endl;
    for(int i = 1; i < 6; i++) {
        cout << setOfStacks.pop() << endl;
    }

    return 0;
}