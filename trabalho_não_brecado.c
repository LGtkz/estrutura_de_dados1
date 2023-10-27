#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    int dia;
    int mes;
    int ano;
} data;

typedef struct{
    char rua[30];
    char cidade[30];
    char estado[30];
} endereco;

typedef struct{
    char nome[30];
    int cpf;
    endereco end;
    data d_nasc;
}cliente;

typedef struct{
    data ano_fab;
    int num_modelo;
    char nome_carro[30];
    char cor[15];
    char tipo_abs[30];//tipo de abastecimento
    int qtd;
}carro;

typedef struct{
    int cpf_c;
    int cod_carro;
    int qtd;
} venda;

typedef struct list_cliente{
    cliente c;
    struct list_cliente *prev, *next;
}list_cliente;

typedef struct list_carro{
    carro v;
    struct list_carro *prev, *next;
}list_carro;

typedef struct list_venda{
    venda v;
    struct list_venda *prev, *next;
}list_venda;

void append_cliente(list_cliente **list1, cliente a);
void append_carros(list_carro **list2, carro a);
void append_vendas(list_venda **list3, venda a);
void display_clientes(list_cliente **list1);
void display_carros(list_carro **list2);
void display_vendas(list_venda **list3);

int verifica_cpf(list_cliente **list1, int cpf);

