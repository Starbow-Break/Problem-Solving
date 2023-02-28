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
    
    int w[7] = {2, 7, 6, 5, 4, 3, 2};
    int arr[7];
    char brr[11] = {'J', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'Z'};
    
    string s; cin >> s;
    for(int i = 0; i < 7; i++) arr[i] = s[i]-'0';
    
    int t = 0;
    for(int i = 0; i < 7; i++) t += arr[i]*w[i];
    
    cout << brr[t%11];
    
    return 0;
}