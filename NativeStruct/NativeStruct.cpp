// NativeStruct.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

// アラインメント
// 構造体メンバの中で最も大きいアラインメントが適用される
// ・メンバが配列の場合は単一要素のアラインメントを適用する(ex. char[5] は 1バイト)
// ・メンバが構造体の場合はその構造体のアラインメントを適用する

struct K0               // alignment=4, size=8
{
    int         a4;     // alignment=4, offset= 0, size=4
    char        a1;     // alignment=1, offset= 4, size=1+3
};
struct S0               // alignment=4, size=24
{
    char        a1;     // alignment=1, offset= 0, size=1+3
    K0          kk;     // alignment=4, offset= 4, size=8
    char        b3[3];  // alignment=1, offset=12, size=3+1
    short       a2;     // alignment=2, offset=16, size=2
    char        b5[5];  // alignment=1, offset=18, size=5+1
};

void alignment()
{
    {
        printf("アラインメント確認\n");
        auto k = K0();
        auto s = S0();
        printf("K0: size=%2d, align=%2d\n", (int)sizeof(K0), (int)alignof(K0));
        printf("- a4: offset=%2d, size=%2d\n", (int)((char*)&k.a4 - (char*)&k), (int)sizeof(k.a4));
        printf("- a1: offset=%2d, size=%2d\n", (int)((char*)&k.a1 - (char*)&k), (int)sizeof(k.a1));
        printf("S0: size=%2d, align=%2d\n", (int)sizeof(S0), (int)alignof(S0));
        printf("- a1: offset=%2d, size=%2d\n", (int)((char*)&s.a1 - (char*)&s), (int)sizeof(s.a1));
        printf("- kk: offset=%2d, size=%2d\n", (int)((char*)&s.kk - (char*)&s), (int)sizeof(s.kk));
        printf("- b1: offset=%2d, size=%2d\n", (int)((char*)&s.b3 - (char*)&s), (int)sizeof(s.b3));
        printf("- a2: offset=%2d, size=%2d\n", (int)((char*)&s.a2 - (char*)&s), (int)sizeof(s.a2));
        printf("- b5: offset=%2d, size=%2d\n", (int)((char*)&s.b5 - (char*)&s), (int)sizeof(s.b5));
        printf("\n");
    }
}

// パッキング
// コンパイラでパッキングサイズを指定するとアラインメントの上限を抑制できる
// ・パッキングサイズ既定値はx86で8、x64で16
// ・既定値で抑制される8バイトを超える基本型はほとんどない

#pragma pack(1)
struct K1
{
    char        a1;
    long long   a8;
};
struct S1
{
    K1          kk;
    short       a2;
    int         a4;
    char        b5[5];
};

#pragma pack(2)
struct K2
{
    char        a1;
    long long   a8;
};
struct S2
{
    K2          kk;
    short       a2;
    int         a4;
    char        b5[5];
};

#pragma pack(4)
struct K4
{
    char        a1;
    long long   a8;
};
struct S4
{
    K4          kk;
    short       a2;
    int         a4;
    char        b5[5];
};

#pragma pack(8)
struct K8
{
    char        a1;
    long long   a8;
};
struct S8
{
    K8          kk;
    short       a2;
    int         a4;
    char        b5[5];
};

#pragma pack(16)
struct K16
{
    char        a1;
    long long   a8;
};
struct S16
{
    K16         kk;
    short       a2;
    int         a4;
    char        b5[5];
};

#pragma pack()

