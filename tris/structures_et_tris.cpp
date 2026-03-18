#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

struct Tableau {
    int* donnees;
    int taille;
    int capacite;
};

struct Noeud {
    int valeur;
    Noeud* suivant;
};

struct ListeChainee {
    Noeud* tete;
};

struct Pile {
    int* donnees;
    int taille;
    int capacite;
};

struct File {
    int* donnees;
    int taille;
    int capacite;
};

void afficherTableau(int* tableau, int taille, const string& nom) {
    cout << nom << " : [";
    for (int i = 0; i < taille; ++i) {
        cout << tableau[i];
        if (i + 1 < taille) {
            cout << ", ";
        }
    }
    cout << "]\n";
}

void initialiserTableau(Tableau& t, int capaciteInitiale) {
    t.donnees = new int[capaciteInitiale];
    t.taille = 0;
    t.capacite = capaciteInitiale;
}

void agrandirTableau(Tableau& t) {
    int nouvelleCapacite = t.capacite * 2;
    int* nouveau = new int[nouvelleCapacite];

    for (int i = 0; i < t.taille; ++i) {
        nouveau[i] = t.donnees[i];
    }

    delete[] t.donnees;
    t.donnees = nouveau;
    t.capacite = nouvelleCapacite;
}

void ajouterTableau(Tableau& t, int valeur) {
    if (t.taille == t.capacite) {
        agrandirTableau(t);
    }
    t.donnees[t.taille] = valeur;
    t.taille++;
}

int lireTableau(const Tableau& t, int indice) {
    if (indice < 0 || indice >= t.taille) {
        throw out_of_range("Indice invalide");
    }
    return t.donnees[indice];
}

void modifierTableau(Tableau& t, int indice, int valeur) {
    if (indice < 0 || indice >= t.taille) {
        throw out_of_range("Indice invalide");
    }
    t.donnees[indice] = valeur;
}

void afficherTableauStructure(const Tableau& t) {
    afficherTableau(t.donnees, t.taille, "Tableau");
}

void libererTableau(Tableau& t) {
    delete[] t.donnees;
    t.donnees = nullptr;
    t.taille = 0;
    t.capacite = 0;
}

void initialiserListe(ListeChainee& liste) {
    liste.tete = nullptr;
}

void insererDebutListe(ListeChainee& liste, int valeur) {
    Noeud* nouveau = new Noeud;
    nouveau->valeur = valeur;
    nouveau->suivant = liste.tete;
    liste.tete = nouveau;
}

void insererFinListe(ListeChainee& liste, int valeur) {
    Noeud* nouveau = new Noeud;
    nouveau->valeur = valeur;
    nouveau->suivant = nullptr;

    if (liste.tete == nullptr) {
        liste.tete = nouveau;
        return;
    }

    Noeud* courant = liste.tete;
    while (courant->suivant != nullptr) {
        courant = courant->suivant;
    }
    courant->suivant = nouveau;
}

bool supprimerValeurListe(ListeChainee& liste, int valeur) {
    if (liste.tete == nullptr) {
        return false;
    }

    if (liste.tete->valeur == valeur) {
        Noeud* aSupprimer = liste.tete;
        liste.tete = liste.tete->suivant;
        delete aSupprimer;
        return true;
    }

    Noeud* courant = liste.tete;
    while (courant->suivant != nullptr && courant->suivant->valeur != valeur) {
        courant = courant->suivant;
    }

    if (courant->suivant == nullptr) {
        return false;
    }

    Noeud* aSupprimer = courant->suivant;
    courant->suivant = courant->suivant->suivant;
    delete aSupprimer;
    return true;
}

void afficherListe(const ListeChainee& liste) {
    cout << "Liste chainee : ";
    Noeud* courant = liste.tete;
    while (courant != nullptr) {
        cout << courant->valeur;
        if (courant->suivant != nullptr) {
            cout << " -> ";
        }
        courant = courant->suivant;
    }
    cout << "\n";
}

void libererListe(ListeChainee& liste) {
    Noeud* courant = liste.tete;
    while (courant != nullptr) {
        Noeud* suivant = courant->suivant;
        delete courant;
        courant = suivant;
    }
    liste.tete = nullptr;
}

void initialiserPile(Pile& pile, int capaciteInitiale) {
    pile.donnees = new int[capaciteInitiale];
    pile.taille = 0;
    pile.capacite = capaciteInitiale;
}

