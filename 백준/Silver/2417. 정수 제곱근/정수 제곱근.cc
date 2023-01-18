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
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

ull intSqrt(ull N) {
    ull i = 0; ull j = 4294967296;
    
    while(i <= j) {
        ull mid = (i+j)>>1;
        if(mid*mid < N) i = mid+1;
        else if(mid*mid > N) j = mid-1;
        else return mid;
    }
    
    return i;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ull N; cin >> N;
    cout << intSqrt(N);
    
    return 0;
}