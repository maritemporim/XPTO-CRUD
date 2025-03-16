#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char op, op2, op3, op4, op5,op6, op7, op8;
float inss, ticA, vt, ps;
float sb[9999],sl[9999];
int qntF, i, j;
char cdg[9999][5];
char cdgDig[9999][5];
char cdgDig2[9999][5];
char nome[9999][100];
char nomeDig[9999][100];
char nomeDig2[9999][100];
char rua[9999][100], cid[9999][100], bairro[9999][100],cep[9999][9];
int encontrar = 0;

apagar()
{
  printf("\n");
  system("pause");
  system("clear");
}

void concerto()
{
system("clear");
menu();
}

menu()
{
    printf("\n+---------------------------------------------+");
    printf("\n|\x1b[96m                 XPTO ATACADO                \x1b[0m|");
    printf("\n+---------------------------------------------+");
    printf("\n| \x1b[96m[1] -\x1b[0m  REALIZAR CADASTROS DE FUNCIONÁRIOS   |");
    printf("\n| \x1b[96m[2] -\x1b[0m  LISTAR FUNCIONÁRIOS CADASTRADOS      |");
    printf("\n| \x1b[96m[3] -\x1b[0m  BUSCAR INFORMAÇÕES DE UM FUNCIONÁRIO |");
    printf("\n| \x1b[96m[4] -\x1b[0m  EXCLUIR FUNCIONÁRIO CADASTRADO       |");
    printf("\n+---------------------------------------------+");
    printf("\nDigite a opção desejada: ");
    scanf("%s", &op); 
    switch(op)
    {
        case '1':
          cadastros();
          break;
        case '2':
          printf("No momento não há nenhum funcionário cadastrado para listar!\n\n");
          apagar();
          menu();
          break;
        case '3':
          printf("No momento não há nenhum funcionário cadastrado para buscar!\n\n");
          apagar();
          menu();
          break;
        case '4':
          printf("No momento não há nenhum funcionário cadastrado para excluir!\n\n");
          apagar();
          menu();
          break;
        default:
          printf("Opção inválida\n");
          apagar();
          menu();
          break;
  }
}

void segmenu()
{
    printf("\n+-------------------------------------------------------+");
    printf("\n|\x1b[96m                     XPTO ATACADO                      \x1b[0m|");
    printf("\n+-------------------------------------------------------+");
    printf("\n|               \x1b[96mCADASTRO DE FUNCIONÁRIOS\x1b[0m                |");
    printf("\n+-------------------------------------------------------+");
}

menuAlt()
{
    printf("\n\n+----------------------------------------------+");
    printf("\n|          \x1b[96m[1]\x1b[0m - RETORNAR AO MENU              |");
    printf("\n|          \x1b[96m[2]\x1b[0m - SAIR                          |");
    printf("\n+----------------------------------------------+");
    printf("\n  \x1b[96m[1-2]:\x1b[0m ");
    scanf("%s",&op4);

    switch(op4)
    {
        case '1':
          apagar();
          terceiromenu();
          break;
        case '2':
          exit(0);
          break;
        default:
          printf("\nOpção inválida.");
          apagar();
          menuAlt();
    }
}

