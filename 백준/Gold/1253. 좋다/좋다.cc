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

map<ll, int> mp;
vector<ll> numbers;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    repeat(N) {
        int v; cin >> v;
        numbers.pb(v);
        auto t = mp.find(v);
        if(t == mp.end()) {
            mp.insert({v, 1});
        }
        else {
            t->second++;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i != j) {
                auto t = mp.find(numbers[i]-numbers[j]);
                if(t != mp.end()) {
                    int cnt = t->second;
                    if(numbers[i]-numbers[j] == numbers[i]) cnt--;
                    if(numbers[i]-numbers[j] == numbers[j]) cnt--;
                    if(cnt > 0) { ans++; break;}
                }
            }
        }
    }
    
    cout << ans;
    
    return 0;
}