void agrandirPile(Pile& pile) {
    int nouvelleCapacite = pile.capacite * 2;
    int* nouveau = new int[nouvelleCapacite];

    for (int i = 0; i < pile.taille; ++i) {
        nouveau[i] = pile.donnees[i];
    }

    delete[] pile.donnees;
    pile.donnees = nouveau;
    pile.capacite = nouvelleCapacite;
}

void empiler(Pile& pile, int valeur) {
    if (pile.taille == pile.capacite) {
        agrandirPile(pile);
    }
    pile.donnees[pile.taille] = valeur;
    pile.taille++;
}

int depiler(Pile& pile) {
    if (pile.taille == 0) {
        throw runtime_error("Pile vide");
    }
    pile.taille--;
    return pile.donnees[pile.taille];
}

int sommetPile(const Pile& pile) {
    if (pile.taille == 0) {
        throw runtime_error("Pile vide");
    }
    return pile.donnees[pile.taille - 1];
}

void afficherPile(const Pile& pile) {
    afficherTableau(pile.donnees, pile.taille, "Pile (bas -> haut)");
}

void libererPile(Pile& pile) {
    delete[] pile.donnees;
    pile.donnees = nullptr;
    pile.taille = 0;
    pile.capacite = 0;
}

void initialiserFile(File& file, int capaciteInitiale) {
    file.donnees = new int[capaciteInitiale];
    file.taille = 0;
    file.capacite = capaciteInitiale;
}

void agrandirFile(File& file) {
    int nouvelleCapacite = file.capacite * 2;
    int* nouveau = new int[nouvelleCapacite];

    for (int i = 0; i < file.taille; ++i) {
        nouveau[i] = file.donnees[i];
    }

    delete[] file.donnees;
    file.donnees = nouveau;
    file.capacite = nouvelleCapacite;
}

void enfiler(File& file, int valeur) {
    if (file.taille == file.capacite) {
        agrandirFile(file);
    }
    file.donnees[file.taille] = valeur;
    file.taille++;
}

int defiler(File& file) {
    if (file.taille == 0) {
        throw runtime_error("File vide");
    }

    int valeur = file.donnees[0];
    for (int i = 1; i < file.taille; ++i) {
        file.donnees[i - 1] = file.donnees[i];
    }
    file.taille--;
    return valeur;
}

int teteFile(const File& file) {
    if (file.taille == 0) {
        throw runtime_error("File vide");
    }
    return file.donnees[0];
}

void afficherFile(const File& file) {
    afficherTableau(file.donnees, file.taille, "File (tete -> fin)");
}

void libererFile(File& file) {
    delete[] file.donnees;
    file.donnees = nullptr;
    file.taille = 0;
    file.capacite = 0;
}

