#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // istringstream
#include <map>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>
#include "CSVcandidatos.h"

using namespace std;

static string iso_8859_1_to_utf8(string &str)
{
  // adaptado de: https://stackoverflow.com/a/39884120 :-)
  string strOut;
  for (string::iterator it = str.begin(); it != str.end(); ++it)
  {
    uint8_t ch = *it;
    if (ch < 0x80)
    {
      // já está na faixa ASCII (bit mais significativo 0), só copiar para a saída
      strOut.push_back(ch);
    }
    else
    {
      // está na faixa ASCII-estendido, escrever 2 bytes de acordo com UTF-8
      // o primeiro byte codifica os 2 bits mais significativos do byte original (ISO-8859-1)
      strOut.push_back(0b11000000 | (ch >> 6));
      // o segundo byte codifica os 6 bits menos significativos do byte original (ISO-8859-1)
      strOut.push_back(0b10000000 | (ch & 0b00111111));
    }
  }
  return strOut;
}

void CSVcandidatos::candidatosReader(string tipo_deputado, string arquivo_cand, string data_eleicao,
                             map<int, Candidato> candidatos, map<int, Partido> partidos)
{
    string celula;
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
            linha = iso_8859_1_to_utf8(linha);
            vector<string> linhaSplit;
            istringstream linhaStream(linha);
            while(getline(linhaStream, celula, ';'))
            {
                celula.erase(remove(celula.begin(), celula.end(), '\"' ), celula.end());
                linhaSplit.push_back(celula);
            }
            cout << linhaSplit[13] << " " << linhaSplit[18] << endl;
            Candidato c = Candidato(stoi(linhaSplit[13]), stoi(linhaSplit[68]), 
                                    stoi(linhaSplit[16]), linhaSplit[18], 
                                    stoi(linhaSplit[27]), linhaSplit[28], 
                                    stoi(linhaSplit[30]), linhaSplit[42], 
                                    stoi(linhaSplit[56]), stoi(linhaSplit[45]), 
                                    linhaSplit[67]);
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
