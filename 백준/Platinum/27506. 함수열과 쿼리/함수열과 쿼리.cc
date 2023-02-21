#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX_N 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

//함수
struct func {
    int f[5];
    
    //합성
    func operator*(func &b) {
        return {{f[b.f[0]-1], f[b.f[1]-1], f[b.f[2]-1], f[b.f[3]-1], f[b.f[4]-1]}};
    }
    
    //역함수
    func inverse() {
        int g[5];
        for(int j = 1; j <= 5; j++) {
            g[f[j-1]-1] = j;
        }
        
        return {{g[0], g[1], g[2], g[3], g[4]}};
    }
    
    //함수 출력
    void printFunc() {
        for(int i = 0; i < 5; i++) cout << f[i] << " ";
        cout << '\n';
    }
};

func segTree[1<<18];
func arr[MAX_N+1];
func id = {{1, 2, 3, 4, 5}};

//세그트리 초기화
void initTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx] = arr[l];
        return;
    }
    
    int mid = (l+r)>>1;
    initTree(l, mid, idx<<1); initTree(mid+1, r, (idx<<1)|1);
    segTree[idx] = segTree[idx<<1]*segTree[(idx<<1)|1];
}

//세그트리 업데이트
void update(int l, int r, int idx, int u, func fu) {
    if(r < u || u < l) return;
    
    if(l == r) {
        segTree[idx] = fu; return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, u, fu); update(mid+1, r, (idx<<1)|1, u, fu);
    segTree[idx] = segTree[idx<<1]*segTree[(idx<<1)|1];
}

//fa * ... * fb
func query(int l, int r, int idx, int a, int b) {
    if(r < a || b < l) return id;
    
    if(a <= l && r <= b) return segTree[idx];
    
    int mid = (l+r)>>1;
    func fl = query(l, mid, idx<<1, a, b);
    func fr = query(mid+1, r, (idx<<1)|1, a, b);
    return fl*fr;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int f[5];
        for(int j = 0; j < 5; j++) cin >> f[j];
        
        arr[i] = {{f[0], f[1], f[2], f[3], f[4]}};
    }
    
    initTree(1, N, 1);
    
    int Q; cin >> Q;
    while(Q--) {
        int u, a, b, f[5];
        cin >> u >> a >> b; for(int j = 0; j < 5; j++) { cin >> f[j]; }
        
        func fab = {{f[0], f[1], f[2], f[3], f[4]}};
        func l = query(1, N, 1, a, u-1).inverse();
        func r = query(1, N, 1, u+1, b).inverse();
        
        func fu = l*fab*r;
        
        fu.printFunc();
        
        update(1, N, 1, u, fu);
    }

    return 0;
}