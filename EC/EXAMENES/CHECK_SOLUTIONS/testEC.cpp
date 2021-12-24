#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include "color.h"

using namespace std;

int main(int narg, char* argv[]){
    vector<string> vector_lectura;
    map<string, vector<string>> mapa_tests;
    pair<string, vector<string>> par;
    
    ifstream fin;
    fin.open(argv[1]);
    while(fin && fin.peek() != EOF){
        string linea;
        getline(fin, linea);
        
        stringstream in_linea(linea);
        string palabra;
        while(getline(in_linea, palabra, ' '))
            vector_lectura.push_back(palabra);
        
        par.first = vector_lectura.front();
        vector_lectura.erase(vector_lectura.begin());
        par.second = vector_lectura;
        
        mapa_tests.insert(par);
        vector_lectura.clear();
    }
    
    cout << KYEL << BOLD("CODIGOS DISPONIBLES: ") << endl;
    map<string,vector<string>>::iterator it;
    for(it = mapa_tests.begin(); it != mapa_tests.end(); ++it)
		cout << (*it).first << endl;
   
    
    string code_test;
    cout << KYEL << BOLD("INSERTE CODIGO DE TEST: ");
    cin >> code_test;
    
    vector<string> selected_test = mapa_tests[code_test];
    
    vector<string> solutions_user;
    string respuesta;
    cout << endl << KYEL << BOLD("INSERTE RESPUESTAS: ");
    for(unsigned int i=0; i<selected_test.size(); i++){
        cin >> respuesta;
        solutions_user.push_back(respuesta);
    }
    
    cout << left;
    cout << endl << endl << KYEL << BOLD("MOSTRANDO RESPUESTAS...") << endl;
    cout << KGRN << BOLD("EXAMEN [") << code_test << KGRN << BOLD("]: ") << setw(10);
    for(unsigned i=0; i<selected_test.size(); i++){
        cout << KGRN << selected_test[i] << " "; 
    }
    
    cout << endl << KYEL << BOLD("EXAMEN RESPUESTAS:     ") << setw(10);
    for(unsigned i=0; i<solutions_user.size(); i++){
        if(solutions_user[i] == selected_test[i])
            cout << KGRN << solutions_user[i] << " ";
        else
            cout << KRED << solutions_user[i] << " ";
    }
    
    cout << endl << endl;
    
    return EXIT_SUCCESS;
}
