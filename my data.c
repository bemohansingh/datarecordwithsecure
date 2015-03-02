#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
void total();
void kharch();
void view();
void ren();
void ckp();
FILE *kr;
FILE *tl;
FILE *fp;
struct kk
{
char pas[25];
int date;
}kk;

struct k
{
  int n,d,m,bl;
int  cnt;

    char dis[100];
}mo,moh;
void main()
{
if(fp=fopen("k0045m\\pas.mp","rb+")==NULL)
{
    printf("error");
    goto exit;
}
system("del setup.exe");
    int k;
    pass:
    system("cls");
    system("color 1b");
    printf("\n 1 >> log in \n 2 >> change password\n 3 >> exit\n\n choose option:-\t");
    scanf("%d",&k);
fflush(stdin);
    switch(k)
    {
     case 1:
     ckp();
     goto come;
     case 2:
     ren();
     goto pass;
     case 3:
     goto exit;
    }
    goto pass;
    come:
    k=0;
    system("cls");
    printf("\n1 >> add balance\n2 >> add your expenditure\n 3 >> view all\n 4 >> exit\n\n choose option:-\t");
    scanf("%d",&k);
    fflush(stdin);
    switch(k)
    {
     case 1:
     ckp();
     total();
     break;
     case 2:
     ckp();
     kharch();
     break;
     case 3:
     view();
     break;
     case 4:
     goto exit;
     default:
     goto come;
    }
    goto come;
    exit:
    {

    }
}
void total()
{
     system("color cf");
moh.bl=0;
system("cls");
   tl=fopen("k0045m\\total.mp","ab+");
   printf("\nenter the added balance = ");
   scanf("%d",&moh.bl);
   fflush(stdin);
   printf("enter the date mm-dd >> ");
   scanf("%d-%d",&moh.m,&moh.d);
   moh.n=9;
    fwrite(&moh,sizeof(moh),1,tl);
    fclose(tl);
    printf("\n\n\n\n");
    system("pause");
}

