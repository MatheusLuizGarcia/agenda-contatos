#include<stdio.h>
#include <assert.h>
#include <string.h>

#define LEN(arr) (sizeof (arr) / sizeof (arr)[0])
#define APAR(arr) (arr), LEN(arr)

enum TipoContato {
    PESSOAL,
    TRABALHO
};
typedef struct {
    int cdCadastro;
    char nome[50];
    long telefone;
    int tipoContato;
} Contato;


Contato Contatos[99];
int operacao = 0;

void cadastroContato(){
    int cont = 0;
    while(cont == 0){
        int listaCheia = 1;
        int indexDisponivel = 0;
        while(listaCheia == 1){
            for(int i = 0; i < 99; i++){
                if(Contatos[i].cdCadastro == 0){
                    listaCheia = 0;
                    indexDisponivel = i;
                }
            }
        }
        if(listaCheia == 1){
            printf("\nLista de contatos está cheia, exclua um contato ou reinicie o programa!:\n");
        }
        else{
            
            printf("----------------------------------\n");
            printf("\nCadastro de contato:\n");
            printf("\nInsira o nome para o contato:\n");
            scanf("%s",&Contatos[indexDisponivel].nome);
            printf("\nInsira o numero para o contato:\n");
            scanf("%ld",&Contatos[indexDisponivel].telefone);
            printf("\nInforme o tipo de contato:\n");
            printf("1 - Pessoal\n");
            printf("2 - Trabalho\n");
            scanf("%hu",&Contatos[indexDisponivel].tipoContato);
            Contatos[indexDisponivel].cdCadastro = indexDisponivel + 1;                        
        }   
    }
}

void excluirContato(){
    
}
void visualizarContatos(){
    
}
void sair(){
    printf("\nObrigado por utilizar a agenda de contatos!\n");
}


void escolherOperacao(){
    int continua = 0; 
    while(continua == 0){
        printf("----------------------------------\n");
        printf("Selecione uma operação:\n\n");
        printf("1 - Cadastrar novo contato\n");
        printf("2 - Visualizar contatos\n");
        printf("3 - Excluir contato:\n");
        printf("4 - Sair do programa:\n");
        printf("----------------------------------\n");
        scanf("%d",&operacao);
        switch (operacao)
        {
        case 1:
            cadastroContato();
            break;
        case 2:
            visualizarContatos();
            break;
        case 3:
            excluirContato();
            break;#include<stdio.h>
#include <assert.h>
#include <string.h>

#define LEN(arr) (sizeof (arr) / sizeof (arr)[0])
#define APAR(arr) (arr), LEN(arr)

enum TipoContato {
    PESSOAL,
    TRABALHO
};
typedef struct {
    int cdCadastro;
    char nome[50];
    long telefone;
    int tipoContato;
} Contato;


Contato Contatos[99];
int operacao = 0;

void cadastroContato(){
    int cont = 0;
    while(cont == 0){
        int listaCheia = 1;
        int indexDisponivel = 0;
        while(listaCheia == 1){
            for(int i = 0; i < 99; i++){
                if(Contatos[i].cdCadastro == 0){
                    listaCheia = 0;
                    indexDisponivel = i;
                }
            }
        }
        if(listaCheia == 1){
            printf("\nLista de contatos está cheia, exclua um contato ou reinicie o programa!:\n");
        }
        else{
            
            printf("----------------------------------\n");
            printf("\nCadastro de contato:\n");
            printf("\nInsira o nome para o contato:\n");
            scanf("%s",&Contatos[indexDisponivel].nome);
            printf("\nInsira o numero para o contato:\n");
            scanf("%ld",&Contatos[indexDisponivel].telefone);
            printf("\nInforme o tipo de contato:\n");
            printf("1 - Pessoal\n");
            printf("2 - Trabalho\n");
            scanf("%hu",&Contatos[indexDisponivel].tipoContato);
            Contatos[indexDisponivel].cdCadastro = indexDisponivel + 1;                        
        }   
    }
}

void excluirContato(){
    
}
void visualizarContatos(){
    
}
void sair(){
    printf("\nObrigado por utilizar a agenda de contatos!\n");
}


void escolherOperacao(){
    int continua = 0; 
    while(continua == 0){
        printf("----------------------------------\n");
        printf("Selecione uma operação:\n\n");
        printf("1 - Cadastrar novo contato\n");
        printf("2 - Visualizar contatos\n");
        printf("3 - Excluir contato:\n");
        printf("4 - Sair do programa:\n");
        printf("----------------------------------\n");
        scanf("%d",&operacao);
        switch (operacao)
        {
        case 1:
            cadastroContato();
            break;
        case 2:
            visualizarContatos();
            break;
        case 3:
            excluirContato();
            break;
        case 4:
            sair();
            return;
            break;
        default:
            printf("\nOperação inválida, tente novamente!\n");
            break;
        }
        printf("\nDeseja realizar outra operação?\n");
        printf("1 - Sim\n");
        printf("2 - Não\n");
        scanf("%d",&operacao);
        if(operacao == 2){
            continua = 1;
        }
        sair();
    }
}
void main(){
    printf("----------------------------------\n");
    printf("\nSeja bem vindo a agenda de contatos\n");
    printf("\nDesenvolvido por Matheus Luiz Garcia\n");
    printf("----------------------------------\n");
    escolherOperacao();
}
        case 4:
            sair();
            return;
            break;
        default:
            printf("\nOperação inválida, tente novamente!\n");
            break;
        }
        printf("\nDeseja realizar outra operação?\n");
        printf("1 - Sim\n");
        printf("2 - Não\n");
        scanf("%d",&operacao);
        if(operacao == 2){
            continua = 1;
        }
        sair();
    }
}
void main(){
    printf("----------------------------------\n");
    printf("\nSeja bem vindo a agenda de contatos\n");
    printf("\nDesenvolvido por Matheus Luiz Garcia\n");
    printf("----------------------------------\n");
    escolherOperacao();
}
