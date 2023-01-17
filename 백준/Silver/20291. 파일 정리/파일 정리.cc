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

map<string, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        string s; cin >> s; string t = "";
        
        bool flag = false;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '.') flag = true;
            else {
                if(flag) {
                    t += s[i];
                }
            }
        }
        
        auto p = mp.find(t);
        
        if(p == mp.end()) mp.insert({t, 1});
        else p->second++;
    }
    
    for(auto &item: mp) {
        cout << item.first << " " << item.second << '\n';
    }

    return 0;
}