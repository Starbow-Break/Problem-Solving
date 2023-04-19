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
#define MAX_N 250'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, char> pic;
typedef pair<double, double> pdd;

struct ingredient {
    int x, y, size;
    char kind;
    bool isStart;
    
    bool operator<(ingredient &i) {
        if(x == i.x) return isStart < i.isStart;
        return x < i.x;
    }
};

struct node {
    ll size, num;
    pic bottom, top;
};

int N;
node segTree[1 << 19];
vector<int> posX, posY; //모든 재료의 x좌표와 y좌표
vector<ingredient> ingredients; //재료들

void compress() {
    sort(posX.begin(), posX.end());
    sort(posY.begin(), posY.end());
    posX.erase(unique(posX.begin(), posX.end()), posX.end());
    posY.erase(unique(posY.begin(), posY.end()), posY.end());
    
    for(auto &i: ingredients) {
        i.x = lower_bound(posX.begin(), posX.end(), i.x)-posX.begin()+1;
        i.y = lower_bound(posY.begin(), posY.end(), i.y)-posY.begin()+1;
    }
}

node merge(node &l, node &r) {
    if(l.num == 0) return r;
    if(r.num == 0) return l;
    
    if(l.top.second == r.bottom.second) {
        if(l.num == 1 && l.top.first < r.bottom.first) return r;
        if(r.num == 1 && l.top.first > r.bottom.first) return l;
        return {l.size+r.size-min(l.top.first, r.bottom.first), l.num+r.num-1, l.bottom, r.top};
    }
    else
        return {l.size+r.size, l.num+r.num, l.bottom, r.top};
}

void initTree(int l, int r, int idx) {
    if(l == r) {
        segTree[idx] = {0, 0, {0, 'S'}, {0, 'S'}};
        return;
    }
    
    int mid = (l+r)>>1;
    initTree(l, mid, idx<<1); initTree(mid+1, r, idx<<1|1);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

void update(int l, int r, int idx, int y, int size, char kind, int num) {
    if(r < y || y < l) return;
    
    if(l == r) {
        segTree[idx] = {size, num, {size, kind}, {size, kind}};
        return;
    }
    
    int mid = (l+r)>>1;
    update(l, mid, idx<<1, y, size, kind, num); update(mid+1, r, idx<<1|1, y, size, kind, num);
    segTree[idx] = merge(segTree[idx<<1], segTree[idx<<1|1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int xl, xr, y; char t;
        cin >> xl >> xr >> y >> t;
        ingredients.push_back({xl, y, xr-xl+1, t, true});
        ingredients.push_back({xr+1, y, xr-xl+1, t, false});
        posX.push_back(xl); posX.push_back(xr+1);
        posY.push_back(y);
    }
    
    
    compress(); //좌표 압축
    sort(ingredients.begin(), ingredients.end());
    
    initTree(1, N, 1);
    
    int idx = 0; ll ans = 0;
    while(idx < ingredients.size()) {
        int cur = ingredients[idx].x;
        while(idx < ingredients.size() && ingredients[idx].x == cur) {
            if(ingredients[idx].isStart)
                update(1, N, 1, ingredients[idx].y, ingredients[idx].size, ingredients[idx].kind, 1);
            else
                update(1, N, 1, ingredients[idx].y, 0, 'S', 0);
            
            idx++;
        }
        ans = max(ans, segTree[1].size);
    }
    
    cout << ans;

    return 0;
}