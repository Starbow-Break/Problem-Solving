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
    while(M--) {
        vector<int> a(N);
        int total = 0; // 1의 총 개수
        for(int i = 0; i < N; i++) {
            cin >> a[i];
            total += (a[i] == 1);
            //cout << a[i] << ' ';
        }
        //cout << '\n';
        
        int target = total/2; bool isTotalOdd = total%2;
        
        int l = 0, r = N/2-1;
        int cnt = 0; // l~r에서 1의 갯수
        for(int i = l; i <= r; i++) {
            cnt += (a[i] == 1);
        }
        
        for(int i = 0; i < N; i++) {
            if(cnt == target) {
                if(isTotalOdd) {
                    // k+1 -> k
                    if(a[(l+(N-1))%N] == 1 && a[r] == -1) {
                        r = (r+(N-1))%N;
                        if(l >= N/2) {
                            l -= N/2; r = (r+N/2)%N;
                        }
                        
                        for(int i = 0; i < N; i++) {
                            cout << (l <= i && i <= r ? -1 : 1) << ' ';
                        }
                        cout << '\n';
                        break;
                    }
                }
                else {
                    for(int i = 0; i < N; i++) {
                        cout << (l <= i && i <= r ? -1 : 1) << ' ';
                    }
                    cout << '\n';
                    break;
                }
            }
            
            cnt -= (a[l] == 1); l = (l+1)%N;
            r = (r+1)%N; cnt += (a[r] == 1); 
        }
    } 
    
    
    return 0;
}
