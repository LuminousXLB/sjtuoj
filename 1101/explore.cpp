#include <iostream>

using namespace std;

const int __base__ = 10;

int digit_XOR(int a, int b) {
    return (a + b) % __base__;
}

int main(int argc, char const *argv[]) {
    cout << '\t';
    for (size_t i = 0; i < 11; i++) {
        cout << i << '\t';
    }
    cout << endl;

    for (size_t i = 0; i < 11; i++) {
        cout << i << '\t';
        for (size_t j = 0; j < 11; j++) {
            cout << digit_XOR(i, j) << '\t';
        }
        cout << endl;
    }

    cout << "===========" << endl;

    int sum = 0;
    for (size_t i = 0; i < 50; i++) {
        cout << sum;
        cout << " + " << i << " = \t" << (sum = digit_XOR(sum, i)) << endl;
    }

    return 0;
}
