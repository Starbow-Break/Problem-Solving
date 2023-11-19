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
 
string solve(int l) {
    if(620 <= l && l <= 780) return "Red";
    if(590 <= l && l < 620) return "Orange";
    if(570 <= l && l < 590) return "Yellow";
    if(495 <= l && l < 570) return "Green";
    if(450 <= l && l < 495) return "Blue";
    if(425 <= l && l < 450) return "Indigo";
    return "Violet";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int lambda; cin >> lambda;
    cout << solve(lambda);
    
    return 0;
}