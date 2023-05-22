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
#define MAX 1'000'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

struct Node {
    Node *l, *r; int v;
    Node() { l = r = NULL; v = 0; }
};

int N; 
int arr[MAX+1]; vector<int> values;
Node* root[MAX+1];

//좌표 압축
void compress() {
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for(int i = 1; i <= N; i++) {
        arr[i] = lower_bound(values.begin(), values.end(), arr[i])-values.begin()+1;
    }
}

void initPST(int l, int r, Node *cur) {
    if(l == r) {
        cur->v = 0; return;
    }
    
    int mid = l+r >> 1;
    cur->l = new Node(); cur->r = new Node();
    initPST(l, mid, cur->l); initPST(mid+1, r, cur->r);
    cur->v = cur->l->v + cur->r->v;
}

void update(int l, int r, Node *prev, Node *cur, int t) {
    if(l == r) {
        cur->v = 1; return;
    }
    
    int mid = l+r >> 1;
    if(t <= mid) {
        cur->l = new Node(); cur->r = prev->r;
        update(l, mid, prev->l, cur->l, t);
    }
    else {
        cur->r = new Node(); cur->l = prev->l;
        update(mid+1, r, prev->r, cur->r, t);
    }
    
    cur->v = cur->l->v + cur->r->v;
}

void buildPST() {
    int check[1'000'001] = {0, };
    compress();
    
    root[0] = new Node();
    initPST(1, N, root[0]);
    
    for(int i = 1; i <= N; i++) {
        if(check[arr[i]]) { //이전에 나온 값이면
            //PST에 반영
            root[i] = new Node();
            update(1, N, root[i-1], root[i], check[arr[i]]);
            check[arr[i]] = i;
        }
        else { //이전에 나온 값이 아니면
            root[i] = root[i-1]; //이 때는 PST에 변화가 없다
            check[arr[i]] = i;
        }
    }
}

int query(int l, int r, Node *cur, int i, int j) {
    if(r < i || j < l) return 0;
    if(i <= l && r <= j) return cur->v;
    
    int mid = l+r >> 1;
    return query(l, mid, cur->l, i, j)+query(mid+1, r, cur->r, i, j);
}

int solve(int l, int r) {
    return r-l+1-query(1, N, root[r], l, r)+query(1, N, root[l-1], l, r);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        values.push_back(arr[i]);
    }
    
    buildPST();
    
    int Q; cin >> Q; int q = 0;
    while(Q--) {
        int x, r; cin >> x >> r;
        q = solve((x+q), r);
        cout << q << '\n';
    }

    return 0;
}