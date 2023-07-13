#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    bool ans = false;
    
    ll k; cin >> k; k--;
    ll w = 1LL << 60;
    
    while(w >= 1) {
        if(k/w == 1 || k/w == 2) {
            ans = !ans;
        }
        k %= w; w /= 4;
    }
    
    cout << ans;

    return 0;
}