listagem()
{
    printf("\n+---------------------------------------------+");
    printf("\n|                  \x1b[96mLISTAGEM\x1b[0m                   |");
    printf("\n+---------------------------------------------+");
    printf("\n|             \x1b[96m[1]\x1b[0m - COMPLETA                  |");
    printf("\n|             \x1b[96m[2]\x1b[0m - SIMPLIFICADA              |");
    printf("\n+---------------------------------------------+");
    printf("\nInsira a opção desejada: ");
    scanf("%s",&op3);
    apagar();

    switch(op3)
    {
        case '1':
        for(i=0;i<qntF;i++)
        {
            printf("\n\n+---------------------------------------------+");
            printf("\n\x1b[96m|           %dº FUNCIONÁRIO.                   |\x1b[0m",i+1);
            printf("\n+---------------------------------------------+");
            printf("\n  \x1b[96mCÓDIGO:\x1b[0m %s                                   ",cdg[i]);
            printf("\n  \x1b[96mNOME COMPLETO:\x1b[0m %s                            ",nome[i]);
            printf("\n  \x1b[96mCEP:\x1b[0m %s                                      ",cep[i]);
            printf("\n  \x1b[96mCIDADE:\x1b[0m %s                                   ",cid[i]);
            printf("\n  \x1b[96mBAIRRO:\x1b[0m %s                                   ",bairro[i]);
            printf("\n  \x1b[96mRUA:\x1b[0m %s                                      ",rua[i]);
            printf("\n  \x1b[96mSALÁRIO BRUTO:\x1b[0m R$ %.2f                       ",sb[i]);
            printf("\n  \x1b[96mSALÁRIO LIQUÍDO:\x1b[0m R$ %.2f                     ",sl[i]);
            printf("\n+---------------------------------------------+");
              }
        menuAlt();
        break;
        case '2':
        for(i=0;i<qntF;i++)
        {
            printf("\n\n+---------------------------------------------+");
            printf("\n\x1b[96m|           %dº FUNCIONÁRIO.                   |\x1b[0m",i+1);
            printf("\n+---------------------------------------------+");
            printf("\n  \x1b[96mCÓDIGO:\x1b[0m %s                                   ",cdg[i]);
            printf("\n  \x1b[96mNOME COMPLETO:\x1b[0m %s                            ",nome[i]);
            printf("\n  \x1b[96mSALÁRIO LIQUÍDO:\x1b[0m R$ %.2f                     ",sl[i]);
            printf("\n+---------------------------------------------+");
        }

        menuAlt();
        break;

        default:
        printf("\nOpção inválida.");
        apagar();
        listagem();
        break;
    }
}

buscarListN()
{
    printf("\n+---------------------------------------------+");
    printf("\n|               \x1b[96mBUSCAR LISTAGEM\x1b[0m               |");
    printf("\n+---------------------------------------------+");
    printf("\n|             \x1b[96m[1]\x1b[0m - COMPLETA                  |");
    printf("\n|             \x1b[96m[2]\x1b[0m - SIMPLIFICADA              |");
    printf("\n+---------------------------------------------+");
    printf("\nDigite qual listagem deseja buscar: ");
    scanf("%s",&op7);
    apagar();
    switch(op7)
    {
        case '1':
        for(i=0;i<qntF;i++)
        {
            if (strcmp(nomeDig, nome[i]) == 0)
            {
                printf("\n\n+---------------------------------------------+");
                printf("\n\x1b[96m|               %dº FUNCIONÁRIO                |\x1b[0m",i+1);
                printf("\n+---------------------------------------------+");
                printf("\n  \x1b[96mCÓDIGO:\x1b[0m %s                                   ",cdg[i]);
                printf("\n  \x1b[96mNOME COMPLETO:\x1b[0m %s                            ",nome[i]);
                printf("\n  \x1b[96mCEP:\x1b[0m %s                                      ",cep[i]);
                printf("\n  \x1b[96mCIDADE:\x1b[0m %s                                   ",cid[i]);
                printf("\n  \x1b[96mBAIRRO:\x1b[0m %s                                   ",bairro[i]);
                printf("\n  \x1b[96mRUA:\x1b[0m %s                                      ",rua[i]);
                printf("\n  \x1b[96mSALÁRIO BRUTO:\x1b[0m R$ %.2f                       ",sb[i]);
                printf("\n  \x1b[96mSALÁRIO LIQUÍDO:\x1b[0m R$ %.2f                     ",sl[i]);
                printf("\n+---------------------------------------------+");
                encontrar = 1;
            }
                if (encontrar==0)
            {
              apagar();
              printf("\nO funcionário não foi encontrado. Tente digitar novamente.");
              buscar();
              i--;
            }
        }
        menuAlt();
        break;
      
        case '2':
        for(i=0;i<qntF;i++)
        {
            if (strcmp(nomeDig, nome[i]) == 0)
            {
                printf("\n\n+---------------------------------------------+");
                printf("\n\x1b[96m|               %dº FUNCIONÁRIO                |\x1b[0m",i+1);
                printf("\n+---------------------------------------------+");
                printf("\n  \x1b[96mCÓDIGO:\x1b[0m %s                                   ",cdg[i]);
                printf("\n  \x1b[96mNOME COMPLETO:\x1b[0m %s                            ",nome[i]);
                printf("\n  \x1b[96mSALÁRIO LIQUÍDO:\x1b[0m R$ %.2f                     ",sl[i]);
                printf("\n+---------------------------------------------+");
                encontrar = 1;
            }
              if (encontrar==0)
            {
              apagar();
              printf("\nO funcionário não foi encontrado. Tente digitar novamente.");
              buscar();
              i--;
            }
        }
        menuAlt();
        break;
    }
}

