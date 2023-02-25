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

void printBlock(int N, int num) {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N*num; j++) cout << '@';
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 1; i <= 5; i++) {
        if(i > 1 && i < 5) printBlock(N, 1);
        else printBlock(N, 5);
    }
    
    return 0;
}