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
	//���ص�ǰ�ڵ�ĸ��ڵ�
	void BackFatherNode();
	//Ϊ��ǰ�ڵ�����ӽڵ�
	void AddChildNode(NODE*);
	//Ϊ��ǰ�ڵ�ĸ��ڵ�
	NODE* GetFatherNode();
	/*
	start = nullptr�����Head��ʼ
	*/
	NODE* GetAllDataCopy(CNodesManage::NODE* start = nullptr);


private:
	//�ͷŽڵ��ڴ�
	bool callBackFreeTheNode(NODE*);
	//����
	bool callBackCopy(NODE*);
	void callBackCopyNodeBackNotify();
	//��
	NODE* CopyHeadNode;
	//��ǰ
	NODE* CopyNowNode;
	
private:
	/*
		return
		false: ��������,�Ѿ���ɹ���,����Ҫ������
		true:  ��������
		NODE* ָ����������Ľڵ�
		STATUS: 0: ���ڷ��ظ��ڵ�
				Other: ���ڽ����ӽڵ�
	*/
	typedef bool(CNodesManage::*CALLBACK_EXPLORER)(NODE*);
	/*
	���Ϸ���һ���ʱ��ᱻ����,֪ͨ:�������½ڵ㣬����������һ��ڵ�
	*/
	typedef void(CNodesManage::*CALLBACK_EXPLORER_BACK)();
	
	//�������û�����������
	/*
	�������
	true ��������,false ��������
	*/
	bool ExplorerNodesPreviousOrder(CALLBACK_EXPLORER call, CALLBACK_EXPLORER_BACK back, NODE* start);
	/*
	�������
	true ��������,false ��������
	*/
	bool ExplorerNodesPostOrder(CALLBACK_EXPLORER call, CALLBACK_EXPLORER_BACK back, NODE* start);


private:
	NODE* m_now_Node;//ָ��ǰ�ڵ�

	const NODE* m_Node_Head;

};
