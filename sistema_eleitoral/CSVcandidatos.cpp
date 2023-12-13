#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // istringstream
#include <map>

#include "Candidato.h"
#include "CSVcandidatos.h"
#include "Partido.h"

using namespace std;

static void candidatosReader(string tipo_deputado, string arquivo_cand, string data_eleicao,
                             map<int, Candidato> candidatos, map<int, Partido> partidos)
{
    string codigoDepStr;
    ifstream inputStream;
    inputStream.exceptions(ifstream::badbit | ifstream::failbit);   
    int linhaAtual=1;
    try
    {
        inputStream.open("candidatos.csv");
        string linha;
        getline(inputStream,linha); // cabeçalho
        while (getline(inputStream,linha))
        {
            istringstream linhaStream(linha);


            linhaAtual++;
        }
        inputStream.close();
    }
    catch(const invalid_argument& e)
    {
        cerr << "Formato de candidatos.csv inválido. ";
        exit(1);
    }
    catch(const ifstream::failure& e)
    {
        if (!inputStream.eof())
        {
            cerr << "Não foi possível ler o arquivo candidatos.csv!" << endl;
            cerr << e.what() << endl;  // só para exemplificar
            exit(1);
        } else
        {
            inputStream.close();
        }
    }
}
