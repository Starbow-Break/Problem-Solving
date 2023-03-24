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

int arr[4'000'001];

ll solve(string s) {
    int r = -1, p = -1;
    string t;
    for(int i = 0; i < s.length(); i++) {
        t += '#'; t += s[i];
    }
    t += '#';
    
    for(int i = 0; i < t.length(); i++) {
        arr[i] = (i > r ? 0 : min(r-i, arr[2*p-i]));
        
        while(i-arr[i] > 0 && i+arr[i] < t.length()-1 && t[i-arr[i]-1] == t[i+arr[i]+1]) {
            arr[i]++;
        }
        
        if(r < arr[i]+i) {
            r = arr[i]+i; p = i;
        }
    }
    
    ll ret = 0;
    for(int i = 0; i < t.length(); i++) ret += arr[i]/2+(t[i] != '#');
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    cout << solve(s) << '\n';
    
    return 0;
}