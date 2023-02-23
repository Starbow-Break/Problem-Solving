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

bool check(string s) {
    for(int i = 0; i < s.length()-1; i++) {
        if(s[i] == 'C' && s[i+1] == 'D') return false;
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N; int ans = 0;
    while(N--) {
        string s; cin >> s;
        ans += check(s);
    }
    
    cout << ans;
    
    return 0;
}