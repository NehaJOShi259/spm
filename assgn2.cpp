#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to encrypt using Transposition Cipher
string encrypt(string plaintext, int key) {
    vector<string> rows(key);
    for (int i = 0; i < plaintext.length(); i++) {
        rows[i % key] += plaintext[i];
    }
    string ciphertext = "";
    for (int i = 0; i < key; i++) {
        ciphertext += rows[i];
    }
    return ciphertext;
}

// Function to decrypt using Transposition Cipher
string decrypt(string ciphertext, int key) {
    int n = ciphertext.length();
    int baseLen = n / key;
    int extra = n % key;
    vector<int> colLen(key, baseLen);
    for (int i = 0; i < extra; i++) colLen[i]++;

    vector<string> cols(key);
    int index = 0;
    for (int i = 0; i < key; i++) {
        cols[i] = ciphertext.substr(index, colLen[i]);
        index += colLen[i];
    }

    string plaintext = "";
    for (int i = 0; i < baseLen + 1; i++) {
        for (int j = 0; j < key; j++) {
            if (i < cols[j].length())
                plaintext += cols[j][i];
        }
    }
    return plaintext;
}

int main() {
    string message;
    int key;

    cout << "Enter the message: ";
    getline(cin, message);
    cout << "Enter the key (number of columns): ";
    cin >> key;

    string encrypted = encrypt(message, key);
    cout << "Encrypted text: " << encrypted << endl;

    string decrypted = decrypt(encrypted, key);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}