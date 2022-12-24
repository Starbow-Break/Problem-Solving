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

int H[1000000];
int arrow[1000001] = {0, }; int ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) { cin >> H[i]; }
    
    for(int i = 0; i < N; i++) {
        if(arrow[H[i]] == 0) {
            ans++;
            arrow[H[i]-1]++;
        }
        else {
            arrow[H[i]]--; arrow[H[i]-1]++;
        }
    }
    
    cout << ans;

    return 0;
}