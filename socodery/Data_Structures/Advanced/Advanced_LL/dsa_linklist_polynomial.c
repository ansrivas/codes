/******************************************************************************
keywords		:       data structures, Linklist ,polynomial operations

File Name		:       dsa_linklist_polynomial.c

Date of Creation	:       13/11/2007

Owner                   	:       Rashi Arora

Date of Modification    	:

Reason for modification 	:

Modifier                	:

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

/********************Structure Declaration *************************/
                /* structure containing a data part and link part */
typedef struct ele
{
        float coeff;
        int index;
        struct ele *next;
}node;

node *p1  = NULL;
node *p2  = NULL;
node *ans = NULL;
node *cp  = NULL;

/********************Function Declarations ***************************/
int getline(char *s, int lim); 
void deleteall(node *p);
int copy_list();
node *createlistend(node *p,float coeff,int i);
void printlist(node *p);
node *take_in(node *p,int o);
int sub_pol();
int user_in();
int add_pol(node *pol1, node*pol2, int s);
int mul_pol();

/***************Function Definitions ******************/
int getline(char *s, int lim) 
{   
       char *t;
       int c, len=lim;
       while ((c=getchar()) == EOF || c == '\n');
       t = s;
       *s++ = c;
      while (--lim>1 && (c=getchar()) != EOF && c != '\n')
            *s++ = c;
      if (c == '\n')
           *s++ = c;
      else if (lim == 1) {
           *s++ = '\n';
            fprintf(stderr, "WARNING. getline: Line too long, splitted.\n");
       }
      *s = '\0';
       return s - t;
}

void deleteall(node *p)
{
        node *current,*prev;
        while(p!=NULL)
        {
                current=p;
                if (current->next==NULL)   /*single node is there*/
                {
                        p=NULL;
                        free(current);
                }
                else
                {
                        while(current->next!=NULL)
                        {
                                prev=current;
                                current=current->next;
                        }
                        prev->next=NULL;
                        free(current);
                }
        }
 }

int copy_list()
{
        node *q,*q1;
        deleteall(cp);
        cp = NULL;
        q=cp;
        q1=ans;
        if(q1!=NULL)
        {
                cp = (node *)malloc(sizeof(node));
                cp->index=q1->index;
                cp->coeff=q1->coeff;
                q = cp;
                q1 = q1->next;
        }
        while(q1!=NULL)
        {
                q->next = (node*)malloc(sizeof(node));
                q=q->next;
                q->coeff = q1->coeff;
                q->index = q1->index;
                q->next = NULL;
                q1 = q1->next;
        }
        deleteall(ans);
        ans = NULL;
        return 0;
}

node *createlistend(node *p,float coeff,int i)
{
        node *newnode, *q;
        newnode=(node*)malloc(sizeof(node));
        newnode->coeff=coeff;
        newnode->index=i;
        newnode->next=NULL;
        if(p==NULL)
                p=newnode;
        else
        {
                q=p;
                while(q->next!=NULL)
                        q=q->next;
                q->next=newnode;
        }
        newnode=NULL;
        return p;
}

void printlist(node *p)
{
        node *q;
        float coeff;
        if(p==NULL)
        {
                printf("\nPolynomial is not entered");
        }
        else
        {
                printf("\n   ");
                if(p->coeff>0)
                        printf("\n   ");
                else
                        printf("\n  -");
                for(q=p;q!=NULL;q=q->next)
                {
                        if(q->coeff>0)
                                coeff = q->coeff;
                        else
                                coeff = 0 - q->coeff;
                        printf("%6.2f X^%d ",coeff,q->index);
                        if((q->next)!=NULL)
                                if((q->next)->coeff>0)
                                        printf("+");
                                else
                                        printf("-");
                }
        }
}    

node *take_in(node *p,int o)
{
        int i;
        float coeff;
        coeff = 0;
        //p = (node*)malloc(sizeof(node));
        p=NULL;
        i = o;
        /*if((i>-1)&&(coeff==0))
        {
                printf("                     %d",o);
                printf("\nEnter the coeff for x : ");
                scanf("%f",&coeff);
                if(coeff!=0)
                {
                        p->coeff = coeff;
                        p->index = i;
                        p->next = NULL;
                }
                i--;
        }*/
        for(;i>-1;i--)
        {
                printf("                     %d",i);
                printf("\nEnter the coeff for x : ");
                scanf("%f",&coeff);
                if(coeff!=0)
                        p = createlistend(p,coeff,i);
        }
        printlist(p);
        return p;
}



int user_in()
{
        int o1,o2;
        system("cls");
        printf("\nEnter the order of first polynomial : ");
        scanf("%d",&o1);
        deleteall(p1);
        p1 = NULL;
        p1 = take_in(p1,o1);
        printf("\nPress enter to continue \n\n\n");
        printf("\nEnter the order of second polynomial : ");
        scanf("%d",&o2);
        deleteall(p2);
        p2 = NULL;
        p2 = take_in(p2,o2);
        return 0;
}

