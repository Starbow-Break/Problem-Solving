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
    
    int N; 
    while(cin >> N) {
        vector<int> p;
        while(N--) {
            int v; cin >> v;
            p.pb(v);
        }
        
        int arr[100000]; int ans = 0;
        for(auto &v: p) {
            if(ans == 0) {
                arr[ans] = v; ans++;
            }
            else {
                if(arr[ans-1] < v) {
                    arr[ans] = v; ans++;
                }
                else {
                    int i = 0, j = ans-1;
                    while(i <= j) {
                        int mid = i+j >> 1;
                        if(arr[mid] < v) i = mid+1;
                        else j = mid-1;
                    }
                    arr[i] = v;
                }
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}
