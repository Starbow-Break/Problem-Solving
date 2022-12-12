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

bool visited[29][29] = {false, };
int probability[4]; //동, 서, 남, 북
double ans = 0;

void solve(int N, double p = 1, int step = 0, int r = 14, int c = 14) {
    if(step == N) { ans += p; return; }
    
    visited[r][c] = true;
    
    for(int i = 0; i < 4; i++) {
        if(probability[i] == 0) continue;
        
        switch(i) {
            case 0:
                if(!visited[r][c+1]) {
                    solve(N, p/100*probability[i], step+1, r, c+1);
                }
                break;
            case 1:
                if(!visited[r][c-1]) {
                    solve(N, p/100*probability[i], step+1, r, c-1);
                }
                break;
            case 2:
                if(!visited[r+1][c]) {
                    solve(N, p/100*probability[i], step+1, r+1, c);
                }
                break;
            case 3:
                if(!visited[r-1][c]) {
                    solve(N, p/100*probability[i], step+1, r-1, c);
                }
        }
    }
    
    visited[r][c] = false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < 4; i++) { cin >> probability[i]; }
    
    solve(N);
    
    cout << fixed; cout.precision(15);
    cout << ans;

    return 0;
}