int add_pol(node *pol1, node*pol2, int s)
{
        deleteall(ans);
        ans = NULL;
        int i=0;
        float coeff;
        node *q,*q1,*q2;
        q1 = pol1;
        q2 = pol2;
        if((q1!=NULL)&&(q2!=NULL))
        {
                if(q1->index>q2->index)
                {
                        ans = (node*)malloc(sizeof(node));
                        q = ans;
                        q->next = NULL;
                        q->coeff = q1->coeff;
                        q->index = q1->index;
                        q1=q1->next;
                }
                else if (q1->index<q2->index)
                {
                        ans = (node*)malloc(sizeof(node));
                        q = ans;
                        q->next = NULL;
                        q->coeff = s*q2->coeff;
                        q->index = q2->index;
                        q2=q2->next;
                }
                else
                {
                        coeff = q1->coeff + s*q2->coeff;
                        if(coeff!=0)
                        {
                                ans = (node*)malloc(sizeof(node));
                                q = ans;
                                q->next = NULL;
                                q->coeff = coeff;
                                q->index = q1->index;
                        }
                        q1=q1->next;
                        q2=q2->next;
                }
        }
        else if(q1!=NULL)
        {
                ans = (node*)malloc(sizeof(node));
                q = ans;
                q->next = NULL;
                q->coeff = q1->coeff;
                q->index = q1->index;
                q1=q1->next;
        }
        else if(q2!=NULL)
        {
                ans = (node*)malloc(sizeof(node));
                q = ans;
                q->next = NULL;
                q->coeff = s*q2->coeff;
                q->index = q2->index;
                q2=q2->next;
        }


        while((q1!=NULL)||(q2!=NULL))
        {
                if((q1!=NULL)&&(q2!=NULL))
                {
                        if(q1->index>q2->index)
                        {
                                q->next=(node*)malloc(sizeof(node));
                                q=q->next;
                                q->coeff = q1->coeff;
                                q->index = q1->index;
                        }
			else if (q1->index<q2->index)
                        {
                                q->next=(node*)malloc(sizeof(node));
                                q=q->next;
                                q->coeff = s*q2->coeff;
                                q->index = q2->index;
                                q2=q2->next;
                        }
                        else
                        {
                                coeff = q1->coeff + s*q2->coeff;
                                if(coeff!=0)
                                {
                                        q->next=(node*)malloc(sizeof(node));
                                        q=q->next;
                                        q->coeff = coeff;
                                        q->index = q1->index;
                                }
                                q1=q1->next;
                                q2=q2->next;
                        }
                }
                else if(q1!=NULL)
                {
                        q->next=(node*)malloc(sizeof(node));
                        q=q->next;
                        q->coeff = q1->coeff;
                        q->index = q1->index;
                        q1=q1->next;
                }
                else if(q2!=NULL)
                {
                        q->next=(node*)malloc(sizeof(node));
                        q=q->next;
                        q->coeff = s*q2->coeff;
                        q->index = q2->index;
                        q2=q2->next;
                }
        }
        if(s==-1)
        {
                printlist(pol1);
                printf("\n\n\t-\t\n\n");
                printlist(pol2);
                printf("\n\n\t=\n\n");
                if(ans!=NULL)
                        printlist(ans);
                else
                        printf("0");
        }
        return 0;
}

int sub_pol()
{
        int i=0;
        scanf("%d",&i);
        if(i==1)
                add_pol(p1,p2,-1);
        if(i==2)
                add_pol(p2,p1,-1);
        return 0;
}
int mul_pol()
{
        deleteall(ans);
        deleteall(cp);
        ans =NULL;
        cp = NULL;
        int index;
        float coeff;
        node *q,*q1,*q2,*temp;
        q1 = p1;
        q2 = p2;
        q = NULL;
        ans = NULL;
        temp = NULL;
        while(q1!=NULL)
        {
                q2 = p2;
                while(q2!=NULL)
                {
                        index = (q1->index)+(q2->index);
                        coeff = (q1->coeff)*(q2->coeff);
                        if(temp == NULL)
                        {
                                temp = (node*)malloc(sizeof(node));
                                q = temp;
                        }
                        else
                        {
                                q->next = (node*)malloc(sizeof(node));
                                q = q->next;
                        }
                        q->index = index;
                        q->coeff = coeff;
                        q2 = q2->next;
                }
                add_pol(cp,temp,1);
                deleteall(temp);
                temp = NULL;
                copy_list();
                q1 = q1->next;
        }
        printlist(p2);
        printf("\n\n\t=\n\n");
        printlist(cp);
        return 0;
}
/*********************Main Function *********************************/

int main()
{
        int i=0;
        char ch[100];
        while(i!=5)
        {
                system("cls");
                printf("\nEnter your choice : \n Press 1 to enter polynomials \n Press 2 to add polynomials \n Press 3 to subtract polynomials \n Press 4 to multiply polynomials\n Press 5 to exit \n\t\t\t\t");
                scanf("%d",&i);
                switch(i)
                {
                        case 1:
                                user_in();
                                i = 0;
                                break;
                        case 2:
                                add_pol(p1,p2,1);
                                printlist(p1);
                                printf("\n\n\t-\t\n\n");
                                printlist(p2);
                                printf("\n\n\t=\n\n");
                                i = 0;
                                if(ans!=NULL)
                                        printlist(ans);
                                else
                                        printf("0");
                                break;
                        case 3:
                                sub_pol();
                                i = 0;
                                break;
                        case 4:
                                mul_pol();
                                i = 0;
                                break;
                        case 5:
                                deleteall(p1);
                                deleteall(p2);
                                deleteall(ans);
                                deleteall(cp);
                                printf("\nExiting.........");
                                break;
                        default:
                                printf("\nInvalid choice.....");
                                i = 0;
                                break;
                }
                printf("\nStrike any key and Press Enter to continue....... \n\t\t\t\t\t");
                getline(ch,1);
                system("cls");
        }
        return 0;
}

