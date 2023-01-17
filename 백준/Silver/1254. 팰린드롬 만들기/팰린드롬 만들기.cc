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
    
    string s; cin >> s;
    
    int ans = 0;
    while(1) {
        bool check = true;
        
        for(int i = ans, j = s.length()-1; i <= j; i++, j--) {
            if(s[i] != s[j]) { check = false; break; }
        }
        
        if(check) break;
        
        ans++;
    }
    
    cout << s.length()+ans;

    return 0;
}