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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int yt, yj; cin >> yt >> yj; bool turn = false;
    while(yt < 5 && yj < 5) {
        if(turn) yt += yj;
        else yj += yt;
        
        turn = !turn;
    }
    
    if(yt >= 5) cout << "yj";
    else cout << "yt";

    return 0;
}