#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int maks(int a,int b);
int min(int a,int b);
int sum(int a,int b);
int forAll(int tablica[],int liczbaElementow, int (*funkcjaa)(int,int));
typedef int( * funkcja)(int, int);
int (*funk[3])(int,int);

int main(int argc, char **argv)
{
  funk[0]=maks;
  funk[1]=min;
  funk[2]=sum;

  int z,n,v;
  printf("Podaj numer funkcji\n0: Maksimum\n1: Minimum\n2: Suma\n");
  scanf("%d",&z);
  printf("Podaj liczbę elementów do wczytania\n");
  scanf("%d",&n);
  int tabela[n];
  for(int i=0;i<n;i++)
  {
    printf("Podaj %d liczbę ciągu\n",i+1);
    scanf("%d",&tabela[i]);
  }
  printf("Wynik: %d\n",forAll(tabela,n,funk[z]));
return 0;
}

int maks(int a,int b){
    if(a>b){
        return a;
        }else{return b;}
}
int min(int a,int b){
    if(a<b){
        return a;
        }else{return b;}
}
int sum(int a,int b){
    return a+b;
}
int forAll(int tablica[],int liczbaElementow, int (*funkcjaa)(int,int)){
    int v,n;
    v=tablica[0];
    n=liczbaElementow;
    for(int i=1;i<n;i++)
  {
    v=funkcjaa(tablica[i],v);
  }
    return v;
}
