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
    
    bool isFull[101] = {false, }; int ans = 0;
    
    int N; cin >> N;
    while(N--) {
        int v; cin >> v;
        ans += isFull[v]; isFull[v] = true;
    }
    
    cout << ans;
    
    return 0;
}