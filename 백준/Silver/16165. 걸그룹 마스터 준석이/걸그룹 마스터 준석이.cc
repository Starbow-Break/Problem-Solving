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

map<string, vector<string>> group;
map<string, string> name;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    while(N--) {
        string g; cin >> g;
        vector<string> member;
        
        int T; cin >> T;
        while(T--) {
            string n; cin >> n;
            name.insert({n, g});
            member.push_back(n);
        }
        
        sort(member.begin(), member.end());
        group.insert({g, member});
    }
    
    while(M--) {
        string s; int q; cin >> s >> q;
        
        if(q) {
            auto t = name.find(s);
            cout << t->second << '\n';
        }
        else {
            auto t = group.find(s);
            for(auto &m: t->second) {
                cout << m << '\n';
            }
        }
    }

    return 0;
}