#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    #ifdef LOCALL
        FILE *fp = freopen("./a.in", "r", stdin);       //测试用例所在路径
    #endif

    int n, k; cin >> n >> k;
    vector<vector<int>> v(n, vector<int>(n));

    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < n; ++ j){
            cin >> v[i][j];
        }
    }

    vector<vector<int>> preSum(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= n; ++ j){
            preSum[i][j] = preSum[i - 1][j] + preSum[i][j  - 1] - preSum[i - 1][j - 1] + v[i - 1][j - 1];
        }
    }

    int ans = INT_MAX;
    for (int i = k; i <= n; ++ i){
        for (int j = k; j <= n; ++ j){
            ans = min(ans, preSum[i][j] - preSum[i - k][j] - preSum[i][j - k] + preSum[i - k][j - k]);
        }
    }
    cout << ans << endl;

    #ifdef LOCALL
        fclose(fp);
    #endif
    return 0;
}