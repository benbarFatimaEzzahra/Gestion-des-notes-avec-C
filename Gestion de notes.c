#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct etudiant {
	int num;
	char nom[30];
	float moy;
	struct etudiant *next;
}Etudiant;

//Question 1
int nombreEtudiant(Etudiant *gi1){
	int n=0;
	while(gi1 != NULL){
		n++;
		gi1=gi1->next;
	}
	return n;
}

//Question 2
int recherche(Etudiant *gi1, int numero){
	while(gi1 != NULL){
		if(numero == gi1->num){
			return 1;
		}
		gi1=gi1->next;
	}
	return 0;
}

//Question3
void affichageRattrapage(Etudiant *gi1){
	while(gi1 != NULL) {
		if(gi1->moy>=6 && gi1->moy<12){
			printf("%d  %.2f  %s\n", gi1->num, gi1->moy, gi1->nom);
		}
		gi1=gi1->next;
	}
}

Etudiant *allouer(int num,float moy,char *nom){
	Etudiant *nv=NULL;
	nv=(Etudiant*)malloc(sizeof(Etudiant));
	
	if(nv == NULL){
		exit(-1);
	} 
	
	nv->moy = moy;
	strcpy(nv->nom , nom);
	nv->num = num;
	nv->next = NULL;
	
	return nv;
}

Etudiant *insererDebut(Etudiant *tete,int num,float moy,char *nom){
	Etudiant *nv=allouer(num, moy, nom);
	
	nv->next=tete;
	
	return nv;
}

//Question4
Etudiant* passage2Annee(Etudiant *gi1){
	Etudiant *gi2=NULL;
	
	while(gi1 != NULL){
		if(gi1->moy >= 12){
			gi2=insererDebut(gi2,gi1->num,gi1->moy,gi1->nom);
		}
		gi1=gi1->next;
	}
	
	return gi2;
}

void affichage(Etudiant *tete){
	while(tete != NULL) {
		printf("%d  %.2f  %s\n", tete->num, tete->moy, tete->nom);
		tete=tete->next;
	}
}


int main(){
	Etudiant *gi1=NULL;
	gi1=insererDebut(gi1,1,17,"ALI");
	gi1=insererDebut(gi1,2,11,"NADA");
	gi1=insererDebut(gi1,3,16,"SARA");
	gi1=insererDebut(gi1,4,19,"BADR");
	gi1=insererDebut(gi1,5,8,"YAHYA");
	
	
	affichage(gi1);
	
	printf("\nLe nombre des etudiant est %d\n",nombreEtudiant(gi1));
	
	if(recherche(gi1,55)==1){
		printf("l etudiant 55 existe\n");
	}else{
		printf("l etudiant 55 n existe pas\n");
	}
	
	affichageRattrapage(gi1);
	
	printf("\nEtudiants de la deuxieme annee:\n");
	affichage(passage2Annee(gi1));
}





