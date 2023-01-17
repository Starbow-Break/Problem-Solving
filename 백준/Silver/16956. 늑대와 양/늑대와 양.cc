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

int R, C;
char arr[500][501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> R >> C;
    for(int i = 0; i < R; i++) { cin >> arr[i]; }
    
    bool possible = true;
    for(int i = 0; i < R && possible; i++) {
        for(int j = 0; j < C && possible; j++) {
            if(arr[i][j] == 'S') {
                if(i > 0) {
                    if(arr[i-1][j] == '.') arr[i-1][j] = 'D';
                    if(arr[i-1][j] == 'W') possible = false;
                }
                if(i < R-1) {
                    if(arr[i+1][j] == '.') arr[i+1][j] = 'D';
                    if(arr[i+1][j] == 'W') possible = false;
                }
                if(j > 0) {
                    if(arr[i][j-1] == '.') arr[i][j-1] = 'D';
                    if(arr[i][j-1] == 'W') possible = false;
                }
                if(j < C-1) {
                    if(arr[i][j+1] == '.') arr[i][j+1] = 'D';
                    if(arr[i][j+1] == 'W') possible = false;
                }
            }
        }
    }
    
    cout << possible << '\n';
    for(int i = 0; i < R; i++) { cout << arr[i] << '\n'; }

    return 0;
}