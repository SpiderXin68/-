#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>
#define LEN sizeof(shop)

typedef struct shoping {
	char barcode[20];   //����
	char name[20];      //����
	float price;        //�۸�
	int count;          //����
	struct shoping *next;
} shop;

void welcome() {   //��ӭ����
	printf("\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *               ��ӭʹ�òֿ����ϵͳ            *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\n \n \n \n");
}



void byebye() {   //�ټ�����
	printf("\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *              ��лʹ�òֿ����ϵͳ             *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("\n \n \n \n");
}

void menu() {     //�˵�����
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                *          (1) ���ӻ���                         *\n");
	printf("                *          (2) ɾ������                         *\n");
	printf("                *          (3) ��������                         *\n");
	printf("                *          (4) �鿴����                         *\n");
	printf("                *          (5) ��������                         *\n");
	printf("                *          (6) �˳�����                         *\n");
	printf("                *                                               *\n");
	printf("                *                                               *\n");
	printf("                * * * * * * * * * * * * * * * * * * * * * * * * *\n");
}

shop *creat() {    //��������
	shop *head=(shop*)malloc(LEN);
	head->next=NULL;
	return head;
}

int add(shop *head,int j) {      //���Ӻ���
	int n;

	printf("�������ӻ����������   \n");
	printf("����0�ɷ��ز˵�\n");
	scanf("%d",&n);
	if(n == 0) {
		system("cls");
		menu();
	}
	while(n--) {
		if(n<0) {
			printf("�������������������������\n");
			break;
		}
		shop *p=head;
		shop *q=(shop*)malloc(LEN);
tp:
		printf("������������  ��������  ����۸� ��������\n");
		scanf("%s %s %f %d",q->barcode,q->name,&q->price,&q->count);
		int k=1;            //      �鿴�Ƿ��ظ�
		for(int i=1; i<=j; i++) {
			p=p->next;
			if(strcmp(p->barcode,q->barcode)==0 && strcmp(p->name,q->name)==0) {
				if(p->price==q->price) {
					printf("������ӳɹ�!!!\n");      //����p������ǰ����
					p->count+=q->count;
					free(q);
					k=2;
					break;
				} else {
					printf("�������ʧ��\n");
					free(q);
					k=3;
					n++;
					break;
				}
			} else if(strcmp(p->barcode,q->barcode)==0 || strcmp(p->name,q->name)==0) {
				printf("�������ʧ��\n");
				free(q);
				k=4;
				n++;
				break;
			}

		}
		if(k==1) {
			printf("������ӳɹ�\n");
			p->next=q;
			q->next=NULL;
			j++;
		}
	}
	return j;
}

void print(shop *head) {    //�������
	shop *p=head->next;
	while(p) {
		printf("����:%s\t ��������:%s\t ����۸�:%.2f\t��������:%d\t\n",p->barcode,p->name,p->price,p->count);
		p=p->next;
	}
}

void search(shop *head) {        //��������
	shop *p=head->next;

	printf("������Ҫ�����Ļ��������:\n");
	printf("����0�ɷ��ز˵�\n");
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
			printf("����ı���Ϊ: %s\n���������Ϊ��%s\n����۸�Ϊ:%.2f\n��������Ϊ:%d\n",p->barcode,p->name,p->price,p->count);
			break;
		} else {
			i=0;
		}
		p=p->next;
	}

	if(i==0) {
		printf("�û��ﲻ����! ! !\n");
	}

}

void del(shop *head) {         //ɾ������
	shop *p=head;
	shop *q=p->next;
	printf("������Ҫɾ������ı���:\n");
	printf("����0�ɷ��ز˵�\n");
	char del_barcode[20];
	scanf("%s",del_barcode);
	int i=1;
	while(q) {
		if(strcmp(q->barcode,del_barcode)==0) {
			p->next=q->next;
			free(q);
			printf("ɾ���ɹ�!\n");
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
		printf("δ�ҵ��û���ı���,ɾ��ʧ�� ! ! !\n");
	}
	if(del_barcode == 0) {
		system("cls");
		menu();
	}
}

void sort(shop *head) { //����
	int temp;
	char temp_[20];
	float _temp;
	shop *q = head->next;
	shop *p = head->next;
	shop *cur = head->next;
	shop *tail = head;   //���β��ָ��
	while(tail != NULL) {
		tail=tail->next;    //tailΪβ�ڵ�
	}
	int n;
	printf("����1���۸�����*******����2����������\n");
	printf("����0�ɷ��ز˵�\n");
	char scan[200];
	while(1) {
		scanf("%s",scan);

		if(scan[0] >= '0' && scan[1] <= '9') {
			if(scan[1] == '\0') {
				break;
			}
		}
		printf("����ָ�����!!!��������!!!\n");
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
						//����
						strcpy(temp_,cur->barcode);
						strcpy(cur->barcode,cur->next->barcode);
						strcpy(cur->next->barcode,temp_);      //����������
						strcpy(temp_,cur->name);
						strcpy(cur->name,cur->next->name);      //������Ʒ����
						strcpy(cur->next->name,temp_);
						temp = cur->count,
						cur->count = cur->next->count;   //������Ʒ����
						cur->next->count = temp;
						_temp = cur->price;
						cur->price = cur->next->price;   //������Ʒ�۸�
						cur->next->price = _temp;
					}
					cur = cur->next;
				}
				tail = cur;

			}
			printf("����ɹ�!!!\n");
			while(p) {
				printf("����ı���Ϊ: %s\t���������Ϊ��%s\t����۸�Ϊ:%.2f\t��������Ϊ:%d\t\n",p->barcode,p->name,p->price,p->count);
				p = p->next;
			}
			break;
		case '2':
			while(p->next != tail) {
				cur = head->next;
				while(cur->next != tail) {
					if(cur->count>cur->next->count) {             //����
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
			printf("����ɹ�!!!\n");
			while(p) {
				printf("����ı���Ϊ: %s\t���������Ϊ��%s\t����۸�Ϊ:%.2f\t��������Ϊ:%d\t\n",p->barcode,p->name,p->price,p->count);
				p = p->next;
			}
			break;
		default:
			printf("�����ָ���ȷ������������!!!\n");
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
		printf("                          ���������� ��ʵ�ֶ�Ӧ�Ĺ���:\n");
		scanf("%d",&i);
		if(i==0) {
			printf("����������������룡\n");
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
				break;              //���ӻ���
			case 2:
				del(p);
				break;             //ɾ������
			case 3:
				search(p);
				break;             //��������
			case 4:
				print(p);
				break;                                     //�鿴���л���
			case 5:
				sort(p);                          //�Ա���Ļ����������
				break;
			case 6:
				system("cls");
				byebye();  //�ټ�
				exit(1);
				break;
			default:
				printf("�����ָ���ȷ������������!!!\n");
				break;
		}
	}
	}
