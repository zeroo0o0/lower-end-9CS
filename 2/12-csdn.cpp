#include<bits/stdc++.h>
using namespace std;

//maintain the element
set<string>maintain;
//store the element and make it oredered by the entry sequence
vector<string>dictionary;

bool eraseOperate(string first, string second)   //*******插入一个  ==该string删除一个 
{
    if( abs ( int( first.size() - second.size() ) ) != 1)return false;   
    //make sure first size is bigger than the second
    if(first.size() < second.size() ) 
        swap(first,second);
    int firstSize = first.size() ; int secondSize = second.size();
    string tmp = first;
    for(int i = 0 ; i < firstSize ; i ++)
    {
        tmp.erase(i,1);
        if(tmp == second)return true;
        tmp = first;
    }
    return false;
}

bool replaceOperate(string first,string second)
{
    int firstSize = first.size() ; int secondSize = second.size();
    if(firstSize != secondSize )return false;
    int count = 0;
    for(int i = 0 ; i < firstSize ; i++)
    {
        if( first[i]!= second[i] )count++;
    }
    return ( count == 1 );
}

int main()
{
    string dict;
    while(cin>>dict && dict[0] !='#')
    {
        dictionary.push_back(dict);
        maintain.insert(dict);
    }
    string word;
    while(cin>>word && word[0] != '#')
    {
        if(maintain.find(word) != maintain.end() )
        {
            cout<<word<<" is correct"<<endl;
        }
        else{
            cout<<word<<": ";
            for(auto& v : dictionary)
            {
                if(replaceOperate(v,word) || eraseOperate(v,word) )
                {
                    cout<<v<<" ";
                }
            }
            cout<<endl;
        }
    }
}


