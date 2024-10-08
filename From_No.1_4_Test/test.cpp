#include "pch.h"

#include "LinkedList.h"

//�����e�X�g�R�[�h
namespace ex01_DataStructure
{
	namespace chapter2
	{
		/**********************************************************************************//**
			@brief		�v�f�������Ȃ����X�g�Ƀ\�[�g�����s�����Ƃ��̃e�X�g
			@details	ID:���X�g-0\n
						�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
						�v�f�������Ȃ����X�g�Ƀ\�[�g�����s�������̋������m�F���Ă��܂��B\n
						�G���[�܂߂ĉ����N����Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckNullListSort) {
			LinkedList<DATA> list;
			//list.Sort(list, [](const DATA& a, const DATA& b) {return a.Score < b.Score; });
			//EXPECT_EQ(false, list.Sort(list, INT_KEY, true));
			EXPECT_EQ(false, list.Sort(list, [](DATA a, DATA b) {return a.Score > b.Score; }));

		}

		/**********************************************************************************//**
			@brief		�v�f������������X�g�Ƀ\�[�g�����s�����Ƃ��̃e�X�g
			@details	ID:���X�g-1\n
						�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
						�v�f��1���������X�g�Ƀ\�[�g�����s�������̋������m�F���Ă��܂��B\n
						�G���[�܂߂ĉ����N����Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckListSortWhen1Data) {
			LinkedList<DATA> list;
			list.Insert(list.GetBegin(), { 10,"Test" });
			//EXPECT_EQ(false, list.Sort(list, std::function( list.GetBegin() > it), true));
			EXPECT_EQ(false, list.Sort(list, [](DATA a, DATA b) {return a.Score > b.Score; }));

		}

		/**********************************************************************************//**
			@brief		��ȏ�v�f�������X�g�Ƀ\�[�g�����s�����Ƃ��̃e�X�g
			@details	ID:���X�g-2\n
						�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
						2�ȏ�v�f�������X�g�Ƀ\�[�g�����s�������̋������m�F���Ă��܂��B\n
						�v�f���w�肵�����ɕ��ׂΐ����ł��B\n
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
			@brief		�����L�[�����v�f�����郊�X�g�Ƀ\�[�g�����s�����Ƃ��̃e�X�g
			@details	ID:���X�g-3\n
						�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
						�����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������̋������m�F���Ă��܂��B\n
						�v�f���\�[�g����ĕ��Ԃ������v�f�̏����͕ۏ؂���Ȃ���ΐ����ł��B\n
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
			@brief		����ς݃��X�g�Ƀ\�[�g�����s�����Ƃ��̃e�X�g
			@details	ID:���X�g-4\n
						�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
						����ς݃��X�g�Ƀ\�[�g�����s�������̋������m�F���Ă��܂��B\n
						�����L�[�̗v�f�̊ԈȊO�̏��Ԃ��ϓ����Ȃ���ΐ����ł��B\n
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
			@brief		��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�����Ƃ��̃e�X�g
			@details	ID:���X�g-5\n
						�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
						��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋������m�F���Ă��܂��B \n
						�v�f���\�[�g����ĕ��ׂΐ����ł��B\n
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
			@brief		�L�[�w������Ȃ�����(nullptr��n����)�Ƃ��̃e�X�g
			@details	ID:���X�g6\n
						�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
						�L�[�w������Ȃ�����(nullptr��n����)���̋������m�F���Ă��܂��B\n
						�G���[�܂߂ĉ����N����Ȃ���ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckListSortWhenNullKey) {
			LinkedList<DATA> list;
			list.Insert(list.GetEnd(), { 30,"Test3" });
			list.Insert(list.GetEnd(), { 10,"Test1" });
			EXPECT_EQ(false, list.Sort(list, nullptr));
		}
	}
}