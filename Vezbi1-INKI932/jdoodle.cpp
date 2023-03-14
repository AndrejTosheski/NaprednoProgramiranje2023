#include <iostream>

using namespace std;

/*Implementacija na Shell Sort:
Shell Sort e podobrena varijanta od Insertion Sort. Shell Sort raboti taka sto nizata se deli na pomali podnizi, 
ne e neophodno podnizite da bidat so sosedni elementi, se koristi inkrement 'i' koj se narekuva "prazen prostor" (gap) i se koristi za kreiranje na niza od elementi koi se oddeleni 'i' elementi. 

Vo ovoj algoritam, prvo postavivme N sto e "prazniot prostor" (gap) za sortiranje na nizata koristejki Shell Sort.
Vo sledniot cekor, ja delime nizata na podnizi so koristenje na "prazniot prostor", potoa
sekoja od podnizite ja podreduvame taka sto na krajot od ciklusot kje dobieme sortirana niza.*/

int shellSort(int arr[], int N) 
{ 
    for (int gap = N/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < N; i += 1) 
        { 
            //Sortiranje na podnizite kreirani so koristenje na prazen prostor(gap)
            int temp = arr[i]; 
 
            int j; 
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
               
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 

int main() 
{
    //Vnesuvam niza so int vrednosti od Ascii vrednostite na ime, prezime i indeks: Andrej Tosheski INKI932
    int arr[] = {(int)'A',(int)'n',(int)'d',(int)'r',(int)'e',(int)'j',(int)'T',(int)'o',(int)'s',(int)'h',(int)'e',(int)'s',(int)'k',(int)'i',(int)'I',(int)'N',(int)'K',(int)'I',(int)'9',(int)'3',(int)'2'}, i; 
    
    //Se presmetuva goleminata na nizata
    int N = sizeof(arr)/sizeof(arr[0]); 
   
    cout << "Niza koja treba da se sortira: \n"; 
    for (int i=0; i<N; i++) 
        cout << arr[i] << " "; 
   
    shellSort(arr, N); 
   
    cout << "\nNizata posle sortiranje so Shell Sort: \n"; 
    for (int i=0; i<N; i++) 
        cout << arr[i] << " "; 
   
    return 0; 
}