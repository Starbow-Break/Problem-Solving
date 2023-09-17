#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define push_back pb
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
    int dist[21][21];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) cin >> dist[i][j];
    }
    
    int ans = 0; bool possible = true;
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            bool check = true;
            for(int k = 1; k <= N; k++) {
                if(k != i && k != j) {
                    if(dist[i][k]+dist[k][j] == dist[i][j]) {
                        check = false;
                    }
                    if(dist[i][k]+dist[k][j] < dist[i][j]) {
                        possible = false;
                    }
                }
            }
            ans += check*dist[i][j];
        }
    }
    
    cout << (possible ? ans : -1);
    
    return 0;
}