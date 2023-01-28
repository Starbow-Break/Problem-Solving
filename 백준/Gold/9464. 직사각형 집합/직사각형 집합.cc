#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX 1000000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> dd;

vector<pii> pythagorean;
int ans[1000001];

bool cmp(pii &A, pii &B) {
    return A.first+A.second < B.first+B.second;
}

ll gcd(ll a, ll b) {
    if(a < b) return gcd(b, a);
    
    if(b == 1) return 1;
    if(b == 0) return a;
    return gcd(b, a%b);
}

void getPythagorean() {
    for(int x = 1; x <= 250000; x++) {
        for(int y = 1; y < x; y++) {
            if(x*y > 250000) break;
            
            ll a = 2*x*y; ll b = 1LL*x*x-1LL*y*y;
            if(a+b > 500000) break;
            if(gcd(a, b) == 1) {
                pythagorean.push_back({a, b});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPythagorean();
    
    sort(pythagorean.begin(), pythagorean.end());
    pythagorean.erase(unique(pythagorean.begin(), pythagorean.end()), pythagorean.end());
    sort(pythagorean.begin(), pythagorean.end(), cmp);
    
    int cnt = 0; int cur = (pythagorean[0].first+pythagorean[0].second)*2;
    for(int i = 1; i <= 1000000; i++) {
        if(i >= cur) {
            cnt++; cur += (pythagorean[cnt].first+pythagorean[cnt].second)*2;
        }
        
        ans[i] = cnt;
    }
    
    int T; cin >> T;
    while(T--) {
        int L; cin >> L;
        cout << ans[L] << '\n';
    }

    return 0;
}