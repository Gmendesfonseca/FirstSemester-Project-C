#include <Stdio.h>
#include <time.h>
#include <string.h>
#include "header.h"


void exibirAviso(char hora[10]) {
    if (strcmp(hora, "22:00") >= 0 || strcmp(hora, "08:00") < 0) {
        printf("Atendimento do Setor de HelpDesk disponível somente das 08h às 22h.\n");
    }
}

void cadastrarOcorrencia(Ocorrencia ocorrencias[], int *numOcorrencias) {
    if (*numOcorrencias >= MAX_OCORRENCIAS) {
        printf("Numero maximo de ocorrencias atingido.\n");
        return;
    }

    Ocorrencia novaOcorrencia;

    printf("Codigo da ocorrencia: ");
    scanf("%d", &novaOcorrencia.codigo);

    printf("Setor/Departamento: ");
    scanf("%s", novaOcorrencia.setor);

    printf("Nome da pessoa que solicitou: ");
    scanf("%s", novaOcorrencia.nome);

    printf("Data: ");
    scanf("%s", novaOcorrencia.data);

    printf("Hora (HH:MM): ");
    scanf("%9s", novaOcorrencia.hora);

    printf("Tipo de ocorrencia:\n");
    printf("911 - Falha de conexao - Internet\n");
    printf("912 - Problema com impressora\n");
    printf("913 - Usuario sem senha\n");
    printf("914 - Problemas na rede interna\n");
    printf("915 - Computador nao liga\n");
    printf("Selecione o numero correspondente ao tipo de ocorrencia: ");
    scanf("%d", &novaOcorrencia.tipo);

    ocorrencias[*numOcorrencias] = novaOcorrencia;
    (*numOcorrencias)++;
}

void exibirTotalOcorrenciasDia(Ocorrencia ocorrencias[], int numOcorrencias) {
    int total = 0;
    char dataAtual[20];
    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(dataAtual, sizeof(dataAtual), "%d/%m/%Y", timeinfo);

    for (int i = 0; i < numOcorrencias; i++) {
        if (strcmp(ocorrencias[i].data, dataAtual) == 0) {
            total++;
        }
    }

    printf("Total de ocorrencias do dia (%s): %d\n", dataAtual, total);
}

void exibirOcorrenciaMaisSolicitada(Ocorrencia ocorrencias[], int numOcorrencias) {
    int ocorrenciasTipo[5] = {0};
    char *tipos[] = {
        "Falha de conexao - Internet",
        "Problema com impressora",
        "Usuario sem senha",
        "Problemas na rede interna",
        "Computador não liga"
    };

    for (int i = 0; i < numOcorrencias; i++) {
        ocorrenciasTipo[ocorrencias[i].tipo - 911]++;
    }

    int maxIndex = 0;
    int maxCount = ocorrenciasTipo[0];

    for (int i = 1; i < 5; i++) {
        if (ocorrenciasTipo[i] > maxCount) {
            maxIndex = i;
            maxCount = ocorrenciasTipo[i];
        }
    }

    printf("Ocorrencia mais solicitada: %s (%d chamados)\n", tipos[maxIndex], maxCount);
}

void listarOcorrencias(Ocorrencia ocorrencias[], int numOcorrencias) {
    FILE *arquivo = fopen("ocorrencias.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < numOcorrencias; i++) {
        fprintf(arquivo, "Codigo: %d\n", ocorrencias[i].codigo);
        fprintf(arquivo, "Setor/Departamento: %s\n", ocorrencias[i].setor);
        fprintf(arquivo, "Nome: %s\n", ocorrencias[i].nome);
        fprintf(arquivo, "Data: %s\n", ocorrencias[i].data);
        fprintf(arquivo, "Hora: %s\n", ocorrencias[i].hora);
        fprintf(arquivo, "Tipo: %d\n", ocorrencias[i].tipo);
        fprintf(arquivo, "------------------------\n");
    }

    fclose(arquivo);

    printf("Ocorrencias gravadas no arquivo ocorrencias.txt.\n");
}
