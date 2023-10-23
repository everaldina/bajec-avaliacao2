#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Data {
	int dia, mes, ano;
	public:
	
	/*
	O método abaixo retornará -1 se d1 é anterior a d2
	Retornará 0 se d1 = d2
	Retornará +1 se d1 é posterior a d2
	*/	
	static int compara(Data d1, Data d2) { 
		return 0;
	}
	
	Data (int _dia, int _mes, int _ano) {
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	string toString() {
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista {
	public:
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
};

class ListaNomes {
	vector<string> lista;
	
	public:
	void entradaDeDados() {
		lista.push_back("Teste");
	}
	
	void mostraMediana() {
		int mediana;
		if (n%2 == 0) {
			mediana = (lista[n/2] + lista[(n/2)-1])/2;
		} else {
			mediana = lista[n/2];
		}
		cout << "A mediana da lista é: " << mediana << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar o primeiro nome alfabeticamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar o ultimo nome alfabeticamente" << endl;
	}
};

class ListaDatas  {
	vector<Data> lista;
	
	public:
		
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() {
		
	}
	void mostraMaior() {
		maior = lista[n-1];
		cout << "O maior elemento da lista é: " << maior << endl;
	}

	static bool compIdade(int i1, int i2) {
		return i1 < i2;
	}

	void ordena() {
		sort(lista.begin(), lista.end(), compIdade);
	}

	void listarEmOrdem() {
		ordena();

		cout << "Idades:" << endl;
		for (int i : lista) {
			cout << i << endl;
		}
	}
};
 
int main () {
	vector<Lista*> listaDeListas;

	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
}