#include "iostream"
#include "string"
#include "trie.h"
using namespace std;
int main()
{
    trie root;
    int n;
    initialization(root);                /*对根节点进行初始化*/
    char choose;
    while(1)
    {
        menu();                             /*输出菜单*/
        string word;
        cin>>choose;
        switch(choose)                      /*进行选择*/
        {
            case '1':read_Word(root);break;
            case '2':cout<<"请输入要插入的单词个数：";cin>>n;
            for(int i=0;i<n;i++){cin>>word;if(word_legality(word))insert_Word(root,word);else cout<<word<<"单词不合法"<<endl;}
            break; /*单词插入*/
            case '3':cout<<"请输入要查找的单词：";cin>>word;find_Word(root,word);break;      /*单词查找*/
            case '0':cout<<"退出程序"<<endl;exit(0);
            default:cout<<"输入错误"<<endl;break;
        }
    }

    return 0;
}
