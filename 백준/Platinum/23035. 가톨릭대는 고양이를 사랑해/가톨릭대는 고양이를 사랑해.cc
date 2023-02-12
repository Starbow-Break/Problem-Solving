#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#define MAX_N 100'000
#define MAX_M 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int N, M, T;
vector<pii> cat;
vector<int> vec, d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> T;
    
    while(T--) {
        int r, c; cin >> r >> c;
        if(r <= N && c <= M) cat.push_back({r, c});
    }
    
    sort(cat.begin(), cat.end());
    
    for(auto &p: cat) {
        vec.push_back(p.second);
    }
    
    for(auto &v: vec) {
        auto t = upper_bound(d.begin(), d.end(), v);
        if(t == d.end()) d.push_back(v);
        else *t = v;
    }
    
    cout << d.size();

    return 0;
}