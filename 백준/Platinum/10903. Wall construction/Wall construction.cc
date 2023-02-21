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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const double PI = 3.141592653589793; //원주율

int N, R;
vector<pii> points;
vector<pii> convexHull;

//CCW
int ccw(pii a, pii b) {
    return a.first*b.second-a.second*b.first;
}

//sort에서 사용할 비교 함수
pii base; //기준점
bool cmp(pii &a, pii &b) {
    pii v1 = {a.first-base.first, a.second-base.second};
    pii v2 = {b.first-base.first, b.second-base.second};
    
    int c = ccw(v1, v2);
    
    if(c == 0) return a.second < b.second;
    else return c > 0;
}

bool check(pii f, pii s, pii t) {
    pii a = {t.first-s.first, t.second-s.second};
    pii b = {s.first-f.first, s.second-f.second};
    
    return ccw(b, a) > 0;
}

//컨벡스 헐 생성
void makeConvexHull() {
    for(int i = 0; i < points.size(); i++) {
        if(points[0].second > points[i].second) swap(points[0], points[i]);
    }
    
    base = points[0];
    sort(points.begin()+1, points.end(), cmp);
    
    stack<pii> s; s.push(points[0]); s.push(points[1]);
    for(int i = 2; i < points.size(); i++) {
        pii third = points[i];
        pii second = s.top(); s.pop();
        pii first = s.top(); s.pop();
        
        while(1) {
            if(check(first, second, third)) {
                s.push(first); s.push(second); s.push(third);
                break;
            }
            else {
                second = first;
                
                if(s.empty()) {
                    s.push(second); s.push(third); break;
                }
                else first = s.top(); s.pop();
            }
        }
    }
    
    while(!s.empty()) {
        convexHull.push_back(s.top()); s.pop();
    }
    
    reverse(convexHull.begin(), convexHull.end());
}

double solve() {
    makeConvexHull(); //컨벡스 헐 생성
    
    double ret = 0;
    
    //볼록껍질의 길이 구하기 (원기둥에 감기는 부분 제외)
    convexHull.push_back(convexHull[0]);
    for(int i = 0; i < convexHull.size()-1; i++) {
        double x = convexHull[i+1].first-convexHull[i].first;
        double y = convexHull[i+1].second-convexHull[i].second;
        ret += sqrt(x*x+y*y);
    }
    
    ret += PI*R*2; //원기둥에 감기는 부분
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> R;
    for(int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        points.push_back({x, y});
    }
    
    cout << setprecision(15) << solve();

    return 0;
}