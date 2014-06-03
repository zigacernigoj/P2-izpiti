// izpiti komplet 4/5 - naloga 3.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Oseba {
  char* ip;
  int stOtrok;
  struct _Oseba** otroci;
} Oseba;

void naslednjiki(Oseba *oseba);

int main(int argc, char const *argv[])
{
  // TODO: testni primer
  return 0;
}

bool naslednjikiIstegaNivoja(Oseba *oseba, int nivo) {
  if(nivo == 0) {
    printf("%s\n", oseba->ip);
    return true;
  }
  bool vsajEdenIzpisan = false;
  for(int i = 0; i < oseba->stOtrok; i++)
    if (naslednjikiIstegaNivoja(oseba->otroci[i], nivo - 1))
      vsajEdenIzpisan = true;
  return vsajEdenIzpisan;
}

void naslednjiki(Oseba *oseba) {
  int nivo = 1;
  bool vsajEden = true;
  while(vsajEden)
    vsajEden = naslednjikiIstegaNivoja(oseba, nivo++);
}
