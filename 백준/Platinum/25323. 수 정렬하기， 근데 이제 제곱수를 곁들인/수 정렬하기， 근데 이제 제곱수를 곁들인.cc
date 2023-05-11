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
typedef __int128_t int128;

vector<ll> vec, sortedVec;

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

bool check(ll a, ll b) {
    ll g = gcd(a, b);
    return sqrt(a/g) == floor(sqrt(a/g)) && sqrt(b/g) == floor(sqrt(b/g));
}

bool solve(int N) {
    for(int i = 0; i < N; i++) {
        ll v; cin >> v;
        vec.push_back(v);
        sortedVec.push_back(v);
    }
    sort(sortedVec.begin(), sortedVec.end());
    
    for(int i = 0; i < N; i++) {
        if(!check(vec[i], sortedVec[i])) return false;
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    cout << (solve(N) ? "YES" : "NO");

    return 0;
}