/**
* Summation of: 1 + 2 + 3 + ... + N
*/

#include <iostream>

using namespace std;

int sum_up(int n) {
    if (n == 1)
        return 1;
    
    return n + sum_up(n-1);
}

// advanced solution
inline int n_sum(int n) {
    return ((n+1)*n)/2;
}

int main() {
    cout << n_sum(10) << endl;
}