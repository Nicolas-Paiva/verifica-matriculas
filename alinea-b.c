#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int MAXSTR = 50;
const int MAXREGISTOS = 50;

typedef struct
{

  char matricula[50];
  char tipo;
  int velocidade;
  char via[50];
  char local[50];

} Sregisto;

// ### FUNCOES

// ### FUNCOES PARA ADICIONAR MATRICULAS COM VALORES QUE VEM DE UM FICHEIRO
void adicionarMatricula(char *ch, FILE *fp, Sregisto *registo);

void adicionarTipo(char *ch, FILE *fp, Sregisto *registo);

void adicionarVel(char *ch, FILE *fp, Sregisto *registo);

void adicionarVia(char *ch, FILE *fp, Sregisto *registo);

void adicionarLocal(char *ch, FILE *fp, Sregisto *registo);

// ###  Contando as ocorrencias da mesma matricula
int contarMatricula(char *matricula, Sregisto *registos, int numRegistos);

int main(void)
{
  FILE *fp;
  fp = fopen("test.txt", "r");

  if (fp == NULL)
  {
    printf("Erro. Arquivo não encontrado");
    exit(1);
  }

  Sregisto *registos;

  char charNumRegistos;
  charNumRegistos = getc(fp);
  int numRegistos = charNumRegistos - '0'; // Define o numero de registos que iremos criar
  printf("%d\n", numRegistos);

  registos = malloc(sizeof(Sregisto) * numRegistos);

  int i = 0;
  char ch;
  ch = getc(fp);

  // Toda vez que invocamos fgetc() o ponteiro avança. Ao invocar "adicionarMatricula" já estamos na primeira letra da matricula
  while (ch != EOF)
  {
    adicionarMatricula(&ch, fp, &registos[i]);
    adicionarTipo(&ch, fp, &registos[i]);
    adicionarVel(&ch, fp, &registos[i]);
    adicionarVia(&ch, fp, &registos[i]);
    adicionarLocal(&ch, fp, &registos[i]);

    i++;
    if (i == numRegistos)
    {
      break;
    }
  }

  char matricula[MAXSTR];

  // 52-CI-23
  fgets(matricula, MAXSTR, stdin);
  matricula[strlen(matricula) - 1] = '\0';

  printf("%d\n", contarMatricula(matricula, registos, numRegistos));

  free(registos);
  fclose(fp);

  return 0;
}

void adicionarMatricula(char *ch, FILE *fp, Sregisto *registo)
{
  int i = 0;
  while ((*ch = fgetc(fp)) != ' ')
  {
    registo->matricula[i] = *ch;
    i++;
  }
  return;
}

void adicionarTipo(char *ch, FILE *fp, Sregisto *registo)
{
  registo->tipo = (*ch = fgetc(fp));
  fgetc(fp);
  return;
}

void adicionarVel(char *ch, FILE *fp, Sregisto *registo)
{

  char stringAux[MAXSTR];

  int i = 0;
  while ((*ch = fgetc(fp)) != ' ')
  {
    stringAux[i] = *ch;
    i++;
  }

  registo->velocidade = atoi(stringAux);
  return;
}

void adicionarVia(char *ch, FILE *fp, Sregisto *registo)
{
  int i = 0;
  while ((*ch = fgetc(fp)) != ' ')
  {
    registo->via[i] = *ch;
    i++;
  }
  return;
}

void adicionarLocal(char *ch, FILE *fp, Sregisto *registo)
{
  int i = 0;
  while ((*ch = fgetc(fp)) != '\n')
  {
    registo->local[i] = *ch;
    i++;
  }
  return;
}

int contarMatricula(char *matricula, Sregisto *registos, int numRegistos)
{
  int contador = 0;
  for (int i = 0; i < numRegistos; i++)
  {
    if (strcmp(matricula, registos[i].matricula) == 0)
    {
      contador++;
    }
  }
  return contador;
}