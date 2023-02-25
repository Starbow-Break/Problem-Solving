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

void printBlock(int N, int num[]) {
    for(int i = 0; i < N; i++) {
        int idx = 0;
        while(num[idx] >= 0) {
            for(int j = 0; j < N*num[idx]; j++) {
                if(idx%2) cout << ' ';
                else cout << '@';
            }
            
            idx++;
        }
        
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int firstLine[4] = {3, 1, 1, -1};
    int lastLine[4] = {1, 1, 3, -1};
    int others[6] = {1, 1, 1, 1, 1, -1};
    
    int N; cin >> N;
    for(int i = 1; i <= 5; i++) {
        if(i == 1) printBlock(N, firstLine);
        else if(i == 5) printBlock(N, lastLine);
        else printBlock(N, others);
    }
    
    return 0;
}