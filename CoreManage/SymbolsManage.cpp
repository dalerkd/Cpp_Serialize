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
			LogTips("Type:%s,的对应值是:nullptr",iter->first.c_str());
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
		LogError("New Type不能为空");
	}
	if (pNODE == nullptr)
	{
		LogError("SetNewType时 pNode不能为空");
	}
	if (m_symbols.end() != m_symbols.find(typeName))
	{
		LogError("添加的类型已经存在");
	}

	m_symbols[typeName] = pNODE;
}

CNodesManage::NODE* CSymbolsManage::FindTypeFullNodeCopy(string typeName) throw(EXCEP())
{
	if (typeName.empty())
	{
		LogError("New Type不能为空");
	}

	map<string, CNodesManage*>::iterator iter = m_symbols.find(typeName);
	if (m_symbols.end() == iter)
	{
		LogError("查找的类型不存在");
	}
	else
	{
		return iter->second->GetAllDataCopy();
	}
}
