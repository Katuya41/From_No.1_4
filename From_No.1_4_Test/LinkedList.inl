#pragma once
#include"LinkedList.h"

/**
 * LinkedListクラスのコンストラクタ。
 * 初期化処理を行います。
 */
template<typename T>
inline LinkedList<T>::LinkedList()
{
    Dummy.Next = Dummy.Prev = &Dummy;
}

/*
* LinkedListクラスのデストラクタ。
* リストの中身解放を行います。
*/
template<typename T>
inline LinkedList<T>::~LinkedList()
{
    //リストの中身を削除
    Clear();
}

/*
 * データ数を返す関数です。
 * @return 現在のデータ数を返します
 */
template <typename T>
int LinkedList<T>::GetDataNum() const { return DataNum; }

/*
* コンストイテレータを使用してリストに格納する関数です。
* @param _it     受け取ったイテレータ
* @param _data   受け取ったデータ
* @return bool   挿入が成功したかを返す
*/
template <typename T>
bool LinkedList<T>::Insert(LinkedList<T>::ConstIterator& _it, const T& _data)
{
    //イテレータが空じゃないか確認
    if (!_it.IsEmpty())
    {
        //新しいノード作成
        NODE* NewNode = new NODE();

        NewNode->Data = _data;
        NewNode->Next = _it.Node;
        NewNode->Prev = _it.Node->Prev;
        _it.Node->Prev->Next = NewNode;
        _it.Node->Prev = NewNode;
        _it.Node = NewNode;
        DataNum++;
        return true;
    }
    return false;
}

/**
* コンストイテレータを使用してリストの要素を削除する関数です。
* @param _it     受け取ったイテレータ
* @return bool   削除が成功したかを返す
*/
template <typename T>
bool LinkedList<T>::Delete(LinkedList<T>::ConstIterator& _it)
{
    //イテレータが空じゃないか確認
    if (!_it.IsEmpty())
    {
        _it.Node->Next->Prev = _it.Node->Prev;
        _it.Node->Prev->Next = _it.Node->Next;
        delete _it.Node;
        DataNum--;
        return true;
    }
    return false;
}

/*
* リストの中身を全て削除する関数です。
*/
template<typename T>
inline void LinkedList<T>::Clear()
{
    if (&Dummy == Dummy.Prev)
    {
        return;
    }

    NODE* Current = Dummy.Next;
    NODE* NextNode;

    do {
        NextNode = Current->Next; // 次のノードを保存
        delete Current; // 現在のノードを解放
        Current = NextNode; // 次のノードに進む
    } while (Current != &Dummy); // リストが一巡したら終了

    DataNum = 0;
}

/*
* 先頭イテレータを取得する関数です。
* @return 先頭イテレータ
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::GetBegin() {
    LinkedList<T>::Iterator it;
    it.Node = Dummy.Next;
    return it;
}

/*
* 先頭コンストイテレータを取得する関数です。
* @return 先頭コンストイテレータ
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::GetConstBegin() const {
    LinkedList<T>::ConstIterator it;
    it.Node = Dummy->Next;
    return it;
}

/*
* 末尾イテレータを取得する関数です。
* @return ダミーノード
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::GetEnd() {
    LinkedList<T>::Iterator it;
    it.Node = &Dummy;
    return it;
}

/*
 * 末尾コンストイテレータを取得する関数です。
 * @return ダミーノード
 */
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::GetConstEnd() {
    LinkedList<T>::ConstIterator it;
    it.Node = &Dummy;
    return it;
}

/*
* 範囲forに対応するbegin関数です。
* @return 先頭イテレータ
*/
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
    LinkedList<T>::Iterator it;
    it = GetBegin();
    return it;
}

/*
* 範囲forに対応するend関数です。
* @return 末尾イテレータ
*/
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
    LinkedList<T>::Iterator it;
    it = GetEnd();
    return it;
}

/*
 * ノードが空か調べます
 * @return ノードが空かどうかを返します
*/
template <typename T>
typename bool LinkedList<T>::ConstIterator::IsEmpty() { return Node == nullptr; }

//クイックソート実装
//参考にしたサイト:https://bi.biopapyrus.jp/cpp/algorithm/sort/quick-sort.html

/*
* クイックソートを行う関数です
* @param 降順か昇順か(>で昇順 , <で降順)
* @return 型などが不適切なキー指定が引数で渡された場合、falseを返します。
*/
template <typename T>
bool LinkedList<T>::Sort(std::function<bool(const T&, const T&)> _compare) {
    //要素数が1以上か
    if (this->GetDataNum() <= 1)
        return true;

    //比較関数がnullptrの場合
    if (!_compare) {
        return false;
    }

    // リストの最後のノードを探す
    Iterator it = this->GetEnd();
    it--;

    // クイックソートの呼び出し
    Sort(this->GetBegin().Node, it.Node, _compare);

    return true;
}

/*
 * クイックソートを行う関数です
 * @param 最初のノード
 * @param 最後のノード
 * @param 降順か昇順か
 * @return 更新されたピポッドの位置を返す
 */
template <typename T>
void LinkedList<T>::Sort(NODE* _low, NODE* _high, std::function<bool(const T&, const T&)> _compare)
{
    if (_low != _high && _low != _high->Next) {
        NODE* Pivod = Partition(_low, _high, _compare);
        //左側をソート
        Sort(_low, Pivod->Prev, _compare);
        //右側をソート
        Sort(Pivod->Next, _high, _compare);
    }
}

