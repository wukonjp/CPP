// MemoryAlloc.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

struct SubData
{
	int x;
	int y;
};

struct MainData
{
	SubData sub1{};			// デフォルトコンストラクタが自動生成され、ゼロ初期化される
	SubData sub2;

	// デフォルトコンストラクタ
	// ひとつでもコンストラクタを定義した場合は全メンバを初期化する義務が生じる。
	MainData()
		// : sub2{}
	{
		// sub2の初期化漏れ
	}

	// 通常コンストラクタ
	MainData(int c)
	{
		this->sub1.x = c;
		this->sub1.y = c;
		this->sub2.x = c;
		this->sub2.y = c;
	}

	// コピーコンストラクタ
	MainData(const MainData& src)
	{
		this->sub1 = src.sub1;
		this->sub2 = src.sub2;
	}

	// 代入演算子
	MainData& operator=(const MainData& src)
	{
		this->sub1 = src.sub1;
		this->sub2 = src.sub2;
		return *this;
	}
};

void print(const MainData& data)
{
	std::cout << "sub1.x " << data.sub1.x << std::endl;
	std::cout << "sub1.y " << data.sub1.y << std::endl;
	std::cout << "sub2.x " << data.sub2.x << std::endl;
	std::cout << "sub2.y " << data.sub2.y << std::endl;
}

int main()
{
	{
		std::cout << "ヒープ生成（初期化子なし）" << std::endl;
		auto p = new MainData;
		print(*p);
		delete p;
	}

	{
		std::cout << "ヒープ生成（デフォルトコンストラクタ）" << std::endl;
		auto p = new MainData();
		print(*p);
		delete p;
	}

	{
		std::cout << "ヒープ生成（デフォルトコンストラクタ ＋ 初期化リスト）" << std::endl;
		auto p = new MainData{};
		print(*p);
		delete p;
	}

	{// コンパイルエラー
		//std::cout << "スタック生成（初期化なし）" << std::endl;
		//auto d = MainData;
		//print(d);
	}

	{
		std::cout << "スタック生成（デフォルトコンストラクタ）" << std::endl;
		auto d = MainData();		// デフォルトコンストラクタ
		print(d);
	}

	{
		std::cout << "スタック生成（通常コンストラクタ + 代入）" << std::endl;
		MainData z = MainData(3);	// 通常コンストラクタ
		print(z);
	}

	{
		std::cout << "スタック生成（通常コンストラクタ）" << std::endl;
		MainData t(3);				// 通常コンストラクタ
		print(t);
	}

	{
		std::cout << "スタック生成（コピーコンストラクタ）" << std::endl;
		auto d = MainData();		// デフォルトコンストラクタ
		MainData e = MainData(d);	// コピーコンストラクタ
		print(e);
	}

	{
		std::cout << "スタック生成（初期化なし, 初期化リスト）" << std::endl;
		auto d = MainData();		// デフォルトコンストラクタ
		MainData g;					// デフォルトコンストラクタ
		g = d;						// 代入演算子
		print(g);
	}

	{
		std::cout << "スタック生成（コンストラクタ未定義構造体の初期化）" << std::endl;
//		SubData s1;
		SubData s2 = {};
		MainData q;
//		q.sub1 = s1;	// ビルドエラー
		q.sub2 = s2;
		print(q);
	}

	{
		std::cout << "スタック生成（デフォルトコンストラクタ ＋ 初期化リスト）" << std::endl;
		auto d = MainData{};
		print(d);
	}

	{
		std::cout << "スタック生成（初期化子なし）" << std::endl;
		MainData d;
		print(d);
	}

	{// コンパイルエラー
		//std::cout << "スタック生成（デフォルトコンストラクタ）" << std::endl;
		//MainData d();
		//print(d);
	}

	{
		std::cout << "スタック生成（デフォルトコンストラクタ ＋ 初期化リスト）" << std::endl;
		MainData d{};
		print(d);
	}
}

