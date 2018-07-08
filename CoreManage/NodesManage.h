#pragma once
#include <string>
#include <list>
using std::string;
using std::list;

/*
负责树空间的释放
*/
class CNodesManage
{
public:
	CNodesManage();
	~CNodesManage();
	CNodesManage(const CNodesManage& p) = delete;
	CNodesManage& operator=(const CNodesManage& p) = delete;
public:
	/*所有支持的基本类型*/
	struct VALUE {
		float float_value;
		char char_value;
		double double_value;
		long long LONG64_value;
		string string_value;
	};

	struct NODE {
		NODE() { father = nullptr; }
		NODE* father;
		string type;
		VALUE node_value;
		list<NODE*> child_list;
	};

	/*
	为当前节点添加子节点
	auto处理父节点
	*/
	//返回当前节点的父节点
	void BackFatherNode();
	//为当前节点添加子节点
	void AddChildNode(NODE*);
	//为当前节点的父节点
	NODE* GetFatherNode();
	/*
	start = nullptr代表从Head开始
	*/
	NODE* GetAllDataCopy(CNodesManage::NODE* start = nullptr);


private:
	//释放节点内存
	bool callBackFreeTheNode(NODE*);
	//复制
	bool callBackCopy(NODE*);
	void callBackCopyNodeBackNotify();
	//总
	NODE* CopyHeadNode;
	//当前
	NODE* CopyNowNode;
	
private:
	/*
		return
		false: 结束处理,已经完成工作,不需要继续了
		true:  继续处理
		NODE* 指向正在浏览的节点
		STATUS: 0: 正在返回父节点
				Other: 正在进入子节点
	*/
	typedef bool(CNodesManage::*CALLBACK_EXPLORER)(NODE*);
	/*
	往上返回一层的时候会被调用,通知:本层无新节点，即将进入上一层节点
	*/
	typedef void(CNodesManage::*CALLBACK_EXPLORER_BACK)();
	
	//多叉树是没有中序遍历的
	/*
	先序遍历
	true 继续处理,false 结束处理
	*/
	bool ExplorerNodesPreviousOrder(CALLBACK_EXPLORER call, CALLBACK_EXPLORER_BACK back, NODE* start);
	/*
	后序遍历
	true 继续处理,false 结束处理
	*/
	bool ExplorerNodesPostOrder(CALLBACK_EXPLORER call, CALLBACK_EXPLORER_BACK back, NODE* start);


private:
	NODE* m_now_Node;//指向当前节点

	const NODE* m_Node_Head;

};
