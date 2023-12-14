#include <iostream> // cout
#include <fstream>  // ifstream
#include <sstream>  // istringstream
#include <map>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

#include "Candidato.h"
#include "CSVvotacao.h"
#include "Partido.h"

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

void CSVvotacao::votacaoReader(const string &tipo_deputado,const string &arquivo_vot, map<int, Candidato> &candidatos,
            map<int, Partido> &partidos) 
{
    int tipo_deputado_int;
    if (tipo_deputado == "estadual")
    {
        tipo_deputado_int = 7;
    }
    else if (tipo_deputado == "federal")
    {
        tipo_deputado_int = 6;
    }

    string celula;
    ifstream inputStream;
    inputStream.exceptions(ifstream::badbit | ifstream::failbit);   
    int linhaAtual=1;
    
    int nr_notavel=-1;
    try
    {
        inputStream.open("votacao.csv");
        string linha;
        getline(inputStream,linha); // cabeçalho
        while (getline(inputStream,linha))
        {
            linha = iso_8859_1_to_utf8(linha);
            vector<string> linhaSplit;
            istringstream linhaStream(linha);
            while(getline(linhaStream, celula, ';'))
            {
                celula.erase(remove(celula.begin(), celula.end(), '\"'), celula.end());
                linhaSplit.push_back(celula);
            }
            
            nr_notavel = stoi(linhaSplit[19]);
            if (nr_notavel < 95 || nr_notavel > 98)
            {
                if (tipo_deputado_int == stoi(linhaSplit[17]))
                {
                    if (candidatos.find(nr_notavel) != candidatos.end())
                    {
                        if (candidatos[nr_notavel].getNm_tipo_destinacao_votos())
                        {
                            //adiciona votos de legenda ao partido do candidato
                            partidos[candidatos[nr_notavel].getNr_partido()].addVotosLegenda(stoi(linhaSplit[21]));
                        }
                        else
                        {
                            if (candidatos[nr_notavel].getCd_situacao_candidato_tot() == 2 || candidatos[nr_notavel].getCd_situacao_candidato_tot() == 16)
                            {
                                candidatos[nr_notavel].addVotos(stoi(linhaSplit[21]));
                            }
                        }
                    }
                    else if(partidos.find(nr_notavel) != partidos.end())
                    {
                        partidos[nr_notavel].addVotosLegenda(stoi(linhaSplit[21]));
                    }
                }
            }
            
            linhaAtual++;
        }
        inputStream.close();
    }
    catch(const invalid_argument& e)
    {
        cerr << "Formato de votacao.csv inválido. ";
        exit(1);
    }
    catch(const ifstream::failure& e)
    {
        if (!inputStream.eof())
        {
            cerr << "Não foi possível ler o arquivo votacao.csv!" << endl;
            cerr << e.what() << endl;  // só para exemplificar
            exit(1);
        } else
        {
            inputStream.close();
        }
    }
}