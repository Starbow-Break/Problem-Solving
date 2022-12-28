#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll T[250001]; int sizeT = 0;
ll F[250001]; int sizeF = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, w; cin >> N >> w;
    while(N--) {
        int t, s; cin >> t >> s;
        if(t == 3) {
            sizeT++; T[sizeT] = -s;
        }
        else {
            sizeF++; F[sizeF] = -s;
        }
    }
    
    sort(T+1, T+sizeT+1); sort(F+1, F+sizeF+1);
    T[0] = 0; F[0] = 0;
    for(int i = 1; i <= sizeT; i++) { T[i] += T[i-1]; }
    for(int i = 1; i <= sizeT; i++) { T[i] *= -1; }
    for(int i = 1; i <= sizeF; i++) { F[i] += F[i-1]; }
    for(int i = 1; i <= sizeF; i++) { F[i] *= -1; }
    
    ll ans = 0;
    for(int i = 0; i <= w/5; i++) {
        ans = max(ans, F[min(i, sizeF)]+T[min((w-i*5)/3, sizeT)]);
    }
    
    cout << ans;

    return 0;
}