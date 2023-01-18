#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int arr[100001];
int S[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i]; S[i] = S[i-1]+arr[i];
    }
    
    ll ans = 0;
    for(int i = 1; i < N; i++) {
        ans += 1LL*arr[i]*(S[N]-S[i]);
    }
    
    cout << ans;
    
    return 0;
}