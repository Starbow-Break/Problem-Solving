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
    vector<int> vec(N);
    
    for(int i = 0; i < N; i++) cin >> vec[i];
    
    int i = 0, j = 0, ans = 0;
    while(j < N) {
        if(j+1 < N && vec[j] < vec[j+1]) j++;
        else {
            if(j+1 < N && vec[j] == vec[j+1]) {
                int t = j+1, p = j;
                int cur = 0;
                while(t < N && p >= i && vec[t] == vec[p]) {
                    cur += 2;
                    t++; p--;
                }
                
                ans = max(ans, cur);
                i = j = j+1;
            }
            else {
                int t = j+1, p = j-1;
                int cur = 1;
                while(t < N && p >= i && vec[t] == vec[p]) {
                    cur += 2;
                    t++; p--;
                }
                
                ans = max(ans, cur);
                i = j = j+1;
            }
        }
    }
    
    cout << ans;
    
    return 0;
}