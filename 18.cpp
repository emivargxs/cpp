
#include <iostream>

using namespace std;

class Robo {
    private:
        int px;
        int py;
        int orientacao;

    public:
    Robo(): px(0), py(0), orientacao(0) {}

    void giraDireita() {
        orientacao--;
        if(orientacao < 0) orientacao = 3;
    }

    void giraEsquerda() {
        orientacao++;
        if(orientacao > 3) orientacao = 0;
    }

    void avanca() {
        switch(orientacao) {
            case 0: px++; break;
            case 1: py++; break;
            case 2: px--; break;
            case 3: py--; break;
        }
    }

    void posiciona(int x, int y, int o) {
        px = x;
        py = y;
        orientacao = o;
    }

    int obtemPosicaoX() {
        return px;
    }

    int obtemPosicaoY() {
        return py;
    }

    int obtemOrientacao() {
        return orientacao;
    }

    void movimenta(string operacoes) {
        for(char operacao : operacoes) {
            switch(operacao) {
                case 'D': giraDireita(); break;
                case 'E': giraEsquerda(); break;
                case 'A': avanca(); break;
            }
        }
    }
};
   

int main() {
  int px, py, orientacao;
  string operacao;
  
  // LEITURA
  cin >> px;
  cin >> py;
  cin >> orientacao;
  cin >> operacao;
  // TESTE DE FUNCIONAMENTO
  Robo *robo = new Robo();
  robo->posiciona(px,py,orientacao);
  if ( robo->obtemPosicaoX()!=px || robo->obtemPosicaoY()!=py ||
       robo->obtemOrientacao()!=orientacao )
      return 1;
  // OPERACAO
  robo->movimenta(operacao);
  // SAIDA
  cout << robo->obtemPosicaoX() << " ";
  cout << robo->obtemPosicaoY() << " ";
  cout << robo->obtemOrientacao() << endl;
  delete robo;
  return 0;
}
