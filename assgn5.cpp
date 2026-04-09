#include <iostream>
#include <cmath>
using namespace std;

// Function to compute gcd
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// Function to compute modular inverse
int modInverse(int e, int phi) {
    for (int i = 1; i < phi; i++) {
        if ((e * i) % phi == 1)
            return i;
    }
    return -1;
}

// Function to compute (base^exp) % mod
long long modExp(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

int main() {
    int p, q;
    cout << "Enter prime number p: ";
    cin >> p;
    cout << "Enter prime number q: ";
    cin >> q;

    int n = p * q;
    int phi = (p - 1) * (q - 1);

    int e;
    cout << "Choose e such that 1 < e < " << phi << " and gcd(e," << phi << ")=1: ";
    cin >> e;
    while (gcd(e, phi) != 1) {
        cout << "Invalid e. Enter again: ";
        cin >> e;
    }

    int d = modInverse(e, phi);
    cout << "Public key (n,e): (" << n << "," << e << ")" << endl;
    cout << "Private key (n,d): (" << n << "," << d << ")" << endl;

    int message;
    cout << "Enter message (as number < " << n << "): ";
    cin >> message;

    long long ciphertext = modExp(message, e, n);
    cout << "Encrypted message: " << ciphertext << endl;

    long long decrypted = modExp(ciphertext, d, n);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}