void packing()
{
    {
        printf("パッキング=1　パディングが発生しない\n");
        auto s = S1();
        printf("K1: size=%2d, align=%2d\n", (int)sizeof(K1), (int)alignof(K1));
        printf("S1: size=%2d, align=%2d\n", (int)sizeof(S1), (int)alignof(S1));
        printf("- kk: offset=%2d, size=%2d\n", (int)((char*)&s.kk - (char*)&s), (int)sizeof(s.kk));
        printf("- a2: offset=%2d, size=%2d\n", (int)((char*)&s.a2 - (char*)&s), (int)sizeof(s.a2));
        printf("- a4: offset=%2d, size=%2d\n", (int)((char*)&s.a4 - (char*)&s), (int)sizeof(s.a4));
        printf("- b5: offset=%2d, size=%2d\n", (int)((char*)&s.b5 - (char*)&s), (int)sizeof(s.b5));
        printf("\n");
    }

    {
        printf("パッキング=2\n");
        auto s = S2();
        printf("K2: size=%2d, align=%2d\n", (int)sizeof(K2), (int)alignof(K2));
        printf("S2: size=%2d, align=%2d\n", (int)sizeof(S2), (int)alignof(S2));
        printf("- kk: offset=%2d, size=%2d\n", (int)((char*)&s.kk - (char*)&s), (int)sizeof(s.kk));
        printf("- a2: offset=%2d, size=%2d\n", (int)((char*)&s.a2 - (char*)&s), (int)sizeof(s.a2));
        printf("- a4: offset=%2d, size=%2d\n", (int)((char*)&s.a4 - (char*)&s), (int)sizeof(s.a4));
        printf("- b5: offset=%2d, size=%2d\n", (int)((char*)&s.b5 - (char*)&s), (int)sizeof(s.b5));
        printf("\n");
    }

    {
        printf("パッキング=4\n");
        auto s = S4();
        printf("K4: size=%2d, align=%2d\n", (int)sizeof(K4), (int)alignof(K4));
        printf("S4: size=%2d, align=%2d\n", (int)sizeof(S4), (int)alignof(S4));
        printf("- kk: offset=%2d, size=%2d\n", (int)((char*)&s.kk - (char*)&s), (int)sizeof(s.kk));
        printf("- a2: offset=%2d, size=%2d\n", (int)((char*)&s.a2 - (char*)&s), (int)sizeof(s.a2));
        printf("- a4: offset=%2d, size=%2d\n", (int)((char*)&s.a4 - (char*)&s), (int)sizeof(s.a4));
        printf("- b5: offset=%2d, size=%2d\n", (int)((char*)&s.b5 - (char*)&s), (int)sizeof(s.b5));
        printf("\n");
    }

    {
        printf("パッキング=8（x86標準）　アラインメントが8を超える基本型がないため効果なし\n");
        auto s = S8();
        printf("K8: size=%2d, align=%2d\n", (int)sizeof(K8), (int)alignof(K8));
        printf("S8: size=%2d, align=%2d\n", (int)sizeof(S8), (int)alignof(S8));
        printf("- kk: offset=%2d, size=%2d\n", (int)((char*)&s.kk - (char*)&s), (int)sizeof(s.kk));
        printf("- a2: offset=%2d, size=%2d\n", (int)((char*)&s.a2 - (char*)&s), (int)sizeof(s.a2));
        printf("- a4: offset=%2d, size=%2d\n", (int)((char*)&s.a4 - (char*)&s), (int)sizeof(s.a4));
        printf("- b5: offset=%2d, size=%2d\n", (int)((char*)&s.b5 - (char*)&s), (int)sizeof(s.b5));
        printf("\n");
    }

    {
        printf("パッキング=16（x64標準）　アラインメントが8を超える基本型がないため効果なし\n");
        auto s = S16();
        printf("K16: size=%2d, align=%2d\n", (int)sizeof(K16), (int)alignof(K16));
        printf("S16: size=%2d, align=%2d\n", (int)sizeof(S16), (int)alignof(S16));
        printf("- kk: offset=%2d, size=%2d\n", (int)((char*)&s.kk - (char*)&s), (int)sizeof(s.kk));
        printf("- a2: offset=%2d, size=%2d\n", (int)((char*)&s.a2 - (char*)&s), (int)sizeof(s.a2));
        printf("- a4: offset=%2d, size=%2d\n", (int)((char*)&s.a4 - (char*)&s), (int)sizeof(s.a4));
        printf("- b5: offset=%2d, size=%2d\n", (int)((char*)&s.b5 - (char*)&s), (int)sizeof(s.b5));
        printf("\n");
    }
}

// エントリポイント
int main()
{
    alignment();
    packing();
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
