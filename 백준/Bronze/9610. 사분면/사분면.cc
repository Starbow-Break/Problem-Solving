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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int q1, q2, q3, q4, axis; q1 = q2 = q3 = q4 = axis = 0;
    
    int N; cin >> N;
    while(N--) {
        int x, y; cin >> x >> y;
        if(x > 0 && y > 0) q1++;
        else if(x < 0 && y > 0) q2++;
        else if(x < 0 && y < 0) q3++;
        else if(x > 0 && y < 0) q4++;
        else axis++;
    }
    
    cout << "Q1: " << q1 << '\n';
    cout << "Q2: " << q2 << '\n';
    cout << "Q3: " << q3 << '\n';
    cout << "Q4: " << q4 << '\n';
    cout << "AXIS: " << axis;

    return 0;
}