buscarListC()
{
    printf("\n+---------------------------------------------+");
    printf("\n|               \x1b[96mBUSCAR LISTAGEM\x1b[0m               |");
    printf("\n+---------------------------------------------+");
    printf("\n|             \x1b[96m[1]\x1b[0m - COMPLETA                  |");
    printf("\n|             \x1b[96m[2]\x1b[0m - SIMPLIFICADA              |");
    printf("\n+---------------------------------------------+");
    printf("\nDigite qual listagem deseja buscar: ");
    scanf("%s",&op6);
    switch(op6)
    {
        case '1':
        for(i=0;i<qntF;i++)
        {
            if (strcmp(cdgDig, cdg[i]) == 0)
            {
                printf("\n\n+---------------------------------------------+");
                printf("\n\x1b[96m|           %dº FUNCIONÁRIO.                   |\x1b[0m",i+1);
                printf("\n+---------------------------------------------+");
                printf("\n  \x1b[96mCÓDIGO:\x1b[0m %s                                   ",cdg[i]);
                printf("\n  \x1b[96mNOME COMPLETO:\x1b[0m %s                            ",nome[i]);
                printf("\n  \x1b[96mCEP:\x1b[0m %s                                      ",cep[i]);
                printf("\n  \x1b[96mCIDADE:\x1b[0m %s                                   ",cid[i]);
                printf("\n  \x1b[96mBAIRRO:\x1b[0m %s                                   ",bairro[i]);
                printf("\n  \x1b[96mRUA:\x1b[0m %s                                      ",rua[i]);
                printf("\n  \x1b[96mSALÁRIO BRUTO:\x1b[0m R$ %.2f                       ",sb[i]);
                printf("\n  \x1b[96mSALÁRIO LIQUÍDO:\x1b[0m R$ %.2f                     ",sl[i]);
                printf("\n+---------------------------------------------+");
                encontrar = 1;
            }
            if(encontrar == 0)
            {
              apagar();
              printf("\nO funcionário não foi encontrado. Tente digitar novamente.");
              buscar();
            }
        }
        menuAlt();
        break;
        case '2':
        for(i=0;i<qntF;i++)
        {
            if (strcmp(cdgDig, cdg[i]) == 0)
            {
                printf("\n\n+---------------------------------------------+");
                printf("\n\x1b[96m|             %dº FUNCIONÁRIO                   |\x1b[0m",i+1);
                printf("\n+---------------------------------------------+");
                printf("\n  \x1b[96mCÓDIGO:\x1b[0m %s                                   ",cdg[i]);
                printf("\n  \x1b[96mNOME COMPLETO:\x1b[0m %s                            ",nome[i]);
                printf("\n  \x1b[96mSALÁRIO LIQUÍDO:\x1b[0m R$ %.2f                     ",sl[i]);
                printf("\n+---------------------------------------------+");
                encontrar = 1;
            }
        
            else 
            {
              apagar();
              printf("\nO funcionário não foi encontrado. Tente digitar novamente.");
              buscar();
           }
        }
        menuAlt();
        break;
        default:
        printf("\nOpção inválida.");
        apagar();
        buscarListC();
        break;
    }
}

