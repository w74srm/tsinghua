#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
 
struct Record{
    int id;
    char name[9];
    int grade;
};
 
vector<Record> records;
 
bool cmpById(Record r1, Record r2){
    return (r1.id < r2.id);
}
 
bool cmpByName(Record r1, Record r2){
    if (strcmp(r1.name, r2.name) == 0){
        return (r1.id < r2.id);
    }
    return (strcmp(r1.name, r2.name) < 0);
}
 
bool cmpByGrade(Record r1, Record r2){
    if (r1.grade != r2.grade){
        return (r1.grade < r2.grade);
    }
    else{
        return (r1.id < r2.id);
    }
}
 
int main(){
    int N, C;
    scanf("%d %d", &N, &C);
    for (int i = 0; i < N; i++){
        Record r;
        scanf("%d%s%d", &r.id, r.name, &r.grade);
        records.push_back(r);
    }
    switch (C){
    case 1:sort(records.begin(), records.end(), cmpById); break;
    case 2:sort(records.begin(), records.end(), cmpByName); break;
    case 3:sort(records.begin(), records.end(), cmpByGrade); break;
    }
    for (int i = 0; i < N; i++){
        printf("%06d %s %d\n", records[i].id, records[i].name, records[i].grade);
    }
    return 0;
}