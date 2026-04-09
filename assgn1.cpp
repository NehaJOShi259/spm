#include <iostream>
using namespace std;

int main() {
    char str[] = "Hello World";

    cout << "Input string: " << str << endl;

    cout << "XOR with 127: ";
    for (int i = 0; str[i] != '\0'; i++) {
        cout << (char)(str[i] ^ 127);
    }
    cout << endl;

    cout << "AND with 127: ";
    for (int i = 0; str[i] != '\0'; i++) {
        cout << (char)(str[i] & 127);
    }
    cout << endl;

    return 0;
}