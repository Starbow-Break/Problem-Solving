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

double dist(pii &a, pii &b) {
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

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
    if(i.y != j.y) return i.y < j.y;
    return i.x < j.x;
}

bool cmp2(pii &i, pii &j) {
    if(i == base) return true;
    if(j == base) return false;
    
    ll c = ccw(i-base, j-base);
    if(c != 0) return c > 0;
    if(i.y != j.y) return i.y < j.y;
    return abs(i.x-base.x) < abs(j.x-base.x);
}
//--------------------Sort--------------------

vector<pii> getConvexHull(vector<pii> &pts) {
    stack<pii> s; vector<pii> convexHull;
    
    //중복 점 제거
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    
    //컨벡스 헐을 구할 수 있도록 정렬
    sort(pts.begin(), pts.end(), cmp1);
    base = pts[0];
    sort(pts.begin(), pts.end(), cmp2);
    
    //컨벡스 헐 구하기
    s.push(pts[0]); s.push(pts[1]);
    for(int i = 2; i < pts.size(); i++) {
        if(s.empty()) break;
        
        pii three = pts[i];
        pii two;
        pii one = s.top(); s.pop();
        
        while(1) {
            if(s.empty()) {
                s.push(one); s.push(three); break;
            }
            
            two = one;
            one = s.top(); s.pop();
            
            if(ccw(two-one, three-two) > 0) {
                s.push(one); s.push(two); s.push(three);
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
    
    vector<pii> pts; //점들의 집합

    int N; cin >> N;
    while(N--) {
        int x, y; cin >> x >> y;
        pts.push_back({x, y});
    }
        
    vector<pii> convexHull = getConvexHull(pts);
        
    ll area = 0; int sz = convexHull.size();
    for(int i = 1; i < sz-1; i++) {
        area += ccw(convexHull[i]-convexHull[0], convexHull[(i+1)%sz]-convexHull[0]);
    }
    area /= 2;
        
    cout << area/50 << '\n';

    return 0;
}