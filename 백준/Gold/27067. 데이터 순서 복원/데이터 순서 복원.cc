#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int N;
int A[3001], B[3001], C[3001];
int posA[3001], posB[3001], posC[3001];
int ans[3001];

void solve() {
    bool flag = false;
    
    for(int i = 1; i <= N; i++) {
        if(posA[i] != posB[i] && posC[i] != posB[i] && posA[i] != posC[i]) {
            int bef; int aft;
            
            if(posA[i] < posB[i] && posA[i] < posC[i]) {
                bef = min(posB[i], posC[i]); aft = posA[i];
                for(int j = 1; j <= N; j++) {
                    if(j == aft) ans[bef] = A[aft];
                    else if(j > aft && j <= bef) {
                        ans[j-1] = A[j];
                    }
                    else ans[j] = A[j];
                }
            }
            
            if(posB[i] < posA[i] && posB[i] < posC[i]) {
                bef = min(posA[i], posC[i]); aft = posB[i];
                for(int j = 1; j <= N; j++) {
                    if(j == aft) ans[bef] = B[aft];
                    else if(j > aft && j <= bef) {
                        ans[j-1] = B[j];
                    }
                    else ans[j] = B[j];
                }
            }
            
            if(posC[i] < posA[i] && posC[i] < posB[i]) {
                bef = min(posA[i], posB[i]); aft = posC[i];
                for(int j = 1; j <= N; j++) {
                    if(j == aft) ans[bef] = C[aft];
                    else if(j > aft && j <= bef) {
                        ans[j-1] = C[j];
                    }
                    else ans[j] = C[j];
                }
            }
            
            flag = true; break;
        }
    }
    
    if(!flag) {
        for(int i = 1; i <= N; i++) {
            if(posA[i] == posB[i] || posA[i] == posC[i]) ans[posA[i]] = i;
            else ans[posB[i]] = i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) { cin >> A[i]; posA[A[i]] = i; }
    for(int i = 1; i <= N; i++) { cin >> B[i]; posB[B[i]] = i; }
    for(int i = 1; i <= N; i++) { cin >> C[i]; posC[C[i]] = i; }
    
    solve();
    
    for(int i = 1; i <= N; i++) { cout << ans[i] << " "; }

    return 0;
}