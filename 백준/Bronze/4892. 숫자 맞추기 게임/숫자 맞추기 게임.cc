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
    
    int tc = 0;
    while(1) {
        tc++;
        
        int N; cin >> N;
        
        if(N == 0) break;
        
        int N1 = N*3;
        int N2 = (N%2 ? (N1+1)/2 : N1/2);
        int N3 = 3*N2;
        int N4 = N3/9;
        
        cout << tc << ". " << (N1%2 ? "odd " : "even ") << N4 << '\n';
    }

    return 0;
}