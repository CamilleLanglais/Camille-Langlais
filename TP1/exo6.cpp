#include <iostream>
using namespace std;

void ajoute(Liste* liste, int valeur);


struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
    // your code
};

struct DynaTableau{
    int current;
   int capacity;
   int* donnees;
};


void initialise(Liste* liste)
{
    // liste->premier->donnee=NULL;
    liste->premier=nullptr;

}

bool est_vide(const Liste* liste)
{
    if(liste->premier==nullptr){
        return true;
    }
    return false;
}

void ajoute(Liste* liste, int valeur)
{
 
    Noeud *noeud1= liste->premier;
    
    if(noeud1==nullptr){
        Noeud *new_noeud= new Noeud;
        new_noeud->donnee=valeur;
        liste->premier=new_noeud;
    }
    while(noeud1->suivant!= nullptr){
        noeud1=noeud1->suivant;
}
    Noeud *new_noeud= new Noeud;
    noeud1->suivant = new_noeud;
    new_noeud->donnee=valeur;


}

void affiche(const Liste* liste)
{
    Noeud *noeud1=liste->premier;
    while(noeud1 != nullptr){
        cout<<noeud1<<endl;
        noeud1=noeud1->suivant;
    }
}

int recupere(const Liste* liste, int n)
{
    int c=0;
    Noeud *noeud1= liste->premier;
    while(c!=n){
        c++;
        noeud1=noeud1->suivant;
    }
    
    
    return(noeud1->donnee);
}

int cherche(const Liste* liste, int valeur)
{
    int c=0;
    Noeud *noeud1=liste->premier;
    if(liste->premier->donnee==valeur){
        cout<<c<<endl;
    }
    else{
    while(liste->premier != nullptr){
        noeud1=liste->premier->suivant;
        if(noeud1->donnee==valeur){
            cout<<c<<endl;
        } 
        c++;  
    }
   
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    int new_valeur=recupere(liste, n);
    new_valeur=valeur;

}

void ajoute(DynaTableau* tableau, int valeur)
{
   if(tableau->current == tableau->capacity){
    int *newtableau = new int[tableau->capacity * 2];
    for (int i = 0 ; i < tableau->current ; i++){
        newtableau[i] = tableau->donnees[i];
    }
    tableau->donnees = newtableau;
    tableau->capacity *= 2;
}
    tableau->donnees[tableau->current] = valeur;
    tableau->current++;
}



void initialise(DynaTableau* tableau, int capacite)
{
    tableau[capacite]=tableau[0];

}

bool est_vide(const DynaTableau* liste)
{
    return (liste->current == 0);
}

void affiche(const DynaTableau* tableau)
{

    for(int i = 0 ; i < tableau->current ; i++){
        cout<<tableau->donnees[i]<<endl;
    }
}

int recupere(const DynaTableau* tableau, int n)
{
    if(n < tableau->current){
        return tableau->donnees[n];
    }

    cout<<"Error!"<<endl;
    return 0;
 
}

int cherche(const DynaTableau *tableau, int valeur)
{
    for(int i = 0 ; i < tableau->current ; i++){
        if(tableau->donnees[i]==valeur){
            return(i);
        }
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    if(n<tableau->current){
        tableau->donnees[n]=valeur;
    }
    else{
        cout<<"Error!"<<endl;
    }
}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(DynaTableau *tableau, int valeur)
{
   //on ajoute au début
   int tab2[tableau->current+1];
   for(int i=1;i<tableau->current+1;i++){
    tab2[i]=tableau->donnees[i-1];      //on  copie exactement le tableau en décalant tout de 1 case
   }
    tab2[0]=valeur;
    tableau->donnees=tab2;

}



//int retire_file(Liste* liste)
int retire_file(DynaTableau *tableau)
{
   int tab2[tableau->current -1];
   for(int i=1;i<tableau->current;i++){
        tab2[i - 1]=tableau->donnees[i];
    }
    int result=tableau->donnees[0];      //on récupère la dernière valeur
    tableau->donnees=tab2;
    return result;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(DynaTableau *tableau, int valeur)
{
// on ajoute à la fin
int tab2[tableau->current +1];
for(int i=0;i<tableau->current;i++){
    tab2[i]=tableau->donnees[i];
}
tab2[tableau->current]=valeur;
tableau->donnees=tab2;
}

//int retire_pile(DynaTableau* liste)
int retire_pile(DynaTableau* tableau)
{
    int tab2[tableau->current -1];
    for(int i=0;i<tableau->current -1 ;i++){
        tab2[i]=tableau->donnees[i];
    }
    int result=tableau->donnees[tableau->current-1];      //on récupère la dernière valeur
    tableau->donnees=tab2;
    return result;
}



int main()
{
    Liste liste;
    initialise(&liste);
    DynaTableau tableau;
    initialise(&tableau, 5);

    if (!est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (!est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    for (int i=1; i<=7; i++) {
        ajoute(&liste, i*7);
        ajoute(&tableau, i*5);
    }

    if (est_vide(&liste))
    {
        std::cout << "Oups y a une anguille dans ma liste" << std::endl;
    }

    if (est_vide(&tableau))
    {
        std::cout << "Oups y a une anguille dans mon tableau" << std::endl;
    }

    std::cout << "Elements initiaux:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    std::cout << "5e valeur de la liste " << recupere(&liste, 4) << std::endl;
    std::cout << "5e valeur du tableau " << recupere(&tableau, 4) << std::endl;

    std::cout << "21 se trouve dans la liste à " << cherche(&liste, 21) << std::endl;
    std::cout << "15 se trouve dans la liste à " << cherche(&tableau, 15) << std::endl;

    stocke(&liste, 4, 7);
    stocke(&tableau, 4, 7);

    std::cout << "Elements après stockage de 7:" << std::endl;
    affiche(&liste);
    affiche(&tableau);
    std::cout << std::endl;

    Liste pile; // DynaTableau pile;
    Liste file; // DynaTableau file;

    initialise(&pile);
    initialise(&file);

    for (int i=1; i<=7; i++) {
        pousse_file(&file, i);
        pousse_pile(&pile, i);
    }

    int compteur = 10;
    while(!est_vide(&file) && compteur > 0)
    {
        std::cout << retire_file(&file) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    compteur = 10;
    while(!est_vide(&pile) && compteur > 0)
    {
        std::cout << retire_pile(&pile) << std::endl;
        compteur--;
    }

    if (compteur == 0)
    {
        std::cout << "Ah y a un soucis là..." << std::endl;
    }

    return 0;
}
