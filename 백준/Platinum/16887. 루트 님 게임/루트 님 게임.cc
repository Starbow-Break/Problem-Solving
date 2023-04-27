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
#define MAX_M 100'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    
    int grendy = 0;
    while(N--) {
        ll A; cin >> A;
        int g;
        if(A <= 3 || (82 <= A && A <= 6'723)) g = 0;
        else if((4 <= A && A <= 15) || (50'626 <= A && A <= 2'562'991'875)) g = 1;
        else if(6'724 <= A && A <= 50'625) g = 3;
        else g = 2;
        
        grendy ^= g;
    }
    
    cout << (grendy ? "koosaga" : "cubelover");

    return 0;
}