#include <cstdio>
#include <cstring>

const int maxn = 110;

int dp[maxn][maxn][maxn];

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  memset(dp, -1, sizeof dp);
  dp[1][0][0] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int p1 = 0, p2 = 0, x;
      scanf("%d", &x);
      for (int z = 0; z < k; ++z) {
        if (dp[i - 1][j][p1] > dp[i][j - 1][p2] && dp[i - 1][j][p1] != -1) {
          dp[i][j][z] = dp[i - 1][j][p1] + x;
          ++p1;
        } else if (dp[i][j - 1][p2] != -1) {
          dp[i][j][z] = dp[i][j - 1][p2] + x;
          ++p2;
        }
      }
    }
  }
  for (int i = 0; i < k; ++i) {
    printf("%d%c", dp[n][m][i], i == k - 1 ? '\n' : ' ');
  }
  return 0;
}


