#include<stdio.h>
#include <assert.h>
#include <string.h>

#define LEN(arr) (sizeof (arr) / sizeof (arr)[0])
#define APAR(arr) (arr), LEN(arr)

typedef enum {
    PESSOAL = 1,
    TRABALHO = 2
} TipoContato;

typedef struct {
    int cdCadastro;
    char nome[50];
    long telefone;
    TipoContato tipoContato;
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
            scanf("%s",Contatos[indexDisponivel].nome);
            printf("\nInsira o numero para o contato:\n");
            scanf("%ld",&Contatos[indexDisponivel].telefone);
            printf("\nInforme o tipo de contato:\n");
            printf("1 - Pessoal\n");
            printf("2 - Trabalho\n");
            scanf("%u",&Contatos[indexDisponivel].tipoContato);
            Contatos[indexDisponivel].cdCadastro = indexDisponivel + 1;
            printf("\nDeseja cadastrar outro contato?\n");
            printf("1 - Sim\n");
            printf("2 - Não\n");
            scanf("%d",&cont);
            if(cont == 1){
                cont = 0;
            }
        }   
    }
}

void excluirContato(){
    int cont = 0;
    int indexExcluir = 0;
    while(cont == 0){
        printf("----------------------------------\n");
        printf("\nExcluir contato:\n");
        printf("\nDigite o código de contato para excluir:\n");
        scanf("%d", &indexExcluir);
        if(indexExcluir < 1 || indexExcluir > 99){
            printf("\nInsira um código válido para excluir!\n");    
        }
        else{
            Contato contatoSelec = Contatos[indexExcluir -1];
            contatoSelec.cdCadastro = 0;
            contatoSelec.telefone = 0;
            contatoSelec.tipoContato = 0;
            printf("\nDeseja Excluir outro contato?\n");
            printf("1 - Sim\n");
            printf("2 - Não\n");
            scanf("%d",&cont);
            if(cont == 1){
                cont = 0;
            }
        }
        
    }
}

void GetPage(int page){
    printf("Página %d: \n",page + 1);
    for(int i = 0;i < 10; i++){
        int indexBase = page * 10;
        Contato contatoSelec = Contatos[indexBase + i];
        if(contatoSelec.cdCadastro == 0){
            printf("%d - %s \n",indexBase + i + 1, "---------------");
            printf("%s - %s \n","---------------", "---------------");
            printf("------------------------------\n");
        }
        else{
            printf("%d - %s \n",i + 1, contatoSelec.nome);
            if(contatoSelec.tipoContato == 1){
                printf("%ld - Pessoal\n",contatoSelec.telefone);
            }
            else{
                printf("%ld - Trabalho\n",contatoSelec.telefone);
            }
            printf("------------------------------\n");
        }
    }
    if (page > 0){
        printf("1 - Página anterior\n");
    }
    if (page < 9){
        printf("2 - Página seguinte\n");
    }
}

void visualizarContatos(){
    int cont = 0;
    int page = 0;
    int opt = 0;
    while(cont == 0){
        printf("----------------------------------\n");
        printf("\nLista de contatos:\n");
        printf("\nExibindo lista de contatos:\n");
        GetPage(page);
        printf("3 - Sair\n");
        scanf(" %d",&opt);
        switch (opt)
        {
        case 3:
            cont = 1;
            break;
        case 2:
            if (page < 0){
                printf("Comando inválido tente novamente!\n");
            }
            else{
                page++;
                GetPage(page);
            }
            break;
        case 1:
            if (page > 9){
                printf("Comando inválido tente novamente!\n");
            }
            else{
                page--;
                GetPage(page);
            }
            break;
        default:
            printf("Comando inválido tente novamente!\n");
            break;
        }
    }
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
    }
    sair();
}


void main(){
    printf("----------------------------------\n");
    printf("\nSeja bem vindo a agenda de contatos\n");
    printf("\nDesenvolvido por Matheus Luiz Garcia\n");
    printf("----------------------------------\n");
    escolherOperacao();
}
