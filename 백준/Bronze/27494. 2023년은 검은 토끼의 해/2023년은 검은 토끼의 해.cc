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
#define MOD 1'000'000'007

using namespace std;
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

ll powTen[19]; //pow10[i] = 10^i
int arr[4] = {2, 0, 2, 3};

ll solve(ll value, int p, int idx = 0) {
    if(idx == 4) return value+1;
    if(p < 0 && idx < 4) return 0;
    
    int q = value/powTen[p];
    if(q < arr[idx]) {
        return (solve(powTen[p]-1, p-1, idx)*q+solve(value-powTen[p]*q, p-1, idx))%MOD;
    }
    else if(q > arr[idx]) {
        return (solve(powTen[p]-1, p-1, idx)*(q-1)+solve(value-powTen[p]*q, p-1, idx)+solve(powTen[p]-1, p-1, idx+1))%MOD;
    }
    else {
        return (solve(powTen[p]-1, p-1, idx)*q+solve(value-powTen[p]*q, p-1, idx+1))%MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    powTen[0] = 1;
    for(int i = 1; i <= 18; i++) { powTen[i] = powTen[i-1]*10; }
    
    ll N; cin >> N;
    int p = 18;
    while(powTen[p] > N) p--;
    
    cout << solve(N, p);

    return 0;
}