#pragma once
//#ifndef LINKED_LIST_H
//#define LINKED_LIST_H
//#include <string>

#include <functional>
#include <cassert>

/**
 * �����LinkedList�N���X�̐����ł��B
 * ���̃N���X�͑o�������X�g�Ŏg�p����܂��B
 *
 * @author �g������
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
     *�m�[�h������\���̂ł��B
     *
     * @param prev  �O�̃m�[�h
     * @param next  ���̃m�[�h
     * @param Data  �f�[�^
     */
    struct NODE
    {
        NODE* Prev = nullptr;     //��O�̃m�[�h
        NODE* Next = nullptr;     //���̃m�[�h
        T Data = T();             //�f�[�^
    };

    //�_�~�[�m�[�h
    NODE* Dummy;

    //�f�[�^�̐�
    int DataNum = 0;

    /*
    * �N�C�b�N�\�[�g���s���֐��ł�
    * @param �ŏ��̃m�[�h
    * @param �Ō�̃m�[�h
    * @param �~����������
    */
    void Sort(NODE* _low, NODE* _high, std::function<bool(T, T)> _compare);

    /*
     * �������s���֐��ł�
     * @param �ŏ��̃m�[�h
     * @param �Ō�̃m�[�h
     * @param �~����������
     */
    NODE* Partition(NODE* _low, NODE* _high, std::function<bool(const T&, const T&)> _compare);

    /*
     * �������s���֐��ł�
     * @param ��������f�[�^1
     * @param ��������f�[�^2
     */
    void Swap(T& _data1, T& _data2);

public:
    /**
     * LinkedList�N���X�̃R���X�g���N�^�B
     * �������������s���܂��B
     */
    LinkedList();
    ~LinkedList();

    /**
     * �f�[�^����Ԃ��֐��ł��B
     * ���݂̃f�[�^����Ԃ��܂�
     */
    int GetDataNum() const;

    /**
    * �R���X�g�C�e���[�^���g�p���ă��X�g�Ɋi�[����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    * @param _score  �󂯎�����f�[�^�̃X�R�A
    * @param _name   �󂯎�����f�[�^�̖��O
    */
    bool Insert(LinkedList<T>::ConstIterator& _it,const T& _data);

    /**
    * �R���X�g�C�e���[�^���g�p���ă��X�g�̗v�f���폜����֐��ł��B
    * @param _it     �󂯎�����C�e���[�^
    */
    bool Delete(LinkedList<T>::ConstIterator& _it);

    // �m�[�h�����ׂĉ�����郁���o�[�֐�
    void Clear();

    /*
    * �擪�C�e���[�^���擾����֐��ł��B
    * @return �擪�C�e���[�^
    */
    LinkedList<T>::Iterator GetBegin();

    /*
    * �擪�R���X�g�C�e���[�^���擾����֐��ł��B
    * @return �擪�R���X�g�C�e���[�^
    */
    LinkedList<T>::ConstIterator GetConstBegin()const;

    /*
    * �����C�e���[�^���擾����֐��ł��B
    * @return �_�~�[�m�[�h
    */
    LinkedList<T>::Iterator GetEnd();

    /*
     * �����R���X�g�C�e���[�^���擾����֐��ł��B
     * @return �_�~�[�m�[�h
     */
    LinkedList<T>::ConstIterator GetConstEnd();

    /*
    * �͈�for�ɑΉ�����begin�֐��ł��B
    * @return �擪�C�e���[�^
    */
    Iterator begin();

    /*
    * �͈�for�ɑΉ�����end�֐��ł��B
    * @return �����C�e���[�^
    */
    Iterator end();

    /*
     * �N�C�b�N�\�[�g���s���֐��ł�
     * @param ���X�g
     * @param �~����������(>�ŏ��� , <�ō~��)
     */
    bool Sort(std::function<bool(T, T)> _compare);

    /*
    * �����ConstIterator�N���X�̐����ł��B
    * ���̃N���X�͑o�������X�g�Ŏg�p����܂��B
    *
    * @author �g������
    * @since 2024-10-02
    */
    class ConstIterator
    {
    private:
        friend class LinkedList;

        bool IsDummy() const;

    protected:
        //�m�[�h
        NODE* Node = nullptr;

    public:
        LinkedList::ConstIterator() {}

        /*
         * �m�[�h���󂩒��ׂ܂�
         * @return �m�[�h���󂩂ǂ�����Ԃ��܂�
        */
        bool IsEmpty();

        //�I�y���[�^
        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator& operator++();

        /*
         * �C�e���[�^�𖖔��Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return ���̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator++(int);

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(�O�u�C���N�������g)
         * @return �O�m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator& operator--();

        /*
         * �C�e���[�^��擪�Ɍ������Đi�߂�I�y���[�^�ł�(��u�C���N�������g)
         * @return �O�̃m�[�h���擾�����C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator operator--(int);

        /*
         * �C�e���[�^�̂����v�f���擾����I�y���[�^(const)�ł�
         * @return �m�[�h��Ԃ��܂�
        */
        const T& operator*() const;
        /*
         * �R�s�|�R���X�g���N�^�ł�
        */
        LinkedList::ConstIterator(const LinkedList::ConstIterator& _constit) : Node(_constit.Node) {}

        /*
         * �������I�y���[�^�ł�
         *@return �R���X�g�C�e���[�^��Ԃ��܂�
        */
        LinkedList::ConstIterator& operator=(const Iterator& _it);

        /*
         * ��r����I�y���[�^�ł�
         * @return ���ꂩ��Ԃ��܂�
        */
        bool operator==(const LinkedList::ConstIterator& _constit) const;

        /*
         * ��r����I�y���[�^�ł�
         * @return �قȂ邩��Ԃ��܂�
        */
        bool operator!=(const LinkedList::ConstIterator& _constit) const;

    };

    /**
    * �����Iterator�N���X�̐����ł��B
    * ���̃N���X�͑o�������X�g�Ŏg�p����܂��B
    *
    * @author �g������
    * @since 2024-10-02
    */
    class Iterator :
        public ConstIterator
    {
    private:
        friend class LinkedList;

    public:
        //�R���X�g���N�^
        LinkedList::Iterator() {}

        //�I�y���[�^
        /*
         * �C�e���[�^�̂����v�f���擾����(��const)�֐��ł��B
         * @return �C�e���[�^�̗v�f��Ԃ��܂�
        */
        T& operator*();

        /*
         * ��r����I�y���[�^�ł�
         * @return ���ꂩ��Ԃ��܂�
        */
        bool operator==(const LinkedList::Iterator& _it) const;

        /*
         * ��r����I�y���[�^�ł�
         * @return �قȂ邩��Ԃ��܂�
        */
        bool operator!=(const LinkedList::Iterator& _it) const;
    };

};

#include "LinkedList.inl"