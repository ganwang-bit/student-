#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
struct stidinfo
{
    char no[20];
    char name[10];
    float score[6];
    float aver,total;
    struct stidinfo*list;
};
struct stidinfo* listHead()
{
    struct stidinfo* start=(struct stidinfo*)malloc(sizeof(struct stidinfo));
    return start;
}
void input(struct stidinfo*p,int n)
{
    int i=1;
    while(n--)
    {
        printf("Please enter %d's information:\n",i);
        printf("Student id:");
        scanf("%s",(p->no));
        printf("Name:");
        scanf("%s",(p->name));
        int j=0;
        printf("Grades in 6 courses:");
        for(j=0;j<6;j++)
        {
            scanf("%f",&(p->score)[j]);
            getchar();
        }
        int l=0;
        for(j=0;j<6;j++)
        {
            l=l+(p->score)[j];
        }
        p->total=l;
        p->aver=l/6.0;
        p->list=(struct stidinfo*)malloc(sizeof(struct stidinfo));
        p=p->list;
        i++;
    }
}
void output(struct stidinfo*p,int n)
{
    while(n--)
    {
        printf("Id      Name    Score1  Score2  Score3  Score4  Score5  Score6  Total  Average\n");
        printf("%s    %s    %0.2f   %0.2f   %0.2f   %0.2f   %0.2f   %0.2f   %0.2f  %0.2f\n",p->no,p->name,(p->score)[0],(p->score)[1],(p->score)[2],(p->score)[3],(p->score)[4],(p->score)[5],p->total,p->aver);
        p=p->list;
    }
}
void calculat(struct stidinfo*p,int n,int*nopass,int*good)
{
    while(n--)
    {
        int j=0;
        while(j<6)
        {
            if((p->score)[j]<60)
                (*nopass)++;
            if((p->score)[j]>=90)
                (*good)++;
            j++;
        }
        p=p->list;
    }
}
int main()
{
    int n;
    printf("Please enter students number:");
    scanf("%d",&n);
    struct stidinfo*Head=listHead();
    input(Head,n);
    output(Head,n);
    int nopass=0;
    int good=0;
    int*no=&nopass;
    int*go=&good;
    calculat(Head,n,no,go);
    printf("Number of flunks %d\n",nopass);
    printf("Number of good %d\n",good);
    return 0;
}
