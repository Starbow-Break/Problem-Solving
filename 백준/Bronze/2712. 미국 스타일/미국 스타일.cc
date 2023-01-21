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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cout << fixed; cout.precision(4);
    
    int T; cin >> T;
    while(T--) {
        double v; string s; cin >> v >> s;
        if(s == "kg") cout << v*2.2046 << " lb" << '\n';
        if(s == "lb") cout << v*0.4536 << " kg" << '\n';
        if(s == "l") cout << v*0.2642 << " g" << '\n';
        if(s == "g") cout << v*3.7854 << " l" << '\n';
    }

    return 0;
}