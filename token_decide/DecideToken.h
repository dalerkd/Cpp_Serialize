#pragma once
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
};

