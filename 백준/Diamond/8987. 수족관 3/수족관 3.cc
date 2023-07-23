#include <bits/stdc++.h>
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

int p[150000], lc[150000] = {0, }, rc[150000] = {0, }; //부모, 왼쪽 자식, 오른쪽 자자식
pii posX[150000]; int posY[150000];
ll w[150000], sum[150000];
int root, in[150000], out[150000]; //루트 노드, in, out
pll segTree[1<<19]; ll lazy[1<<19] = {0, };

//각 정점의 가중치 구하기
void getWeight(int cur, int s, int e) {
    if(!cur) return;
    
    if(cur == root)
        w[cur] = 1LL*(e-s)*posY[cur];
    else
        w[cur] = 1LL*(e-s)*(posY[cur]-posY[p[cur]]);
    
    getWeight(lc[cur], s, posX[cur].first);
    getWeight(rc[cur], posX[cur].second, e);
}

//DFS
int ord = 0;
void dfs(int cur) {
    if(!cur) return;
    
    in[cur] = ++ord;
    
    sum[cur] = w[cur];
    if(cur != root) {
        sum[cur] += sum[p[cur]];
    }
    dfs(lc[cur]); dfs(rc[cur]);
    
    out[cur] = ord;
}

void propagate(int s, int e, int idx) {
    if(s != e) {
        lazy[idx<<1] += lazy[idx];
        lazy[idx<<1|1] += lazy[idx];
    }
    
    segTree[idx].first += lazy[idx];
    lazy[idx] = 0;
}

pll merge(pll &l, pll &r) {
    pll ret;
    ret.first = max(l.first, r.first);
    if(ret.first == l.first) ret.second = l.second;
    else ret.second = r.second;
    return ret;
}

//트리 초기화
void init(int s, int e, int idx) {
    if(s == e) {
        segTree[idx] = {0, s};
        return;
    }
    
    int mid = s+e>>1;
    init(s, mid, idx<<1); init(mid+1, e, idx<<1|1);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

//update
void update(int s, int e, int idx, int i, int j, ll del) {
    propagate(s, e, idx);
    
    if(e < i || j < s) return;
    if(i <= s && e <= j) {
        lazy[idx] += del;
        propagate(s, e, idx);
        return;
    }
    
    int mid = s+e>>1;
    update(s, mid, idx<<1, i, j, del); update(mid+1, e, idx<<1|1, i, j, del);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, A, x, y, xx, yy; cin >> N;
    N = (N-1)/2;
    cin >> x >> y;
    for(int i = 1; i <= N; i++) {
        cin >> x >> y >> xx >> yy;
        posX[i] = {x, xx}; posY[i] = y;
        //첫번째 노드일 때
        if(i == 1) {
            p[i] = i;
            continue;
        }
        
        //두번째 노드부터 차근 차근 연결하면서 트리 구축
        int q = i-1;
        while(q != p[q] && posY[q] > y) q = p[q];
        
        if(posY[q] > y) {
            lc[i] = q; p[q] = i; p[i] = i;
        }
        else {
            if(rc[q] != 0) {
                lc[i] = rc[q]; p[rc[q]] = i;
            }
            rc[q] = i; p[i] = q;
        }
    }
    cin >> A >> y;
    
    //루트 구하기
    for(int i = 1; i <= N; i++) {
        if(i == p[i]) {
            root = i; break;
        }
    }
    
    getWeight(root, 0, A); //각 정점의 가중치 구하기
    
    //DFS 돌면서 sum 채우기
    dfs(root);
    
    //세그먼트 트리에 반영
    init(1, N, 1);
    for(int i = 1; i <= N; i++) {
        update(1, N, 1, in[i], in[i], sum[i]);
    }
    
    //답 구하기
    int K; cin >> K;
    ll ans = 0;
    while(K--) {
        //현재 상황에서 가자 무를 많이 뺄 수 있는 구멍 뚫기
        ll cur = segTree[1].first, idx = segTree[1].second;
        ans += cur;
        
        //빠진 물 반영
        while(1) {
            if(w[idx]) update(1, N, 1, in[idx], out[idx], -w[idx]);
            w[idx] = 0;
            
            if(idx == p[idx]) break;
            idx = p[idx];
        }
    }
    
    cout << ans;

    return 0;
}