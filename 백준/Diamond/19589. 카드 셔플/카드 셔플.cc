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
    bool inv; int value, cnt;
    
    node(int v) {
        l = r = p = NULL;
        inv = false; value = v;
        cnt = 0;
    }
    ~node() {
        delete l; delete r;
    }
};

int n, q; 
node *root; //스플레이 트리의 루트 노드
vector<int> cards;

//Lazy Propagation
void lazy(node *cur) {
    if(!cur->inv) return; //갱신 해 줄 필요가 없으면 바로 함수 탈출
    
    //왼쪽 서브트리와 오른쪽 서브트리를 서로 교환
    swap(cur->l, cur->r);
    cur->inv = false;
    
    //lazy 전파
    if(cur->l) cur->l->inv = !cur->l->inv;
    if(cur->r) cur->r->inv = !cur->r->inv;
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
    if(temp) temp->p = p;
    
    if(cur->p) {
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
        if(g) {
            //Zig-Zig Step
            if((cur == p->l && p == g->l) || (cur == p->r && p == g->r)) rotate(p);
            else rotate(cur); //Zig-Zag Step
        }
        rotate(cur);
    }
}

//트리 초기화
void initTree() {
    root = new node(0);
    
    node *t = root;
    for(int i = 1; i <= n; i++) {
        t->r = new node(i);
        t->r->p = t;
        t = t->r;
    }
    
    t->r = new node(n+1);
    t->r->p = t;
    t = t->r;
    
    while(t) { update(t); t = t->p; }
}

//k번째 원소 찾기 (k는 0-based)
void findKth(int k) {
    node *cur = root;
    lazy(cur);
    
    //k번째 원소를 찾아 이동한다.
    while(1) {
        while(cur->l && cur->l->cnt > k) {
            cur = cur->l; lazy(cur);
        }
        if(cur->l) k -= cur->l->cnt;
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

//생성한 배열에서 리플 셔플
void _rippleShuffle() {
    int sz = cards.size();
    vector<int> temp(sz);
    for(int i = 0; i < (sz+1)/2; i++) temp[2*i] = cards[i];
    for(int i = (sz+1)/2; i < sz; i++) temp[2*(i-(sz+1)/2)+1] = cards[i];
    for(int i = 0; i < sz; i++) cards[i] = temp[i];
}

//중위 순회 돌면서 카드 순서를 배열로 생성
void inorder(node *cur) {
    lazy(cur);
    if(cur->l) inorder(cur->l);
    cards.push_back(cur->value);
    if(cur->r) inorder(cur->r);
}

//배열을 토대로 스플레이 트리 수정
int idx = 0;
void inorder1(node *cur) {
    lazy(cur);
    if(cur->l) inorder1(cur->l);
    cur->value = cards[idx]; idx++;
    if(cur->r) inorder1(cur->r);
}

//A_i, ..., A_j를 뒤집기
void reverse(int l, int r) {
    interval(l, r); //[l, r]구간 작업을 위해 트리 변환
    node *cur = root->r->l; //[l, r]구간 작업을 위한 노드로 이동
    cur->inv = !cur->inv; //뒤집기
}

//[x, y]번째 카드를 위로 올리기
void shuffleUp(int x, int y) {
    if(x > 1) reverse(1, x-1);
    reverse(x, y); reverse(1, y);
}

//[x, y]번째 카드를 아래로 내리기
void shuffleDown(int x, int y) {
    if(y < n) reverse(y+1, n);
    reverse(x, y); reverse(x, n);
}

//리플 셔플
void rippleShuffle(int x, int y) {
    cards.clear(); idx = 0;
    interval(x, y);
    inorder(root->r->l); //중위 순회하면서 리플 셔플할 구간 배열로 복원
    _rippleShuffle(); //복원한 배열에서 리플 셔플
    inorder1(root->r->l); //셔플된 배열을 사용해서 스플레이 트리 수정
}

void printAnswer() {
    for(int i = 1; i <= n; i++) {
        findKth(i);
        cout << root->value << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> q;
    
    initTree();
    
    while(q--) {
        int i, x, y; cin >> i >> x >> y;
        switch(i) {
            case 1:
                shuffleUp(x, y);
                break;
            case 2:
                shuffleDown(x, y);
                break;
            case 3:
                rippleShuffle(x, y);
        }
    }
    
    printAnswer();

    return 0;
}