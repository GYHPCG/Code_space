# The template of basic algorithm

## 一.基础算法

### 1. 快速排序算法模板



```c++
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}

```

### 2.归并排序算法模板

#### 定义

归并排序（[merge sort](https://en.wikipedia.org/wiki/Merge_sort)）是高效的基于比较的稳定排序算法。

#### 性质

归并排序基于分治思想将数组分段排序后合并，时间复杂度在最优、最坏与平均情况下均为 $\theta(nlogn)$，空间复杂度为$\theta(n)$。

归并排序可以只使用 $\theta(1)$![\Theta (1)](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 的辅助空间，但为便捷通常使用与原数组等长的辅助数组。

#### 分治法实现归并排序

1. 当数组长度为 ![1](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 1 时，该数组就已经是有序的，不用再分解。
2. 当数组长度大于 ![1](data:image/gif;base64,R0lGODlhAQABAIAAAAAAAP///yH5BAEAAAAALAAAAAABAAEAAAIBRAA7) 1 时，该数组很可能不是有序的。此时将该数组分为两段，再分别检查两个数组是否有序（用第 1 条)。如果有序，则将它们合并为一个有序数组；否则对不有序的数组重复第 2 条，再合并。

用数学归纳法可以证明该流程可以将一个数组转变为有序数组。

为保证排序的复杂度，通常将数组分为尽量等长的两段。

```c++
void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];

    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}

```

### 3. 整数二分算法模板

```c++
bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
// 求左边界
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}

// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用.
// 求右边界
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
```

```cpp
class Solution {
    // lower_bound 返回最小的满足 nums[i] >= target 的 i
    // 如果数组为空，或者所有数都 < target，则返回 nums.size()
    // 要求 nums 是非递减的，即 nums[i] <= nums[i + 1]

    // 闭区间写法
    int lower_bound(vector<int> &nums, int target) {
        int left = 0, right = (int) nums.size() - 1; // 闭区间 [left, right]
        while (left <= right) { // 区间不为空
            // 循环不变量：
            // nums[left-1] < target
            // nums[right+1] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1; // 范围缩小到 [mid+1, right]
            else
                right = mid - 1; // 范围缩小到 [left, mid-1]
        }
        return left; // 或者 right+1
    }

    // 左闭右开区间写法
    int lower_bound2(vector<int> &nums, int target) {
        int left = 0, right = nums.size(); // 左闭右开区间 [left, right)
        while (left < right) { // 区间不为空
            // 循环不变量：
            // nums[left-1] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid + 1; // 范围缩小到 [mid+1, right)
            else
                right = mid; // 范围缩小到 [left, mid)
        }
        return left; // 或者 right
    }

    // 开区间写法
    int lower_bound3(vector<int> &nums, int target) {
        int left = -1, right = nums.size(); // 开区间 (left, right)
        while (left + 1 < right) { // 区间不为空
            // 循环不变量：
            // nums[left] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target)
                left = mid; // 范围缩小到 (mid, right)
            else
                right = mid; // 范围缩小到 (left, mid)
        }
        return right; // 或者 left+1
    }

public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums, target); // 选择其中一种写法即可
    }
};

作者：灵茶山艾府
链接：https://leetcode.cn/problems/search-insert-position/solutions/2023391/er-fen-cha-zhao-zong-shi-xie-bu-dui-yi-g-nq23/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
```



### 4. 浮点二分

```c++
bool check(double x) {/* ... */} // 检查x是否满足某种性质

double bsearch_3(double l, double r)
{
    const double eps = 1e-6;   // eps 表示精度，取决于题目对精度的要求
    while (r - l > eps)
    {
        double mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    return l;
}
```

### 5. 高精度

1. 高精度加法 

   ```c++
   // C = A + B, A >= 0, B >= 0
   vector<int> add(vector<int> &A, vector<int> &B)
   {
       if (A.size() < B.size()) return add(B, A);
   
       vector<int> C;
       int t = 0;
       for (int i = 0; i < A.size(); i ++ )
       {
           t += A[i];
           if (i < B.size()) t += B[i];
           C.push_back(t % 10);
           t /= 10;
       }
   
       if (t) C.push_back(t);
       return C;
   }
   
   ```

   

2. 高精度减法

   ```c++
   // C = A - B, 满足A >= B, A >= 0, B >= 0
   vector<int> sub(vector<int> &A, vector<int> &B)
   {
       vector<int> C;
       for (int i = 0, t = 0; i < A.size(); i ++ )
       {
           t = A[i] - t;
           if (i < B.size()) t -= B[i];
           C.push_back((t + 10) % 10);
           if (t < 0) t = 1;
           else t = 0;
       }
   
       while (C.size() > 1 && C.back() == 0) C.pop_back();
       return C;
   }
   
   ```

   

3. 高精度乘低精度

   ```c++
   // C = A * b, A >= 0, b >= 0
   vector<int> mul(vector<int> &A, int b)
   {
       vector<int> C;
   
       int t = 0;
       for (int i = 0; i < A.size() || t; i ++ )
       {
           if (i < A.size()) t += A[i] * b;
           C.push_back(t % 10);
           t /= 10;
       }
   
       while (C.size() > 1 && C.back() == 0) C.pop_back();
   
       return C;
   }
   
   ```

   

4. 高精度除以低精度 

   ```c++
   // A / b = C ... r, A >= 0, b > 0
   vector<int> div(vector<int> &A, int b, int &r)
   {
       vector<int> C;
       r = 0;
       for (int i = A.size() - 1; i >= 0; i -- )
       {
           r = r * 10 + A[i];
           C.push_back(r / b);
           r %= b;
       }
       reverse(C.begin(), C.end());
       while (C.size() > 1 && C.back() == 0) C.pop_back();
       return C;
   }
   
   ```

### 6. 前缀数组

   1. 一维前缀和

      ```c++
      S[i] = a[1] + a[2] + ... a[i]
      a[l] + ... + a[r] = S[r] - S[l - 1]
      ```

      

   2. 二维前缀和

      ```c++
      S[i, j] = 第i行j列格子左上部分所有元素的和
      以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵的和为：
      S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]
      ```

      

### 7. 差分数组

1. 一维差分

   ```c++
   给区间[l, r]中的每个数加上c：B[l] += c, B[r + 1] -= c
   ```

   

2. 二维差分

   ```c++
   给以(x1, y1)为左上角，(x2, y2)为右下角的子矩阵中的所有元素加上c：
   S[x1, y1] += c, S[x2 + 1, y1] -= c, S[x1, y2 + 1] -= c, S[x2 + 1, y2 + 1] += c
   ```

### 8. 双指针

```c++
for (int i = 0, j = 0; i < n; i ++ )
{
    while (j < i && check(i, j)) j ++ ;

    // 具体问题的逻辑
}
常见问题分类：
    (1) 对于一个序列，用两个指针维护一段区间
    (2) 对于两个序列，维护某种次序，比如归并排序中合并两个有序序列的操作
```

### 9. 离散化

```c++
vector<int> alls; // 存储所有待离散化的值
sort(alls.begin(), alls.end()); // 将所有值排序
alls.erase(unique(alls.begin(), alls.end()), alls.end());   // 去掉重复元素

// 二分求出x对应的离散化的值
int find(int x) // 找到第一个大于等于x的位置
{
    int l = 0, r = alls.size() - 1;
    while (l < r)
    {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return r + 1; // 映射到1, 2, ...n
}
 
```

### 10. 区间合并

```c++
// 将所有存在交集的区间合并
void merge(vector<PII> &segs)
{
    vector<PII> res;

    sort(segs.begin(), segs.end());

    int st = -2e9, ed = -2e9;
    for (auto seg : segs)
        if (ed < seg.first)
        {
            if (st != -2e9) res.push_back({st, ed});
            st = seg.first, ed = seg.second;
        }
        else ed = max(ed, seg.second);

    if (st != -2e9) res.push_back({st, ed});

    segs = res;
}

```

### 11. 日期问题

判断闰年：能被4整除、但不能被100整除，或能被400整除的年份为闰年；其余为平年。

* 回文日期

```c++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(int date)
{
    int year = date / 10000;
    int month = date % 10000 / 100;
    int day = date % 100;

    if (!month || month >= 13 || !day) return false;

    if (month != 2 && day > months[month]) return false;
    if (month == 2)
    {
        bool leap = year % 4 == 0 && year % 100 || year % 400 == 0;
        if (day > 28 + leap) return false;
    }

    return true;
}

int main()
{
    int date1, date2;
    cin >> date1 >> date2;

    int res = 0;
    for (int i = 1000; i < 10000; i ++ )
    {
        int x = i, r = i;
        for (int j = 0; j < 4; j ++ ) r = r * 10 + x % 10, x /= 10;

        if (r >= date1 && r <= date2 && check(r)) res ++ ;
    }

    printf("%d\n", res);
    return 0;
}
```



##  二. 基础数据结构

### 1. 单调栈

```c++
int tt = 0;
for (int i = 1; i <= n; i ++ )
{
    while (tt && check(stk[tt], i)) tt -- ;
    stk[ ++ tt] = i;
}
```

### 2. 单调队列

```c++
常见模型：找出滑动窗口中的最大值/最小值
int hh = 0, tt = -1;
for (int i = 0; i < n; i ++ )
{
    while (hh <= tt && check_out(q[hh])) hh ++ ;  // 判断队头是否滑出窗口
    while (hh <= tt && check(q[tt], i)) tt -- ;
    q[ ++ tt] = i;
}
```

### 3. KMP

```c++
// s[]是长文本，p[]是模式串，n是s的长度，m是p的长度
求模式串的Next数组：
for (int i = 2, j = 0; i <= m; i ++ )
{
    while (j && p[i] != p[j + 1]) j = ne[j];
    if (p[i] == p[j + 1]) j ++ ;
    ne[i] = j;
}

// 匹配
for (int i = 1, j = 0; i <= n; i ++ )
{
    while (j && s[i] != p[j + 1]) j = ne[j];
    if (s[i] == p[j + 1]) j ++ ;
    if (j == m)
    {
        j = ne[j];
        // 匹配成功后的逻辑
    }
}

```

### 4. Trie树

```c++
int son[N][26], cnt[N], idx;
// 0号点既是根节点，又是空节点
// son[][]存储树中每个节点的子节点
// cnt[]存储以每个节点结尾的单词数量

// 插入一个字符串
void insert(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) son[p][u] = ++ idx;
        p = son[p][u];
    }
    cnt[p] ++ ;
}

// 查询字符串出现的次数
int query(char *str)
{
    int p = 0;
    for (int i = 0; str[i]; i ++ )
    {
        int u = str[i] - 'a';
        if (!son[p][u]) return 0;
        p = son[p][u];
    }
    return cnt[p];
}

```

### 5. 并查集

```c++
(1)朴素并查集：

    int p[N]; //存储每个点的祖宗节点

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ ) p[i] = i;

    // 合并a和b所在的两个集合：
    p[find(a)] = find(b);


(2)维护size的并查集：

    int p[N], size[N];
    //p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x) p[x] = find(p[x]);
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        size[i] = 1;
    }

    // 合并a和b所在的两个集合：
    size[find(b)] += size[find(a)];
    p[find(a)] = find(b);


(3)维护到祖宗节点距离的并查集：

    int p[N], d[N];
    //p[]存储每个点的祖宗节点, d[x]存储x到p[x]的距离

    // 返回x的祖宗节点
    int find(int x)
    {
        if (p[x] != x)
        {
            int u = find(p[x]);
            d[x] += d[p[x]];
            p[x] = u;
        }
        return p[x];
    }

    // 初始化，假定节点编号是1~n
    for (int i = 1; i <= n; i ++ )
    {
        p[i] = i;
        d[i] = 0;
    }

    // 合并a和b所在的两个集合：
    p[find(a)] = find(b);
    d[find(a)] = distance; // 根据具体问题，初始化find(a)的偏移量


```

### 6. 堆

```c++
// h[N]存储堆中的值, h[1]是堆顶，x的左儿子是2x, 右儿子是2x + 1
// ph[k]存储第k个插入的点在堆中的位置
// hp[k]存储堆中下标是k的点是第几个插入的
int h[N], ph[N], hp[N], size;

// 交换两个点，及其映射关系
void heap_swap(int a, int b)
{
    swap(ph[hp[a]],ph[hp[b]]);
    swap(hp[a], hp[b]);
    swap(h[a], h[b]);
}

void down(int u)
{
    int t = u;
    if (u * 2 <= size && h[u * 2] < h[t]) t = u * 2;
    if (u * 2 + 1 <= size && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
    if (u != t)
    {
        heap_swap(u, t);
        down(t);
    }
}

void up(int u)
{
    while (u / 2 && h[u] < h[u / 2])
    {
        heap_swap(u, u / 2);
        u >>= 1;
    }
}

// O(n)建堆
for (int i = n / 2; i; i -- ) down(i);

```

### 7. 一般哈希

```c++
(1) 拉链法
    int h[N], e[N], ne[N], idx;

    // 向哈希表中插入一个数
    void insert(int x)
    {
        int k = (x % N + N) % N;
        e[idx] = x;
        ne[idx] = h[k];
        h[k] = idx ++ ;
    }

    // 在哈希表中查询某个数是否存在
    bool find(int x)
    {
        int k = (x % N + N) % N;
        for (int i = h[k]; i != -1; i = ne[i])
            if (e[i] == x)
                return true;

        return false;
    }

(2) 开放寻址法
    int h[N];

    // 如果x在哈希表中，返回x的下标；如果x不在哈希表中，返回x应该插入的位置
    int find(int x)
    {
        int t = (x % N + N) % N;
        while (h[t] != null && h[t] != x)
        {
            t ++ ;
            if (t == N) t = 0;
        }
        return t;
    }


```

### 8. 字符串哈希

```c++
核心思想：将字符串看成P进制数，P的经验值是131或13331，取这两个值的冲突概率低
小技巧：取模的数用2^64，这样直接用unsigned long long存储，溢出的结果就是取模的结果

typedef unsigned long long ULL;
ULL h[N], p[N]; // h[k]存储字符串前k个字母的哈希值, p[k]存储 P^k mod 2^64

// 初始化
p[0] = 1;
for (int i = 1; i <= n; i ++ )
{
    h[i] = h[i - 1] * P + str[i];
    p[i] = p[i - 1] * P;
}

// 计算子串 str[l ~ r] 的哈希值
ULL get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

```

### 9. C++ STL简介

```c++
vector, 变长数组，倍增的思想
    size()  返回元素个数
    empty()  返回是否为空
    clear()  清空
    front()/back()
    push_back()/pop_back()
    begin()/end()
    []
    支持比较运算，按字典序

pair<int, int>
    first, 第一个元素
    second, 第二个元素
    支持比较运算，以first为第一关键字，以second为第二关键字（字典序）

string，字符串
    size()/length()  返回字符串长度
    empty()
    clear()
    substr(起始下标，(子串长度))  返回子串
    c_str()  返回字符串所在字符数组的起始地址

queue, 队列
    size()
    empty()
    push()  向队尾插入一个元素
    front()  返回队头元素
    back()  返回队尾元素
    pop()  弹出队头元素

priority_queue, 优先队列，默认是大根堆
    size()
    empty()
    push()  插入一个元素
    top()  返回堆顶元素
    pop()  弹出堆顶元素
    定义成小根堆的方式：priority_queue<int, vector<int>, greater<int>> q;

stack, 栈
    size()
    empty()
    push()  向栈顶插入一个元素
    top()  返回栈顶元素
    pop()  弹出栈顶元素

deque, 双端队列
    size()
    empty()
    clear()
    front()/back()
    push_back()/pop_back()
    push_front()/pop_front()
    begin()/end()
    []

set, map, multiset, multimap, 基于平衡二叉树（红黑树），动态维护有序序列
    size()
    empty()
    clear()
    begin()/end()
    ++, -- 返回前驱和后继，时间复杂度 O(logn)

    set/multiset
        insert()  插入一个数
        find()  查找一个数
        count()  返回某一个数的个数
        erase()
            (1) 输入是一个数x，删除所有x   O(k + logn)
            (2) 输入一个迭代器，删除这个迭代器
        lower_bound()/upper_bound()
            lower_bound(x)  返回大于等于x的最小的数的迭代器
            upper_bound(x)  返回大于x的最小的数的迭代器
    map/multimap
        insert()  插入的数是一个pair
        erase()  输入的参数是pair或者迭代器
        find()
        []  注意multimap不支持此操作。 时间复杂度是 O(logn)
        lower_bound()/upper_bound()

unordered_set, unordered_map, unordered_multiset, unordered_multimap, 哈希表
    和上面类似，增删改查的时间复杂度是 O(1)
    不支持 lower_bound()/upper_bound()， 迭代器的++，--

bitset, 圧位
    bitset<10000> s;
    ~, &, |, ^
    >>, <<
    ==, !=
    []

    count()  返回有多少个1

    any()  判断是否至少有一个1
    none()  判断是否全为0

    set()  把所有位置成1
    set(k, v)  将第k位变成v
    reset()  把所有位变成0
    flip()  等价于~
    flip(k) 把第k位取反

```

## 三.搜索与图论

### 1. 树与图的遍历

```c++
//1. dfs()
int dfs(int u)
{
    st[u] = true; // st[u] 表示点u已经被遍历过

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j]) dfs(j);
    }
}

//2. bfs
queue<int> q;
st[1] = true; // 表示1号点已经被遍历过
q.push(1);

while (q.size())
{
    int t = q.front();
    q.pop();

    for (int i = h[t]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true; // 表示点j已经被遍历过
            q.push(j);
        }
    }
}
```

### 2. 拓扑排序 

```c++
bool topsort()
{
    int hh = 0, tt = -1;

    // d[i] 存储点i的入度
    for (int i = 1; i <= n; i ++ )
        if (!d[i])
            q[ ++ tt] = i;

    while (hh <= tt)
    {
        int t = q[hh ++ ];

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (-- d[j] == 0)
                q[ ++ tt] = j;
        }
    }

    // 如果所有点都入队了，说明存在拓扑序列；否则不存在拓扑序列。
    return tt == n - 1;
}
```

### 3. dijkstra算法

![image-20240325221752666](D:\Code_space\Markdown\imags\image-20240325221752666.png)

```c++
//1.朴素版，时间复杂是 O(n2+m)

int g[N][N];  // 存储每条边
int dist[N];  // 存储1号点到每个点的最短距离
bool st[N];   // 存储每个点的最短路是否已经确定

// 求1号点到n号点的最短路，如果不存在则返回-1
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i ++ )
    {
        int t = -1;     // 在还未确定最短路的点中，寻找距离最小的点
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        // 用t更新其他点的距离
        for (int j = 1; j <= n; j ++ )
            dist[j] = min(dist[j], dist[t] + g[t][j]);

        st[t] = true;
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}


//2. heap优化, O(mlogm)

typedef pair<int, int> PII;

int n;      // 点的数量
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N];        // 存储所有点到1号点的距离
bool st[N];     // 存储每个点的最短距离是否已确定

// 求1号点到n号点的最短距离，如果不存在，则返回-1
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});      // first存储距离，second存储节点编号

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;

        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];
}

```

### 4. Bellman-Ford

单源最短路径，能处理负权边，时间复杂度为 O(VE)

```c++
int n, m;       // n表示点数，m表示边数
int dist[N];        // dist[x]存储1到x的最短路距离

struct Edge     // 边，a表示出点，b表示入点，w表示边的权重
{
    int a, b, w;
}edges[M];

// 求1到n的最短路距离，如果无法从1走到n，则返回-1。
int bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // 如果第n次迭代仍然会松弛三角不等式，就说明存在一条长度是n+1的最短路径，由抽屉原理，路径中至少存在两个相同的点，说明图中存在负权回路。
    for (int i = 0; i < n; i ++ )
    {
        for (int j = 0; j < m; j ++ )
        {
            int a = edges[j].a, b = edges[j].b, w = edges[j].w;
            if (dist[b] > dist[a] + w)
                dist[b] = dist[a] + w;
        }
    }

    if (dist[n] > 0x3f3f3f3f / 2) return -1;
    return dist[n];
}

```

### 5. SPFA

求单源最短路径，能处理负权边，是 **Bellman-ford** **的优化**，平均时间复杂度低于 **Bellman-ford**，最坏情况仍为 O(VE)。

```c++
int n;      // 总点数
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N];        // 存储每个点到1号点的最短距离
bool st[N];     // 存储每个点是否在队列中

// 求1号点到n号点的最短路距离，如果从1号点无法走到n号点则返回-1
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])     // 如果队列中已存在j，则不需要将j重复插入
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    
    return dist[n];
}

// 判断是否有负环
int n;      // 总点数
int h[N], w[N], e[N], ne[N], idx;       // 邻接表存储所有边
int dist[N], cnt[N];        // dist[x]存储1号点到x的最短距离，cnt[x]存储1到x的最短路中经过的点数
bool st[N];     // 存储每个点是否在队列中

// 如果存在负环，则返回true，否则返回false。
bool spfa()
{
    // 不需要初始化dist数组
    // 原理：如果某条最短路径上有n个点（除了自己），那么加上自己之后一共有n+1个点，由抽屉原理一定有两个点相同，所以存在环。

    queue<int> q;
    for (int i = 1; i <= n; i ++ )
    {
        q.push(i);
        st[i] = true;
    }

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n) return true; // 如果从1号点到x的最短路中包含至少n个点（不包括己），则说明存在环
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }

    return false;
}
```

### 6. floyd

```c++
初始化：
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= n; j ++ )
            if (i == j) d[i][j] = 0;
            else d[i][j] = INF;

// 算法结束后，d[a][b]表示a到b的最短距离
void floyd()
{
    for (int k = 1; k <= n; k ++ )
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= n; j ++ )
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
```

### 7. 最小生成树

1. Prim

   ```c++
   int n;      // n表示点数
   int g[N][N];        // 邻接矩阵，存储所有边
   int dist[N];        // 存储其他点到当前最小生成树的距离
   bool st[N];     // 存储每个点是否已经在生成树中
   
   
   // 如果图不连通，则返回INF(值是0x3f3f3f3f), 否则返回最小生成树的树边权重之和
   int prim()
   {
       memset(dist, 0x3f, sizeof dist);
   
       int res = 0;
       for (int i = 0; i < n; i ++ )
       {
           int t = -1;
           for (int j = 1; j <= n; j ++ )
               if (!st[j] && (t == -1 || dist[t] > dist[j]))
                   t = j;
           
           // 不是第一个点且无穷，说明不是连通图
           if (i && dist[t] == INF) return INF;
   
           if (i) res += dist[t];
           st[t] = true;
   
           for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
           
       }
       return res;
   }
   ```
   
   2. Kruskal
   
      ```c++
      int n, m;       // n是点数，m是边数
      int p[N];       // 并查集的父节点数组
      
      struct Edge     // 存储边
      {
          int a, b, w;
      
          bool operator< (const Edge &W)const
          {
              return w < W.w;
          }
      }edges[M];
      
      int find(int x)     // 并查集核心操作
      {
          if (p[x] != x) p[x] = find(p[x]);
          return p[x];
      }
      
      int kruskal()
      {
          sort(edges, edges + m);
      
          for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集
      
          int res = 0, cnt = 0;
          for (int i = 0; i < m; i ++ )
          {
              int a = edges[i].a, b = edges[i].b, w = edges[i].w;
      
              a = find(a), b = find(b);
              if (a != b)     // 如果两个连通块不连通，则将这两个连通块合并
              {
                  p[a] = b;
                  res += w;
                  cnt ++ ;
              }
          }
      
          if (cnt < n - 1) return INF;
          
          return res;
      }
      ```
   
      

### 8. 二分图

**什么是二分图**：节点由两个集合组成，且两个集合内部没有边的图。换言之，存在一种方案，将节点划分成满足以上性质的两个集合。

**二分图的性质**：

1. 如果两个集合中的点分别染成黑色和白色，可以发现二分图中的每一条边都一定是连接一个黑色点和一个白色点
1. 二分图不存在长度为奇数的环 (因为每一条边都是从一个集合走到另一个集合，只有走偶数次才可能回到同一个集合。)

1. 染色法

   ```c++
   int n;      // n表示点数
   int h[N], e[M], ne[M], idx;     // 邻接表存储图
   int color[N];       // 表示每个点的颜色，-1表示未染色，0表示白色，1表示黑色
   
   // 参数：u表示当前节点，c表示当前点的颜色
   bool dfs(int u, int c)
   {
       color[u] = c;
       for (int i = h[u]; i != -1; i = ne[i])
       {
           int j = e[i];
           if (color[j] == -1)
           {
               if (!dfs(j, !c)) return false;
           }
           else if (color[j] == c) return false;
       }
       return true;
   }
   
   bool check()
   {
       memset(color, -1, sizeof color);
       bool flag = true;
       for (int i = 1; i <= n; i ++ )
           if (color[i] == -1)
               if (!dfs(i, 0))
               {
                   flag = false;
                   break;
               }
       return flag;
   }
   ```
   
   2. 匈牙利算法：求二分图的最大匹配

      ```c++
      int n1, n2;     // n1表示第一个集合中的点数，n2表示第二个集合中的点数
      int h[N], e[M], ne[M], idx;     // 邻接表存储所有边，匈牙利算法中只会用到从第一个集合指向第二个集 // 合的边，所以这里只用存一个方向的边
      int match[N];       // 存储第二个集合中的每个点当前匹配的第一个集合中的点是哪个
      bool st[N];     // 表示第二个集合中的每个点是否已经被遍历过
      
      bool find(int x)
      {
          for (int i = h[x]; i != -1; i = ne[i])
          {
              int j = e[i];
              if (!st[j]) //如果没有匹配过
              {
                  st[j] = true;
                  if (match[j] == 0 || find(match[j])) 
                  {
                      match[j] = x;
                      return true;
                  }
              }
          }
          return false;
      }
      
      // 求最大匹配数，依次枚举第一个集合中的每个点能否匹配第二个集合中的点
      int res = 0;
      for (int i = 1; i <= n1; i ++ )
      {
          memset(st, false, sizeof st);
          if (find(i)) res ++ ;
      }
      ```
      
      

## 四. 数学知识

### 算术基本定理

![image-20240529214235703](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240529214235703.png)

### 1. 质数

#### 1.1 试除法判定质数

```c++
bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
            return false;
    return true;
}
```

#### 1.2 试除法分解质因数

![image-20240420195304455](E:\workspace\markdown\md\image-20240420195304455.png)

* 如果一个整数$$N$$是质数，那么显然它可以表示成为 $$N*1$$的积
* 如果一个整数$$N$$是合数，那么显然可以表示成为两个整数$$m$$和$$z$$的积，其中两个至少小于$$N$$，那么我们可以对这两个整数不断进行试除，直到取出来的为质数即可。但是为什么代码里面说$$i……x$$是取质数尔没有合数呢，其实是我们知道合数可以用质数表示，如当我们质数$$2$$的次数除尽了，即代表我们也把关于合数$$4,6,8……2n$$都除尽了

```c++
void divide(int x)
{
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            int s = 0;
            while (x % i == 0) x /= i, s ++ ;
            cout << i << ' ' << s << endl;
        }
    if (x > 1) cout << x << ' ' << 1 << endl;
    cout << endl;
}
```



#### 1.3 朴素筛法求素数 

```c++
int primes[N], cnt;     // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (st[i]) continue;
        primes[cnt ++ ] = i;
        for (int j = i + i; j <= n; j += i)
            st[j] = true;
    }
}
```



#### 1.4 线性筛法求素数 

```c++
int primes[N], cnt;     // primes[]存储所有素数
bool st[N];         // st[x]存储x是否被筛掉

void get_primes(int n)
{
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i]) primes[cnt ++ ] = i;
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;  /**/
        }
    }
}
```

### 2. 约数

#### 2.1 试除法求所有约数

```c++
/*约数成对出现，但是刚好有平方根最多只可能出现一次，所以最后判断一次就可以了，不用每次都判断*/
vector<int> get_divisors(int x)
{
    vector<int> res;
    for (int i = 1; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res.push_back(i);
            if (i != x / i) res.push_back(x / i);
        }
    sort(res.begin(), res.end());
    return res;
}
```

#### 2.2 约数个数和约数之和

![image-20240525223049639](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240525223049639.png)

```c++
如果 N = p1^c1 * p2^c2 * ... *pk^ck
约数个数： (c1 + 1) * (c2 + 1) * ... * (ck + 1)
约数之和： (p1^0 + p1^1 + ... + p1^c1) * ... * (pk^0 + pk^1 + ... + pk^ck)
```

```c++
```



#### 2.3 欧几里得算法，最大公约数

```c++
// 方法1：辗转相除法
int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

// 2. 使用c++库函数
#include <algorithm>
__gcd(a, b)
```

#### 2.4 LCM求最小公倍数

* 求 $$a和b的最小公倍数$$

* ```c++
  lcm(a,b) = a * b / gcd(a, b)
      
   int lcm(int& a, int& b)
  {
      return a * b / __gcd(a, b);
  }
  ```

  



#### 2.5 扩展欧几里得

```c++
// 求x, y，使得ax + by = gcd(a, b)
int exgcd(int a, int b, int &x, int &y)
{
    if (!b)
    {
        x = 1; y = 0;
        return a;
    }
    int d = exgcd(b, a % b, y, x);
    y -= (a/b) * x;
    return d;
}
```




### 3. 欧拉数

#### 3.1 欧拉函数

```c++
int phi(int x)
{
    int res = x;
    for (int i = 2; i <= x / i; i ++ )
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0) x /= i;
        }
    if (x > 1) res = res / x * (x - 1);

    return res;
}
```



#### 3.2 筛法求欧拉函数 

![](E:\workspace\markdown\md\image-20240420203449186.png)

![image-20240420203552257](E:\workspace\markdown\md\image-20240420203552257.png)

```c++
int primes[N], cnt;     // primes[]存储所有素数
int euler[N];           // 存储每个数的欧拉函数
bool st[N];         // st[x]存储x是否被筛掉


void get_eulers(int n)
{
    euler[1] = 1;
    for (int i = 2; i <= n; i ++ )
    {
        if (!st[i])
        {
            primes[cnt ++ ] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j ++ )
        {
            int m = primes[j] * i;
            st[m] = true;
            if (i % primes[j] == 0)
            {
                euler[m] = euler[i] * primes[j];
                break;
            }
            euler[m] = euler[i] * (primes[j] - 1);
        }
    }
}

```

### 4. 快速幂

```c++
// 求 m^k mod p，时间复杂度 O(logk)。
int qmi(int m, int k, int p)
{
    int res = 1 % p, t = m;
    while (k)
    {
        if (k&1) res = res * t % p;
        t = t * t % p;
        k >>= 1;
    }
    return res;
}
```

#### 龟速加

```c++

#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

i64 m, n, k;
// 快速幂是用乘法来表示乘方
// 龟速加是用加法表示乘法
int qmi(i64 m, i64 n, i64 p) {
    i64 res = 1 % p;
    while(n) {
        if (n & 1) res = res * m % p;
        m = m * m % p;
        n >>= 1;
    }
    return res;
}
// 龟速加是用加法表示乘法
i64 qad(i64 m, i64 n, i64 p) {
    i64 res = 0;
    while(n) {
        if (n&1) res = (res+m) % p;
        m = (m+m) % p;
        n >>= 1;
    }
    return res;
}
int main() {

  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> n >> k;
  cout << qad(m, n, k) << endl;
  return 0;
}
```



### 5. 高斯消元解线性方程组

   ```c++
   // a[N][N]是增广矩阵
   int gauss()
   {
       int c, r;
       for (c = 0, r = 0; c < n; c ++ )
       {
           int t = r;
           for (int i = r; i < n; i ++ )   // 找到绝对值最大的行
               if (fabs(a[i][c]) > fabs(a[t][c]))
                   t = i;
   
           if (fabs(a[t][c]) < eps) continue;
   
           for (int i = c; i <= n; i ++ ) swap(a[t][i], a[r][i]);      // 将绝对值最大的行换到最顶端
           for (int i = n; i >= c; i -- ) a[r][i] /= a[r][c];      // 将当前行的首位变成1
           for (int i = r + 1; i < n; i ++ )       // 用当前行将下面所有的列消成0
               if (fabs(a[i][c]) > eps)
                   for (int j = n; j >= c; j -- )
                       a[i][j] -= a[r][j] * a[i][c];
   
           r ++ ;
       }
   
       if (r < n)
       {
           for (int i = r; i < n; i ++ )
               if (fabs(a[i][n]) > eps)
                   return 2; // 无解
           return 1; // 有无穷多组解
       }
   
       for (int i = n - 1; i >= 0; i -- )
           for (int j = i + 1; j < n; j ++ )
               a[i][n] -= a[i][j] * a[j][n];
   
       return 0; // 有唯一解
   }
   
   ```

   

### 6. 组合数和排列数



   1. 递推法求组合数，递推公式

      ```c++
      // c[a][b] 表示从a个苹果中选b个的方案数
      for (int i = 0; i < N; i ++ )
          for (int j = 0; j <= i; j ++ )
              if (!j) c[i][j] = 1;
              else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
      ```

      

   2. 通过预处理逆元的方式求组合数

      ```c++
      首先预处理出所有阶乘取模的余数fact[N]，以及所有阶乘取模的逆元infact[N]
      如果取模的数是质数，可以用费马小定理求逆元
      int qmi(int a, int k, int p)    // 快速幂模板
      {
          int res = 1;
          while (k)
          {
              if (k & 1) res = (LL)res * a % p;
              a = (LL)a * a % p;
              k >>= 1;
          }
          return res;
      }
      
      // 预处理阶乘的余数和阶乘逆元的余数
      fact[0] = infact[0] = 1;
      for (int i = 1; i < N; i ++ )
      {
          fact[i] = (LL)fact[i - 1] * i % mod;
          infact[i] = (LL)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
      }
      ```

      

   3. Lucas定理

      ```c++
      若p是质数，则对于任意整数 1 <= m <= n，有：
          C(n, m) = C(n % p, m % p) * C(n / p, m / p) (mod p)
      
      int qmi(int a, int k, int p)  // 快速幂模板
      {
          int res = 1 % p;
          while (k)
          {
              if (k & 1) res = (LL)res * a % p;
              a = (LL)a * a % p;
              k >>= 1;
          }
          return res;
      }
      
      int C(int a, int b, int p)  // 通过定理求组合数C(a, b)
      {
          if (a < b) return 0;
      
          LL x = 1, y = 1;  // x是分子，y是分母
          for (int i = a, j = 1; j <= b; i --, j ++ )
          {
              x = (LL)x * i % p;
              y = (LL) y * j % p;
          }
      
          return x * (LL)qmi(y, p - 2, p) % p;
      }
      
      int lucas(LL a, LL b, int p)
      {
          if (a < p && b < p) return C(a, b, p);
          return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
      }
      
      ```

      #### 排列数

      排列数 \( P(n, m) \) 表示从 \( n \) 个元素中取出 \( m \) 个元素进行排列的方法数。排列数可以用组合数和阶乘来表示：

      $\[ P(n, m) = \frac{n!}{(n-m)!} \]$

      但如果你已经知道组合数 \( C(n, m) \)，那么可以利用组合数来计算排列数：

      $\[ P(n, m) = C(n, m) \times m! \]$

      其中 \( C(n, m) \) 是从 \( n \) 个元素中取出 \( m \) 个元素的组合数，\( m! \) 是 \( m \) 个元素的全排列数。

      假设我们已经通过某种方式计算并存储了组合数 \( C(n, m) \)，例如使用预处理来填充一个二维数组 `C`。我们可以利用这个数组和一个阶乘数组 `factorial` 来计算排列数。

      下面是一个完整的C++程序，展示如何计算组合数并使用它们来计算排列数：

      ```cpp
      #include <iostream>
      #include <vector>
      
      constexpr int N = 1e2 + 10;  // 定义常数 N
      
      using namespace std;
      
      using i64 = long long;       // 使用 i64 作为 long long 的别名
      
      i64 C[N][N];  // 存储组合数
      i64 factorial[N];  // 存储阶乘
      
      // 计算组合数的函数
      void computeCombinations() {
          for (int i = 0; i < N; ++i) {
              C[i][0] = 1;
              for (int j = 1; j <= i; ++j) {
                  C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
              }
          }
      }
      
      // 计算阶乘的函数
      void computeFactorials() {
          factorial[0] = 1;
          for (int i = 1; i < N; ++i) {
              factorial[i] = factorial[i - 1] * i;
          }
      }
      
      // 根据组合数计算排列数的函数
      i64 getPermutation(int n, int m) {
          if (m > n) return 0;  // 如果 m 大于 n，返回 0
          return C[n][m] * factorial[m];
      }
      
      int main() {
          computeCombinations();  // 计算组合数
          computeFactorials();    // 计算阶乘
      
          // 测试示例
          int n = 5, m = 3;
          cout << "C(" << n << ", " << m << ") = " << C[n][m] << endl;
          cout << "P(" << n << ", " << m << ") = " << getPermutation(n, m) << endl;
      
          return 0;
      }
      ```

      ### 解释

      1. **计算组合数**：
         - `computeCombinations()` 函数使用动态规划方法预处理并计算组合数 `C(n, m)`。`C[i][j]` 表示从 `i` 个元素中取 `j` 个元素的组合数。
         - 边界条件 `C[i][0] = 1` 表示从 `i` 个元素中取 0 个元素的方法只有一种，即不取任何元素。

      2. **计算阶乘**：
         - `computeFactorials()` 函数计算并存储从 0 到 `N-1` 的阶乘值在 `factorial` 数组中。
         - 阶乘的定义为 `factorial[i] = i * factorial[i - 1]`。

      3. **计算排列数**：
         - `getPermutation(int n, int m)` 函数通过组合数和阶乘计算排列数。公式为 `P(n, m) = C(n, m) * m!`。
         - 如果 `m` 大于 `n`，排列数为 0，因为不能从 `n` 个元素中取 `m` 个元素。

      4. **测试**：
         - 在 `main()` 函数中，首先调用 `computeCombinations()` 和 `computeFactorials()` 函数来计算组合数和阶乘。
         - 然后，通过示例 `n = 5, m = 3` 来测试组合数和排列数的计算。

      通过这种方法，你可以使用预处理的组合数和阶乘来高效地计算排列数

   4. 求全排列的解法：

      1. 1个人手写回溯算法模拟

      ```c++
      //求全排列，用回溯算法,对字符串里面的字符
      vector<string>res;
      string path;
      void backTrack(string& s, vector<bool>& used) {
          if (path.size() == s.size()) {
              res.push_back(path);
              return;
          }
          for (int i = 0; i < (int) s.size(); ++i) {
              if (i > 0 && s[i] == s[i-1] && used[i-1] == true) continue;
              if(used[i] == false) {
                  used[i] = true;
                  path += s[i];
                  backTrack(s,used);
                  used[i] = false;
                  path.pop_back();
              }
          }
      }
      std::vector<std::string> permutations(std::string s) {
        // Your code here
          int n = s.size();
          //去重，所以先排一下大小
          sort(s.begin(),s.end());
          vector<bool>used(n,false);
          backTrack(s,used);
          return res;
      }
      ```

      2. 调用库函数

         ==**std::next_permutation**====(**first,last**)==

         它用于将[first, last]范围内的元素重新排列到下一个字典上更大的排列。排列是N的每一个！元素可以采用的可能排列方式(其中N是范围内的元素数量)。可以根据它们在字典上的比较方式来排序不同的排列。

      3. ==**std**::**prev_permutation(first,last)**==

         它用于将[first, last)范围内的元素重新排列为上一个按字典顺序排列的排列。排列是N的每一个！元素可以采用的可能排列方式(其中N是范围内的元素数量)。可以根据它们在字典上的比较方式来排列不同的排列顺序。

      ```c++
      void Next_permutation(string s) {
          //next_permutation(first,end),每次只能找到比当前排列下一个的排列,同样的，prev_permutation()是比当前大的前一个排	//列
          //所以，要想获得所有的全排列，必须先sort(),然后循环里找。
          sort(s.begin(),s.end());
          do {
              res.push_back(s);
          } while(next_permutation(s.begin(),s.end()));
          //return res;
      }
      ```

   5. 分解质因数法求组合数 

      ```c++
      当我们需要求出组合数的真实值，而非对某个数的余数时，分解质因数的方式比较好用：
          1. 筛法求出范围内的所有质数
          2. 通过 C(a, b) = a! / b! / (a - b)! 这个公式求出每个质因子的次数。 n! 中p的次数是 n / p + n / p^2 + n / p^3 + ...
          3. 用高精度乘法将所有质因子相乘
      
      int primes[N], cnt;     // 存储所有质数
      int sum[N];     // 存储每个质数的次数
      bool st[N];     // 存储每个数是否已被筛掉
      
      
      void get_primes(int n)      // 线性筛法求素数
      {
          for (int i = 2; i <= n; i ++ )
          {
              if (!st[i]) primes[cnt ++ ] = i;
              for (int j = 0; primes[j] <= n / i; j ++ )
              {
                  st[primes[j] * i] = true;
                  if (i % primes[j] == 0) break;
              }
          }
      }
      
      
      int get(int n, int p)       // 求n！中的次数
      {
          int res = 0;
          while (n)
          {
              res += n / p;
              n /= p;
          }
          return res;
      }
      
      
      vector<int> mul(vector<int> a, int b)       // 高精度乘低精度模板
      {
          vector<int> c;
          int t = 0;
          for (int i = 0; i < a.size(); i ++ )
          {
              t += a[i] * b;
              c.push_back(t % 10);
              t /= 10;
          }
      
          while (t)
          {
              c.push_back(t % 10);
              t /= 10;
          }
      
          return c;
      }
      
      get_primes(a);  // 预处理范围内的所有质数
      
      for (int i = 0; i < cnt; i ++ )     // 求每个质因数的次数
      {
          int p = primes[i];
          sum[i] = get(a, p) - get(b, p) - get(a - b, p);
      }
      
      vector<int> res;
      res.push_back(1);
      
      for (int i = 0; i < cnt; i ++ )     // 用高精度乘法将所有质因子相乘
          for (int j = 0; j < sum[i]; j ++ )
              res = mul(res, primes[i]);
      
      
      ```

      

### 7. 中国剩余定理(求解线性同余方程组)

### 8. 博弈论

#### 8.1 公平组合游戏

##### 8.1.2 Nim游戏

![image-20240510190313360](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240510190313360.png)

![image-20240505195507793](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240505195507793.png)

```c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int a[N], n;

int main()
{
    cin >> n;
    int res;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (i == 0) res = x;
        else res ^= x;
        
    }
    if (res == 0) cout << "No" << '\n';
    else cout << "Yes" << endl;
    
    return 0;
}
```

##### 8.1.3 台阶Nim游戏

![image-20240510190105415](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240510190105415.png)

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int res;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (i == 1) res = x;
        if (i % 2 == 1 && i != 1) res ^= x;
    }
    
    if (res != 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}
```



##### 8.1.4 有向图游戏 SG函数

![image-20240510193553647](https://cdn.jsdelivr.net/gh/GYHPCG/my_picgo/picture/image-20240510193553647.png)



## 五. 动态规划

### 1. 数字三角形模型

