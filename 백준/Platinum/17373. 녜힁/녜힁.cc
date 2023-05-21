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

//PST의 노드
struct Node {
    Node *l, *r;
    ll v;
    
    Node() {
        l = r = NULL;
        v = 0;
    }
};

int N, M, Q; 
Node *root[100'001];
int a[100'001], b[1'000'001] = {0, }; //원래 수열, 앞 값에 따른 참고애햐하는 세그트리 인덱스
int cnt[1'000'001] = {0, };
pii ans[100'001];
vector<pll> queries;

//초기값으로 설정
void initTree(int i, int j, Node *cur) {
    if(i == j) {
        cur->v = (cnt[i] == 0);
        return;
    }
    
    int mid = i+j >> 1;
    cur->l = new Node(); cur->r = new Node();
    initTree(i, mid, cur->l); initTree(mid+1, j, cur->r);
    cur->v = cur->l->v + cur->r->v;
}

//트리 갱신
void update(int i, int j, Node *prev, Node *cur, int idx, int v) {
    if(i == j) {
        cur->v = v;
        return;
    }
    
    int mid = i+j >> 1;
    if(idx <= mid) { //왼쪽 갱신 시
        cur->l = new Node(); cur->r = prev->r;
        update(i, mid, prev->l, cur->l, idx, v);
    }
    else { //오른쪽 갱신 시
        cur->l = prev->l; cur->r = new Node();
        update(mid+1, j, prev->r, cur->r, idx, v);
    }
    
    cur->v = cur->l->v + cur->r->v;
}

int query(int i, int j, Node *cur, int l, int r) {
    if(j < l || r < i) return 0;
    if(l <= i && j <= r) return cur->v;
    
    int mid = i+j >> 1;
    return query(i, mid, cur->l, l, r)+query(mid+1, j, cur->r, l, r);
}

int solve(int p, int v) {
    int i = 1, j = M;
    while(i <= j) {
        int mid = i+j >> 1;
        int q = query(1, M, root[p], 1, mid);
        
        if(q >= v) j = mid-1;
        else i = mid+1;
    }
    
    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> Q;
    for(int i = 1; i <= N; i++) {
        cin >> a[i]; cnt[a[i]]++;
        if(b[a[i]] == 0) b[a[i]] = i;
    }
    
    root[0] = new Node();
    initTree(1, M, root[0]);
    
    for(int q = 1; q <= Q; q++) {
        ll v; cin >> v;
        queries.push_back({v, q});
    }
    
    sort(queries.begin(), queries.end());
    
    for(int i = 1; i <= N; i++) {
        cnt[a[i]]--;
        
        if(cnt[a[i]]) root[i] = root[i-1];
        else {
            root[i] = new Node();
            update(1, M, root[i-1], root[i], a[i], 1);
        }
    }
    
    ll w = 0; int p = 1;
    for(auto &query: queries) {
        ll q = query.first;
        int idx = query.second;
        
        while(p <= M) {
            if(b[p] == 0) {
                if(q-w <= M) {
                    ans[idx] = {p, q-w};
                    break;
                }
            }
            else {
                if(root[b[p]]->v >= q-w) {
                    ans[idx] = {p, solve(b[p], q-w)};
                    break;
                }
            }
            
            w += (b[p] ? root[b[p]]->v : M);
            p++;
        }
        
        if(p > M) ans[idx] = {-1, -1};
    }
    
    for(int i = 1; i <= Q; i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

    return 0;
}