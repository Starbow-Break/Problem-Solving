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
#define MAX_N 10'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

const int INF = 1'000'000'000;

struct node {
    pii before; int left, right;
};

int dp[MAX_N+1][10];
node arr[MAX_N+1][10];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    string s, f; cin >> s >> f;
    
    for(int i = 1; i <= N; i++) {
        fill(dp[i], dp[i]+10, INF);
    }
    
    for(int i = 1; i <= N; i++) {
        int a = s[i-1]-'0'; int b = f[i-1]-'0';
        
        if(i == 1) {
            for(int d = 0; d <= 9; d++) {
                dp[i][d] = d+(10+a+d-b)%10;
                arr[i][d] = {{0, 0}, d, (10+a+d-b)%10};
            }
        }
        else {
            for(int j = 0; j <= 9; j++) {
                for(int d = 0; d <= 9; d++) {
                    if(dp[i][(j+d)%10] > dp[i-1][j]+d+(10+a+d+j-b)%10) {
                        dp[i][(j+d)%10] = dp[i-1][j]+d+(10+a+d+j-b)%10;
                        arr[i][(j+d)%10] = {{i-1, j}, d, (10+a+d+j-b)%10};
                    }
                }
            }
        }
    }
    
    int d = 0;
    for(int i = 0; i < 10; i++) {
        if(dp[N][d] > dp[N][i]) d = i;
    }
    
    vector<pii> vec;
    pii cur = {N, d};
    while(cur.first > 0) {
        int r = cur.first; int c = cur.second;
        vec.push_back({r, arr[r][c].left});
        vec.push_back({r, -1*arr[r][c].right});
        cur = arr[r][c].before;
    }
    reverse(vec.begin(), vec.end());
    
    cout << dp[N][d] << '\n';
    for(auto &p: vec) {
        if(p.second != 0) {
            cout << p.first << ' ' << p.second << '\n';
        }
    }

    return 0;
}