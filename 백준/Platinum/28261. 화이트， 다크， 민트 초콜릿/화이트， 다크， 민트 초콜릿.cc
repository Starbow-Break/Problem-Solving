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

string taste = "WDM";

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    string s; cin >> s;
    
    // W == 0, D == 1, M == 2
    int top_taste = 0;
    int w[N], v[N];
    
    for(int i = 0; i < N; i++) {
        if(s[i] == 'W') v[i] = 0;
        else if(s[i] == 'D') v[i] = 1;
        else v[i] = 2;
    }
    
    w[0] = 1;
    int r = 1, cnt = 0;
    for(int i = 1; i < N; i++) {
        int a = N-i, b = i;
        while(a%3 == 0) {
            cnt++; a /= 3;
        }
        while(b%3 == 0) {
            cnt--; b /= 3;
        }
        r *= (1LL*a*b)%3; r %= 3;
        
        w[i] = (cnt ? 0 : r);
    }
    
    for(int i = 0; i < N; i++) {
        top_taste += w[i]*v[i];
        top_taste %= 3;
    }
    
    cout << taste[(N%2 ? top_taste : (3-top_taste)%3)] << '\n';
    
    int Q; cin >> Q;
    while(Q--) {
        int i; char c; cin >> i >> c;
        
        int newValue;
        if(c == 'W') newValue = 0;
        else if(c == 'D') newValue = 1;
        else newValue = 2;
        
        int delta = newValue-v[i-1];
        if(delta < 0) delta += 3;
        
        top_taste += w[i-1]*delta;
        top_taste %= 3;
        
        cout << taste[(N%2 ? top_taste : (3-top_taste)%3)] << '\n';
        v[i-1] = newValue;
    }
    
    return 0;
}
