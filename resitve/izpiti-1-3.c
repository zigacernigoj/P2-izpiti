// izpiti komplet 1/5 - naloga 3.

#include <stdio.h>
#include <stdlib.h>

#define MIN_V 8
#define MAX_V 20

void gesla (int vCiljna, int mesto, int stCrk, int stStevk, char *znaki);

int main(int argc, char const *argv[]) {
  char *znaki = (char *) malloc(MAX_V * sizeof(char));
  for(int v = MIN_V; v <= MAX_V; v += 2) {
    gesla(v, 0, 0, 0, znaki); // izpise vsa gesla dolzine v
  }
  free(znaki);
  return 0;
}

void gesla (int vCiljna, int mesto, int stCrk, int stStevk, char *znaki) {
  if(mesto == vCiljna) { // geslo je bilo generirano
    for(int i = 0; i < vCiljna; i++) {
      printf("%c", znaki[i]);
    }
    printf("\n");
  }
  else {
    // zavsak mozen znak na trenutnem mestu generiraj vse moznosti za mesto + 1 do vCiljna
    if(stCrk < vCiljna / 2) {
      for(int c = 'a'; c <= 'z'; c++) {
        znaki[mesto] = c;
        gesla(vCiljna, mesto + 1, stCrk + 1, stStevk, znaki);
      }
    }
    if(stStevk < vCiljna / 2) {
      for(int c = '0'; c <= '9'; c++) {
        znaki[mesto] = c;
        gesla(vCiljna, mesto + 1, stCrk, stStevk + 1, znaki);
      }
    }
  }
}
