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
    
    int T; cin >> T;
    while(T--) {
        int C; cin >> C;
        cout << C/25 << " "; C %= 25;
        cout << C/10 << " "; C %= 10;
        cout << C/5 << " "; C %= 5;
        cout << C << '\n';
    }

    return 0;
}