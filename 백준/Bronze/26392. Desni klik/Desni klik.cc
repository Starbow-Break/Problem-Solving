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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    char arr[50][51];
    int n, r, s; cin >> n >> r >> s;
    while(n--) {
        for(int i = 0; i < r; i++) cin >> arr[i];
        
        int minV = r; int maxV = 1;
        for(int j = 0; j < s; j++) {
            for(int i = r-1; i >= 0; i--) {
                if(arr[i][j] == '#') {
                    int value = r-i;
                    minV = min(minV, value); maxV = max(maxV, value);
                    break;
                }
            }
        }
        
        cout << maxV-minV << '\n';
    }
    
    return 0;
}