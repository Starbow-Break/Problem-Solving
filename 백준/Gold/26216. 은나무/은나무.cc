#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int K, H, Q; 

pll getWhiteInfo(ll X) {
    ll dep = H;
    
    while(!(X%(K+1))) {
        dep--; X /= (K+1);
    }
    
    return {dep, X/(K+1)};
}

int query(ll A, ll B) {
    ll border = 1;
    for(int i = 1; i <= H; i++) { border *= (K+1); }
    border--;
    
    if(A > border || B > border) return -1;
    if(A == B) return 0;
    
    pll wA = getWhiteInfo(A);
    pll wB = getWhiteInfo(B);
    
    ll depA = wA.first; ll depB = wB.first;
    ll idxA = wA.second; ll idxB = wB.second;
        
    int ans = 2;
    
    while(depA > depB) {
        idxA /= (K+1); depA--; ans++;
    }
    while(depA < depB) {
        idxB /= (K+1); depB--; ans++;
    }
    
    while(idxA != idxB) {
        idxA /= (K+1); idxB /= (K+1); ans += 2;
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> K >> H >> Q;
    
    while(Q--) {
        ll A, B; cin >> A >> B;
        cout << query(A, B) << '\n';
    }

    return 0;
}