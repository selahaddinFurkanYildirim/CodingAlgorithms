#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define max(a,b) ((a)<(b)?(b):(a))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) ((a)<0?(0-(a)):(a))

#ifdef __cplusplus
#define debug(a) Debug(#a,a,'\n',sizeof(a))
void Debug(char* n,int d,char E,int size){
  printf("%s : %d%c",n,d,E);
}
void Debug(char* n,float f,char E,int size){
  printf("%s : %f%c",n,f,E);
}
void Debug(char* n,char c,char E,int size){
  printf("%s : %c%c",n,c,E);
}
void Debug(char* n,char *s,char E,int size){
  printf("%s : %s%c",n,s,E);
}
void Debug(char* n,int *s,char E,int size){
  printf("%s : {",n);
  for(int i=0;i<(int)(size/sizeof(int))-1;i++){
    printf("%d,",s[i]);
  }
  printf("%d}",s[(int)(size/sizeof(int))-1]);
  printf("%c",E);
}
void Debug(char* n,float *s,char E,int size){
  printf("%s : {",n);
  for(int i=0;i<(int)(size/sizeof(float))-1;i++){
    printf("%f,",s[i]);
  }
  printf("%f}",s[(int)(size/sizeof(float))-1]);
  printf("%c",E);
}
void Debug(char* n,char *s[],char E,int size){
  printf("%s : {",n);
  for(int i=0;i<(int)(size/sizeof(char*))-1;i++){
    printf("\"%s\",",s[i]);
  }
  printf("\"%s\"}",s[(int)(size/sizeof(char*))-1]);
  printf("%c",E);
}
#else
#define debug(a) _Generic((a), double:debugF,double*:debugFX, float:debugF,char:debugC,char*: debugS, int: debugD,int*:debugDX,float*:debugFX,char**:debugSX)(#a,a,'\n',sizeof(a))
void debugD(char* n,int d,char end,int size){
  printf("%s : %d%c",n,d,end);
}
void debugF(char* n,float f,char end,int size){
  printf("%s : %f%c",n,f,end);
}
void debugC(char* n,char c,char end,int size){
  printf("%s : %c%c",n,c,end);
}
void debugS(char* n,char *s,char end,int size){
  printf("%s : %s%c",n,s,end);
}
void debugDX(char* n,int *s,char end,int size){
  printf("%s : {",n);
  for(int i=0;i<(int)(size/sizeof(int))-1;i++){
    printf("%d,",s[i]);
  }
  printf("%d}",s[(int)(size/sizeof(int))-1]);
  printf("%c",end);
}
void debugFX(char* n,float *s,char end,int size){
  printf("%s : {",n);
  for(int i=0;i<(int)(size/sizeof(float))-1;i++){
    printf("%f,",s[i]);
  }
  printf("%f}",s[(int)(size/sizeof(float))-1]);
  printf("%c",end);
}
void debugSX(char* n,char *s[],char end,int size){
  printf("%s : {",n);
  for(int i=0;i<(int)(size/sizeof(char*))-1;i++){
    printf("\"%s\",",s[i]);
  }
  printf("\"%s\"}",s[(int)(size/sizeof(char*))-1]);
  printf("%c",end);
}
#endif


// int main() {
//     int intValue = 42;
//     int intValues[]={45,15,5};
//     char charValue = 'A';
//     float floatValue = 3.14;
//     float floatValues[] = {3.14,1.45,5.5};
//     char* stringValue = "Hello, World!";
//     char* stringValues[] = {"Hello, World!","mynameisblabla"};

//     debug(intValue);
//     debug(intValues);
//     debug(charValue);
//     debug(floatValue);
//     debug(floatValues);
//     debug(stringValue);
//     debug(stringValues);
//     return 0;
// }
