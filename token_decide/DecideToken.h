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
���ڴ���Token
�ּ�����:
1. �õ��������ͺ�ֵeg:
{string,���}//�ַ���
{number,3.14}//����
{identifier,��ʶ��}//�ַ���
{keywords,struct}//�ؼ���
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
�ݹ�:����ר����ĳһϵ�С�
ÿһ�������ٹ���һ��switch��
�����鵽��ĳϵ�о�:�߸ú�������
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
//���������return.�����throw()
catch()
{
Ҫ��ӡGet�к�,�ַ�,�Լ���ǰtoken����Ϣ;

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
		string identifier;//��ʶ��
		string keyWord;//�ؼ���
		/*
		string �ַ���
		int value;
		*/

	};
	/*
	����ֵ: ������: identifier|keyWord
	- �ڲ��ᴦ��ע��,���Բ��᷵��ע��
	- ���йؼ�����:KW_NEW_LINE
	����\n����\r\n

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
	size_t m_lineNumberNow;//��ǰ����ڼ��У���1��ʼ
	size_t m_columnsNow;//��ǰ����ĵڼ��У���1��ʼ
	size_t m_lastTokenOffset;//��ǰƫ��
	size_t m_nowTokenOffset;//�ϴ�ƫ��

public:
	void StartDecideToken();
	//////////////////////////////////////////////
	//����ͬ��token�����ֵ��ȡ����
	void DecideGlobal();
	void DecideStruct();
	void DecideSingleLineComments();//����ע�ʹ���
	void DecideMultiLineComments();//����ע�ʹ���
	/*int a; ������ü��;������ֱ�ӷ���*/
	void DecideCreateNewType();
};

