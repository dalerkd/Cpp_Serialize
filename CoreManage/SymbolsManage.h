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
	��ĳ���Ƿ���
	Y: ������ָ��
	N: 
	һ���뷨�Ƿ�����ָ�롣
	ͷ�ṹ��ָ�룺

	struct sa{
	}
	struct sb{
	sa c;
	}
	��Щָ����ôɾ����
	- �����ͷ�
	- �ϲ���
		�Ժ��ַ�ʽ��
		- ��ָ�뷽ʽ
		- ����ָ�뷽ʽ
			- ˭���ͷţ�
			- �Ƿ��������ݣ�
				- ����
					- ͳһ�ͷ�
					- ���ü���
	����ˣ�
	���ű�ָ������ݲ�Ӧ���ǹ������ݣ�
	ÿ�η��ض���һ���µ���Ҫ�ͷŵ�ָ��ṹ��
	!����ָ����ͬλ����Ϊ�˷�ֹ��ѭ����
	{
	������δ���������ܵ�ѭ�������أ�
	��Ϊ�����͵��ظ�����
	������������ǽ�ֹѭ�����õġ�
	Ҳ��������ṹδ�����֮ǰ�ǲ�����ڷ��ű�
	�еġ�
	��ͽ���ˡ�
	���ű�Ĳ�����
	- ��¼����ָ�������
	- ��ѯ������ָ��󣺵�����ָ�뷵��һ��
	�µ���������



	}
	*/

public:
	void SetNewType(string typeName, CNodesManage*);
	CNodesManage::NODE* FindType(string typeName);
private:
	map<string/*typeName*/ , CNodesManage*> symbols;

};

