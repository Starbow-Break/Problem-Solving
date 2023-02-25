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

bool check(int v) {
    while(v%2 == 0) v /= 2;
    return v == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int Q; cin >> Q;
    while(Q--) {
        int v; cin >> v;
        cout << check(v) << '\n';
    }
    
    return 0;
}