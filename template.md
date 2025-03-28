# <font color = red>背包 </font>
## <font color = blue>01背包 </font>
以一维为例，$res$为结果数组，$num$为价值数组  
1. 只能先遍历物品再遍历背包
2. 背包要倒序遍历
3. 若价值有负数，则非零下标要初始化为负无穷，0下标仍为0
4. **<font color = green>在求最大值的同时若要求将背包装满，则非零下标初始化为负无穷，0下标仍为0；若未要求一定要将背包装满则正常初始化</font>**
5. **<font color = orange>若问达到某一种目的有几种方法，一般初始化为$res[0]=1$，其余正常。递归公式：$res[j] += res[j - nums[i]]$ [洛谷P1164](https://www.luogu.com.cn/problem/P1164)</font>**  [洛谷P2663](https://www.luogu.com.cn/problem/P2663)好像也是这个意思？
6. （2025.3.20补档）你会发现其实把背包装满的问题其实就是问有几种方法（因为把背包装满大多只有一种情况）

## <font color = blue>完全背包 </font>
$weight$为占用空间数组，$V$代表背包体积
1. 背包要正序遍历，从小到大（$weight[i] \rightarrow V$）
2. <font color = orange>若问达到某一种目的有几种方法，一般初始化为$res[0]=1$，其余正常。递归公式：$res[j] += res[j - nums[i]]$。与01背包不同的是由于每件物品可以选取不止一件，就会产生重复的情况。此时：
    + 先遍历物品，再遍历背包=====>组合数 [洛谷P2563](https://www.luogu.com.cn/problem/P2563)、[洛谷P1832](https://www.luogu.com.cn/problem/P1832)、[零钱兑换II](https://leetcode.cn/problems/coin-change-ii/description/)
    + 先遍历背包，再遍历物品=====>排列数 [组合总和IV](https://leetcode.cn/problems/combination-sum-iv/description/)

</font>  

3. <font color = purple>求在能装满背包的情况下最少用几件物品：$res$数组初始化为正无穷，0下标仍初始化为0.递归方程$res[j] = \min(res[j], res[j - cost[i]] + 1)$ [洛谷P1679](https://www.luogu.com.cn/problem/P1679)、[零钱兑换](https://leetcode.cn/problems/coin-change/)、[完全平方数](https://leetcode.cn/problems/perfect-squares/description/) </font>
4. 有时在求最优情况时另一个限制条件不是某个特定的数，而是一个范围。这种情况下仍然可以按照正常做法去做，只需要将结果数组开大一点，然后在结果数组中寻找符合条件的最优解 [洛谷P2918](https://www.luogu.com.cn/problem/P2918)（常规解答是[P2918.cpp](./P2918.cpp) 对于这道题还可以改变限制条件和要求的条件，详见[P2918_2.cpp](./P2918_2.cpp)）

# <font color = red> 前缀和与差分 </font>
## <font color = blue> 前缀和 </font>
对一个数组求出第一个位置到当前位置所有元素的和，将其保存在一个数组中，称该数组为前缀和数组
```c++
// 设num为原数组，pre为前缀和数组
int pre[10];
int main() {
    int num[10];
    for (int i = 0; i < 10; i++){
        cin >> num[i];
        if (i == 0)
            pre[i] = num[i];
        else
            pre[i] = pre[i - 1] + num[i];
    }
}
```
前缀和数组可以用来查询某一区间上的和
```c++
// 求i到j之间num数组元素的和
// 传统做法
    int sum = 0;
    for (int k = i; k <= j; k++)
        sum += num[k];
// 利用前缀和
    int sum = 0;
    sum = pre[j] - pre[i];
```
将时间复杂度由O(n)转化为O(1)

## <font color = orange> 二维前缀和 </font>
$pre[i][j]$表示第i行第j列左上角所有元素之和  
```c++
    for (int m = 0; m < i; m++)
        for (int n = 0; n < j; n++)
            if (m == 0 && n == 0)
                pre[m][n] = num[m][n];
            else
                pre[m][n] += num[m][n];
```
以$num[x1, y1]为左上角，num[x2, y2]为右下角的矩形区域元素之和为$  
```sum = pre[x2][y2] + pre[x1 - 1][y1 - 1] - pre[x2][y1 - 1] - pre[x1 - 1][y2]```  
**有个值得注意的点：求矩阵任意区域面积时要从1开始累加，详情见[洛谷P1719](https://www.luogu.com.cn/problem/P1719)**

## <font color = green> 差分 </font>
计算一个数组中每一个元素与前一个元素的差值，结果保存在diff数组中，这个数组称为差分数组
```c++
    int diff[10];
    int main() {
        int num[10];
        for (int i = 0; i < 10; i++) {
            cin >> num[i];
            if (i == 0)
                diff[i] = num[i];
            else
                diff[i] = num[i] - num[i - 1];
        }
    }
```
可以利用差分数组实现对某一区间上加或减
```c++
// 将[2,6]区间中的每个数加3
// 传统做法
    for (int i = 2; i <= 6; i++)
        num[i] += 3;
// 利用差分
    diff[2] += 3;
    diff[7] -= 3;
    for (int i = 2; i <= 7; i++)
        num[i] = diff[i] + num[i - 1];
```

## <font color = purple> 二维差分 </font>
diff[i][j]表示num[i][j]减去左侧元素减去上侧元素再加上左上角元素的和
```c++
for (int m = 0; m < i; m++) {
    for (int n = 0; n < j; n++) {
        if (m == 0 && n == 0)
            diff[m][n] = num[m][n];
        else if (m == 0 && n != 0)
            diff[m][n] = num[m][n] - num[m - 1][n];
        else if (m != 0 && n == 0)
            diff[m][n] = num[m][n] - num[m][n - 1];
        else
            diff[m][n] = num[m][n] + num[m - 1][n - 1] - num[m - 1][n] - num[m][n - 1];
    }
}
```
将以num[x1][y1]为左上角，num[x2][y2]为右下角的矩阵区域元素加或减某一个数：
```c++
diff[x1][y1] += c;
diff[x2][y2] += c;
diff[x1][y2] -= c;
diff[x2][y1] -= c;
for (int i = x1; i <= x2; i++) {
    for (int j = x2; j <= y2; j++) {
        num[i][j] = diff[i][j] + diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1];
    }
}
```

# <font color = red> 高精度 </font>
## <font color = blue> 高精度加法 </font>
[洛谷P1601](https://www.luogu.com.cn/problem/P1601)
## <font color = green> 高精度减法 </font>
[洛谷P2142](https://www.luogu.com.cn/problem/P2142)
## <font color = purple> 高精度乘法 </font>
[洛谷P1303](https://www.luogu.com.cn/problem/P1303)

# <font color = blue> 回溯法 </font>
回溯法的本质仍是穷举：列出所有可能的情况，从中选取正确的答案。因此效率与直接枚举差别不大，充其量加个剪枝。但回溯法可以解决一些枚举解决不了的问题。比如[组合问题](https://leetcode.cn/problems/combinations/)。
## <font color = black> 回溯法的步骤 </font>
1. 确定回溯函数返回值及参数
2. 确定终止条件
3. 回溯

## <font color = red> 几个关键点 </font>
1.[组合问题](https://leetcode.cn/problems/combinations/)  
Q: 参数中的```startindex```是做什么的？  
A: 很明显题目中要求选取的数字**不能重复**，假设`n = 5, k = 3`，那么答案中是不允许出现`[1, 1, 1]`这种答案。也就是说每次选取完若干个数之后不能选取已经选过的数，因此需要一个`startindex`来控制选择的区间：`startindex`之前的数字被选取过，再选取时不能从小于`startindex`的树中选取  

Q:循环遍历时为什么要` i <= n - (k - path.size()) + 1`？  
A: 这实质上是剪枝操作。题目中要求每次选取`k`个数，而当前已经选取的数的个数为`path.size()`，还需要选取`k - path.size()`个。而当` i <= n - (k - path.size()) + 1`时说明待选取空间中剩余的数足够选取，否则如果` i > n - (k - path.size()) + +`则说明哪怕都选上也到不了`k`个数，因此这种情况直接被剪枝舍弃了  

2. [电话号码](https://leetcode.cn/problems/letter-combinations-of-a-phone-number/description/)  

Q: 这里的`index`是什么  
A: 这里面的`index`不同于之前的`startindex`，是用来判断当前遍历几个数字的，在循环体中与`i`没关系。

3. [组合总和](https://leetcode.cn/problems/combination-sum/description/)  
   

Q: 与前面的题相比不同点在什么地方？  
A: 显而易见的，题目中说明“同一个数字可以无限制的使用”，也就是说数字可以出现很多次，那么循环体中的迭代函数的```startindex```就不用加一（详见[L39](D://Vscode//Code//Cpp_algorithm//LuoGu//L39.cpp)第19行）另外值得注意的是：判断需不需要```startindex```要看被选取的集合，如果是从一个集合中选区的话就要用```startindex```，否则不需要。以上经验判断仅在组合问题中奏效，排列问题与其不同。

4. [组合总和II](https://leetcode.cn/problems/combination-sum-ii/description/)  
   

Q: 这题与上一题的区别又是什么？  
A: 根据题目要求：同一个数字只能使用一次，而且集合中包含相同元素且最终结果中却不能包含有重复的组合，因此需要对结果进行去重。（用```set或map```会超时）所以本题最大的难点在于如何去重，其它的地方与上一题差别不大。可使用```used```数组进行去重，对已使用的数字标记为```true```，对标记为```false```的元素进行选取，选取之后再更新标记即可

## 总结  

1. 判断是排列问题还是组合问题：  
    排列问题：需要```startindex或index```  
    组合问题：不需要```startindex```  

如果是组合问题：  

2. 判断待选取集合是一个还是多个：  
    一个集合中选取：使用```startindex```  
    多个集合中选取：使用```index```

3. 集合中无重复元素，要求结果中不能有重复元素：使用```startindex```，循环体中```startindex```每次加一
4. 集合中右重复元素，要求结果中不能有重复元素：回溯前对集合排序，将相同值的元素放在一起，使用```used```数组去重（使用```startindex```去重也可）

## 快速幂
用于计算大整数次幂，时间复杂度可由$O(n)降至O(logn)$
```c++
long long ans = 1;
long long f(int a, int b, int mod) {            // 求a的b次幂，结果对mod求余
    while (b) {
        if (b & 1) {
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}
```

## 离散化
常用于仅关注数据关系（大小）而不注重具体数值的题目，可降低时间和空间复杂度  
```c++
int n;
cin >> n;
vector<int> a(n + 1), t(n + 1);         // a表示要进行离散化的数据，t是副本
for (int i = 1; i < n; i++) {
    cin >> a[i];
    t[i] = a[i];
}
sort(t + 1, t + n + 1);
int m = unique(t + 1, t + n + 1) - t - 1;
for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(t + 1, t + m + 1, t[i]) - t;
    cout << a[i];
}
```

## 单调栈
指栈中元素有序：单调递增或单调递减
```c++
int num[10];
for (int i = 0; i < 10; i++)
    cin >> num[i];
stack<int> s;
for (int a : num) {
    if (s.empty() || s.top() > a)
        s.push(a);
    else {
        while (!s.empty() && s.top() < a)
            s.pop();
        s.push(a);
    }
}
```

## 单调队列
同单调栈，可一边进一边出。多用于滑动窗口和最大序列和
具体实现看例题  
（2025.3.25补档）  代码模板如下：
```c++
int a[N + 1];   // a是待进入队列的数组，一般从1开始
deque<int> q;
q.insert(1);    // 先将下标1插入
for (int i = 2; i <= N; i++) {
    while (!q.empty() && i - q.front() > m) // 移除超过窗口大小的元素
        q.pop_front();
    cout << q.front() << "\n";   // 输出最小值（以最小值为例）
    while (!q.empty() && a[q.back()] > a[i])    // 移除队列中比当前元素大的元素
        q.pop_back();
    q.push_back(i);  // 将当前元素插入队列中
}
```
<font color = red> 注意：  
1. 实现单调队列时要注意：进队列的是下标不是数！
2. 循环体内部大概有四步：
   1. 移除过期元素（在窗口外侧的元素）
   2. 输出最小（大）的元素（可选，根据题意）
   3. 移除队列尾部比当前元素大（小）的元素
   4. 将当前元素下标插入队列尾部
这四个步骤顺序不能随意调换
3. 求最小值队列递增，求最大值队列递减</font>  

相关题目[P1440](https://www.luogu.com.cn/problem/P1440)

## 字典树
详见[test.cpp](./test.cpp)

## 并查集
并查集是用于管理数据的一种数据结构，实现为一颗森林，每棵树表示一个集合，树中的节点表示集合中的元素。并查集支持查找和合并操作。实现细节如下：  
```c++
struct dsu {
    vector<int> fa;
    dsu(int n): fa(n + 1) {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }

    int find(int x) {       // 查找操作
        return fa[x] == x ? x : find(x);
    }

    void merge(int x, int y) {  // 合并操作
        fa[find(x)] = find(y);
    }
};
```
相关题目[P3367](https://www.luogu.com.cn/problem/P3367)  

## 堆
分为大根堆（根最大）和小根堆（根最小）。要注意堆中位于同一节点的子节点的大小是不固定的，可以左节点大也可以右节点大。  
具体实现如下（以大根堆为例）：  
```c++
class Heap {
    vector<int> num;
    void push_up(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;
            if (num[parent] >= num[i])
                break;
            else {
                swap(num[parent], num[i]);
            }
            i = parent;
        }
    }

    void push_down(int i) {
        while (i <= num.size()) {
            int left = 2 * i + 1, right = 2 * i + 2;
            if (left > num.size())
                break;
            int mini_child = left;
            if (right < num.size() && left > right)
                mini_child = right;
            if (num[mini_child] < num[i])
                swap(num[mini_child] < num[i])
            else 
                break;
            i = mini_child;
        }
    }

    void push(int x) {
        num.push_back(x);
        push_up(num.size() - 1);
    }

    void pop(int x) {
        swap(nu[0], num[num.size() - 1]);
        num.pop_back();
        push_down(0)
    };
};
```