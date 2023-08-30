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
    vector<int> A;
    
    repeat(N) {
        int v; cin >> v;
        A.pb(v);
    }
    
    sort(all(A));
    
    int i = 0, j = N-1;
    int ans = 1'000'000'000;
    while(i < j) {
        if(abs(ans) > abs(A[j]+A[i])) ans = A[j]+A[i];
        if(A[j]+A[i] > 0) j--;
        else i++;
    }
    
    cout << ans;
    
    return 0;
}