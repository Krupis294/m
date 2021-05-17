//
//  main.cpp
//  obj_prog
//
//  Created by kuba on 04.05.2021.
//

#include "database.h"

int main() {
    int volba;
    Auto x;
    Garaz Auta;
    do{
        menu();
        cin>>volba;
        switch (volba) {
            case 1: if(Auta.UlozeniDoSouboru()) cout<<"Auta ulozena do souboru";
                    else cout<<"Chyba xd";
                break;
            case 2: if(Auta.NacteniZSouboru()) cout<<"Auta nactena z souboru";
                    else cout<<"Chyba xd";
                break;
            case 3: cin>>x;
                    if(Auta.NoveAuto(x)) cout<<"Auto pridano";
                    else cout<<"Auto nepridano";
                break;
            case 4: cout<<Auta<<endl;
                break;
            case 5: if(!Auta.Hledani()) cout<<"Zadne auto nenalezene";
                break;
            case 6: if(Auta.Serazeni()) cout<<"Auta serazena podle hp";
                break;
            case 7: cout<<Auta<<endl;
                    if(Auta.Smazani()) cout<< "Auto uspesne smazano";
                    else cout<<"Chyba xd";
                break;
            case 8: cout<<Auta<<endl;
                    if(Auta.Zmena()) cout<<"Auto bylo zmenene";
                    else cout<<"Chyba xd";
                break;
            case 9: Auta.slabko();
                break;
            default:
                break;
        }
    }while(volba!=0);
    return 0;
}
