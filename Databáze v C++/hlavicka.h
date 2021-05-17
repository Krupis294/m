#ifndef hlavicka
#define hlavicka


#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>

using namespace std;
	
	class studenti{
		private: 
			int cislo;
			string jmeno;
			string prijmeni;
			int mat;
			int aj;
			int cj;
			int ch; //celkove hodnoceni
			
		public:
			studenti();
			studenti(int id, string jm, string prij, int matika, int ajina, int cestina, int celkoveh);
		friend istream &operator>>(istream &vstup, studenti &s);
		friend ostream &operator<<(ostream &vystup, studenti s);
		
		int DejCislo() const;
		int DejMat() const;
		int DejAj() const;
		int DejCj() const;
		string DejJmeno() const;
		string DejPrijmeni() const;
		int DejCh() const;
		
		
	};
	
	class skupiny{
		private:
			studenti pole[20];
			int pocet;
		
		public:
			skupiny();
			
			friend	ostream &operator<<(ostream &vystup, skupiny sk);
			
			int pridej(studenti sk);
			void uloz();
			bool nacteni();
			studenti hledani_prijm();
			studenti hledani_id();
			void smazat();
			int nejlepsi();
			void razeni_prijmeni();
			void razeni_mat();
			void razeni_aj();
			void razeni_cj();
			int DejPocet() const;
	};



#endif
