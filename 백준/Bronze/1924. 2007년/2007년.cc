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
    
    int x, y; cin >> x >> y;
    int t = y;
    if(x > 1) t += 31;
    if(x > 2) t += 28;
    if(x > 3) t += 31;
    if(x > 4) t += 30;
    if(x > 5) t += 31;
    if(x > 6) t += 30;
    if(x > 7) t += 31;
    if(x > 8) t += 31;
    if(x > 9) t += 30;
    if(x > 10) t += 31;
    if(x > 11) t += 30;
    
    t %= 7;
    
    string arr[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    
    cout << arr[t];
    
    return 0;
}