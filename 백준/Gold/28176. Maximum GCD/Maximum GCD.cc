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
    
    int n; cin >> n;
    vector<int> data(n);
    
    for(int i = 0; i < n; i++) cin >> data[i];
    
    sort(all(data));
    
    for(int i = 1; i <= n; i++) {
        if(i == n) {
            cout << data[0];
            return 0;
        }
        
        if(!(data[i]%data[0] == 0 || (data[i]-1)/2 >= data[0])) {
            break;
        }
    }
    
    if(data[0]%2) {
        cout << data[0]/2;
    }
    else {
        for(int i = 1; i <= n; i++) {
            if(i == n) {
                cout << data[0]/2;
                return 0;
            }
            
            if(!(data[i]%(data[0]/2) == 0 || (data[i]-1)/2 >= data[0]/2)) {
                break;
            }
        }
        
        cout << data[0]/2-1;
    }
    
    return 0;
}