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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M; cin >> N >> M;
    int A[N+1], B[M+1];
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= M; i++) cin >> B[i];
    
    int remain[N+1];
    for(int i = 1; i <= N; i++) remain[i] = A[i];
    
    int idx = 1;
    for(int i = 1; i <= M && idx <= N; i++) {
        while(idx <= N && remain[idx] < B[i]) idx++;
        
        if(idx <= N) remain[idx] -= B[i];
    }
    
    int ans = 0;
    for(int i = 1; i <= N; i++) ans += remain[i];
    cout << ans;

    return 0;
}