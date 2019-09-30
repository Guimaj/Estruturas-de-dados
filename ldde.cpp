#include <iostream>


template<typename T>
class Ildde{
    virtual bool insere(T) = 0;
    virtual bool imprime() = 0;
    virtual int busca(T) const = 0;
    virtual bool remove(int) = 0;
};

template<typename T>
class Ldde;

template<typename T>
class No{
    private: 
        No* proximo;
        No* anterior;
        T valor;
        friend class Ldde<T>; 
    public:
        No(T valor){
            this->proximo = NULL;
            this->anterior = NULL;
            this->valor = valor;
        }
};

template<typename T>
class Ldde:public Ildde<T>{
    private:
        No<T>* primeiro;
        No<T>* ultimo;
        int size;
    public:
        Ldde(){
            this->primeiro = NULL;
            this->ultimo = NULL;
            this->size = 0;
        }
       
        ~Ldde(){
            while(this->remove(0));
        }

        int busca(T valor) const override{
            No<T>* atual = primeiro;
            int pos = 0;
            while(atual){
                if(atual->valor == valor){
                    return pos;
                }
                pos++;
                atual = atual->proximo;
            }

            return -1;
        }

        bool insere(T valor) override{
            
            No<T>* novo = new No<T>(valor);
            No<T>* atual = primeiro;
            No<T>* anterior = NULL;

            while (atual && atual->valor < valor)
            {
                anterior = atual;
                atual = atual->proximo;
            }
            
            if(anterior == NULL){
                primeiro = novo;
                ultimo = novo;
            }
            else{
                anterior->proximo = novo;             
            }
            
            if(atual){
                atual->anterior = novo;             
            }
            else{
                ultimo = novo;
            }
            
            novo->proximo = atual;
            novo->anterior = anterior;
            size++;
            return true;
        }
        

        bool imprime() override {
            if(size <= 0){
                std::cout << "lista vazia" << std::endl;
                return false;
            }
                
            No<T>* atual = primeiro;
            while(atual){
                std::cout << atual->valor << std::endl;
                atual = atual->proximo;
            }
            
            return true;
            
        }

        bool remove(int idx) override{
            
            if(idx < 0 || idx >= size){
                return false;
            }


            No<T>* atual = primeiro;
            No<T>* anterior = NULL;

            while(atual && idx > 0){
                anterior = atual;
                atual = atual->proximo;
                idx--;
            }

            if(anterior){
                if(anterior->proximo){
                    anterior->proximo = atual->proximo;    
                }else{
                    ultimo = anterior;
                    anterior->proximo = NULL;
                }
            }
            else{
                primeiro = atual->proximo;
                atual->anterior = NULL;
            }
        
            delete atual;
            size--;
            return true;   

        }

};


int main(int argc, char const *argv[])
{
    Ldde<int>l1;
    l1.insere(10);
    l1.insere(9);
    l1.insere(7);
    l1.insere(5);
    l1.insere(1);
    l1.insere(2);
    l1.imprime();

    return 0;
}
