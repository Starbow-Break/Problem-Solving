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

int N;
int score[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) { cin >> score[i]; }
    
    int ans = 0; int t = 100000000;
    for(int i = N-1; i >= 0; i--) {
        if(score[i] <= t) { t = score[i]-1; }
        else {
            ans += (score[i]-t); t--;
        }
    }
    
    cout << ans;

    return 0;
}