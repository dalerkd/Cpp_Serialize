========================================================================
    控制台应用程序：token_decide 项目概述
========================================================================

##好的token处理
- 将token选择和字符串分析分离
GetToken
BackLastToken


- 提供回退接口,回退由字符串分析控制
- 错误异常处理就好

class TokenAna{
private:
	long long m_nowOffset;
	void* m_pDataBase;	
	long long m_length_limit;
public:
	string GetToken();
	//跳过本行后面的内容,直接从下行开始获取Token
	string GetNextLine();
	//向后搜索字符串,找到其后面
	string GetString(string word);
	//返回上次token之前
	BackLastToken();
}

/*
TOKEN:
- //注释
- /* */注释
- struct 结构体
- {
- }
- ;
- <  //数组？map<>
- >  //数组？vector<>
- 标志符
- 换行
- [ 有限数组
- ] 有限数组
- # 开头,预处理命令
*/
初始化:
struct int{};
struct float{};
struct good{float a;int b;};
