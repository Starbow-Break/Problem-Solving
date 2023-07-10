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

vector<int> quest;

int cnt(int value) {
    int ret = 0;
    for(int i = 0; i < 20; i++) {
        ret += ((value & (1<<i)) > 0);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, k; cin >> n >> m >> k;
    for(int i = 1; i <= m; i++) {
        int q = 0;
        for(int j = 0; j < k; j++) {
            int v; cin >> v;
            q |= 1<<(v-1);
        }
        quest.push_back(q);
    }
    
    int ans = 0;
    for(int s = 0; s < 1<<(2*n); s++) {
        if(cnt(s) == n) {
            int cur = 0;
            for(auto &q: quest) {
                cur += (q == (q & s));
            }
            ans = max(ans, cur);
        }
    }
    cout << ans;

    return 0;
}