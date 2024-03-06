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

const double EPS = 1e-15; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, X, Y; cin >> N >> X >> Y;
    vector<int> gn1(N+1), gn2(N+1), w(N+1);
    
    for(int i = 1; i <= N; i++) cin >> gn1[i];
    for(int i = 1; i <= N; i++) cin >> gn2[i];
    for(int i = 1; i <= N; i++) cin >> w[i];
    
    double l = 0, r = (double)w[1]/gn1[1];
    for(int i = 2; i <= N; i++) {
        r = min(r, (double)w[i]/gn1[i]);
    }
    
    // 이분 탐색
    while(r-l >= EPS) {
        double mid = (r+l)/2;
        double minV = (double)(w[1]-gn1[1]*mid)/gn2[1];
        double slope = (double)(-gn1[1])/gn2[1];
        
        for(int i = 2; i <= N; i++) {
            if(minV > (double)(w[i]-gn1[i]*mid)/gn2[i]) {
                minV = (double)(w[i]-gn1[i]*mid)/gn2[i];
                slope = (double)(-gn1[i])/gn2[i];
            }
        }
        
        if(X+Y*slope > 0) l = mid;
        else r = mid;
    }
    
    double a = (l+r)/2;
    double b = (double)(w[1]-gn1[1]*a)/gn2[1];
    for(int i = 2; i <= N; i++) {
        b = min(b, (double)(w[i]-gn1[i]*a)/gn2[i]);
    }
    
    cout << fixed << setprecision(2) << X*a+Y*b << '\n';
    cout << fixed << setprecision(2) << a << ' ' << b;
    
    return 0;
}
