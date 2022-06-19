//
// Created by euphoria on 2022/6/18.
//
#include "trie.h"
#include "iostream"
#include "string"
using namespace std;
void initialization(trie&root)              /*对根节点进行初始化*/
{
    root=new Trie;                          /*创建新节点*/
    for(int i=0;i<MAX_SIZE;i++)
    {
        root->next[i]=NULL;                 /*对根节点的next[]赋予NULL*/
    }
    root->flag=false;                       /*对flag标志赋予false*/
    root->frequency=0;                      /*单词频率初始为0*/
    root->number=0;
}
void insert_Word(trie &root,string word)    /*单词插入*/
{
    trie p=root;
    int k;
    if(root==NULL) return;          /*如果根节点为空，则结束*/
    for(int i=0;i<word.length();i++)
    {
        if(word[i]>='A'&&word[i]<='Z') {
            k=word[i]-'A';
            if (p->next[word[i]-'A'] == NULL) {
                initialization(p->next[word[i]-'A']);       /*对节点进行初始化*/
                //p->next[word[i]-'A']->number++;
            }else{
                p->next[word[i]-'A']->number++;
            }
            p = p->next[k];
        }else if(word[i]>='a'&&word[i]<='z'){
            k=word[i]-'A'-6;
            if (p->next[word[i]-'A'-6] == NULL) {
                initialization(p->next[word[i]-'A'-6]);      /*对节点进行初始化*/
                //p->next[word[i]-'A']->number++;
            }else{
                p->next[word[i]-'A'-6]->number++;
            }
            p = p->next[k];
        }
    }
    p->data=word;
    p->frequency++;             /*单词频率加一*/
    p->flag=true;               /*标志变为TRUE*/
    for(int i=0;i<word.length();i++)            /*输出单词*/
    {
        if(word[i]>='a'&&word[i]<='z'||word[i]>='A'&&word[i]<='Z')
            cout<<word[i];
    }
    cout<<"  插入成功"<<endl;
}
void find_Word(trie root,string word)           /*查找单词*/
{
    //int k;
    trie p=root;
    string new_word;
    //cout<<"h";
    //cout<<"请输入你要查找的单词：";
    //cin>>new_word;
    for(int i=0;i<word.length();i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            if (p->next[word[i] - 'A'-6] == NULL) {
                //Vague_Search(p);
                cout << "未找到" << endl;
                return;
            }
            p = p->next[word[i] - 'A'-6];
        }else if (word[i] >= 'A' && word[i] <= 'Z') {
            if (p->next[word[i] - 'A'] == NULL) {
                //Vague_Search(p);
                cout << "未找到" << endl;
                return;
            }
            p = p->next[word[i] - 'A'];
        }

    }
    if(p->flag) {
        cout << "找到" << endl;
        cout << "所查找的单词出现的次数为：" << p->frequency << endl;
        cout<<"以这为前缀的单词有："<<p->number<<endl;
    }else{
        cout<<"未找到"<<endl;
        cout<<"以这为前缀的单词有："<<p->number<<endl;
    }
    //cout<<"或是你想查找的单词为："<<endl;
    //Vague_Search(p);

}

bool word_legality(string name)             /*判断单词的合法性*/
{
    for(int i=0;i<name.length();i++)
    {
        if(name[i]<'A'||name[i]>='z'||(name[i]>'Z'&&name[i]<'a'))
        {
            if(i>=1&&i<=name.length()-2)
            {
                return false;
            }
        }else if(name[i]-0>=0&&name[i]-0<=9)
        {
            return false;
        }

        if(name[i]-'0'>=0&&name[i]-'0'<=9) return false;

    }
    return true;
}
void read_Word(trie& root)                   /*从文件中读取单词*/
{
    fstream f;                               /*定义文件指针*/
    string word;
    f.open("1.txt",ios::in);        /*打开文件*/
    while(f>>word) {                         /*如果到文件末尾则跳出循环*/
        if (word_legality(word)) {     /*判断单词是否合法*/
            insert_Word(root, word);      /*插入单词*/
            //cout<<word<<"插入成功"<<endl;
        } else {
            cout << word << "插入失败" << endl;
        }
    }
}

void menu()         /*菜单*/
{
    cout<<"【1】从文件中读入单词"<<endl;
    cout<<"【2】插入新单词"<<endl;
    cout<<"【3】查找单词"<<endl;
    cout<<"【0】退出程序"<<endl;
    cout<<"请输入你的选择：";
}

void Vague_Search(trie root)        /*模糊搜索*/
{
    trie p=root;
    while(p)
    {
        for(int i=0;i<MAX_SIZE;i++)
        {
            if(p->next[i])
            {
                if(p->next[i]->flag)
                {
                    cout<<p->next[i]->data<<endl;
                    Vague_Search(p->next[i]);
                }
            }
            p=p->next[i];
        }
    }
}