buscar()
{
    printf("\n+---------------------------------------------+");
    printf("\n|              \x1b[96mBUSCAR FUNCIONÁRIO\x1b[0m             |");
    printf("\n+---------------------------------------------+");
    printf("\n|         \x1b[96m[1]\x1b[0m - ATRAVÉS DO CÓDIGO             |");
    printf("\n|         \x1b[96m[2]\x1b[0m - ATRAVÉS DO NOME               |");
    printf("\n+---------------------------------------------+");
    printf("\nInsira a opção desejada: ");
    scanf("%s",&op5);
    apagar();

    switch(op5)
    {
        case '1':
        apagar();
        printf("\n Digite o código do funcionário que deseja listar os dados: ");
        scanf("%s",&cdgDig);
        buscarListC();
        break;
        case '2':
        apagar();
        printf("\n Digite o nome do funcionário que deseja listar os dados: ");
        scanf("%s",&nomeDig);
        buscarListN();
        break;
        default:
        printf("\nOpção inválida.");
        apagar();
        buscar();
        break;
    }
}

terceiromenu()
{

    printf("\n+---------------------------------------------+");
    printf("\n|                 \x1b[96mXPTO ATACADO\x1b[0m                |");
    printf("\n+---------------------------------------------+");
    printf("\n| \x1b[96m[1]\x1b[0m - LISTAR FUNCIONÁRIOS CADASTRADOS       |");
    printf("\n| \x1b[96m[2]\x1b[0m - BUSCAR INFORMAÇÕES DE UM FUNCIONÁRIO  |");
    printf("\n| \x1b[96m[3]\x1b[0m - EXCLUIR FUNCIONÁRIO CADASTRADO        |");
    printf("\n+---------------------------------------------+");
    printf("\nDigite a opção desejada: ");
    scanf("%s",&op2);
    switch(op2)
    {
        case '1':
          listagem();
          break;
        case '2':
          buscar();
          break;
        case '3':
          excluir();
          break;
        default:
          printf("\nOpção inválida.");
          apagar();
          terceiromenu();
          break;
    }
}

desconto()
{
    printf("\nSalário bruto: ");
    if (scanf("%f",&sb[i]) == 1)
    {
        inss = sb[i] * 0.11;
        printf("\nINSS: R$%.2f", inss);

        ticA = sb[i] * 0.05;
        printf("\nTicket Alimentação: R$%.2f", ticA);

        vt= sb[i] * 0.05;
        printf("\nVale Transporte: R$%.2f", vt);

        ps= sb[i] * 0.1;
        printf("\nPlano de Saúde: R$%.2f", ps);

        sl[i] = sb[i] - inss - ticA - vt - ps;
        printf("\nSalário Líquido: R$%.2f", sl[i]);
        fflush(stdout);
        apagar();
    }
    else
    {
        printf("\n+-----------------------------------+");
        printf("\n|   Você deve inserir um número!    |");
        printf("\n+-----------------------------------+\n");
        while (getchar() != '\n');
        desconto();
    }
}

ceps()
{
    printf("\nCEP: ");
    gets(cep[i]);

    if(strlen(cep[i]) == 8)
    {
      int valido = 1;
      for (j=0; j<8; j++)
        {
          if(!isdigit(cep[i][j]))
          {
            valido = 0;
            break;
          }
        }
      if (valido == 0)
      {
        printf("\n+-----------------------------------+");
        printf("\n|         CEP inválido              |");
        printf("\n+-----------------------------------+\n");
        ceps();
      }
    }
    else
    {
      printf("\n+---------------------------------+");
      printf("\n|  CEP deve conter 8 caracteres   |");
      printf("\n+---------------------------------+\n");
      ceps();
    }

}

codigos()
{
    for (i = 0; i < qntF; i++)
    {
        segmenu();
        printf("\n\n\x1b[96m---------------------%dº FUNCIONÁRIO----------------------\x1b[0m", i + 1);
        printf("\n\nPor favor insira o código com 4 caracteres: ");
        scanf("%s",&cdg[i]);
        int valido1 = 1;
        for (j=0; j<4; j++)
          {
            if(!isdigit(cdg[i][j]))
            {
              valido1 = 0;
              break;
            }
          }
        if(valido1 == 0)
        {
          printf("+-----------------+");
          printf("\n| Código inválido |");
          printf("\n+-----------------+");
          apagar();
          codigos();
          i--;
        }
        else
        {
          if (strlen(cdg[i]) == 4)
            {
              if (i > 0 && (atoi(cdg[i])) != (atoi(cdg[i - 1]) + 1))
              {
                printf("O código precisa ser sequencial, por favor insira um código válido!\n");
                apagar();
                i--;
              }
              else
              {
                printf("Código cadastrado!\n");
                getchar();
                nomes();
              }
            }
          else
          {
            printf("\n+-----------------------------------+");
            printf("\n|  O código deve ter 4 caracteres   |");
            printf("\n+-----------------------------------+\n");
            apagar();
            i--;
          }
          }
        }
        
}

