#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 1) return 1;
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
    return a*b/gcd(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N, A, B; cin >> N >> A >> B;
    
    if(N < min(A, B)) cin >> N;
    
    ll l = lcm(A, B);
    
    ll cnt = 0; ll lenB = 0;
    while(lenB < l && N-lenB >= 0) {
        cnt += (N-lenB)/A+1;
        lenB += B;
    }
    cnt--;
    
    cout << N-cnt;

    return 0;
}