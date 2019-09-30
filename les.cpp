#include <iostream>

using namespace std;

template<typename T>
class Lista{
    public:
        virtual bool insere(T) = 0;
        virtual int busca(T) const = 0;
        virtual bool deleta(int) = 0;
        virtual void imprime() const = 0;
};

template<typename T>
class LES:public Lista<T>{
    private:
        int n = 0;
        int tam = 0;
        int* vetor;
    public:
        LES(int size){
            this->tam = size;
            this->vetor = new T[tam];    
        }

        LES(const LES<T>& outra){
            this->vetor = new T[outra.tam];
            this->n = outra.n;
            this->tam = outra.tam; 
            copy(outra.vetor, outra.vetor + tam, this->vetor);
        }

        LES& operator=(const LES<T>& outra){
            this->~LES();
            this->vetor = new T[outra.tam];
            this->n = outra.n;
            this->tam = outra.tam; 
            copy(outra.vetor, outra.vetor + tam, this->vetor);
        }

        ~LES(){
            delete[] this->vetor;
        }

        bool insere(T num) override{

            if(n == tam){
                return false;
            }

            int i;
            for(i=0; i<n && vetor[i] < num; i++);

            for (int j = n; j > i ; j--) {
                vetor[j] = vetor[j-1];
            }

            vetor[i] = num;
            n++;
            return true;
            
        }

        int busca(T num) const override{
            for(int i=0; i < n; i++){
                if(vetor[i] == num){
                    return i;
                }
            }
            return -1;
        }

        void imprime() const override{
            for(int i=0; i < n; i++){
                cout << vetor[i] << endl;
            }
        }

        bool deleta(int pos) override{
            if(pos >= n){
                return false;
            }

            for(int i=pos; i < n-1; i++){
                vetor[i] = vetor[i+1];
            }
            n--;
            return true;
        }
        
};


int main(int argc, char const *argv[])
{
    
    LES<int>lista(4);
    lista.insere(20);
    lista.insere(10);
    lista.insere(5);
    lista.insere(1);
    lista.imprime();
    lista.deleta(2);
    lista.imprime();

    return 0;
}