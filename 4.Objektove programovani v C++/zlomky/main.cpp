//
//  main.cpp
//  zlomky
//
//  Created by kuba on 02.03.2021.
//

#include "db.h"

int main(){
    int vlb,n;
    float rh;
    Zlomky x,y,z;
    do{
        menu();
        cin>>vlb;
        switch(vlb){
            case 1: cin>>x;
                    cin>>y;
                break;
            case 2: cout<< "VYPIS:"<<endl;
                    cout<<x<<endl<<y<<endl;
                break;
            case 3: cout<<"SCITANI:"<<endl;
                    z=x+y;
                    cout<<z;
                break;
            case 4: cout<<"ODCITANI:"<<endl;
                    z=x-y;
                    cout<<z;
                break;
            case 5: cout<<"NASOBENI:"<<endl;
                    z=x*y;
                    cout<<z;
                break;
            case 6: cout<<"DELENI:"<<endl;
                    z=x/y;
                    cout<<z;
                break;
            case 7: cout<<"REALNA HODNOTA:"<<endl;
                    rh=x.rhz();
                    cout<<rh<<endl;
                    rh=y.rhz();
                    cout<<rh<<endl;
                break;
            case 8: z=x.zakl();
                    cout<<z;
                    z=y.zakl();
                    cout<<z;
                break;
            case 9: cout<<"Zadej na kolikatou:";
                    cin>>n;
                    cout<<"CELOCISELNA MOCNINA:"<<endl;
                    z=x.moc(n);
                    cout<<z<<endl;
                    z=z.moc(n);
                    cout<<z;
                break;
            case 10: if(x.por(y)) cout<<"Zlomky jsou shodne"<<endl;
                     else cout<<"Zlomky nejsou shodne"<<endl;
                break;
            default: cout<<"TAKOVE MOZNOSTI NEVEDEME"<<endl;
                break;
        }
    }while(vlb!=0);
    return 0;
}
