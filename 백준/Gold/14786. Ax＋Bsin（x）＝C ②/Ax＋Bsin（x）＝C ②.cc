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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    double A, B, C; cin >> A >> B >> C;
    
    double i = 0, j = 200'000;
    while(abs(j-i) > 1e-10) {
        double mid = (i+j)/2;
        if(A*mid+B*sin(mid) < C) i = mid;
        else j = mid;
    }
    
    cout << fixed << setprecision(15) << i;
    
    return 0;
}