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

char arr[50][51];
bool brr[50][50] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) { cin >> arr[i]; }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(i == j) continue;
            
            if(arr[i][j] == 'Y') brr[i][j] = true;
            else {
                for(int k = 0; k < N; k++) {
                    if(arr[i][k] == 'Y' && arr[j][k] == 'Y') {
                        brr[i][j] = true; break;
                    }
                }
            }
        }
    }
    
    int ans = 0;
    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            if(brr[i][j]) cnt++;
        }
        
        ans = max(ans, cnt);
    }
    
    cout << ans;

    return 0;
}