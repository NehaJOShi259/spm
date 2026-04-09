#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// Simplified demonstration DES-like encryption (not full DES)
uint64_t simpleDES(uint64_t plaintext, uint64_t key) {
    // XOR with key
    return plaintext ^ key;
}

int main() {
    uint64_t plaintext, key;

    cout << "Enter 64-bit plaintext (as number): ";
    cin >> plaintext;
    cout << "Enter 64-bit key (as number): ";
    cin >> key;

    uint64_t encrypted = simpleDES(plaintext, key);
    cout << "Encrypted text: " << bitset<64>(encrypted) << endl;

    uint64_t decrypted = simpleDES(encrypted, key); // XOR again for decryption
    cout << "Decrypted text: " << bitset<64>(decrypted) << endl;

    return 0;
}