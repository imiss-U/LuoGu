#include <cstdio>
#include <vector>
using namespace std;
int read() {
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9') {  // ch 不是数字时
        if (ch == '-') w = -1;        // 判断是否为负
        ch = getchar();               // 继续读入
    }
    while (ch >= '0' && ch <= '9') {  // ch 是数字时
        x = x * 10 + (ch - '0');  // 将新读入的数字「加」在 x 的后面
        // x 是 int 类型，char 类型的 ch 和 '0' 会被自动转为其对应的
        // ASCII 码，相当于将 ch 转化为对应数字
        // 此处也可以使用 (x<<3)+(x<<1) 的写法来代替 x*10
        ch = getchar();  // 继续读入
    }
    return x * w;  // 数字 * 正负号 = 实际数值
}
void write(int x) {
    static int sta[35];
    int top = 0;
    do {
        sta[top++] = x % 10, x /= 10;
    }
    while (x);
    while (top) putchar(sta[--top] + 48);  // 48 是 '0'
}
int main() {
    int n;
    n = read();
    vector<int> a(n + 1), b(n + 1), A(n + 1), B(n + 1);
    vector<long long> p(n), start(n);
    for (int i = 1; i <= n; i++)
        a[i] = read(), A[i] = a[i];
    for (int i = 1; i <= n; i++) {
        b[i] = read(), B[i] = b[i];
    }
    int q;
    q = read();
    int k;
    for (int h = 0; h < q; h++) {
        long long diff;
        k = read();
        for (int i = 1; i <= n; i++)
            a[i] = A[i], b[i] = B[i];
        int i, ai, bi;
        for (int j = 0; j < k; j++) {
            i = read(), ai = read(), bi = read();
            a[i] = ai, b[i] = bi;
        }
        for (int i = 1; i < n; i++) {
            int left = i, right = i + 1;
            diff = 0;
            p[i] = min(a[left], a[right]);
            start[i] = p[i];
            while (left >= 1 || right <= n) {
                if (p[i] >= max(a[left], a[right])) {
                    if (b[left] <= b[right]) {
                        p[i] += b[right];
                        right++;
                    }
                    else {
                        p[i] += b[left];
                        left--;
                    }
                }
                else if (p[i] < min(a[left], a[right])) {
                    diff += (min(a[left], a[right]) - p[i]);
                    if (a[left] < a[right]) {
                        p[i] = a[left];
                        p[i] += b[left];
                        left--;
                    }
                    else {
                        p[i] = a[right];
                        p[i] += b[right];
                        right++;
                    }
                }
                else {
                    if (p[i] >= a[left] && a[left] < a[right]) {
                        p[i] += b[left];
                        left--;
                    }
                    else {
                        p[i] += b[right];
                        right++;
                    }
                }
                if (left == 0) {
                    while (right <= n) {
                        if (p[i] >= a[right])
                            p[i] += b[right];
                        else {
                            diff += (a[right] - p[i]);
                            p[i] = a[right] + b[right];
                        }
                        right++;
                    }
                }
                else if (right == n + 1) {
                    while (left >= 1) {
                        if (p[i] >= a[left])
                            p[i] += b[left];
                        else {
                            diff += (a[left] - p[i]);
                            p[i] = a[left] + b[left];
                        }
                        left--;
                    }
                }
            }
            start[i] += diff;
        }
        int tmp = 0;
        for (int i = 1; i < n; i++)
            tmp ^= start[i];
        write(tmp), putchar('\n');
    }
    return 0;
}