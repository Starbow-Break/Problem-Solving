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
    string word; int cnt;
    
    bool operator<(node &n) {
        if(cnt != n.cnt) return cnt < n.cnt;
        if(word.length() != n.word.length()) return word.length() < n.word.length();
        return word > n.word;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    map<string, int> mp;
    while(N--) {
        string s; cin >> s;
        if(s.length() < M) continue;
        
        auto t = mp.find(s);
        if(t == mp.end()) mp.insert({s, 1});
        else t->second++;
    }
    
    vector<node> vec;
    for(auto &m: mp) {
        vec.push_back({m.first, m.second});
    }
    
    sort(vec.rbegin(), vec.rend());
    
    for(auto &v: vec) {
        cout << v.word << '\n';
    }

    return 0;
}