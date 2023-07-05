#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

bool check[12] = {false, };

int getIdx(pii p) {
    if(make_pair(1, 20) <= p && p <= make_pair(2, 18)) return 0;
    if(make_pair(2, 19) <= p && p <= make_pair(3, 20)) return 1;
    if(make_pair(3, 21) <= p && p <= make_pair(4, 19)) return 2;
    if(make_pair(4, 20) <= p && p <= make_pair(5, 20)) return 3;
    if(make_pair(5, 21) <= p && p <= make_pair(6, 21)) return 4;
    if(make_pair(6, 22) <= p && p <= make_pair(7, 22)) return 5;
    if(make_pair(7, 23) <= p && p <= make_pair(8, 22)) return 6;
    if(make_pair(8, 23) <= p && p <= make_pair(9, 22)) return 7;
    if(make_pair(9, 23) <= p && p <= make_pair(10, 22)) return 8;
    if(make_pair(10, 23) <= p && p <= make_pair(11, 22)) return 9;
    if(make_pair(11, 23) <= p && p <= make_pair(12, 21)) return 10;
    else return 11;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i < 7; i++) {
        int x, y; cin >> x >> y;
        int t = getIdx({x, y});
        check[t] = true;
    }
    
    int N; cin >> N;
    vector<pii> ans;
    while(N--) {
        int x, y; cin >> x >> y;
        int t = getIdx({x, y});
        if(!check[t]) ans.push_back({x, y});
    }
    
    if(ans.empty()) cout << "ALL FAILED";
    else {
        sort(ans.begin(), ans.end());
        for(auto &a: ans) cout << a;
    }

    return 0;
}