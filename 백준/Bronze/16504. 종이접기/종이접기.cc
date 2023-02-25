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
    
    int N; cin >> N; ll ans = 0;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            int v; cin >> v;
            ans += v;
        }
    }
    
    cout << ans;
    
    return 0;
}