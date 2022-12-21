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

int H, W;
char joi[100][101];
int ans[100][100];

void init() {
    for(int i = 0; i < H; i++) {
        fill(ans[i], ans[i]+W, -1);
    }
}

void moveCloud() {
    for(int w = W-2; w >= 0; w--) {
        for(int h = 0; h < H; h++) {
            joi[h][w+1] = joi[h][w];
        }
    }
    
    for(int h = 0; h < H; h++) {
        joi[h][0] = '.';
    }
}

void check(int t) {
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(ans[i][j] == -1 && joi[i][j] == 'c') ans[i][j] = t;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> H >> W;
    init();
    for(int i = 0; i < H; i++) { cin >> joi[i]; }
    
    for(int t = 0; t < W; t++) {
        if(t > 0) moveCloud();
        check(t);
    }
    
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}