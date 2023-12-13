#include "Acervo.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
    if(argc != 5) {
        cout << "Argumentos invalidos" << endl;
        return 0;
    }

    string tipo_deputado = argv[1];
    tipo_deputado = tipo_deputado.substr(2);
    string arq_cand = argv[2];
    string arq_vot = argv[3];
    string data_eleicao = argv[4];

    cout << tipo_deputado << endl;
    cout << arq_cand << endl;
    cout << arq_vot << endl;
    cout << data_eleicao << endl;
    
    Acervo acervo(tipo_deputado, arq_cand, arq_vot, data_eleicao);
    acervo.geraRelatorio(tipo_deputado);
    
    return 0;
}