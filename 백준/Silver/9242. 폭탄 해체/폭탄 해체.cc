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
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef __int128_t int128;

ostream& operator<<(ostream &out, const pii &p) {
    out << p.first << ' ' << p.second;
    return out;
}

char number[10][5][4] = 
{
    {"***", "* *", "* *", "* *", "***"}, // 0
    {"  *", "  *", "  *", "  *", "  *"}, // 1
    {"***", "  *", "***", "*  ", "***"}, // 2
    {"***", "  *", "***", "  *", "***"}, // 3
    {"* *", "* *", "***", "  *", "  *"}, // 4
    {"***", "*  ", "***", "  *", "***"}, // 5
    {"***", "*  ", "***", "* *", "***"}, // 6
    {"***", "  *", "  *", "  *", "  *"}, // 7
    {"***", "* *", "***", "* *", "***"}, // 8
    {"***", "* *", "***", "  *", "***"}, // 9
};

string code[5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i = 0; i < 5; i++) getline(cin, code[i]);
    
    bool flag = true; int num = 0;
    for(int i = 0; i < code[0].length() & flag; i += 4) {
        int n;
        for(n = 0; n < 10; n++) {
            bool check = true;
            for(int r = 0; r < 5; r++) {
                for(int c = 0; c < 3; c++) {
                    if(number[n][r][c] != code[r][i+c]) check = false; 
                }
            }
            if(check) break;
        }
        
        if(n > 9) flag = false;
        num = num*10+n;
    }
    
    cout << (flag && num%6 == 0 ? "BEER!!" : "BOOM!!");

    return 0;
}