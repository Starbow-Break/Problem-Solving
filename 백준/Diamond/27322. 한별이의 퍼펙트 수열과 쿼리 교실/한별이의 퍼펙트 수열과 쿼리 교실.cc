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

const int INF = 2'000'000'000;

struct node {
    int cnt[12]; //cnt[i] == 범위 안에 들어 있는 i(cnt[11]은 11 이상)의 갯수
    ll sumOver10; //10보다 큰 수들의 합
    int minV, maxV;
    int maxLazy, minLazy, sumLazy;
};

int A[500'001];
node segTree[1<<20];

node merge(node &a, node &b) {
    node ret;
    
    for(int i = 0; i <= 11; i++) ret.cnt[i] = a.cnt[i] + b.cnt[i];
    ret.sumOver10 = a.sumOver10 + b.sumOver10;
    ret.minV = min(a.minV, b.minV);
    ret.maxV = max(a.maxV, b.maxV);
    
    ret.sumLazy = 0;
    ret.minLazy = 0; ret.maxLazy = INF;
    
    return ret;
}

//노드 갱신 (여기서 lazy 전파 안함)
void propagate(int l, int r, int idx) {
    //갱신 할게 없으면 바로 함수 탈출
    if(segTree[idx].minV == 0 && segTree[idx].maxV == INF && segTree[idx].sumLazy == 0)
        return;
    
    //maxLazy, minLazy 사용
    if(segTree[idx].minLazy > segTree[idx].maxV) {
        segTree[idx].minV = segTree[idx].minLazy;
        segTree[idx].maxV = segTree[idx].minLazy;
    }
    else if(segTree[idx].maxLazy < segTree[idx].minV) {
        segTree[idx].minV = segTree[idx].maxLazy;
        segTree[idx].maxV = segTree[idx].maxLazy;
    }
    else {
        segTree[idx].minV = max(segTree[idx].minV, segTree[idx].minLazy);
        segTree[idx].maxV = min(segTree[idx].maxV, segTree[idx].maxLazy);
    }
    
    //cnt 갱신
    if(segTree[idx].minV <= 10) {
        for(int i = 0; i < segTree[idx].minV; i++) {
            segTree[idx].cnt[segTree[idx].minV] += segTree[idx].cnt[i];
            segTree[idx].cnt[i] = 0;
        }
    }
    if(segTree[idx].maxLazy <= 10) {
        for(int i = 11; i > segTree[idx].maxV; i--) {
            segTree[idx].sumOver10 = 0;
            segTree[idx].cnt[segTree[idx].maxV] += segTree[idx].cnt[i];
            segTree[idx].cnt[i] = 0;
        }
    }
    
    //sumLazy 사용
    segTree[idx].minV += segTree[idx].sumLazy;
    segTree[idx].maxV += segTree[idx].sumLazy;
    if(segTree[idx].sumLazy > 0) {
        for(int i = 11; i >= 0; i--) {
            if(i+segTree[idx].sumLazy >= 11) {
                if(i == 11) {
                    segTree[idx].sumOver10 += segTree[idx].cnt[i]*segTree[idx].sumLazy;
                }
                else {
                    segTree[idx].sumOver10 += segTree[idx].cnt[i]*(i+segTree[idx].sumLazy);
                    segTree[idx].cnt[11] += segTree[idx].cnt[i];
                    segTree[idx].cnt[i] = 0;
                }
            }
            else {
                segTree[idx].cnt[i+segTree[idx].sumLazy] += segTree[idx].cnt[i];
                segTree[idx].cnt[i] = 0;
            }
        }
    }
    
    //lazy 전파
    if(l != r) {
        int m = segTree[idx].minLazy-segTree[idx<<1].sumLazy;
        int M = segTree[idx].maxLazy-segTree[idx<<1].sumLazy;
        
        if(m > segTree[idx<<1].maxLazy) {
            segTree[idx<<1].minLazy = segTree[idx].minLazy;
            segTree[idx<<1].maxLazy = segTree[idx].minLazy;
            segTree[idx<<1].sumLazy = 0;
        }
        else if(M < segTree[idx<<1].minLazy) {
            segTree[idx<<1].minLazy = segTree[idx].maxLazy;
            segTree[idx<<1].maxLazy = segTree[idx].maxLazy;
            segTree[idx<<1].sumLazy = 0;
        }
        else {
            segTree[idx<<1].minLazy = max(m, segTree[idx<<1].minLazy);
            segTree[idx<<1].maxLazy = min(M, segTree[idx<<1].maxLazy);
        }
        
        segTree[idx<<1].sumLazy += segTree[idx].sumLazy;
        
        m = segTree[idx].minLazy-segTree[idx<<1|1].sumLazy;
        M = segTree[idx].maxLazy-segTree[idx<<1|1].sumLazy;
        if(m > segTree[idx<<1|1].maxLazy) {
            segTree[idx<<1|1].minLazy = segTree[idx].minLazy;
            segTree[idx<<1|1].maxLazy = segTree[idx].minLazy;
            segTree[idx<<1|1].sumLazy = 0;
        }
        else if(M < segTree[idx<<1|1].minLazy) {
            segTree[idx<<1|1].minLazy = segTree[idx].maxLazy;
            segTree[idx<<1|1].maxLazy = segTree[idx].maxLazy;
            segTree[idx<<1|1].sumLazy = 0;
        }
        else {
            segTree[idx<<1|1].minLazy = max(m, segTree[idx<<1|1].minLazy);
            segTree[idx<<1|1].maxLazy = min(M, segTree[idx<<1|1].maxLazy);
        }
        
        segTree[idx<<1|1].sumLazy += segTree[idx].sumLazy;
    }
    
    //Lazy 값 초기화
    segTree[idx].minLazy = 0, segTree[idx].maxLazy = INF, segTree[idx].sumLazy = 0;
}

void init(int l, int r, int idx) {
    if(l == r) {
        segTree[idx].minLazy = 0; segTree[idx].maxLazy = INF;
        segTree[idx].sumLazy = 0; segTree[idx].sumOver10 = 0;
        
        for(int i = 0; i <= 11; i++) {
            segTree[idx].cnt[i] = 0; 
            segTree[idx].minV = A[l]; segTree[idx].maxV = A[l];
            
            if(i <= 10 && i == A[l]) segTree[idx].cnt[i] = 1;
            if(i == 11 && i <= A[l]) {
                segTree[idx].cnt[i] = 1;
                segTree[idx].sumOver10 += A[l];
            }
        }
        
        return;
    }
    
    int mid = (l+r)>>1;
    init(l, mid, idx<<1); init(mid+1, r, idx<<1|1);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

//1번 쿼리
void query1(int l, int r, int idx, int i, int j, int x) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree[idx].maxLazy = x;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r)>>1;
    query1(l, mid, idx<<1, i, j, x); query1(mid+1, r, idx<<1|1, i, j, x);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

//2번 쿼리
void query2(int l, int r, int idx, int i, int j, int x) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree[idx].minLazy = x;
        propagate(l, r, idx);
        return;
    }

    int mid = (l+r)>>1;
    query2(l, mid, idx<<1, i, j, x); query2(mid+1, r, idx<<1|1, i, j, x);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

