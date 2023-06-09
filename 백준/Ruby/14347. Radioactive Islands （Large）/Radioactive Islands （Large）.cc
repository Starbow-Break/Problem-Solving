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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

const double UNIT = 0.01; //적분 시 조각의 단위
const double INF = 1'000'000'000'000'000'000; //조각 수

ostream& operator<<(ostream &out, const pdd &p) {
    out << p.first << ' ' << p.second;
    return out;
}

vector<double> island; //섬들의 y좌표

//f''(x)의 값 구하기
double getf2(double x, double y, double f1) {
    double f2 = 1+f1*f1;
    
    double a = 0, b = 0, c = 0;
    for(auto &i: island) {
        double d = x*x+(y-i)*(y-i);
        a += 1/d;
        b += -2*(y-i)/(d*d);
        c += (2*x+2*(y-i)*f1)/(d*d);
    }
    
    f2 *= b*(1+f1*f1)+c*f1;
    f2 /= 1+a;
    
    return f2;
}

//초기 f'가 f1일 때, 최소 경로의 길이와 도착지점에서의 y좌표를 구함
pdd getLenAndY(double a, double b, double f1) {
    double x = -10, y = a, len = 0;
    while(x < 10) {
        double del = 1;
        for(auto &i: island) del += 1/(x*x+(y-i)*(y-i));
        del *= sqrt(1+f1*f1);
        len += del*UNIT;
        
        x += UNIT; //x는 UNIT만큼 
        y += f1*UNIT; //y는 f'(x)*UNIT만큼
        f1 += getf2(x, y, f1)*UNIT; //f1은 f''(x)*UNIT만큼
    }
    
    return {len, y};
}

//초기 f'의 범위가 [i, j]일 때, 최소 경로의 길이
double solve(double a, double b, double i, double j) {
    double ret;
    
    while(j-i > 1e-7) {
        double mid = (i+j)/2;
        pdd p = getLenAndY(a, b, mid); //초기 f'이 mid일 때, 최소 경로의 길이 및 y좌표를 구한다.
        ret = p.first; double y = p.second;
        
        if(y < b) i = mid;
        else j = mid;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        island.clear();
        cout << "Case #" << tc << ": ";
        
        int n; double a, b; cin >> n >> a >> b;
        vector<double> vec;
        vec.push_back(-2); vec.push_back(2);
        while(n--) {
            double c; cin >> c;
            island.push_back(c);
            vec.push_back((c-a)/10);
        }
        sort(vec.begin(), vec.end());
        
        double ans = INF;
        for(int i = 0; i < vec.size()-1; i++) {
            ans = min(ans, solve(a, b, vec[i], vec[i+1]));
        }
        
        cout << fixed << setprecision(2) << ans << '\n';
    }

    return 0;
}