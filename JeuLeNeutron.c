#include <stdio.h>
#include <stdlib.h>


#define reset "\033[0m"
#define reverse "\033[7m"



#define rouge "\033[;31m"
#define vert "\033[;32m"
#define bleu "\033[;34m"

typedef struct{
    int x;
    int y;
    char couleur;
}pion;


/*============================================
 ACTION:  initialisation(Lpions)
 INITIALISATION de la Lpions de pions
 Résultat :
    - Lpions : Vecteur de PIONS de taille 11
============================================*/


void initialisation(pion *Lpions){
    //ajout pion rouge dans liste
    for(int i=0;i<5;i++){
        pion p;
        p.x=0;
        p.y=i;
        p.couleur='r';
        Lpions[i]=p;
    }

    //ajout pion bleu dans liste
    for(int i=5;i<10;i++){
        pion p;
        p.x=4;
        p.y=i-5;
        p.couleur='b';
        Lpions[i]=p;
    }

    //ajout du pion vert dans liste
    pion p;
    p.x=2;
    p.y=2;
    p.couleur='v';
    Lpions[10]=p;
}

/*======================================================
 ACTION: affiche(Lpions)
 Affichage de la Lpions de pions et de leurs coordonnées
 Donnée :
    - Lpions : Vecteur de PIONS de taille 11

 Cette fonction a été consue pour la phase de test dans
 le but de voir les changement de coordonnes de nos pions
======================================================*/


void affiche(pion *Lpions){
    for(int i=0;i<11;i++){
        printf("Le pion ");
        if(Lpions[i].couleur=='r'){
            printf("%sRouge%s%s est au coordone %d %d \n",rouge,reverse,reset,Lpions[i].x,Lpions[i].y);
        }
        else if(Lpions[i].couleur=='b'){
            printf("%sBleu%s%s est au coordone %d %d \n",bleu,reverse,reset,Lpions[i].x,Lpions[i].y);
        }
        else if(Lpions[i].couleur=='v'){
            printf("%sVert%s%s est au coordone %d %d \n",vert,reverse,reset,Lpions[i].x,Lpions[i].y);
        }
    }
}

/*============================================
 ACTION:  initdamier(Lpions,damier)5,5
 INITIALISATION de la Lpions de pions

 DONNEE :
  - Lpions : Vecteur de PIONS de taille 11
 RESULTAT :
 - damier : Matrice d'ENTIER de taille 5
============================================*/

void initdamier(pion *Lpions ,int damier[][5]){

    for(int i = 1; i < 4; i++){
        for(int j = 0; j < 5; j++){
            damier[i][j] = -1;
        }
    }

    for(int i = 0; i < 11; i++){
        damier[Lpions[i].x][Lpions[i].y] = i; // on enregistre l'index (Lpions) du pion au sien de la matrice damier.

    }


}
/*============================================
 ACTION:  affichedamier(damier, Lpions)
 Affiche le damier avec les pions

 DONNEE :
 - damier : Matrice d'ENTIER de taille 5
 - Lpions : Vecteur de PIONS de taille 11
============================================*/

void affichedamier(int damier[][5], pion *Lpions){
    for(int i = 0; i < 5; i++){
        printf("%d",5-i);
        for(int j = 0; j < 5; j++){
            if(damier[i][j]!=-1){
                if(Lpions[damier[i][j]].couleur=='b'){
                    printf("%s 0 %s%s",bleu,reverse,reset);
                }
                else if(Lpions[damier[i][j]].couleur=='r'){
                    printf("%s 0 %s%s",rouge,reverse,reset);
                }
                else if(Lpions[damier[i][j]].couleur=='v'){
                    printf("%s 0 %s%s",vert,reverse,reset);
                }
            }
            else{
                printf("   ");
            }
        }
        printf("\n");
    }
    printf(" ");
    for(int i=1;i<6;i++){
            printf(" %d ",i);
        }
    printf("\n");
}


