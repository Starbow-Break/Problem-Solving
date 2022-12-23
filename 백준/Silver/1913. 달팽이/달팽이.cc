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

int N, T;
int arr[1000][1000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> T;
    
    int cur = 1;
    int r = (N+1)/2; int c = (N+1)/2; int d = 0;
    
    while(cur <= N*N) {
        if(d == 0) {
            arr[r][c] = cur;
            r--; cur++;
        }
        else {
            while(c < (N+1)/2+d) { arr[r][c] = cur; cur++; c++; }
            while(r < (N+1)/2+d) { arr[r][c] = cur; cur++; r++; }
            while(c > (N+1)/2-d) { arr[r][c] = cur; cur++; c--; }
            while(r >= (N+1)/2-d) { arr[r][c] = cur; cur++; r--; }
        }
        
        d++;
    }
    
    int rr, cc;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << arr[i][j] << ' ';
            
            if(arr[i][j] == T) {rr = i; cc = j;}
        }
        cout << '\n';
    }
    
    cout << rr << ' ' << cc;

    return 0;
}