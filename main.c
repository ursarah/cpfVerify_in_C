#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  int menu;
  while (menu != 3)
  {
    int digitos = 0, peso, ultimo_digito = 0, soma_produtos = 0, result_soma_prod = 0, primeiro_ver = 0, segundo_ver = 0;
    long long int cpf_temp, cpf;
    char cpf_completo[11], cpf_prim_ver[2], cpf_seg_ver[2];

    // Verifica se menu é igual a 3, se for sai do laço
    printf("Menu de verificação:\n[1]Calcular os digitos\n[2]Informação de desenvolvedor\n[3]Encerrar programa: ");
    scanf("%d", &menu);

    if (menu == 1)
    {
      // Digitar seu cpf
      printf("Digite seu cpf: ");
      scanf("%lld", &cpf);

      // Deixar o cpf em uma variavel e converter ele em string
      cpf_temp = cpf;
      sprintf(cpf_completo, "%lld", cpf);

      // Criando um cpf temporario para não modificar o cpf original
      long long int cpf_digitos = cpf;

      // Fazendo a contagem de quantos digitos tem o cpf e verificando se ele tem 9 digitos ou não
      // Se não tiver 9 digitos da cpf invalido, se não vai pro menu de calculo
      while (cpf_digitos != 0)
      {
        cpf_digitos = cpf_digitos / 10;
        digitos++;
      }
      if (digitos != 9)
      {
        printf("CPF invalido");
        break;
      }

      // Primeiro digito
      for (peso = 2; peso <= 10; peso++)
      {
        // Pega o resto de cpf / 10 que quer dizer ser o ultimo digito do numero
        ultimo_digito = cpf_temp % 10;
        // Aqui tira o ultimo digito do cpf para que no proximo laço tenha um digito a menos
        cpf_temp = cpf_temp / 10;
        // Aqui é a soma dos produtos do ultimo digito
        soma_produtos = (peso * ultimo_digito) + soma_produtos;
      }
      primeiro_ver = (soma_produtos * 10) % 11;

      if (primeiro_ver == 10)
      {
        primeiro_ver = 0;
      }
      printf("==*==*==*==*==*==*==*==*==*==*==*==*==\n");
      printf("O primeiro numero verificador é %d\n", primeiro_ver);

      // ==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==
      // CODIGOS A MAIS
      // Transforma o primeiro verificador em string
      sprintf(cpf_prim_ver, "%d", primeiro_ver);
      // Concatena o verificador com o resto do cpf
      strcat(cpf_completo, cpf_prim_ver);

      // Transforma o cpf que era string em inteiro de volta
      long long int cpf_com_prim_ver = atoll(cpf_completo);
      // ==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==

      // Segundo digito
      soma_produtos = 0;
      for (peso = 2; peso <= 11; peso++)
      {
        ultimo_digito = cpf_com_prim_ver % 10;
        cpf_com_prim_ver = cpf_com_prim_ver / 10;
        soma_produtos = (peso * ultimo_digito) + soma_produtos;
      }

      result_soma_prod = soma_produtos % 11;

      if (result_soma_prod < 2)
      {
        segundo_ver = 0;
      }
      else
      {
        segundo_ver = 11 - result_soma_prod;
      }

      printf("O segundo numero verificador é %d\n", segundo_ver);

      // ==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==
      // CODIGOS A MAIS
      sprintf(cpf_seg_ver, "%d", segundo_ver);
      strcat(cpf_completo, cpf_seg_ver);
      // ==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==*==

      printf("O CPF completo é: %s\n", cpf_completo);
      printf("==*==*==*==*==*==*==*==*==*==*==*==*==\n");
    }
  }
  return 0;
}
