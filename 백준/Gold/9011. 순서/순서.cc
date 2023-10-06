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
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vector<int> R(N), S(N);
        
        for(int i = 0; i < N; i++) cin >> R[i];
        
        for(int i = 0; i < N; i++) {
            S[i] = R[i]+1;
            for(int j = 0; j < i; j++) {
                if(S[j] > R[i]) S[j]++;
            }
        }
        
        bool check = true;
        bool visited[101] = {false, };
        for(int i = 0; i < N; i++) {
            if(S[i] > N || visited[S[i]]) {
                check = false;
                break;
            }
            visited[S[i]] = true;
        }
        
        if(check) {
            for(int i = 0; i < N; i++) cout << S[i] << ' ';
        }
        else cout << "IMPOSSIBLE";
        cout << '\n';
    }
    
    return 0;
}
