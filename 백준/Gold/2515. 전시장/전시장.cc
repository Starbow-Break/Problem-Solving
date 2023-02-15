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
#define MAX_N 300'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N, S;

int dp[MAX_N+1][2];
vector<pii> art;
vector<int> artH;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> S;
    art.push_back({0, 0});
    for(int i = 1; i <= N; i++) {
        int H, C; cin >> H >> C;
        art.push_back({H, C});
    }
    
    sort(art.begin(), art.end());
    for(auto &a: art) { artH.push_back(a.first); }
    
    dp[0][0] = 0; dp[0][1] = 0;
    for(int i = 1; i <= N; i++) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        
        int t = upper_bound(artH.begin(), artH.end(), artH[i]-S)-artH.begin()-1;
        dp[i][1] = max(dp[t][0], dp[t][1])+art[i].second;
    }
    
    cout << max(dp[N][0], dp[N][1]);

    return 0;
}