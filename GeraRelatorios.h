#ifndef GERARELATORIOS_H
#define GERARELATORIOS_H
#include <map>
#include <string>
#include "Candidato.h"
#include "Partido.h"

class GeraRelatorios {
    public:
    static void geraRelatorio(string tipo_deputado, map<int, Candidato> candidatos, map<int, Partido> partidos);
    static void geraRelatorio1(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos);
    static void geraRelatorio2(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos);
    static void geraRelatorio3(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos);
    static void geraRelatorio4(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos);
    static void geraRelatorio5(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos);
    static void geraRelatorio6(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos);
    static void geraRelatorio7(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos);
    static void geraRelatorio8(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos);
    static void geraRelatorio9(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos);
    static void geraRelatorio10(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos);

};

#endif