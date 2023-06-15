#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[1001][1001] = {0, };

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
    string A, B;
    cin >> A >> B;
    
    int lenA = A.length(); int lenB = B.length();
    
    for(int i = 1; i <= lenA; i++) {
        for(int j = 1; j <= lenB; j++) {
            if(A[i-1] == B[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }
    
    int len = dp[lenA][lenB]; char ans[1000]; int idx = 0;
    int i = lenA; int j = lenB;
    while(len != 0) {
        if(A[i-1] == B[j-1]) {
            ans[idx] = A[i-1]; idx++;
            len--;
            i--; j--;
        }
        else if(len == dp[i][j-1])
            j--;
        else
            i--;
    } 

    cout << dp[lenA][lenB] << '\n';
    for(int k = idx-1; k >= 0; k--)
        cout << ans[k];
    
    return 0;
}