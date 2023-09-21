#include <bits/stdc++.h>
#define repeat(i, s, e) for(int i = s; i < e; i++)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using int128 = __int128_t;

const int MAX = 1'000;

//세그먼트 트리의 노드
struct Node {
    //maxL : 맨 왼쪽값을 포함하는 연속된 부분 수열 중 최댓값
    //maxR : 맨 오른쪽값을 포함하는 연속된 부분 수열 중 최댓값
    //maxV : 연속된 부분 수열 중 최댓값
    //sum : 총 합계
    ll maxL, maxR, maxV, sum; 
    
    Node() {
        maxL = 0, maxR = 0, maxV = 0, sum = 0;
    }
    
    Node(ll ml, ll mr, ll mv, ll s) {
        maxL = ml, maxR = mr, maxV = mv, sum = s;
    }
};

//세그먼트 트리
struct SegTree {
    Node tree[1 << 11];
    
    SegTree() {
        for(int i = 1; i < 1<<11; i++) tree[i] = Node();
    }
    
    //두 노드를 합침
    Node merge(Node &l, Node &r) {
        Node ret = Node(); //반환할 노드
        ret.maxL = max(l.maxL, l.sum+r.maxL);
        ret.maxR = max(r.maxR, r.sum+l.maxR);
        ret.sum = l.sum+r.sum;
        ret.maxV = max({ret.maxL, ret.maxR, l.maxV, r.maxV, l.maxR+r.maxL});
        return ret;
    }
    
    //특정 노드를 업데이트
    void update(int s, int e, int idx, int t, int v) {
        if(e < t || t < s) return;
        if(s == e) {
            if(v > 0) tree[idx] = Node(v, v, v, v);
            else tree[idx] = Node(0, 0, 0, v);
            return;
        }
        
        int mid = s+e >> 1;
        update(s, mid, idx<<1, t, v); update(mid+1, e, idx<<1|1, t, v);
        tree[idx] = merge(tree[idx<<1], tree[idx<<1|1]);
    }
    
    //전체 수열에서 연속된 부분 수열의 최댓값
    ll maxValue() {
        return tree[1].maxV;
    }
};

//금 혹은 돌이 있는 지점
struct Spot {
    int x, y, w;
    
    bool operator<(Spot &s) {
        if(x != s.x) return x < s.x;
        return y < s.y;
    }
};

//서로 다른 두 Spot을 잇는 직선
struct Line {
    //i, j : 직선이 지나가는 서로 다른 두 Spot
    //dx, dy : x,y 변화량
    int i, j, dx, dy;
    
    //dy/dx < l.dy/l.dx 즉, 기울기가 더 작으면 True
    bool operator<(Line &l) {
        if(1LL*dy*l.dx != 1LL*dx*l.dy) return 1LL*dy*l.dx > 1LL*dx*l.dy;
        if(i != l.i) return i < l.i;
        return j < l.j;
    }
    
    //기울기가 같으면 True
    //이 문제에서는 직선의 기울기만이 중요하므로 기울기만 가지고 비교한다.
    bool operator==(Line &l) {
        return 1LL*dy*l.dx == 1LL*dx*l.dy;
    }
};

Spot pt[MAX+1]; //금 혹은 돌이 있는 지점을 모아논 배열
int pos[MAX+1]; //지점들의 정렬 상태
vector<Line> lines;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    SegTree sgTree = SegTree(); //세그먼트 트리 생성
    
    //빨간점, 파란점 정보 받기
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int x, y; char c; cin >> x >> y >> c;
        pt[i] = {x, y, (c == 'R' ? 1 : -1001)};
    }
    
    if(N == 1) {
        cout << (pt[1].w > 0 ? 1 : 0);
        return 0;
    }
    
    sort(pt+1, pt+N+1); //지점들을 정렬
    for(int i = 1; i <= N; i++) pos[i] = i;
    
    //세그먼트 트리 초기화
    for(int i = 1; i <= N; i++) {
        sgTree.update(1, N, 1, i, pt[i].w);
    }
    
    //서로 다른 두 지점을 잇는 모든 직선들을 생성 및 정렬
    for(int i = 1; i <= N; i++) {
        for(int j = i+1; j <= N; j++) {
            lines.push_back({i, j, pt[j].x-pt[i].x, pt[j].y-pt[i].y});
        }
    }
    sort(lines.begin(), lines.end());
    
    //Rotating Sweep Line Technique
    int i = 0; ll ans = 0;
    while(i < lines.size()) {
        int j = i;
        //동일한 기울기를 가진 직선들의 범위 [i, j)
        while(j < lines.size() && lines[i] == lines[j]) j++;
        //범위 안에 있는 직선들이 지나가는 두 지점을 swap
        for(int k = i; k < j; k++) {
            sgTree.update(1, N, 1, pos[lines[k].i], pt[lines[k].j].w);
            sgTree.update(1, N, 1, pos[lines[k].j], pt[lines[k].i].w);
            swap(pos[lines[k].i], pos[lines[k].j]);
        }
        
        ans = max(ans, sgTree.maxValue()); //해당 정렬 상태에서 답 갱신
        i = j;
    }
    
    cout << ans;
    
    return 0;
}
