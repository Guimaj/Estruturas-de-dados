#include <iostream>
#include <string>
using namespace std;

template<typename T>
class IPilha{
public:
    virtual bool Empilha(T valor) = 0;
    virtual bool Desempilha() = 0;
    virtual void Imprime() = 0;
};

template<typename T>
class Pilha;

template<typename T>
class No{
private:
	T valor;
	No* anterior;
public:
	No(T valor){
		this->valor = valor;
		this->anterior = NULL;
	}
	template <typename>
	friend class Pilha;
};

template <typename T>
class Pilha:public IPilha<T>{
private:
	No<T>* topo;
	int num_elementos;
public:
    Pilha(){
		this->topo = NULL;
		this->num_elementos = 0;
    }
    ~Pilha(){
		while(Desempilha());
    }

    bool Empilha(T valor){
		No<T>* novo = new No<T>(valor);
		
		if(!topo){
			topo = novo;
		}
		else{
			novo->anterior = topo;
			topo = novo;
		}
		num_elementos++;
		return true;
    }

    bool Desempilha(){

		if(num_elementos == 0){
			return false;
		}

        No<T>* atual = topo;
		topo = topo->anterior;
		delete atual;
		num_elementos--;
		return true;
    }

    void Imprime(){

		if(num_elementos == 0){
			cout << "Pilha vazia" << endl;
		}
		else{
			No<T>* atual = topo;
			while(atual){
				cout << atual->valor << endl;
				atual = atual->anterior;
			}
		}
    }

    Pilha& operator<<(T valor){
		this->Empilha(valor);
		return *this;
    }
};


int main() {
	Pilha<int>p1;
	p1.Empilha(2);
	p1.Empilha(3);
	p1.Empilha(4);
	p1 << 5 << 6;
	p1.Imprime();
	
    return 0;
}
