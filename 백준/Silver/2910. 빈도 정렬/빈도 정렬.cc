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

struct node {
    int cnt, idx, value;
    
    bool operator<(node &N) {
        if(cnt != N.cnt) {
            return cnt > N.cnt;
        }
        
        return idx < N.idx;
    }
};

map<int, pair<int,int>> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, C; cin >> N >> C;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        
        auto t = mp.find(v);
        if(t == mp.end()) {
            mp.insert({v, {1, i}});
        }
        else {
            (t->second).first++;
        }
    }
    
    vector<node> vec;
    for(auto &iter: mp) {
        vec.push_back({iter.second.first, iter.second.second, iter.first});
    }
    
    sort(vec.begin(), vec.end());
    
    for(auto &n: vec) {
        for(int i = 0; i < n.cnt; i++) { cout << n.value << " "; }
    }

    return 0;
}