#include <bits/stdc++.h>
#define fi first
#define se second
#define repeat(n) for(int i = 0; i < n; i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define pb push_back 
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define compress(vec) sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
 
vector<pii> stars; //별들의 위치
vector<pii> convexHull; // Convex Hull
vector<double> len;
 
pii operator-(pii &a, pii &b) {
    return {a.fi-b.fi, a.se-b.se};
}
 
ll ccw(pii a, pii b) {
    return 1LL*a.fi*b.se-1LL*a.se*b.fi;
}
 
bool cmp1(pii &a, pii &b) {
    if(a.se != b.se) return a.se < b.se;
    else return a.fi < b.fi;
}
 
pii base;
bool cmp2(pii &a, pii &b) {
    if(a == base) return true;
    if(b == base) return false;
    
    ll c = ccw(a-base, b-base);
    if(c != 0) return c > 0;
    else {
        if(a.se == b.se) return a.fi < b.fi;
        return a.se < b.se;
    }
}
 
// Convex Hull 구하기
void getCvxHull() {
    sort(all(stars), cmp1);
    base = stars.front();
    sort(all(stars), cmp2);
    
    stack<pii> s;
    for(auto &star: stars) {
        if(s.size() < 2) {
            s.push(star);
        }
        else {
            while(s.size() >= 2) {
                pii second = s.top(); s.pop();
                pii first = s.top(); s.pop();
                if(ccw(second-first, star-second) > 0) {
                    s.push(first); s.push(second);
                    break;
                }
                else {
                    s.push(first);
                }
            }
            s.push(star);
        }
    }
    
    while(!s.empty()) {
        convexHull.pb(s.top()); s.pop();
    }
    reverse(all(convexHull));
}
 
//회전하는 캘리퍼스를 사용해서 우리가 보고자 하는 값의 최솟값을 구한다.
double rotatingCalipus() {
    int sz = convexHull.size();
    
    // 각 변의 길이를 구한다.
    for(int i = 0; i < sz; i++) {
        pii dpos = convexHull[(i+1)%sz]-convexHull[i];
        len.pb(sqrt(1LL*dpos.fi*dpos.fi+1LL*dpos.se*dpos.se));
    }
    
    //처음 평행선의 위치를 찾는다. 이 때, 제일 우측에 있는 점을 선택한다.
    int i = 0, j = 0;
    for(int k = 0; k < sz; k++) {
        if(convexHull[j].se < convexHull[k].se) j = k;
        else if(convexHull[j].se == convexHull[k].se && convexHull[j].fi < convexHull[k].fi) j = k;
    }
    
    //처음 길이의 합 계산
    double sum = 0, ret;
    for(int k = i; k != j; k = (k+1)%sz) sum += len[k];
    ret = sum;
    
    // 돌려가면서 변화하는 길이의 합 계산
    // 이 때 한변이 밧줄에 완전히 포함되는 경우는 고려하지 않아도 된다.
    for(int k = 0; k <= 2*sz; k++) {
        pii dvi = convexHull[i]-convexHull[(i+1)%sz];
        pii dvj = convexHull[(j+1)%sz]-convexHull[j];
        
        ll c = ccw(dvi, dvj);
        
        if(c >= 0) { sum -= len[i]; i = (i+1)%sz; }
        if(c <= 0) { sum += len[j]; j = (j+1)%sz;  }
        ret = min(ret, sum);
    }
    
    return ret;
}
 
double solve() {
    getCvxHull();
    return rotatingCalipus();
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    repeat(N) {
        int x, y; cin >> x >> y;
        stars.pb({x, y});
    }
    
    cout << fixed << setprecision(12) << solve() << '\n';
 
    return 0;
}