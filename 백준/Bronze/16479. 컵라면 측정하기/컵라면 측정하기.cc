#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    double K, D1, D2;
    cin >> K >> D1 >> D2;
    
    cout << fixed << setprecision(8) << K*K-(D1-D2)/2*(D1-D2)/2;
    
    return 0;
}