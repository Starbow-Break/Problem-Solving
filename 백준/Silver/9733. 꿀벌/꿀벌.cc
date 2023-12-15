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
    
    string work[7] = {"Re","Pt","Cc","Ea","Tb","Cm","Ex"};
    int cnt[7] = {0, };
    
    string s; int total = 0;
    while(cin >> s) {
        total++;
        for(int i = 0; i < 7; i++) {
            if(work[i] == s) {
                cnt[i]++;
                break;
            }
        }
    }
    
    for(int i = 0; i < 7; i++) {
        cout << work[i] << ' ' << cnt[i] << ' ' << fixed << setprecision(2) << (double)cnt[i]/total << '\n';
    }
    cout << "Total " << total << " 1.00"; 
    
    return 0;
}
