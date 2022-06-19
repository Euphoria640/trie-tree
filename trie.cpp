//
// Created by euphoria on 2022/6/18.
//
#include "trie.h"
#include "iostream"
#include "string"
using namespace std;
void initialization(trie&root)              /*�Ը��ڵ���г�ʼ��*/
{
    root=new Trie;                          /*�����½ڵ�*/
    for(int i=0;i<MAX_SIZE;i++)
    {
        root->next[i]=NULL;                 /*�Ը��ڵ��next[]����NULL*/
    }
    root->flag=false;                       /*��flag��־����false*/
    root->frequency=0;                      /*����Ƶ�ʳ�ʼΪ0*/
    root->number=0;
}
void insert_Word(trie &root,string word)    /*���ʲ���*/
{
    trie p=root;
    int k;
    if(root==NULL) return;          /*������ڵ�Ϊ�գ������*/
    for(int i=0;i<word.length();i++)
    {
        if(word[i]>='A'&&word[i]<='Z') {
            k=word[i]-'A';
            if (p->next[word[i]-'A'] == NULL) {
                initialization(p->next[word[i]-'A']);       /*�Խڵ���г�ʼ��*/
                //p->next[word[i]-'A']->number++;
            }else{
                p->next[word[i]-'A']->number++;
            }
            p = p->next[k];
        }else if(word[i]>='a'&&word[i]<='z'){
            k=word[i]-'A'-6;
            if (p->next[word[i]-'A'-6] == NULL) {
                initialization(p->next[word[i]-'A'-6]);      /*�Խڵ���г�ʼ��*/
                //p->next[word[i]-'A']->number++;
            }else{
                p->next[word[i]-'A'-6]->number++;
            }
            p = p->next[k];
        }
    }
    p->data=word;
    p->frequency++;             /*����Ƶ�ʼ�һ*/
    p->flag=true;               /*��־��ΪTRUE*/
    for(int i=0;i<word.length();i++)            /*�������*/
    {
        if(word[i]>='a'&&word[i]<='z'||word[i]>='A'&&word[i]<='Z')
            cout<<word[i];
    }
    cout<<"  ����ɹ�"<<endl;
}
void find_Word(trie root,string word)           /*���ҵ���*/
{
    //int k;
    trie p=root;
    string new_word;
    //cout<<"h";
    //cout<<"��������Ҫ���ҵĵ��ʣ�";
    //cin>>new_word;
    for(int i=0;i<word.length();i++) {
        if (word[i] >= 'a' && word[i] <= 'z') {
            if (p->next[word[i] - 'A'-6] == NULL) {
                //Vague_Search(p);
                cout << "δ�ҵ�" << endl;
                return;
            }
            p = p->next[word[i] - 'A'-6];
        }else if (word[i] >= 'A' && word[i] <= 'Z') {
            if (p->next[word[i] - 'A'] == NULL) {
                //Vague_Search(p);
                cout << "δ�ҵ�" << endl;
                return;
            }
            p = p->next[word[i] - 'A'];
        }

    }
    if(p->flag) {
        cout << "�ҵ�" << endl;
        cout << "�����ҵĵ��ʳ��ֵĴ���Ϊ��" << p->frequency << endl;
        cout<<"����Ϊǰ׺�ĵ����У�"<<p->number<<endl;
    }else{
        cout<<"δ�ҵ�"<<endl;
        cout<<"����Ϊǰ׺�ĵ����У�"<<p->number<<endl;
    }
    //cout<<"����������ҵĵ���Ϊ��"<<endl;
    //Vague_Search(p);

}

bool word_legality(string name)             /*�жϵ��ʵĺϷ���*/
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
void read_Word(trie& root)                   /*���ļ��ж�ȡ����*/
{
    fstream f;                               /*�����ļ�ָ��*/
    string word;
    f.open("1.txt",ios::in);        /*���ļ�*/
    while(f>>word) {                         /*������ļ�ĩβ������ѭ��*/
        if (word_legality(word)) {     /*�жϵ����Ƿ�Ϸ�*/
            insert_Word(root, word);      /*���뵥��*/
            //cout<<word<<"����ɹ�"<<endl;
        } else {
            cout << word << "����ʧ��" << endl;
        }
    }
}

void menu()         /*�˵�*/
{
    cout<<"��1�����ļ��ж��뵥��"<<endl;
    cout<<"��2�������µ���"<<endl;
    cout<<"��3�����ҵ���"<<endl;
    cout<<"��0���˳�����"<<endl;
    cout<<"���������ѡ��";
}

void Vague_Search(trie root)        /*ģ������*/
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

