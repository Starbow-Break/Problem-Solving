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

const int INF = 1'000'000'000;

int solve(int l, int r, int status, vector<int> &vec) {
    int ret = 0;
    int sz = vec.size();
    for(int i = 0; i < sz; i++) {
        if(status & 1<<i) {
            if(r < vec[i]) {
                ret += vec[i]-r;
                r = vec[i];
            }
            if(r > vec[i]) {
                if(vec[i] <= l) return INF;
                else {
                    ret += r-vec[i];
                    r = vec[i];
                }
            }
        }
        else {
            if(l > vec[i]) {
                ret += l-vec[i];
                l = vec[i];
            }
            if(l < vec[i]) {
                if(vec[i] >= r) return INF;
                else {
                    ret += vec[i]-l;
                    l = vec[i];
                }
            }
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N; cin >> N;
    int arr[2]; cin >> arr[0] >> arr[1];
    if(arr[0] > arr[1]) swap(arr[0], arr[1]);
    
    int M; cin >> M;
    vector<int> vec(M);
    
    for(int i = 0; i < M; i++) cin >> vec[i];

    int ans = INF;
    for(int s = 0; s < 1<<M; s++) {
        ans = min(ans, solve(arr[0], arr[1], s, vec));
    }
    
    cout << ans;
    
    return 0;
}