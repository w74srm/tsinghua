#include<math.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student
{
	char id[14];
	int score;
	int room;
	int room_rank;

}stu[50000];


bool cmp(Student a, Student b){
	if (a.score != b.score) return a.score>b.score;
	else return strcmp(a.id, b.id) < 0;
}

int main()
{
	int n, k,all=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%s %d", stu[all].id, &stu[all].score);
			stu[all].room = i ;
			all++;
		}
		sort(stu+all-k,stu+all,cmp);
		stu[all - k].room_rank = 1;
		for (int j = all - k,rank=2; j < all; j++,rank++)
		{
			if (stu[j].score == stu[j + 1].score)
				stu[j + 1].room_rank = stu[j].room_rank;
			else
				stu[j + 1].room_rank = rank;
		}
	}

	sort(stu, stu + all, cmp);
	printf("%d\n", all);
	int tmp = 1;
	printf("%s %d %d %d\n", stu[0].id,tmp, stu[0].room, stu[0].room_rank);
	for (int i = 1; i <all; i++)
	{
		if (stu[i - 1].score != stu[i].score)
			tmp = i + 1;
		printf("%s %d %d %d\n", stu[i].id, tmp, stu[i].room, stu[i].room_rank);
	}
	return 0;
}
