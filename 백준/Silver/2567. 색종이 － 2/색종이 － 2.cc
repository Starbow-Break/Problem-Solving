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

bool paper[102][102] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int x, y; cin >> x >> y;
        for(int i = 1; i <= 10; i++) {
            for(int j = 1; j <= 10; j++) {
                paper[x+i][y+j] = true;
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            if(paper[i][j]) {
                ans += (4-(paper[i-1][j]+paper[i+1][j]+paper[i][j-1]+paper[i][j+1]));
            }
        }
    }
    
    cout << ans;

    return 0;
}