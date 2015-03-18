#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>


typedef unsigned char   u8; 
typedef unsigned short  u16;    
typedef unsigned int    u32;


int main(int argc, char * argv[])
{
	register  int i, n;

	int nb_entrees;
	int nb_parcours;
	u32 * bloc;
	struct timeval tv_debut;
	struct timeval tv_fin;
	long long int duree_lectures;
	long long int duree_ecritures;

	if ((argc != 3)
	 || (sscanf(argv[1], "%d", & nb_entrees) != 1)
	 || (sscanf(argv[2], "%d", & nb_parcours) != 1)) {
		fprintf(stderr,"usage: %s nb_entrees nb_parcours\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fprintf(stderr, "Preparation de la table des donnees...\n");
	bloc = calloc(nb_entrees, sizeof(u32));

	// Chaque entree contient le numero de la case suivante
	for (i = 0; i < nb_entrees-1; i ++)
		bloc[i] = i+1;
	// La derniere entree est indiquee par -1
	bloc[i] = -1;

	fprintf(stderr, "Table prete...\n");

	fprintf(stderr, "Parcours en lecture...\n");
	gettimeofday(& tv_debut, NULL);
	for (n = 0; n < nb_parcours; n ++) {
		i = 0;
		while(i != -1) {
			i=bloc[i];
		}
	}
	gettimeofday(& tv_fin, NULL);
	duree_lectures  = tv_fin.tv_sec - tv_debut.tv_sec;
	duree_lectures *= 1000000;
	duree_lectures += tv_fin.tv_usec - tv_debut.tv_usec;

	fprintf(stderr, "Parcours en ecriture...\n");
	gettimeofday(& tv_debut, NULL);
	for (n = 0; n < nb_parcours; n ++) {
		i = 0;
		// On decremente chaque entree sauf la derniere
		while(i != -1) {
			i=(bloc[i]--);
		}
		i = 0;
		// On incremente chaque entree sauf la derniere
		while(i != -1)
			i=(++bloc[i]);
	}
	gettimeofday(& tv_fin, NULL);
	duree_ecritures  = tv_fin.tv_sec - tv_debut.tv_sec;
	duree_ecritures*= 1000000;
	duree_ecritures += tv_fin.tv_usec - tv_debut.tv_usec;
	duree_ecritures /= 2; // Deux parcours complets

	fprintf(stderr, "Parcours termines...\n");

	// Durees en centiemes de nanosecondes
	duree_lectures  = duree_lectures  * 100000 / (nb_entrees * nb_parcours);
	duree_ecritures = duree_ecritures * 100000 / (nb_entrees * nb_parcours);

	fprintf(stdout, "Duree par acces lecture  : %lld.%lld\n", duree_lectures/100, duree_lectures%100);
	fprintf(stdout, "Duree par acces ecriture : %lld.%lld\n", duree_ecritures/100, duree_ecritures%100);
	return 0;
}
