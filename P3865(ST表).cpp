#include <iostream>
#include <cmath>
using namespace std;

const int MAXN = 100005; // 数据范围
const int LOGN = 20;     // log2(MAXN)向上取整

int n, m;                // n个数，m个查询
int a[MAXN];             // 原始数组
int st[MAXN][LOGN];      // ST表
int Log2[MAXN];          // 预处理log2值，加速计算

// 预处理log2函数值
// # 将一个区间分成两个小区间，这两个小区间的长度是2的幂次方，这样能使计算速度更快
void init_log() {
    Log2[1] = 0;
    for (int i = 2; i <= MAXN; i++) {
        Log2[i] = Log2[i / 2] + 1;
    }
}

// 构建ST表
void build_st() {
    // 初始化：st[i][0]表示区间长度为1的情况
    for (int i = 1; i <= n; i++) {
        st[i][0] = a[i];
    }
    
    // 动态规划：st[i][j]表示从i开始，长度为2^j的区间的最大值
    for (int j = 1; j <= LOGN; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = max(st[i][j-1], st[i + (1 << (j-1))][j-1]);
        }
    }
}

// 查询区间[l, r]的最大值
int query(int l, int r) {
    int len = r - l + 1;
    int k = Log2[len];
    // 将区间分成两部分，取两部分最大值的较大者
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    // 读入数据
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    // 预处理并构建ST表
    init_log();
    build_st();
    
    // 处理查询
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << "\n";
    }
    
    return 0;
}