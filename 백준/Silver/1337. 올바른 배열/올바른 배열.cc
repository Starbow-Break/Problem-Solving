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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    vector<int> vec;
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int v; cin >> v;
        vec.push_back(v);
    }
    
    sort(vec.begin(), vec.end());
    
    int ans = 0;
    for(int i = 0; i < vec.size(); i++) {
        int cur = 0;
        for(int j = 0; j < 5; j++) {
            if(i+j < vec.size() && vec[i] <= vec[i+j] && vec[i]+4 >= vec[i+j]) {
                cur++;
            }
            
            ans = max(ans, cur);
        }
    }
    
    cout << ((ans >= 5) ? 0 : 5-ans);

    return 0;
}
