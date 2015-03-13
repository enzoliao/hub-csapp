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
	char filename[MAX] = "passage.txt"; //待分析的文本 
	char saveplace[MAX] = "outcome.txt"; //分析结果保存位置 
	fp = fopen(filename,"r");
	outcome = fopen(saveplace,"w");
	if(fp != NULL)	printf("File: [%s] has been open.\n",filename); 
	else{
		printf("Wrong filename.\n");
		return 0;
	}
	root = buildtree(root, fp);// 从fp读取单词并加入到root中 
	//treeprint(root);
	count_root = sorttree(count_root, root); //对二叉树root内的节点排序，形成新的二叉树count_root 
	if(outcome != NULL)	treewrite(count_root, outcome);
	fclose(fp); 
	fclose(outcome);
	return 0; 
}
