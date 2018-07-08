#include "stdafx.h"
#include "SymbolsManage.h"


CSymbolsManage::CSymbolsManage()
{
}


CSymbolsManage::~CSymbolsManage()
{
	map<string, CNodesManage*>::iterator iter = m_symbols.begin();
	for (;iter!=m_symbols.end();++iter)
	{
		if (nullptr == iter->second)
		{
			LogTips("Type:%s,�Ķ�Ӧֵ��:nullptr",iter->first.c_str());
		}
		else
		{
			delete(iter->second);
		}
	}
}

void CSymbolsManage::SetNewType(string typeName, CNodesManage* nowNodeManage, CNodesManage::NODE* fatherNode) throw(EXCEP())
{
	if (typeName.empty())
	{
		LogError("New Type����Ϊ��");
	}
	
	if (nowNodeManage==nullptr)
	{
		LogError("SetNewTypeʱ NodeMange����Ϊ��");
	}

	if (fatherNode == nullptr)
	{//ȫ��������
		if (m_symbols.end() != m_symbols.find(typeName))
		{
			LogError("��ӵ�������ȫ���������Ѿ�����");
		}

		m_symbols[typeName] = nowNodeManage;
	}
	else//�ֲ�������
	{
		fatherNode->child_list;

		list<CNodesManage::NODE*>::iterator iter;
		for (iter = fatherNode->child_list.begin(); iter != fatherNode->child_list.end(); ++iter)
		{
			auto pNode = *iter;
			if (pNode != nullptr)
			{
				if (pNode->type == typeName)
				{
					LogError("���������Ѿ����ڸýڵ��������,�����ظ�����");
				}
			}
		}




		CNodesManage::NODE* p = new CNodesManage::NODE();
		p->type = typeName;
		p->father = fatherNode;
		fatherNode->child_list.push_back(p);
	}


	
}

CNodesManage::NODE* CSymbolsManage::FindTypeFullNodeCopy(string typeName, CNodesManage* nowNodeManage, CNodesManage::NODE* nowNode)throw(EXCEP())
{
	if (typeName.empty())
	{
		LogError("New Type����Ϊ��");
	}

	CNodesManage::NODE* tmpNode = const_cast<CNodesManage::NODE*>(nowNode);

	for (;;)
	{
		//����ȫ��������
		if (tmpNode == nullptr||nowNodeManage == nullptr)
		{
			map<string, CNodesManage*>::iterator iter = m_symbols.find(typeName);
			if (m_symbols.end() == iter)
			{
				LogError("���ҵ����Ͳ�����");
			}
			else
			{
				return iter->second->GetAllDataCopy();
			}
		}

		/*
		���ұ���
		*/
		list<CNodesManage::NODE*>::iterator iter;
		for (iter = tmpNode->child_list.begin(); iter != tmpNode->child_list.end(); ++iter)
		{
			auto pNode =*iter;
			if (pNode!=nullptr)
			{
				if (pNode->type == typeName)
				{
					return nowNodeManage->GetAllDataCopy(pNode);
				}
			}
		}

		/*
		�ص���һ��
		*/
		tmpNode = tmpNode->father;
	}
}
