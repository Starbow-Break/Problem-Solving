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
#define MAX 524'287

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

//PST의 노드
struct Node {
    Node *l, *r; int v;
    
    Node() {
        l = r = NULL; v = 0;
    }
};

int arr[500'001] = {0, }, back = 0;//arr[i] = i번째 값이 추가된 쿼리 번호
Node* root[500'001]; //PST의 루트 노드

//PST 초기화
void buildTree(int l, int r, Node *cur) {
    if(l == r) { cur->v = 0; return; }
    
    int mid = l+r >> 1;
    cur->l = new Node(); cur->r = new Node();
    buildTree(l, mid, cur->l); buildTree(mid+1, r, cur->r);
    cur->v = cur->l->v+cur->r->v;
}

//index가 x인 곳에 값 1 증가
void add(int l, int r, Node *prev, Node *cur, int x) {
    if(l == r) {
        cur->v = prev->v+1; return;
    }
    
    int mid = l+r >> 1;
    if(x <= mid) {
        cur->l = new Node(); cur->r = prev->r;
        add(l, mid, prev->l, cur->l, x);
    }
    else {
        cur->l = prev->l; cur->r = new Node(); 
        add(mid+1, r, prev->r, cur->r, x);
    }
    
    cur->v = cur->l->v+cur->r->v;
}

//[i, j]의 합
int query(int l, int r, Node *cur, int i, int j) {
    if(r < i || j < l) return 0;
    if(i <= l && r <= j) return cur->v;
    
    int mid = l+r >> 1;
    return query(l, mid, cur->l, i, j)+query(mid+1, r, cur->r, i, j);
}

//1번 쿼리
void query1(int q, int x) {
    back++; arr[back] = q; //값이 q번 쿼리에서 추가됐음을 기록
    root[q] = new Node();
    add(0, MAX, root[q-1], root[q], x); //PST에 반영
}

//2번 쿼리
int query2(int q, int l, int r, int x) {
    root[q] = root[q-1]; //PST는 변화 없음
    int k = 18, ans = 0;
    Node* a = root[arr[l-1]]; Node* b = root[arr[r]];
    while(k >= 0) {
        if(x & (1 << k)) { //x의 k번째 비트가 1이면
            //배열내에 0인 비트가 있는지 우선적으로 확인
            if(b->l->v - a->l->v > 0) { a = a->l; b = b->l; }
            else { ans |= (1 << k); a = a->r; b = b->r; }
        }
        else { //0이면
            //배열내에 1인 비트가 있는지 우선적으로 확인
            if(b->r->v - a->r->v > 0) { ans |= (1 << k); a = a->r; b = b->r; }
            else { a = a->l; b = b->l; }
        }
        
        k--;
    }
    
    return ans;
}

//3번 쿼리
void query3(int q, int k) {
    back -= k; //최신 k개 제거
    root[q] = root[arr[back]]; //PST에 반영
}

//4번 쿼리
int query4(int q, int l, int r, int x) {
    root[q] = root[q-1]; //PST는 변화 없음
    return query(0, MAX, root[arr[r]], 1, x)-query(0, MAX, root[arr[l-1]], 1, x);
}

//5번 쿼리
int query5(int q, int l, int r, int k) {
    root[q] = root[q-1]; //PST는 변화 없음
    
    Node* a = root[arr[l-1]]; Node* b = root[arr[r]];
    int i = 18; int ans = 0;
    while(i >= 0) {
        int num = b->l->v - a->l->v;
        if(k <= num) { a = a->l; b = b->l; }
        else { ans |= (1 << i); a = a->r; b = b->r; k -= num; }
        i--;
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    arr[0] = 0; root[0] = new Node();
    buildTree(1, MAX, root[0]); //PST 생성
    
    int M; cin >> M;
    for(int q = 1; q <= M; q++) {
        int c, l, r, x; cin >> c;
        switch(c) {
            case 1:
                cin >> x; query1(q, x);
                break;
            case 2:
                cin >> l >> r >> x;
                cout << query2(q, l, r, x) << '\n';
                break;
            case 3:
                cin >> x; query3(q, x);
                break;
            case 4:
                cin >> l >> r >> x;
                cout << query4(q, l, r, x) << '\n';
                break;
            case 5:
                cin >> l >> r >> x;
                cout << query5(q, l, r, x) << '\n';
        }
    }

    return 0;
}