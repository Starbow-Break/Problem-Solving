#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int cnt[2000001] = {0, };
vector<int> school;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int v; cin >> v;
        school.push_back(v);
    }
    
    for(auto &s: school) {
        for(int i = 1; i*i <= s; i++) {
            if(!(s%i)) {
                cnt[i]++;
                if(i != s/i) cnt[s/i]++;
            }
        }
    }
    
    ll ans = 0;
    for(int i = 1; i <= 2000000; i++) {
        if(cnt[i] >= 2)
            ans = max(ans, 1LL*cnt[i]*i);
    }
    
    cout << ans;

    return 0;
}
