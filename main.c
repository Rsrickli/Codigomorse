#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <malloc.h>
#include <locale.h>

struct arv
{
    int info;
    struct arv *dir;
    struct arv *esq;
};

typedef struct arv *ptarv;

ptarv getnode()
{
    ptarv p;
    p=(ptarv)malloc(sizeof(struct arv));
    return p;
}

ptarv criar(int x)
{
    ptarv p;
    p=getnode();
    p->info=x;
    p->dir=NULL;
    p->esq=NULL;
}

void letra(int x){
    switch(x){
        case 1 :
           printf("h");
           break;
        case 2 :
           printf("s");
           break;
        case 3 :
           printf("v");
           break;
        case 4 :
           printf("f");
           break;
        case 5 :
           printf("i");
           break;
        case 6 :
           printf("u");
           break;
        case 7 :
           printf("e");
           break;
        case 8 :
           printf("l");
           break;
        case 9 :
           printf("r");
           break;
        case 10 :
           printf("a");
           break;
        case 11 :
           printf("p");
           break;
        case 12 :
           printf("w");
           break;
        case 13 :
           printf("j");
           break;
        case 14 :
           printf(" ");
           break;
        case 15 :
           printf("b");
           break;
        case 16 :
           printf("d");
           break;
        case 17 :
           printf("x");
           break;
        case 18 :
           printf("n");
           break;
        case 19 :
           printf("c");
           break;
        case 20 :
           printf("k");
           break;
        case 21 :
           printf("y");
           break;
        case 22 :
           printf("t");
           break;
        case 23 :
           printf("z");
           break;
        case 24 :
           printf("g");
           break;
        case 25 :
           printf("q");
           break;
        case 26 :
           printf("m");
           break;
        case 27 :
           printf("o");
           break;

    }
}
int numero (char x){
    int h=14;
    switch(x){
        case 'h' :
           h=1;
           break;
        case 's' :
           h= 2;
           break;
        case 'v' :
           h= 3;
           break;
        case 'f' :
           h= 4;
           break;
        case 'i' :
           h= 5;
           break;
        case 'u' :
           h= 6;
           break;
        case 'e' :
           h= 7;
           break;
        case 'l' :
           h= 8;
           break;
        case 'r' :
           h= 9;
           break;
        case 'a' :
           h= 10;
           break;
        case 'p' :
           h= 11;
           break;
        case 'w' :
           h= 12;
           break;
        case 'j' :
           h= 13;
           break;
        case '/':
           return 14;
           break;
        case 'b' :
           h= 15;
           break;
        case 'd' :
           h= 16;
           break;
        case 'x' :
           h= 17;
           break;
        case 'n' :
           h= 18;
           break;
        case 'c' :
           h= 19;
           break;
        case 'k' :
           h= 20;
           break;
        case 'y' :
           h= 21;
           break;
        case 't' :
           h= 22;
           break;
        case 'z' :
           h= 23;
           break;
        case 'g' :
           h= 24;
           break;
        case 'q' :
           h= 25;
           break;
        case 'm' :
           h= 26;
           break;
        case 'o' :
           h= 27;
           break;

    }
    return h;
}

void criafesq(ptarv p,int x)
{
    ptarv f;
    f=criar(x);
    p->esq=f;
}

void criafdir(ptarv p,int y)
{
    ptarv f;
    f=criar(y);
    p->dir=f;
}

void imprimir_inordem(ptarv a)
{

    if(a!=NULL)
    {
        imprimir_inordem(a->esq);
        printf("%d ",a->info);
        imprimir_inordem(a->dir);
    }

}

void imprimir_posordem(ptarv a)
{

    if(a!=NULL)
    {
        imprimir_posordem(a->esq);
        imprimir_posordem(a->dir);
        printf("%d ",a->info);
    }

}

void imprimir_preordem(ptarv a)
{

    if(a!=NULL)
    {
        printf("%d ",a->info);
        imprimir_preordem(a->esq);
        imprimir_preordem(a->dir);
    }

}
void busca(ptarv p,int x){

    if(p!=NULL){
        if(x==p->info){
        }
        if(x<p->info){
            printf(".");
            busca(p->esq,x);
        }
        if(x>p->info){
            printf("-");
            busca(p->dir,x);
        }
    }
}

void carregarv(ptarv p, int x){

  if(x<p->info){
      if(p->esq==NULL){
          criafesq(p,x);
      }else{
          carregarv(p->esq, x);
      }
  }else{
      if(p->dir==NULL){
          criafdir(p,x);
      }else{
          carregarv(p->dir, x);
      }
  }
}

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int opt=0;
    ptarv p;
    FILE *fp,*fq;
    int num;
    ptarv y;
    char c,ch;
    float aux[26]={7,22,5,10,18,26,2,6,9,12,16,20,24,27,1,3,4,8,11,13,15,17,19,21,23,25};
    //printf(" \n Criar arvore,\n digite a raiz :\n");
    //scanf("%f",&x);
    p=criar(14);
    system("CLS");
    for(int i=0;i<26;i++){
    carregarv(p,aux[i]);
    }
    printf("\n Raiz = %d ",p->info);
    do
    {
        printf("\n\n=====================================================================================\n\n");
        printf("\n Digite a opcao desejada :");
        printf("\n 1- arquivo txt :");
        printf("\n 2- pre_ordem :");
        printf("\n 3- codificar txt :");
        printf("\n 0- sair :\n");
        scanf("%d",&opt);
        printf("\n\n===================================================================================== \n\n");
        switch(opt)
        {
        case 1:
            printf("\n ler aquivo txt:\n");
            if((fq = fopen("codg.txt","r"))==NULL){
                printf("Erro: fopen");
                exit(EXIT_FAILURE);
    	}

    	y=p;

    do{
    	ch=fgetc(fq);

    	if((ch == '.')){
    		y=y->esq;

    	}

    	if((ch=='-')){

    		y=y->dir;
    	}

    	if((ch=='/')){
    		printf(" ");

    	}
    	if((ch ==' ')||(ch == EOF)){
    		if(y->info != 'n' )
                letra(y->info);

    		y=p;
    	}

    }while(ch!= EOF);
    fclose(fq);

            break;
        case 2:
            printf("\n pre_ordem : ");
            imprimir_preordem(p);
            break;
        case 3:

            fp = fopen("frase.txt","r");
                if(fp == NULL) {
                    perror("Error in opening file");
                    return(-1);
                } do {
                    c = fgetc(fp);
                    num=numero(c);
                    busca(p,num);
                    printf(" ");
                if( feof(fp) ) {
                        break ;
                    }
                } while(1);

                    fclose(fp);
            break;
        case 0:
            break;

        }
    }while(opt!=0);

    return 0;
}
