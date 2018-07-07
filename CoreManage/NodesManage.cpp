#include "stdafx.h"
#include "NodesManage.h"
#include "EXCEP.h"
#include "debug.h"

CNodesManage::CNodesManage()
{
	m_Node_Head = new NODE();
	m_now_Node = const_cast<NODE*>(m_Node_Head);
}


CNodesManage::~CNodesManage()
{
	ExplorerNodes(&CNodesManage::callBackFreeTheNode, const_cast<NODE*>(m_Node_Head));
}

void CNodesManage::AddChildNode(NODE * pnode)
{
	m_now_Node->child_list.push_back(pnode);
}

CNodesManage::NODE * CNodesManage::GetFatherNode()
{
	return m_now_Node->father;	
}

CNodesManage::NODE* CNodesManage::GetAllDataCopy()
{
	
}
/*
后序遍历,深度有限
*/
bool CNodesManage::ExplorerNodes(CALLBACK_EXPLORER call,NODE* start)
{
	if (call==nullptr)
	{
		LogError("callback == nullptr"); \
		return false;
	}
	if (start == nullptr)
	{
		return true;
	}
	bool b = false;
	

	list<NODE*>::iterator iter;
	for (iter = start->child_list.begin();iter!=start->child_list.end();++iter)
	{
		b = (this->*call)(*iter);
		if (!b)
		{
			return false;
		}
	}




	return (this->*call)(start);

}

bool CNodesManage::callBackFreeTheNode(NODE* p)
{
	delete(p);
	return true;
}

bool CNodesManage::callBackCopy(NODE *)
{
	throw();
	return false;
}
