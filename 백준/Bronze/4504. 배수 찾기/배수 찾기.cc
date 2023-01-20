#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    
    while(1) {
        int v; cin >> v;
        if(v == 0) break;
        
        if(v%n) {
            cout << v << " is NOT a multiple of " << n << "." << '\n';
        }
        else {
            cout << v << " is a multiple of " << n << "." << '\n';
        }
    }

    return 0;
}