#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h> 
#define MAX 20
typedef struct tnode *Treept;
typedef struct tnode{
	char *word;
	int count;
	Treept left;
	Treept right;
} Treenode;//Treenode�Ƕ�������һ���ڵ� 
Treept nodealloc(void)
{
	return (Treept) malloc( sizeof( Treenode));
}
char *strmake( char *s)
{
	char *p;
	p = (char *) malloc( strlen(s) + 1);
	if(p != NULL) strcpy(p, s);
	return p;
}//����ռ䴢�浥�� 
Treept addtree( Treept p, char *w)
{
	int cond;
	if( p == NULL)
	{
		p = nodealloc();
		p -> word = strmake(w);
		p -> count = 1;
		p -> left = p->right = NULL;
	}
	else if((cond = strcmp(w, p-> word)) == 0) //����������洢�ڶ������ϣ��������ڲ��� 
		p -> count++;
	else if(cond < 0)
		p -> left = addtree(p -> left, w);
	else
		p -> right = addtree(p -> right, w);
	return p;
}

Treept addtree_by_count( Treept p, Treept q) 
{	
	if( p == NULL)
	{
		p = nodealloc();
		p -> word = q -> word; 
		p -> count = q -> count;
		p -> left = p -> right = NULL;
	}
	else if( (p -> count) > (q -> count))
		p -> left = addtree_by_count(p -> left, q);
	else
		p -> right = addtree_by_count(p -> right,q);
	return p;
}
Treept sorttree(Treept p, Treept q) //�����ʰ�count�ڶ��������������� 
{	
	if(q != NULL){
		p = sorttree(p, q -> left);
		p = addtree_by_count(p, q);	
		p = sorttree(p, q -> right);
	}
	return p;
}
void treeprint(Treept p)
{
	if( p!= NULL){
		treeprint(p -> left);
		printf( "%4d %s\n", p -> count, p -> word);
		treeprint(p -> right);
	}
}
void treewrite(Treept p, FILE *outcome)
{
	if( p != NULL){
		treewrite(p -> left,outcome);
		fprintf(outcome, "%s %d\n", p -> word, p -> count);
		treewrite(p -> right,outcome);
	}
}
Treept buildtree(Treept root,FILE *fp)// ��fp��ȡ���ʣ��и��������ӵ�������root�� 
{
	char c;
	char word[MAX];
	int i = 0;
	while( (c = getc(fp)) != EOF)
	{
		if(isalpha(c))
		{	
			if(isupper(c)) c = ( c - 'A' + 'a'); // if c is upper, turn it to a lower one.
			word[i] = c; 
			i++;
		}
		else if(i)
		{
			if(c == '\'')//�����д�������� 
			{
				word[i] = c;
				i++;
				c = getc(fp);
				if(isalpha(c)){
					if(isupper(c))  c - 'A' + 'a';
					word[i] = c;
					i++;
				}
				else{
					word[i - 1] = '\0';
					root = addtree(root, word);
					i = 0; 
				}
			}
			else
			{		
				word[i] = '\0';
				root = addtree(root, word);
				i = 0;
			}
		}
	}
	return root;
}		
 
