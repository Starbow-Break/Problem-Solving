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

//스플레이 트리의 노드
struct node {
    node *l, *r, *p;
    int cnt, value; bool inv;
    
    node(int v) {
        l = r = p = NULL;
        cnt = 0; value = v;
        inv = false;
    }
    ~node() {
        delete l;
        delete r;
    }
};

node *root, *arr[2'500'010];

//Lazy Propagation
void lazy(node *cur) {
    if(!cur->inv) return; //갱신 해 줄 필요가 없으면 바로 함수 탈출
    
    //왼쪽 서브트리와 오른쪽 서브트리를 서로 교환
    swap(cur->l, cur->r);
    cur->inv = false;
    
    //lazy 전파
    if(cur->l != NULL) cur->l->inv = !cur->l->inv;
    if(cur->r != NULL) cur->r->inv = !cur->r->inv;
}

//cur 노드를 업데이트
void update(node *cur) {
    cur->cnt = 1;
    cur->cnt += (cur->l ? cur->l->cnt : 0)+(cur->r ? cur->r->cnt : 0);
}

//Rotate 연산
void rotate(node *cur) {
    node *p = cur->p; //cur의 부모 노드
    lazy(p); lazy(cur);
    
    node *temp = NULL;
    if(cur == p->l) { //cur이 부모 노드의 왼쪽 자식인 경우
        p->l = temp = cur->r; cur->r = p;
    }
    else { //오른쪽 자식인 경우
        p->r = temp = cur->l; cur->l = p;
    }
    
    cur->p = p->p;
    p->p = cur;
    if(temp != NULL) temp->p = p;
    
    if(cur->p != NULL) {
        if(p == cur->p->l) cur->p->l = cur;
        else cur->p->r = cur;
    }
    else root = cur;
    
    //p와 cur의 위치가 변경 됐으므로 변경된 위치에 맞게 노드를 업데이트 시켜준다.
    update(p); update(cur);
}

//Splay 연산
void splay(node *cur) {
    //cur이 root 노드가 될 때까지 반복
    while(cur->p) {
        node *p = cur->p, *g = p->p;
        if(g != NULL) {
            //Zig-Zig Step
            if((cur == p->l && p == g->l) || (cur == p->r && p == g->r)) rotate(p);
            else rotate(cur); //Zig-Zag Step
        }
        rotate(cur);
    }
}

//트리 초기화
void initTree(int n) {
    if(root != NULL) delete root;
    root = new node(0); //더미 노드
    arr[0] = root;
    
    node *cur = root;
    for(int i = 1; i <= n; i++) {
        cur->r = new node(i);
        arr[i] = cur->r;
        cur->r->p = cur;
        cur = cur->r;
    }
    
    cur->r = new node(n+1); //더미 노드
    arr[n+1] = cur->r; 
    cur->r->p = cur;
    
    update(arr[n+1]);
    for(int i = n; i >= 1; i--) update(arr[i]);
    update(arr[0]);
}

//k번째 원소 찾기 (k는 0-based)
void findKth(int k) {
    node *cur = root;
    lazy(cur);
    
    //k번째 원소를 찾아 이동한다.
    while(1) {
        while(cur->l != NULL && cur->l->cnt > k) {
            cur = cur->l; lazy(cur);
        }
        if(cur->l != NULL) k -= cur->l->cnt;
        if(!k) break;
        k--;
        cur = cur->r;
        lazy(cur);
    }
    
    splay(cur); //k번째 원소를 루트 노드로 끌어올린다.
}

//[l, r]구간 작업을 위해 트리 변환
void interval(int l, int r) {
    findKth(l-1); //(l-1)번째 원소를 찾는다.
    node *t = root;
    root = t->r; root->p = NULL;
    findKth(r-l+1); //(r+1)번째 원소를 찾는다.
    t->r = root; root->p = t;
    root = t;
}

//A_i, ..., A_j를 뒤집기
void reverse(int l, int r) {
    if(l == r) return;
    
    interval(l, r); //[l, r]구간 작업을 위해 트리 변환
    node *cur = root->r->l; //[l, r]구간 작업을 위한 노드로 이동
    cur->inv = !cur->inv; //뒤집기
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    initTree(s.length());
    
    int m; cin >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        reverse(a, b);
    }
    
    for(int i = 1; i <= s.length(); i++) {
        findKth(i);
        cout << s[root->value-1];
    }

    return 0;
}