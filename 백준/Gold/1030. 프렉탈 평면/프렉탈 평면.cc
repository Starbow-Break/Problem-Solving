#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MOD 998244353

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int s, N, K, R1, R2, C1, C2;

bool check(int r, int c) {
    int len = pow(N, s-1);
    
    while(len >= 1) {
        int left = 0, right = N-1;
        while(right-left+1 > K) { left++; right--; }
        
        if(left <= r/len && r/len <= right) {
            if(left <= c/len && c/len <= right) {
                return true;
            }
        }
        
        r %= len; c %= len; len /= N;
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> s >> N >> K >> R1 >> R2 >> C1 >> C2;
    
    for(int r = R1; r <= R2; r++) {
        for(int c = C1; c <= C2; c++) {
            cout << check(r, c);
        }
        cout << '\n';
    }

    return 0;
}