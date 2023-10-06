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
    
    int N, M; cin >> N >> M;
    if(N < M) swap(N, M);
    if(N == 1 || M == 1) {
        cout << (int)pow(2, N*M);
        return 0;
    }
    
    int arr[32] = {0, };
    
    for(int i = 0; i < 1<<M; i++) {
        for(int j = 0; j < 1<<M; j++) {
            bool check = true;
            for(int k = 0; k < M-1 && check; k++) {
                if((i & 1<<k) && (i & 1<<(k+1)) && (j & 1<<k) && (j & 1<<(k+1))) {
                    check = false;
                }
            }
            arr[i] += check;
        }
    }
    
    int ans = 0;
    int num = 1<<(N*M-M);
    for(int status = 0; status < num; status++) {
        bool check = true;
        for(int r = 0; r < N-1 && check; r++) {
            for(int c = 0; c < M-1 && check; c++) {
                if((status & 1<<(r*M+c)) && (status & 1<<(r*M+c+1))
                && (status & 1<<((r+1)*M+c)) && (status & 1<<((r+1)*M+c+1))) {
                    check = false;
                }
            }
        }
        
        int t = 0;
        for(int j = 0; j < M; j++) {
            t = t*2+((status & 1 << (N-2)*M+j) > 0);
        }
        
        ans += check*arr[t];
    }
    
    cout << ans;
    
    return 0;
}