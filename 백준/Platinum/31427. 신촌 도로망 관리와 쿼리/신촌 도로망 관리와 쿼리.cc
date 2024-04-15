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

vector<string> per;

bool used[5] = {false, };
string temp = "XXXXX";
void getPermutation(int step = 0) {
    if(step == 5) {
        per.pb(temp);
        return;
    }
    
    for(int i = 0; i < 5; i++) {
        if(!used[i]) {
            temp[step] = 'A'+i;
            used[i] = true;
            getPermutation(step+1);
            used[i] = false;
            temp[step] = 'X';
        }
    }
}

vector<pii> edges[5];
int parent[50'001];

int findRoot(int v) {
    if(v == parent[v]) return v;
    parent[v] = findRoot(parent[v]);
    return parent[v];
}

void merge(int a,int b) {
    int ra = findRoot(a), rb = findRoot(b);
    if(ra > rb) swap(ra, rb);
    parent[rb] = ra;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    getPermutation();
    
    int N, M, Q; cin >> N >> M >> Q;
    while(M--) {
        int a, b; char c; cin >> a >> b >> c;
        edges[c-'A'].pb({a, b});
    }
    
    map<string, vector<int>> mp;
    for(auto &p: per) {
        vector<int> res(5);
        
        for(int i = 1; i <= N; i++) {
            parent[i] = i;
        }
        
        int cnt = 0;
        for(int i = 0; i < 5 && cnt < N-1; i++) {
            for(auto &[a, b]: edges[p[i]-'A']) {
                if(findRoot(a) != findRoot(b)) {
                    merge(a, b);
                    res[p[i]-'A']++;
                    cnt++;
                }
            }
        }
        
        mp.insert({p, res});
    }
    
    while(Q--) {
        int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
        vector<pair<int, char>> vec;
        vec.pb({a, 'A'}); vec.pb({b, 'B'});
        vec.pb({c, 'C'}); vec.pb({d, 'D'});
        vec.pb({e, 'E'});
        
        sort(all(vec));
        
        string s = "";
        for(auto &[v, c]: vec) {
            s += c;
        }
        
        auto t = mp.find(s);
        cout << 1LL*t->se[0]*a+1LL*t->se[1]*b+1LL*t->se[2]*c
            +1LL*t->se[3]*d+1LL*t->se[4]*e << '\n';
    }
    
    return 0;
}
