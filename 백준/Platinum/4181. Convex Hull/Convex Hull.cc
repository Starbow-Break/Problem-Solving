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
#define x first
#define y second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

//-----------------int pair operator-----------------
pii operator+(pii &a, pii &b) {
    return {a.x+b.x, a.y+b.y};
}

pii operator-(pii &a, pii &b) {
    return {a.x-b.x, a.y-b.y};
}

ostream& operator<<(ostream &out, const pii &a) {
    cout << a.x << ' ' << a.y;
    return out;
}
//-----------------int pair operator-----------------

//--------------------CCW--------------------
ll ccw(pii a, pii b) {
    return 1LL*a.x*b.y-1LL*a.y*b.x;
}
//--------------------CCW--------------------

//--------------------Sort--------------------
pii base; //컨벡스 헐 기준 점
bool cmp1(pii &i, pii &j) {
    if(i.x != j.x) return i.x < j.x;
    return i.y < j.y;
}

bool cmp2(pii &i, pii &j) {
    if(i == base) return true;
    if(j == base) return false;
    
    ll c = ccw(i-base, j-base);
    if(c != 0) return c > 0;
    if(i.x != j.x) return i.x < j.x;
    return abs(i.y-base.y) < abs(j.y-base.y);
}
//--------------------Sort--------------------

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<pii> pts;
    int N; cin >> N;
    while(N--) {
        int x, y; char c; cin >> x >> y >> c;
        if(c == 'Y') pts.push_back({x, y});
    }
    
    sort(pts.begin(), pts.end(), cmp1);
    base = pts[0];
    sort(pts.begin(), pts.end(), cmp2);
    
    int idx = pts.size()-1;
    while(idx > 0) {
        if(ccw(pts[idx-1]-base, pts[idx]-base) != 0) break;
        idx--;
    }
    reverse(pts.begin()+idx, pts.end());
    
    cout << pts.size() << '\n';
    for(auto &p: pts) cout << p << '\n';

    return 0;
}