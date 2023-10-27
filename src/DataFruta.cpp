#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <iomanip>
//#include <ctime>

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
		time_t tempo1 = 0;
		time_t tempo2 = 0;
		
		tm tm1 = *gmtime(&tempo1);
		tm tm2 = *gmtime(&tempo2);
		
		tm1.tm_mday = d1.dia;
		tm1.tm_mon = d1.mes - 1;
		tm1.tm_year = d1.ano - 1900;
		
		tm2.tm_mday = d2.dia;
		tm2.tm_mon = d2.mes - 1;
		tm2.tm_year = d2.ano - 1900;
		
		time_t newt1 = mktime(&tm1);
		time_t newt2 = mktime(&tm2);

		if(newt1 < newt2) {return -1;}
		else if(newt1 == newt2) {return -0;}
		return 1;
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
	virtual void entradaDeDados() = 0;
	virtual void mostraMediana() = 0;
	virtual void mostraMenor() = 0;
	virtual void mostraMaior() = 0;
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

		cout << "Quantos nomes tera a lista?: ";
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
			cout << "Mediana dos nomes: " << lista[(lista.size()/2) - 1] << endl;
		else
			cout << "Mediana dos nomes: " << lista[(lista.size()/2)] << endl;
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
		string data;
		string aux = "";
		cout << "Quantas datas tera a lista?: ";
		cin >> n;

		for (int i = 0; i < n; i++) {
			int dia, mes, ano;
			int flag = 1;

			cout << "Digite a data " << i + 1 << ": ";
			cin >> data;

			for(int i = 0; i < data.length(); i++) {

				if(data[i] == '/') {
					if(flag == 1){
						dia = stoi(aux);
						flag++;
					}
					else if(flag == 2){
						mes = stoi(aux);
						flag++;
					}
					aux = "";
				}
				else{
					aux += data[i];
				}
			}

			ano = stoi(aux);
			aux = "";

			lista.push_back(Data(dia, mes, ano));
		}
	}
	
	void mostraMediana() {
		int index, tam;

		tam = lista.size()-1;

		tam % 2 == 0 ? index = tam / 2 : index = (tam + 1) / 2;

		ordena();
		cout << "Mediana das datas: " << lista[index].toString() << endl;
	}
	
	void mostraMenor() {
		Data menor = lista[0];

		for (Data d : lista) {
			if (Data::compara(d, menor) == -1) {
				menor = d;
			}
		}

		cout << "Menor data: " << menor.toString() << endl;
	}

	void mostraMaior() {
		Data maior = lista[0];

		for (Data d : lista) {
			if (Data::compara(d, maior) == 1) {
				maior = d;
			}
		}

		cout << "Maior data: " << maior.toString() << endl;
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
		cout << "Quantos salarios tera a lista?: ";
		cout << fixed << setprecision(2); //para mostrar sempre 2 casas decimais
		int n;
		cin >> n;
		for (int i=0; i<n; i++) {
			cout << "Digite o salario " << i + 1 << ": ";
			float x;
			cin >> x;
			this->lista.push_back(x);
		}
		this->ordena();
	}
			
	void mostraMediana() {
		int meio = this->lista.size()/2;
		cout << "Mediana dos salarios: ";
		if (this->lista.size()%2==0) {
			cout << (this->lista[meio-1] + this->lista[meio])/2 << endl;
		} else {
			cout << this->lista[meio] << endl;
		}
	}
	
	void mostraMenor() {
		//como a lista ja ta ordenada, o menor é o primeiro
		cout << "Menor salario: ";
		cout << this->lista[0] << endl;
	}
	void mostraMaior() {
		//como a lista ja ta ordenada, o maior é o ultimo
		cout << "Maior salario: ";
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
		cout << "Quantas idades tera a lista?: ";
		cin >> n;
		for (int i=0; i<n; i++) {
			int idade;
			cout << "Digite a idade " << i+1 << ": ";
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
		cout << "Mediana das idades: " << mediana << endl;
	}
	
	void mostraMenor() {
		menor = lista[0];
		cout << "Menor idade: " << menor << endl;

	}
	void mostraMaior() {
		maior = lista[n-1];
		cout << "Maior idade: " << maior << endl;
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
	cout << endl;
	
	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	cout << endl;
	
	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	cout << endl;
	
	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	cout << endl;
	
	for (Lista* l : listaDeListas) {
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
		cout << endl;
	}
}