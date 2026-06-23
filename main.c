#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// prototipo funcoes
// tipoSaida nomeFuncao(tipoParametro: nomeParametro);

typedef struct {
    char name[50];
    char phoneNumber[20];
    char email[50];
    char city[50];
    char business[50];
    char obs[100];
} Contact;

void addContact(int contactCount, Contact contacts[]);
void listContacts(int contactCount, Contact contacts[]);
void searchContactByName(int contactCount, Contact contacts[]);
void deleteContact(int *contactCount, Contact contacts[]);
void editContact(int contactCount, Contact contacts[]);
void drawTitle(void);
int chooseMenuOption(void);
int chooseColorOption(void);
void readContact(int index, Contact contacts[]);
void writeContact(Contact contact, int contactNumber);
int getContactIndexByName(int contactCount, Contact contacts[], char name[]);
void sortContacts(int contactCount, Contact sorted[]);
void gotoxy(int column, int line);
void pauseConsole(void);
void clearConsole(void);
void setColor(int color);
void changeConsoleColor(void);

int main()
{
    int menuOption = 0, contactCount = 0;
    Contact contacts[100];

    system("cls");
    drawTitle();

    do {
        menuOption = chooseMenuOption();
        switch(menuOption){
            case 1:
                addContact(contactCount, contacts);
                contactCount++;
                clearConsole();
                break;
            case 2:
                listContacts(contactCount, contacts);
                clearConsole();
                break;
            case 3:
                searchContactByName(contactCount, contacts);
                clearConsole();
                break;
            case 4:
                deleteContact(&contactCount, contacts);
                clearConsole();
                break;
            case 5:
                editContact(contactCount, contacts);
                clearConsole();
                break;
            case 6:
                changeConsoleColor();
                clearConsole();
                break;
            case 7:
                printf("\nSaindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    } while (menuOption != 7);

    return 0;
}

void drawTitle(void) {
    gotoxy(0, 0);
    printf("================================================");
    gotoxy(15, 1);
    printf("AGENDA DE CONTATOS");
    gotoxy(0, 2);
    printf("================================================\n\n");
}

int chooseMenuOption(void) {
    int menuOption;

    printf("------- MENU -------\n");
    printf("[1] Incluir contato\n");
    printf("[2] Listar contatos\n");
    printf("[3] Consultar contato pelo nome\n");
    printf("[4] Excluir contato\n");
    printf("[5] Editar contato\n");
    printf("[6] Alterar cor do console\n");
    printf("[7] Sair\n");
    printf("--------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%i", &menuOption);

    return menuOption;
}

void addContact(int contactCount, Contact contacts[]){
    readContact(contactCount, contacts);
    printf("\nContato adicionado com sucesso!\n");
    pauseConsole();
}

void listContacts(int contactCount, Contact contacts[]){
    Contact sorted[100];
    for (int i = 0; i < contactCount; i++) {
        sorted[i] = contacts[i];
    }

    sortContacts(contactCount, sorted);

    for(int i = 0; i < contactCount; i++) {
        writeContact(sorted[i], i + 1);
    }

    pauseConsole();  
}

void sortContacts(int contactCount, Contact sorted[]) {
    Contact temp;

    for (int i = 0; i < contactCount - 1; i++) {
        for (int j = 0; j < contactCount - i - 1; j++) {
            if (strcmp(sorted[j].name, sorted[j + 1].name) <= 0) continue;
            
            temp = sorted[j];
            sorted[j] = sorted[j + 1];
            sorted[j + 1] = temp;
        }
    }
}

void searchContactByName(int contactCount, Contact contacts[]){
    Contact sorted[100];
    char name[50];
    int found = 0;
    
    printf("\nBusque o nome do contato: ");
    scanf("%s", name); // testar busca usando contato com espaço no nome

    for (int i = 0; i < contactCount; i++) {
        sorted[i] = contacts[i];
    }
    sortContacts(contactCount, sorted);
    
    for (int i = 0; i < contactCount; i++) {
        if (strstr(sorted[i].name, name) != NULL) {
            writeContact(sorted[i], i + 1);
            found++;
        }
    }

    if (found == 0) printf("Contato nao encontrado!\n");
    pauseConsole();  
}

void deleteContact(int *contactCount, Contact contacts[]){
    char name[50];
    
    printf("\nBusque o nome do contato que deseja excluir: ");
    scanf("%s", name);

    int index = getContactIndexByName(*contactCount, contacts, name);
    if (index == -1) {
        printf("Contato nao encontrado!\n");
        return;
    }

    for (int j = index; j < *contactCount - 1; j++) {
        contacts[j] = contacts[j + 1];
    }

    (*contactCount)--;

    printf("Contato excluido com sucesso!\n");
    pauseConsole();  
}

void editContact(int contactCount, Contact contacts[]){
    char name[50];
    
    printf("\nBusque o nome do contato que deseja editar: ");
    scanf("%s", name);

    int index = getContactIndexByName(contactCount, contacts, name);
    if (index == -1) {
        printf("Contato nao encontrado!\n");
        return;
    }

    readContact(index, contacts);
    printf("\nContato editado com sucesso!\n");
    pauseConsole();  
}

void changeConsoleColor(void) {
    int color = chooseColorOption();
    if (color < 1 || color > 14) {
        printf("Opcao invalida!\n");
        return;
    }

    setColor(color);
}

int chooseColorOption(void) {
    int color;

    printf("\n------- CORES -------\n");
    printf("[1]  Azul escuro\n");
    printf("[2]  Verde escuro\n");
    printf("[3]  Ciano escuro\n");
    printf("[4]  Vermelho escuro\n");
    printf("[5]  Roxo\n");
    printf("[6]  Amarelo escuro\n");
    printf("[7]  Branco\n");
    printf("[8]  Cinza\n");
    printf("[9]  Azul\n");
    printf("[10] Verde\n");
    printf("[11] Ciano\n");
    printf("[12] Vermelho\n");
    printf("[13] Rosa\n");
    printf("[14] Amarelo\n");
    printf("---------------------\n");
    printf("Escolha uma cor: ");
    scanf("%i", &color);

    return color;
}

void readContact(int index, Contact contacts[]){
    printf("Nome: ");
    scanf(" %[^\n]", contacts[index].name);

    printf("Numero de telefone: ");
    scanf(" %[^\n]", contacts[index].phoneNumber);

    printf("Email: ");
    scanf(" %[^\n]", contacts[index].email);
    
    printf("Cidade: ");
    scanf(" %[^\n]", contacts[index].city);
    
    printf("Empresa: ");
    scanf(" %[^\n]", contacts[index].business);
    
    printf("Observacao: ");
    scanf(" %[^\n]", contacts[index].obs);
}

void writeContact(Contact contact, int contactNumber){
    printf("\n------- Contato %i -------\n", contactNumber);
    printf("Nome: %s\n", contact.name);
    printf("Numero de telefone: %s\n", contact.phoneNumber);
    printf("E-mail: %s\n", contact.email);
    printf("Cidade: %s\n", contact.city);
    printf("Empresa: %s\n", contact.business);
    printf("Observacao: %s\n", contact.obs);
}

int getContactIndexByName(int contactCount, Contact contacts[], char name[]){
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(name, contacts[i].name) == 0) return i;
    }
    return -1;
}

void setColor(int color) {
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // ponteiro para o console
    SetConsoleTextAttribute(handle, color);
}

void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // ponteiro para o console
    SetConsoleCursorPosition(handle, coord);
}

void clearConsole(){
    system("cls");
    drawTitle();
}

void pauseConsole(void) {
    printf("\nPressione Enter para continuar...");
    while (getchar() != '\n');
    getchar();
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

/* recursos opcionais

    • gravação e leitura em arquivo;
    • uso de typedef struct;                -> feito
    • uso da biblioteca string.h;           -> feito (uso de strcmp())
    • uso da biblioteca windows.h;          -> usado em GetStdHandle   
    • utilização da função gotoxy();        -> feito
    • alteração de contatos;                -> feito no editContact
    • pesquisa parcial pelo nome;           -> feito na busca por nome
    • ordenação alfabética dos contatos;    -> feito (bubble sort ao listar contatos)
    • melhorias visuais na interface;       -> feito (escolha de cor do console)
*/

