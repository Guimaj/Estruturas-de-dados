#include <iostream>

using namespace std;

template<typename T>
class Ifila{

    virtual bool enfileira(T) = 0; 
    virtual bool imprime() = 0;
    virtual bool desenfileira() = 0;
};


template<typename T>
class Fila : public Ifila<T>{
    private:
        T* vetor;
        int n;
        int tam;
        int inicio;
        int fim;
    public:
        Fila(int size){
            this->vetor = new T[size];
            this->n = 0;
            this->tam = size;
            this->inicio = 0;
            this->fim = 0;
        }
        
        Fila(const Fila<T>& fila2){
           this->vetor = new T[fila2.tam];
           this->n = fila2.n;
           this->tam = fila2.tam;
           this->inicio = fila2.inicio;
           this->fim = fila2.fim;
           copy(fila2.vetor, fila2.vetor + tam, this->vetor); 
        }
        
        Fila& operator=(const Fila<T>& fila2){
            this->~Fila();
            this->vetor = new T[fila2.tam];
            this->n = fila2.n;
            this->tam = fila2.tam;
            this->inicio = fila2.inicio;
            this->fim = fila2.fim;
            copy(fila2.vetor, fila2.vetor + tam, this->vetor);          
        }

        ~Fila(){
            delete[] vetor;
        }
         
        bool enfileira(T valor){
            if(n >= tam){
                cout << "Lista cheia!" << endl;
                return false;
            }

            int pos = (inicio + n)%tam;
            fim = pos;
            vetor[pos] = valor;
            n++;
            return true;
        }

        bool imprime(){
            if(n == 0){
                cout << "Fila vazia!" << endl;
                return false;
            }
            int cont = 0;
        
            for (int i = inicio; cont < n; i=(i+1)%tam)
            {
                cout << vetor[i] << endl;
                cont++;
            }
            return true;
        }


        bool desenfileira(){
            if(n == 0){
                cout << "Fila vazia" << endl;
                return false;
            }
            
            inicio = (inicio + 1)%tam;
            n--;
            return true;
        }
};


int main(int argc, char const *argv[])
{
    Fila<int>f1(3);
    f1.enfileira(1);
    f1.enfileira(2);
    f1.enfileira(4);
    cout << "FILA 1" << endl;
    f1.imprime();
    Fila<int>f2 = f1;
    cout << "FILA 2" << endl;
    f2.imprime();
    
    return 0;
}
