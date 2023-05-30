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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

struct _data {
    int t, p, s; //계산돈 시간, 서브트리의 루트 노드, 가중치
    
    bool operator<(_data &d) {
        return t < d.t;
    }
};

struct node {
    ll value, lazy;
};

int N, K, J; 
vector<int> graph[100'001]; //그래프(트리)
vector<int> music[100'001]; //가수 별 곡 목록
int artist[100'001]; //곡별 가수
vector<_data> datas; vector<int> times; int invComp[100'001];
int in[100'001], out[100'001], siz[100'001], lo[100'001], hi[100'001];
node segTree[1 << 18];

//시간 압축
void compressTime() {
    sort(times.begin(), times.end());
    times.erase(unique(times.begin(), times.end()), times.end());
    
    for(int i = 1; i <= times.size(); i++) {
        invComp[i] = times[i-1];
    }
    
    for(int i = 0; i < K; i++) {
        datas[i].t = lower_bound(times.begin(), times.end(), datas[i].t)-times.begin()+1;
    }
}

//DFS
int ord = 0;
void dfs(int cur = 1) {
    in[cur] = ++ord; siz[cur] = 1;
    for(auto &c: graph[cur]) {
        dfs(c);
        siz[cur] += siz[c];
    }
    out[cur] = ord;
}

void propagate(int l, int r, int idx) {
    ll lazy = segTree[idx].lazy;
    
    if(l != r) {
        segTree[idx<<1].lazy += lazy;
        segTree[idx<<1|1].lazy += lazy;
    }
    
    segTree[idx].value += lazy*(r-l+1);
    segTree[idx].lazy = 0;
}

node merge(node &a, node &b) {
    node ret;
    ret.value = a.value+b.value;
    ret.lazy = 0;
    return ret;
}

//트리 초기화
void initTree() {
    for(int i = 1; i < 1<<18; i++) segTree[i] = {0, 0};
}

//트리 업데이트
void update(int l, int r, int idx, int i, int j, int v) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    if(i <= l && r <= j) {
        segTree[idx].lazy += v;
        propagate(l, r, idx);
        return;
    }
    
    int mid = l+r>>1;
    update(l, mid, idx<<1, i, j, v); update(mid+1, r, idx<<1|1, i, j, v);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

//점수 구하기
ll query(int l, int r, int idx, int i) {
    propagate(l, r, idx);
    
    if(r < i || i < l) return 0;
    if(l == r) return segTree[idx].value;
    
    int mid = l+r>>1;
    return query(l, mid, idx<<1, i)+query(mid+1, r, idx<<1|1, i);
}

ll getScore(int v) {
    ll ret = 0;
    for(auto &s: music[v]) {
        ret += query(1, N, 1, in[s]);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K >> J;
    for(int i = 2; i <= N; i++) {
        int v; cin >> v;
        graph[v].push_back(i);
    }
    
    for(int i = 1; i <= N; i++) {
        cin >> artist[i];
        music[artist[i]].push_back(i);
    }
    
    for(int i = 1; i <= K; i++) {
        int t, p, s; cin >> t >> p >> s;
        datas.push_back({t, p, s});
        times.push_back(t);
    }
    
    compressTime();
    sort(datas.begin(), datas.end());
    
    int sz = times.size();
    for(int i = 1; i <= N; i++) { lo[i] = 1; hi[i] = sz; }
    
    dfs();
    
    bool flag;
    vector<int> mlist[100'001];
    while(1) {
        flag = false; initTree();
        
        for(int i = 1; i <= N; i++) {
            if(lo[i] <= hi[i]) mlist[(lo[i]+hi[i])/2].push_back(i);
        }
        
        int idx = 0;
        for(int mid = 1; mid <= sz; mid++) {
            while(idx < datas.size() && datas[idx].t == mid) {
                update(1, N, 1, in[datas[idx].p], out[datas[idx].p], datas[idx].s/siz[datas[idx].p]);
                idx++;
            }
            
            if(!mlist[mid].empty()) {
                flag = true;
                
                for(auto &v: mlist[mid]) {
                    ll score = getScore(v);
                    if(score > 1LL*J*music[v].size()) hi[v] = mid-1;
                    else lo[v] = mid+1;
                }
            }
        }
        
        if(!flag) break;
        for(int i = 1; i <= sz; i++) mlist[i].clear();
    }
    
    for(int i = 1; i <= N; i++) {
        cout << (lo[artist[i]] > sz ? -1 : invComp[lo[artist[i]]]) << '\n';
    }

    return 0;
}