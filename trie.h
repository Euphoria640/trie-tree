//
// Created by euphoria on 2022/6/18.
//

#ifndef UNTITLED1_TRIE_H
#define UNTITLED1_TRIE_H

#endif //UNTITLED1_TRIE_H
#include <iostream>
#include "string"
#include "fstream"
#define MAX_SIZE 53
using namespace std;
typedef struct Node* trie;
/*�ֵ����ṹ����*/
typedef struct Node{
    string data;        /*������*/
    bool flag;          /*����Ƿ񹹳ɵ���*/
    int frequency;      /*��¼���ʳ��ֵĴ���*/
    int number;         /*��¼�ж��ٸ��Դ�Ϊǰ׺*/
    trie next[MAX_SIZE];/*ָ����һ��ָ��*/
}Trie;
void initialization(trie&root);                     /*��ʼ���ڵ�*/
void insert_Word(trie &root,string word);           /*���뵥��*/
void find_Word(trie root,string word);              /*���ҵ���*/
bool word_legality(string name);                    /*��鵥���Ƿ�Ϸ�*/
void read_Word(trie& root);                         /*���ļ��ж��뵥��*/
void menu();                                        /*�˵�*/
void Vague_Search(trie root);                       /*ģ������*/