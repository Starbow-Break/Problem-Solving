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

struct node {
    int pos, height, num;
    bool isAdd;
    
    bool operator< (node &n) {
        return pos < n.pos;
    }
};

struct cmp {
    bool operator()(pii &a, pii &b) {
        return a.fi < b.fi;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<node> vec;
    
    FOR(i, 1, N+1) {
        int l, h, r; cin >> l >> h >> r;
        vec.pb({l, h, i, true});
        vec.pb({r, h, i, false});
    }
    
    sort(all(vec));
    
    bool check[100001] = {false, }; check[0] = true;
    priority_queue<pii, vector<pii>, cmp> pq;
    pq.push({0, 0});
    
    int idx = 0, cur = 0;
    while(idx < vec.size()) {
        int x = vec[idx].pos;
        while(idx < vec.size() && vec[idx].pos == x) {
            if(vec[idx].isAdd) {
                check[vec[idx].num] = true;
                pq.push({vec[idx].height, vec[idx].num});
            }
            else {
                check[vec[idx].num] = false;
            }
            idx++;
        }
        
        while(!pq.empty() && !check[pq.top().se]) pq.pop();
        if(cur != pq.top().fi) {
            cout << x << ' ' << pq.top().fi << ' ';
            cur = pq.top().fi;
        }
        
    }
    
    return 0;
}