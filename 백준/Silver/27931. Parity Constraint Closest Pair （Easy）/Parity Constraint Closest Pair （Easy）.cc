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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    int minDist[2] = {2'100'000'000, 2'100'000'000};
    
    vector<int> pos(N);
    
    for(int i = 0; i < N; i++) cin >> pos[i];
    sort(all(pos));
    
    for(int i = 0; i < N; i++) {
        if(i+1 < N) {
            int d = pos[i+1] - pos[i];
            minDist[d%2] = min(minDist[d%2], d);
        }
        if(i+2 < N) {
            int d = pos[i+2] - pos[i];
            minDist[d%2] = min(minDist[d%2], d);
        }
    }
    
    for(int i = 0; i < 2; i++) {
        cout << (minDist[i] == 2'100'000'000 ? -1 : minDist[i]) << ' ';
    }
    
    return 0;
}
