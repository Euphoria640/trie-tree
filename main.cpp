#include "iostream"
#include "string"
#include "trie.h"
using namespace std;
int main()
{
    trie root;
    int n;
    initialization(root);                /*�Ը��ڵ���г�ʼ��*/
    char choose;
    while(1)
    {
        menu();                             /*����˵�*/
        string word;
        cin>>choose;
        switch(choose)                      /*����ѡ��*/
        {
            case '1':read_Word(root);break;
            case '2':cout<<"������Ҫ����ĵ��ʸ�����";cin>>n;
            for(int i=0;i<n;i++){cin>>word;if(word_legality(word))insert_Word(root,word);else cout<<word<<"���ʲ��Ϸ�"<<endl;}
            break; /*���ʲ���*/
            case '3':cout<<"������Ҫ���ҵĵ��ʣ�";cin>>word;find_Word(root,word);break;      /*���ʲ���*/
            case '0':cout<<"�˳�����"<<endl;exit(0);
            default:cout<<"�������"<<endl;break;
        }
    }

    return 0;
}
