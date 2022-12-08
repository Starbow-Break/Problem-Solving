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

vector<int> palindrome;
vector<int> primes;

bool isPrime[10001];
void getPrime() {
    fill(isPrime+2, isPrime+10001, true);
    for(int i = 2; i <= 10000; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j = i*2; j <= 10000; j += i) { isPrime[j] = false; }
        }
    }
}

bool check(int N, int w) {
    if(N == 0) return true;
    
    if(N/w == N%10) {
        return check(N%w/10, w/100);
    }
    
    return false;
}

void getPalindrome() {
    int w = 1;
    for(int i = 0; i <= 100000000; i++) {
        if(i/w >= 10) { w *= 10; }
        
        if(i%2 && check(i, w)) {
            palindrome.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPalindrome();
    getPrime();
    
    int a, b; cin >> a >> b;
    for(auto &p: palindrome) {
        if(a > p || p > b) continue;
        
        bool flag = true;
        for(auto &pp: primes) {
            if(p <= pp) break;
            
            if(!(p%pp)) {
                flag = false; break;
            }
        }
        
        if(flag) cout << p << '\n';
    }
    
    cout << -1;

    return 0;
}