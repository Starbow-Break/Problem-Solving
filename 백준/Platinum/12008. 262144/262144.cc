#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <cassert>
#define MAX_N 270'000

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int dp[60][270000] = {0, };
int arr[MAX_N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[arr[i]][i] = i+1;
    }
    
    for(int v = 1; v < 60; v++) {
        for(int i = 1; i <= N; i++) {
            dp[v][i] = max(dp[v][i], dp[v-1][dp[v-1][i]]);
        }
    }
    
    bool flag = false;
    for(int v = 59; v >= 1 && !flag; v--) {
        for(int j = 1; j <= N && !flag; j++) {
            if(dp[v][j]) { cout << v; flag = true; }
        }
    }

    return 0;
}