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

Contato Contatos[100];
int operacao = 0;

int GetIndexDisponivel(){
    for(int i = 0; i <= 99; i++){
        if(Contatos[i].cdCadastro == 0){
            return i;
        }
    }
    return -1;
}

void cadastroContato(){
    int cont = 0;
    while(cont == 0){
        int indexDisponivel = GetIndexDisponivel();
        if(indexDisponivel < 0){
            printf("\nLista de contatos está cheia, exclua um contato ou reinicie o programa!:\n");
        }
        else{
            Contatos[indexDisponivel].cdCadastro = indexDisponivel + 1;
            printf("----------------------------------\n");
            printf("\nCadastro de contato:\n");
            printf("\nInsira o nome para o contato:\n");
            scanf("%s",&Contatos[indexDisponivel].nome);
            printf("\nInsira o numero para o contato:\n");
            scanf("%ld",&Contatos[indexDisponivel].telefone);
            printf("\nInforme o tipo de contato:\n");
            printf("1 - Pessoal\n");
            printf("2 - Trabalho\n");
            scanf("%u",&Contatos[indexDisponivel].tipoContato);
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
        if(indexExcluir < 1 || indexExcluir > 100){
            printf("\nInsira um código válido para excluir!\n");    
        }
        else{
            Contatos[indexExcluir -1].cdCadastro = 0;
            Contatos[indexExcluir -1].telefone = 0;
            Contatos[indexExcluir -1].tipoContato = 0;
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
    printf("3 - Sair\n");
}

void visualizarContatos(){
    int cont = 0;
    int page = 0;
    int opt = 0;
    printf("----------------------------------\n");
        printf("\nLista de contatos:\n");
        printf("\nExibindo lista de contatos:\n");
        GetPage(page);
    while(cont == 0){
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
void buscarContato() {
    int cont = 0;
    int id = 0;
    int opt = 0;
    printf("----------------------------------\n");
    printf("\nBusca de contato:\n");
    while(cont == 0){
            printf("\nInsira um código de contato entre 1 e 100 para buscar:\n");
            scanf("%d", &id);
        if (id < 1 || id > 100){
            printf("\nInsira um ID válido, tente novamente!\n");
        }
        else{
            Contato contatoBuscado = Contatos[id-1];
            if (contatoBuscado.cdCadastro == 0){
                printf("Contato com código %d não cadastrado ou não encontrado!\n", id);
            }
            else{
                printf("Cód. Cadastro: %d\n", contatoBuscado.cdCadastro);
                printf("Nome: %s \n", contatoBuscado.nome);
                printf("Cód. Cadastro: %d\n", contatoBuscado.telefone);
                if(contatoBuscado.tipoContato == 1){
                    printf("Tipo de contato: Pessoal\n");
                }
                else{
                    printf("Tipo de contato: Trabalho\n");
                }
            }
            cont = 1;
        }
    }
}

void editarContato(){ 
    int cont = 0;
    int id = 0;
    int opt = 0;
    printf("----------------------------------\n");
    printf("\nEditar contato:\n");
    while(cont == 0){
            printf("\nInsira um código de contato entre 1 e 100 para editar:\n");
            scanf("%d", &id);
        if (id < 1 || id > 100){
            printf("\nInsira um ID válido, tente novamente!\n");
        }
        else{
            Contatos[id-1].cdCadastro = id;
            printf("\nInsira o nome para o contato:\n");
            scanf("%s",&Contatos[id-1].nome);
            printf("\nInsira o numero para o contato:\n");
            scanf("%ld",&Contatos[id-1].telefone);
            printf("\nInforme o tipo de contato:\n");
            printf("1 - Pessoal\n");
            printf("2 - Trabalho\n");
            scanf("%u",&Contatos[id-1].tipoContato);
            printf("\nDeseja editar outro contato?\n");
            printf("1 - Sim\n");
            printf("2 - Não\n");
            scanf("%d",&cont);
            if(cont == 1){
                cont = 0;
            }
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
        printf("3 - Excluir contato\n");
        printf("4 - Buscar contato por ID\n");
        printf("5 - Editar contato\n");
        printf("6 - Sair do programa\n");
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
            buscarContato();
            break;
        case 5:
            editarContato();
            break;
        case 6:
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


int main(){
    for (int i = 0; i <= 99; i++){
            Contatos[i].cdCadastro = 0;
            Contatos[i].telefone = 0;
            Contatos[i].tipoContato = 0;
    }
    printf("----------------------------------\n");
    printf("\nSeja bem vindo a agenda de contatos\n");
    printf("\nDesenvolvido por Matheus Luiz Garcia\n");
    printf("----------------------------------\n");
    escolherOperacao();
    return 0;
}
