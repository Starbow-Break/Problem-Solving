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

string arr[51], t;
pll brr[51];

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    
    if(b == 1) return 1;
    if(b == 0) return a;
    
    return gcd(b, a%b);
}

pll extEuc(ll A, ll B, ll c1, ll c2) {
    ll g = gcd(A, B);
    if(A < B) { swap(A, B); swap(c1, c2); }
    
    ll C = c2-c1;
    if(C%g != 0) return {-1, -1};
    
    ll _A = A; ll _B = B; 
    ll x1 = 1; ll y1 = 0; // curA = A*x1+B*y1
    ll x2 = 0; ll y2 = 1; // curB = A*x2+B*y2
    
    while(B > 0) {
        ll q = A/B; ll r = A%B;
        ll x3 = x1-q*x2; ll y3 = y1-q*y2;
        
        A = B; B = r;
        x1 = x2; y1 = y2; x2 = x3; y2 = y3;
    }
    
    x1 *= C/A; y1 *= C/A; //A*x1+B*y1 = C;
    
    if(x1 >= _B/g) { x1 %= _B/g; }
    if(x1 < 0) { x1 = (-x1)%(_B/g); x1 = _B/g-x1; x1 %= _B/g; }
    
    return {_A/g*_B, _A*x1+c1};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) { cin >> arr[i]; }
    cin >> t;
    
    for(int i = 1; i <= N; i++) {
        int idx;
        for(idx = 0; idx < arr[i].length(); idx++) {
            if(t[i-1] == arr[i][idx]) break;
        }
        
        brr[i] = {arr[i].length(), idx};
    }
    
    pll ans = {1, 0};
    for(int i = 1; i <= N; i++) {
        if(brr[i].second == arr[i].length()) { ans = {-1, -1}; break; }
        ans = extEuc(ans.first, brr[i].first, ans.second, brr[i].second);
        if(ans.first == -1) break;
    }
    
    cout << (ans.first == -1 ? -1 : ans.second);

    return 0;
}