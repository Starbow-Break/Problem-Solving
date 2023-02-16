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
#define MAX_N 1'000'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N; ll K;

int S[MAX_N+1], arr[51][MAX_N+1];
int D[MAX_N+1], f[MAX_N+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    for(int i = 1; i <= N; i++) { cin >> S[i]; f[i] = i; }
    for(int i = 1; i <= N; i++) {
        int v; cin >> v; D[v] = i;
    }
    
    for(int i = 1; i <= N; i++) { arr[0][D[i]] = i; }
    
    for(int i = 1; i <= 50; i++) {
        for(int j = 1; j <= N; j++) {
            arr[i][j] = arr[i-1][arr[i-1][j]];
        }
    }
    
    int idx = 0;
    while(K > 0) {
        if(K%2) {
            for(int i = 1; i <= N; i++) f[i] = arr[idx][f[i]];
        }
        
        K /= 2; idx++;
    }
    
    int ans[MAX_N+1];
    for(int i = 1; i <= N; i++) ans[f[i]] = S[i];
    for(int i = 1; i <= N; i++) cout << ans[i] << " ";

    return 0;
}