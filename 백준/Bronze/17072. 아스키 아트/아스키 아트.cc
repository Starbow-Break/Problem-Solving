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
    for(int r = 0; r < N; r++) {
        for(int c = 0; c < M; c++) {
            int R, G, B; cin >> R >> G >> B;
            int I = 2126*R+7152*G+722*B;
            if(I < 510000) cout << '#';
            else if(I < 1'020'000) cout << 'o';
            else if(I < 1'530'000) cout << '+';
            else if(I < 2'040'000) cout << '-';
            else cout << '.';
        }
        cout << '\n';
    }
    
    return 0;
}
