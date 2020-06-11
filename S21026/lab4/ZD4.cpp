#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char **argv)
{
  int dlugosc=0;

  if(argc==1){
  printf("Nie podano nazwy pliku.\n");
  printf("Podaj długość ciągu:\n");
  scanf("%d", &dlugosc);
  int tabela[dlugosc];
  for(int i=0;i<dlugosc;i++)
  {
    printf("Podaj %d liczbę ciągu\n",i+1);
    scanf("%d",&tabela[i]);
  }
  }
  else
  {
    string line;
    printf("Podana nazwa pliku: %s\n",(argv[1]));
    ifstream myfile;
    myfile.open (argv[1]);
    if (myfile.is_open())
    {
      getline (myfile,line);
      dlugosc=stoi(line);
      int tabela[dlugosc];
      for(int i=0;i<dlugosc;i++)
      {
        getline(myfile,line);
        tabela[i] = stoi(line);
      }
      for(int i=dlugosc-1;i>-1;i--)
      {
        printf("%d\n",tabela[i]);  
      }
    myfile.close();
    }

    
  }
  
  
  return 0;
}