excluir()
{
  int ec;
  printf("\n+---------------------------------------------+");
  printf("\n|              \x1b[96mEXCLUIR FUNCIONÁRIO\x1b[0m            |");
  printf("\n+---------------------------------------------+");
  printf("\n|         \x1b[96m[1]\x1b[0m - ATRAVÉS DO CÓDIGO             |");
  printf("\n|         \x1b[96m[2]\x1b[0m - ATRAVÉS DO NOME               |");              
  printf("\n+---------------------------------------------+");
  printf("\nInsira a opção desejada: ");
  scanf("%s",&op8);
  apagar();
  switch(op8)
    {
      case '1':
      printf("Digite o código do funcionário que deseja excluir: ");
      scanf("%s",&cdgDig2);
      int acho = 1;
      for(i=0;i<qntF;i++)
        {
          if(strcmp(cdgDig2,cdg[i]) == 0)
          {
            acho = i;
            break;
          }
        }
          if(acho == 0)
          {
            printf("\nCadastro encontrado! Você tem a plena certeza que deseja excluir?");
            printf("\n+------------------------+");
            printf("\n| \x1b[96m[1] -\x1b[0m  SIM\t\t\t |");
            printf("\n| \x1b[96m[2] -\x1b[0m  NÃO\t\t\t |");
            printf("\n+------------------------+");
            printf("\nSelecione a opção desejada: ");
            scanf("%d",&ec);
            int b;
            switch(ec)
              {
                case 1:
                  for(b=0;b<qntF;b++)
                    {
                      strcpy(nome[b],nome[b + 1]);
                      strcpy(cep[b],cep[b + 1]);
                      strcpy(cid[b],cid[b + 1]);
                      strcpy(bairro[b],bairro[b + 1]);
                      strcpy(rua[b],rua[b + 1]);
                      sb[b],sb[b + 1];
                      sl[b],sl[b + 1];
                      qntF--;
                    }
                  printf("\nCadastro excluido com sucesso!");
                  menuAlt();
                  break;
                case 2:
                  menuAlt();
                  break;
                default:
                  printf("\nopção inválida");
                  excluir();
              }
          }
          else if(!acho)
          {
            printf("\n+-----------------------+");
            printf("\n| Usuário não econtrado |");
            printf("\n+-----------------------+");
            excluir();
          }
      case 2:
      printf("Digite o nome do funcionário que deseja excluir: ");
      scanf("%s",&nomeDig2);
      int acho2 = 1;
      for(i=0;i<qntF;i++)
        {
          if(strcmp(nomeDig2,nome[i]) == 0)
          {
            acho2 = i;
            break;
          }
        }
          if(acho2 == 0)
          {
            printf("\nCadastro encontrado! Você tem a plena certeza que deseja excluir?");
            printf("\n+------------------------+");
            printf("\n| \x1b[96m[1] -\x1b[0m  SIM\t\t\t |");
            printf("\n| \x1b[96m[2] -\x1b[0m  NÃO\t\t\t |");
            printf("\n+------------------------+");
            printf("\nSelecione a opção desejada: ");
            scanf("%d",&ec);
            int b;
            switch(ec)
              {
                case 1:
                  for(b=0;b<qntF;b++)
                    {
                      strcpy(nome[b],nome[b + 1]);
                      strcpy(cep[b],cep[b + 1]);
                      strcpy(cid[b],cid[b + 1]);
                      strcpy(bairro[b],bairro[b + 1]);
                      strcpy(rua[b],rua[b + 1]);
                      sb[b],sb[b + 1];
                      sl[b],sl[b + 1];
                      qntF--;
                    }
                  printf("\nCadastro excluido com sucesso!");
                  menuAlt();
                  break;
                case 2:
                  menuAlt();
                  break;
                default:
                  printf("\nopção inválida");
                  excluir();
              }
          }
          else if(!acho)
          {
            printf("\n+-----------------------+");
            printf("\n| Usuário não econtrado |");
            printf("\n+-----------------------+");
            excluir();
          }
    }
}

