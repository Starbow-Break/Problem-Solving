#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

bool isPrime[1000001];
ll solve(int N) {
    ll ret = 0;
    fill(isPrime+2, isPrime+N+1, true);
    for(int i = 2; i <= N; i++) {
        if(isPrime[i]) {
            for(int j = i; j <= N; j += i) {
                if(isPrime[j]) {
                    isPrime[j] = false;
                    ret += i;
                }
            }
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    cout << solve(N);

    return 0;
}