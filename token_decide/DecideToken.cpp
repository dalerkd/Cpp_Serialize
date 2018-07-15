#include "stdafx.h"
#include "DecideToken.h"


CDecideToken::CDecideToken()
{
}


CDecideToken::~CDecideToken()
{
}

void CDecideToken::StartDecideToken()
{
	//Ҫ��ӡGet�к�,�ַ�,�Լ���ǰtoken����Ϣ;
	try
	{
		DecideGlobal();
	}
	catch (EXCEP& e)
	{
		LogTips("����һ������:%s,��������:��%d��,��%d���ַ�,%d", e.what(), GetLineNumberNow(), GetColumnsNow());
	}

}

void CDecideToken::DecideGlobal()
{
	st_token_value value;
	while (true)
	{
		string typeName = GetToken(value);

		switch (hash_(typeName.c_str()))
		{
		case "identifier"_hash://��ʶ��
		{/*int a*/
			DecideCreateNewType();
		}
		case "keyWord"_hash:
		{
			switch (hash_(value.identifier.c_str()))
			{
			case ";"_hash:
			{
				break;
			}
			case "KW_NEW_LINE"_hash://����
			{
				break;
			}
			case "struct"_hash:
			{
				DecideStruct();
				break;
			}
			default:
				break;
			}
			break;
		}
		default:
		{
			LogError("δ�����token����:%s", typeName.c_str());
			break;
		}
		}
	}


}
/*
struct iter
*/
void CDecideToken::DecideStruct()
{

}

void CDecideToken::DecideSingleLineComments()
{
	throw("");
}

void CDecideToken::DecideMultiLineComments()
{
	throw("");
}