/*============================================
 ACTION:  dx (Lpions,damier,x,y)
Deplace le pion de coordonnées donnée
vers la direction x

valeurs de x :
    1 : Nord
    2 : Nord-Est
    3 : Est
    4 : Sud-Est
    5 : Sud
    6 : Sud-Ouest
    7 : Ouest
    8 : Nord-Ouest

Nord = Haut du damier, côté bleu

 DONNEE :
 - damier : Matrice d'ENTIER de taille 5
 - x,y : ENTIER coordonnées du pion à bouger

 DONNEES/RESULTAT :
 - Lpions : Vecteur de PIONS de taille 11
============================================*/


void d1(pion *Lpions ,int damier[][5],int x,int y){
    int i=x;
    //tant que la cases suivante dans la direction choisie est vide et dans le damier on increment i et on reteste
    while(i>0 && damier[i-1][y]==-1){
        i--;
    }

    Lpions[damier[x][y]].x = i;

    damier[i][y]= damier[x][y];
    damier[x][y]= -1;
}

void d5(pion *Lpions ,int damier[][5],int x,int y){
    int i=x;
    while(i<4 && damier[i+1][y]==-1){
        i++;
    }

    Lpions[damier[x][y]].x = i;

    damier[i][y]= damier[x][y];
    damier[x][y]= -1;
}

void d3(pion *Lpions ,int damier[][5],int x,int y){
    int i=y;
    while(i<4 && damier[x][i+1]==-1){
        i++;
    }

    Lpions[damier[x][y]].y = i;

    damier[x][i]= damier[x][y];
    damier[x][y]= -1;

}
void d7(pion *Lpions ,int damier[][5],int x,int y){
    int i=y;
    while(i>0 && damier[x][i-1]==-1){
        i--;
    }

    Lpions[damier[x][y]].y = i;

    damier[x][i]= damier[x][y];
    damier[x][y]= -1;

}

void d2(pion *Lpions ,int damier[][5],int x,int y){
    int i=x,j=y;
    while(i>0 && j<4 && damier[i-1][j+1]==-1){
        i--;
        j++;
    }

    Lpions[damier[x][y]].x = i;
    Lpions[damier[x][y]].y = j;

    damier[i][j]= damier[x][y];
    damier[x][y]= -1;

}
void d6(pion *Lpions ,int damier[][5],int x,int y){
    int i=x,j=y;
    while(i<4 && j>0 && damier[i+1][j-1]==-1){
        i++;
        j--;
    }

    Lpions[damier[x][y]].x = i;
    Lpions[damier[x][y]].y = j;

    damier[i][j]= damier[x][y];
    damier[x][y]= -1;

}
void d4(pion *Lpions ,int damier[][5],int x,int y){
    int i=x,j=y;
    while(i<4 && j<4 && damier[i+1][j+1]==-1){
        i++;
        j++;
    }

    Lpions[damier[x][y]].x = i;
    Lpions[damier[x][y]].y = j;

    damier[i][j]= damier[x][y];
    damier[x][y]= -1;
}
void d8(pion *Lpions ,int damier[][5],int x,int y){
    int i=x,j=y;
    while(i>0 && j>0 && damier[i-1][j-1]==-1){
        i--;
        j--;
    }

    Lpions[damier[x][y]].x = i;
    Lpions[damier[x][y]].y = j;

    damier[i][j]= damier[x][y];
    damier[x][y]= -1;
}

/*=================================================
 FONCTION:  victoire(Lpions ,damier) INT
 Verifie les conditions de victoire
  - Si le neutron a atteint un camp
  - Si tous les pions du joueur sont bloqués

 DONNEE :
 - damier : Matrice d'ENTIER de taille 5
 - Lpions : Lpions : Vecteur de PIONS de taille 11
 - tour: INT

 VARIABLE LOCALE :
 - bloquage INT
 - pionbloque INT
 - x INT
 - y INT
===================================================*/


