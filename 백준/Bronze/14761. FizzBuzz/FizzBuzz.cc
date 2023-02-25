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
    
    int X, Y, N; cin >> X >> Y >> N;
    for(int i = 1; i <= N; i++) {
        if(i%X == 0) cout << "Fizz";
        if(i%Y == 0) cout << "Buzz";
        
        if(i%X != 0 && i%Y != 0) cout << i;
        
        cout << '\n';
    }

    return 0;
}