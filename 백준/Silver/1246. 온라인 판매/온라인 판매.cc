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
    
    int N, M; cin >> N >> M;
    vector<int> vec;
    
    for(int i = 0; i < M; i++) {
        int v; cin >> v;
        vec.push_back(v);
    }
    
    sort(vec.begin(), vec.end());
    
    int ans = 0; int price = 0; int cnt = 0;
    for(int i = vec.size()-1; i >= 0; i--) {
        if(cnt < N) cnt++;
        if(ans < vec[i]*cnt) {
            ans = vec[i]*cnt;
            price = vec[i];
        }
    }
    
    cout << price << " " << ans;

    return 0;
}