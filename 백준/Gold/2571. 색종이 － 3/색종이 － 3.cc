#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

bool paper[100][100] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    while(N--) {
        int x, y; cin >> x >> y;
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) { paper[x+i][y+j] = true; }
        }
    }
    
    int ans = 0; int cur = 0;
    for(int y1 = 0; y1 < 100; y1++) {
        for(int y2 = y1; y2 < 100; y2++) {
            for(int x = 0; x < 100; x++) {
                bool flag = true;
                for(int i = y1; i <= y2 && flag; i++) {
                    if(!paper[x][i]) flag = false;
                }
                
                if(flag) {
                    cur += y2-y1+1;
                }
                else {
                    ans = max(ans, cur); cur = 0;
                }
            }
            
            ans = max(ans, cur); cur = 0;
        }
    }

    cout << ans;
    
    return 0;
}
