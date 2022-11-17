#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

struct side {
    int x, y1, y2;
    bool isIns;
    
    bool operator<(side &S) {
        return x < S.x;
    }
};

vector<side> vec;
int segTree[1050000] = {0, };
int cntTree[1050000] = {0, };
vector<int> vecX, vecY;

void compress() {
    sort(vecX.begin(), vecX.end()); sort(vecY.begin(), vecY.end());
    vecX.erase(unique(vecX.begin(), vecX.end()), vecX.end());
    vecY.erase(unique(vecY.begin(), vecY.end()), vecY.end());
    
    for(auto &v: vec) {
        v.x = lower_bound(vecX.begin(), vecX.end(), v.x) - vecX.begin();
        v.y1 = lower_bound(vecY.begin(), vecY.end(), v.y1) - vecY.begin();
        v.y2 = lower_bound(vecY.begin(), vecY.end(), v.y2) - vecY.begin();
    }
}

void update(int s, int f, int idx, int l, int r, int delta) {
    if(f < l || r < s)  return;
    
    if(l <= s && f <= r) {
        cntTree[idx] += delta;
        if(cntTree[idx]) segTree[idx] = vecY[f+1]-vecY[s];
        else {
            if(s == f) segTree[idx] = 0;
            else segTree[idx] = segTree[idx<<1]+segTree[(idx<<1)|1];
        }
        return;
    }
    
    int mid = (s+f)>>1;
    update(s, mid, idx<<1, l, r, delta); update(mid+1, f, (idx<<1)|1, l, r, delta);
    if(cntTree[idx]) segTree[idx] = vecY[f+1]-vecY[s];
    else segTree[idx] = segTree[idx<<1]+segTree[(idx<<1)|1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int x1, x2, y1, y2; cin >> x1 >> x2 >> y1 >> y2;
        vec.push_back({x1, y1, y2, true});
        vec.push_back({x2, y1, y2, false});
        vecX.push_back(x1); vecX.push_back(x2);
        vecY.push_back(y1); vecY.push_back(y2);
    }
    
    sort(vec.begin(), vec.end());
    compress();
    
    int bef = -1; int idx = 0; ll ans = 0;
    while(idx < vec.size()) {
        int cur = vecX[vec[idx].x];
        ans += 1LL*segTree[1]*(cur-bef);
        while(idx < vec.size() && cur == vecX[vec[idx].x]) {
            if(vec[idx].isIns)
                update(0, 400000, 1, vec[idx].y1, vec[idx].y2-1, 1);
            else
                update(0, 400000, 1, vec[idx].y1, vec[idx].y2-1, -1);
            idx++;
        }
        
        bef = cur;
    }
    
    cout << ans;

    return 0;
}
