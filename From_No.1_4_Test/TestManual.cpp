#include "pch.h"

//--------------------------------------------------------------------------------
// ファイル依存関係
//--------------------------------------------------------------------------------
// GoogleTestのヘッダ。ウィザードにて別のファイルに記述されている場合は、不要です。
#include <gtest/gtest.h>

// 例。自分のプロジェクトにあったヘッダファイルをincludeしてください。
#include "LinkedList.h"

#include "TestManual.h"

namespace ex01_DataStructure
{
	namespace chapter2
	{
		//--------------------------------------------------------------------------------
		// コンパイル関連手動テスト
		//--------------------------------------------------------------------------------
		/**********************************************************************************//**
		@brief		型などが不適切なキー指定が引数で渡されたときのテスト
		@details	ID:リスト-7\n
					クイックソートのテストです。\n
					型などが不適切なキー指定が引数で渡されたときの戻り値を確認しています。\n
					コンパイルエラーとなれば成功です。\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckMissKey) {
#if defined TT_TEST_NULL_KEY
			LinkedList<DATA> list;
			list.Sort(list, [](DATA* a, DATA* b) {return a->Score > b->Name; });	//エラー
#endif //TT_TEST_NULL_KEY
			SUCCEED();
		}

		/**********************************************************************************//**
		@brief		非constのメソッドであるかのテスト
		@details	ID:リスト-8\n
					クイックソートのテストです。\n
					constのリストから呼び出して、コンパイルエラーとなるかを確認しています。\n
					コンパイルエラーとなれば成功です。\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckConstList) {
#if defined TT_TEST_NULL_KEY
			const LinkedList<DATA> list;
			list.Sort(list, [](DATA* a, DATA* b) {return a->Score > b->Score; });	//エラー
#endif //TT_TEST_NULL_KEY
			SUCCEED();
		}


	}	// chapter2
}	//	ex01_DataStructure
