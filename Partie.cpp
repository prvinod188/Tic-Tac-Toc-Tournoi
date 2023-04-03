#include "Partie.hpp"
#include <iostream>
using namespace std;


ostream& operator<<(ostream& out, Partie &x) {
out <<"Partie entre " << x.getJoueur1().getIdJoueur()<<" et "<<x.getJoueur2().getIdJoueur() << endl; return out;
}

Partie::Partie (Joueur *j1, Joueur *j2):joueur_1{j1},joueur_2{j2}{
    this->grille = zeroMatrix();
    this->nbCouts = 0;
}

vector <vector<int> > Partie::zeroMatrix(){
    vector <vector<int> > matrix;
    vector <int> line;
    for( int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            line.push_back(0);
        }
        matrix.push_back(line);
    }
     return matrix;
}

Joueur Partie::getJoueur1(){
    return *joueur_1;
}

Joueur Partie::getJoueur2(){
    return *joueur_2;
}

void Partie::afficherGrille(){
    for( int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            cout << grille[i][j] <<" ";
        }
        cout << "\n" << endl;
    }
        
}

bool Partie::grillePlein(){
    for( int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            if (grille[i][j] == 0) return false;
        }
    }
    return true;
}
int Partie::getGagnant(){
    //first line
    if(grille[0][0]!=0 && grille[0][0] == grille[0][1] && grille[0][0] == grille[0][2]) return grille[0][0];
    //second line
    if(grille[1][0]!=0 && grille[1][0] == grille[1][1] && grille[1][0] == grille[1][2]) return grille[1][0];
    //third line
    if(grille[2][0]!=0 && grille[2][0] == grille[2][1] && grille[2][0] == grille[2][2]) return grille[2][0];
    
    //first column
    if(grille[0][0]!=0 && grille[0][0] == grille[1][0] && grille[0][0] == grille[2][0]) return grille[0][0];
    //second column
    if(grille[0][1]!=0 && grille[0][1] == grille[1][1] && grille[0][1] == grille[2][1]) return grille[0][1];
    //third column
    if(grille[0][2]!=0 && grille[0][2] == grille[1][2] && grille[0][2] == grille[2][2]) return grille[0][2];
    
    //first diagonal
    if(grille[0][0]!=0 && grille[0][0] == grille[1][1] && grille[0][0] == grille[2][2]) return grille[0][0];
    //second diagonal
    if(grille[0][2]!=0 && grille[0][2] == grille[1][1] && grille[0][2] == grille[2][0]) return grille[0][2];
    
    return 0;
    
}
float Partie::calculerScoreGagne(){
    return  9.0 / (nbCouts + nbCouts % 2);
}
void Partie::terminePartie(int gagnat){
      switch(gagnat) {
          case 1:
            joueur_1->majScores(calculerScoreGagne());
            cout << "--> Bravo Joueur " <<joueur_1->getIdJoueur() <<" !!!" << endl;
            break;
          case 2:
            joueur_2->majScores(calculerScoreGagne());
            cout << "--> Bravo Joueur " <<joueur_2->getIdJoueur() <<" !!!" << endl;
            break;
          case 0:
            cout << "--> Partie nulle" << endl;
            break;
       }
       cout << *joueur_1 << "\n"<< *joueur_2<< endl;
}
void Partie::lancePartie(){
     int joueurActif = 1;
     int i,j = -1;
     cout<< *this << endl;
     while (!this->grillePlein() && this->getGagnant() == 0){
         cout <<"Entrez une case i j"<< endl;
         cin>> i;
         cin>> j;
        
         if(joueurActif == 1){
             joueurActif = 2;
             grille[i][j] = 1;
         }else{
             joueurActif = 1;
             grille[i][j] = 2;
         }
         nbCouts++;
         afficherGrille();
     }
     terminePartie(getGagnant());
}
