#include<stdio.h>
#include<ctype.h>
#include<string.h>


void add(void);
void delete_a(void);
void edit(void);
void search(void);
void starbar(void);
void print(void);
int com_tax(int,int,int,int);
void insert(void);

struct worker {
	int num;
	char name[10];
	char partment[10];
	int salary;
	int allowance;
	int complement;
	int insurance;
	int water;
	int tax;
	int should;
	int actual;
};

int size=sizeof(struct worker);

struct worker x[100];
int n;
FILE *fp;

int main(void)
{
	fclose(fopen("list.txt","a"));
	printf("***************************���ʹ���ϵͳ************************\n");
	starbar();
	puts("��ѡ����");
	puts("A.��������Ϣ	B.�༭������Ϣ");
	puts("C.ɾ��������Ϣ	D.��ѯ��������");
	puts("E.��ӡ��������	F.�˳�");
	puts("G.���ļ���������");
	starbar();
	char option;
	while ((option = toupper(getchar())) != NULL)
	{
		if(option=='\n')
		continue;
		switch(option)
		{
			case 'A':add();break;
			case 'B':edit();break;
			case 'C':delete_a();break;
			case 'D':search();break;
			case 'E':print();break;
			case 'F':exit(0);
			case 'G':insert();break;
			default:puts("�������������");	
		}
		starbar();
		puts("��ѡ����");
		puts("A.��������Ϣ	B.�༭������Ϣ");
		puts("C.ɾ��������Ϣ	D.��ѯ��������");
		puts("E.��ӡ��������	F.�˳�");
		puts("G.���ļ���������");
		starbar();
	}

	return 0;

}




void add(void)
{

	struct worker temp;

	fp = fopen("list.txt", "a");
	starbar();
	puts("A.�ֶ�����");
	i:puts("B.����");
	char option;
	while ((option = toupper(getchar())) != NULL)
	{
		if (option == 'B')
			{
				fclose(fp);
				break;
			}
		if(option=='\n')
			continue;
		switch (option)
		{
		case 'A': {
			a:puts("������ְ����");
			if(scanf("%d",&temp.num)!=NULL)
			fwrite(&temp.num,sizeof(int),1,fp);
			else
			{
				puts("�������");
				clear();
				goto a;
			}
			b:puts("����������");//
			if (scanf("%s", &temp.name) != NULL)
				fwrite(&temp.name,sizeof(char[10]),1,fp);
			else
			{
				puts("�������");
				clear();
				goto b;
			}
			c:puts("�����벿��");
			if (scanf("%s", &temp.partment) != NULL)
				fwrite(&temp.partment,sizeof(char[10]),1,fp);
			else
			{
				puts("�������");
				clear();
				goto c;
			}
			d:puts("�������λ����");
			if (scanf("%d", &temp.salary) != NULL&&temp.salary >= 0)
				fwrite(&temp.salary,sizeof(int),1,fp);
			else
			{
				puts("�������");
				clear();
				goto d;
			}
			  e:puts("�������λ����");
				if (scanf("%d", &temp.allowance) != NULL&&temp.allowance >= 0)
				  fwrite(&temp.allowance, sizeof(int), 1, fp);
			  else
			  {
				  puts("�������");
				  clear();
				  goto e;
			  }
				f:puts("�����벹������");
				if (scanf("%d", &temp.complement) != NULL&&temp.complement >= 0)
					fwrite(&temp.complement, sizeof(int), 1, fp);
				else
				{
					puts("�������");
					clear();
					goto f;
				}
				  g:puts("������ҽ�Ʊ���");
				  if (scanf("%d", &temp.insurance) != NULL&&temp.insurance >= 0)
					  fwrite(&temp.insurance, sizeof(int), 1, fp);
				  else
				  {
					  puts("�������");
					  clear();
					  goto g;
				  }
					h:puts("������ˮ���");
					if (scanf("%d", &temp.water) != NULL&&temp.water >= 0)
						fwrite(&temp.water, sizeof(int), 1, fp);
					else
					{
						puts("�������");
						clear();
						goto h;
					}
				clear();
				temp.tax=com_tax(temp.salary,temp.allowance,temp.complement,temp.insurance);
				fwrite(&temp.tax, sizeof(int), 1, fp);
				temp.should= temp.salary+ temp.allowance+temp.complement+ temp.insurance;
				fwrite(&temp.should, sizeof(int), 1, fp);
				temp.actual=temp.should-temp.water-temp.tax;
				fwrite(&temp.actual, sizeof(int), 1, fp);
				puts("��ӳɹ���");
				starbar();
				puts("A.��������");
				goto i;

		}
		case '\n':break;
		default:puts("�������������");
		}
	}

}