//3번 쿼리
void query3(int l, int r, int idx, int i, int j, int x) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return;
    
    if(i <= l && r <= j) {
        segTree[idx].sumLazy += x;
        propagate(l, r, idx);
        return;
    }
    
    int mid = (l+r)>>1;
    query3(l, mid, idx<<1, i, j, x); query3(mid+1, r, idx<<1|1, i, j, x);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

//4번 쿼리
int query4(int l, int r, int idx, int i, int j) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return INF;
    
    if(i <= l && r <= j) return segTree[idx].minV;
    
    int mid = (l+r)>>1;
    return min(query4(l, mid, idx<<1, i, j), query4(mid+1, r, idx<<1|1, i, j));
}

//5번 쿼리
int query5(int l, int r, int idx, int i, int j) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) return segTree[idx].maxV;
    
    int mid = (l+r)>>1;
    return max(query5(l, mid, idx<<1, i, j), query5(mid+1, r, idx<<1|1, i, j));
}

//6번 쿼리
ll query6(int l, int r, int idx, int i, int j) {
    propagate(l, r, idx);
    
    if(r < i || j < l) return 0;
    
    if(i <= l && r <= j) {
        ll ret = 0;
        for(int i = 0; i <= 10; i++) {
            ret += i*segTree[idx].cnt[i];
        }
        ret += segTree[idx].sumOver10;
        return ret;
    }
    
    int mid = (l+r)>>1;
    return query6(l, mid, idx<<1, i, j)+query6(mid+1, r, idx<<1|1, i, j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N; 
    for(int i = 1; i <= N; i++) cin >> A[i];
    
    init(1, N, 1);
    
    int M; cin >> M;
    while(M--) {
        int q, l, r, x; cin >> q;
        
        vector<int> vec(1); vec[0] = 1;
    
        switch(q) {
            case 1:
                cin >> l >> r >> x;
                query1(1, N, 1, l, r, x);
                break;
            case 2:
                cin >> l >> r >> x;
                query2(1, N, 1, l, r, x);
                break;
            case 3:
                cin >> l >> r >> x;
                query3(1, N, 1, l, r, x);
                break;
            case 4:
                cin >> l >> r;
                cout << query4(1, N, 1, l, r) << '\n';
                break;
            case 5:
                cin >> l >> r;
                cout << query5(1, N, 1, l, r) << '\n';
                break;
            case 6:
                cin >> l >> r;
                cout << query6(1, N, 1, l, r) << '\n';
        }
    }
    
    return 0;
}

//------------ 디버깅용-----------
/*cout << '*' << l << ' ' << r << '*' << '\n';
vector<int> vec(3); vec[0] = idx, vec[1] = idx<<1, vec[2] = idx<<1|1;
//vector<int> vec(1); vec[0] = 1;
for(auto &idx: vec) {
    for(int i = 1; i <= 11; i++) {
        cout << segTree[idx].cnt[i] << ' ';
    }
    cout << '\n';
    
    cout << segTree[idx].sumOver10 << ' ' << segTree[idx].minV << ' ' << segTree[idx].maxV << '\n';  
}*/