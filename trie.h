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
/*字典树结构定义*/
typedef struct Node{
    string data;        /*数据域*/
    bool flag;          /*标记是否构成单词*/
    int frequency;      /*记录单词出现的次数*/
    int number;         /*记录有多少个以此为前缀*/
    trie next[MAX_SIZE];/*指向下一个指针*/
}Trie;
void initialization(trie&root);                     /*初始化节点*/
void insert_Word(trie &root,string word);           /*插入单词*/
void find_Word(trie root,string word);              /*查找单词*/
bool word_legality(string name);                    /*检查单词是否合法*/
void read_Word(trie& root);                         /*从文件中读入单词*/
void menu();                                        /*菜单*/
void Vague_Search(trie root);                       /*模糊搜索*/