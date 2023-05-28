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

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cout << "YES" << '\n';
    
    int N; cin >> N;
    if(N%2) {
        for(int k = 2; k <= (N+1)/2; k++) {
            if(k == 2) cout << 3 << ' ' << 1 << ' ' << 2 << ' ';
            else if(k%2) cout << 2*k+1 << ' ' << 2*k << ' ';
            else cout << 2*k << ' ' << 2*k+1 << ' ';
        }
    }
    else {
        for(int k = 1; k <= N/2; k++) {
            if(k%2) cout << 2*k-1 << ' ' << 2*k << ' ';
            else cout << 2*k << ' ' << 2*k-1 << ' ';
        }
    }

    return 0;
}