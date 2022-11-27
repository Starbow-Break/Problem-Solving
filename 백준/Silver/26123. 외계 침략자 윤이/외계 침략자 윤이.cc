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
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int cnt[300001] = {0, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, D; cin >> N >> D;
    for(int i = 1; i <= N; i++) {
        int h; cin >> h; cnt[h]++;
    }
    
    ll ans = 0;
    int idx = 300000;
    while(D-- && idx > 0) {
        while(cnt[idx] == 0 && idx > 0) { idx--; }
        if(idx > 0) {
            ans += cnt[idx];
            cnt[idx-1] += cnt[idx]; cnt[idx] = 0;
        }
    }
    
    cout << ans;

    return 0;
}