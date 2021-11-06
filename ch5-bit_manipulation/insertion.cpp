/*
* You are given two 32-bit numbers, N and M, and two bit positions, i and j. 
* Write a method to insert M into N such that M starts at bit j and ends at bit i. 
* You can assume that the bits j through i have enough space to fit all of M. 
* That is, if M = 10011, you can assume that there are at least 5 bits between j and i. 
* You would not, for example, have j = 3 and i = 2, because M could not fully fit between bit 3 and bit 2. 
*/

#include <iostream>

using namespace std;

int updateBits(int n, int m, int i, int j){
    // will `unsigned int` be better?
    int insert_m = m << i; 
    unsigned int clear_mask = UINT32_MAX; // or ~0
    int n_update = n;
    
    clear_mask = clear_mask << (j+1); // fill zeros
    for (size_t b = 0; b < i; b++) { // fill the postfix 1s
        clear_mask += 1 << b;
    } // or += ((i << i) - 1)

    n_update &= clear_mask;
    n_update += insert_m;

    return n_update;
}

int main() {
    int M, N, i, j;

    // case 1
    N = 0b1000000000, M = 0b11001;
    i = 2, j = 6;
    cout << updateBits(N, M, i, j) << endl;

    // case 2
    N = 0b100001, M = 0b111;
    i = 1, j = 3;
    cout << updateBits(N, M, i, j) << endl;

    // case 3
    N = 0b1111111111, M = 0b101;
    i = 6, j = 8;
    cout << updateBits(N, M, i, j) << endl;
    
    return 0;
}