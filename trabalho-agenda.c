#include<stdio.h>

void cadastroContato(){

}

void excluirContato(){
    
}
void visualizarContatos(){
    
}
void sair(){

}

enum TipoContato {
    PESSOAL,
    TRABALHO
};
typedef struct {
    int cdCadastro;
    char nome[20];
    long telefone;
} Contato;


Contato Contatos[99];
int operacao = 0;


void escolherOperacao(){
    int continua = 0; 
    while(continua == 0){
        printf("Selecione uma operação:\n\n");
        printf("1 - Cadastrar novo contato\n");
        printf("2 - Visualizar contatos\n");
        printf("3 - Excluir contato:\n");
        printf("4 - Sair do programa:\n");
        scanf("%d",&operacao);
        switch (operacao)
        {
        case 1:
            continua = 1;
            cadastroContato();
            break;
        case 2:
            continua = 1;
            visualizarContatos();
            break;
        case 3:
            continua = 1;
            excluirContato();
            break;
        case 4:
            continua = 1;
            sair();
            break;
        default:
            printf("Operação inválida, tente novamente!\n");
            break;
        }
    }
}
void main(){
    printf("Seja bem vindo a agenda de contatos\n\n");
    printf("Desenvolvido por Matheus Luiz Garcia\n\n");
    escolherOperacao();
}