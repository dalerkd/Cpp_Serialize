#pragma once
#include <string>
#include <list>
using std::string;
using std::list;

/*
�������ռ���ͷ�
*/
class CNodesManage
{
public:
	CNodesManage();
	~CNodesManage();
public:
	/*����֧�ֵĻ�������*/
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
	Ϊ��ǰ�ڵ�����ӽڵ�
	auto�����ڵ�
	*/
	void AddChildNode(NODE*);
	NODE* GetFatherNode();
private:
	NODE* now_Node;//ָ��ǰ�ڵ�

	const NODE* m_Node_Head;

};

