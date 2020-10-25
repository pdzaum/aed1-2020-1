#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct registro
{
    char nome[100];
    char raca[50];
    char alinhamento[50];
    char Elemeristicas[100];
    char talentos[100];
    char ideais[100];
    char vinculos[100];
    char personalidade[100];
    char proficiencia[100];
    char idiomas[100];
    char habilidades[100];
    int xp;
};

struct elemento
{
    struct registro dados;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento *Personagem;

Personagem *cria_personagem();
int inserir_nome(Personagem *p,char *nome);
int inserir_raca(Personagem *p,char *raca);
int inserir_alinhamento(Personagem *p,char *alinhamento);
int inserir_caracteristicas(Personagem *p,char *caracteristicas);
int inserir_talentos(Personagem *p,char *talentos);
int inserir_ideais(Personagem *p,char *ideais);
int inserir_vinculos(Personagem *p,char *vinculos);
int inserir_personalidade(Personagem *p,char *personalidade);
int inserir_proficiencia(Personagem *p,char *proficiencia);
int inserir_idiomas(Personagem *p,char *idiomas);
int inserir_habilidades(Personagem *p,char *habilidades);
int inserir_xp(Personagem *p,int xp);
void libera(Personagem *p);
void imprime(Personagem *p);

Personagem *cria_personagem()
{
    Personagem *p = (Personagem*)malloc(sizeof(Personagem));
    if(p != NULL)
    {
        *p = NULL;
    }
    return p;
}
int inserir_nome(Personagem *p, char *nome)
{
    if(p==NULL)
    {
        return 0;
    }
    Elem *no;
    no = (Elem*)malloc(sizeof(Elem));
    if(no == NULL)
    {
        return 0;
    }
    strcpy(no->dados.nome,nome);
    no->prox = NULL;
    if((*p)==NULL)
    {
        *p = no;
    }
    else
    {
        Elem *aux;
        aux = *p;
        while(aux->prox !=NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}
void libera(Personagem *p)
{
    if(p!=NULL)
    {
        Elem *no;
        while((*p)!=NULL)
        {
            no = *p;
            *p = (*p)->prox;
            free(no);
        }
        free(p);
    }
}
void imprime(Personagem *p)
{
    if(p==NULL)
    {
        return;
    }
    Elem *no = *p;
    while(no!=NULL)
    {
        printf("O seu personagem se chama %s",no->dados.nome);
        no = no->prox;
    }
}
int main()
{
    struct registro al;
    Personagem *p = cria_personagem();
    char nome[100];
    printf("Digite o nome do personagem\n");
    fgets(nome,100,stdin);
    inserir_nome(p,nome);
    imprime(p);
    return 0;
}