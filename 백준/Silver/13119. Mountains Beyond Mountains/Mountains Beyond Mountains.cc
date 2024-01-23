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
    
    int N, M, X; cin >> N >> M >> X;
    vector<char> vec[N+1]; vector<int> mountain(M+1);
    
    for(int i = 1; i <= M; i++) cin >> mountain[i];
    
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j <= M; j++) {
            vec[i].pb('.');
        }
    }
    
    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= mountain[i]; j++) {
            vec[N+1-j][i] = '#';
        }
    }
    
    for(int i = 1; i <= M; i++) {
        vec[N+1-X][i] = (vec[N+1-X][i] == '#' ? '*' : '-');
    }
    
    for(int i = 3; i <= M; i += 3) {
        for(int j = X-1; j >= 1; j--) {
            if(vec[N+1-j][i] == '#') break;
            vec[N+1-j][i] = '|';
        }
    }
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << vec[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}