void echanger(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void triSelection(int* tableau, int taille) {
    for (int i = 0; i < taille; ++i) {
        int indiceMin = i;
        for (int j = i + 1; j < taille; ++j) {
            if (tableau[j] < tableau[indiceMin]) {
                indiceMin = j;
            }
        }
        echanger(tableau[i], tableau[indiceMin]);
    }
}

void triInsertion(int* tableau, int taille) {
    for (int i = 1; i < taille; ++i) {
        int cle = tableau[i];
        int j = i - 1;

        while (j >= 0 && tableau[j] > cle) {
            tableau[j + 1] = tableau[j];
            j--;
        }
        tableau[j + 1] = cle;
    }
}

void triBulles(int* tableau, int taille) {
    for (int fin = taille - 1; fin > 0; --fin) {
        for (int j = 0; j < fin; ++j) {
            if (tableau[j] > tableau[j + 1]) {
                echanger(tableau[j], tableau[j + 1]);
            }
        }
    }
}

void fusion(int* tableau, int gauche, int milieu, int droite) {
    int tailleGauche = milieu - gauche + 1;
    int tailleDroite = droite - milieu;

    int* gaucheTemp = new int[tailleGauche];
    int* droiteTemp = new int[tailleDroite];

    for (int i = 0; i < tailleGauche; ++i) {
        gaucheTemp[i] = tableau[gauche + i];
    }

    for (int i = 0; i < tailleDroite; ++i) {
        droiteTemp[i] = tableau[milieu + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = gauche;

    while (i < tailleGauche && j < tailleDroite) {
        if (gaucheTemp[i] <= droiteTemp[j]) {
            tableau[k] = gaucheTemp[i];
            i++;
        } else {
            tableau[k] = droiteTemp[j];
            j++;
        }
        k++;
    }

    while (i < tailleGauche) {
        tableau[k] = gaucheTemp[i];
        i++;
        k++;
    }

    while (j < tailleDroite) {
        tableau[k] = droiteTemp[j];
        j++;
        k++;
    }

    delete[] gaucheTemp;
    delete[] droiteTemp;
}

void triFusionRecursif(int* tableau, int gauche, int droite) {
    if (gauche >= droite) {
        return;
    }

    int milieu = gauche + (droite - gauche) / 2;
    triFusionRecursif(tableau, gauche, milieu);
    triFusionRecursif(tableau, milieu + 1, droite);
    fusion(tableau, gauche, milieu, droite);
}

void triFusion(int* tableau, int taille) {
    if (taille > 0) {
        triFusionRecursif(tableau, 0, taille - 1);
    }
}

int partitionner(int* tableau, int debut, int fin) {
    int pivot = tableau[fin];
    int i = debut - 1;

    for (int j = debut; j < fin; ++j) {
        if (tableau[j] <= pivot) {
            i++;
            echanger(tableau[i], tableau[j]);
        }
    }

    echanger(tableau[i + 1], tableau[fin]);
    return i + 1;
}

void triRapideRecursif(int* tableau, int debut, int fin) {
    if (debut >= fin) {
        return;
    }

    int pivot = partitionner(tableau, debut, fin);
    triRapideRecursif(tableau, debut, pivot - 1);
    triRapideRecursif(tableau, pivot + 1, fin);
}

void triRapide(int* tableau, int taille) {
    if (taille > 0) {
        triRapideRecursif(tableau, 0, taille - 1);
    }
}

void copierTableau(int* source, int* destination, int taille) {
    for (int i = 0; i < taille; ++i) {
        destination[i] = source[i];
    }
}

void demoStructures() {
    cout << "=== STRUCTURES ===\n\n";

    Tableau tableau;
    initialiserTableau(tableau, 4);
    ajouterTableau(tableau, 10);
    ajouterTableau(tableau, 20);
    ajouterTableau(tableau, 30);
    afficherTableauStructure(tableau);
    cout << "Element a l'indice 1 : " << lireTableau(tableau, 1) << "\n";
    modifierTableau(tableau, 1, 25);
    afficherTableauStructure(tableau);
    cout << "\n";

    ListeChainee liste;
    initialiserListe(liste);
    insererDebutListe(liste, 2);
    insererDebutListe(liste, 1);
    insererFinListe(liste, 3);
    insererFinListe(liste, 4);
    afficherListe(liste);
    supprimerValeurListe(liste, 3);
    afficherListe(liste);
    cout << "\n";

    Pile pile;
    initialiserPile(pile, 4);
    empiler(pile, 5);
    empiler(pile, 10);
    empiler(pile, 15);
    afficherPile(pile);
    cout << "Sommet de la pile : " << sommetPile(pile) << "\n";
    cout << "Depile : " << depiler(pile) << "\n";
    afficherPile(pile);
    cout << "\n";

    File file;
    initialiserFile(file, 4);
    enfiler(file, 100);
    enfiler(file, 200);
    enfiler(file, 300);
    afficherFile(file);
    cout << "Tete de la file : " << teteFile(file) << "\n";
    cout << "Defile : " << defiler(file) << "\n";
    afficherFile(file);
    cout << "\n";

    libererTableau(tableau);
    libererListe(liste);
    libererPile(pile);
    libererFile(file);
}

void demoTri(const string& nom, void (*tri)(int*, int), int* original, int taille) {
    int* copie = new int[taille];
    copierTableau(original, copie, taille);
    afficherTableau(copie, taille, "Avant " + nom);
    tri(copie, taille);
    afficherTableau(copie, taille, "Apres " + nom);
    cout << "\n";
    delete[] copie;
}

void demoTris() {
    cout << "=== TRIS ===\n\n";

    int donnees[] = {7, 4, 9, 1, 5, 2};
    int taille = sizeof(donnees) / sizeof(donnees[0]);

    demoTri("tri par selection", triSelection, donnees, taille);
    demoTri("tri par insertion", triInsertion, donnees, taille);
    demoTri("tri a bulles", triBulles, donnees, taille);
    demoTri("tri fusion", triFusion, donnees, taille);
    demoTri("tri rapide", triRapide, donnees, taille);
}

int main() {
    demoStructures();
    demoTris();
    return 0;
}
