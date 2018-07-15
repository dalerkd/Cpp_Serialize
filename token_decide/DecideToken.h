#pragma once

#include "debug.h"
#include <string>
using std::string;

typedef std::uint64_t hash_t;
constexpr hash_t prime = 0x100000001B3ull;
constexpr hash_t basis = 0xCBF29CE484222325ull;
hash_t hash_(char const* str)
{
	hash_t ret{ basis };
	while (*str) {
		ret ^= *str;
		ret *= prime;
		str++;
	}
	return ret;
}
constexpr hash_t hash_compile_time(char const* str, hash_t last_value = basis)
{
	return *str ? hash_compile_time(str + 1, (*str ^ last_value) * prime) : last_value;
}
constexpr unsigned long long operator "" _hash(char const* p, size_t)
{
	return hash_compile_time(p);
}


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

public:
	struct st_token_value {
		string identifier;//标识符
		string keyWord;//关键字
		/*
		string 字符串
		int value;
		*/

	};
	/*
	返回值: 类型名: identifier|keyWord
	- 内部会处理注释,所以不会返回注释
	- 换行关键字是:KW_NEW_LINE
	包括\n或者\r\n

	*/
	string GetToken(st_token_value& value);
	
	size_t GetLineNumberNow(){
		return m_lineNumberNow;
	}
	size_t GetColumnsNow() {
		return m_columnsNow;
	}
	size_t GetLastTokenOffset(){
		return m_nowTokenOffset;
	}

private:
	size_t m_lineNumberNow;//当前处理第几行，从1开始
	size_t m_columnsNow;//当前处理的第几列，从1开始
	size_t m_lastTokenOffset;//当前偏移
	size_t m_nowTokenOffset;//上次偏移

public:
	void StartDecideToken();
	//////////////////////////////////////////////
	//处理不同的token检查与值获取操作
	void DecideGlobal();
	void DecideStruct();
	void DecideSingleLineComments();//单行注释处理
	void DecideMultiLineComments();//多行注释处理
	/*int a; 建议最好检查;而不是直接返回*/
	void DecideCreateNewType();
};

