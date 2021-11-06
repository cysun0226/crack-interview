/** 
* Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double, 
* return the binary representation. 
* If the number cannot be represented accurately in binary with at most 32 characters, return "ERROR' 
*/

#include <string>
#include <iostream>

using namespace std;

string doubleToBinary(double n){
    if (n <= 0 || n >= 1)
        return "ERROR";

    // in binary with at most 32 characters

    // convert 2^(-n) to bits (1/0)
    string bstr = "";
    for (size_t i = 0; i < 30; i++){
        n = n * 2;

        if (n == 0)
            break;

        if (n >= 1){
            bstr += "1";
            n -= 1;
        }
            
        else
            bstr += "0";
    }

    if (n != 0)
        return "ERROR";

    return "0." + bstr;
}

int main() {
    double input = 0.625;

    // case 1
    cout << doubleToBinary(input) << endl;

    // case 2
    cout << doubleToBinary(0.6640625) << endl;

    return 0;
}
