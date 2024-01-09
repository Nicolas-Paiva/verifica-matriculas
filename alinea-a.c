#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int MAXSTR = 50;
const int MAXREGISTOS = 50;

typedef struct
{

  char *matricula;
  char tipo;
  int velocidade;
  char *via;
  char *local;

} Sregisto;

// ### FUNCOES

// CRIACAO DO REGISTO
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void adicionarRegisto(Sregisto *registosArr);

// Verifica se a alocação de memória para a string foi bem sucedida
void verificarAlocString(char *string);

void adicionarString(Sregisto *registo, char *membro);

// Verifica e adiciona o tipo do veiculo
char adicionarTipo();

// Verifica e adiciona a velocidade do veiculo
int adicionarVel();
/////////////////////////////////////////////////////////////////////////////////////////////////////////

// APRESENTACAO DO REGISTO
/////////////////////////////////////////////////////////////////////////////////////////////////////////
void mostrarRegisto(Sregisto *registo);

int main(void)
{
  Sregisto registosArr[MAXREGISTOS];
  adicionarRegisto(registosArr);
  mostrarRegisto(&registosArr[0]);

  return 0;
}

void adicionarRegisto(Sregisto *registosArr)
{
  static int registosArrIndex = 0;
  Sregisto novoRegisto;
  char *matricula = "matricula";
  char *via = "via";
  char *local = "local";
  novoRegisto.matricula = NULL;
  novoRegisto.via = NULL;

  ///////// MATRICULA
  printf("Matricula: ");
  adicionarString(&novoRegisto, matricula);

  ///////// TIPO
  novoRegisto.tipo = adicionarTipo();

  ///////// VELOCIDADE
  novoRegisto.velocidade = adicionarVel();

  ///////// VIA
  printf("Via: ");
  adicionarString(&novoRegisto, via);

  ///////// LOCAL
  printf("Local: ");
  adicionarString(&novoRegisto, local);

  registosArr[registosArrIndex] = novoRegisto;
  registosArrIndex++;
  return;
}

// ### Criacao do registo

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void verificarAlocString(char *string)
{
  if (string == NULL)
  {
    printf("Falha ao alocar memória\n");
    exit(1);
  }
  return;
}

void adicionarString(Sregisto *registo, char *membro)
{
  char stringAux[MAXSTR];

  fgets(stringAux, MAXSTR, stdin);
  stringAux[strlen(stringAux) - 1] = '\0';

  // Alocando memoria para a string
  if (strcmp(membro, "matricula") == 0)
  {
    registo->matricula = (char *)malloc(sizeof(stringAux) + 1);
    verificarAlocString(registo->matricula);
    strcpy(registo->matricula, stringAux);
  }
  else if (strcmp(membro, "via") == 0)
  {
    registo->via = (char *)malloc(sizeof(stringAux) + 1);
    verificarAlocString(registo->via);
    strcpy(registo->via, stringAux);
  }
  else if (strcmp(membro, "local") == 0)
  {
    registo->local = (char *)malloc(sizeof(stringAux) + 1);
    verificarAlocString(registo->local);
    strcpy(registo->local, stringAux);
  }
  return;
}

char adicionarTipo()
{
  char tipoViatura;
  printf("Tipo da viatura: ");

  scanf("%c", &tipoViatura);
  tipoViatura = toupper(tipoViatura);
  getchar(); // Temos que remover o '\n'

  while (tipoViatura != 'L' && tipoViatura != 'P' && tipoViatura != 'M')
  {
    printf("Por favor, insira um tipo valido de veiculo.\n");
    printf("L: Ligeiro\n");
    printf("P: Pesado\n");
    printf("M: Motociclo\n\n");
    scanf("%c", &tipoViatura);
    tipoViatura = toupper(tipoViatura);
    getchar();
  }

  return tipoViatura;
}

int adicionarVel()
{
  int verificar;
  int velocidade;
  printf("Insira a velocidade: ");
  verificar = scanf("%d", &velocidade);
  getchar();

  while (verificar != 1 || velocidade < 1)
  {
    printf("Por favor, insira um valor numerico valido\n");
    verificar = scanf("%d", &velocidade);
    getchar();
  }
  return velocidade;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ### Apresentacao do registo
void mostrarRegisto(Sregisto *registo)
{
  printf("Matrícula: %s\n", registo->matricula);
  printf("Tipo: %c\n", registo->tipo);
  printf("Velocidade: %d\n", registo->velocidade);
  printf("Via: %s\n", registo->via);
  printf("Local: %s\n", registo->local);
}

// ### Liberacao de memoria
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void liberarMemoria(Sregisto *registo)
{
  free(registo->matricula);
  free(registo->via);
  free(registo->local);
}