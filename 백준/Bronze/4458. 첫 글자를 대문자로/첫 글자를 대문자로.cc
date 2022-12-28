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
    
    int N; cin >> N; cin.ignore();
    while(N--) {
        string s; getline(cin, s);
        if('a' <= s[0] && s[0] <= 'z') { s[0] = s[0]-'a'+'A'; }
        cout << s << '\n';
    }

    return 0;
}