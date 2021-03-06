/*
Q1) Implemente uma função em C que receba uma string como parâmetro e substitua todas as suas
letras por predecessoras do alfabeto, trocando maiúsculas por minúsculas. Por exemplo, a string
“Amor” seria alterada para “zLNQ”. Esta função deve obedecer o seguinte protótipo: void
shift_troca_string (char *str). A letra ‘a’ deve ser substituída por ‘Z’ (e ‘A’ por ‘z’). Caracteres que não
forem letras devem ser substituídos por ‘!’. Sabe-se que A = 65, Z = 90, a = 97 e z = 122.
*/

/**
 * Solução.
 *
 * Intervalo das letras
 * A = 65
 * B = 66
 * Z = 90
 * a = 97
 * b = 98
 * z = 122
 *
*/
#include <stdio.h>
#include <stdlib.h>

void shift_troca_string (char *str);

int main(void) {

  /* Assim não funciona por essa razão
  https://stackoverflow.com/questions/164194/why-do-i-get-a-segmentation-fault-when-writing-to-a-string-initialized-with-cha
  char *str = (char*) malloc(100*sizeof(char));
  str = "Amor";
  */

  char str[] = "Amor";

  shift_troca_string(str);

  printf("\n\n%s\n\n", str);

  return 0;
}

void shift_troca_string (char *str) {
  if (str[0]) {
    int c = (int) str[0];

    // se for um A vira z
    if (c == 65) {
      str[0] = 97;
    }

    // se for um a vira Z
    if (c == 97) {
      str[0] = 90;
    }

    // se estiver entre B e Z soma 31
    if (c >= 66 && c <= 90) {
      str[0] += 31;
    }

    // se estiver entre b e z subtrai 33
    if (c >= 98 && c <= 122) {
      str[0] -= 33;
    }

    shift_troca_string(&str[1]);
  }
}