

/*Définitions liste*/
typedef struct liste_couleurs {                
	struct couleur{
	unsigned char rouge;
	unsigned char vert;
	unsigned char bleu;
	unsigned char alpha;
	}*couleur;
	struct liste_couleurs *next;
}liste_couleurs;             


/*Prototypes*/
liste_couleurs* insertion(struct couleur *c,liste_couleurs *li);
liste_couleurs* remove_first_color(liste_couleurs *li);             
void parcours(liste_couleurs *li);

