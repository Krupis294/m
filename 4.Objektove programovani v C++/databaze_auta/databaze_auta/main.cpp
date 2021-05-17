//
//  main.cpp
//  databaze_auta
//
//  Created by kuba on 07.02.2021.
//

#include "database.h"

int main(){
    int choice,lowest_hp;
    Car x;
    Showroom Cars;
    do{
        menu();
        cin>>choice;
        switch(choice){
            case 1: if(Cars.SaveToFile()) cout<<"Auta byla ulozena do souboru";
                    else cout<<"Nekde nastala chyba";
                break;
            case 2: if(Cars.ImportFromFile()) cout<<"Auta byla pridana do databaze";
                    else cout<<"Nekde nastala chyba";
                break;
            case 3: cin>>x;
                    if(Cars.NewCar(x)) cout<<"Vozidlo pridano do databaze";
                    else cout<<"Databaze je plna";
                break;
            case 4: cout<<Cars<<endl;
                break;
            case 5: if(!Cars.Finder()) cout<<"Vozidlo se nepovedlo nalezt";
                break;
            case 6: if(Cars.Sort()) cout<<"Vozidla byla serazena podle HP";
                break;
            case 7: if(Cars.Delete()) cout<<"Vozidlo bylo smazane";
                    else cout<<"Vozidlo nebylo nalezeno";
                break;
            case 8: if(Cars.Change()) cout<<"Vozidlo bylo zmenene";
                    else cout<<"Vozidlo k editaci nebylo nalezeno";
                break;
            case 9: lowest_hp=Cars.ShittyCar();
                break;
            case 0: cout<<"Konec";
                break;
            default: cout<< "Tak to zkusime znovu";
                break;
        }
    }while(choice!=0);
    return 0;
}