int main(void){
    list_cliente *list1 = NULL;
    list_carro *list2 = NULL;
    list_venda *list3 = NULL;
    int choose, menu, abastecimento, quant;
    cliente c;
    carro veiculo;
    venda v;
    do{
        printf("\n-------------- MENU --------------\n\n");
        printf("1 - Para cadastros\n");
        printf("2 - Para fazer alterações no cadastro\n");
        printf("3 - Para fazer exclusões de cadastros\n");
        printf("4 - Para selecionar listagens\n");
        printf("5 - Para finalizar o programa\n");
        scanf("%d", &choose);
        system("cls");
        switch(choose){
            case 1:
                printf("\n-------------- Cadastros --------------\n\n");
                printf("1 - Para cadastrar clientes\n");
                printf("2 - Para cadastrar veiculos\n");
                printf("3 - Para cadastrar vendas\n");
                printf("4 - Para retornar ao menu principal\n");
                scanf("%d", &menu);
                system("cls");

                switch(menu){
                    case 1:
                        printf("\n-------------- Cadastro de cliente --------------\n\n");
                        printf("Digite o nome do cliente\n");
                        fflush(stdin);
                        gets(c.nome);
                        printf("Digite o CPF:\n");
                        scanf("%d", &c.cpf);
                            printf("Digite o endereço do cliente:\n");
                            printf("Rua:\n");
                            fflush(stdin);
                            gets(c.end.rua);
                            printf("Cidade:\n");
                            fflush(stdin);
                            gets(c.end.cidade);
                            printf("Estado:\n");
                            fflush(stdin);
                            gets(c.end.estado);
                            printf("Data de nascimento do cliente:\n");
                            printf("Dia/Mes/Ano\n");
                            scanf("%d %d %d", &c.d_nasc.dia, &c.d_nasc.mes, &c.d_nasc.ano);
                            system("cls");
                            append_cliente(&list1, c);
                    break;
                    case 2:
                        printf("\n-------------- Cadastro de veiculo --------------\n\n");
                        printf("Nome do modelo do carro:\n");
                        fflush(stdin);
                        gets(veiculo.nome_carro);
                        printf("Insira o codigo do carro:\n");
                        fflush(stdin);
                        scanf("%d", &veiculo.num_modelo);
                        printf("Insira a cor deste modelo:\n");
                        fflush(stdin);
                        gets(veiculo.cor);
                        printf("Insira o tipo de abastecimento que o carro recebe:\n");
                        printf("1 - Alcool\n2 - Gasolina\n3 - Diesel\n4 - Flex(Alcool e gasolina)\n");
                        scanf("%d", &abastecimento);
                        if(abastecimento == 1) strcpy(veiculo.tipo_abs, "Alcool");
                        else if(abastecimento == 2) strcpy(veiculo.tipo_abs, "Gasolina");
                        else if(abastecimento == 3) strcpy(veiculo.tipo_abs, "Diesel");
                        else if(abastecimento == 4) strcpy(veiculo.tipo_abs, "Flex");
                        printf("Digite a data de fabricação desta leva de carros:\n");
                        printf("Dia/Mes/Ano");
                        scanf("%d %d %d", &veiculo.ano_fab.dia, &veiculo.ano_fab.mes, &veiculo.ano_fab.ano);
                        printf("Digite a quantidade de veiculos deste modelo disponiveis:\n");
                        scanf("%d", &veiculo.qtd);
                        system("cls");
                        append_carros(&list2, veiculo);
                    break;
                    case 3:
                        printf("\n-------------- Cadastro de venda --------------\n\n");
                        printf("Digite o cpf do cliente:");
                        scanf("%d", &v.cpf_c);
                        printf("Digite o cod de modelo do carro:\n");
                        scanf("%d", &v.cod_carro);
                        printf("Digite a quantidade de veiculos que deseja comprar:\n");
                        scanf("%d", &v.qtd);
                        system("cls");
                        append_vendas(&list3, v);
                    break;
                    case 4:
                        printf("Retornando ao menu principal...");
                        system("cls");
                    break;
                    default:
                        printf("Digite uma opção valida\n");
                        system("cls");
                    break;
                }

            break;
            case 2:
                printf("\n-------------- Alterações --------------\n\n");
                printf("1 - Para Alterar clientes\n");
                printf("2 - Para Alterar veiculos\n");
                printf("3 - Para Alterar vendas\n");
                printf("4 - Para retornar ao menu principal\n");
                scanf("%d", &menu);
                system("cls");

                switch(menu){
                    case 1:
                        printf("\n-------------- Alterar cliente --------------\n\n");
                        printf("Digite o CPF do cliente que deseja alterar\n");
                        scanf("%d", &c.cpf);
                        system("cls");
                    break;
                    case 2:
                        printf("\n-------------- Alterar veiculo --------------\n\n");
                        printf("Digite o codigo do carro:\n");
                        scanf("%d", &veiculo.num_modelo);
                        system("cls");
                    break;
                    case 3:
                        printf("\n-------------- Alterar venda --------------\n\n");
                        printf("Digite o codigo do carro que deseja alterar:\n");
                        scanf("%d", &v.cod_carro);
                        system("cls");
                    break;
                    case 4:
                        printf("Retorando ao menu principal:\n");
                        system("cls");
                    break;
                    default:
                        printf("Digite uma opção valida\n");
                        system("cls");
                    break;
                }

            break;
            case 3:
                printf("\n-------------- Excluir Cadastros --------------\n\n");
                printf("1 - Para Alterar clientes\n");
                printf("2 - Para Alterar veiculos\n");
                printf("3 - Para Alterar vendas\n");
                printf("4 - Para retornar ao menu principal\n");
                scanf("%d", &menu);
                system("cls");
                switch(menu){
                    case 1:
                        printf("\n-------------- Excluir Clientes --------------\n\n");
                        printf("Digite o cpf do cliente que deseja excluir\n");
                        scanf("%d", &c.cpf);
                        system("cls");
                    break;
                    case 2:
                        printf("\n-------------- Excluir veiculos --------------\n\n");
                        printf("Digite o codigo de veiculo que deseja excluir:\n");
                        scanf("%d", &veiculo.num_modelo);
                        system("cls");
                    break;
                    case 3:
                        printf("\n-------------- Excluir vendas --------------\n\n");
                        printf("Digite o codigo do veiculo atrelado a venda que deseja excluir:\n");
                        scanf("%d", &v.cod_carro);
                    break;
                    case 4:
                        printf("Retorando ao menu principal...\n");
                        system("cls");
                    break;
                    default:
                        printf("Digite uma opção valida\n");
                        system("cls");
                    break;
                }
            break;
            case 4:
                printf("\n-------------- Listagens --------------\n\n");
                printf("1 - Todos os clientes cadastrados\n");
                printf("2 - Todos os veiculos cadastrados\n");
                printf("3 - Todos os carros vendidos\n");
                printf("4 - Quantos clientes fizeram compras acima de R$X valor a sua escolha\n");
                printf("5 - Quais carros estão com estoque menor que X carros, valor a sua escolha\n");
                printf("6 - Para retornar ao menu principal");
                scanf("%d", &menu);
                system("cls");

                switch(menu){
                    case 1:
                        display_clientes(&list1);
                    break;
                    case 2:
                        display_carros(&list2);
                    break;
                    case 3:
                        display_vendas(&list3);
                    break;
                    case 4:
                        printf("Digite o valor que deseja usar de base para a pesquisa\n");
                        scanf("%d", &quant);
                        system("cls");
                    break;
                    case 5:
                        printf("Digite o valor minimo de estoque para usar de base para a pesquisa\n");
                        scanf("%d", &quant);
                        system("cls");
                    break;
                    case 6:
                        printf("Retornando ao menu principal...\n");
                        system("cls");
                    break;
                    default:
                        printf("Digite um valor valido\n");
                        system("cls");
                    break;
                }
            break;
            case 5:
                printf("Salvando os arquivos...\n");
                printf("Finalizando programa...\n");
            break;
            default:
                printf("Digite uma opção valida\n");
            break;
        }
    }while(choose != 5);
    return 0;
}

