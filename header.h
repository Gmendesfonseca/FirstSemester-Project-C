#ifndef HEADER_H
#define HEADER_H

#define MAX_OCORRENCIAS 100

typedef struct {
    int codigo;
    char setor[50];
    char nome[50];
    char data[20];
    char hora[10];
    int tipo;
} Ocorrencia;

void exibirAviso(char hora[10]);
void cadastrarOcorrencia(Ocorrencia ocorrencias[], int *numOcorrencias);
void exibirTotalOcorrenciasDia(Ocorrencia ocorrencias[], int numOcorrencias);
void exibirOcorrenciaMaisSolicitada(Ocorrencia ocorrencias[], int numOcorrencias);
void listarOcorrencias(Ocorrencia ocorrencias[], int numOcorrencias);

#endif
