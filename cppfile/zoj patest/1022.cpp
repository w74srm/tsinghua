#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
 
 
struct book{
    int id;
    string title;
    string author;
    vector<string> keywords;
    string publisher;
    int year;
};
 
int N, M;
vector<book> lib;
vector<string> comm;
 
bool cmp(book b1,book b2){
    return b1.id<b2.id;
}
 
int main(){
    int i;
    cin>>N;
    for(i=0;i<N;i++){
        book b;
        cin>>b.id;
        string s,words;
        getline(cin,s);//消除ID行结尾的换行符
        getline(cin,b.title);
        getline(cin,b.author);
        getline(cin,words);
        getline(cin,b.publisher);
        cin>>b.year;
        int l=0;
        int cnt=0;
        for(int j=0;j<words.size()+1;j++){
            if(j==words.size()||words[j]==' '){
                string sn=words.substr(l,cnt);
                b.keywords.push_back(sn);
                l=j+1;
                cnt=0;
            }else{
                cnt++;
            }
        }
        lib.push_back(b);
    }
    cin>>M;
    string s;
    getline(cin,s);
    for(i=0;i<M;i++){
        string w;
        getline(cin,w);
        comm.push_back(w);
    }
 
    sort(lib.begin(),lib.end(),cmp);
 
    int flag=0;
    for(i=0;i<M;i++){
        string c=comm[i].substr(3);
        switch(comm[i][0]){
        case '1':
            cout<<comm[i]<<endl;
            for(int j=0;j<N;j++){
                if(lib[j].title==c){
                    printf("%07d",lib[j].id);
                    cout<<endl;
                    flag=1;
                }
            }
            if(flag==0)
                cout<<"Not Found"<<endl;
            break;
        case '2':
            cout<<comm[i]<<endl;
            for(int j=0;j<N;j++){
                if(lib[j].author==c){
                    printf("%07d",lib[j].id);
                    cout<<endl;
                    flag=1;
                }
            }
            if(flag==0)
                cout<<"Not Found"<<endl;
            break;
        case '3':
            cout<<comm[i]<<endl;
            for(int j=0;j<N;j++){
                for(int k=0;k<lib[j].keywords.size();k++){
                    if(lib[j].keywords[k]==c){
                        printf("%07d",lib[j].id);
                        cout<<endl;
                        flag=1;
                    }
                }
            }
            if(flag==0)
                cout<<"Not Found"<<endl;
            break;
        case '4':
            cout<<comm[i]<<endl;
            for(int j=0;j<N;j++){
                if(lib[j].publisher==c){
                    printf("%07d",lib[j].id);
                    cout<<endl;
                    flag=1;
                }
            }
            if(flag==0)
                cout<<"Not Found"<<endl;
            break;
        case '5':
            cout<<comm[i]<<endl;
            int y=atoi(c.c_str());
            for(int j=0;j<N;j++){
                if(lib[j].year==y){
                    printf("%07d",lib[j].id);
                    cout<<endl;
                    flag=1;
                }
            }
            if(flag==0)
                cout<<"Not Found"<<endl;
            break;
        }
        flag=0;
    }
    return 0;
}