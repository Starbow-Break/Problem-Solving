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
    
    string s; cin >> s;
    string ans = "";
    for(int i = 0; i < s.length(); i++) {
        if(i == 0 || s[i-1] == '-') {
            ans += s[i];
        }
    }
    
    cout << ans;

    return 0;
}