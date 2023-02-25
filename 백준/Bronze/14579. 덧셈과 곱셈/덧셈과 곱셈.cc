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
    
    int a, b; cin >> a >> b; ll sum = 1;
    
    for(int i = a; i <= b; i++) {
        sum *= i*(i+1)/2; sum %= 14579;
    }
    
    cout << sum;
    
    return 0;
}