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

bool check(int i) {
    return i/10000 < 24 && (i%10000)/100 < 60 && i%100 < 60;
}

int solve(string s, string t) {
    int a = 0, b = 0;
    
    int w = 100000;
    for(int i = 0; i <= 7; i++) {
        if(i != 2 && i != 5) {
            a += (s[i]-'0')*w;
            w /= 10;
        }
    }
    
    w = 100000;
    for(int i = 0; i <= 7; i++) {
        if(i != 2 && i != 5) {
            b += (t[i]-'0')*w;
            w /= 10;
        }
    }
    
    int ans = 0;
    if(a < b) {
        for(int i = a; i <= b; i++) ans += (check(i) && i%3 == 0);
    }
    else {
        for(int i = a; i <= 235959; i++) ans += (check(i) && i%3 == 0);
        for(int i = 0; i <= b; i++) ans += (check(i) && i%3 == 0);
    }
    
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i < 3; i++) {
        string s, t; cin >> s >> t;
        cout << solve(s, t) << '\n';
    }
    
    return 0;
}