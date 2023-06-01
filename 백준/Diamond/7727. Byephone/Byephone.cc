#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <iomanip>
#define MAX_L 10'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int x, y;
string S, T, ans = ""; int n, m;
int dp1[MAX_L+1], dp2[MAX_L+1], temp[MAX_L+1];
void solve(int la, int lb, int ra, int rb) {
    if(rb <= lb) return;
    if(rb-lb == 1) {
        for(int i = la; i < ra; i++) {
            if(S[i] == T[lb]) {
                ans += S[i]; break;
            }
        }
        return;
    }
    
    int mid = (lb+rb)/2;
    for(int i = lb; i <= mid; i++) {
        if(i == lb) fill(dp1+la, dp1+ra+1, 0);
        else {
            for(int j = la; j <= ra; j++) {
                temp[j] = dp1[j];
                if(j > la) {
                    temp[j] = max(temp[j], temp[j-1]);
                    if(S[j-1] == T[i-1])
                        temp[j] = max(temp[j], dp1[j-1]+1);
                }
            }
            
            for(int j = la; j <= ra; j++) {
                dp1[j] = temp[j];
            }
        }
    }

    for(int i = rb; i >= mid; i--) {
        if(i == rb) fill(dp2+la, dp2+ra+1, 0);
        else {
            for(int j = ra; j >= la; j--) {
                temp[j] = dp2[j];
                if(j < ra) {
                    temp[j] = max(temp[j], temp[j+1]);
                    if(S[j] == T[i])
                        temp[j] = max(temp[j], dp2[j+1]+1);
                }
            }
            
            for(int j = la; j <= ra; j++) {
                dp2[j] = temp[j];
            }
        }
    }
    
    int i = la;
    for(int a = la; a <= ra; a++) {
        if(dp1[i]+dp2[i] < dp1[a]+dp2[a]) i = a;
    }
    
    solve(la, lb, i, mid); solve(i, mid, ra, rb);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> x >> y >> S >> T;
    int n = S.length(), m = T.length();
    
    solve(0, 0, n, m);
    
    cout << ans.length() << '\n' << ans;

    return 0;
}