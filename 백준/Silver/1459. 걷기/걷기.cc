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

int N, M;
char arr[50][51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll X, Y, W, S; cin >> X >> Y >> W >> S;
    if(S < W) cout << S*max(X, Y)+(W-S)*(abs(X-Y)%2);
    else if(2*W <= S) cout << (X+Y)*W;
    else cout << min(X, Y)*S+abs(X-Y)*W;

    return 0;
}