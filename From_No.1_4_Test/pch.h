//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <string>

/**
 *�f�[�^������\���̂ł��B
 *
 * @param Score �X�R�A
 * @param Name  ���O
 */
struct DATA
{
    int Score = 0;
    std::string Name = "NULL";
};

/**
*�\�[�g���̃L�[�����߂�t���O�ł�
*
* @param INT_KEY       int�^�Ń\�[�g
* @param STRING_KEY    string�^�Ń\�[�g
*/
enum SORT_KEY
{
    INT_KEY,
    STRING_KEY,
};
