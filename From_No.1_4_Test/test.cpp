#include "pch.h"

#include "LinkedList.h"

//自動テストコード
namespace ex01_DataStructure
{
	namespace chapter2
	{
		/**********************************************************************************//**
			@brief		要素を持たないリストにソートを実行したときのテスト
			@details	ID:リスト-0\n
						クイックソートのテストです。\n
						要素を持たないリストにソートを実行した時の挙動を確認しています。\n
						エラー含めて何も起こらなければ成功です。\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckNullListSort) {
			LinkedList<DATA> list;
			//list.Sort(list, [](const DATA& a, const DATA& b) {return a.Score < b.Score; });
			//EXPECT_EQ(false, list.Sort(list, INT_KEY, true));
			EXPECT_EQ(false, list.Sort(list, [](DATA a, DATA b) {return a.Score > b.Score; }));

		}

		/**********************************************************************************//**
			@brief		要素を一つだけ持つリストにソートを実行したときのテスト
			@details	ID:リスト-1\n
						クイックソートのテストです。\n
						要素を1つだけ持つリストにソートを実行した時の挙動を確認しています。\n
						エラー含めて何も起こらなければ成功です。\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckListSortWhen1Data) {
			LinkedList<DATA> list;
			list.Insert(list.GetBegin(), { 10,"Test" });
			//EXPECT_EQ(false, list.Sort(list, std::function( list.GetBegin() > it), true));
			EXPECT_EQ(false, list.Sort(list, [](DATA a, DATA b) {return a.Score > b.Score; }));

		}

		/**********************************************************************************//**
			@brief		二つ以上要素を持つリストにソートを実行したときのテスト
			@details	ID:リスト-2\n
						クイックソートのテストです。\n
						2つ以上要素を持つリストにソートを実行した時の挙動を確認しています。\n
						要素が指定した順に並べば成功です。\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckListSort) {
			LinkedList<DATA> list;
			list.Insert(list.GetBegin(), { 20,"aaa" });
			list.Insert(list.GetBegin(), { 30,"bbb" });
			list.Insert(list.GetBegin(), { 10,"ccc" });
			//list.Sort(list, INT_KEY,true);
			list.Sort(list, [](DATA a, DATA b) {return a.Score > b.Score; });
			LinkedList<DATA>::Iterator it = list.GetBegin();
			DATA Data;
			Data.Name = "ccc";
			Data.Score = 10;
			EXPECT_EQ(Data.Score, (*it).Score);
			EXPECT_EQ(Data.Name, (*it).Name);
			//EXPECT_EQ(Data, (*it));
			it++;
			Data.Name = "aaa";
			Data.Score = 20;
			EXPECT_EQ(Data.Score, (*it).Score);
			EXPECT_EQ(Data.Name, (*it).Name);
			//EXPECT_EQ(Data, (*it));
			it++;
			Data.Name = "bbb";
			Data.Score = 30;
			EXPECT_EQ(Data.Score, (*it).Score);
			EXPECT_EQ(Data.Name, (*it).Name);
			//EXPECT_EQ(Data, (*it));

		}

		/**********************************************************************************//**
			@brief		同じキーを持つ要素があるリストにソートを実行したときのテスト
			@details	ID:リスト-3\n
						クイックソートのテストです。\n
						同じキーを持つ要素があるリストで、そのキーを指定しソートを実行した時の挙動を確認しています。\n
						要素がソートされて並ぶか同じ要素の順序は保証されなければ成功です。\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckListSortWhenCorrectedData) {
			LinkedList<DATA> list;
			list.Insert(list.GetBegin(), { 10,"Test1" });
			list.Insert(list.GetBegin(), { 20,"Test2" });
			list.Insert(list.GetBegin(), { 10,"Test1" });
			//list.Sort(list, INT_KEY, true);
			list.Sort(list, [](DATA a, DATA b) {return a.Score > b.Score; });
			LinkedList<DATA>::Iterator it = list.GetBegin();
			DATA Data;
			Data.Name = "Test1";
			Data.Score = 10;
			EXPECT_EQ(Data.Score, (*it).Score);
			EXPECT_EQ(Data.Name, (*it).Name);
			//EXPECT_EQ(Data, (*it));
			it++;
			EXPECT_EQ(Data.Score, (*it).Score);
			EXPECT_EQ(Data.Name, (*it).Name);
			//EXPECT_EQ(Data, (*it));
			it++;
			Data.Name = "Test2";
			Data.Score = 20;
			EXPECT_EQ(Data.Score, (*it).Score);
			EXPECT_EQ(Data.Name, (*it).Name);
			//EXPECT_EQ(Data, (*it));
		}

		/**********************************************************************************//**
			@brief		整列済みリストにソートを実行したときのテスト
			@details	ID:リスト-4\n
						クイックソートのテストです。\n
						整列済みリストにソートを実行した時の挙動を確認しています。\n
						同じキーの要素の間以外の順番が変動しなければ成功です。\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckListSortWhenSortData) {
			LinkedList<DATA> list;
			list.Insert(list.GetEnd(), { 10,"Test1" });
			list.Insert(list.GetEnd(), { 20,"Test2" });
			list.Insert(list.GetEnd(), { 30,"Test3" });
			//list.Sort(list, INT_KEY, true);
			list.Sort(list, [](DATA a, DATA b) {return a.Score > b.Score; });
			LinkedList<DATA>::Iterator it = list.GetBegin();
			DATA Data;
			Data.Name = "Test1";
			Data.Score = 10;
			EXPECT_EQ(Data.Score, (*it).Score);
			EXPECT_EQ(Data.Name, (*it).Name);
			//EXPECT_EQ(Data, (*it));
			it++;
			Data.Name = "Test2";
			Data.Score = 20;
			EXPECT_EQ(Data.Score, (*it).Score);
			EXPECT_EQ(Data.Name, (*it).Name);
			//EXPECT_EQ(Data, (*it));
			it++;
			Data.Name = "Test3";
			Data.Score = 30;
			EXPECT_EQ(Data.Score, (*it).Score);
			EXPECT_EQ(Data.Name, (*it).Name);
			//EXPECT_EQ(Data, (*it));
		}

		/**********************************************************************************//**
			@brief		一度整列したリストの各所に挿入し、再度ソートを実行したときのテスト
			@details	ID:リスト-5\n
						クイックソートのテストです。\n
						一度整列したリストの各所に挿入し、再度ソートを実行した時の挙動を確認しています。 \n
						要素がソートされて並べば成功です。\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckListSortWhenSortDataInsertBack) {
			LinkedList<DATA> list;
			list.Insert(list.GetEnd(), { 30,"Test3" });
			list.Insert(list.GetEnd(), { 10,"Test1" });
			//list.Sort(list, INT_KEY, true);
			list.Sort(list, [](DATA a, DATA b) {return a.Score > b.Score; });
			list.Insert(list.GetEnd(), { 40,"Test4" });
			LinkedList<DATA>::Iterator it = list.GetBegin();
			DATA Data;
			Data.Name = "Test1";
			Data.Score = 10;
			EXPECT_EQ(Data.Score, (*it).Score);
			EXPECT_EQ(Data.Name, (*it).Name);
			//EXPECT_EQ(Data, (*it));
			it++;
			Data.Name = "Test3";
			Data.Score = 30;
			EXPECT_EQ(Data.Score, (*it).Score);
			EXPECT_EQ(Data.Name, (*it).Name);
			//EXPECT_EQ(Data, (*it));
			it++;
			Data.Name = "Test4";
			Data.Score = 40;
			EXPECT_EQ(Data.Score, (*it).Score);
			EXPECT_EQ(Data.Name, (*it).Name);
			//EXPECT_EQ(Data, (*it));
		}

		/**********************************************************************************//**
			@brief		キー指定をしなかった(nullptrを渡した)ときのテスト
			@details	ID:リスト6\n
						クイックソートのテストです。\n
						キー指定をしなかった(nullptrを渡した)時の挙動を確認しています。\n
						エラー含めて何も起こらなければ成功です。\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckListSortWhenNullKey) {
			LinkedList<DATA> list;
			list.Insert(list.GetEnd(), { 30,"Test3" });
			list.Insert(list.GetEnd(), { 10,"Test1" });
			EXPECT_EQ(false, list.Sort(list, nullptr));
		}
	}
}