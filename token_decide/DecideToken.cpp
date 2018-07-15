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
	//要打印Get行号,字符,以及当前token等信息;
	try
	{
		DecideGlobal();
	}
	catch (EXCEP& e)
	{
		LogTips("发现一个错误:%s,错误发生在:第%d行,第%d个字符,%d", e.what(), GetLineNumberNow(), GetColumnsNow());
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
		case "identifier"_hash://标识符
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
			case "KW_NEW_LINE"_hash://换行
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
			LogError("未处理的token类型:%s", typeName.c_str());
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
