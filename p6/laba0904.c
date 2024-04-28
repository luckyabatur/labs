#include <stdio.h>

struct bolnoy {
  char name[50];
  int t;
  char* subjects[];

};

typedef struct bolnoy bolnoy;

int preprocessing(){
  FILE *out = fopen("base.txt", "w");
  if (!out){
      return 1;
  }
  bolnoy chel;
  while (scanf("%[^;];%d\n", chel.name, &chel.t) != EOF){
    fwrite(&chel, sizeof(bolnoy), 1, out);
  }
  fclose(out);
  return 0;
}

int main(){
  int err;
  err = preprocessing();
  if (err != 0){
    printf("Ne otkryli fayl\n");
    return err;
  }

  FILE *in = fopen("base.txt", "r");
  bolnoy chel;
  int srt=0, kol=0;
  while (fread(&chel, sizeof(bolnoy), 1, in) == 1){
    srt += chel.t;
    kol += 1;
  }
  double midt = srt / kol;
  fseek(in, 0, SEEK_SET);
  printf("Mid temp: %f\n", midt);
  while (fread(&chel, sizeof(bolnoy), 1, in) == 1){
    if (chel.t < midt) {
      printf("Patient: %s temper is lower, then mid temper\n", chel.name);
    }
  }
  fclose(in);
}