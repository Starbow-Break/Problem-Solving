#include <bits/stdc++.h>
#define repeat(cnt) for(int i = 0; i < cnt; i++)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

const int MAX_SIZE = 1e5; //입력 최댓값
const int MAX = 2e9; //다루는 x좌표의 최댓값
const ll INF = 4e18; //무한대 직선의 기울기
int cnt = 0;

//Li-Chao Tree의 노드
struct Node {
    int l, r; //left child, right child
    int s, e; //노드가 다루는 범위 [s, e]
    pll line; //직선
    
    Node() {
        l = r = -1;
        s = 0, e = MAX;
        line = {0, INF};
    }
    Node(int _s, int _e) : s(_s), e(_e) {
        l = r = -1;
        line = {0, INF};
    }
};

ll getValue(pll line, ll x) {
    return line.first*x+line.second;
}

Node tree[3'200'000]; int sz = 0;
int root[MAX_SIZE+1];
vector<pii> edges[MAX_SIZE+1]; //도시의 도로
int S[MAX_SIZE+1], V[MAX_SIZE+1]; //S_i, V_i
int dist[MAX_SIZE+1]; //루트부터 해당 정점까지의 거리
ll dp[MAX_SIZE+1]; //최소시간을 구하기 위한 배열
    
//직선 추가
void _add(int prev, int cur, pll line) {
    int s = tree[cur].s, e = tree[cur].e; //노드가 다루는 x의 범위
    
    //low, high 세팅
    pll low, high = line;
    if(prev == -1) low = {0, INF};
    else low = tree[prev].line;
    
    if(getValue(low, s) > getValue(high, s)) swap(low, high);
    else if(getValue(low, s) == getValue(high, s) && 
    getValue(low, e) > getValue(high, e)) swap(low, high);
    
    //high가 항상 low보다 크거나 같을 때
    if(getValue(low, e) <= getValue(high, e)) {
        tree[cur].l = (prev == -1 ? -1 : tree[prev].l);
        tree[cur].r = (prev == -1 ? -1 : tree[prev].r);
        tree[cur].line = low; return;
    }
    
    //low와 high의 대소 관계가 바구는 구간이 존재할 때
    int m = s+e>>1;
    if(getValue(low, m) < getValue(high, m)) { //m보다 큰쪽에서 바뀌면
        tree[cur].line = low;
        tree[cur].l = tree[prev].l; //왼쪽 자식은 기존 노드 재 사용
        tree[sz] = Node(m+1, e); sz++;
        tree[cur].r = sz-1; //오른쪽 자식은 새 노드 생성
        _add(tree[prev].r, tree[cur].r, high);
    }
    else { //m보다 작은쪽에서 바뀌면
        tree[cur].line = high;
        tree[cur].r = tree[prev].r; //오른쪽 자식은 기존 노드 재 사용
        tree[sz] = Node(s, m); sz++;
        tree[cur].l = sz-1; //왼쪽 자식은 새 노드 생성
        _add(tree[prev].l, tree[cur].l, low);
    }
}
    
//쿼리 수행
ll _query(int node, ll x) {
    if(node == -1) return INF;
    int s = tree[node].s, e = tree[node].e;
    int m = s+e>>1;
    if(x <= m) return min(getValue(tree[node].line, x), _query(tree[node].l, x));
    return min(getValue(tree[node].line, x), _query(tree[node].r, x));
}
    
//외부에서 사용할 add 함수
void add(int s, int e, int prev, int cur, pll line) {
    tree[sz] = Node(0, MAX); sz++; root[cur] = sz-1;
    _add(root[prev], root[cur], line);
}
    
//외부에서 사용할 query 함수
ll query(int cur, ll x) {
    return _query(root[cur], x);
}

//DFS를 돌면서 CHT를 사용
void dfs(int start = 1) {
    stack<pii> s; s.push({start, -1});
    
    while(!s.empty()) {
        int cur = s.top().first, bef = s.top().second; s.pop();
        
        if(bef != -1) {
            add(0, MAX, bef, cur, {-dist[bef], dp[bef]});
            dp[cur] = query(cur, V[cur])+S[cur]+1LL*dist[cur]*V[cur];
        }
        
        for(auto &[next, w]: edges[cur]) {
            if(next != bef) {
                dist[next] = dist[cur]+w;
                s.push({next, cur});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    //N = 100000;
    for(int i = 0; i < N-1; i++) {
        int a, b, w; cin >> a >> b >> w;
        //a = i+1, b = i+2, w = 10000;
        edges[a].push_back({b, w});
        edges[b].push_back({a, w});
    }
    for(int i = 2; i <= N; i++) {
        cin >> S[i] >> V[i];
        //S[i] = i+1; V[i] = 2*i;
    }
    
    tree[sz] = Node(0, MAX); sz++;
    dp[1] = 0; dist[1] = 0; root[1] = sz-1;
    dfs();
    
    for(int i = 2; i <= N; i++) cout << dp[i] << ' ';
    //cout << sizeof(Node)*sz/(1024*1024) << "MB";
    
    return 0;
}