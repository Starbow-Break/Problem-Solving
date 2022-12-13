#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

bool isPrime[1000001];

void getPrime() {
    fill(isPrime+2, isPrime+1000001, true);
    
    for(int i = 2; i <= 1000000; i++) {
        if(isPrime[i]) {
            for(int j = i*2; j <= 1000000; j += i) { isPrime[j] = false; }
        }
    }
}

ii getPrimePair(int value) {
    for(int i = 2; i <= value/2; i++) {
        if(isPrime[i] && isPrime[value-i]) {
            return {i, value-i};
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPrime();
    
    int N; cin >> N;
    if(N < 8) cout << -1;
    else {
        if(N%2) {
            ii p = getPrimePair(N-5);
            cout << "2 3 " << p.first << " " << p.second;
        }
        else {;
            ii p = getPrimePair(N-4);
            cout << "2 2 " << p.first << " " << p.second;
        }
    }

    return 0;
}