void edit(void)
{
	fp = fopen("list.txt", "r");
	rewind(fp);
	int max = fread(x, size, 100, fp);
	j:puts("��������Ҫ���ĵ�����,����#������һ���˵�");
	char name_temp[10];
	scanf("%s", &name_temp);
	clear();
	fclose(fp);
	if (strcmp(name_temp, "#")==0)
		return;
	for (int i = 0; i < max; i++)
	{
		int tf=0;
		if (strcmp(name_temp, x[i].name) == 0)
		{
			tf=1;
			puts("������ְ����");
			scanf("%d",&x[i].num);
			puts("����������");
			scanf("%s",&x[i].name);
			puts("�����벿��");
			scanf("%s",&x[i].partment);
			puts("�������λ����");
			scanf("%d",&x[i].salary);
			puts("�������λ����");
			scanf("%d",&x[i].allowance);
			puts("�����벹������");
			scanf("%d",&x[i].complement);
			puts("������ҽ�Ʊ���");
			scanf("%d",&x[i].insurance);
			puts("������ˮ���");
			scanf("%d",&x[i].water);
			x[i].tax= com_tax(x[i].salary, x[i].allowance, x[i].complement, x[i].insurance);
			x[i].should = x[i].salary + x[i].allowance + x[i].complement + x[i].insurance;
			x[i].actual = x[i].should - x[i].water - x[i].tax;
			clear();
			fp=fopen("list.txt", "w");
			for (int i = 0; i < max; i++)
			{
				if (x[i].num<0)
					continue;
				fwrite(&x[i], size, 1, fp);
			}
			puts("�޸ĳɹ�");
			starbar();
			fclose(fp);
		}
		else
			{
				if(tf==0)
				puts("�޴�Ա����Ϣ��������");
				starbar();
				goto j;
			}
	}
}


void delete_a(void)
{
	m:puts("A.ȫ�����	B.�������");
	puts("C.����");
	char option;
	while ((option = toupper(getchar())) != NULL)
	{
		if (option == '\n')
			continue;
		if(option=='C')
			break;
		else
		{
			switch (option)
				{
				case'A':fp=fopen("list.txt","w"); puts("ȫ��������"); fclose(fp); starbar(); break;
				case'B':fp = fopen("list.txt", "r");
						rewind(fp);
						int max=fread(x,size,100,fp);
						k:puts("��������Ҫɾ��������������#������һ���˵�");
						char name_temp[10];
						scanf("%s",&name_temp);
						clear();
						if (strcmp(name_temp, "#") == 0)
							goto m;
							int tf=0;
						for (int i = 0; i < max; i++)
						{
							if(strcmp(name_temp,x[i].name)==0)
							{
								x[i].num=-1;
								tf=1;
							}
						}
						fclose(fp);
						fp = fopen("list.txt", "w");
						for (int i = 0; i < max; i++)
						{
							if(x[i].num<0)
							continue;
							fwrite(&x[i],size,1,fp);
						}
						if (tf==1)
						puts("ɾ���ɹ�");
						else
						{
							puts("�޴�Ա����Ϣ��������");
							starbar();
							goto k;
						}

						starbar();
						fclose(fp);
				break;
				default:puts("�������������");
				}
		}
		puts("A.ȫ�����	B.�������");
		puts("C.����");
	}

}


