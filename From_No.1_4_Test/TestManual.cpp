#include "pch.h"

//--------------------------------------------------------------------------------
// �t�@�C���ˑ��֌W
//--------------------------------------------------------------------------------
// GoogleTest�̃w�b�_�B�E�B�U�[�h�ɂĕʂ̃t�@�C���ɋL�q����Ă���ꍇ�́A�s�v�ł��B
#include <gtest/gtest.h>

// ��B�����̃v���W�F�N�g�ɂ������w�b�_�t�@�C����include���Ă��������B
#include "LinkedList.h"

#include "TestManual.h"

namespace ex01_DataStructure
{
	namespace chapter2
	{
		//--------------------------------------------------------------------------------
		// �R���p�C���֘A�蓮�e�X�g
		//--------------------------------------------------------------------------------
		/**********************************************************************************//**
		@brief		�^�Ȃǂ��s�K�؂ȃL�[�w�肪�����œn���ꂽ�Ƃ��̃e�X�g
		@details	ID:���X�g-7\n
					�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
					�^�Ȃǂ��s�K�؂ȃL�[�w�肪�����œn���ꂽ�Ƃ��̖߂�l���m�F���Ă��܂��B\n
					�R���p�C���G���[�ƂȂ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckMissKey) {
#if defined TT_TEST_NULL_KEY
			LinkedList<DATA> list;
			list.Sort(list, [](DATA* a, DATA* b) {return a->Score > b->Name; });	//�G���[
#endif //TT_TEST_NULL_KEY
			SUCCEED();
		}

		/**********************************************************************************//**
		@brief		��const�̃��\�b�h�ł��邩�̃e�X�g
		@details	ID:���X�g-8\n
					�N�C�b�N�\�[�g�̃e�X�g�ł��B\n
					const�̃��X�g����Ăяo���āA�R���p�C���G���[�ƂȂ邩���m�F���Ă��܂��B\n
					�R���p�C���G���[�ƂȂ�ΐ����ł��B\n
		*//***********************************************************************************/
		TEST(QuickSortTest, TestCheckConstList) {
#if defined TT_TEST_NULL_KEY
			const LinkedList<DATA> list;
			list.Sort(list, [](DATA* a, DATA* b) {return a->Score > b->Score; });	//�G���[
#endif //TT_TEST_NULL_KEY
			SUCCEED();
		}


	}	// chapter2
}	//	ex01_DataStructure
