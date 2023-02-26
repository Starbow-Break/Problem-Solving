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

bool isTime(int n, int m) {
    return (n <= 23 && m <= 59);
}

bool isDate(int n, int m) {
    if(n == 0 || n >= 13) return false;
    
    switch(n) {
        case 2: return (m >= 1 && m <= 29);
        case 4:
        case 6:
        case 9:
        case 11: return (m >= 1 && m <= 30);
        default: return (m >= 1 && m <= 31);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int n, m; cin >> n >> m;
        cout << (isTime(n, m) ? "Yes" : "No") << ' ' << (isDate(n, m) ? "Yes" : "No") << '\n';
    }
    
    return 0;
}