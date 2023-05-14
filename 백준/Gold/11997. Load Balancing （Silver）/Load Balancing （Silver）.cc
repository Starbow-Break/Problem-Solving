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

vector<pii> points;
vector<int> vecX, vecY;
int sum[1'000][1'000] = {0, };

void compress() {
    sort(vecX.begin(), vecX.end());
    sort(vecY.begin(), vecY.end());
    vecX.erase(unique(vecX.begin(), vecX.end()), vecX.end());
    vecY.erase(unique(vecY.begin(), vecY.end()), vecY.end());
    
    for(auto &p: points) {
        p.first = lower_bound(vecX.begin(), vecX.end(), p.first)-vecX.begin();
        p.second = lower_bound(vecY.begin(), vecY.end(), p.second)-vecY.begin();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int x, y; cin >> x >> y;
        points.push_back({x, y});
        vecX.push_back(x); vecY.push_back(y);
    }
    
    compress();
    
    for(auto &p: points) { 
        sum[p.first][p.second]++; 
    }
    
    for(int i = 0; i < 1'000; i++) {
        for(int j = 1; j < 1'000; j++) {
            sum[i][j] += sum[i][j-1];
        }
    }
    
    for(int j = 0; j < 1'000; j++) {
        for(int i = 1; i < 1'000; i++) {
            sum[i][j] += sum[i-1][j];
        }
    }
    
    int ans = 1000;
    for(int i = 0; i < 1'000; i++) {
        for(int j = 0; j < 1'000; j++) {
            int num1 = sum[999][999]-sum[999][j]-sum[i][999]+sum[i][j];
            int num2 = sum[999][j]-sum[i][j];
            int num3 = sum[i][999]-sum[i][j];
            int num4 = sum[i][j];
            
            ans = min(ans, max({num1, num2, num3, num4}));
        }
    }
    
    cout << ans;

    return 0;
}