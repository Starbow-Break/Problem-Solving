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
    
    int N, t;
    cin >> N >> t;
    
    cout << "! " << N/2+t << '\n'; cout << flush;
    
    if(t == 1) { cout << 1 << ' ' << 1 << '\n'; cout << flush; N--; }
    while(N > 0) {
        int a, b; cin >> a >> b; N--;
        
        if(N == 0) break;
        cout << b << ' ' << a << '\n'; N--; cout << flush;
    }
    
    return 0;
}