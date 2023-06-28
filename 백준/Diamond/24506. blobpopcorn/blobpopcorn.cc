#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

struct node {
    int len, maxV; //증가 수열의 길이, 증가 수열에서의 최댓값
};

int N, Q, arr[100'001];
node segTreeL[1 << 18]; //l_i 관리
node segTreeR[1 << 18]; //r_i 관리

//---------------------------segTreeL---------------------------
//segTreeL[idx]의 증가 수열에서 lb보다 큰 값의 갯수 
int countL(int s, int e, int idx, int lb) {
    if(s == e) return segTreeL[idx].maxV > lb;
    
    int mid = (s+e)>>1;
    if(segTreeL[idx<<1].maxV <= lb) {
        return countL(mid+1, e, idx<<1|1, lb);
    }
    else {
        return countL(s, mid, idx<<1, lb)+segTreeL[idx].len-segTreeL[idx<<1].len;
    }
}

//nodeL 합치기
node mergeL(int sl, int el, int idxL, int sr, int er, int idxR) {
    if(segTreeL[idxL].maxV >= segTreeL[idxR].maxV) return segTreeL[idxL];
    
    //오른쪽 노드의 증가수열에서 l.maxV보다 큰 값의 갯수를 구한다.
    int cnt = countL(sr, er, idxR, segTreeL[idxL].maxV);
    node newNode;
    newNode.len = segTreeL[idxL].len+cnt; newNode.maxV = segTreeL[idxR].maxV;
    return newNode;
}

//segTreeL 초기화
void initTreeL(int s, int e, int idx) {
    if(s == e) {
        segTreeL[idx].len = 1;
        segTreeL[idx].maxV = arr[s];
        return;
    }
    
    int mid = (s+e)>>1;
    initTreeL(s, mid, idx<<1); initTreeL(mid+1, e, idx<<1|1);
    segTreeL[idx] = mergeL(s, mid, idx<<1, mid+1, e, idx<<1|1);
}

//segTreeL 업데이트
void updateL(int s, int e, int idx, int x, int y) {
    if(e < x || x < s) return;
    if(s == e) {
        segTreeL[idx].len = 1;
        segTreeL[idx].maxV = y;
        return;
    }
    
    int mid = (s+e)>>1;
    updateL(s, mid, idx<<1, x, y); updateL(mid+1, e, idx<<1|1, x, y);
    segTreeL[idx] = mergeL(s, mid, idx<<1, mid+1, e, idx<<1|1);
}
//---------------------------segTreeL---------------------------

//---------------------------segTreeR---------------------------
//segTreeR[idx]의 증가 수열에서 lb보다 큰 값의 갯수 
int countR(int s, int e, int idx, int lb) {
    if(s == e) return segTreeR[idx].maxV > lb;
    
    int mid = (s+e)>>1;
    if(segTreeR[idx<<1|1].maxV <= lb) {
        return countR(s, mid, idx<<1, lb);
    }
    else {
        return countR(mid+1, e, idx<<1|1, lb)+segTreeR[idx].len-segTreeR[idx<<1|1].len;
    }
}

//nodeR 합치기
node mergeR(int sl, int el, int idxL, int sr, int er, int idxR) {
    if(segTreeR[idxL].maxV <= segTreeR[idxR].maxV) return segTreeR[idxR];
    
    //오른쪽 노드의 증가수열에서 l.maxV보다 큰 값의 갯수를 구한다.
    int cnt = countR(sl, el, idxL, segTreeR[idxR].maxV);
    node newNode;
    newNode.len = segTreeR[idxR].len+cnt; newNode.maxV = segTreeR[idxL].maxV;
    return newNode;
}

//segTreeR 초기화
void initTreeR(int s, int e, int idx) {
    if(s == e) {
        segTreeR[idx].len = 1;
        segTreeR[idx].maxV = arr[s];
        return;
    }
    
    int mid = (s+e)>>1;
    initTreeR(s, mid, idx<<1); initTreeR(mid+1, e, idx<<1|1);
    segTreeR[idx] = mergeR(s, mid, idx<<1, mid+1, e, idx<<1|1);
}

//segTreeR 업데이트
void updateR(int s, int e, int idx, int x, int y) {
    if(e < x || x < s) return;
    if(s == e) {
        segTreeR[idx].len = 1;
        segTreeR[idx].maxV = y;
        return;
    }
    
    int mid = (s+e)>>1;
    updateR(s, mid, idx<<1, x, y); updateR(mid+1, e, idx<<1|1, x, y);
    segTreeR[idx] = mergeR(s, mid, idx<<1, mid+1, e, idx<<1|1);
}
//---------------------------segTreeR---------------------------

void query1(int x, int y) {
    updateL(1, N, 1, x, y);
    updateR(1, N, 1, x, y);
}

//segTreeL[1] -> l_i가 존재하지 않는 i의 갯수
//segTreeR[1] -> r_i가 존재하지 않는 i의 갯수
//즉, 구하고자 하는 값은 2*N-segTreeL[1]-segTreeR[1]이다.
int query2() {
    return 2*N-segTreeL[1].len-segTreeR[1].len;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    
    initTreeL(1, N, 1); initTreeR(1, N, 1);
    
    while(Q--) {
        int q; cin >> q;
        if(q == 1) {
            int x, y; cin >> x >> y;
            query1(x, y);
        }
        else cout << query2() << '\n';
    }

    return 0;
}