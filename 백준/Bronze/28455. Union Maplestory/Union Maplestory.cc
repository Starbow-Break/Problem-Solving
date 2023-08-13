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

int occupation(int level) {
    if(level >= 250) return 5;
    if(level >= 200) return 4;
    if(level >= 140) return 3;
    if(level >= 100) return 2;
    if(level >= 60) return 1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<int> levels;
    
    while(N--) {
        int v; cin >> v;
        levels.push_back(v);
    }
    
    sort(levels.rbegin(), levels.rend());
    
    int raid = 0, cnt = 0, occup = 0;
    
    for(auto &l: levels) {
        if(cnt < 42) {
            raid += l; cnt++;
            occup += occupation(l);
        }
        
    }
    
    cout << raid << ' ' << occup;

    return 0;
}