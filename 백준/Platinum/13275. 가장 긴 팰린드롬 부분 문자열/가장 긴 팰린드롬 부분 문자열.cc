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

int arr[200'001];

int solve(string s) {
    //Manacher 알고리즘
    int r = 0, p = 0;
    string t = "";
    
    for(int i = 0; i < s.length(); i++) {
        t += '#'; t += s[i];
    }
    t += '#';
    
    for(int i = 0; i < t.length(); i++) {
        arr[i] = (r < i ? 0 : min(arr[2*p-i], r-i));
        
        while(i-arr[i]-1 >= 0 && i+arr[i]+1 < t.length() && t[i-arr[i]-1] == t[i+arr[i]+1])
            arr[i]++;
        
        if(r < arr[i]+i) {
            r = arr[i]+i; p = i;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < t.length(); i++) {
        ans = max(ans, arr[i]);
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s; cin >> s;
    cout << solve(s);

    return 0;
}