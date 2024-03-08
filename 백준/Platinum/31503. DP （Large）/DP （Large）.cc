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

int dp1[300'001];
int dp2[300'001];

vector<pii> d;
void lis1(vector<int> arr) {
    for(int i = 1; i <= arr.size(); i++) {
        if(d.size()) {
            int l = 0, r = d.size()-1;
            while(l <= r) {
                int mid = (l+r) >> 1;
                if(d[mid].fi < arr[i-1]) l = mid+1;
                else r = mid-1;
            }
            
            if(l == d.size()) {
                d.pb({arr[i-1], i});
            }
            else {
                d[l] = {arr[i-1], i};
            }
            
            dp1[i] = l+1;
        }
        else {
            d.pb({arr[i-1], i});
            dp1[i] = 1;
        }
    }
}

void lis2(vector<int> arr) {
    for(int i = 1; i <= arr.size(); i++) {
        if(d.size()) {
            int l = 0, r = d.size()-1;
            while(l <= r) {
                int mid = (l+r) >> 1;
                if(d[mid].fi < arr[i-1]) l = mid+1;
                else r = mid-1;
            }
            
            if(l == d.size()) {
                d.pb({arr[i-1], i});
            }
            else {
                d[l] = {arr[i-1], i};
            }
            
            dp2[arr.size()+1-i] = l+1;
        }
        else {
            d.pb({arr[i-1], i});
            dp2[arr.size()+1-i] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, Q; cin >> N >> Q;
    vector<int> arr(N);
    
    for(int i = 0; i < N; i++) cin >> arr[i];
    
    lis1(arr);
    
    reverse(arr.begin(), arr.end());
    
    for(int i = 0; i < N; i++) arr[i] *= -1;
    
    lis2(arr);
    
    while(Q--) {
        int v; cin >> v;
        cout << dp1[v]+dp2[v]-1 << '\n';
    }
    
    return 0;
}