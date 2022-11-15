#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#define N 100
struct student {
	int number;
	char name[10];
	float c_score;
	float ps_score;
	float sum;
};
struct student stu[N];
void fristface();
void addstudent();
void fixstudent();
void deletestudent();
void searchstudent();
void sortstudent();
void out();
int i=0;


main() {
	int j=0;
	FILE *fp;
	fp=fopen("C:\\Users\\admin\\Desktop\\a.txt","r");//�ļ�·���������������ģ�
	if(fp==NULL) {
		printf("error");
	} else {

		while(!feof(fp)) {
			fscanf(fp,"%d %s %f %f %f",&stu[i].number,stu[i].name,&stu[i].c_score,&stu[i].ps_score,&stu[i].sum);//��ʽ����ȡ�ļ��е�ֵ 
			i++;//���ļ��е�ֵ�������� 
		}

		fclose(fp);
	}
	int choice;
	fristface();
	
	scanf("%d",&choice);

	while(1) {
		switch(choice) {
			case 1:
				addstudent();
				break;
			case 2:
				fixstudent();
				break;
			case 3:
				deletestudent();
				break;
			case 4:
				searchstudent();
				break;
			case 5:
				sortstudent();
				break;
			case 6:
				out();
				break;
		}
		FILE *fp;
		fp=fopen("C:\\Users\\admin\\Desktop\\a.txt","w");//�ļ�·���������������ģ� 
		if(fp==NULL) {
			printf("error");
		} else {
			for(j=0; j<i-1; j++) {
				fprintf(fp,"%d\t %s\t %.1f\t %.1f\t %.1f\t\n",stu[j].number,stu[j].name,stu[j].c_score,stu[j].ps_score,stu[j].sum);
			}
       fclose(fp);
		}
		printf("�Ƿ�������������밴��Ӧ�����֣������밴6��");
		scanf("%d",&choice);
		if(choice==6) {
			break;
		}}
		return 0;
	}
void fristface() {
	system("cls");
	printf("********************\n");
	printf("**ѧ����Ϣ����ϵͳ**\n");
	printf("********************\n");
	printf("**����ѧ����Ϣ�밴1*\n");
	printf("**�޸�ѧ����Ϣ�밴2*\n");
	printf("**ɾ��ѧ����Ϣ�밴3*\n");
	printf("**����ѧ����Ϣ�밴4*\n");
	printf("**ѧ���ɼ������밴5*\n");
	printf("**�˳������밴6*****");
}

