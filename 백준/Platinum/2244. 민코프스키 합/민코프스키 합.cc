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

ll ccw(pii a, pii b) {
    return 1LL*a.x*b.y-1LL*a.y*b.x;
}

pii base;
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

vector<pii> getConvexHull(vector<pii> &pts) {
    stack<pii> s; vector<pii> convexHull;
    s.push(pts[0]); s.push(pts[1]);
    for(int i = 2; i < pts.size(); i++) {
        if(s.empty()) break;
        
        pii th = pts[i];
        pii sec;
        pii fir = s.top(); s.pop();
        
        while(1) {
            if(s.empty()) {
                s.push(fir); s.push(th); break;
            }
            
            sec = fir;
            fir = s.top(); s.pop();
            
            if(ccw(sec-fir, th-sec) > 0) {
                s.push(fir); s.push(sec); s.push(th);
                break;
            }
        }
    }
    
    while(!s.empty()) {
        convexHull.push_back(s.top()); s.pop();
    }
    
    reverse(convexHull.begin(), convexHull.end());
    return convexHull;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<pii> A, B, pts; pii t = {1'000'000'000, 1'000'000'000};
    int N, M; cin >> N >> M;
    while(N--) {
        int x, y; cin >> x >> y;
        A.push_back({x, y});
    }
    while(M--) {
        int x, y; cin >> x >> y;
        B.push_back({x, y});
    }
    
    for(int i = 0; i < A.size(); i++) {
        for(int j = 0; j < B.size(); j++) {
            pii pt = A[i]+B[j];
            pts.push_back(pt);
            
            if(t.x > pt.x) t = pt;
            else if(t.x == pt.x && t.y > pt.y) t = pt;
        }
    }
    
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    
    sort(pts.begin(), pts.end(), cmp1);
    base = pts[0];
    sort(pts.begin(), pts.end(), cmp2);
    
    vector<pii> convexHull = getConvexHull(pts);
    cout << convexHull.size() << '\n';
    
    int i;
    for(int i = 0; i < convexHull.size(); i++) {
        if(convexHull[i] == t) break;
    }
    
    for(int j = 0; j < convexHull.size(); j++) {
        cout << convexHull[(i+j)%convexHull.size()] << '\n';
    }

    return 0;
}