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

void CSymbolsManage::SetNewType(string typeName, CNodesManage * pNODE) throw(EXCEP())
{
	if (typeName.empty())
	{
		LogError("New Type����Ϊ��");
	}
	if (pNODE == nullptr)
	{
		LogError("SetNewTypeʱ pNode����Ϊ��");
	}
	if (m_symbols.end() != m_symbols.find(typeName))
	{
		LogError("��ӵ������Ѿ�����");
	}

	m_symbols[typeName] = pNODE;
}

CNodesManage::NODE* CSymbolsManage::FindTypeFullNodeCopy(string typeName) throw(EXCEP())
{
	if (typeName.empty())
	{
		LogError("New Type����Ϊ��");
	}

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
