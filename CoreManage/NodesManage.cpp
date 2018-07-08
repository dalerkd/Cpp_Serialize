#include "stdafx.h"
#include "NodesManage.h"
#include "EXCEP.h"
#include "debug.h"

CNodesManage::CNodesManage() :CopyNowNode(nullptr), CopyHeadNode(nullptr)
{
	m_Node_Head = new NODE();
	m_now_Node = const_cast<NODE*>(m_Node_Head);
}


CNodesManage::~CNodesManage()
{
	ExplorerNodesPostOrder(&CNodesManage::callBackFreeTheNode, nullptr,const_cast<NODE*>(m_Node_Head));
}

void CNodesManage::BackFatherNode()
{
	if (m_now_Node!=nullptr)
	{
		m_now_Node = m_now_Node->father;
	}
}

void CNodesManage::AddChildNode(NODE * pnode)
{
	m_now_Node->child_list.push_back(pnode);
}

CNodesManage::NODE * CNodesManage::GetFatherNode()
{
	return m_now_Node->father;	
}

CNodesManage::NODE* CNodesManage::GetAllDataCopy(CNodesManage::NODE* startNode)
{
	if (CopyNowNode != nullptr)
	{
		LogError("CopyNowNode!=nullptr ����û�����");
	}
	if (CopyHeadNode != nullptr)
	{
		LogError("CopyResultNode!=nullptr ����û�����");
	}
	CopyNowNode = nullptr;
	CopyHeadNode = nullptr;

	if (startNode==nullptr)
	{
		startNode = const_cast<NODE*>(m_Node_Head);
	}

	ExplorerNodesPreviousOrder(&CNodesManage::callBackCopy, &CNodesManage::callBackCopyNodeBackNotify,
		startNode);





	NODE* temp = CopyHeadNode;
	CopyHeadNode = nullptr;
	CopyNowNode = nullptr;
	return temp;


}
bool CNodesManage::ExplorerNodesPreviousOrder(CALLBACK_EXPLORER call, CALLBACK_EXPLORER_BACK back, NODE * start)
{
	if (call == nullptr)
	{
		LogError("callback == nullptr"); \
			return false;
	}
	if (start == nullptr)
	{
		if (back != nullptr)
		{
			(this->*back)();
		}
		return true;
	}
	bool b = false;

	b = (this->*call)(start);
	if (b == false)
	{
		if (back != nullptr)
		{
			(this->*back)();
		}
		return false;
	}

	list<NODE*>::iterator iter;
	for (iter = start->child_list.begin(); iter != start->child_list.end(); ++iter)
	{
		b = ExplorerNodesPostOrder(call,back, *iter);
		if (!b)
		{
			if (back != nullptr)
			{
				(this->*back)();
			}
			return false;
		}
	}
	if (back != nullptr)
	{
		(this->*back)();
	}
	return true;
}
/*
�������,�������
*/
bool CNodesManage::ExplorerNodesPostOrder(CALLBACK_EXPLORER call, CALLBACK_EXPLORER_BACK back,NODE* start)
{
	if (call==nullptr)
	{
		LogError("callback == nullptr"); \
		return false;
	}
	if (start == nullptr)
	{
		if (back != nullptr)
		{
			(this->*back)();
		}
		return true;
	}
	bool b = false;
	

	list<NODE*>::iterator iter;
	for (iter = start->child_list.begin();iter!=start->child_list.end();++iter)
	{
		//b = (this->*call)(*iter,6);
		b = ExplorerNodesPostOrder(call,back,*iter);
		if (!b)
		{
			if (back != nullptr)
			{
				(this->*back)();
			}
			return false;
		}
	}
	if (back != nullptr)
	{
		(this->*back)();
	}

	return (this->*call)(start);

}

bool CNodesManage::callBackFreeTheNode(NODE* p)
{
	delete(p);
	return true;
}

bool CNodesManage::callBackCopy(NODE *pNode)
{
	/*
	�ڵ㣺���ƺ�����������
		��θ��ƣ�
		- �����������Ӳ���ָ����ǰ�������
		�Ⱥ������(��Ҫ�ܶ�ڵ�������м�����������ںϵĹ���)������ķ����ǣ�
		������� + ������
		�����ʺϣ��ͷ���Դ��
		�����ʺϣ�������Դ��
	{
		��Ҫ�˽⣺
		- ���ڵ�:֪�����ĸ�������½ڵ�
		- ���������⣺
		û����֪ͨ���½ڵ����ĸ���֧������
		- listֱ����Ӻ���
	}
	*/
	
	if (nullptr == CopyHeadNode)
	{
		CopyHeadNode = new NODE();
		CopyNowNode = CopyHeadNode;
		CopyNowNode->father = nullptr;
		CopyNowNode->node_value = pNode->node_value;
	}
	else
	{

		if (CopyNowNode == nullptr)
		{
			LogTips("CopyNowNode==nullptr");
			return true;
		}
		
		NODE* temp = new NODE();
		temp->father = CopyNowNode;
		temp->node_value = pNode->node_value;
		CopyNowNode->child_list.push_back(temp);
		CopyNowNode = temp;
	}	
	return true;
}

void CNodesManage::callBackCopyNodeBackNotify()
{
	if (m_now_Node)
	{
		m_now_Node = m_Node_Head->father;
	}
}
