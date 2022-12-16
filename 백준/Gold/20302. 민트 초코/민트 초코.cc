#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int A[100001] = {0, };
int B[100001] = {0, };

vector<int> primes;
bool isPrime[320];

void getPrimes() {
    fill(isPrime+2, isPrime+320, true);
    for(int i = 2; i < 320; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i*2; j < 320; j += i) { isPrime[j] = false; }
        }
    }
}

void primeFact(int value, bool b) {
    if(b) {
        for(auto &p: primes) {
            while(!(value%p)) {
                value /= p;
                B[p]++;
            }
        }
        
        if(value > 1) { B[value]++; }
    }
    else {
        for(auto &p: primes) {
            while(!(value%p)) {
                value /= p;
                A[p]++;
            }
        }
        
        if(value > 1) { A[value]++; }
    }
}

bool check() {
    for(int i = 2; i <= 100000; i++) {
        if(A[i] < B[i]) return false;
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrimes();
    
    int N; cin >> N;
    
    bool flag = false;
    for(int i = 1; i <= N; i++) {
        if(i == 1) {
            int value; cin >> value;
            value = abs(value);
            
            if(value == 0) { flag = true; break; }
            
            primeFact(value, false);
        }
        else {
            char op; cin >> op;
            int value; cin >> value;
            value = abs(value);
            
            if(value == 0) { flag = true; break; }
            
            primeFact(value, op == '/');
        }
    }
    
    cout << (check() || flag ? "mint chocolate" : "toothpaste");

    return 0;
}