#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// prototipo funcoes
// tipoSaida nomeFuncao(tipoParametro: nomeParametro);

int chooseMenuOption(void);
void addContact(int index, char namesList[][50], char numbersList[][20], char emailList[][50], char cityList[][50], char businessList[][50], char obsList[][100]);
void listContacts(int index, char namesList[][50], char numbersList[][20], char emailList[][50], char cityList[][50], char businessList[][50], char obsList[][100]);
void searchContactByName(int totalContacts, char namesList[][50], char numbersList[][20], char emailList[][50], char cityList[][50], char businessList[][50], char obsList[][100]);
void deleteContact(int index, char namesList[][50], char numbersList[][20], char emailList[][50], char cityList[][50], char businessList[][50], char obsList[][100]);

int main()
{
    int menuOption = 0, contactCount = 0;
    char namesList[100][50], numbersList[100][20], emailList[100][50], cityList[100][50], businessList[100][50], obsList[100][100];

    do {
        menuOption = chooseMenuOption();
        switch(menuOption){
            case 1:
                addContact(contactCount, namesList, numbersList, emailList, cityList, businessList, obsList);
                contactCount++;
                break;
            case 2:
                listContacts(contactCount, namesList, numbersList, emailList, cityList, businessList, obsList);
                break;
            case 3:
                searchContactByName(contactCount, namesList, numbersList, emailList, cityList, businessList, obsList);
                break;
            case 4:
                deleteContact(contactCount, namesList, numbersList, emailList, cityList, businessList, obsList);
                break;
            case 5:
                printf("\nSair\n");
                break;
        }
    } while (menuOption != 5);

    return 0;
}

int chooseMenuOption(void) {
    int menuOption;

    printf("\n------- MENU -------\n");
    printf("[1] Incluir contato\n");
    printf("[2] Listar contatos\n");
    printf("[3] Consultar contato pelo nome\n");
    printf("[4] Excluir contato\n");
    printf("[5] Sair\n");
    printf("--------------------\n");
    printf("Escolha uma opção: ");
    scanf("%i", &menuOption);

    return menuOption;
}

void addContact(int index, char namesList[][50], char numbersList[][20], char emailList[][50], char cityList[][50], char businessList[][50], char obsList[][100]){
    printf("Nome: ");
    scanf(" %[^\n]", namesList[index]);

    printf("Telefone: ");
    scanf(" %[^\n]", numbersList[index]);

    printf("Email: ");
    scanf(" %[^\n]", emailList[index]);

    printf("Cidade: ");
    scanf(" %[^\n]", cityList[index]);

    printf("Empresa: ");
    scanf(" %[^\n]", businessList[index]);

    printf("Observações: ");
    scanf(" %[^\n]", obsList[index]);

    printf("\nContato adicionado com sucesso!\n");
}

void listContacts(int index, char namesList[][50], char numbersList[][20], char emailList[][50], char cityList[][50], char businessList[][50], char obsList[][100]){
    for(int i = 0; i < index; i++) {
        printf("\n------- Contato %i -------\n", i + 1);
        printf("Nome: %s\n", namesList[i]);
        printf("Número: %s\n", numbersList[i]);
        printf("E-mail: %s\n", emailList[i]);
        printf("Cidade: %s\n", cityList[i]);
        printf("Empresa: %s\n", businessList[i]);
        printf("Observações: %s\n", obsList[i]);
    }
}

void searchContactByName(int index, char namesList[][50], char numbersList[][20], char emailList[][50], char cityList[][50], char businessList[][50], char obsList[][100]){
    char name[50];
    
    printf("\nBusque o nome do contato: ");
    scanf("%s", name);

    for(int i = 0; i <= index; i++){
        if(strcmp(name, namesList[i]) == 0){
            printf("Nome: %s\n", namesList[i]);
            printf("Número: %s\n", numbersList[i]);
            printf("E-mail: %s\n", emailList[i]);
            printf("Cidade: %s\n", cityList[i]);
            printf("Empresa: %s\n", businessList[i]);
            printf("Observações: %s\n\n", obsList[i]); 
        }
    }
}

void deleteContact(int index, char namesList[][50], char numbersList[][20], char emailList[][50], char cityList[][50], char businessList[][50], char obsList[][100]){
    char name[50];
    
    printf("\nBusque o nome do contato que deseja excluir: ");
    scanf("%s", name);

    for(int i = 0; i <= index; i++){
        if(strcmp(name, namesList[i]) == 0){
            namesList[i][0] = '\0';
            numbersList[i][0] = '\0';
            emailList[i][0] = '\0';
            cityList[i][0] = '\0';
            businessList[i][0] = '\0';
            obsList[i][0] = '\0';

            printf("Contato excluido com sucesso!");
            return;
        }
    }
}


/* dados do contato
*   nome
*   telefone
*   e-mail
*   cidade
*   empresa
*   observações
---------------- */

/* funcionalidades

    1. Permitir incluir novos contatos.
    2. Permitir listar todos os contatos cadastrados.
    3. Permitir consultar um contato pelo nome.
    4. Permitir excluir um contato existente.
    5. Retornar ao menu principal após cada operação.
    6. Encerrar somente quando o usuário selecionar a opção sair.
    7. Utilizar vetores para armazenar os contatos.
    8. Utilizar funções para organizar o código.

---------------- */

// funcoes
/*
tipoSaida nomeFuncao(tipoParametro: nomeParametro) {
    comandos
    return valor;
}
*/

/* menu obrigatório

    1 - Incluir contato
    2 - Listar contatos
    3 - Consultar contato pelo nome
    4 - Excluir contato
    5 – Sair

Após cada operação, o programa deverá retornar ao menu principal até que o usuário
escolha a opção sair.
---------------- */

/* conteudos obrigatorios

    • variáveis;
    • entrada e saída de dados;
    • operadores aritméticos;
    • estrutura condicional;
    • estrutura de seleção (switch);
    • estruturas de repetição;
    • vetores;
    • funções;
    • strings simples utilizando vetores de caracteres.

*/