void addstudent() {

	
	char T;
	printf("����ѧ����Ϣ\n");
	printf("ѧ��: ������c���Գɼ���ps�ɼ������ÿո������\n");
	FILE *fp;
	fp=fopen("C:\\Users\\admin\\Desktop\\a.txt","a");//�ļ�·���������������ģ�

	if(fp==NULL) {
		printf("error");
	} else {

		while(T!='t') {
			
			scanf("%d %s %f %f",&stu[i-1].number,stu[i-1].name,&stu[i-1].c_score,&stu[i-1].ps_score);
		
			stu[i-1].sum=stu[i-1].c_score+stu[i-1].ps_score;
			fprintf(fp,"%d\t %s\t %.1f\t %.1f\t %.1f\t\n",stu[i-1].number,stu[i-1].name,stu[i-1].c_score,stu[i-1].ps_score,stu[i-1].sum);
		
			printf("�������t�򷵻ز˵�");
			scanf("%c",&T);
			T=getchar() ;
				i++;
		}
		fclose(fp);
	}

}
void fixstudent() {
	int t;
	int c;
	int num;
	char name[5] ;
	float c_score,ps_score,sum;
	printf("�޸�ѧ����Ϣ\n");
	printf("������Ҫ�޸ĵ�ѧ��������:\n");
	scanf("%s",name);
	for(t=0; t<i-1; t++) {

		if(strcmp(stu[t].name,name)==0) {
			printf("ѧ��\t ����\t c���Գɼ�\tps�ɼ�\t  �ܷ�\n");
			printf("%d\t %s\t %.1f\t        %.1f\t  %.1f\t\n",stu[t].number,stu[t].name,stu[t].c_score,stu[t].ps_score,stu[t].sum);
         num=t;
		}
	}
	while(1) {
	printf("������Ҫ�޸ĵ���Ϣ\n") ;
	printf("�޸�ѧ���밴:     1\n") ;
	printf("�޸������밴:     2\n") ;
	printf("�޸�c���Գɼ��밴:3\n") ;
	printf("�޸�ps�ɼ��밴:   4\n") ;
	printf("�޸��ܷ��밴:     5\n") ;
	scanf("%d",&c);
	
		switch(c) {
			case 1:
				printf("�������µ�ѧ�ţ�\n") ;
				scanf("%d",&stu[num].number);
			
				break;
			case 2:
				printf("�������µ�������\n");
				scanf("%s",name);
				strcpy(stu[num].name,name);
				break;
			case 3:
				printf("�������µ�c���Գɼ���\n");
				scanf("%f",&stu[num].c_score);
				break;
			case 4:
				printf("�������µ�ps�ɼ���\n");
				scanf("%f",&stu[num].ps_score);
			
				break;
			case 5:
				printf("�������µ��ܷ֣�\n");
				scanf("%f",&stu[num].sum) ;
			
				break;

		}
		printf("�Ƿ���������޸ģ����밴��Ӧ�����֣������밴0��");
		scanf("%d",&c);
		if(c==0) {
			break;
		}
	}
}
void deletestudent() {
	 int s,h,w,t;
	 t=i-1;
	printf("ɾ��ѧ����Ϣ\n");
	printf("��������Ҫɾ����ѧ��ѧ�ţ�") ;
	scanf("%d",&s) ;
	for(h=0;h<t;h++)
	if(s==stu[h].number)
	{for(w=h;w<t-1;w++)
	stu[w]=stu[w+1];
		
	}
	i=t-1;
	printf("ɾ���ɹ�"); 
}
void searchstudent() {
	int i;
	int x;
	int t=0;
	int num;
	char name[10];
	printf("����ѧ����Ϣ\n");
	printf("��ѧ�Ž��в��Ұ�1\n");
	printf("���������в��Ұ�2\n");
	printf("��������ҷ�ʽ��") ;

	scanf("%d",&x);
	if(x==1) {

		printf("�������Ӧ��ѧ�ţ�");
		scanf("%d",&num);
		for(i=0; i<N; i++) {

			if(stu[i].number==num) {
				printf("ѧ��\t ����\t c���Գɼ�\tps�ɼ�\t  �ܷ�\n");
				printf("%d\t %s\t %.1f\t        %.1f\t  %.1f\t\n",stu[i].number,stu[i].name,stu[i].c_score,stu[i].ps_score,stu[i].sum);
               t=1;
			}
		}
		if(t=0) {
			printf("�޴���ѧ��");
		}
	} else if(x==2) {
		printf("�������Ӧ��������");
		scanf("%s",name);
		for(i=0; i<N; i++) {

			if(strcmp(stu[i].name,name)==0) {
				t=1;
				printf("ѧ��\t ����\t c���Գɼ�\tps�ɼ�\t  �ܷ�\n");
				printf("%d\t %s\t %.1f\t %.1f\t %.1f\t\n",stu[i].number,stu[i].name,stu[i].c_score,stu[i].ps_score,stu[i].sum);
			}
		}
		if(t=0) {
			printf("�޴�������");
		}
	}
}


void sortstudent() {
	int q,z,j; 
	float y,t,p;
	char name[10];
	printf("ѧ���ɼ�����\n");
	printf("ѧ��\t ����\t c���Գɼ�\tps�ɼ�\t  �ܷ�\n");//ð������ 
	for(q=0;q<i-1;q++)
	{for(z=0;z<i-1-q;z++)
	if(stu[z].sum>stu[z+1].sum)
	{y=stu[z].sum;
	stu[z].sum=stu[z+1].sum;
	stu[z+1].sum=y;
	
	j=stu[z].number;
	stu[z].number=stu[z+1].number;
	stu[z+1].number=j;
	
	t=stu[z].c_score;
	stu[z].c_score=stu[z+1].c_score;
	stu[z+1].c_score=t;
	
	p=stu[z].ps_score;
	stu[z].ps_score=stu[z+1].ps_score;
	stu[z+1].ps_score=p;
	
	strcpy(name,stu[z].name);
	strcpy(stu[z].name,stu[z+1].name);
	strcpy(stu[z+1].name,name);}
	
    printf("%d\t %s\t %.1f\t        %.1f\t  %.1f\t\n",stu[z].number,stu[z].name,stu[z].c_score,stu[z].ps_score,stu[z].sum);
	} 
}
void out() {
	printf("�˳�����\n");
}



