#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

vector<int> pos;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int d, n, m; cin >> d >> n >> m;
    for(int i = 0; i < n; i++) {
        int v; cin >> v;
        pos.push_back(v);
    }
    pos.push_back(0); pos.push_back(d);
    sort(pos.begin(), pos.end());
    
    int l = 0; int r = d;
    while(l <= r) {
        int mid = (l+r)>>1;
        
        int bef = 0; int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(pos[i]-pos[bef] >= mid) {
                bef = i; continue;
            }
            
            cnt++;
        }
        
        if(cnt > m) r = mid-1;
        else l = mid+1;
    }
    
    cout << r;

    return 0;
}