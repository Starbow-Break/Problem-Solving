#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <cassert>
#define MAX_N 100'000
#define MAX_Q 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

vector<double> lights;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K; cin >> N >> M >> K;
    
    int x, y;
    for(int i = 1; i <= N; i++) {
        cin >> x >> y;
        for(int j = 0; j < K; j++) {
            lights.push_back((double)x/(double)y);
            x += (M-x%M)*2;
        }
    }
    
    sort(lights.begin(), lights.end());
    
    int cnt = 0; double cur = 0;
    int ans = 0;
    for(auto &c: lights) {
        if(cur != c) {
            ans = max(cnt, ans);
            cnt = 1; cur = c;
        }
        else cnt++;
    }
    
    cout << ans;

    return 0;
}