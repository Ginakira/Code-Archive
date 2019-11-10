# 四、STL库

## 1.栈(stack)

头文件 `#include <stack>`

定义 `stack<typename> name`

**常用函数**

`push()` 压栈，入栈一个元素

`top()` 访问栈顶元素 ***注意：当栈空时访问栈顶元素非法***

`pop()` 弹出栈顶元素

`empty()` 判断是否栈空，是返回true，否返回false

`size()` 返回栈内当前元素个数

## 2.不定长数组（vector）

头文件 `#include <vector>`

定义 `vector<typename> name`

**访问**

- 通过下标访问name[index]

- 通过迭代器访问

  - 定义方式：`vector<typename>::iterator it = name.begin()`

    得到 `it` 后通过 `*it` 来访问vector里的元素， `*(it + i)` 来访问第`i`个元素

    遍历vector的循环可写：

    ```cpp
    for(vector<typename>::iterator it = name.begin(); it != name.end(); it++){}
    ```

**常用函数**

`push_back()` 在尾部插入一个元素

`pop_back()` 在首部插入一个元素

`size()` 获取vector长度，返回unsigned类型

`clear()` 清空

`insert(it, x)` 向迭代器it处插入元素x 

`erase()`

- 删除迭代器it处的单个元素 `erase(it)`
- 删除一个区间 [first, last) 的元素`erase(first, last)` first与last都是迭代器

## 3.集合（set）

特点：内部自动有序且不含重复元素，默认升序

头文件 `#include <set>`

定义 `vector<typename> name`

只能通过迭代器访问set内元素

**访问**

只能通过迭代器访问，迭代器定义`set<typename>::iterator it`

使用`*it`来访问set内的元素

采用下列方式枚举：

```cpp
for(set<typename>::iterator it = name.begin(); it != name.end(); it++){}
```

**常用函数**

`insert()` 向集合内插入一个元素

`find(value)` 返回对应值是value的迭代器

`erase()` 删除单个元素 `s.earse(it)` （迭代器）或`s.erase(value)`（对应值）

`size()` 返回集合大小

`clear()` 清空集合

**通过重载小于号自定义结构体集合排序规则**

重载结构体小于号，示例（id优先升序，相同时age升序）：

```cpp
bool operator < (const Students &s) const {
    if(id != s.id) return id < s.id;
    else return age < s.age;
}
```



## 4.队列（queue）

头文件 `#include <queue>`

定义 `queue<typename> name`

**常用函数**

`front()` 访问队首

`back()` 访问队尾

`push()` 入队一个元素

`pop()`  队首元素出队

`empty()` 队列判空，返回true为空

`size()` 返回队列大小

## 5.优先队列（priority_queue）

头文件 `#include <queue>`

定义 `priority_queue<typename> name`

**常用函数**

`push()` 往堆底插入元素，向上调整

`top()` 访问队首元素，也就是优先级最高的元素

`pop()` 令队首元素出队

`empty()` 队列判空

`size()` 返回队列大小

**优先级自定义**

- 基本数据类型

  `priority_queue<int, vector<int>, less<int> > q` 数字大的优先级大

  `priority_queue<int, vector<int>, greater<int> > q` 数字小的优先级大

- 结构体类型（或在结构体内重载小于号）

  ```cpp
  struct cmp{
      bool operator (const student &s1, const student &s2){
          return s1.s_grade > s2.s_grade;//grade大的优先级高
      }
  }
  priority_queue<student, vector<student>, cmp> q;
  ```

## 6.键值对（map）

特点：每个键只能出现一次

头文件 `#include <map>`

定义 `map<typename1, typename2> mp`

**访问**

- 通过下标访问，例如`mp['key']`

- 通过迭代器访问

  ```cpp
  map<typename1, typename2>::iterator it;
  for(map<typename1, typename2>::iterator it = mp.begin(); it != mp.end(); it++){//it->first; 访问键, it->second; 访问值}
  ```

**常用函数**

`find(key)` 返回key的映射的迭代器

`erase(it)` 删除迭代器指向的键值对

`erase(key)` 删除键为key的键值对

`erase(first, last)` 删除[first, last)区间元素

`size()` 返回map的大小

`clear()` map判空

