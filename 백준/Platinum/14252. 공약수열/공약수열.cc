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

pii arr[7] = {
    {2184, 2200},
    {27830, 27846},
    {32214, 32230},
    {57860, 57876},
    {62244, 62260},
    {87890, 87906},
    {92274, 92290}
};

int gcd(int a, int b) {
    if(a < b) swap(a, b);
    return (b ? gcd(b, a%b) : a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<int> vec(N);
    
    for(int i = 0; i < N; i++) cin >> vec[i];
    
    sort(vec.begin(), vec.end());
    
    int ans = 0;
    for(int i = 1; i < N; i++) {
        int d = 0;
        for(int j = 0; j < 7; j++) {
            if(vec[i-1] == arr[j].fi && vec[i] == arr[j].se) {
                d = 2;
                break;
            }
        }
        if(!d) {
            d = gcd(vec[i-1], vec[i]) > 1;
        }
        
        ans += d;
    }
    
    cout << ans;
    
    return 0;
}
