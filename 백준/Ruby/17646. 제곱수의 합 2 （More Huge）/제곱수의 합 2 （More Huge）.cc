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
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

bool checkFour(ll N) {
    while(N%4 == 0) N /= 4;
    
    return N%8 == 7;
}

ll modPow(ll a, ll e, ll n) {
    int128 ret = 1, w = a;
    
    while(e > 0) {
        if(e%2) {
            ret *= w; ret %= n;
        }
        
        e /= 2;
        w *= w; w %= n;
    }
    
    return ret;
}

ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

//x^2+c
ll f(ll x, ll c, ll n) {
    return ((int128)x*x+c)%n;
}

bool millerRabin(ll n) {
    ll a[16] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    
    for(int i = 0; i < 14; i++) {
        if(n <= a[i]) break;
        
        ll _n = n-1;
        
        bool check = false;
        
        while(_n%2 == 0) {
            _n /= 2;
            if(modPow(a[i], _n, n) == n-1) check = true;
        }
        
        if(modPow(a[i], _n, n) == 1) check = true;
        
        if(!check) return false;
    }
    
    return true;
}

void pollardRho(ll n, vector<ll> &pf) {
    if(n == 1) return;
    
    if(n%2 == 0) {
        while(n%2 == 0) {
            pf.push_back(2);
            n /= 2;
        }
        
        pollardRho(n, pf);
        return;
    }
    
    
    if(millerRabin(n)) {
        pf.push_back(n); return;
    }
    
    ll x = 1, y = 1, g = 1, c = 1;
    
    while(g == 1) {
        x = f(x, c, n);
        y = f(y, c, n);
        y = f(y, c, n);
        
        g = gcd(abs(y-x), n);
        
        //g가 n이면 실패, c값을 바꿔서 다시 실시한다.
        if(g == n) {
            g = 1; x = 1; y = 1;
            c++;
        }
    }
    
    pollardRho(g, pf);
    pollardRho(n/g, pf);
}

//제곱수의 최소 갯수 구하기
int numOfSquare(ll n) {
    //답이 4개인지 체크
    if(checkFour(n)) return 4;
    
    vector<ll> pf;
    //N을 소인수분해
    pollardRho(n, pf);
    
    sort(pf.begin(), pf.end());
    pf.push_back(1);
    
    int ans = 1; ll cur = 1, cnt = 0;
    for(auto &p: pf) {
        if(cur == p) { cnt++; continue; }
        
        //지수가 홀수인 소인수가 있으면 최소 2개
        if(cnt % 2) {
            ans = max(ans, 2);
            
            //그 중 4로 나눈 나머지가 3인 소인수가 있으면 3개
            if(cur % 4 == 3)
                ans = max(ans, 3);
        }
        
        cur = p; cnt = 1;
    }
    
    return ans;
}

//Tonelli-Shanks Algorithm
//x^2 = -1 (mod p)를 만족하는 x 반환
//원래는 -1이 p의 이차 잉여인지 확인해야 하지만 이 문제에서는 필요 없음
ll tonelliShanks(ll p) {
    ll Q = p-1, S = 0;
    while(Q%2 == 0) {Q /= 2; S++; }
    
    ll z;
    for(z = 2; z < p; z++) {
        if(modPow(z, (p-1)/2, p) != 1) break;
    }
    
    ll M = S, c = modPow(z, Q, p), t = p-1, R = ((Q+1)/2%2 ? p-1 : 1);
    while(1) {
        if(t == 0) return 0;
        if(t == 1) return R;
        
        int i = 0; int128 w = t;
        while(w != 1) {
            i++; w *= w; w %= p;
        }
        
        int128 b = c;
        for(int j = 1; j <= M-i-1; j++) {
            b *= b; b %= p;
        }

        M = i%p, c = b*b%p, t = b*b%p*t%p, R = b*R%p;
    }
}

//Cornaccia's Algorithm
//소수 p를 두 제곱수의 합으로 표현
//원래는 해가 존재하는지 판별하는 부분이 있어야하지만 이 문제에서는 필요 없으
pii cornaccia(ll p) {
    ll x = tonelliShanks(p);
    
    if(!(p/2+1 <= x && x < p)) x = p-x;
    
    ll a = p, b = x, l = floor(sqrt(p));
    
    while(b > l) {
        ll r = a%b;
        a = b; b = r;
    }
    
    return {b, sqrt(p-b*b)};
}

vector<int> solve(ll n) {
    vector<int> ret;
    
    int v = numOfSquare(n);
    int w = 1;
    switch(v) {
        case 4: {
            while(n%4 == 0) { w *= 2; n /= 4; }
            ret.push_back(w);
            n--; v--;
        }
        case 3: {
            while(n%4 == 0) { w *= 2; n /= 4; }
            
            for(int t = 1; n-1LL*t*t > 0; t++) {
                if(numOfSquare(n-1LL*t*t) == 2) {
                    ret.push_back(w*t); v--; 
                    n -= 1LL*t*t;
                    break;
                }
            }
        }
        case 2: {
            vector<ll> pf;
            pollardRho(n, pf);
            
            ll T = 1; vector<ll> prime;
            sort(pf.begin(), pf.end());
            
            int cnt = 0; ll cur = 1;
            for(int i = 0; i < pf.size(); i++) {
                if(i < pf.size()-1 && pf[i] == pf[i+1]) {
                    T *= pf[i]; i++;
                }
                else { prime.push_back(pf[i]); }
            }
            
            pii ans = {-1, -1};
            for(auto &p: prime) {
                pii ansP;
                if(p == 2) ansP = {1, 1};
                else if(p == 5) ansP = {1, 2};
                else if(p == 13) ansP = {2, 3};
                else if(p == 17) ansP = {1, 4};
                else if(p == 29) ansP = {2, 5};
                else if(p == 37) ansP = {1, 6};
                else ansP = cornaccia(p);
                
                if(ans.first == -1) ans = ansP;
                else ans = {abs(ans.x*ansP.y-ans.y*ansP.x), ans.x*ansP.x+ans.y*ansP.y};
            }
            ret.push_back(w*T*ans.x);
            ret.push_back(w*T*ans.y);
            break;
        }
        case 1:
            ret.push_back(sqrt(n));
            v--;
            break;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll N; cin >> N;
    vector<int> ans = solve(N);
    
    cout << ans.size() << '\n';
    for(auto &v: ans) cout << v << ' ';
    
    return 0;
}