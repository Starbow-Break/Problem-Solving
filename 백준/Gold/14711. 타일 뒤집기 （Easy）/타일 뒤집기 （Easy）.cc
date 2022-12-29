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
bool arr[1000][1000] = {false, };
bool ans[1000][1000] = {false, };

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    string s; cin >> s;
    for(int i = 0; i < N; i++) {
        arr[0][i] = (s[i] == '#');
        ans[0][i] = (s[i] == '#');
    }
    
    for(int i = 0; i < N; i++) {
        if(i > 0) {
            for(int j = 0; j < N; j++) {
                if(arr[i-1][j]) {
                    ans[i][j] = true; arr[i][j] = !arr[i][j];
                }
            }
        }
        
        if(i < N-1) {
            for(int j = 0; j < N; j++) {
                if(ans[i][j]) {
                    arr[i][j] = !arr[i][j];
                    if(i > 0) arr[i-1][j] = !arr[i-1][j];
                    if(i < N-1) arr[i+1][j] = !arr[i+1][j];
                    if(j > 0) arr[i][j-1] = !arr[i][j-1];
                    if(j < N-1) arr[i][j+1] = !arr[i][j+1];
                }
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(ans[i][j]) cout << '#';
            else cout << '.';
        }
        cout << '\n';
    }

    return 0;
}