#include <stdio.h>
#include <stdlib.h>
typedef struct dulnode
{
	int data;
	struct dulnode *prior;
	struct dulnode *next;
}dulnode,*dulinklist;
void input(dulinklist &s)
{
	dulinklist p;
	char c;
	int i=0;
	s=(dulinklist)malloc(sizeof(dulnode));
	s->next=s->prior=s;
	c=getchar();
	while(c!='\n'&&c!=' ')
	{
		if(c>='0'&&c<='9')
		{
			if(!(p=(dulinklist)malloc(sizeof(dulnode))))
			return;
			p->data=(int)(c-'0');
			p->next=s->next;
			s->next->prior=p;
			s->next=p;
			p->prior=s;
			i++;
		}
		c=getchar();
	}
	s->data=i;
}
void readlinklist(dulinklist s)
{
	dulinklist p;
	int i=s->data+1;
	p=s->prior;
	while(--i)
	{
		printf("%d",p->data);
		p=p->prior;
		if(i%4==1&&i>1)
		printf(",");
	}
}
void qiujie(dulinklist a,dulinklist &b)
{
	dulinklist pa=a->next,pb=b->next,p;
	int i=a->data,j=b->data;
	if(i>j)
	{
		while(j)
	{
		pa->data+=pb->data;
		if(pa->data>9)
		{
			pa->data%=10;
			pa->next->data++;
		}
		j--;
		pa=pa->next;
		pb=pb->next;
	}
	readlinklist(a);
	}
	else if(i<j)
	{
		while(i)
	{
		pb->data+=pa->data;
		if(pb->data>9)
		{
			pb->data%=10;
			pb->next->data++;
		}
		i--;
		pa=pa->next;
		pb=pb->next;
	}
	readlinklist(b);
	}
	else
	{
			while(j)
	{
		pb->data+=pa->data;
		if(pb->data>9)
		{
			if(j>1)
			{
				pb->data%=10;
			pb->next->data++;
			}
			else
			{
				p=(dulinklist)malloc(sizeof(dulnode));
				p->prior=pb;
				p->next=pb->next;
				pb->next->prior=p;
				pb->next=p;
				pb->data%=10;
				pb->next->data=1;
				b->data++;
			}
		}
		j--;
		pa=pa->next;
		pb=pb->next;
	}
	readlinklist(b);
	}
}
main()
{
	dulinklist a,b;
	printf("请输入第一个整数，以换行符或空格表示输入结束\n");
	input(a);
	printf("请输入第二个整数，以换行符或空格表示输入结束\n");
	input(b);
	printf("求和结果为\n");
	qiujie(a,b);

}	


