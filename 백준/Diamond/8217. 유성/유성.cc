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
#include <set>

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

struct query {
    int l, r, a;
};

int N, M; 
vector<int> area[300'001]; //각 국가에 속하는 영역들
int goal[300'001]; //목표 운석 수
query queries[300'001]; //전체 쿼리
int lo[300'001], hi[300'001]; //이분 탐색에 사용할 값
vector<int> vec[300'001]; //mid 값에 따라 국가들 분류
ll fenwick[1 << 19];

//세그먼트 트리 초기화
void initTree() {
    for(int i = 1; i < 1<<19; i++) fenwick[i] = 0;
}

void update(int x, int del) {
    while(x <= M) {
        fenwick[x] += del;
        x += x&-x;
    }
}

ll query(int x) {
    ll ret = 0;
    while(x > 0) {
        ret += fenwick[x];
        x -= x&-x;
    }
    
    return ret;
}

//유성 추가
void addMeteor(int l, int r, int a) {
    if(l <= r) { update(l, a); update(r+1, -a); }
    else {
        update(l, a); update(M+1, -a);
        update(1, a); update(r+1, -a);
    }
}

//특정 구역의 유성의 갯수
ll getMeteor(int x) {
    return query(x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        int v; cin >> v;
        area[v].push_back(i);
    }
    for(int i = 1; i <= N; i++) cin >> goal[i];
    
    int Q; cin >> Q;
    for(int i = 1; i <= Q; i++) {
        int l, r, a; cin >> l >> r >> a;
        queries[i] = {l, r, a};
    }
    
    for(int i = 1; i <= N; i++) { lo[i] = 1; hi[i] = Q+1; }
    
    while(1) {
        bool flag = false;
        initTree();
        
        for(int i = 1; i <= N; i++) {
            if(lo[i] < hi[i]) {
                vec[(lo[i]+hi[i])/2].push_back(i);
                flag = true;
            }
        }
        
        for(int mid = 1; mid <= Q; mid++) {
            addMeteor(queries[mid].l, queries[mid].r, queries[mid].a);
            
            if(vec[mid].size()) { //해당하는 국가가 있으면
                for(auto &c: vec[mid]) { //각 국가별로 유성 수 체크
                    ll numMeteor = 0;
                    for(auto &a: area[c]) {
                        numMeteor += getMeteor(a);
                        if(numMeteor >= goal[c]) break;
                    }
                    
                    if(numMeteor >= goal[c]) hi[c] = mid;
                    else lo[c] = mid+1;
                }
            }
        }
        
        if(!flag) break;
        
        for(int i = 1; i <= Q; i++) vec[i].clear();
    }
    
    for(int i = 1; i <= N; i++) {
        if(lo[i] > Q) cout << "NIE"; else cout << lo[i];
        cout << '\n';
    }

    return 0;
}