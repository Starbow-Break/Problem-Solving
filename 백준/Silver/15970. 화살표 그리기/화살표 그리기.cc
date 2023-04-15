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

vector<int> pts[5001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int x, y; cin >> x >> y;
        pts[y].push_back(x);
    }
    
    for(int i = 1; i <= N; i++) sort(pts[i].begin(), pts[i].end());
    
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        if(pts[i].size() < 2) continue;
        for(int j = 0; j < pts[i].size(); j++) {
            if(j == 0) {
                ans += pts[i][j+1]-pts[i][j];
            }
            else if(j == pts[i].size()-1) {
                ans += pts[i][j]-pts[i][j-1];
            }
            else ans += min(pts[i][j+1]-pts[i][j], pts[i][j]-pts[i][j-1]);
        }
    }
    
    cout << ans;

    return 0;
}