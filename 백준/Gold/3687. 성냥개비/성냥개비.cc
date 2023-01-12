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

void repeatPrint(int count, int value) {
    for(int i = 0; i < count; i++) { cout << value; }
}

void printSmallest(int n) {
    if(n <= 7) {
        switch(n) {
            case 2:
                cout << 1;
                break;
            case 3:
                cout << 7;
                break;
            case 4:
                cout << 4;
                break;
            case 5:
                cout << 2;
                break;
            case 6:
                cout << 6;
                break;
            case 7:
                cout << 8;
        }
        
        return;
    }
    
    if(n == 10) { cout << 22; return; }
    
    switch(n%7) {
        case 0:
            repeatPrint(n/7, 8);
            break;
        case 1:
            cout << 10;
            repeatPrint(n/7-1, 8);
            break;
        case 2:
            cout << 1;
            repeatPrint(n/7, 8);
            break;
        case 3:
            cout << 200;
            repeatPrint(n/7-2, 8);
            break;
        case 4:
            cout << 20;
            repeatPrint(n/7-1, 8);
            break;
        case 5:
            cout << 2;
            repeatPrint(n/7, 8);
            break;
        case 6:
            cout << 6;
            repeatPrint(n/7, 8);
    }
}

void printBiggest(int n) {
    if(n%2 == 0) {
        repeatPrint(n/2, 1);
    }
    else {
        cout << "7";
        repeatPrint(n/2-1, 1);
    }
}

void solve(int n) {
    printSmallest(n);
    cout << " ";
    printBiggest(n);
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        solve(n);
    }

    return 0;
}