void search(void)
{
	l:puts("A.���˹��ʲ�ѯ");
	puts("B.���Ź��ʲ�ѯ");
	puts("C.����");
	char option;
	while ((option = toupper(getchar())) != NULL)
	{
		if (option == 'C')
		{
			break;
		}
		if(option=='\n')
			continue;
		switch (option)
		{
			case 'A': fp = fopen("list.txt", "r");
						rewind(fp);
						int max = fread(x, size, 100, fp);
						n:puts("��������Ҫ��ѯ������,����#������һ���˵�");
						char name_temp[10];
						scanf("%s", &name_temp);
						clear();
						fclose(fp);
						int tf=0;
						if (strcmp(name_temp, "#") == 0)
							goto l;
						if(max==0)
							{
								puts("����Ա����Ϣ");
								starbar();
							}
						else
						{
							for (int i = 0; i < max; i++)
							{
								if (strcmp(name_temp, x[i].name) == 0)
								{
									tf=1;
									printf("%6s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s\n","ְ����","����","����","��λ����","��λ����","��������","ҽ�Ʊ���","ˮ���","����˰","Ӧ������","ʵ������");
									printf("%6d%10s%10s%10d%10d%10d%10d%10d%10d%10d%10d\n", x[i].num, x[i].name, x[i].partment, x[i].salary, x[i].allowance, x[i].complement, x[i].insurance, x[i].water, x[i].tax, x[i].should, x[i].actual);
								}
							}
							if (tf == 0)
							{
								puts("�޴�Ա����Ϣ��������");
								starbar();
								goto n;
							}
							starbar();
						}
						break;
						
				case'B':o:fp = fopen("list.txt", "r");
						rewind(fp);
						int max2 = fread(x, size, 100, fp);
						puts("�����벿�����ƣ�����#������һ���˵�");
						char partment_temp[10];
						scanf("%s",partment_temp);
						clear();
						fclose(fp);
						int tf2=0;
						if (strcmp(partment_temp, "#") == 0)
							goto l;
						int total = 0;
						for (int i = 0; i < max2; i++)
						{
							
							if (strcmp(partment_temp, x[i].partment) == 0)
							{
								tf2=1;
								total+=x[i].actual;
							}
						}
						if(tf2==1)
							printf("����ʵ�����ʹ���%dԪ\n",total);
						else
						{
							puts("�޴˲�����Ϣ��������");
							starbar();
							goto o;
						}
						starbar();
						break;
			}
		puts("A.���˹��ʲ�ѯ");
		puts("B.���Ź��ʲ�ѯ");
		puts("C.����");
		}
}


void print(void)
{
	char ch;
	fp = fopen("list.txt", "r");
	int tf=0;
	rewind(fp);
	int max = fread(x, size, 100, fp);
	if( max==0)
		puts("������Ϣ");
	else
		printf("%6s%10s%10s%10s%10s%10s%10s%10s%10s%10s%10s\n", "ְ����", "����", "����", "��λ����", "��λ����", "��������", "ҽ�Ʊ���", "ˮ���", "����˰", "Ӧ������", "ʵ������");
	for (int i = 0; i < max; i++)
	{
		for (int k = i+1; k < max; k++)
		{
			if(x[i].actual<x[k].actual)
			{
				struct worker temp=x[i];
				x[i]=x[k];
				x[k]=temp;
			}
		}
	}
	for (int i = 0; i < max; i++)
	{
		printf("%6d%10s%10s%10d%10d%10d%10d%10d%10d%10d%10d\n", x[i].num, x[i].name, x[i].partment, x[i].salary, x[i].allowance, x[i].complement, x[i].insurance, x[i].water, x[i].tax, x[i].should, x[i].actual);
	}
	if(max>0)
		puts("��ӡ��ɣ�");
	fclose(fp);
}


int com_tax(int a, int b, int c, int d)
{
	int total,tax;
	total=a+b+c+d;
	if(total<=800)
	tax=0;
	else if(total<=1300)
	tax=(total-800)*0.05;
	else if(total<=2800)
	tax=(total-1300)*0.1+25;
	else if(total<=5800)
	tax=(total-2800)*0.15+175;
	else if(total<=20800)
	tax=(total-5800)*0.2+625;
	else
	tax=(total-20800)*0.3;

	return tax;
}

void insert(void)
{
	FILE *fp1,*fp2;
	struct worker temp;
	fp1=fopen("insert.txt","r");
	fp2=fopen("list.txt","a+");
	while(fscanf(fp1,"%d\t%s\t%s\t%d\t%d\t%d\t%d\t%d\n", &temp.num, &temp.name, &temp.partment, &temp.salary, &temp.allowance, &temp.complement, &temp.insurance, &temp.water)!=EOF)
	{
		fwrite(&temp.num, sizeof(int), 1, fp2);
		fwrite(&temp.name,sizeof(char[10]),1,fp2);
		fwrite(&temp.partment,sizeof(char[10]),1,fp2);
		fwrite(&temp.salary,sizeof(int),1,fp2);
		fwrite(&temp.allowance,sizeof(int),1,fp2);
		fwrite(&temp.allowance,sizeof(int),1,fp2);
		fwrite(&temp.insurance,sizeof(int),1,fp2);
		fwrite(&temp.water, sizeof(int), 1, fp2);
		
		temp.tax = com_tax(temp.salary, temp.allowance, temp.complement, temp.insurance);
		fwrite(&temp.tax, sizeof(int), 1, fp2);
		temp.should = temp.salary + temp.allowance + temp.complement + temp.insurance;
		fwrite(&temp.should, sizeof(int), 1, fp2);
		temp.actual = temp.should - temp.water - temp.tax;
		fwrite(&temp.actual, sizeof(int), 1, fp2);
	}
	fclose(fp1);
	fclose(fp2);
	puts("����ɹ���");
}