#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

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

class ListaDatas  : public Lista{
	vector<Data> lista;
	
	public:
		
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() {
		int n;
		cout << "Quantas datas terá a lista?" << endl;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int dia, mes, ano;

			cout << "Digite a data " << i << ":" << endl;
			
			cout << "Digite o dia" << endl;
			cin >> dia;
			cout << "Digite o mes" << endl;
			cin >> mes;
			cout << "Digite o ano" << endl;
			cin >> ano;

			lista.push_back(Data(dia, mes, ano));
		}
	}
	
	void mostraMediana() {
		int index, tam;

		tam = lista.size();

		tam % 2 == 0 ? index = tam / 2 : index = (tam + 1) / 2;

		ordena();
		cout << "Mediana: " << lista[index].toString() << endl;
	}
	
	void mostraMenor() {
		Data menor = lista[0];

		for (Data d : lista) {
			if (Data::compara(d, menor) == -1) {
				menor = d;
			}
		}

		cout << "Menor: " << menor.toString() << endl;
	}

	void mostraMaior() {
		Data maior = lista[0];

		for (Data d : lista) {
			if (Data::compara(d, maior) == 1) {
				maior = d;
			}
		}

		cout << "Maior: " << maior.toString() << endl;
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

class ListaSalarios : public Lista {
	vector<float> lista;
	
	public:

	void entradaDeDados() {
		cout << "Quantos elementos vão existir na lista? ";
		cout << fixed << setprecision(2); //para mostrar sempre 2 casas decimais
		int n;
		cin >> n;
		for (int i=0; i<n; i++) {
			cout << "Digite o " << i+1 << "o. elemento: ";
			float x;
			cin >> x;
			this->lista.push_back(x);
		}
		this->ordena();
	}
			
	void mostraMediana() {
		int meio = this->lista.size()/2;
		if (this->lista.size()%2==0) {
			cout << "A mediana é:" << endl;
			cout << (this->lista[meio-1] + this->lista[meio])/2 << endl;
		} else {
			cout << this->lista[meio] << endl;
		}
	}
	
	void mostraMenor() {
		//como a lista ja ta ordenada, o menor é o primeiro
		cout << "O menor salario é:";
		cout << this->lista[0] << endl;
	}
	void mostraMaior() {
		//como a lista ja ta ordenada, o maior é o ultimo
		cout << "O maior salario é:";
		cout << this->lista[this->lista.size()-1] << endl;
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


class ListaIdades: public Lista  {
	vector<int> lista;
	int menor, maior, n;
	
	public:
	void entradaDeDados() {
		cout << "Quantos elementos terá a lista de idades?" << endl;
		cin >> n;
		for (int i=0; i<n; i++) {
			int idade;
			cout << "Digite a idade " << i+1 << endl;
			cin >> idade;
			lista.push_back(idade);
		}
		ordena();
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
		menor = lista[0];
		cout << "O menor elemento da lista é: " << menor << endl;

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