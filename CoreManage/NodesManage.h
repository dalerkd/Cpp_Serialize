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
public:
	/*所有支持的基本类型*/
	struct VALUE {
		float float_value;
		char char_value;
		double double_value;
		long long LONG64_value;
		string string_value;
	};

	struct NODE {NODE() { father == nullptr; }
		NODE* father ;
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
private:
	NODE* now_Node;//指向当前节点

	const NODE* m_Node_Head;

};

