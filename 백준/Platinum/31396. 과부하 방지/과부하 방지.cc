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
    
    int N, K, M; cin >> N >> K >> M;
    vector<int> A(N), D(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> D[i];
    
    sort(rall(A)); sort(all(D));
    
    int i = 0, j = M;
    while(i <= j) {
        int mid = (i+j) >> 1;
        ll cnt[200'001] = {0, }; cnt[0] = K;
        ll totalSocket = K;
        int idx = M-mid, sidx = 0;
        
        bool check = totalSocket >= mid;
        for(int l = 0; sidx < N && !check; l++) {
            int need = 0;
            while(idx < M && D[idx] == l) {
                need++; idx++;
            }
            
            if(need > cnt[l]) break;
            
            cnt[l] -= need;
            
            while(cnt[l] && sidx < N) {
                cnt[l]--;
                cnt[l+1] += A[sidx];
                totalSocket += A[sidx]-1;
                sidx++;
                
                if(totalSocket >= mid) {
                    check = true;
                    break;
                }
            }
        }
        
        if(check) i = mid+1;
        else j = mid-1;
    }
    
    cout << j;
    
    return 0;
}
