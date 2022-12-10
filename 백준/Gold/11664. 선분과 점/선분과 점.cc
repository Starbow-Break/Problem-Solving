#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

class Point {
    private:
        int x, y, z;
    public:
        Point(int _x, int _y, int _z) {
            x = _x; y = _y; z = _z;
        }
        
        Point operator-(Point &B) {
            return Point(x-B.x, y-B.y, z-B.z);
        }
        
        //점P까지의 거리
        double distanceTo(Point &P) {
            return sqrt((double)((x-P.x)*(x-P.x)+(y-P.y)*(y-P.y)+(z-P.z)*(z-P.z)));
        }
        
        //직선 AB까지의 거리
        double distanceTo(Point &A, Point &B) {
            Point AB = B-A; Point AC = *this-A;
            double dAC = this->distanceTo(A); double dAB = B.distanceTo(A);
            double dAH = abs((double)(AB.x*AC.x+AB.y*AC.y+AB.z*AC.z)/dAB);
            
            return sqrt(dAC*dAC-dAH*dAH);
        }
        
        //해당 점을 지나고 선분 AB와 수직으로 만나는 반직선을 그릴 수 있는지 확인 
        bool check(Point &A, Point &B) {
            Point AB = B-A;
            Point AC = *this-A;
            Point CB = B-*this;
            
            return ((AB.x*AC.x+AB.y*AC.y+AB.z*AC.z >= 0) && (AB.x*CB.x+AB.y*CB.y+AB.z*CB.z >= 0));
        }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int ax, ay, az, bx, by, bz, cx, cy, cz;
    cin >> ax >> ay >> az >> bx >> by >> bz >> cx >> cy >> cz;
    
    Point A = Point(ax, ay, az);
    Point B = Point(bx, by, bz);
    Point C = Point(cx, cy, cz);
    
    cout << fixed; cout.precision(12);
    if(C.check(A, B)) {
        cout << C.distanceTo(A, B);
    }
    else {
        cout << min(C.distanceTo(A), C.distanceTo(B));
    }

    return 0;
}
