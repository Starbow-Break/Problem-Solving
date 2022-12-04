#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;

int N;
bool swit[101];

void male(int s) {
    for(int i = s; i <= N; i += s) { swit[i] = !swit[i]; }
}

void female(int s) {
    int l = s; int r = s;
    
    while(l > 1 && r < N) {
        if(swit[l-1] != swit[r+1]) break;
        l--; r++;
    }
    
    for(int i = l; i <= r; i++) { swit[i] = !swit[i]; }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for(int i = 1; i <= N; i++) { cin >> swit[i]; }
    
    int M; cin >> M;
    while(M--) {
        int gender, num; cin >> gender >> num;
        if(gender == 1) { male(num); }
        else { female(num); }
    }
    
    for(int i = 1; i <= N; i++) { 
        cout << swit[i] << " "; 
        if(!(i%20)) cout << '\n';
    }

    return 0;
}