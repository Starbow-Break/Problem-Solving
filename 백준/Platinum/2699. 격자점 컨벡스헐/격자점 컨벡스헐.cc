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

pii operator-(pii &a, pii &b) {
    return {a.x-b.x, a.y-b.y};
}

int ccw(pii a, pii b) {
    return a.x*b.y-a.y*b.x;
}

pii base;

bool cmp1(pii &i, pii &j) {
    if(i.y != j.y) return i.y > j.y;
    return i.x < j.x;
}

bool cmp2(pii &i, pii &j) {
    if(i == base) return true;
    if(j == base) return false;
    
    int c = ccw(i-base, j-base);
    if(c != 0) return c < 0;
    if(i.y != j.y) return i.y > j.y;
    return abs(i.x-base.x) < abs(j.x-base.x);
}

vector<pii> getConvexHull(vector<pii> &pts) {
    stack<pii> s; vector<pii> convexHull;
    s.push(pts[0]);
    if(pts.size() > 1) s.push(pts[1]);
    for(int i = 2; i < pts.size(); i++) {
        if(s.empty()) {
            cout << i << '\n'; break;
        }
        pii th = pts[i];
        pii sec;
        pii fir = s.top(); s.pop();
        
        while(1) {
            if(s.empty()) {
                s.push(fir); s.push(th); break;
            }
            
            sec = fir;
            fir = s.top(); s.pop();
            
            if(ccw(sec-fir, th-sec) < 0) {
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
    
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        vector<pii> pts;
    
        while(N--) {
            int x, y; cin >> x >> y;
            pts.push_back({x, y});
        }
        
        sort(pts.begin(), pts.end(), cmp1);
        base = pts[0];
        sort(pts.begin(), pts.end(), cmp2);
        
        vector<pii> convexHull = getConvexHull(pts);
        
        cout << convexHull.size() << '\n';
        for(auto &p: convexHull) {
            cout << p.x << ' ' << p.y << '\n';
        }
    }

    return 0;
}