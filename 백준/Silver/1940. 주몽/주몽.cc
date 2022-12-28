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
    
    while(N--) {
        int v; cin >> v;
        vec.push_back(v);
    }
    
    sort(vec.begin(), vec.end());
    
    int i = 0; int j = vec.size()-1; int ans = 0;
    while(i < j) {
        if(vec[i]+vec[j] < M) i++;
        else if(vec[i]+vec[j] > M) j--;
        else {
            i++; j--; ans++;
        }
    }
    
    cout << ans;

    return 0;
}