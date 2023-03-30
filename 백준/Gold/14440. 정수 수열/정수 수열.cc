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
#define MAX_N 300'000

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int x, y, a0, a1, n; cin >> x >> y >> a0 >> a1 >> n;
    
    cout.width(2); cout.fill('0');
    if(n == 0) cout << a0;
    else if(n == 1) cout << a1;
    else {
        int A[2][2] = {{x, y}, {1, 0}}, e = n-1;
        int B[2][2] = {{1, 0}, {0, 1}};
        while(e > 0) {
            if(e%2) {
                int temp[2][2] = {0, };
                for(int i = 0; i < 2; i++) {
                    for(int j = 0; j < 2; j++) {
                        for(int k = 0; k < 2; k++) {
                            temp[i][j] += B[i][k]*A[k][j];
                            temp[i][j] %= 100;
                        }
                    }
                }
                
                for(int i = 0; i < 2; i++) {
                    for(int j = 0; j < 2; j++) {
                        B[i][j] = temp[i][j];
                    }
                }
            }
            
            int temp[2][2] = {0, };
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    for(int k = 0; k < 2; k++) {
                        temp[i][j] += A[i][k]*A[k][j];
                        temp[i][j] %= 100;
                    }
                }
            }
                
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    A[i][j] = temp[i][j];
                }
            }
            
            e /= 2;
        }
        
        cout << (B[0][0]*a1+B[0][1]*a0)%100;
    }

    return 0;
}