#ifndef TENTATIVE_H
#define TENTATIVE_H
#include <iostream>
#include <string>


using namespace std;

class Tentative
{

	string motsaisi;

	public:
	    Tentative(){}
		Tentative( string );
		~Tentative();
		string getmotsaisi()const;
		void setmotsaisi(string);
		int getNbessais();
		bool controlesaisie(string);
};
#endif