/*
 * 分割を行う関数です
 * @param 最初のノード
 * @param 最後のノード
 * @param 降順か昇順か
 */
template <typename T>
typename LinkedList<T>::NODE* LinkedList<T>::Partition(NODE* _low, NODE* _high, std::function<bool(const T&, const T&)> _compare)
{
    //ピポット設定(一番最後の要素)
    NODE* Pivod = _high;
    NODE* i = nullptr;     // 境界を表すポインタ（最初はnullptr）
    Iterator it;
    it.Node = _low;
    while (it.Node != _high)
    {
        //ピポッドより小さい
        if (_compare((Pivod->Data), (*it)))
        {
            {
                if (i == nullptr)
                    i = _low;
                else
                    i = i->Next;

                Swap((i->Data), (*it));
            }
        }
        it++;
    }

    // 最後にピボットを正しい位置に移動
    if (i == nullptr)
        i = _low;
    else
        i = i->Next;
    Swap((i->Data), (_high->Data));
    return i;  // ピボットの新しい位置を返す
}

/*
* 交換を行う関数です
* @param 交換するデータ1
* @param 交換するデータ2
*/
template <typename T>
void LinkedList<T>::Swap(T& _data1, T& _data2) {
    T temp = std::move(_data1);
    _data1 = std::move(_data2);
    _data2 = std::move(temp);
}

//コンストイテレータクラスのオペレータ
/*
 * イテレータを末尾に向かって進めるオペレータです(前置インクリメント)
 * @return 次のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator++()
{
    assert(this->Node != nullptr && "Iterator points to null!");
    assert(this->Node != this->Node->Next && "Iterator points to Dummy!");
    this->Node = Node->Next;
    //assert(this->Node->Data != nullptr && "Iterator points to Dummy!");
    return *this;
}

/*
 * イテレータを末尾に向かって進めるオペレータです(後置インクリメント)
 * @return 次のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator++(int)
{
    assert(this->Node != nullptr && "Iterator points to null!");
    assert(this->Node != this->Node->Next && "Iterator points to Dummy!");
    LinkedList::Iterator it;
    it.Node = Node;
    Node = Node->Next;
    //assert(IsDummy() != true && "Iterator points to Dummy!");
    //assert(this->Node->Data != nullptr && "Iterator points to Dummy!");
    return it;
}

/*
 * イテレータを先頭に向かって進めるオペレータです(前置インクリメント)
 * @return 前ノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator--() {
    assert(this->Node != nullptr && "Iterator points to null!");
    assert(this->Node != this->Node->Next && "Iterator points to Dummy!");
    this->Node = Node->Prev;
    //assert(this->Node->Prev->Data != nullptr && "Iterator points to Dummy!");
    return *this;
}

/*
 * イテレータを先頭に向かって進めるオペレータです(後置インクリメント)
 * @return 前のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator--(int) {
    assert(this->Node != nullptr && "Iterator points to null!");
    assert(this->Node != this->Node->Next && "Iterator points to Dummy!");
    LinkedList::Iterator it;
    it.Node = Node;
    Node = Node->Prev;
    //assert(IsDummy() != true && "Iterator points to Dummy!");
    //assert(this->Node->Prev->Data != nullptr && "Iterator points to Dummy!");
    return it;
}

/*
 * イテレータのさす要素を取得するオペレータ(const)です
 * @return ノードを返します
*/
template <typename T>
const T& LinkedList<T>::ConstIterator::operator*() const { return this->Node->Data; }

/*
 * 代入するオペレータです
 * @param 代入するコンストイテレータ
 *@return コンストイテレータを返します
*/
template <typename T>
typename LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator=(const Iterator& _it) {
    if ((*this) != _it) {
        this->Node = _it.Node;
        return *this;
    }
    return *this;
}

/*
 * 比較するオペレータです
 * @param 比較するコンストイテレータ
 * @return 同一かを返します
*/
template <typename T>
bool LinkedList<T>::ConstIterator::operator==(const LinkedList<T>::ConstIterator& _constit) const {
    return Node == _constit.Node;
}

/*
 * 比較するオペレータです
 * @param 比較するコンストイテレータ
 * @return 異なるかを返します
*/
template <typename T>
bool LinkedList<T>::ConstIterator::operator!=(const LinkedList<T>::ConstIterator& _constit) const {
    return Node != _constit.Node;
}

//イテレータクラスのオペレータ
/*
 * イテレータのさす要素を取得する(非const)関数です。
 * @return イテレータの要素を返します
*/
template <typename T>
T& LinkedList<T>::Iterator::operator*() {
    assert(this->Node != nullptr && "Iterator points to null!");
    assert(this->Node != this->Node->Next && "Iterator points to Dummy!");
    //assert(this->Node->Data != nullptr && "Iterator points to Dummy!");
    return this->Node->Data;
}

/*
 * 比較するオペレータです
 * @param 比較するイテレータ
 * @return 同一かを返します
*/
template <typename T>
bool LinkedList<T>::Iterator::operator==(const LinkedList<T>::Iterator& _it) const {
    return this->Node == _it.Node;
}

/*
 * 比較するオペレータです
 * @param 比較するイテレータ
 * @return 異なるかを返します
*/
template <typename T>
bool LinkedList<T>::Iterator::operator!=(const LinkedList<T>::Iterator& _it) const {
    return this->Node != _it.Node;
}