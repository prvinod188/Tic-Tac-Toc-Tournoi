#ifndef TOURNOI.HPP
#define TOURNOI.HPP
#include<iostream>
#include<string>
#include<vector>
#include"Partie.hpp"

using namespace std;

class Tournoi{
private:
    bool inscriptionClose;
    vector <Joueur *> listeJoueurs;
    void razScoreTournoi();
    void affcherGagnants();
    void afficherStats();
    
public:
    Tournoi();
    void inscription(Joueur &j);
    void lance_tournoi();
    void vide_participants();
};

ostream& operator<<(ostream& out, Tournoi &x);
#endif