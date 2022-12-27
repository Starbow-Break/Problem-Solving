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

int N, M;
char arr[50][51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for(int i = 0; i < N; i++) { cin >> arr[i]; }
    
    int ans = 0;
    
    bool flag = false;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(arr[i][j] == '-') {
                flag = true;
            }
            else {
                ans += flag;
                flag = false;
            }
        }
        
        ans += flag;
        flag = false;
    }
    
    flag = false;
    for(int j = 0; j < M; j++) {
        for(int i = 0; i < N; i++) {
            if(arr[i][j] == '|') {
                flag = true;
            }
            else {
                ans += flag;
                flag = false;
            }
        }
        
        ans += flag;
        flag = false;
    }
    
    cout << ans;

    return 0;
}