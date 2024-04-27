#include<iostream>
#include <iomanip>

    using namespace std;

    #define MAX 10 //Serie de ate 10 avaliações;

    class Estudante{
        private:
            string nome;
            double notas[MAX];
            int numNotas;

        public:
            Estudante() : nome(""), numNotas(0){
                for(int i = 0; i < MAX; i++){
                    notas[i] = 0.0;
                }
            
            }

            Estudante(string nome) : nome (nome), numNotas(0){
                for(int i = 0; i < MAX; i++){
                    notas[i] = 0.0;
                }
            }

            void defineNome(string nome){
                this -> nome = nome; 
            }

            string obtemNome (){
                return nome;
            }

            bool adicionaNota(double nota){
                if(numNotas < MAX){
                    notas[numNotas++] = nota;
                    return true; }
                    return false;
                }
            int obtemNumNotas(){
                return numNotas;
            }

             double obtemNota(int indice) {
        if (indice >= 0 && indice < numNotas) {
            return notas[indice]; }
        else {
            return -1.0; }
    }

           double obtemMedia() {
        if (numNotas == 0)
            return -1.0;
        double soma = 0.0;
        for (int i = 0; i < numNotas; ++i) {
            soma += notas[i]; }
        return soma / numNotas; }
    };

    void mostraEstudante(Estudante &e) {
      cout << e.obtemNome() << " [";
    int n = e.obtemNumNotas();
    for (int i=0; i<n; ++i) {
        if (i>0) cout << " ";
        cout << fixed << setprecision(1) << e.obtemNota(i);
    }
    cout << "] = " << fixed << setprecision(4) << e.obtemMedia() << endl;
}

int main() {
    Estudante e1;
    mostraEstudante(e1);
    e1.defineNome("Fulano");
    cout << (e1.adicionaNota(7.0)?"true":"false") << endl;
    cout << (e1.adicionaNota(10.0)?"true":"false") << endl;
    mostraEstudante(e1);
    Estudante e2("Beltrano");
    mostraEstudante(e2);
    double n = 1.0;
    while (e2.adicionaNota(n)) {
            mostraEstudante(e2);
            n = n + 1.0;
    }
    return 0;
}