#pragma once
#include"LinkedList.h"

/**
 * LinkedList�N���X�̃R���X�g���N�^�B
 * �������������s���܂��B
 */
template<typename T>
inline LinkedList<T>::LinkedList()
{
    Dummy.Next = Dummy.Prev = &Dummy;
}

/*
* LinkedList�N���X�̃f�X�g���N�^�B
* ���X�g�̒��g������s���܂��B
*/
template<typename T>
inline LinkedList<T>::~LinkedList()
{
    //���X�g�̒��g���폜
    Clear();
}

/*
 * �f�[�^����Ԃ��֐��ł��B
 * @return ���݂̃f�[�^����Ԃ��܂�
 */
template <typename T>
int LinkedList<T>::GetDataNum() const { return DataNum; }

/*
* �R���X�g�C�e���[�^���g�p���ă��X�g�Ɋi�[����֐��ł��B
* @param _it     �󂯎�����C�e���[�^
* @param _data   �󂯎�����f�[�^
* @return bool   �}����������������Ԃ�
*/
template <typename T>
bool LinkedList<T>::Insert(LinkedList<T>::ConstIterator& _it, const T& _data)
{
    //�C�e���[�^���󂶂�Ȃ����m�F
    if (!_it.IsEmpty())
    {
        //�V�����m�[�h�쐬
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
* �R���X�g�C�e���[�^���g�p���ă��X�g�̗v�f���폜����֐��ł��B
* @param _it     �󂯎�����C�e���[�^
* @return bool   �폜��������������Ԃ�
*/
template <typename T>
bool LinkedList<T>::Delete(LinkedList<T>::ConstIterator& _it)
{
    //�C�e���[�^���󂶂�Ȃ����m�F
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
* ���X�g�̒��g��S�č폜����֐��ł��B
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
        NextNode = Current->Next; // ���̃m�[�h��ۑ�
        delete Current; // ���݂̃m�[�h�����
        Current = NextNode; // ���̃m�[�h�ɐi��
    } while (Current != &Dummy); // ���X�g���ꏄ������I��

    DataNum = 0;
}

/*
* �擪�C�e���[�^���擾����֐��ł��B
* @return �擪�C�e���[�^
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::GetBegin() {
    LinkedList<T>::Iterator it;
    it.Node = Dummy.Next;
    return it;
}

/*
* �擪�R���X�g�C�e���[�^���擾����֐��ł��B
* @return �擪�R���X�g�C�e���[�^
*/
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::GetConstBegin() const {
    LinkedList<T>::ConstIterator it;
    it.Node = Dummy->Next;
    return it;
}

/*
* �����C�e���[�^���擾����֐��ł��B
* @return �_�~�[�m�[�h
*/
template <typename T>
typename LinkedList<T>::Iterator LinkedList<T>::GetEnd() {
    LinkedList<T>::Iterator it;
    it.Node = &Dummy;
    return it;
}

/*
 * �����R���X�g�C�e���[�^���擾����֐��ł��B
 * @return �_�~�[�m�[�h
 */
template <typename T>
typename LinkedList<T>::ConstIterator LinkedList<T>::GetConstEnd() {
    LinkedList<T>::ConstIterator it;
    it.Node = &Dummy;
    return it;
}

/*
* �͈�for�ɑΉ�����begin�֐��ł��B
* @return �擪�C�e���[�^
*/
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin()
{
    LinkedList<T>::Iterator it;
    it = GetBegin();
    return it;
}

/*
* �͈�for�ɑΉ�����end�֐��ł��B
* @return �����C�e���[�^
*/
template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end()
{
    LinkedList<T>::Iterator it;
    it = GetEnd();
    return it;
}

/*
 * �m�[�h���󂩒��ׂ܂�
 * @return �m�[�h���󂩂ǂ�����Ԃ��܂�
*/
template <typename T>
typename bool LinkedList<T>::ConstIterator::IsEmpty() { return Node == nullptr; }

//�N�C�b�N�\�[�g����
//�Q�l�ɂ����T�C�g:https://bi.biopapyrus.jp/cpp/algorithm/sort/quick-sort.html

/*
* �N�C�b�N�\�[�g���s���֐��ł�
* @param �~����������(>�ŏ��� , <�ō~��)
* @return �^�Ȃǂ��s�K�؂ȃL�[�w�肪�����œn���ꂽ�ꍇ�Afalse��Ԃ��܂��B
*/
template <typename T>
bool LinkedList<T>::Sort(std::function<bool(const T&, const T&)> _compare) {
    //�v�f����1�ȏォ
    if (this->GetDataNum() <= 1)
        return true;

    //��r�֐���nullptr�̏ꍇ
    if (!_compare) {
        return false;
    }

    // ���X�g�̍Ō�̃m�[�h��T��
    Iterator it = this->GetEnd();
    it--;

    // �N�C�b�N�\�[�g�̌Ăяo��
    Sort(this->GetBegin().Node, it.Node, _compare);

    return true;
}

/*
 * �N�C�b�N�\�[�g���s���֐��ł�
 * @param �ŏ��̃m�[�h
 * @param �Ō�̃m�[�h
 * @param �~����������
 * @return �X�V���ꂽ�s�|�b�h�̈ʒu��Ԃ�
 */
template <typename T>
void LinkedList<T>::Sort(NODE* _low, NODE* _high, std::function<bool(const T&, const T&)> _compare)
{
    if (_low != _high && _low != _high->Next) {
        NODE* Pivod = Partition(_low, _high, _compare);
        //�������\�[�g
        Sort(_low, Pivod->Prev, _compare);
        //�E�����\�[�g
        Sort(Pivod->Next, _high, _compare);
    }
}

/*
 * �������s���֐��ł�
 * @param �ŏ��̃m�[�h
 * @param �Ō�̃m�[�h
 * @param �~����������
 */
template <typename T>
typename LinkedList<T>::NODE* LinkedList<T>::Partition(NODE* _low, NODE* _high, std::function<bool(const T&, const T&)> _compare)
{
    //�s�|�b�g�ݒ�(��ԍŌ�̗v�f)
    NODE* Pivod = _high;
    NODE* i = nullptr;     // ���E��\���|�C���^�i�ŏ���nullptr�j
    Iterator it;
    it.Node = _low;
    while (it.Node != _high)
    {
        //�s�|�b�h��菬����
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

    // �Ō�Ƀs�{�b�g�𐳂����ʒu�Ɉړ�
    if (i == nullptr)
        i = _low;
    else
        i = i->Next;
    Swap((i->Data), (_high->Data));
    return i;  // �s�{�b�g�̐V�����ʒu��Ԃ�
}

/*
* �������s���֐��ł�
* @param ��������f�[�^1
* @param ��������f�[�^2
*/
template <typename T>
void LinkedList<T>::Swap(T& _data1, T& _data2) {
    T temp = std::move(_data1);
    _data1 = std::move(_data2);
    _data2 = std::move(temp);
}

//�R���X�g�C�e���[�^�N���X�̃I�y���[�^
/*
 * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
 * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
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
 * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
 * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
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
 * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
 * @return �O�m�[�h���擾�����C�e���[�^��Ԃ��܂�
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
 * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
 * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
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
 * �C�e���[�^�̂����v�f���擾����I�y���[�^(const)�ł�
 * @return �m�[�h��Ԃ��܂�
*/
template <typename T>
const T& LinkedList<T>::ConstIterator::operator*() const { return this->Node->Data; }

/*
 * �������I�y���[�^�ł�
 * @param �������R���X�g�C�e���[�^
 *@return �R���X�g�C�e���[�^��Ԃ��܂�
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
 * ��r����I�y���[�^�ł�
 * @param ��r����R���X�g�C�e���[�^
 * @return ���ꂩ��Ԃ��܂�
*/
template <typename T>
bool LinkedList<T>::ConstIterator::operator==(const LinkedList<T>::ConstIterator& _constit) const {
    return Node == _constit.Node;
}

/*
 * ��r����I�y���[�^�ł�
 * @param ��r����R���X�g�C�e���[�^
 * @return �قȂ邩��Ԃ��܂�
*/
template <typename T>
bool LinkedList<T>::ConstIterator::operator!=(const LinkedList<T>::ConstIterator& _constit) const {
    return Node != _constit.Node;
}

//�C�e���[�^�N���X�̃I�y���[�^
/*
 * �C�e���[�^�̂����v�f���擾����(��const)�֐��ł��B
 * @return �C�e���[�^�̗v�f��Ԃ��܂�
*/
template <typename T>
T& LinkedList<T>::Iterator::operator*() {
    assert(this->Node != nullptr && "Iterator points to null!");
    assert(this->Node != this->Node->Next && "Iterator points to Dummy!");
    //assert(this->Node->Data != nullptr && "Iterator points to Dummy!");
    return this->Node->Data;
}

/*
 * ��r����I�y���[�^�ł�
 * @param ��r����C�e���[�^
 * @return ���ꂩ��Ԃ��܂�
*/
template <typename T>
bool LinkedList<T>::Iterator::operator==(const LinkedList<T>::Iterator& _it) const {
    return this->Node == _it.Node;
}

/*
 * ��r����I�y���[�^�ł�
 * @param ��r����C�e���[�^
 * @return �قȂ邩��Ԃ��܂�
*/
template <typename T>
bool LinkedList<T>::Iterator::operator!=(const LinkedList<T>::Iterator& _it) const {
    return this->Node != _it.Node;
}