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

int reverseNumber(int value) {
    int ret = 0;
    
    while(value > 0) {
        ret *= 10; ret += value%10; value /= 10;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int a, b; cin >> a >> b;
        cout << reverseNumber(reverseNumber(a)+reverseNumber(b)) << '\n';
    }
    
    return 0;
}