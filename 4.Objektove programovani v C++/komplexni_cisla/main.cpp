    //
    //  main.cpp
    //  komplexni_cisla
    //
    //  Created by kuba on 08.02.2021.
    //

    #include "db.h"

    int main(){
        int vlb;
        char v;
        float a;
        Komplex x,y,z;
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
                case 7: cout<<"ABSOLUTNI HODNOTA:"<<endl;
                        a=x.abs();
                        cout<<"Prvni:"<<a<<endl;
                        a=y.abs();
                        cout<<"Druha:"<<a<<endl;
                    break;
                case 8: cout<<"ROVNOST:"<<endl;
                        if(x.rovnost(y)) cout<<"Komplexni cisla jsou rovna"<<endl;
                        else cout<<"Komplexni cisla nejsou rovna"<<endl;
                    break;
                case 9: cout<<"x/y?";
                        cin>>v;
                    switch (v){
                        case 'x': cout<<"Puvodni hodnota:"<<endl;
                                  cout<<x<<endl;
                                  cout<<"Prevracena hodnota:"<<endl;
                                  x.reverse();
                                  cout<<x<<endl;
                            break;
                        case 'y': cout<<"Puvodni hodnota:"<<endl;
                                  cout<<y<<endl;
                                  cout<<"Prevracena hodnota:"<<endl;
                                  y.reverse();
                                  cout<<y<<endl;
                            break;
                        default: break;
                    }
                    break;
                case 10: cout<<"x/y?";
                        cin>>v;
                    switch (v){
                        case 'x': cout<<"Puvodni hodnota:"<<endl;
                                  cout<<x<<endl;
                                  cout<<"Prevracena hodnota:"<<endl;
                                  x.sdruzene();
                                  cout<<x<<endl;
                            break;
                        case 'y': cout<<"Puvodni hodnota:"<<endl;
                                  cout<<y<<endl;
                                  cout<<"Prevracena hodnota:"<<endl;
                                  y.sdruzene();
                                  cout<<y<<endl;
                            break;
                        default: break;
                    }
                    break;
                default: cout<<"KOKOTE TAKOVE MOZNOSTI NEVEDEME"<<endl;
                    break;
            }
        }while(vlb!=0);
        return 0;
    }
