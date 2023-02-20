#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

struct node {
    int value, lazy;
};

struct sweepNode {
    int pos; bool isAdd; int num;
    
    bool operator<(sweepNode &sn) {
        return pos < sn.pos;
    }
};

int N; 
vector<pii> range; vector<int> vec;
node segTree[1 << 19];

//좌표 압축
void compress() {
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    
    for(int i = 0; i < N; i++) {
        range[i].first = lower_bound(vec.begin(), vec.end(), range[i].first)-vec.begin()+1;
        range[i].second = lower_bound(vec.begin(), vec.end(), range[i].second)-vec.begin()+1;
    }
}

//갱신 및 lazy 전파
void propagate(int l, int r, int idx) {
    int lazy = segTree[idx].lazy;
    if(l != r) {
        segTree[idx<<1].lazy += lazy;
        segTree[(idx<<1)|1].lazy += lazy;
    }
    
    segTree[idx].value += lazy;
    segTree[idx].lazy = 0;
}

//두 노드 merge
node merge(int a, int b) {
    return {max(segTree[a].value, segTree[b].value), 0};
}

//[i, j] 구간의 값을 del 만큼 증가
void update(int l, int r, int idx, int i, int j, int del) {
    propagate(l, r, idx); //lazy 전파
    
    if(j < l || r < i) return;
    
    if(i <= l && r <= j) {
        segTree[idx].lazy += del;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, i, j, del);
    update(mid+1, r, (idx<<1)|1, i, j, del);
    segTree[idx] = merge(idx<<1, (idx<<1)|1);
}

//세그먼트 트리 초기화
void buildTree() {
    for(int i = 0; i < N; i++)
        update(1, 2*N, 1, range[i].first, range[i].second, 1);
}

//답 도출
int solve() {
    int ret = 0;
    
    compress(); //좌표 압축
    buildTree(); //세그먼트 트리 빌드
    ret = segTree[1].value;
    
    //스위핑을 위한 준비
    vector<sweepNode> sweep;
    for(int i = 0; i < N; i++) {
        sweep.push_back({range[i].first, true, i});
        sweep.push_back({range[i].second+1, false, i});
    }
    sort(sweep.begin(), sweep.end());
    
    int idx = 0; int cnt = 0;
    //스위핑 실시
    while(idx < 2*N) {
        int cur = sweep[idx].pos;
        //스위핑하면서 첫번째 수평선과 만나는 직사각형 갯수를 구하고
        //만난 직사각형들은 세그먼트 트리에서 제외해 준다.
        while(idx < 2*N && sweep[idx].pos == cur) {
            int num = sweep[idx].num;
            
            if(sweep[idx].isAdd) {
                update(1, 2*N, 1, range[num].first, range[num].second, -1);
                cnt++;
            }
            else {
                update(1, 2*N, 1, range[num].first, range[num].second, 1);
                cnt--;
            }
            
            idx++;
        }
        //두번째 수평선이 늘릴 수 있는 직사각형의 최대 갯수는 segTree[1].value
        ret = max(ret, cnt+segTree[1].value);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int ux, uy, vx, vy; cin >> ux >> uy >> vx >> vy;
        range.push_back({vy, uy});
        vec.push_back(uy); vec.push_back(vy);
    }
    
    cout << solve();

    return 0;
}