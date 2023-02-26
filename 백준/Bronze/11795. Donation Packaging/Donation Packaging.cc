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
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    
    int A = 0, B = 0, C = 0;
    while(T--) {
        int a, b, c; cin >> a >> b >> c;
        A += a; B += b; C += c;
        
        if(A < 30 || B < 30 || C < 30) cout << "NO";
        else {
            int k = min(A, B); k = min(k, C);
            cout << k;
            A -= k; B -= k; C -= k;
        }
        
        cout << '\n';
    }

    return 0;
}