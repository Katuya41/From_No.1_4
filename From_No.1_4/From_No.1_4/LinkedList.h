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
    NODE Dummy;

    //データの数
    int DataNum = 0;

    /*
    * クイックソートを行う関数です
    * @param 最初のノード
    * @param 最後のノード
    * @param 降順か昇順か
    */
    void Sort(NODE* _low, NODE* _high, std::function<bool(const T&, const T&)> _compare);

    /*
     * 分割を行う関数です
     * @param 最初のノード
     * @param 最後のノード
     * @param 降順か昇順か
     * @return 更新されたピポッドの位置を返す
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

    /*
     * LinkedListクラスのデストラクタ。
    * リストの中身解放を行います。
    */
    ~LinkedList();

    /*
     * データ数を返す関数です。
     * @return 現在のデータ数を返します
     */
    int GetDataNum() const;

    /**
    * コンストイテレータを使用してリストに格納する関数です。
    * @param _it     受け取ったイテレータ
    * @param _data   受け取ったデータ
    * @return bool   挿入が成功したかを返す
    */
    bool Insert(LinkedList<T>::ConstIterator& _it, const T& _data);

    /**
    * コンストイテレータを使用してリストの要素を削除する関数です。
    * @param _it     受け取ったイテレータ
    * @return bool   削除が成功したかを返す
    */
    bool Delete(LinkedList<T>::ConstIterator& _it);

    /*
    * リストの中身を全て削除する関数です。
    */
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
     * @param 降順か昇順か(>で昇順 , <で降順)
     * @return 型などが不適切なキー指定が引数で渡された場合、falseを返します。
     */
    bool Sort(std::function<bool(const T&, const T&)> _compare);

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
         * @return データを返します
        */
        const T& operator*() const;
        /*
         * コピ－コンストラクタです
         * @param コピーする対象
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}

        /*
         * 代入するオペレータです
         * @param 代入するイテレータ
         *@return コンストイテレータを返します
        */
        LinkedList::ConstIterator& operator=(const Iterator& _it);

        /*
         * 比較するオペレータです
         * @param 比較するコンストイテレータ
         * @return 同一かを返します
        */
        bool operator==(const LinkedList::ConstIterator& _constit) const;

        /*
         * 比較するオペレータです
         * @param 比較するコンストイテレータ
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
         * @param 比較するイテレータ
         * @return 同一かを返します
        */
        bool operator==(const LinkedList::Iterator& _it) const;

        /*
         * 比較するオペレータです
         * @param 比較するイテレータ
         * @return 異なるかを返します
        */
        bool operator!=(const LinkedList::Iterator& _it) const;
    };

};

#include "LinkedList.inl"