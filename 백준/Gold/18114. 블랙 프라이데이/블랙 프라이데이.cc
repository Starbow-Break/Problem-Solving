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
    
    bool check = false;
    int N, C; cin >> N >> C;
    vector<int> weight(N);
    FOR(i, 0, N) cin >> weight[i];
    
    sort(all(weight));
    
    for(int i = 0; i < N && !check; i++) {
        if(weight[i] == C) {
            check = true;
            continue;
        }
        
        for(int j = i+1; j < N; j++) {
            if(weight[i]+weight[j] == C) {
                check = true;
                continue;
            }
        }
        
        int l = i+1, r = N-1;
        while(l < r) {
            if(weight[i]+weight[l]+weight[r] < C) l++;
            else if(weight[i]+weight[l]+weight[r] > C) r--;
            else { check = true; break; }
        }
    }
    
    cout << check;
    
    return 0;
}