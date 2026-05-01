#include <iostream>
using namespace std;

int main() {
    string text, pattern;
    cin >> text >> pattern;

    int n = text.size();
    int m = pattern.size();

    int pHash = 0, tHash = 0;
    int base = 31, mod = 1e9 + 7;
    int power = 1;


    for(int i = 0; i < m - 1; i++)
        power = (power * base) % mod;

    for(int i = 0; i < m; i++) {
        pHash = (pHash * base + pattern[i]) % mod;
        tHash = (tHash * base + text[i]) % mod;
    }

    for(int i = 0; i <= n - m; i++) {
        if(pHash == tHash) {

            if(text.substr(i, m) == pattern)
                cout << "Pattern found at index " << i << endl;
        }


        if(i < n - m) {
            tHash = (tHash - text[i] * power % mod + mod) % mod;
            tHash = (tHash * base + text[i + m]) % mod;
        }
    }

    return 0;
}
