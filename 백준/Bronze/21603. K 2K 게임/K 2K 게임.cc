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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K; cin >> N >> K;
    
    vector<int> ans;
    for(int i = 1; i <= N; i++) {
        if(i%10 == K%10) continue;
        if(i%10 == (2*K)%10) continue;
        
        ans.push_back(i);
    }
    
    cout << ans.size() << '\n';
    for(auto &x: ans) cout << x << ' ';
    
    return 0;
}