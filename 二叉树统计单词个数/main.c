#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "tree.h" 
#define MAX 20
main()
{
	FILE *fp,*outcome;
	Treept root,count_root;
	root = count_root = NULL;
	char filename[MAX] = "passage.txt"; //���������ı� 
	char saveplace[MAX] = "outcome.txt"; //�����������λ�� 
	fp = fopen(filename,"r");
	outcome = fopen(saveplace,"w");
	if(fp != NULL)	printf("File: [%s] has been open.\n",filename); 
	else{
		printf("Wrong filename.\n");
		return 0;
	}
	root = buildtree(root, fp);// ��fp��ȡ���ʲ����뵽root�� 
	//treeprint(root);
	count_root = sorttree(count_root, root); //�Զ�����root�ڵĽڵ������γ��µĶ�����count_root 
	if(outcome != NULL)	treewrite(count_root, outcome);
	fclose(fp); 
	fclose(outcome);
	return 0; 
}
