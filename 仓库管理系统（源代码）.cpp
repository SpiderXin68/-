#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#define LEN sizeof(shop)

typedef struct shoping {
	char barcode[20];   //编码
	char name[20];      //名字
	float price;        //价格
	int count;          //数量
	struct shoping *next;
} shop;

void welcome() {   //欢迎函数
	printf("\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *               欢迎使用仓库管理系统            *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\n \n \n \n");
}



void byebye() {   //再见函数
	printf("\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *              感谢使用仓库管理系统             *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\n \n \n \n");
}

void menu() {     //菜单函数
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *          (1) 增加货物                         *\n");
	printf("                *          (2) 删除货物                         *\n");
	printf("                *          (3) 搜索货物                         *\n");
	printf("                *          (4) 查看货物                         *\n");
	printf("                *          (5) 货物排序                         *\n");
	printf("                *          (6) 退出程序                         *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
}

shop *creat() {    //创建链表
	shop *head=(shop*)malloc(LEN);
	head->next=NULL;
	return head;
}

int add(shop *head,int j) {      //增加函数
	int n;

	printf("输入增加货物的数量：   \n");
	printf("输入0可返回菜单\n");
	scanf("%d",&n);
	if(n == 0) {
		system("cls");
		menu();
	}
	while(n--) {
		if(n<0) {
			printf("您输入的数据有误，请重新输入\n");
			break;
		}
		shop *p=head;
		shop *q=(shop*)malloc(LEN);
tp:
		printf("请输入货物编码  货物名称  货物价格 货物数量\n");
		scanf("%s %s %f %d",q->barcode,q->name,&q->price,&q->count);
		int k=1;            //      查看是否重复
		for(int i=1; i<=j; i++) {
			p=p->next;
			if(strcmp(p->barcode,q->barcode)==0 && strcmp(p->name,q->name)==0) {
				if(p->price==q->price) {
					printf("货物添加成功!!!\n");      //利用p遍历以前链表
					p->count+=q->count;
					free(q);
					k=2;
					break;
				} else {
					printf("货物添加失败\n");
					free(q);
					k=3;
					n++;
					break;
				}
			} else if(strcmp(p->barcode,q->barcode)==0 || strcmp(p->name,q->name)==0) {
				printf("货物添加失败\n");
				free(q);
				k=4;
				n++;
				break;
			}

		}
		if(k==1) {
			printf("货物添加成功\n");
			p->next=q;
			q->next=NULL;
			j++;
		}
	}
	return j;
}

void print(shop *head) {    //输出函数
	shop *p=head->next;
	while(p) {
		printf("编码:%s\t 货物名称:%s\t 货物价格:%.2f\t货物数量:%d\t\n",p->barcode,p->name,p->price,p->count);
		p=p->next;
	}
}

void search(shop *head) {        //搜索函数
	shop *p=head->next;

	printf("请输入要搜索的货物的名称:\n");
	printf("输入0可返回菜单\n");
	char name [20];
	scanf("%s",name);
	if(name == 0) {
		system("cls");
		menu();
	}
	int count =0;
	int i=1;
	while(p) {
		if(strcmp(p->name,name)==0) {
			i=1;
			printf("货物的编码为: %s\n货物的名称为：%s\n货物价格为:%.2f\n货物数量为:%d\n",p->barcode,p->name,p->price,p->count);
			break;
		} else {
			i=0;
		}
		p=p->next;
	}

	if(i==0) {
		printf("该货物不存在! ! !\n");
	}

}

void del(shop *head) {         //删除函数
	shop *p=head;
	shop *q=p->next;
	printf("请输入要删除货物的编码:\n");
	printf("输入0可返回菜单\n");
	char del_barcode[20];
	scanf("%s",del_barcode);
	int i=1;
	while(q) {
		if(strcmp(q->barcode,del_barcode)==0) {
			p->next=q->next;
			free(q);
			printf("删除成功!\n");
			i=1;
			break;
		} else {
			p=p->next;
			q=q->next;
			i=0;
		}
	}
	p=p->next;  //
	if(i==0) {
		printf("未找到该货物的编码,删除失败 ! ! !\n");
	}
	if(del_barcode == 0) {
		system("cls");
		menu();
	}
}

void sort(shop *head) { //排序
	int temp;
	char temp_[20];
	float _temp;
	shop *q = head->next;
	shop *p = head->next;
	shop *cur = head->next;
	shop *tail = head;   //标记尾端指针
	while(tail != NULL) {
		tail=tail->next;    //tail为尾节点
	}
	int n;
	printf("输入1按价格排序*******输入2按数量排序\n");
	printf("输入0可返回菜单\n");
	char scan[200];
	while(1) {
		scanf("%s",scan);

		if(scan[0] >= '0' && scan[1] <= '9') {
			if(scan[1] == '\0') {
				break;
			}
		}
		printf("输入指令错误!!!从新输入!!!\n");
	}
	switch(scan[0]) {
		case '1':
			while(p->next != tail) {
				if(scan == 0) {
					system("cls");
					menu();
				}
				cur = head->next;
				while(cur->next != tail) {
					if(cur->price>cur->next->price) {
						//交换
						strcpy(temp_,cur->barcode);
						strcpy(cur->barcode,cur->next->barcode);
						strcpy(cur->next->barcode,temp_);      //交换条形码
						strcpy(temp_,cur->name);
						strcpy(cur->name,cur->next->name);      //交换商品名称
						strcpy(cur->next->name,temp_);
						temp = cur->count,
						cur->count = cur->next->count;   //交换商品数量
						cur->next->count = temp;
						_temp = cur->price;
						cur->price = cur->next->price;   //交换商品价格
						cur->next->price = _temp;
					}
					cur = cur->next;
				}
				tail = cur;

			}
			printf("排序成功!!!\n");
			while(p) {
				printf("货物的编码为: %s\t货物的名称为：%s\t货物价格为:%.2f\t货物数量为:%d\t\n",p->barcode,p->name,p->price,p->count);
				p = p->next;
			}
			break;
		case '2':
			while(p->next != tail) {
				cur = head->next;
				while(cur->next != tail) {
					if(cur->count>cur->next->count) {             //交换
						strcpy(temp_,cur->barcode);
						strcpy(cur->barcode,cur->next->barcode);
						strcpy(cur->next->barcode,temp_);
						strcpy(temp_,cur->name);
						strcpy(cur->name,cur->next->name);
						strcpy(cur->next->name,temp_);
						temp = cur->count,
						cur->count = cur->next->count;
						cur->next->count = temp;
						_temp = cur->price;
						cur->price = cur->next->price;
						cur->next->price = _temp;
					}
					cur = cur->next;
				}
				tail = cur;
			}
			printf("排序成功!!!\n");
			while(p) {
				printf("货物的编码为: %s\t货物的名称为：%s\t货物价格为:%.2f\t货物数量为:%d\t\n",p->barcode,p->name,p->price,p->count);
				p = p->next;
			}
			break;
		default:
			printf("输入的指令不正确，请重新输入!!!\n");
			break;
	}
}

int main() {
	
	shop *head=creat();
	shop *p=head;
	int i=1;
	while(i) {
		system("pause");
		system("cls");
		menu();
		printf("                          请输入数字 以实现对应的功能:\n");
		scanf("%d",&i);
		if(i==0) {
			printf("输入错误，请重新输入！\n");
			system("pause");
			fflush(stdin);
			continue;
		}
		switch(i) {
			case 1:
				int k;
				static int j;
				k=add( p , j );
				j=k;
				break;              //增加货物
			case 2:
				del(p);
				break;             //删除货物
			case 3:
				search(p);
				break;             //搜索货物
			case 4:
				print(p);
				break;                                     //查看所有货物
			case 5:
				sort(p);                          //对保存的货物进行排序
				break;
			case 6:
				system("cls");
				byebye();  //再见
				exit(1);
				break;
			default:
				printf("输入的指令不正确，请重新输入!!!\n");
				break;
		}
	}
	}
