#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int solve(string s, string t) {
    queue<int> q[26];
    
    for(int i = 0; i < s.length(); i++) {
        q[s[i]-'a'].push(i);
    }
    
    int ret = 0; int cur = -1;
    while(1) {
        for(int j = 0; j < t.length(); j++) {
            while(!q[t[j]-'a'].empty() && q[t[j]-'a'].front() < cur) {
                q[t[j]-'a'].pop();
            }
            
            if(q[t[j]-'a'].empty()) return ret;
            cur = q[t[j]-'a'].front(); q[t[j]-'a'].pop();
        }
        
        ret++; cur = -1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s, t; cin >> s >> t;
    cout << solve(s, t);
    
    return 0;
}