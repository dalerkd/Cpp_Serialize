#pragma once
/*
用于处理Token
分级处理:
1. 得到基础类型和值eg:
{string,你好}//字符串
{number,3.14}//数字
{identifier,标识符}//字符串
{keywords,struct}//关键字
{keywords,[}
{keywords,]}
{keywords,<}
{keywords,>}
{keywords,'{'}
{keywords,'}'}
{keywords,';'}


'struct' -> '{' -> '}'
				
```
(struct\{(\1)*|;*\})
```	   
递归:函数专处理某一系列。
每一个函数再构成一个switch。
如果检查到是某系列就:走该函数处理。
void GlobalDecide{
swtich
case struct
{
DecideStruct

}
}
void DecideStruct{
swtich
case struct
{
DecideStruct
//处理结束就return.出错就throw()
catch()
{
要打印Get行号,字符,以及当前token等信息;

}
}
}

*/
class CDecideToken
{
public:
	CDecideToken();
	~CDecideToken();
};

