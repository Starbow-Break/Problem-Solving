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
    vector<pii> desk(N);
    
    for(int i = 0; i < N; i++) {
        int a, b; cin >> a >> b;
        desk[i] = {a, b};
    }
    
    int maxS = 0, grade = 0;
    for(int i = 1; i <= 5; i++) {
        int cur = 0, maxCnt = 0;
        for(int j = 0; j < N; j++) {
            if(desk[j].fi == i || desk[j].se == i) cur++;
            else {
                maxCnt = max(maxCnt, cur);
                cur = 0;
            }
        }
        maxCnt = max(maxCnt, cur);
        
        if(maxS < maxCnt) {
            maxS = maxCnt; grade = i;
        }
    }
    
    cout << maxS << ' ' << grade;
    
    return 0;
}