ruas()
{
    printf("\nRua: ");
    gets(rua[i]);

    int valido = 0;

    for(j = 0; rua[i][j] != '\0'; j++)
    {
      if(!islower(rua[i][j]) && !isupper(rua[i][j]) && !isspace(rua[i][j]))
    {
      rua[i][j] = tolower(rua[i][j]);
      valido = 1;
      break;
    }
    }

    if (valido == 1)
    {
        printf("\n+-----------------------------------+");
        printf("\n|         Caractere inválido        |");
        printf("\n+-----------------------------------+\n");
        apagar();
        j--;
        ruas();
    }
    else
    {
        desconto();
    }
}

bairros()
{
    printf("\nBairro: ");
    gets(bairro[i]);

    int valido = 0;

    for(j = 0; bairro[i][j] != '\0'; j++)
    {
      if(!islower(bairro[i][j]) && !isupper(bairro[i][j]) && !isspace(bairro[i][j]))
    {
      bairro[i][j] = tolower(bairro[i][j]);
      valido = 1;
      break;
    }
    }

    if (valido == 1)
    {
        printf("\n+-----------------------------------+");
        printf("\n|         Caractere inválido        |");
        printf("\n+-----------------------------------+\n");
        //apagar();
        j--;
        bairros();
    }
    else
    {
        ruas();
    }
}

cidades()
{
  printf("\nCidade: ");
  gets(cid[i]);

  int valido = 0;
  for(j = 0; cid[i][j] != '\0'; j++)
  {
    if(!islower(cid[i][j]) && !isupper(cid[i][j]) && !isspace(cid[i][j]))
  {
    cid[i][j] = tolower(cid[i][j]);
    valido = 1;
    break;
  }
  }
  
  if (valido == 1)
    {
        printf("\n+-----------------------------------+");
        printf("\n|         Caractere inválido        |");
        printf("\n+-----------------------------------+\n");
        //apagar();
        j--;
        cidades();
    }
    else
    {
        bairros();
    }
}

nomes()
{
  printf("\nNome completo: ");
  gets(nome[i]);

  int valido = 0;
  int valido10 = 0;
  int t;
  for(t=0;t<i;t++)
    {
      if(strcmp(nome[i],nome[t])==0)
      {
        valido10 = 1;
        if(!isalpha(nome[i][t]) && !isspace(nome[i][t]))
        {
          valido = 1;
          break;
        }
        
      }
    }
  if(valido == 1 && valido10 == 1)
  {
    printf("\n+-----------------------------------+");
    printf("\n|           Nome repetido           |");
    printf("\n+-----------------------------------+\n");
    nomes();
  }
  else
  {
    valido = 0;
    for (j = 0; nome[i][j] != '\0'; j++)
      {
        if(!isalpha(nome[i][j]) && !isspace(nome[i][j]))
      {
        valido = 1;
        break;
      }
      }
    if (valido == 1)
    {
      printf("\n+-----------------------------------+");
      printf("\n|         Caractere inválido        |");
      printf("\n+-----------------------------------+\n");
      //apagar();
      j--;
      nomes();
    }
    else
        {
          ceps();
          cidades();
        }
  }
}

cadastros()
{
  printf("\nDigite quantos funcionários deseja cadastrar: ");
  if (scanf("%d", &qntF) != 1 || qntF <= 0 || qntF > 9999) 
  { 
    printf("\n+--------------------+");
    printf("\n| Caractere inválido |");
    printf("\n+--------------------+\n");
    while (getchar() != '\n');
    cadastros(); 
  } 
  else 
  {
    apagar();
   for (i = 0; i < qntF; i++) 
   {
     codigos();
    }
  }
}

main()
  {
    setlocale(LC_ALL,"Portuguese");
    concerto();
    terceiromenu();
    excluir();
  }