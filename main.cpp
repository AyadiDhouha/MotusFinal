#include <iostream>
#include<stdlib.h>
#include<time.h>
#include<fstream>
#include "Joueur.h"
#include "Lettre.h"
#include "Tentative.h"
#include <vector>
#include<algorithm>
#include<string>
using namespace std;

string setmotadeviner(){
    int i=rand()%50+1;
ifstream f("fichier.txt");
string m;
for (int j=1; j<i; j++ ) {
	getline(f,m);

}
return m;
}

int main (){
    vector<string> v;
    v.push_back("R");
    v.push_back("J");
    v.push_back("B");

    int A;
	string nom ,mot;
	cout<<"    *********** BIENVENUE AU JEU MOTUS ***********"<<endl;
	cout <<"              Veuillez entrer votre Nom :    "<<endl;
	cin >> nom ;
	Joueur l(nom);
	cout<<"Voulez vous commencez ? "<<endl;
	cout<<"Si oui enterez 1 "<<endl;
	cin>> A ;
	do {
     cout<<"      ****************************************************     "<<endl;
     system("cls");

	string motadeviner;
	motadeviner=setmotadeviner();
	int nbessai=0;bool test=false;
	do{
    cout<<"\n";
    cout<<"     Le mot commence par la lettre  "<<motadeviner[0]<<endl;
	cout<<"      Saisir votre essai numero :  "<< nbessai+1 <<endl;

		cin>>mot;
		if (mot==motadeviner){test=true;break;}
    Tentative t(mot);
    if (t.controlesaisie(motadeviner))
        { nbessai++;//essai validé

     vector<int> red; //recherche des lettres bien placées
     for (int i=0;i<7;i++){
            Lettre j(mot[i],i,blanc);
      for (int k=0;k<7;k++){
            Lettre m(motadeviner[k],k,blanc);
            j.Comparer(m);
            if (j.getCouleur()==rouge) {red.push_back(k);break;}
     }
     }
     vector<int> yellow;//recherche des lettres mal placées
	for (int i=0;i<7;i++)
    {   Lettre j(mot[i],i,blanc);
        //calcul de l'occurence de chaque lettre dans le mot a deviner

        for (int k=0;k<7;k++)
        {if ((!(std::count(red.begin(), red.end(), k)))&&(!(std::count(yellow.begin(), yellow.end(), k))))//k pas dans red
                                {//recherche des jaunes
         Lettre m(motadeviner[k],k,blanc);
         j.Comparer(m);
         if (j.getCouleur()==jaune) {yellow.push_back(k);}
                                }

        }//fin parcours lettre mot a deviner

        if ((std::count(red.begin(), red.end(), i))){j.setCouleur(rouge);}
        if ((std::count(yellow.begin(), yellow.end(), i))){j.setCouleur(jaune);}
        yellow.clear();

        cout<<v[j.getCouleur()];


    }//fin parcours de la lettre lettre


    }//fin parcours de l'essai
    else {
            cout<<"        Veuillez essayer de nouveau !!   "<<endl;
    }
	}//fin parcours de tous les essais
	while (nbessai<7);
	if (test) {
            cout <<"      BRAVO !! Vous avez gagne en "<<nbessai +1<<" couts"<<endl;
                 int x;
               x=7-nbessai;
	           l.setScore(x);

	           cout<<"        Votre score est :   "<<x<<endl;
	           l.setRecord(x);
               int b=l.getRecord();
	           cout<<"        Votre record est :  "<<b<<endl;
	}
        else {cout<<"        Dommage, vous avez perdu"<<endl;}

        cout<<"Voulez vous jouer de nouveau ? "<<endl;
        cout<<"Entrez 0 si vous voulez quitter et 1 si vous voulez rejouer : "<<endl;
        cin>>A;

	} while(A==1) ;

	return 0;

}
