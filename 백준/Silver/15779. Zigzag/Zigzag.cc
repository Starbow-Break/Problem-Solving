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
    vector<int> A(N);
    
    for(int i = 0; i < N; i++) cin >> A[i];
    
    int ans = 2, cur = 2;
    for(int i = 0; i <= N-3; i++) {
        if(A[i] < A[i+1] && A[i+1] > A[i+2]) {
            cur++;
        }
        else if(A[i] > A[i+1] && A[i+1] < A[i+2]) {
            cur++;
        }
        else cur = 2;
        
        ans = max(ans, cur);
    }
    
    cout << ans;
    
    return 0;
}