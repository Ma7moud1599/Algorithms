#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//The time complexity of this algorithm is O(nm), where n and m are the lengths of the input strings
//The space complexity of this algorithm is also O(nm)

int main() {
    string text_01 = "HELLOWORLD";
    string text_02 = "OHELOD";
    int n = text_01.length();
    int m = text_02.length();

    // Add a space at the beginning of each string
    text_01 = " " + text_01;
    text_02 = " " + text_02;

    // Initialize a 2D vector to store the dynamic programming values
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    // Fill in the dp array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (text_02[i] == text_01[j]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    // Backtrack through the dp array to construct the LCS string
    string lcs_str = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (dp[i][j] > dp[i][j-1]) {
            if (dp[i][j] == dp[i-1][j]) {
                i--;
            } else {
                lcs_str = text_02[i] + lcs_str;
                i--;
                j--;
            }
        } else {
            j--;
        }
    }

    // Output the length of the LCS and the LCS string
    cout << dp[m][n] << endl;
    cout << lcs_str << endl;

    return 0;
}
