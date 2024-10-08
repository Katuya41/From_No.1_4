#pragma once
#include"LinkedList.h"

/**
 * データ数を返す関数です。
 * 現在のデータ数を返します
 */
template <typename T>
int LinkedList<T>::GetDataNum() const { return DataNum; }

/**
    * コンストイテレータを使用してリストに格納する関数です。
    * @param _it     受け取ったイテレータ
    * @param _score  受け取ったデータのスコア
    * @param _name   受け取ったデータの名前
    */
template <typename T>
bool LinkedList<T>::Insert(LinkedList<T>::ConstIterator& _it, const T& _data)
{
    //イテレータが空じゃないか確認
    if (!_it.IsEmpty())
    {
        //新しいノード作成
        NODE* NewNode = new NODE();
        T* Data = new T();
        Data->Score = _data.Score;
        Data->Name = _data.Name;
        NewNode->Data = Data;
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
    it.Node = Dummy.Next;
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
* 末尾イテレータを取得する関数です。
* @return 末尾イテレータ
*/
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Getend()
{
    LinkedList<T>::Iterator it;
    it.Node = Dummy.Prev;
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
 * 末尾コンストイテレータを取得する関数です。
 * @return 末尾コンストイテレータ
 */
template<typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::GetConstend()
{
    LinkedList<T>::ConstIterator it;
    it.Node = Dummy.Prev;
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
     * @param リスト
     * @param 降順か昇順か(>で昇順 , <で降順)
     */
template <typename T>
bool LinkedList<T>::Sort(LinkedList<T>& _list, std::function<bool(T, T)> _compare) {
    //要素数が1以上か
    if (_list.GetDataNum() <= 1)
        return false;

    //比較関数がnullptrの場合
    if (!_compare) {  
        return false;
    }

    // リストの最後のノードを探す
    Iterator it = _list.GetEnd();
    it--;

    // クイックソートの呼び出し
    Sort(_list.GetBegin().Node, it.Node, _compare);

    return true;
}

/*
 * クイックソートを行う関数です
 * @param 最初のノード
 * @param 最後のノード
 * @param 降順か昇順か
 */
template <typename T>
void LinkedList<T>::Sort(NODE* _low, NODE* _high, std::function<bool(T, T)> _compare)
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
typename LinkedList<T>::NODE* LinkedList<T>::Partition(NODE* _low, NODE* _high, std::function<bool(T&, T&)> _compare)
{
    //ピポット設定(一番最後の要素)
    NODE* Pivod = _high;
    NODE* i = nullptr;     // 境界を表すポインタ（最初はnullptr）
    Iterator it;
    it.Node = _low;
    while (it.Node != _high)
    {
        //ピポッドより小さい
        if (_compare((*Pivod->Data), (*it)))
        {
            {
                if (i == nullptr)
                    i = _low;
                else
                    i = i->Next;

                Swap((*i->Data), (*it));
            }
        }
        it++;
    }

    // 最後にピボットを正しい位置に移動
    if (i == nullptr)
        i = _low;
    else
        i = i->Next;
    Swap((*i->Data), (*_high->Data));
    return i;  // ピボットの新しい位置を返す
}

/*
* 交換を行う関数です
* @param 交換するデータ1
* @param 交換するデータ2
*/
template <typename T>
void LinkedList<T>::Swap(T& _data1, T& _data2) {
    T temp = _data1;
    _data1 = _data2;
    _data2 = temp;
}

//コンストイテレータクラスのオペレータ
/*
 * イテレータを末尾に向かって進めるオペレータです(前置インクリメント)
 * @return 次のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator++()
{
    this->Node = Node->Next;
    return *this;
}

/*
 * イテレータを末尾に向かって進めるオペレータです(後置インクリメント)
 * @return 次のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator++(int)
{
    LinkedList::Iterator it;
    it.Node = Node;
    Node = Node->Next;
    return it;
}

/*
 * イテレータを先頭に向かって進めるオペレータです(前置インクリメント)
 * @return 前ノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::ConstIterator& LinkedList<T>::ConstIterator::operator--() {
    this->Node = Node->Prev;
    return *this;
}

/*
 * イテレータを先頭に向かって進めるオペレータです(後置インクリメント)
 * @return 前のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator--(int) {
    LinkedList::Iterator it;
    it.Node = Node;
    Node = Node->Prev;
    return it;
}

/*
 * イテレータのさす要素を取得するオペレータ(const)です
 * @return ノードを返します
*/
template <typename T>
const T& LinkedList<T>::ConstIterator::operator*() const { return *this->Node->Data; }

/*
 * 代入するオペレータです
 *@return コンストイテレータを返します
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::ConstIterator::operator=(const Iterator* _it) {
    if (this != _it) {
        LinkedList::ConstIterator NewConst;
        NewConst = _it;
        return NewConst;
    }
    return *this;
}

/*
 * 比較するオペレータです
 * @return 同一かを返します
*/
template <typename T>
bool LinkedList<T>::ConstIterator::operator==(const LinkedList<T>::ConstIterator& _constit) const {
    return Node == _constit.Node;
}

/*
 * 比較するオペレータです
 * @return 異なるかを返します
*/
template <typename T>
bool LinkedList<T>::ConstIterator::operator!=(const LinkedList<T>::ConstIterator& _constit) const {
    return Node != _constit.Node;
}

//イテレータクラスのオペレータ
/*
* イテレータを末尾に向かって進めるオペレータです(前置インクリメント)
* @return 次のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++() {
    assert(Node != nullptr && "Iterator points to null!");
    assert(Node->Data != nullptr && "Iterator points to Dummy!");
    this->Node = this->Node->Next;
    return *this;
}

/*
 * イテレータを末尾に向かって進めるオペレータです(後置インクリメント)
 * @return 次のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int) {
    assert(Node != nullptr && "Iterator points to null!");
    assert(Node->Data != nullptr && "Iterator points to Dummy!");
    LinkedList::Iterator it;
    it.Node = Node;
    Node = Node->Next;
    return it;
}

/*
 * イテレータを先頭に向かって進めるオペレータです(前置インクリメント)
 * @return 前ノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--() {
    assert(this->Node != nullptr && "Iterator points to null!");
    assert(this->Node->Prev->Data != nullptr && "Iterator points to Dummy!");
    this->Node = this->Node->Prev;
    return *this;
}

/*
 * イテレータを先頭に向かって進めるオペレータです(後置インクリメント)
 * @return 前のノードを取得したイテレータを返します
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator--(int) {
    assert(Node != nullptr && "Iterator points to null!");
    assert(Node->Prev->Data != nullptr && "Iterator points to Dummy!");
    LinkedList::Iterator it;
    it.Node = Node;
    Node = Node->Prev;
    return it;
}

/*
 * イテレータのさす要素を取得する(非const)関数です。
 * @return イテレータの要素を返します
*/
template <typename T>
T& LinkedList<T>::Iterator::operator*() {
    assert(Node != nullptr && "Iterator points to null!");
    assert(Node->Data != nullptr && "Iterator points to Dummy!");
    return *this->Node->Data;
}

/*
 * 比較するオペレータです
 * @return 同一かを返します
*/
template <typename T>
bool LinkedList<T>::Iterator::operator==(const LinkedList<T>::Iterator& _it) const {
    return this->Node == _it.Node;
}

/*
 * 比較するオペレータです
 * @return 異なるかを返します
*/
template <typename T>
bool LinkedList<T>::Iterator::operator!=(const LinkedList<T>::Iterator& _it) const {
    return this->Node != _it.Node;
}