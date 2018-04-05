#include <iostream>

using namespace std;

class Album{
public:
  void CompraSobre(int n_en_sobre);
  void Status(void);
  bool EstaLleno(int n, int n_en_album);
  int EnAlbum(int n_en_album);
  Album(int n);
  
private:
  int n_total;
  int n_repetidas;
  int n_en_album;
  int n_sobres_comprados;
  
  int *album;
  int *repetidas;
};

void Album::Status(void){
  cout << n_en_album << " "<<n_repetidas << endl;
}

void Album::CompraSobre(int n_en_sobre){
  int lamina;
  for(int i=0;i<n_en_sobre;i++){
    lamina = rand()%n_total;
    if(album[lamina]==0){
      album[lamina] = 1;
      n_en_album++;
    }else{
      repetidas[lamina] +=1;
      n_repetidas++;
    }
  }
}

int Album::EnAlbum(int n_en_album){
  int a = 0;
  while(n_en_album % 5 != 0 ){
    a+=1;
  }	
  return n_en_album/5 + a;
}
Album::Album(int n){
  album = new int[n];
  repetidas = new int[n];
  n_total = n;
  n_repetidas = 0;
  n_en_album = 0 ;
  for (int i=0;i<n_total;i++){
    album[i] = 0;
    repetidas[i] = 0;
  }
}

bool Album::EstaLleno(int n, int n_en_album){
  while (n == n_en_album ){
    return true;
  }

}

int main(){ 
  srand(time(0));
  Album A(660);
  int b = A.EnAlbum();
  while (A.EstaLleno(660, b) == false){
    A.CompraSobre(5);
    A.Status();
  }
}
