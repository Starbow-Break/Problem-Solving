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
    
    map<string, int> mp;
    
    string s; int cnt = 0;
    while(getline(cin, s)) {
        cnt++;
        
        auto t = mp.find(s);
        if(t == mp.end()) {
            mp.insert({s, 1});
        }
        else {
            (t->second)++;
        }
    }
    
    cout << fixed << setprecision(4);
    for(auto &iter: mp) {
        cout << iter.first << " " << (double)iter.second/cnt*100 << '\n';
    }

    return 0;
}