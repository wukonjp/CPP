// ConsoleApplication1.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <vector>
#include <map>
#include "header.h"

#if _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include "ConsoleApplication1.h"
#define new                new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define calloc(c, s)       _calloc_dbg(c, s, _NORMAL_BLOCK, __FILE__, __LINE__)
#define _expand(p, s)      _expand_dbg(p, s, _NORMAL_BLOCK, __FILE__, __LINE__)
#define free(p)            _free_dbg(p, _NORMAL_BLOCK)
#define malloc(s)          _malloc_dbg(s, _NORMAL_BLOCK, __FILE__, __LINE__)
#define _msize(p)          _msize_dbg(p, _NORMAL_BLOCK)
#define realloc(p, s)      _realloc_dbg(p, s, _NORMAL_BLOCK, __FILE__, __LINE__)
#define _recalloc(p, c, s) _recalloc_dbg(p, c, s, _NORMAL_BLOCK, __FILE__, __LINE__)
#endif


void NewFunction1_1()
{
	auto ptr = new C;
	std::cout << "x + y = " << ptr->Get() << std::endl;

	// 手動破棄が必要
	delete ptr;
}

void NewFunction1_2()
{
	auto ptr = std::make_unique<C>();
	std::cout << "x + y = " << ptr->Get() << std::endl;
}

void NewFunction1_3()
{
	auto ptr = std::make_shared<C>();
	std::cout << "x + y = " << ptr->Get() << std::endl;

	// コピー可（シャローコピー）
	auto ptr2 = ptr;
}

void NewFunction2_1()
{
	auto list = std::vector<C*>();
	list.push_back(new C);
	list.push_back(new C);
	list.push_back(new C);

	// 全コピー可（シャローコピー）
	auto list2 = list;

	// 部分コピー可（シャローコピー）
	auto list3 = std::vector<C*>(list2.size());
	std::copy(list2.begin(), list2.end(), list3.begin());

	// 手動破棄が必要
	for (auto item : list)
	{
		delete item;
	}
}

void NewFunction2_2()
{
	auto list = std::vector<std::unique_ptr<C>>();
	list.push_back(std::make_unique<C>());
	list.push_back(std::make_unique<C>());
	list.push_back(std::make_unique<C>());
}

void NewFunction2_3()
{
	auto list = std::vector<std::shared_ptr<C>>();
	list.push_back(std::make_shared<C>());
	list.push_back(std::make_shared<C>());
	list.push_back(std::make_shared<C>());

	// 全コピー可（シャローコピー）
	auto list2 = list;

	// 部分コピー可（シャローコピー）
	auto list3 = std::vector<std::shared_ptr<C>>(list2.size());
	std::copy(list2.begin(), list2.end(), list3.begin());
}

void NewFunction3_1()
{
	auto map = std::map<char, C*>();
	map.insert(std::make_pair('a', new C));
	map.insert(std::make_pair('b', new C));
	map.insert(std::make_pair('c', new C));

	// 全コピー可（シャローコピー）
	auto map2 = map;

	// 手動破棄が必要
	for (auto item : map)
	{
		delete item.second;
	}
}

void NewFunction3_2()
{
	auto map = std::map<char, std::unique_ptr<C>>();
	map.insert(std::make_pair('a', std::make_unique<C>()));
	map.insert(std::make_pair('b', std::make_unique<C>()));
	map.insert(std::make_pair('c', std::make_unique<C>()));
}

void NewFunction3_3()
{
	auto map = std::map<char, std::shared_ptr<C>>();
	map.insert(std::make_pair('a', std::make_shared<C>()));
	map.insert(std::make_pair('b', std::make_shared<C>()));
	map.insert(std::make_pair('c', std::make_shared<C>()));

	// 全コピー可（シャローコピー）
	auto map2 = map;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	NewFunction1_1();
	NewFunction1_2();
	NewFunction1_3();

	NewFunction2_1();
	NewFunction2_2();
	NewFunction2_3();

	NewFunction3_1();
	NewFunction3_2();
	NewFunction3_3();
}
