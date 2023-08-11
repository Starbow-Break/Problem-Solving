#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

const ll MOD = 900528;
ll arr[1000000];

ll solve(string &s, string &strSet, int step = 0) {
    if(step == s.length()) return 0;
    
    int t;
    for(t = 0; t < strSet.length(); t++) {
        if(s[step] == strSet[t]) break;
    }
    
    return (arr[s.length()-1-step]*(t+1)%MOD+solve(s, strSet, step+1))%MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s, strSet; cin >> strSet >> s;
    arr[0] = 1;
    for(int i = 1; i <= s.length(); i++) {
        arr[i] = arr[i-1]*strSet.size();
        arr[i] %= MOD;
    }
    cout << solve(s, strSet);
    
    return 0;
}