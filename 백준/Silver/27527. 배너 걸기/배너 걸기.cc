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
    
    int N, M; cin >> N >> M;
    vector<int> h(N);
    
    for(int i = 0; i < N; i++) cin >> h[i];
    
    int cnt[1'000'001] = {0, };
    int i = 0, j = -1;
    
    bool check = false;
    int target = M*9/10+(M*9%10 > 0);
    
    while(j < M-1) {
        cnt[h[++j]]++;
        if(cnt[h[j]] >= target) check = true;
    }
    
    while(j < N-1) {
        cnt[h[++j]]++; cnt[h[i++]]--;
        if(cnt[h[j]] >= target) check = true;
    }
    
    cout << (check ? "YES" : "NO");
    
    return 0;
}
