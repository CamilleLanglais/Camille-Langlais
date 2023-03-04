#include <iostream>
#include <stack>


using namespace std;

struct Noeud{
    int donnee;
    Noeud* suivant;
};

struct Liste{
    Noeud* premier;
    // your code
};

struct DynaTableau{
    int taille;
   int *donees;
   int capacity;
   int *tab[255];
   
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
        return c;
    }
    else{
    while(liste->premier != nullptr){
        noeud1=liste->premier->suivant;
        if(noeud1->donnee==valeur){
            return c;
        } 
        c++;  
    }
   
    }
    return -1;
}

void stocke(Liste* liste, int n, int valeur)
{
    int c=0;
    Noeud *noeud1= liste->premier;
    while(c!=n){
        c++;
        noeud1=noeud1->suivant;
    }
    noeud1->donnee=valeur;

}

void ajoute(DynaTableau* tableau, int valeur)
{
    int len=tableau->taille;
    if (len==tableau->capacity){
        tableau->donees=new ; // Je ne sais pas quoi mettre pour ajouter une nouvelle case dans le tableau
        
    }
        *tableau->tab[len]=valeur;
    
}



void initialise(DynaTableau* tableau, int capacite)
{
    tableau[capacite]=tableau[0];

}

bool est_vide(const DynaTableau* liste)
{
    if(sizeof(liste)==0){
        return true;
    }
    return false;
}

void affiche(const DynaTableau* tableau)
{
    int len=sizeof(tableau->tab);
    for(int i=0;i<len;i++){
        cout<<*tableau->tab[i]<<endl;
    }
}

int recupere(const DynaTableau* tableau, int n)
{
 return *tableau->tab[n-1];
}

int cherche(const DynaTableau *tableau, int valeur)
{
    int len=sizeof(tableau->tab);
    for(int i=0;i<len; i++){
        if(*tableau->tab[i]==valeur){
            return(i);
        }
    }
    return -1;
}

void stocke(DynaTableau* tableau, int n, int valeur)
{
    *tableau->tab[n-1]=valeur;

}

//void pousse_file(DynaTableau* liste, int valeur)
void pousse_file(Liste* liste, int valeur)
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



//int retire_file(Liste* liste)
int retire_file(Liste* liste)
{
    while(liste->premier!=nullptr){
        cout<<liste->premier->donnee;
        liste->premier->donnee=liste->premier->suivant->donnee;
        liste->premier=liste->premier->suivant;
    }
    return 0;
}

//void pousse_pile(DynaTableau* liste, int valeur)
void pousse_pile(Liste* liste, int valeur)
{

}

//int retire_pile(DynaTableau* liste)
int retire_pile(Liste* liste)
{
    stack<int> i;
    if(liste->premier != nullptr){  // Il faut que la liste soit non nulle
        liste.pop();
    }
    return 0;
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
