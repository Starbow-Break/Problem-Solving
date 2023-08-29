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
    int card[200][3];
    
    for(int i = 0; i < N; i++) {
        cin >> card[i][0] >> card[i][1] >> card[i][2];
    }
    
    for(int i = 0; i < N; i++) {
        int cur = 0;
        for(int j = 0; j < 3; j++) {
            cur += card[i][j];
            bool flag = false;
            for(int ii = 0; ii < N; ii++) {
                if(i == ii) continue;
                if(card[i][j] == card[ii][j]) {
                    cur -= card[i][j];
                    break;
                }
            }
        }
        
        cout << cur << '\n';
    }
    
    return 0;
}