#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

struct info {
    int a, b, p, q;
};

int N;
vector<info> infos;
ll ans[10] = {0, };
int step = 0;

ll gcd(ll A, ll B) {
    if(A < B) return gcd(B, A);
    if(B == 1) return 1;
    if(B == 0) return A;
    
    return gcd(B, A%B);
}

ll lcm(ll A, ll B) {
    return A/gcd(A, B)*B;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i < N; i++) {
        int a, b, p, q;
        cin >> a >> b >> p >> q;
        infos.push_back({a, b, p, q});
    }
    
    ans[infos[0].a] = infos[0].p/gcd(infos[0].p, infos[0].q);
    ans[infos[0].b] = infos[0].q/gcd(infos[0].p, infos[0].q);
    step++;
    
    while(step < N-1) {
        for(int i = 0; i < N-1; i++) {
            if((ans[infos[i].a] != 0) ^ (ans[infos[i].b] != 0)) {
                ll p = infos[i].p/gcd(infos[i].p, infos[i].q);
                ll q = infos[i].q/gcd(infos[i].p, infos[i].q);
                
                if(ans[infos[i].a] != 0) {
                    ll l = lcm(ans[infos[i].a], p);
                    for(int j = 0; j < N; j++) {
                        if(j == infos[i].a) continue;
                        ans[j] *= l/ans[infos[i].a];
                    }
                    
                    ans[infos[i].a] = l;
                    ans[infos[i].b] = 1LL*q*l/p;
                }
                else {
                    ll l = lcm(ans[infos[i].b], q);
                    for(int j = 0; j < N; j++) {
                        if(j == infos[i].b) continue;
                        ans[j] *= l/ans[infos[i].b];
                    }
                    
                    ans[infos[i].b] = l;
                    ans[infos[i].a] = 1LL*p*l/q;
                }
                
                step++;
                break;
            }
        }
    }
    
    for(int i = 0; i < N; i++) { cout << ans[i] << " "; }

    return 0;
}