#include <stdio.h>
void exibirMenu();
void consultarSaldo(float saldo);
float realizarSaque(float saldo); 
float realizarDeposito(float saldo); 
int main(){
    float saldo = 300.0;
    int opcao;
    do{
        exibirMenu();
        scanf("%d", &opcao);
        switch(opcao) {
            case 1: 
            printf("Consulta de saldo selecionado.\n");
            consultarSaldo(saldo); 
            break;
            case 2: 
            printf("Saque de saldo selecionado.\n");
            saldo = realizarSaque(saldo); 
            break;
            case 3: 
            printf("Deposito de saldo selecionado.\n");
            saldo = realizarDeposito(saldo); 
            break;
            case 0: 
            printf("Saindo...\n"); 
            break;
            default: printf("Invalido!\n");
        }
    }while(opcao != 0);
    printf("Obrigado por sua perferência!\n");
    return 0;
}

void exibirMenu(){
    printf("\n========================\n");
    printf(" CAIXA ELETRONICO \n");
    printf("========================\n");
    printf("1 - Consultar Saldo\n");
    printf("2 - Realizar Saque\n");
    printf("3 - Realizar Deposito\n");
    printf("0 - Sair\n");
    printf("========================\n");
    printf("Escolha uma opcao: \n");
}

void consultarSaldo(float saldo){
    printf("\n--- SALDO ATUAL ---\n");
    printf("R$ %.2f\n", saldo);
    printf("-------------------\n");
    printf("Pressione Enter para continuar...\n");
    setbuf(stdin, NULL);
    getchar();
}

float realizarSaque(float saldo){
    for(int i = 2; i >= 0; i--){
        float valor; 
        printf("Digite o valor para ser retirado: \n"); 
        scanf("%f", &valor);
        if(saldo < valor){ 
            printf("Saldo insufuciente!\n");
            if(i == 2){
                printf("2 tentativas restantes!\n");
                continue;
            }
            else if(i == 1){
                printf("1 tentativa restante!\n");
                continue;
            } 
            else{
                printf("Nenhuma tentativa restante.\n");
                printf("Pressione Enter para continuar...\n");
                setbuf(stdin, NULL);
                getchar();
            }
        }
        else if(valor <= 0){
            printf("Valor invalido!\n"); 
            if(i == 2){
                printf("2 tentativas restantes!\n");
                continue;
            }
            else if(i == 1){
                printf("1 tentativa restante!\n");
                continue;
            } 
            else{
                printf("Nenhuma tentativa restante.\n");
                printf("Pressione Enter para continuar...\n");
                setbuf(stdin, NULL);
                getchar();
            }
        }
        else if(valor > 1000.00){
            printf("Limite diario excedido!\n");
            if(i == 2){
                printf("2 tentativas restantes!\n");
                continue;
            }
            else if(i == 1){
                printf("1 tentativa restante!\n");
                continue;
            } 
            else{
                printf("Nenhuma tentativa restante.\n");
                printf("Pressione Enter para continuar...\n");
                setbuf(stdin, NULL);
                getchar();
            }
        } 
        else{
            saldo -= valor;
            printf("Saque realizado!\n");
            printf("Pressione Enter para continuar...\n");
            setbuf(stdin, NULL);
            getchar();
            break;
        }
    }
    return saldo;
}

float realizarDeposito(float saldo){
    float valor;
    printf("Digite o valor para ser depositado: ");
    scanf("%f", &valor);
    if(valor > 0){
        saldo += valor;
        printf("Deposito realizado!\n");
        printf("Pressione Enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
    } 
    else{
        printf("Valor invalido!\n");
        printf("Pressione Enter para continuar...\n");
        setbuf(stdin, NULL);
        getchar();
    }
    return saldo;
}