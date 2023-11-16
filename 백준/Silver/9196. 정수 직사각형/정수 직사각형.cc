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

vector<pii> vec;

bool cmp(pii a, pii b) {
    int da = a.fi*a.fi+a.se*a.se;
    int db = b.fi*b.fi+b.se*b.se;
    
    if(da != db) return da < db;
    return a.fi < b.fi;
}

int find(int h, int w) {
    int i = 0, j = vec.size()-1;
    while(i <= j) {
        int mid = i+j >> 1;
        if(vec[mid] == make_pair(h, w)) return mid;
        else if(cmp(vec[mid], make_pair(h, w))) i = mid+1;
        else j = mid-1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 1; i <= 200; i++) {
        for(int j = i+1; j <= 200; j++) {
            vec.pb({i, j});
        }
    }
    
    sort(all(vec), cmp);
    
    int h, w;
    while(cin >> h >> w) {
        if(!h && !w) break;
        int idx = find(h, w);
        cout << vec[idx+1].first << ' ' << vec[idx+1].second << '\n';
    }
    
    return 0;
}
