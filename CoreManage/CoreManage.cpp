// CoreManage.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "NodesManage.h"
#include "SymbolsManage.h"

using std::cout;
bool g_OPEN_LOG = true;

int main()
{
	CNodesManage* pNM = new CNodesManage();
	CSymbolsManage* pSM = new CSymbolsManage();

	

	pSM->SetNewType("firstStruct", pNM, nullptr);
	/*
	struct b{
	int b;
	}
	*/
	pNM->SetNodeType("struct");
	pNM->SetNodeName("firstStruct");
	CNodesManage::NODE* pTemp = new CNodesManage::NODE();
	pTemp->name = "ok";
	pTemp->type = "struct";
	pNM->AddChildNode(pTemp);


	return 0;
}

