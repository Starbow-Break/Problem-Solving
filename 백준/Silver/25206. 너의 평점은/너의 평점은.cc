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

int arr[101];

double scoreToDouble(string score) {
    if(score == "A+") return 4.5;
    if(score == "A0") return 4.0;
    if(score == "B+") return 3.5;
    if(score == "B0") return 3.0;
    if(score == "C+") return 2.5;
    if(score == "C0") return 2.0;
    if(score == "D+") return 1.5;
    if(score == "D0") return 1.0;
    return 0.0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    double sum = 0, sumV = 0;
    
    string sub, score; double v;
    for(int i = 1; i <= 20; i++) {
        cin >> sub >> v >> score;
        if(score != "P") {sum += v*scoreToDouble(score); sumV += v;}
    }
    
    cout << fixed << setprecision(9) << sum/sumV;

    return 0;
}