# 常用STL整理
## 容器和配接器 
### list (链表)
<font size = 4>

list可以认为是一个线性的双向链表，具有链表的特性，不使用连续的内存空间，可以快速的插入和删除，不支持随机的内部访问。使用需包含`include<list>`头文件，`std`命名空间。
</font>  

<font size = 4>

常用使用方法:  
1.创建实例，迭代器  

```c++
int a[] = { 1,2,3,4,5 };
list<int> lt;
list<int>::iterator it;//创建迭代器
list<int> lt(a, a + 5);
list<int> lt(2, 100);    
```

2.输入输出，插入删除，迭代器遍历  

```c++
//push_back,push_front(插入尾，插入头)
int a;
cin >> a;
lt.push_back(a);
lt.push_front(a);

//pop_back,pop_front(删除尾，删除头)
lt.pop_back();
lt.pop_front();

//assign(插入)
list<int> first;
list<int> second;
first.assgin(2,100);//添加2个100的元素
second.assgin(first.begin(),first.end())//将first拷贝给second

//insert(指定位置插入)
/*
iterator insert (iterator position, const value_type& val);  
//position是要插入的这个list的迭代器，val是要插入的值
void insert (iterator position, size_type n, const value_type& val);  
//从该list容器中的position位置处开始，插入n个值为val的元素
template <class InputIterator>
void insert (iterator position, InputIterator first, InputIterator last);  
//first，last是我们选择的把值插入到这个list中的值所在的容器的迭代器
*/
list<int> lt;
list<int>::iterator it;
it = lt.begin();
lt.insert(it, 2);
lt.insert(it, 2, 100);
lt.insert(it, sth.begin(), sth.end());
//在指定位置插入某容器的一个区段

//遍历
list<int> lt;
list<int>::iterator it;
for (it = lt.begin(); it != lt.end(); it++) cout << *it;  
```
3.常用成员函数  

```c++
//erase(删除元素)erase函数是可以有返回值的，注意当删除元素的同时，迭代器也被销毁了。
lt.erase(iterator it);//删除it位置的元素
lt.erase(iterator begin,iterator end);//删除一定区间的元素

//swap(交换)
list<int> first;
list<int> second;
first.swap(second);

//clear(清空)
lt.clear();

//splice(转移元素)
/*
void splice (iterator position, list& x); 
//将列表x中的所有元素移到当前list中，从当前列表的position指向的位置开始，此时列表x为空
void splice (iterator position, list& x, iterator i);  
//将列表x中迭代器 i 指向的元素移到当前list的position指向的位置处，由于i指向的元素从列表x中被移，所以迭代器 i 此时是invalid的；position是当前列表的迭代器，i是列表x的迭代器
void splice (iterator position, list& x, iterator first, iterator last);  
//将列表x中[first, last)的元素移到当前list中，从position指向的位置开始；first,last是列表x的迭代器
*/

//remove(移除指定元素)
/*
void remove (const value_type& val);  
//从list中删除所有值为val的元素
*/
lt.remove(100);

//unique(删除重复值)
/*
void unique();  
//只能删除相邻的重复元素，然后保留第一个值，因此这个函数只对排好序的list有用
*/

//sort(排序) 默认升序，可自写cmp函数
lt.sort(cmp);

//reverse(逆序)
lt.reserve();

//merge(合并有序的list)
list<int> first;
list<int> second;
first.merge(second);

//remove_if(按条件移除元素)
bool single_digit (const int& value) { return (value < 10); }
lt.remove_if (single_digit);  
```

</font>

### stack（栈）  

<font size = 4>stack就是一个标准的栈，后进先出，不能遍历。使用需包含`include<stack>`头文件，`std`命名空间。

</font>

<font size = 4>

常用使用方法：  

```c++
int a;
stack<int> st;//创建实例
cin >> a;
st.push(a);//ru'zhan
a = st.top();//返回入栈
st.pop();出栈
bool b = st.empty（）;//判断栈是否为空
a = st.size();//返回栈长度  
```

</font>

### queue（队列）

 <font size = 4>  

queue先进先出，不能遍历。使用需包含`include<queue>`头文件，`std`命名空间。  </font>

<font size = 4>

```c++
int a;
queue<int> que;//创建实例
cin >> a;
que.push(a);//进队
a = que.front();//返回队头
a = que.back();//返回队尾
que.pop();//出队
bool b = que.empty();//队列是否为空
a = que.size();//返回队列长度
```

</font>

### priority_queue（优先队列）

<font size = 4>

可以认为是队列的一种，但是会按照一种优先规律，将优先级最高的元素始终置于队头。底层通过heap（堆）来实现，所以默认为一个大根堆。 

</font>

<font size = 4>

常用使用方法：

```c++
struct node
{
    int x,y;
    bool operator < (const node & a) const
    {
        return x<a.x;
    }
};


int a;
priority_queue <int> que;//创建实例，默认降序
priority_queue <int, vector<int>, greater<int> > que2;//升序
priority_queue <node>;//重载小于，可以利用重载小于来自定义优先级
priority_queue
cin >> a;
que.push(a);//进队
a = que.top();//返回队头
que.pop();//出队
bool b = que.empty();//队列是否为空
a = que.size();//返回队列长度
```

</font>

###  set（集合）

<font size = 4>

