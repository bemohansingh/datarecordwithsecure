#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
FILE *fp;
void wait();
struct k
{
char pas[25];
int date;
}mo;
void main()
{
     system("color b2");
        wait();
         wait();
        printf("\n\nMOHAN\n\n\n");
        wait();
         wait();
        printf("...................mohan singh\n\n\n");
        wait();
         wait();
        printf(".........MOHAN.........singh...........thagunna..\n");
       wait();
        printf(".....M......O......H.....A.....N.....\n");
        wait();
        printf(".M.O.H.A.N.\n");

        wait();
        printf("M....................\n");
        wait();
        printf("..........O.............\n");
        wait();
        printf("................H...............\n");
        wait();
        printf("...........................A.................\n");
       wait();
        printf("...................................N...............\n");
        wait();
        printf("............................................S.........\n");
        wait();
        printf("....................................................I...\n");
        wait();
        printf("........................................................N.\n");
        wait();
        printf("....................................................G.......\n");
        wait();
        printf("..............................................H.........\n");
        wait();
        printf("..........................................T..........\n");
        wait();
        printf(".......................................H...........\n");
        wait();
        printf(".................................A............\n");
        wait();
        printf("...........................G...........\n");
       wait();
        printf("......................U...........\n");
        wait();
        printf(".............N..............\n");
        wait();
        printf("..........N.....\n");
        wait();
        printf("....A..........................\n");
wait();
    if(fp=fopen("k0045m\\pas.mp","rb+")!=NULL)
    {
        printf("sory dude");
        getch();
        goto e;
    }
    fp=fopen("k0045m\\pas.mp","wb+");
    int i=0,a[21],cnt=0,k=0,wt=0;

    char ms[25],a1,ckc[25],as[25];
printf("enter the year >> ");
scanf("%d",&mo.date);
    re:
        system("cls");
        printf("enter your new password >> ");
         a1=getch();
   while(a1!=13)
    {
        if(a1!=8)
        {
             ms[i]=a1;
            i++;


        }
        else
        {
            if(i>0)
            {
            ms[i]='\0';
            i--;
            }
        }

        system("cls");
        k=0;
        printf("\nenter your pass >> ");
        while(k<i)
        {
       printf("%c",1);
       k++;
        }
        fflush(stdin);
a1=getch();
    }
    ms[i]='\0';
    i=0;
        fflush(stdin);
        printf("\n\nre-enter your new password >> ");
         a1=getch();
    while(a1!=13)
    {
        if(a1!=8)
        {
             as[i]=a1;
            i++;


        }
        else
        {
            if(i>0)
            {
            as[i]='\0';
            i--;
            }
        }

        system("cls");
        k=0;
        printf("\nenter your pass >> ");
        while(k<i)
        {
       printf("%c",1);
       k++;
        }
        fflush(stdin);
a1=getch();
    }
    as[i]='\0';
        fflush(stdin);
        if(strcmp(as,ms)!=0)
        {
           goto re;
        }
        strcpy(mo.pas,as);
        fwrite(&mo,sizeof(mo),1,fp);
    fclose(fp);
e:
{

}

}
void wait()
{
    int i=0;
    for(i=0;i<99990900;i++)
    {

    }
}
