#include <stdio.h>
#include <stdlib.h>

#define tamanho 5

// Estrutura da fila 
struct tfila {
  int dados[tamanho];
  int ini;
  int fim;
};

// variáveis globais
struct tfila fila;

//prototipação 
void fila_entrar();
void fila_sair();
void fila_mostrar();
void menu_mostrar();

int main() {

  int op = 1;
  fila.ini = 0;
  fila.fim = 0;

  while (op != 0) {
    system("clear");
    fila_mostrar();
    menu_mostrar();
    
    scanf("%d", &op);

    switch (op) {
      
      case 1:
        fila_entrar();
        break;

      case 2:
        fila_sair();
        break;

      default: 
        printf("O numero digitado não confere! \n");
        system("pause");
        break;
    }
  }

  return 0;
}

// adicionar elemento no final da fila
void fila_entrar(){
  if (fila.fim == tamanho) {
    
    printf("\nA fila esta cheia, impossivel adicionar um novo valor! \n\n");
    system("pause");
    
  }  
  else {
    printf("\nDigite o valor a ser inserido: ");
    scanf("%d", &fila.dados[fila.fim]);
    fila.fim++;
  }
}

//Retirar o primeiro elemento da fila 
void fila_sair() {
  if (fila.ini == fila.fim) {
    printf("\nA fila está vazia, não há nada para remover!\n\n ");
    system("pause");
  }
  else {
    int i;

    for (i = 0; i < tamanho; i++) {
      fila.dados[i] = fila.dados[i+1];
    }
    fila.dados[fila.fim] = 0;
    fila.fim--;
  }
}  

  //mostar conteudo da fila 
  void fila_mostrar() {
    int i;
    printf("[  ");

    for (i = 0; i < tamanho; i++) {
      printf("%d", fila.dados[i]);
    }
    printf("]\n\n");
  }

void menu_mostrar() {
  printf("\nEscolha uma opcao: \n");
  printf("1 - Incluir Fila\n");
  printf("2 - Exclir na Fila\n");
  printf("0 - Sair\n\n");
  printf("-> ");
}
