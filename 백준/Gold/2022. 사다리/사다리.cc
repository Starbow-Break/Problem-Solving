#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

double x, y, c;

double h(double l) {
    return sqrt(x*x-l*l)*sqrt(y*y-l*l)/(sqrt(x*x-l*l)+sqrt(y*y-l*l));
}

double solve() {
    double i = 0; double j = min(x, y);
    
    while(1) {
        if(abs(i-j) < 1e-5) return i;
        
        double mid = (i+j)/2.00;
        double cc = h(mid);
        
        if(cc < c) j = mid;
        else i = mid;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> x >> y >> c;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << solve();

    return 0;
}