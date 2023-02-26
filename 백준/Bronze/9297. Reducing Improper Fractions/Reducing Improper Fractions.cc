#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    for(int tc = 1; tc <= T; tc++) {
        int A, B; cin >> A >> B;
        cout << "Case " << tc << ": ";
        
        if(A == 0) cout << 0;
        else {
            if(A > B) cout << A/B << " ";
            if(A%B)cout << (A%B) << '/' << B;
        }
        
        cout << '\n';
    }
    
    return 0;
}