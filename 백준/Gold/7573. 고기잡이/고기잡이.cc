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

vector<int> pos[10'001];
vector<pii> fishes;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, l, M; cin >> N >> l >> M; l /= 2;
    for(int i = 1; i <= M; i++) {
        int a, b; cin >> a >> b;
        pos[a].push_back(b);
        fishes.push_back({a, b});
    }
    
    int ans = 0;
    for(auto &f: fishes) {
        int x = f.first, y = f.second;
        
        for(int w = 1; w < l; w++) {
            for(int t = 0; t <= l-w; t++) {
                int cnt = 0;
                for(int i = max(1, x); i <= min(N, x+w); i++) {
                    for(auto &j: pos[i]) {
                        if(max(y-t, 1) <= j && j <= min(N, y+(l-w)-t)) cnt++;
                    }
                }
                ans = max(ans, cnt);
            }

            for(int t = 0; t <= w; t++) {
                int cnt = 0;
                for(int i = max(1, x-t); i <= min(N, x+w-t); i++) {
                    for(auto &j: pos[i]) {
                        if(max(1, y) <= j && j <= min(N, y+(l-w))) cnt++;
                    }
                }
                ans = max(ans, cnt);
            }
            
            for(int t = 0; t <= l-w; t++) {
                int cnt = 0;
                for(int i = max(1, x-w); i <= min(N, x); i++) {
                    for(auto &j: pos[i]) {
                        if(max(1, y-t) <= j && j <= min(N, y+(l-w)-t)) cnt++;
                    }
                }
                ans = max(ans, cnt);
            }

            for(int t = 0; t <= w; t++) {
                int cnt = 0;
                for(int i = max(1, x-t); i <= min(N, x+w-t); i++) {
                    for(auto &j: pos[i]) {
                        if(max(1, y-(l-w)) <= j && j <= min(N, y)) cnt++;
                    }
                }
                ans = max(ans, cnt);
            }
        }
    }
    
    cout << ans;
    
    return 0;
}