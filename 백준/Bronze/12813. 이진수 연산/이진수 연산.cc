#include <iostream>
#include <cstring>
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
    
    string A, B; cin >> A >> B;
    
    string _and = "", _or = "", _xor = "", notA = "", notB = "";
    
    for(int i = 0; i < 100000; i++) {
        int bitA = A[i]-'0'; int bitB = B[i]-'0';
        
        _and += '0'+(bitA & bitB);
        _or += '0'+(bitA | bitB);
        _xor += '0'+(bitA ^ bitB);
        notA += '0'+!bitA;
        notB += '0'+!bitB;
    }
    
    cout << _and << '\n' << _or << '\n' << _xor << '\n' << notA << '\n' << notB;

    return 0;
}