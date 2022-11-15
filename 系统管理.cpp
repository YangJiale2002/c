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
	fp=fopen("C:\\Users\\admin\\Desktop\\a.txt","r");//文件路经（需根据情况更改）
	if(fp==NULL) {
		printf("error");
	} else {

		while(!feof(fp)) {
			fscanf(fp,"%d %s %f %f %f",&stu[i].number,stu[i].name,&stu[i].c_score,&stu[i].ps_score,&stu[i].sum);//格式化读取文件中的值 
			i++;//给文件中的值重新排序 
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
		fp=fopen("C:\\Users\\admin\\Desktop\\a.txt","w");//文件路经（需根据情况更改） 
		if(fp==NULL) {
			printf("error");
		} else {
			for(j=0; j<i-1; j++) {
				fprintf(fp,"%d\t %s\t %.1f\t %.1f\t %.1f\t\n",stu[j].number,stu[j].name,stu[j].c_score,stu[j].ps_score,stu[j].sum);
			}
       fclose(fp);
		}
		printf("是否继续操作（是请按对应的数字，不是请按6）");
		scanf("%d",&choice);
		if(choice==6) {
			break;
		}}
		return 0;
	}
void fristface() {
	system("cls");
	printf("********************\n");
	printf("**学生信息管理系统**\n");
	printf("********************\n");
	printf("**增加学生信息请按1*\n");
	printf("**修改学生信息请按2*\n");
	printf("**删除学生信息请按3*\n");
	printf("**查找学生信息请按4*\n");
	printf("**学生成绩排名请按5*\n");
	printf("**退出程序请按6*****");
}

void addstudent() {

	
	char T;
	printf("增加学生信息\n");
	printf("学号: 姓名：c语言成绩：ps成绩：（用空格隔开）\n");
	FILE *fp;
	fp=fopen("C:\\Users\\admin\\Desktop\\a.txt","a");//文件路经（需根据情况更改）

	if(fp==NULL) {
		printf("error");
	} else {

		while(T!='t') {
			
			scanf("%d %s %f %f",&stu[i-1].number,stu[i-1].name,&stu[i-1].c_score,&stu[i-1].ps_score);
		
			stu[i-1].sum=stu[i-1].c_score+stu[i-1].ps_score;
			fprintf(fp,"%d\t %s\t %.1f\t %.1f\t %.1f\t\n",stu[i-1].number,stu[i-1].name,stu[i-1].c_score,stu[i-1].ps_score,stu[i-1].sum);
		
			printf("如果输入t则返回菜单");
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
	printf("修改学生信息\n");
	printf("请输入要修改的学生的姓名:\n");
	scanf("%s",name);
	for(t=0; t<i-1; t++) {

		if(strcmp(stu[t].name,name)==0) {
			printf("学号\t 姓名\t c语言成绩\tps成绩\t  总分\n");
			printf("%d\t %s\t %.1f\t        %.1f\t  %.1f\t\n",stu[t].number,stu[t].name,stu[t].c_score,stu[t].ps_score,stu[t].sum);
         num=t;
		}
	}
	while(1) {
	printf("输入需要修改的信息\n") ;
	printf("修改学号请按:     1\n") ;
	printf("修改姓名请按:     2\n") ;
	printf("修改c语言成绩请按:3\n") ;
	printf("修改ps成绩请按:   4\n") ;
	printf("修改总分请按:     5\n") ;
	scanf("%d",&c);
	
		switch(c) {
			case 1:
				printf("请输入新的学号：\n") ;
				scanf("%d",&stu[num].number);
			
				break;
			case 2:
				printf("请输入新的姓名：\n");
				scanf("%s",name);
				strcpy(stu[num].name,name);
				break;
			case 3:
				printf("请输入新的c语言成绩：\n");
				scanf("%f",&stu[num].c_score);
				break;
			case 4:
				printf("请输入新的ps成绩：\n");
				scanf("%f",&stu[num].ps_score);
			
				break;
			case 5:
				printf("请输入新的总分：\n");
				scanf("%f",&stu[num].sum) ;
			
				break;

		}
		printf("是否继续进行修改（是请按对应的数字，不是请按0）");
		scanf("%d",&c);
		if(c==0) {
			break;
		}
	}
}
void deletestudent() {
	 int s,h,w,t;
	 t=i-1;
	printf("删除学生信息\n");
	printf("请输入需要删除的学生学号：") ;
	scanf("%d",&s) ;
	for(h=0;h<t;h++)
	if(s==stu[h].number)
	{for(w=h;w<t-1;w++)
	stu[w]=stu[w+1];
		
	}
	i=t-1;
	printf("删除成功"); 
}
void searchstudent() {
	int i;
	int x;
	int t=0;
	int num;
	char name[10];
	printf("查找学生信息\n");
	printf("按学号进行查找按1\n");
	printf("按姓名进行查找按2\n");
	printf("请输入查找方式：") ;

	scanf("%d",&x);
	if(x==1) {

		printf("请输入对应的学号：");
		scanf("%d",&num);
		for(i=0; i<N; i++) {

			if(stu[i].number==num) {
				printf("学号\t 姓名\t c语言成绩\tps成绩\t  总分\n");
				printf("%d\t %s\t %.1f\t        %.1f\t  %.1f\t\n",stu[i].number,stu[i].name,stu[i].c_score,stu[i].ps_score,stu[i].sum);
               t=1;
			}
		}
		if(t=0) {
			printf("无此类学号");
		}
	} else if(x==2) {
		printf("请输入对应的姓名：");
		scanf("%s",name);
		for(i=0; i<N; i++) {

			if(strcmp(stu[i].name,name)==0) {
				t=1;
				printf("学号\t 姓名\t c语言成绩\tps成绩\t  总分\n");
				printf("%d\t %s\t %.1f\t %.1f\t %.1f\t\n",stu[i].number,stu[i].name,stu[i].c_score,stu[i].ps_score,stu[i].sum);
			}
		}
		if(t=0) {
			printf("无此类姓名");
		}
	}
}


void sortstudent() {
	int q,z,j; 
	float y,t,p;
	char name[10];
	printf("学生成绩排名\n");
	printf("学号\t 姓名\t c语言成绩\tps成绩\t  总分\n");//冒泡排序法 
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
	printf("退出程序\n");
}