set内部通过红黑树实现，实现了一个自动排序，元素值唯一的容器。查找的复杂度为（logn），set中的元素值不能直接被修改，在其中的查找属于二分查找。使用需包含`include<set>`头文件，`std`命名空间。

</font>

<font size = 4>

常用使用方法： 

1.创建实例，迭代器

```c++
set <int> se;
set <int>::iterator it;
```

2.插入删除(insert依然可以插入一段元素)

```c++
//insert(插入)
int a;
set <int> se;
cin >> a;
se.insert(a);
//erase(删除)
se.erase(iterator it);
```

3.常用成员函数

```c++
//find(查找某个值)
se.find(2);//返回2所在的迭代器，否则返回end()

//lower_bound(查找第一个大于等于key的值)upper_bound(查找第一个大于key的值)
se.lower_bound(2);
se.upper.bound(2);
```

4.mutiset（可重复插入的set）

```c++
mutiset <int> se;
//count(返回某一键值出现次数,set中使用此函数只会返回1或0)
int a = se.count(2);
```

</font>

### vector（向量）

<font size = 4>

可以将其近似的认为是一个动态的数组。使用需包含`include<vector>`头文件，`std`命名空间。

</font>

<font size = 4>

常用使用方法：
1.创建实例，迭代器

```c++
vector <int> vec;
vector <int> vec(10,1);//创建了有10个元素的向量，并赋初值为1
int b[7]={1,2,3,4,5,9,8};vector<int> a(b,b+7);
vector <int>::iterator it;
```

2.插入删除，访问

```c++
//push_back(尾部插入一个元素)
vec.push_back(a);

//insert(插入一个元素)
vec.insert(position,elem)   //在pos位置插入一个elem拷贝，传回新数据位置。
vec.insert(position,n,elem) //在pos位置插入n个elem数据，无返回值。
vec.insert(position,begin,end)  //在pos位置插入在[beg,end)区间的数据，无返回值。

//erase(删除指定位置的元素)
vec.erase(iterator it);

//[]访问，由于vector重载了[]，所以可以利用[]直接访问已有元素
cout << vec[1];

//at(返回指定位置的元素)
vec.at(1);//at()函数具有检测是否越界的功能，如果越界会抛出错误，所以安全性高于[]

//迭代器访问
vector <int> vec;
vector <int>::iterator it;
for (it = vec.begin(); it != vec.end(); it++) cout << *it;
```

3.常用成员函数

```c++
//vec.clear();//清空

//vec.back(),vec.front(),vec.empty()//返回末尾，返回头，判断是否为空

//vec.begin(),vec.end()//传回对应位置的迭代器

//vector作为容器，可以使用较多algorithm中的函数，例如sort，reverse，swap。
```

</font>

### map&&pair（关联）

<font size = 4>

map内部也是通过红黑树实现的，map的形式为一个键值对，和set一样查找的复杂度为（logn）可以修改value值，但不能修改key值。使用需包含`include<map>`头文件，`std`命名空间。

</font>

<font size = 4>

常用使用方法：
1.创建实例，迭代器

```c++
map <int,string> mp;//创建了一个以int为key，string为value的键值对。
map <int,string>::iterator it; 
```

2.插入删除

```c++
//insert(插入)//注意前两种只能在map内无此元素的时候插入，而最后一种可以实现覆盖再赋值
mp.insert(make_pair(1, "one"));//利用make_pair函数构造出一对关联量插入
mp.insert(map<int, string>::value_type(1, "one"));//插入map的value_type数据
mp[1] = "one";//利用重载[]输入赋值

//earse(删除)
mp.erase（iterator it);//通过一个条目对象删除
mp.erase（iterator first，iterator last）//删除一个范围
int n = erase(con容器st Key&key);//通过关键字删除，删除成功n==1.否则==0
```

3.常用成员函数

```c++
//find(查找某个值)
mp.find(1);//返回key所在的迭代器，否则返回end()

//lower_bound(查找第一个大于等于key的值)upper_bound(查找第一个大于key的值)
mp.lower_bound(1);
mp.upper.bound(1);

//count(返回某一key值出现次数,map中使用此函数只会返回1或0)
int a = mp.count(1);
```

</font>

##  常用算法

### #include<algorthm> （算法）

<font size = 4>

```c++
//sort(快速排序)stable_sort(稳定排序)
sort(start，end，排序方法);

//reserve(反转容器）
reserve(vec.begin(),vec.end());

//lower_bound,upper_bound(二分查找)//返回的是位置,前提要有序
int num[6]={1,2,4,7,15,34}; 
sort(num,num+6);
int pos1=lower_bound(num,num+6,7)-num;    //返回数组中第一个大于或等于被查数的值 
int pos2=upper_bound(num,num+6,7)-num;    //返回数组中第一个大于被查数的值

//集合操作(前提容器序列有序)
includes(s1.begin(), s1.end(), s2.begin(), s2.end());
//s1是否包含s2，递增序列使用less<int>(),递减序列使用greater<int>()。
set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3));
//求并集，并输入到支持insert操作的s3中，也可以使用back_inserter(s3)输入到支持push_back操作的s3
set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3));
//求交集
set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3));
//求差集

//堆操作
make_heap(begin(),end());//对一个序列建立一个堆，默认大根堆，greater<int>()则是小根堆
pop_heap(begin(),end());//将堆顶元素移到序列末尾，一般搭配pop_back();使用
push_heap(begin(), end());//有新元素插入序列末尾后的加入操作。
```

</font>