int victoire(pion *Lpions ,int damier[][5],int tour){
    //Test Du Neutron dans les camps rouge ou bleu
    if(Lpions[10].x==0){
        printf("______________________Joueur Rouge Gagne ! ______________________\n");
        return 1;
    }
    else if(Lpions[10].x==4){
        printf("______________________Joueur Bleu Gagne ! ______________________\n");
        return 1;
    }
    //test du neutron bloqué
    int x=Lpions[10].x,y=Lpions[10].y;
    int bloquage=0;

    //vérification si le pion est au bord du damier
    if(y-1<0 || y+1>4){
        bloquage+=3;
    }

    // on vérifie toutes les directions du pion sélectionné
    if(x-1>=0 && damier[x-1][y] !=-1){
        bloquage++;
    }
    if(x+1<5 && damier[x+1][y] !=-1){
        bloquage++;
    }
    if(y-1>=0 && damier[x][y-1] !=-1){
        bloquage++;
    }
    if(y+1<5 && damier[x][y+1] !=-1){
        bloquage++;
    }
    if(x+1<5 && y+1<5 && damier[x+1][y+1] !=-1){
        bloquage++;
    }
    if(x-1>=0 && y-1>=0 && damier[x-1][y-1] !=-1){
        bloquage++;
    }
    if(x-1>=0 && y+1<5 && damier[x-1][y+1] !=-1){
        bloquage++;
    }
    if(x+1<5 && y-1>=0 && damier[x+1][y-1] !=-1){
        bloquage++;
    }


    if (bloquage == 8 && tour%2==0) {
        printf("Neutron Bloqué ! \n");
        printf("______________________Joueur Rouge Gagne ! ______________________\n");
        return 1;
    }
    else if(bloquage == 8 && tour%2!=0){
        printf("Neutron Bloqué ! \n");
        printf("______________________Joueur Bleu Gagne ! ______________________\n");
        return 1;
    }

    //test si le joueur ROUGE peut jouer
    int pionbloque=0;
    for (int i=0;i<=4;i++){
        int x=Lpions[i].x,y=Lpions[i].y;
        int bloquage=0;

        //vérification si le pion est au bord du damier
        if((x-1<0 || x+1>4)&&(y-1<0 || y+1>4)){
            bloquage+=5;
        }
        else if(y-1<0 || y+1>4 || x-1<0 || x+1>4){
            bloquage+=3;
        }

        // on vérifie toutes les directions du pion sélectionné
        if(x-1>=0 && damier[x-1][y] !=-1){
            bloquage++;
        }
        if(x+1<5 && damier[x+1][y] !=-1){
            bloquage++;
        }
        if(y-1>=0 && damier[x][y-1] !=-1){
            bloquage++;
        }
        if(y+1<5 && damier[x][y+1] !=-1){
            bloquage++;
        }
        if(x+1<5 && y+1<5 && damier[x+1][y+1] !=-1){
            bloquage++;
        }
        if(x-1>=0 && y-1>=0 && damier[x-1][y-1] !=-1){
            bloquage++;
        }
        if(x-1>=0 && y+1<5 && damier[x-1][y+1] !=-1){
            bloquage++;
        }
        if(x+1<5 && y-1>=0 && damier[x+1][y-1] !=-1){
            bloquage++;
        }
        //si la variable bloquage atteint 8 donc les 8 direction sont bloques , la variable pionbloque est incrementé un pion de plus est bloqué
        if (bloquage == 8) {
            pionbloque++;
        }
    }
    //si le nombre de pion bloque pour l'equipe atteint 5 cela veut dire que tt les pions sont bloqués et donc le joueur perd
    if(pionbloque==5){
        printf("______________________Joueur Bleu Gagne ! ______________________\n");
        return 1;
    }

    //test si le joueur BLEU peut jouer
    pionbloque=0;
    for (int i=5;i<=9;i++){
        int x=Lpions[i].x,y=Lpions[i].y;
        int bloquage=0;

        if((x-1<0 || x+1>4)&&(y-1<0 || y+1>4)){
            bloquage+=5;
        }
        else if(y-1<0 || y+1>4 || x-1<0 || x+1>4){
            bloquage+=3;
        }

        // on vérifie toutes les directions du pion sélectionné
        if(x-1>=0 && damier[x-1][y] !=-1){
            bloquage++;
        }
        if(x+1<5 && damier[x+1][y] !=-1){
            bloquage++;
        }
        if(y-1>=0 && damier[x][y-1] !=-1){
            bloquage++;
        }
        if(y+1<5 && damier[x][y+1] !=-1){
            bloquage++;
        }
        if(x+1<5 && y+1<5 && damier[x+1][y+1] !=-1){
            bloquage++;
        }
        if(x-1>=0 && y-1>=0 && damier[x-1][y-1] !=-1){
            bloquage++;
        }
        if(x-1>=0 && y+1<5 && damier[x-1][y+1] !=-1){
            bloquage++;
        }
        if(x+1<5 && y-1>=0 && damier[x+1][y-1] !=-1){
            bloquage++;
        }

        //si la variable bloquage atteint 8 donc les 8 direction sont bloques , la variable pionbloque est incrementé un pion de plus est bloqué
        if (bloquage == 8) {
            pionbloque++;
        }
    }
    //si le nombre de pion bloque pour l'equipe atteint 5 cela veut dire que tt les pions sont bloqués et donc le joueur perd 
    if(pionbloque==5){
        printf("______________________Joueur Rouge Gagne ! ______________________\n");
        return 1;
    }
    return 0;
}

