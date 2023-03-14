#include <iostream>
#include <string>
using namespace std;

enum Denovi {
    ponedelnik,
    vtornik,
    sreda,
    cetvrtok,
    petok,
    sabota,
    nedela
};

Denovi getDay(string den){
    Denovi obj;
    if(den == "Ponedelnik"){
        obj = ponedelnik;
    }
    else if(den == "Vtornik"){
        obj = vtornik;
    }
    else if(den == "Sreda"){
        obj = sreda;
    }
    else if(den == "Cetvrtok"){
        obj = cetvrtok;
    }
    else if(den == "Petok"){
        obj = petok;
    }
    else if(den == "Sabota"){
        obj = sabota;
    }
    else if(den == "Nedela"){
        obj = nedela;
    }
    return obj;
}

int main(){
    
    string den;
    
    cout<<"Napisi den od nedelata"<<endl;
    cin>>den;
    //NAPOMENA: Ako pri pisuvanje na denot se napravi greska i se izbrisi bukva i odnovo se vnesi nema da raboti(Ne znam koja e pricinata)
    //Denovite se pisuvaat so prva bukva golema.
    
    Denovi obj = getDay(den);
    cout<<endl;
    switch(obj){
        case ponedelnik:
        cout<<"Ponedelnik:\nNapredno Programiranje i Arhitektura I Organizcaija Na Kompjuteri"<<endl;
        break;
        case vtornik:
        cout<<"Vtornik:\nMatematika 2"<<endl;
        break;
        case sreda:
        cout<<"Sreda:\nVeb Tehnologii"<<endl;
        break;
        case cetvrtok:
        cout<<"Cetvrtok:\nMatematika 2"<<endl;
        break;
        case petok:
        cout<<"Petok:\nFinansiski Tehnologii"<<endl;
        break;
        case sabota:
        cout<<"Sabota:\nNema Predavanja"<<endl;
        break;
        case nedela:
        cout<<"Nedela:\nNema Predavanja"<<endl;
        break;
        default:
        cout<<"Greska"<<endl;
        break;
        
    }
}

/*Na pocetok imame enum so site denovi od nedelata, potoa vo glavnata funkcija vnesuvame den i definiram objekt od Denovi(enum) pri sto se povikuva funckijata getDay() na koja i se dodeluva vneseniot den kako parametar,
vo funckijata spored toa koj den e vnesen na objektot od Denovi se dodeluva soodvetniot element i funkcijata go vrakja nazad vo glavnata funkcija kade so switch se proveruva i se pecatat predmetite od toj den*/