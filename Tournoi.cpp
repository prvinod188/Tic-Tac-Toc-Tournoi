#include "Tournoi.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


ostream& operator<<(ostream& out, Tournoi &x) {
out << "Nouveau Tournoi" << endl; return out;
}

Tournoi::Tournoi (){
    this->inscriptionClose = false;
}

void Tournoi::razScoreTournoi(){
    for (int i=0; i < listeJoueurs.size(); i++){
       listeJoueurs[i]->razScoreTournoi();
    }
}

void Tournoi::inscription(Joueur &j){
    if(!inscriptionClose){
        listeJoueurs.push_back(&j);
    }else std::cout << "les inscriptions sont fermées" << std::endl;
}

void Tournoi::vide_participants(){
    inscriptionClose = false;
    listeJoueurs.clear();
}

void Tournoi::affcherGagnants(){
    vector <Joueur *> gagnants;
    float maxScore = 0;
    for (int i=0; i < listeJoueurs.size(); i++){
       if(listeJoueurs[i]->getScoreTournoi() > maxScore) maxScore = listeJoueurs[i]->getScoreTournoi();
    }
    for (int i=0; i < listeJoueurs.size(); i++){
       if(listeJoueurs[i]->getScoreTournoi() == maxScore) gagnants.push_back(listeJoueurs[i]);
    }
    cout << "\nLe(s) gagnants du tournoi sont :" << endl;
    for (int i=0; i < gagnants.size(); i++){
        cout << gagnants[i]->getIdJoueur() << std::endl;
    }
    cout << "avec le score " << maxScore<< endl;
}

void Tournoi::afficherStats(){
    cout << "\nLeScores totaux des participants :" << endl;
    for (int i=0; i < listeJoueurs.size(); i++){
        cout << *listeJoueurs[i] << std::endl;
    }
}

void Tournoi::lance_tournoi(){
    inscriptionClose = true;
    razScoreTournoi();
    for (int i=0; i < listeJoueurs.size()-1; i++){
        for (int j=i+1; j < listeJoueurs.size(); j++){
            Partie partie {listeJoueurs[i], listeJoueurs[j]};
            partie.lancePartie();
        }
    }
    affcherGagnants();
    afficherStats();
    
}