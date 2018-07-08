#pragma once
#include "NodesManage.h"
#include <map>
#include <string>
#include "EXCEP.h"
#include "debug.h"

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
	/*
	����һ���µ����ͣ�����Ѿ����ڻ����쳣

	���nowNode.father == nullptr������ӵ�ȫ��������.
	������ĳ�ľֲ�������
	*/
	void SetNewType(string typeName, CNodesManage* nowNode)throw(EXCEP());
	
	/*
	�Ҳ������쳣.
	��ȡ����һ�����нڵ� �Ŀ���
	CNodesManage* nowNodeManage: �ڵ����ָ��,ȫ��������Ϊnullptr��
	CNodesManage* nowNode: Ҫ�����������ָ��,ȫ��������Ϊnullptr��
	
	���ܣ����Ҵ�ָ���ڵ�������򼰸��ڵ���������м�ȫ���������Ƿ���ڸ�typeNameֵ��
	�������ȡ�����͵�һ������
	*/
	CNodesManage::NODE* FindTypeFullNodeCopy(string typeName,CNodesManage* nowNodeManage,CNodesManage::NODE* nowNode)throw(EXCEP());
private:
	map<string/*typeName*/ , CNodesManage*> m_symbols;

};

