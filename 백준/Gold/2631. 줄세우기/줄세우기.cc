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

vector<int> vec;
int arr[200];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for(int i = 0; i < N; i++) { cin >> arr[i]; }
    
    for(int i = 0; i < N; i++) {
        if(vec.empty() || vec.back() < arr[i]) {
            vec.push_back(arr[i]);
        }
        else {
            for(int j = 0; j < vec.size(); j++) {
                if(vec[j] > arr[i]) {
                    vec[j] = arr[i];
                    break;
                }
            }
        }
    }
    
    cout << N-vec.size();

    return 0;
}