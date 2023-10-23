#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
	virtual void ordena() = 0;
	virtual void listarEmOrdem() = 0;
};

class ListaNomes : public Lista{
	vector<string> lista;
	
	public:
	
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() {
		int n;
		string nome;

		cout << "Quantos nomes você quer digitar? ";
		cin >> n;
		cin.ignore();
		for (int i=0; i<n; i++){
			cout << "Digite o nome " << i+1 << ": ";
			getline(cin, nome);
			lista.push_back(nome);
		}
		ordena();
	}
		
	void mostraMediana() {
		if(lista.size() % 2 == 0)
			cout << "Mediana: " << lista[(lista.size()/2) - 1] << endl;
		else
			cout << "Mediana: " << lista[(lista.size()/2)] << endl;
	}
	
	void mostraMenor() {
		cout << "Menor nome: " << lista[0] << endl;
	}

	void mostraMaior() {
		cout << "Maior nome: " << lista[lista.size() - 1] << endl;
	}

	static bool compNome(string s1, string s2) {
		return s1 < s2;
	}

	void ordena() {
		sort(lista.begin(), lista.end(), compNome);
	}

	void listarEmOrdem() {
		ordena();

		cout << "Nomes:" << endl;
		for (string s : lista) {
			cout << s << endl;
		}
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
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
	}

	static bool compData(Data d1, Data d2) {
		return Data::compara(d1, d2) < 0;
	}

	void ordena() {
		sort(lista.begin(), lista.end(), compData);
	}

	void listarEmOrdem() {
		ordena();

		cout << "Datas:" << endl;
		for (Data d : lista) {
			cout << d.toString() << endl;
		}
	}
};

class ListaSalarios  {
	vector<float> lista;
	
	public:
	
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() {
		
	}
			
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de salarios" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar o menor dos salarios" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar o maior dos salarios" << endl;
	}

	static bool compSalario(float s1, float s2) {
		return s1 < s2;
	}

	void ordena() {
		sort(lista.begin(), lista.end(), compSalario);
	}

	void listarEmOrdem() {
		ordena();

		cout << "Salarios:" << endl;
		for (float s : lista) {
			cout << s << endl;
		}
	}
};


class ListaIdades  {
	vector<int> lista;
	
	public:
		
		/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() {
		
	}
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a menor das idades" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a maior das idades" << endl;
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
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
	
}
    
