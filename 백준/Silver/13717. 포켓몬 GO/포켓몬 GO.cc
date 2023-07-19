#include <bits/stdc++.h>

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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    string name = ""; int maxV = 0, tot = 0;
    
    while(N--) {
        string s; cin >> s;
        int k, m; cin >> k >> m;
        int cur = 0;
        while(k <= m) {
            cur++;
            m -= k; m += 2;
        }
        
        tot += cur;
        if(maxV < cur) {
            name = s; maxV = cur;
        }
    }
    
    cout << tot << '\n' << name;

    return 0;
}