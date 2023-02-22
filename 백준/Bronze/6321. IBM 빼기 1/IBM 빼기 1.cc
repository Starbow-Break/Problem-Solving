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
    
    int T; cin >> T;
    for(int i = 1; i <= T; i++) {
        cout << "String #" << i << '\n';
        string s, t = ""; cin >> s;
        for(auto &c: s) {
            int i = c-'A'; i = (i+1)%26;
            t += ('A'+i);
        }
        
        cout << t << '\n' << '\n';
    }

    return 0;
}