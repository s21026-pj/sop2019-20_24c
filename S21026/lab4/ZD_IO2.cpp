#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char **argv)
{
  int dlugosc=0;
  char tabela[100];
  bzero(tabela,100);

  if(argc==1){
  printf("Nie podano nazwy pliku.\n");
  printf("Podaj długość ciągu:\n");
  scanf("%d", &dlugosc);
  int temp;
  for(int i=0;i<dlugosc;i++)
  {
    printf("Podaj %d liczbę ciągu\n",i+1);
    scanf("%i",&temp);
    tabela[i]=temp;
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
      //int tabela[dlugosc];
      for(int i=0;i<dlugosc;i++)
      {
        getline(myfile,line);
        tabela[i] = stoi(line);
      }
    myfile.close();
    }
  }
  
for(int i=dlugosc-1;i>-1;i--)
  {
    printf("%d\n",tabela[i]);  
    }

fstream plik;
    plik.open( "dane", ios::out );
    if( plik.good() )
    {
        cout << "Zapis do pliku binarnego:" << endl;
        plik.write( & tabela[0], 100 );
        plik.close();
        cout << "SUKCES" << endl;

    } else cout << "Error! Nie udalo utworzyc sie pliku!" << endl;
    
return 0;
}