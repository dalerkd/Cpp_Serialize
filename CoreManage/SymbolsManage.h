#pragma once
#include "NodesManage.h"
#include <map>
#include <string>
using std::map;
using std::string;

class CSymbolsManage
{
public:
	CSymbolsManage();
	~CSymbolsManage();

public:
	/*
	查某项是否在
	Y: 返回类指针
	N: 
	一种想法是返回类指针。
	头结构体指针：

	struct sa{
	}
	struct sb{
	sa c;
	}
	这些指针怎么删除？
	- 自行释放
	- 合并？
		以何种方式？
		- 类指针方式
		- 数据指针方式
			- 谁来释放？
			- 是否重用数据？
				- 重用
					- 统一释放
					- 引用计数
	清楚了：
	符号表指向的内容不应该是共用数据：
	每次返回都是一份新的需要释放的指针结构体
	!但是指向相同位置是为了防止死循环。
	{
	到底如何处理这个可能的循环引用呢？
	因为是类型的重复引用
	解决：编译器是禁止循环引用的。
	也就是这个结构未定义好之前是不会放在符号表
	中的。
	这就解决了。
	符号表的操作是
	- 记录新类指针和名字
	- 查询到新类指针后：调用类指针返回一个
	新的完整数据



	}
	*/

public:
	void SetNewType(string typeName, CNodesManage*);
	CNodesManage::NODE* FindType(string typeName);
private:
	map<string/*typeName*/ , CNodesManage*> symbols;

};

