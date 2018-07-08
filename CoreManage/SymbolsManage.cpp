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

CNodesManage::NODE* CSymbolsManage::FindTypeFullNodeCopy(string typeName, CNodesManage* nowNodeManage, CNodesManage::NODE* nowNode)throw(EXCEP())
{
	if (typeName.empty())
	{
		LogError("New Type不能为空");
	}

	CNodesManage::NODE* tmpNode = const_cast<CNodesManage::NODE*>(nowNode);

	for (;;)
	{
		//到了全局作用域
		if (tmpNode == nullptr||nowNodeManage == nullptr)
		{
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

		/*
		查找本级
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
		回到上一级
		*/
		tmpNode = tmpNode->father;
	}
}
