#include "parkif.h"

int main() {
    int op;
    veiculo x;

    init();
    
    do{
        printf("---------------------------\n");
        printf("- 1) Entrada de Veiculo   -\n");
        printf("- 2) Saida de Veiculo     -\n");
        printf("- 3) Visualizar Veiculos  -\n");
        printf("- 0) Sair                 -\n");
        printf("---------------------------\n");
        printf(">> ");

        scanf("%i", &op);
        flush_in();

        switch (op){
        case 1:
            printf("\n[ENTRADA DE VEICULO]\n");
            printf(" - Marca: ");
            gets(x.marca);
            printf(" - Modelo: ");
            gets(x.modelo);
            printf(" - Cor: ");
            gets(x.cor);
            printf(" - Placa: ");
            gets(x.placa);

            add(x);
            break;
        case 2:
            printf("[SAIDA DE VEICULO]\n");
            printf(" - Placa: ");
            gets(placa);
            rem(placa);
            break;
        case 3:
            view();
            break;
        case 0:
            printf("Saindo...");
            break;
        
        default:
            printf("Opcao invalida!");
            break;
        }

    } while (op != 0);
    

    printf("\n");
    return 0;
}


