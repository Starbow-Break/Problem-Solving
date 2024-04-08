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
    
    int N;
    while(cin >> N) {
        if(N == -1) break;
        
        cout << N << " coconuts, ";
        int ans = -1;
        for(int i = 1; i <= N; i++) {
            int temp = N;
            bool check = true;
            for(int j = 1; j <= i && check; j++) {
                if(temp > 0 && temp%i > 0 && (temp-1)%i == 0) {
                    temp = (temp-1)/i*(i-1);
                }
                else check = false;
            }
            
            if(check && temp%i == 0) {
                ans = i;
            }
        }
        
        if(ans == -1) {
            cout << "no solution";
        }
        else {
            cout << ans;
            cout << " people and 1 monkey";
        }
        
        cout << '\n';
    }
    
    return 0;
}