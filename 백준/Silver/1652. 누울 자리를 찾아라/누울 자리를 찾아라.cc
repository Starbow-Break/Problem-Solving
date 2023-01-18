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

int N;
char arr[100][101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 0; i < N; i++) { cin >> arr[i]; }
    
    int a = 0, b = 0;
    for(int i = 0; i < N; i++) {
        int len = 0;
        for(int j = 0; j < N; j++) {
            if(arr[i][j] == '.') {
                len++;
            }
            else {
                if(len >= 2) a++;
                len = 0;
            }
        }
        
        if(len >= 2) a++;
    }
    
    for(int j = 0; j < N; j++) {
        int len = 0;
        for(int i = 0; i < N; i++) {
            if(arr[i][j] == '.') {
                len++;
            }
            else {
                if(len >= 2) b++;
                len = 0;
            }
        }
        
        if(len >= 2) b++;
    }
    
    cout << a << " " << b;

    return 0;
}