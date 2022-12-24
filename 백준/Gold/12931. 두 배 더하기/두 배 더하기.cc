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

int B[50];
int cnt[50][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) { cin >> B[i]; }
    for(int i = 0; i < N; i++) {
        while(B[i] > 0) {
            if(B[i]%2) {
                cnt[i][0]++;
                B[i]--;
            }
            else {
                cnt[i][1]++;
                B[i] /= 2;
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < N; i++) { ans += cnt[i][0]; }
    
    int t = 0;
    for(int i = 0; i < N; i++) { t = max(t, cnt[i][1]); }
    ans += t;
    
    cout << ans;

    return 0;
}