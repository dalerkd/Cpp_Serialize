========================================================================
    控制台应用程序：CoreManage 项目概述
========================================================================
##2018年7月7日
Hi本项目是一个进步！
本项目的组成是这样的：

```
class NodesManage;  //易
class SymbolsManage;//每个节点类型都要注册: 存储NodesManage的指针
class StringAnaly;  //
```
我将对其难点进行分析：
- `class NodesManage;`预计难点是：
node的设计:我预备添加数种基础类型的存储。虽然似乎增加了大小，
但我不想过早优化，特别是对于这个有挑战的项目。
```
struct value{
float;
char;
double;
LONG64;//我不打算支持long long
std::string;
}
struct node{
string type;
value node_value;
list<node> child_list;
}
```
这样似乎就简单了。
接口:
SetValue
深度优先遍历？->基本类型？死循环？{
每个结构都会先搜索在符号表。
有 就结束。
没有 就注册:继续遍历。

问题:
如何返回父亲节点？
答：一般不需要返回父亲节点，因为这是一个从
树叶开始构建的过程。
只有特殊情况,eg:
map,vector中嵌套新的复合定义
map<int,map<float,int>> a;//处理int和float节点
的时候有返回需求。

vector和map与struct相比还是不同的，
vector是数组:
map是key-value数组
struct不是数组


}
