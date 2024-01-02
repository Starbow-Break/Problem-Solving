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
    
    int n;
    while(cin >> n) {
        vector<int> vec(n), check(n);
        bool isJolly = true;
        for(int i = 0; i < n; i++) cin >> vec[i];
        for(int i = 0; i < n-1 && isJolly; i++) {
            if(check[abs(vec[i+1]-vec[i])] || abs(vec[i+1]-vec[i]) >= n) {
                isJolly = false;
            }
            else check[abs(vec[i+1]-vec[i])] = true;
        }
        
        cout << (isJolly ? "Jolly" : "Not jolly") << '\n';
    }
    
    return 0;
}
