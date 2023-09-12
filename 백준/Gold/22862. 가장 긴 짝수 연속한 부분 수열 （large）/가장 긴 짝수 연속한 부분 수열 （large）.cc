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

int arr[1000000];
vector<int> vec;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        arr[i] %= 2;
        arr[i] = 1-arr[i];
    }
    
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(arr[i]) {
            if(cnt < 0) {
                vec.pb(cnt);
                cnt = 0;
            }
            cnt++;
        }
        else {
            if(cnt > 0) {
                vec.pb(cnt);
                cnt = 0;
            }
            cnt--;
        }
    }
    vec.pb(cnt);
    
    int i = 0, j = 0;
    int ans = 0;
    int cur = 0, cost = 0;
    
    if(vec[0] > 0) {
        cur += vec[0];
    }
    else {
        cost += -vec[0];
    }
    
    ans = max(ans, cur);
    while(true) {
        if(cost <= K) {
            j++;
            if(j >= vec.size()) break;
            
            if(vec[j] > 0) {
                cur += vec[j];
            }
            else {
                cost += -vec[j];
            }
        }
        else {
            if(vec[i] > 0) {
                cur -= vec[i];
            }
            else {
                cost -= -vec[i];
            }
            i++;
        }
        ans = max(ans, cur);
    }
    
    
    cout << ans;
    return 0;
}