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
    
    int x;
    while(cin >> x) {
        int N; cin >> N;
        vector<int> blocks;
        repeat(N) {
            int v; cin >> v;
            blocks.pb(v);
        }
        
        sort(all(blocks));
        
        int i = 0, j = N-1;
        while(i < j) {
            if(blocks[i]+blocks[j] < x*10000000) i++;
            else if(blocks[i]+blocks[j] > x*10000000) j--;
            else {
                cout << "yes " << blocks[i] << ' ' << blocks[j];
                break;
            }
        }
        
        if(i >= j) {
            cout << "danger";
        }
        
        cout << '\n';
    }
    
    return 0;
}
