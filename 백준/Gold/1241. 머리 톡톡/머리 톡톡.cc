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

int cnt[1'000'001] = {0, };
int hitCnt[1'000'001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<int> vec(N);
    FOR(i, 0, N) { cin >> vec[i]; cnt[vec[i]]++; }
    FOR(i, 1, 1'000'001) {
        for(int j = i; j <= 1'000'000; j += i) {
            hitCnt[j] += cnt[i];
        }
    }
    
    for(auto &v: vec) {
        cout << hitCnt[v]-1 << '\n';
    }
    
    return 0;
}