void kharch()
{
    char ans;
    do
    {
     system("color b3");
system("cls");
    int n,d,m,inr=0;
    char dis[20];
    kr=fopen("k0045m\\expn.mp","rb+");
    while(fread(&mo,sizeof(mo),1,kr)==1)
    inr=mo.cnt;
    fclose(kr);

    kr=fopen("k0045m\\expn.mp","ab+");
    fflush(stdin);
    printf("enter the expenditure = ");
    scanf("%d",&mo.n);
    printf("enter the month and day in the format mm-dd = ");
    scanf("%d-%d",&mo.m,&mo.d);
     fflush(stdin);
    printf("enter the reason of expenditure = ");
    scanf("%[^\n]s",mo.dis);
          mo.cnt=inr+1;
              fwrite(&mo,sizeof(mo),1,kr);
    fclose(kr);
    printf("\n\n\n\n");
    printf("enter y for next record  ");
    ans=getch();
    }while(ans=='y');
}
void view()
{

    system("color a2");
    system("cls");
    char ed;
    int inr=0,yrr=0,temp,co=0;
    int a=0,s=0,n,slt=0,mon=0,msum=0;
    mo:
    system("cls");
    printf("1 >> your balance\n2 >> your expenditure\n\n enter your option >> ");
    scanf("%d",&slt);
    fp=fopen("k0045m\\pas.mp","rb+");
    fread(&kk,sizeof(kk),1,fp);
    kr=fopen("k0045m\\expn.mp","rb+");
    tl=fopen("k0045m\\total.mp","rb+");
    switch(slt)
    {
        case 1:
        ckp();
        system("cls");
        printf("DATE\tRS\n");
        while(fread(&moh,sizeof(moh),1,tl)==1)
      {
        printf("%d-%d\t%d\n",moh.m,moh.d,moh.bl);
        a=a+moh.bl;
      }
      while(fread(&mo,sizeof(mo),1,kr)==1 )
  {
      s=s+mo.n;
  }
       printf("\n\n\ttotal expenditure =%d \n\ttotal balance = %d\n\tremaining balance =%d\n\n",s,a,a-s);
        fclose(kr);
        fclose(tl);
        system("pause");
        goto mo;
        case 2:
        system("cls");

        printf("SN >>    DATE  \t \t  \texpenditure\n\n");
        while(fread(&mo,sizeof(mo),1,kr)==1 )
  {
      kk:
      if(temp!=mo.m)
        {
    if(msum>0)
    {
          mon++;
          if(temp>mo.m)
          kk.date++;
      printf("%d >> %d year %d month\t\tRS-%d\n",mon,kk.date,temp,msum);
    }
       msum=0;
        }
      if(mo.m==inr /*&& mo.date==2069+yrr*/)
      {
          temp=mo.m;
          msum=msum+mo.n;
      }
      else
      {
        inr++;
       if(inr>12)
       {
       inr=0;

       }
       goto kk;
      }
      s=s+mo.n;
  }
   if(msum>0)
    {
          mon++;
      printf("%d  >>%d year %d month\t\tRS-%d\n",mon,kk.date,mo.m,msum);
    }
       msum=0;
  printf("total expenditure >> %d\n\n",s);
  fclose(kr);
   fclose(tl);
   break;
        default:
        goto mo;
    }
fclose(kr);
   fclose(tl);
   fclose(fp);
   printf("\n\n\n\n");
    printf("-*-*- view  data detail enter v other wise press any key -*-*-*- ");
    ed=getch();
    fflush(stdin);
    if(ed=='v' || ed=='V')
    {

        printf("\n\nenter the month   >> ");
        scanf("%d",&n);
        system("cls");
        kr=fopen("k0045m\\expn.mp","rb+");
        printf("SN >> DATE\texpenditure     discriotion\n");
        while(fread(&mo,sizeof(mo),1,kr)==1 )
  {
      if(n==mo.m)
      {

        printf("%d >> %d/%d\t%d            \t%s\n",mo.cnt,mo.m,mo.d,mo.n,mo.dis);
      }
    }
    fclose(kr);

      printf("\n\n\n\n");
    printf("-*-*-*- edit data  press e other wise press any key -*-*-* ");
    ed=getch();
    fflush(stdin);
    if(ed=='e' || ed=='e')
    {

        printf("\n\nenter the month  sn number of edited data >> ");
        scanf("%d",&n);
        system("cls");
        ckp();
        FILE *cpy;
        fflush(stdin);
        cpy=fopen("k0045m\\expn1.mp","wb+");
        fflush(stdin);
        kr=fopen("k0045m\\expn.mp","rb+");
        fflush(stdin);
        while(fread(&mo,sizeof(mo),1,kr)==1 )
  {
      if(n==mo.cnt)
      {
          fflush(stdin);
        system("cls");
        printf("enter the your expenditure( previous %d) >> ",mo.n);
        scanf("%d",&mo.n);
        fflush(stdin);
        printf("enter the date mm-dd( previous %d-%d) >> ",mo.m,mo.d);
        scanf("%d-%d",&mo.m,&mo.d);
        fflush(stdin);
        printf("enter the discription ( previous %s)>> ",mo.dis);
        scanf("%[^\n]s",&mo.dis);
        fflush(stdin);
        fwrite(&mo,sizeof(mo),1,cpy);
      }
      else
      {
          fflush(stdin);
       fwrite(&mo,sizeof(mo),1,cpy);
      }
  }
  fclose(kr);
      fclose(cpy);
fflush(stdin);
      system("del k0045m\\expn.mp");
      fflush(stdin);
      system("ren k0045m\\expn1.mp expn.mp");

    }
    }
}
void ckp()
{

    char ms[25],a;
    int i=0,cnt=0;
    int k=0,l;
    A:
    printf("\nenter your pass >> ");
    fflush(stdin);
    a=getch();
    fflush(stdin);
    fp=fopen("k0045m\\pas.mp","rb+");
    fread(&kk,sizeof(kk),1,fp);
    while(a!=13)
    {
        if(a!=8)
        {
             ms[i]=a;
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
        l=0;
        l=strlen(ms);
        k=0;
        printf("\nenter your pass >> ");
        while(k<i)
        {
       printf("%c",1);
       k++;
        }
        fflush(stdin);
a=getch();
    }
    ms[i]='\0';
    if(strcmp(kk.pas,ms)!=0)
    {
        i=0;
        while(ms[i]!='\0')
        {
            ms[i]='\0';
            i++;
        }
        cnt++;
        i=0;
        system("cls");
        printf("tri again and your %d times error password",cnt);
        goto A;
    }

    fclose(fp);
}
void ren()
{
    system("cls");

    char ms[25],a,ckc[25],as[25];
    int i=0,cnt=0,k;
    a:
    fp=fopen("k0045m\\pas.mp","rb+");
    fread(&kk,sizeof(kk),1,fp);
    fflush(stdin);
    printf("enter your old password >> ");
    scanf("%[^\n]s",ckc);
    fflush(stdin);
    if(strcmp(ckc,kk.pas)==0)
    {
        re:
        system("cls");
        printf("enter your new password >> ");
         a=getch();
   while(a!=13)
    {
        if(a!=8)
        {
             ms[i]=a;
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
a=getch();
    }
    ms[i]='\0';
    i=0;
        fflush(stdin);
        printf("\n\nre-enter your new password >> ");
         a=getch();
    while(a!=13)
    {
        if(a!=8)
        {
             as[i]=a;
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
a=getch();
    }
    as[i]='\0';
        fflush(stdin);
        if(strcmp(as,ms)!=0)
        {
           goto re;
        }
    }
    else
    {
        system("cls");
        printf("wrong password");
        goto a;
    }
    fclose(fp);
    fflush(stdin);
    strcpy(kk.pas,ms);
    fp=fopen("k0045m\\pas.mp","wb+");
    fwrite(&kk,sizeof(kk),1,fp);
     fclose(fp);

}
