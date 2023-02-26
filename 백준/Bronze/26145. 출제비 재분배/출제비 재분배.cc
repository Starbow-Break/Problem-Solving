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
    
    int N, M; cin >> N >> M;
    int ans[2001] = {0, };
    
    for(int i = 1; i <= N; i++) cin >> ans[i];
    
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N+M; j++) {
            int v; cin >> v;
            ans[i] -= v; ans[j] += v;
        }
    }
    
    for(int i = 1; i <= N+M; i++) cout << ans[i] << " ";
    
    return 0;
}