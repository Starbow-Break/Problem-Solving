#include <bits/stdc++.h>
#define repeat(i, s, e) for(int i = s; i < e; i++)
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
    
    int N, K; cin >> N >> K;
    vector<int> cards;
    
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        cards.push_back(v);
    }
    
    sort(cards.begin(), cards.end());
    
    int ans = -K*(K-1)/2;
    for(int i = 0; i < K; i++) {
        ans += cards[cards.size()-1-i];
    }
    cout << ans;
    
    return 0;
}