/*============================================
            FONCTION PRINCIPALE
                   MAIN
============================================*/


int main(){
    int tour=0;
    pion Lpions[11];
    int damier[5][5];
    int x,y,dir;
    void (*Ldirection[])(pion *, int (*)[5], int,  int) = {d1,d2,d3,d4,d5,d6,d7,d8};
    //initialisation des 11 pions totals sur le damier
    initialisation(Lpions);
    //mettre les pions sur le damier
    initdamier(Lpions,damier);
    //afficher le damier
    affichedamier(damier, Lpions);

    do {

        if(victoire(Lpions,damier,tour)){ //Si il y'a occurence de victoire la fonction renvoie 1 et donc arrete le jeu 
            x=-1;
            affichedamier(damier, Lpions);
        }
        else{

            if(tour){ // le joueur déplace le Neutron
                if(tour%2==0){
                    printf("C'est le tour du joueur %s Bleu %s%s \n",bleu,reverse,reset);
                }
                else{
                    printf("C'est le tour du joueur %s Rouge %s%s \n",rouge,reverse,reset);
                }
                //choix de la direction pour bouger le neutron
                printf("Donner une direction pour bouger le neutron 1-8: \n");
                scanf("%d",&dir);
                //bouger le neutron selon la direction choisie
                Ldirection[dir-1](Lpions,damier,Lpions[10].x,Lpions[10].y);
                //pour garder lisible et visible le jeu sans accumulation
                system("clear");
                affichedamier(damier, Lpions);
            }
            if(tour%2==0){ // le joueur déplace un pion de son choix
                printf("C'est le tour du joueur %s Bleu %s%s \n",bleu,reverse,reset);
            }
            else{
                printf("C'est le tour du joueur %s Rouge %s%s \n",rouge,reverse,reset);
            }
            //choix du pion a bouger
            printf("Donner les coordonne du pion a bouger dans le format 'X,Y' exemple '5,1' pour le pion le plus en haut a gauche: \n");
            scanf("%d,%d",&x,&y);
            //choix de la direction
            printf("Donner une direction de 1-8: \n");
            scanf("%d",&dir);
            //bouger le pion
            Ldirection[dir-1](Lpions,damier,5-x,y-1);
            //pour garder lisible et visible le jeu sans accumulation
            system("clear");
            affichedamier(damier, Lpions);
            //le tour avance
            tour++;

        }

    } while (x!=-1); // condition victoire
}
