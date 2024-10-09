#pragma once
//#ifndef LINKED_LIST_H
//#define LINKED_LIST_H
//#include <string>

#include <functional>
#include <cassert>

/**
 * これはLinkedListクラスの説明です。
 * このクラスは双方向リストで使用されます。
 *
 * @author 吉村括哉
 * @since 2024-10-02
 */
template <typename T>
class LinkedList
{
public:
    class Iterator;
    class ConstIterator;

private:

    /**
     *ノードを入れる構造体です。
     *
     * @param prev  前のノード
     * @param next  次のノード
     * @param Data  データ
     */
    struct NODE
    {
        NODE* Prev = nullptr;     //一個前のノード
        NODE* Next = nullptr;     //次のノード
        T Data = T();             //データ
    };

    //ダミーノード
    NODE* Dummy;

    //データの数
    int DataNum = 0;

    /*
    * クイックソートを行う関数です
    * @param 最初のノード
    * @param 最後のノード
    * @param 降順か昇順か
    */
    void Sort(NODE* _low, NODE* _high, std::function<bool(T, T)> _compare);

    /*
     * 分割を行う関数です
     * @param 最初のノード
     * @param 最後のノード
     * @param 降順か昇順か
     */
    NODE* Partition(NODE* _low, NODE* _high, std::function<bool(const T&, const T&)> _compare);

    /*
     * 交換を行う関数です
     * @param 交換するデータ1
     * @param 交換するデータ2
     */
    void Swap(T& _data1, T& _data2);

public:
    /**
     * LinkedListクラスのコンストラクタ。
     * 初期化処理を行います。
     */
    LinkedList();
    ~LinkedList();

    /**
     * データ数を返す関数です。
     * 現在のデータ数を返します
     */
    int GetDataNum() const;

    /**
    * コンストイテレータを使用してリストに格納する関数です。
    * @param _it     受け取ったイテレータ
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
    bool Insert(LinkedList<T>::ConstIterator& _it,const T& _data);

    /**
    * コンストイテレータを使用してリストの要素を削除する関数です。
    * @param _it     受け取ったイテレータ
    */
    bool Delete(LinkedList<T>::ConstIterator& _it);

    // ノードをすべて解放するメンバー関数
    void Clear();

    /*
    * 先頭イテレータを取得する関数です。
    * @return 先頭イテレータ
    */
    LinkedList<T>::Iterator GetBegin();

    /*
    * 先頭コンストイテレータを取得する関数です。
    * @return 先頭コンストイテレータ
    */
    LinkedList<T>::ConstIterator GetConstBegin()const;

    /*
    * 末尾イテレータを取得する関数です。
    * @return ダミーノード
    */
    LinkedList<T>::Iterator GetEnd();

    /*
     * 末尾コンストイテレータを取得する関数です。
     * @return ダミーノード
     */
    LinkedList<T>::ConstIterator GetConstEnd();

    /*
    * 範囲forに対応するbegin関数です。
    * @return 先頭イテレータ
    */
    Iterator begin();

    /*
    * 範囲forに対応するend関数です。
    * @return 末尾イテレータ
    */
    Iterator end();

    /*
     * クイックソートを行う関数です
     * @param リスト
     * @param 降順か昇順か(>で昇順 , <で降順)
     */
    bool Sort(std::function<bool(T, T)> _compare);

    /*
    * これはConstIteratorクラスの説明です。
    * このクラスは双方向リストで使用されます。
    *
    * @author 吉村括哉
    * @since 2024-10-02
    */
    class ConstIterator
    {
    private:
        friend class LinkedList;

        bool IsDummy() const;

    protected:
        //ノード
        NODE* Node = nullptr;

    public:
        LinkedList::ConstIterator() {}

        /*
         * ノードが空か調べます
         * @return ノードが空かどうかを返します
        */
        bool IsEmpty();

        //オペレータ
        /*
         * イテレータを末尾に向かって進めるオペレータです(前置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator& operator++();

        /*
         * イテレータを末尾に向かって進めるオペレータです(後置インクリメント)
         * @return 次のノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator operator++(int);

        /*
         * イテレータを先頭に向かって進めるオペレータです(前置インクリメント)
         * @return 前ノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator& operator--();

        /*
         * イテレータを先頭に向かって進めるオペレータです(後置インクリメント)
         * @return 前のノードを取得したイテレータを返します
        */
        LinkedList::ConstIterator operator--(int);

        /*
         * イテレータのさす要素を取得するオペレータ(const)です
         * @return ノードを返します
        */
        const T& operator*() const;
        /*
         * コピ－コンストラクタです
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}

        /*
         * 代入するオペレータです
         *@return コンストイテレータを返します
        */
        LinkedList::ConstIterator& operator=(const Iterator& _it);

        /*
         * 比較するオペレータです
         * @return 同一かを返します
        */
        bool operator==(const LinkedList::ConstIterator& _constit) const;

        /*
         * 比較するオペレータです
         * @return 異なるかを返します
        */
        bool operator!=(const LinkedList::ConstIterator& _constit) const;

    };

    /**
    * これはIteratorクラスの説明です。
    * このクラスは双方向リストで使用されます。
    *
    * @author 吉村括哉
    * @since 2024-10-02
    */
    class Iterator :
        public ConstIterator
    {
    private:
        friend class LinkedList;

    public:
        //コンストラクタ
        LinkedList::Iterator() {}

        //オペレータ
        /*
         * イテレータのさす要素を取得する(非const)関数です。
         * @return イテレータの要素を返します
        */
        T& operator*();

        /*
         * 比較するオペレータです
         * @return 同一かを返します
        */
        bool operator==(const LinkedList::Iterator& _it) const;

        /*
         * 比較するオペレータです
         * @return 異なるかを返します
        */
        bool operator!=(const LinkedList::Iterator& _it) const;
    };

};

#include "LinkedList.inl"