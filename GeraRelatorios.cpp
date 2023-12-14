#include "GeraRelatorios.h"
#include <iostream>
#include <iomanip>
#include <locale>
#include <list>

using namespace std;

bool ordernarCandidatosDecrescente (const Candidato& primeiro, const Candidato& segundo)
{
    int res = 0;
    res = segundo.getQtd_votos() - primeiro.getQtd_votos();
    if (res == 0) {
        res = segundo.getIdade() - primeiro.getIdade();
    }
    return res<0;
}

bool ordernarPartidosPorVotosTotais (const Partido& primeiro, const Partido& segundo)
{
    int res = 0;
    res = segundo.getVotosTotais() - primeiro.getVotosTotais();
    if (res == 0) {
        res = primeiro.getNr_partido() - segundo.getNr_partido();
    }
    return res<0;
}

bool ordernarPartidosPorCandidatoMaisVotado ( Partido& primeiro,  Partido& segundo)
{
    int res = 0;
    if (primeiro.getCandidatos().size() == 0 && segundo.getCandidatos().size() == 0) {
        return false;
    }
    else if (primeiro.getCandidatos().size() == 0) {
        return false;
    }
    else if (segundo.getCandidatos().size() == 0) {
        return true;
    }


    list<Candidato> candidatos_primeiro; 
    for (auto &c : primeiro.getCandidatos())
    {
        int sc = c.second.getCd_situacao_candidato_tot();
        if (sc == 2 || sc == 16)
        {
            candidatos_primeiro.push_back(c.second);
        }
    }

    list<Candidato> candidatos_segundo; 
    for (auto &c : segundo.getCandidatos())
    {
        int sc = c.second.getCd_situacao_candidato_tot();
        if (sc == 2 || sc == 16)
        {
            candidatos_segundo.push_back(c.second);
        }
    }

    candidatos_primeiro.sort(ordernarCandidatosDecrescente);
    candidatos_segundo.sort(ordernarCandidatosDecrescente);

    res = candidatos_segundo.front().getQtd_votos() - candidatos_primeiro.front().getQtd_votos();
            
    if (res == 0) {
        res = primeiro.getNr_partido() - segundo.getNr_partido();
    }

    return res<0;
}



