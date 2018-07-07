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
	CNodesManage(const CNodesManage& p) = delete;
	CNodesManage& operator=(const CNodesManage& p) = delete;
public:
	/*����֧�ֵĻ�������*/
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
	Ϊ��ǰ�ڵ�����ӽڵ�
	auto�����ڵ�
	*/
	void AddChildNode(NODE*);
	NODE* GetFatherNode();
	NODE* GetAllDataCopy();

	/*
		return
		false: ��������,�Ѿ���ɹ���,����Ҫ������
		true:  ��������
	*/
	typedef bool(CNodesManage::*CALLBACK_EXPLORER)(NODE*);
	//true ��������,false ��������
	bool ExplorerNodes(CALLBACK_EXPLORER call, NODE* start);
private:
	//�ͷŽڵ��ڴ�
	bool callBackFreeTheNode(NODE*);
	//����
	bool callBackCopy(NODE*);

private:
	NODE* m_now_Node;//ָ��ǰ�ڵ�

	const NODE* m_Node_Head;

};
