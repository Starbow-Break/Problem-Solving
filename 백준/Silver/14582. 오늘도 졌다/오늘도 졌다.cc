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

int score[9][2];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i < 18; i++) cin >> score[i%9][i/9];
    
    int cur[2] = {0, }; bool ans = false;
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 2; j++) {
            cur[j] += score[i][j];
            
            if(cur[0] > cur[1]) ans = true;
        }
    }
    
    cout << (ans ? "Yes" : "No");

    return 0;
}