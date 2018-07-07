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
	void AddChildNode(NODE*);
	NODE* GetFatherNode();
	NODE* GetAllDataCopy();

	/*
		return
		false: 结束处理,已经完成工作,不需要继续了
		true:  继续处理
	*/
	typedef bool(CNodesManage::*CALLBACK_EXPLORER)(NODE*);
	//true 继续处理,false 结束处理
	bool ExplorerNodes(CALLBACK_EXPLORER call, NODE* start);
private:
	//释放节点内存
	bool callBackFreeTheNode(NODE*);
	//复制
	bool callBackCopy(NODE*);

private:
	NODE* m_now_Node;//指向当前节点

	const NODE* m_Node_Head;

};
