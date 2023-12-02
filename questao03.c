#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* paraMinusculas(char *string) {
    int i = 0;
    while (string[i] != '\0') {
        if (string[i] >= 'A' && string[i] <= 'Z') {
            // Converter caractere maiúsculo para minúsculo
            string[i] = string[i] + 32; // Diferença entre maiúsculo e minúsculo na tabela ASCII
        }
        i++;
    }
    return string;
}

int validarPlaca(char *placa) {

    int tamanho = strlen(placa);
    if (tamanho != 8) {
        return 0; 
    }

    if (placa[3] != '-' && placa[3] != '\0') {
        return 0; 
    }

    for (int i = 0; i < tamanho; i++) {
        if (i == 3) {
            continue; 
        }
        if (i == 4 && placa[3] == '-') {
            continue; 
        }
        if (!isalnum(placa[i])) {
            return 0; 
        }
    }

    return 1; 
}

int validarPlacaNova(char *placa) {

    int tamanho = strlen(placa);
    if (tamanho != 7) {
        return 0; 
    }

    for (int i = 0; i < tamanho; i++) {
        if (!isalnum(placa[i])) {
            return 0; 
        }
    }

    return 1; 
}

int validarDiaSemana(char *dia) {
    char *diasValidos[] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    for (int i = 0; i < 7; i++) {
        if (strcmp(dia, diasValidos[i]) == 0) {
            return 1; // Dia da semana válido
        }
    }
    return 0; 
}

int main() {
    char placa[9];
    char diaSemana[20];

    scanf("%s", placa);
    scanf("%s", diaSemana);

    
    int placaValidaVelha = validarPlaca(placa);
    int placaValidaNova = validarPlacaNova(placa);

    int diaValido = validarDiaSemana(diaSemana);

    
    if (!placaValidaVelha && !placaValidaNova) {
        printf("Placa invalida\n");
        if(!diaValido){
        printf("Dia da semana invalido\n");
        }
    }
    else if (!diaValido) {
        printf("Dia da semana invalido\n");
    } else {
        if(strcmp(diaSemana, "SABADO") == 0 || strcmp(diaSemana, "DOMINGO") == 0){
            printf("Nao ha proibicao no fim de semana\n");
            return 0;
        }
        int ultimoDigito = placa[strlen(placa) - 1] - '0';
        int diaProibido = 0;

        if (strcmp(diaSemana, "SEGUNDA-FEIRA") == 0 && (ultimoDigito == 0 || ultimoDigito == 1))
            diaProibido = 1;
        else if (strcmp(diaSemana, "TERCA-FEIRA") == 0 && (ultimoDigito == 2 || ultimoDigito == 3))
            diaProibido = 1;
        else if (strcmp(diaSemana, "QUARTA-FEIRA") == 0 && (ultimoDigito == 4 || ultimoDigito == 5))
            diaProibido = 1;
        else if (strcmp(diaSemana, "QUINTA-FEIRA") == 0 && (ultimoDigito == 6 || ultimoDigito == 7))
            diaProibido = 1;
        else if (strcmp(diaSemana, "SEXTA-FEIRA") == 0 && (ultimoDigito == 8 || ultimoDigito == 9))
            diaProibido = 1;

        if (diaProibido)
            printf("%s nao pode circular %s\n", placa, paraMinusculas(diaSemana));
        else
            printf("%s pode circular %s\n", placa, paraMinusculas(diaSemana));
    }

    return 0;
}
