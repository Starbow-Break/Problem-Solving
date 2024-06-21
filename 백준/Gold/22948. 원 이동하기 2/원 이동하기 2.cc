#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORIter(v, vec) for(auto &v: vec)
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

const int INF = 1e9;
vector<int> edges[200'001]; // 트리
vector<pii> vec;

int dep[200'001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    // 원 입력력
    FOR(i, 1, N+1) {
        int k, x, r; cin >> k >> x >> r;
        vec.pb({x-r, k}); vec.pb({x+r, -k}); //
    }
    
    // 정렬 후 스위핑
    sort(all(vec));
    
    stack<int> s; s.push(0);
    FORIter(v, vec) {
        if(v.se > 0) {
            edges[v.se].pb(s.top());
            dep[v.se] = dep[s.top()] + 1;
            s.push(v.se);
        }
        else {
            s.pop();
        }
    }
    
    int A, B; cin >> A >> B;
    vector<int> pathAtoLCA, pathLCAtoB;
    int da = dep[A], db = dep[B];
    while(da > db) {
        da--;
        pathAtoLCA.pb(A);
        A = edges[A][0];
    }
    while(da < db) {
        db--;
        pathLCAtoB.pb(B);
        B = edges[B][0];
    }
    
    while(A != B) {
        da--;
        pathAtoLCA.pb(A);
        A = edges[A][0];
        db--;
        pathLCAtoB.pb(B);
        B = edges[B][0];
    }
    
    pathAtoLCA.pb(A);
    
    cout << pathAtoLCA.size() + pathLCAtoB.size() << '\n';
    reverse(all(pathLCAtoB));
    
    FORIter(v, pathAtoLCA) cout << v << ' ';
    FORIter(v, pathLCAtoB) cout << v << ' ';
    
    return 0;
}
