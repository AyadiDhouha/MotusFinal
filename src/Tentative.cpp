#include "Tentative.h"
#include <iostream>
#include <cstring>
#include<cctype>

using namespace std;


Tentative::Tentative(string mot )
{
setmotsaisi(mot);
}

Tentative::~Tentative()
{

}

int Tentative::getNbessais(){
	return Nbessais;
}

bool Tentative::controlesaisie(string mot){
    bool test=true;
    int i=0;
    if ((mot.length() == motsaisi.length())   ){
        do{
            if (isalpha(motsaisi[i])==false){return false;}
            else {i++;}

        }while (i<7);
     if (i==7) {return true;}
    }
    else{return false;}


    }

void Tentative::setmotsaisi(string mot){
	motsaisi=mot;
}

string Tentative::getmotsaisi()const{
	return motsaisi;
}

