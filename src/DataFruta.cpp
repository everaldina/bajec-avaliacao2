#include <iostream>
#include <string>
#include <vector>
#include <ctime>

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
	virtual void entradaDeDados() =0;
	virtual void mostraMediana() =0;
	virtual void mostraMenor() =0;
	virtual void mostraMaior() =0;
};

class ListaNomes {
	vector<string> lista;
	
	public:
	
	/*
	O método abaixo pergunta ao usuários quantos
	elementos vão existir na lista e depois
	solicita a digitação de cada um deles
	*/	
	void entradaDeDados() {
		lista.push_back("Teste");
	}
		
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de strings" << endl;
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
	
	void mostraMediana() {
		cout << "Aqui vai mostrar a mediana da lista de datas" << endl;
	}
	
	void mostraMenor() {
		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
	}
	void mostraMaior() {
		cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
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
    