void GeraRelatorios::geraRelatorio(string tipo_deputado, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
   locale brasilLocale("pt_BR.UTF-8");
   cout.imbue(brasilLocale);

    int tipo_deputado_int = 0;
    if (tipo_deputado == "estadual")
    {
        tipo_deputado_int = 7;
    }
    else if (tipo_deputado == "federal")
    {
        tipo_deputado_int = 6;
    }

    geraRelatorio1(tipo_deputado_int, candidatos, partidos);
    geraRelatorio2(tipo_deputado_int, candidatos, partidos);
    geraRelatorio3(tipo_deputado_int, candidatos, partidos);
    geraRelatorio4(tipo_deputado_int, candidatos, partidos);
    geraRelatorio5(tipo_deputado_int, candidatos, partidos);
    geraRelatorio6(tipo_deputado_int, candidatos, partidos);
    geraRelatorio7(tipo_deputado_int, candidatos, partidos);
    geraRelatorio8(tipo_deputado_int, candidatos, partidos);
    geraRelatorio9(tipo_deputado_int, candidatos, partidos);
    geraRelatorio10(tipo_deputado_int, candidatos, partidos);
}

 void GeraRelatorios::geraRelatorio1(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{   
    int nr_vagas = 0;
    
    for (auto &c : candidatos)
    {
        int sc = c.second.getCd_situacao_candidato_tot();
        int st = c.second.getCd_sit_tot_turno();
        int td = c.second.getCd_cargo();
        if ((sc == 2 || sc == 16)&&(st ==2 || st == 3)&&(td == tipo_deputado_int))
        {
            nr_vagas++;
        }
    }

    cout << "Número de vagas: " << nr_vagas << endl << endl;
}

void GeraRelatorios::geraRelatorio2(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{

    list<Candidato> ordem; 
    
    for (auto &c : candidatos)
    {
        int sc = c.second.getCd_situacao_candidato_tot();
        int st = c.second.getCd_sit_tot_turno();
        int td = c.second.getCd_cargo();
        if ((sc == 2 || sc == 16)&&(st ==2 || st == 3)&&(td == tipo_deputado_int))
        {
            ordem.push_back(c.second);
        }
    }

    ordem.sort(ordernarCandidatosDecrescente);

    if (tipo_deputado_int == 6)
        cout << "Deputados federais eleitos: " << endl;
    else if (tipo_deputado_int == 7)
        cout << "Deputados estaduais eleitos: " << endl;

    int idx = 1;
    for (auto &c : ordem)
    {
        string fed = "";
        if (c.getNr_federacao() != -1)
        {
            fed = "*";
        }
        
        cout << idx << " - " << fed; 
        c.imprimeCandidato();
        cout << endl;

        idx++;
    }
}

void GeraRelatorios::geraRelatorio3(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
    int nr_vagas = 0;
    
    for (auto &c : candidatos)
    {
        int sc = c.second.getCd_situacao_candidato_tot();
        int st = c.second.getCd_sit_tot_turno();
        int td = c.second.getCd_cargo();
        if ((sc == 2 || sc == 16)&&(st ==2 || st == 3)&&(td == tipo_deputado_int))
        {
            nr_vagas++;
        }
    }

    list<Candidato> ordem; 
    
    for (auto &c : candidatos)
    {
        int sc = c.second.getCd_situacao_candidato_tot();
        int td = c.second.getCd_cargo();
        if ((sc == 2 || sc == 16)&&(td == tipo_deputado_int))
        {
            ordem.push_back(c.second);
        }
    }

    ordem.sort(ordernarCandidatosDecrescente);

    cout << endl << "Candidatos mais votados (em ordem decrescente de votação e respeitando número de vagas):" << endl;
   
    int idx = 1;
    for (auto &c : ordem)
    {
        string fed = "";
        if (c.getNr_federacao() != -1)
        {
            fed = "*";
        }
        
        cout << idx << " - " << fed; 
        c.imprimeCandidato();
        cout << endl;

        idx++;        
        
        if (idx == nr_vagas+1) break;
    }
}

void GeraRelatorios::geraRelatorio4(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
    int nr_vagas = 0;
    
    for (auto &c : candidatos)
    {
        int sc = c.second.getCd_situacao_candidato_tot();
        int st = c.second.getCd_sit_tot_turno();
        int td = c.second.getCd_cargo();
        if ((sc == 2 || sc == 16)&&(st ==2 || st == 3)&&(td == tipo_deputado_int))
        {
            nr_vagas++;
        }
    }
    list<Candidato> ordem; 
    
    for (auto &c : candidatos)
    {
        int sc = c.second.getCd_situacao_candidato_tot();
        int td = c.second.getCd_cargo();
        if ((sc == 2 || sc == 16)&&(td == tipo_deputado_int))
        {
            ordem.push_back(c.second);
        }
    }

    ordem.sort(ordernarCandidatosDecrescente);

    cout << endl << "Teriam sido eleitos se a votação fosse majoritária, e não foram eleitos:"<< endl << "(com sua posição no ranking de mais votados)" << endl;
   
    int idx = 1;
    for (auto &c : ordem)
    {
        string fed = "";
        if (c.getNr_federacao() != -1)
        {
            fed = "*";
        }

        if (!(c.getCd_sit_tot_turno() == 2 || c.getCd_sit_tot_turno() == 3)){
            cout << idx << " - " << fed; 
            c.imprimeCandidato();
            cout << endl;
        }
        idx++;        
        
        if (idx == nr_vagas+1) break;
    }
}

void GeraRelatorios::geraRelatorio5(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
    int nr_vagas = 0;

    list<Candidato> ordem; 
    
    for (auto &c : candidatos)
    {
        int sc = c.second.getCd_situacao_candidato_tot();
        int st = c.second.getCd_sit_tot_turno();
        int td = c.second.getCd_cargo();
        if ((sc == 2 || sc == 16)&&(st ==2 || st == 3)&&(td == tipo_deputado_int))
        {
            nr_vagas++;
        
        }
    }

    for (auto &c : candidatos)
    {
        int sc = c.second.getCd_situacao_candidato_tot();
        int td = c.second.getCd_cargo();
        if ((sc == 2 || sc == 16)&&(td == tipo_deputado_int))
        {
            ordem.push_back(c.second);
        }
    }

    ordem.sort(ordernarCandidatosDecrescente);

    cout << endl << "Eleitos, que se beneficiaram do sistema proporcional:" << endl << "(com sua posição no ranking de mais votados)" << endl;
   
    int idx = 1;
    for (auto &c : ordem)
    {
        string fed = "";
        if (c.getNr_federacao() != -1)
        {
            fed = "*";
        }

        if ((c.getCd_sit_tot_turno() == 2 || c.getCd_sit_tot_turno() == 3) && idx > nr_vagas){
            cout << idx << " - " << fed; 
            c.imprimeCandidato();
            cout << endl;
        }

        idx++;        
    }
}

void GeraRelatorios::geraRelatorio6(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
    cout << endl << "Votação dos partidos e número de candidatos eleitos:" << endl;

    list<Partido> p_ordem; 

    for (auto &p : partidos)
    {
            p_ordem.push_back(p.second);
    }

    p_ordem.sort(ordernarPartidosPorVotosTotais);

    int idx = 1;
    for (auto &p : p_ordem)
    {
        int qtd_eleitos_partido = 0;

        for (auto &c : p.getCandidatos())
        {
            int st = c.second.getCd_sit_tot_turno();
            int td = c.second.getCd_cargo();
            if ((st == 2 || st == 3)&&(td == tipo_deputado_int))
            {
                qtd_eleitos_partido++;
            }
        }
        
        string plural_vtsTots = "";
        if (p.getVotosTotais() > 1)
        {
            plural_vtsTots = "s";
        }
        

        string plural_vtsNomTot = "l";
        if (p.getVotosNominaisTotal() > 1) {
            plural_vtsNomTot = "is";
        }

        string plural_eleito = "";
        if (qtd_eleitos_partido > 1) {
            plural_eleito = "s";
        }

        cout << idx << " - "; 
        p.imprimePartido(); 
        cout << " " << p.getVotosTotais() << " voto" << plural_vtsTots << " (" << p.getVotosNominaisTotal() << " nomina";
        cout << plural_vtsNomTot << " e " << p.getVotosLegenda() << " de legenda), " << qtd_eleitos_partido;
        cout << " candidato" << plural_eleito << " eleito" << plural_eleito << endl;

        idx++;        
    }
}

void GeraRelatorios::geraRelatorio7(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
    cout << endl << "Primeiro e último colocados de cada partido:" << endl;

    list<Partido> p_ordem; 

    for (auto &p : partidos)
    {
            p_ordem.push_back(p.second);
    }

    p_ordem.sort(ordernarPartidosPorCandidatoMaisVotado);

    int idx = 1;

    for (auto &p : p_ordem)
    {
        if (p.getCandidatos().size() == 0) continue;

        list<Candidato> c_ordem;
        
        for (auto &c : p.getCandidatos())
        {
            int td = c.second.getCd_cargo();
            if ((td == tipo_deputado_int) && c.second.getNm_tipo_destinacao_votos() == false)
            {
                c_ordem.push_back(c.second);
            }
        }

        c_ordem.sort(ordernarCandidatosDecrescente); 

        Candidato melhor = c_ordem.front();


        if (melhor.getQtd_votos() <= 0) continue;


        Candidato pior = c_ordem.back();
        
        /*
        while (pior.getQtd_votos() < 0)
        {
            c_ordem.pop_back();
            pior = c_ordem.back();
        }
        */

        string plural_melhor="";
        if (melhor.getQtd_votos() > 1)
        {
            plural_melhor="s";
        }
        
        string plural_pior="";
        if (pior.getQtd_votos() > 1)
        {
            plural_pior="s";
        }

        cout << idx << " - ";
        p.imprimePartido();
        cout << " " << melhor.getNm_urna_candidato() << " (" << to_string(melhor.getNr_candidato());
        cout << ", " << melhor.getQtd_votos() << " voto" << plural_melhor <<")" << " / " << pior.getNm_urna_candidato();
        cout << " (" << to_string(pior.getNr_candidato()) << ", " << pior.getQtd_votos() << " voto" << plural_pior <<")" << endl;
        
        idx++;
    }
}

void GeraRelatorios::geraRelatorio8(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
    cout << endl << "Eleitos, por faixa etária (na data da eleição):" << endl;

    int idade_menor_30 = 0;
    int idade_30_40 = 0;
    int idade_40_50 = 0;
    int idade_50_60 = 0;
    int idade_maior_60 = 0;
    
    double porcentagem_menor_30 = 0;
    double porcentagem_30_40 = 0;
    double porcentagem_40_50 = 0;
    double porcentagem_50_60 = 0;
    double porcentagem_maior_60 = 0;
    
    for (auto &c : candidatos) {
        int st = c.second.getCd_sit_tot_turno();
        int td = c.second.getCd_cargo();
        int idade = c.second.getIdade();

        if (td == tipo_deputado_int && (st == 2 || st == 3)) {
            if (idade < 30)
                idade_menor_30++;
            else if (idade >= 30 && idade < 40)
                idade_30_40++;
            else if (idade >= 40 && idade < 50)
                idade_40_50++;
            else if (idade >= 50 && idade < 60)
                idade_50_60++;
            else if (idade >= 60)
                idade_maior_60++;
        }
    }

    int total = idade_menor_30 + idade_30_40 + idade_40_50 + idade_50_60 + idade_maior_60;

    porcentagem_menor_30 = ((double) idade_menor_30 / total) * 100;
    porcentagem_30_40 = ((double) idade_30_40 / total) * 100;
    porcentagem_40_50 = ((double) idade_40_50 / total) * 100;
    porcentagem_50_60 = ((double) idade_50_60 / total) * 100;
    porcentagem_maior_60 = ((double) idade_maior_60 / total) * 100;

    cout << "      Idade < 30: " << idade_menor_30 << " (" << fixed << setprecision(2) << porcentagem_menor_30 << "%)" << endl;
    cout << "30 <= Idade < 40: " << idade_30_40 << " (" << fixed << setprecision(2) << porcentagem_30_40 << "%)" << endl;
    cout << "40 <= Idade < 50: " << idade_40_50 << " (" << fixed << setprecision(2) << porcentagem_40_50 << "%)" << endl;
    cout << "50 <= Idade < 60: " << idade_50_60 << " (" << fixed << setprecision(2) << porcentagem_50_60 << "%)" << endl;
    cout << "60 <= Idade     : " << idade_maior_60 << " (" << fixed << setprecision(2) << porcentagem_maior_60 << "%)" << endl;
}

void GeraRelatorios::geraRelatorio9(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
    int qtd_masculino = 0;
    int qtd_feminino = 0;
    double porcentagem_masculino = 0;
    double porcentagem_feminino = 0;

    for(auto &candidato : candidatos)
    {   
        if((candidato.second.getCd_sit_tot_turno() == 2 || candidato.second.getCd_sit_tot_turno() == 3) && candidato.second.getCd_cargo() == tipo_deputado_int) {
        if(candidato.second.getCd_genero() == MASCULINO)
        {
            qtd_masculino++;
        }
        else if(candidato.second.getCd_genero() == FEMININO)
        {
            qtd_feminino++;
        }
        }
        
    }

    porcentagem_masculino = ((double) qtd_masculino / (qtd_feminino + qtd_masculino)) * 100;
    porcentagem_feminino = ((double) qtd_feminino / (qtd_feminino + qtd_masculino)) * 100;

    cout << "\nEleitos, por gênero:" << endl;
    cout << "Feminino:  " << qtd_feminino << " (" << fixed << setprecision(2) << porcentagem_feminino << "%)" << endl;
    cout << "Masculino:  " << qtd_masculino << " (" << fixed << setprecision(2) << porcentagem_masculino << "%)" << endl;
}
 void GeraRelatorios::geraRelatorio10(int tipo_deputado_int, map<int, Candidato> candidatos, map<int, Partido> partidos)
{
    int total_votos_legenda = 0;
    int total_votos_nomimais = 0;
    int total_votos_validos = 0;
    double percentual_votos_legenda = 0;
    double percentual_votos_nomimais = 0;

    for (auto &partido : partidos)
    {
        total_votos_legenda += partido.second.getVotosLegenda();
        total_votos_nomimais += partido.second.getVotosNominaisTotal();
    }

    total_votos_validos = total_votos_legenda + total_votos_nomimais;
    percentual_votos_legenda = ((double) total_votos_legenda / total_votos_validos) * 100;
    percentual_votos_nomimais = ((double) total_votos_nomimais / total_votos_validos) * 100;


    cout << "\nTotal de votos válidos:    " << total_votos_validos << endl;
    cout << "Total de votos nominais:   " << total_votos_nomimais << " (" << fixed << setprecision(2) << percentual_votos_nomimais << "%)" << endl;
    cout << "Total de votos de legenda: " << total_votos_legenda << " (" << fixed << setprecision(2) << percentual_votos_legenda << "%)" << endl;

}
