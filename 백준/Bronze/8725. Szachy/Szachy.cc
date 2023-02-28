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

int arr[200][200];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int cur = 0;
        for(int j = 0; j < N; j++) {
            int v; cin >> v;
            cur = max(cur, v);
        }
        
        ans += cur;
    }
    
    cout << ans;
    
    return 0;
}