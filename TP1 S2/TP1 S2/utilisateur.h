
/*
 *********************************
 *  interface du module maillon  *
 *      (Modèle des LLC)         *
 *********************************
*/


#include <stdio.h>
#include <stdlib.h>	/// pour malloc et free
#include <string.h>

#ifndef UTILISATEUR
#define UTILISATEUR


/// Creation d'une structure d'enregistrement
///        pour chaque utilisateure
typedef struct utilisateur utilisateur ;

struct utilisateur
{
    char  nom[25] ;
    char  ville[100] ;
    long  octet ;

    utilisateur* precedente ;
    utilisateur* suivant ;

    utilisateur* followings [100] ;
};

/// Creation de la base de donnees
utilisateur* tableau [26] ;

/// Declaration des fonctions
void creation_DataB ();
/*
 **************************************
 *          Machine abstraire         *
 *                                    *
 **************************************
*/
void Allouer( utilisateur** p );/// Creer un nouveau maillon .
void liberer (utilisateur** p );/// Liberer un maillon .
void aff_nom(utilisateur* p , char* nom) ; /// affecter le nom pour l'utilisateur
void aff_ville(utilisateur* p , char* ville) ; /// affecter la ville pour l'utilisateur
void aff_adr (utilisateur* p , utilisateur* q) ; /// indiquer que (q) et le suivant de (p) .
utilisateur* suivant (utilisateur* p );/// Donner le suivant du maillon .
utilisateur* precedent (utilisateur* p );/// Donner le precedent du maillon .
///////////////////////////////////////////////////////////////////////////////////////////////////
/*
 **************************************
 *        Autres Fonctions            *
 *                                    *
 **************************************
*/
utilisateur* detect_lettre (char* chaine );/// Detecter en quelle case[26 cases = 26 lettres] il faut stocker le nom d'utilisateur
utilisateur* creation_utilisateur(utilisateur* dernier_utilisateur,char* name) ; /// c est pour creer un nouveau utilisateur .
void suppression (char* nom) ; ///   c est pour supprimer un utilisateur .
void modification_utilisateur () ; /// c est pour modifier les information d'un utilisateur
void affichage_utilisateur () ;/// c est pour afficher les information d'un utilisateur
void recherche_par_nom () ; /// pour trouver esq l'utilisateur existe ou pas en utilisant son nom .
void recherche_par_ville () ; /// pour trouver esq l'utilisateur existe ou pas en utilisant sa ville .
void recherche_par_octet() ; /// pour trouver esq l'utilisateur existe ou pas en utilisant son centre d'interet  .
void suggestion_par_nom (char* suggestionName) ;/// donner des sugestion pour abonner des utilisateur .
void abonnement_utilisateur (); ///  pour abonner un nouveaau utilisateur .
int Detect_sim(int a,int b,int i); /// pour detecter les similarites entre 02 octets de centre d'interet .
void suggestion_par_octet () ; /// pour suggerer des utilisateurs  par raport au centre d' interet .void
void aff_liste_followings (char* username); ///  pour afficher la liste de followings d'une utilisateur .
void free_DATABAse () ; ///  Pour liberer l'espace reserver par la base de donnee .
void Sauvgarde () ; /// pour sauvgarder la base de donnee .
void restauration () ; /// pour restaurer la base de donnee sauvgardee .








#endif


