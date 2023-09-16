#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second << '\n';
    return out;
}

pii operator-(pii &a, pii &b) {
    return {a.first-b.first, a.second-b.second};
}

vector<pii> dabbaba;
pii p[4] = {{-2, 0}, {2, 0}, {0, -2}, {0, 2}};
set<pii> visited;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    while(K--) {
        int x, y; cin >> x >> y;
        dabbaba.push_back({x, y});
        visited.insert({x, y});
    }
    
    
    int ans = 0;
    for(int i = 0; i < dabbaba.size(); i++) {
        for(int j = 0; j < 4; j++) {
            pii next = dabbaba[i]-p[j];
            if(1 <= next.first && next.first <= N && 1 <= next.second && next.second <= N) {
                auto t = visited.find(next);
                
                if(t == visited.end()) {
                    ans++; visited.insert(next);
                }
            }
        }
    }
    
    cout << ans;

    return 0;
}