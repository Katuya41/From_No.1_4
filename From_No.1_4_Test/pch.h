//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <string>

/**
 *データを入れる構造体です。
 *
 * @param Score スコア
 * @param Name  名前
 */
struct DATA
{
    int Score = 0;
    std::string Name = "NULL";
};

/**
*ソート時のキーを決めるフラグです
*
* @param INT_KEY       int型でソート
* @param STRING_KEY    string型でソート
*/
enum SORT_KEY
{
    INT_KEY,
    STRING_KEY,
};
