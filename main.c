#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "header.h"

#define MAX_OCORRENCIAS 100

int main() {
    Ocorrencia ocorrencias[MAX_OCORRENCIAS];
    int numOcorrencias = 0;
    int opcao;
    char hora[10] = "";

    do {
        printf("\n--- Menu ---\n");
        printf("1. Lancar Chamados\n");
        printf("2. Exibir total de ocorrencias do dia\n");
        printf("3. Exibir ocorrencia mais solicitada\n");
        printf("4. Listar ocorrencias gravadas\n");
        printf("5. Finalizar o programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarOcorrencia(ocorrencias, &numOcorrencias);
                break;
            case 2:
                exibirTotalOcorrenciasDia(ocorrencias, numOcorrencias);
                break;
            case 3:
                exibirOcorrenciaMaisSolicitada(ocorrencias, numOcorrencias);
                break;
            case 4:
                listarOcorrencias(ocorrencias, numOcorrencias);
                break;
            case 5:
                printf("Programa finalizado.\n");
                break;
            default:
                printf("Opção inválida.\n");
                break;
        }

        exibirAviso(hora);
    } while (opcao != 5);

    return 0;
}
