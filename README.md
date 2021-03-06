# Cpp_Serialize

通过对头文件进行分析构建中间结构，支持广泛的序列化和反序列化代码的自动生成。
最终将提供将任意数据结构序列化成JSON和反序列化的例子.

## 工具设计:

根据头文件给出的数据结构:生成负责序列化和反序列化的C++代码.

是一种代码翻译器:
`ana.exe b.h -o result.cpp -of json`


## 谈谈其他

一般我们生成序列化代码是通过:
- Google Protocol Buffers（protobuf）
不支持C++容器
- Boost.Serialization
编译相当坑

为了减少其他依赖,看来只能自力更生了.
```
数据结构->JSON:1.5小时
JSON->数据结构:1小时
```
在经历以上努力后,在想:
有没有什么办法能解决普通数据结构的序列化呢？

转换工作是可以自动化的,一个比较合理的方法是自动生成转换代码,再编译之.
所以本项目应运而生.
## 工具设计:

根据头文件给出的数据结构:生成负责序列化和反序列化的C++代码.


## 原理

数据结构(头文件)->提取中间信息->生成能动态处理数据的代码(cpp文件)
生成部分可以支持多种序列化方式.

## 工作进度
- 前端
	- [ ] token分析
- 中间层
	- [x] 符号表管理
	- [x] 中间树管理
- 后端
	- [ ] 翻译成JSON处理代码


