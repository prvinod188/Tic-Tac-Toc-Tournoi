#include "Joueur.hpp"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, Joueur &x) {
out << "scores du joueur " << x.getIdJoueur()<<": tournoi "<<x.getScoreTournoi()<<", total "<<x.getScoreTotal()<< endl; return out;
}

Joueur::Joueur (string idJoueur){
    this->idJoueur = idJoueur;
    this->scoreTotal = 0;
    this->scoreTournoi = 0;
}

string Joueur::getIdJoueur(){
    return this->idJoueur;
}

float Joueur::getScoreTotal(){
    return this->scoreTotal;
}

float Joueur::getScoreTournoi(){
    return this->scoreTournoi;
}



void Joueur::majScores(float scoreGagne){
    scoreTournoi+=scoreGagne;
    scoreTotal+=scoreGagne;
}

void Joueur::razScoreTournoi(){
    this->scoreTournoi = 0;
}