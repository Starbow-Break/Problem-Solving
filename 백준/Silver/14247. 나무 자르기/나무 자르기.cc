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
    
    ll ans = 0;
    vector<int> vec;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int h; cin >> h; ans += h;
    }
    for(int i = 0; i < n; i++) {
        int a; cin >> a; vec.push_back(a);
    }
    
    sort(vec.begin(), vec.end());
    
    for(int i = 0; i < n; i++) {
        ans += 1LL*vec[i]*i;
    }
    
    cout << ans;

    return 0;
}