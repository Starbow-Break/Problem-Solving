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

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    return (b ? gcd(b, a%b) : a);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    
    ll A = 0, B = 1;
    for(int i = 1; i <= N; i++) B *= i;
    
    for(int status = 0; status < (1<<(N-1)); status++) {
        ll cur = B;
        int bef = 0, cnt = 0, combo = 0, cycle = 0;
        bool check = true;
        for(int i = 0; i <= N && check; i++) {
            if(i) {
                if(i == N || status & (1 << (i-1))) {
                    if(bef > cnt) {
                        check = false;
                        break;
                    }
                    else if(bef == cnt) {
                        combo++;
                        cur /= cnt;
                        cur /= combo;
                        cnt = 1;
                        cycle++;
                    }
                    else {
                        cur /= cnt;
                        bef = cnt;
                        cnt = 1;
                        combo = 1;
                        cycle++;
                    }
                }
                else {
                    cnt++;
                }
            }
            else {
                cnt++;
            }
        }
        
        if(check && cycle <= K) {
            A += cur;
        }
    }
    
    ll g = gcd(A, B);
    A /= g; B /= g;
    cout << A << "/" << B;
    
    return 0;
}
