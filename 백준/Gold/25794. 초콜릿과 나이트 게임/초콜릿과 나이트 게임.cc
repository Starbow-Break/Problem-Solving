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
vector<pii> route;

void move(int a, int b) {
    route.push_back({a, b});
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int X, Y; cin >> X >> Y;
    if(X < Y) swap(X, Y);
    
    if(Y == 0) {
        move(0, X); move(X, X); move(2*X, X); move(2*X, 0);
        move(2*X, -X); move(X, -X); move(X, 0);
    }
    else {
        if(X == Y) {
            move(X, Y); move(2*X, 0); move(3*X, -Y); move(2*X, -2*Y);
            move(X, -3*Y); move(0, -2*Y); move(X, -Y);
        }
        else {
            move(-Y, X); move(X-Y, X-Y); move(X, 2*X-Y); move(X+Y, X-Y);
            move(2*X+Y, X); move(2*X, 0); move(3*X, -Y); move(2*X, -2*Y);
            move(2*X+Y, -X-2*Y); move(X+Y, -X-Y); move(X, -2*X-Y); move(X-Y, -X-Y);
            move(-Y, -X-2*Y); move(0, -2*Y); move(X, -Y);
        }
    }
    
    cout << route.size() << '\n';
    for(auto &p: route) {
        cout << p.first << " " << p.second << '\n';
    }

    return 0;
}