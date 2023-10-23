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
		int n;
		string nome;

		cout << "Quantos nomes você quer digitar?" << endl;
		cin >> n;
		for (int i=0; i<n; i++){
			cout << "Digite o nome " << i+1 << endl;
			getline(cin, nome);
			lista.push_back(nome);
		}
	}
	
	void mostraMediana() {
		string mediana;

		


		cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
	}
	
	void mostraMenor() {
		string menor = lista[0];

		for (string s: lista) {
			if (s < menor) {
				menor = s;
			}
		}

		cout << "Menor nome: " << menor << endl;
	}

	void mostraMaior() {
		string maior = lista[0];

		for (string s: lista) {
			if (s > maior)
				maior = s;
		}

		cout << "Maior nome: " << maior << endl;
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
	
	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	
	for (Lista* l : listaDeListas) {
		//l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
}