void append_cliente(list_cliente **list1, cliente a){
    list_cliente *newNode =  (list_cliente*)malloc(sizeof(list_cliente));
    newNode -> c = a;
    newNode -> next = NULL;
    newNode -> prev = NULL;
    if((*list1) == NULL){
        *list1 = newNode;
    }
    else{
        list_cliente *current = *list1;
        while (current -> next != NULL){
            current = current -> next;
        }
        current -> next = newNode;
        newNode -> prev = current;
    }
}

int verifica_cpf(list_cliente **list1, int cpf){
    list_cliente *aux = *list1;
    int flag = 0;
    while(flag != 1 || aux != NULL){
        if(aux -> c.cpf == cpf){
            flag = 1;
        }
        aux = aux -> next;
    }
    if(flag == 0) return 0;
    else return 1;
}

void append_carros(list_carro **list2, carro a){
    list_carro *newNode = (list_carro*)malloc(sizeof(list_carro));
    newNode -> v = a;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if((*list2) == NULL){
        *list2 = newNode;
    }
    else{
        list_carro *current = *list2;
        while(current -> next != NULL){
            current = current -> next;
        }
        current -> next = newNode;
        newNode -> prev = current;
    }
}

void append_vendas(list_venda **list3, venda a){
    list_venda *newNode = (list_venda*)malloc(sizeof(list_venda));
    newNode -> v = a;
    newNode -> next = NULL;
    newNode -> prev = NULL;

    if((*list3) == NULL){
        *list3 = newNode;
    }
    else{
        list_carro *current = (*list3);
        while(current -> next != NULL){
            current = current -> next;
        }
        current -> next = newNode;
        newNode -> prev = current;
    }
}

void display_clientes(list_cliente **list1){
    list_cliente *aux = *list1;
    while(aux != NULL){
        printf("Nome: ");
        puts(aux -> c.nome);
        printf("CPF: %d\n", aux -> c.cpf);
        printf("%d/%d/%d\n", aux -> c.d_nasc.dia, aux -> c.d_nasc.mes, aux -> c.d_nasc.ano);
        aux = aux -> next;
        printf("-----------------------------------------------------\n");
    }
    printf("NULL");
}

void display_carros(list_carro **list2){
    list_carro *aux = *list2;
    while(aux != NULL){
        printf("Modelo: ");
        puts(aux -> v.nome_carro);
        printf("Codigo: %d\n", aux -> v.num_modelo);
        printf("Cor: ");
        puts(aux -> v.cor);
        printf("Ano de fabricação: %d/%d/%d\n", aux -> v.ano_fab.dia, aux -> v.ano_fab.mes, aux -> v.ano_fab.ano);
        printf("Tipo de abastecimento: ");
        puts(aux -> v.tipo_abs);
        printf("-----------------------------------------------------\n");
        aux = aux -> next;
    }
}

void display_vendas(list_venda **list3){
    list_venda *aux = *list3;
    while(aux != NULL){
        printf("CPF: %d\n", aux -> v.cpf_c);
        printf("Codigo: %d\n", aux -> v.cod_carro);
        printf("Quantidade: %d\n", aux -> v.qtd);
        printf("-----------------------------------------------------\n");
        aux = aux -> next;
    }
    printf("NULL");
}