#include <stdio.h>
#include <stdlib.h>

int main()
{
     /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             Réalisée par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/


  /*_____________declarations des variables______________*/

  #include <stdio.h>
  #include <stdlib.h>

  typedef int bool ;
  typedef char * string255 ;
  typedef char * string2 ;

  #define True 1
  #define False 0

  /** Implémentation **\: ARBRE BINAIRE DE STRUCTURES**/

  /** Structures statiques **/

  typedef struct Tcb Type_Tcb  ;
  typedef Type_Tcb * Typestr_Tcb ;
  typedef string2 Type1_Tcb  ;
  typedef bool Type2_Tcb  ;
  struct Tcb
    {
      Type1_Tcb Champ1 ;
      Type2_Tcb Champ2 ;
    };

  Type1_Tcb Struct1_Tcb ( Typestr_Tcb S)
    {
      return  S->Champ1 ;
    }

  Type2_Tcb Struct2_Tcb ( Typestr_Tcb S)
    {
      return  S->Champ2 ;
    }

  void Aff_struct1_Tcb ( Typestr_Tcb S, Type1_Tcb Val )
    {
      strcpy( S->Champ1 , Val );
    }

  void Aff_struct2_Tcb ( Typestr_Tcb S, Type2_Tcb Val )
    {
       S->Champ2 = Val ;
    }


  /** Arbres de recherche binaire **/

  typedef Typestr_Tcb Typeelem_ATcb   ;
  typedef struct Noeud_ATcb * Pointeur_ATcb ;

  struct Noeud_ATcb
    {
      Typeelem_ATcb  Val ;
      Pointeur_ATcb Fg ;
      Pointeur_ATcb Fd ;
      Pointeur_ATcb Pere ;
     } ;

  Typeelem_ATcb Info_ATcb( Pointeur_ATcb P )
    { return P->Val;   }

  Pointeur_ATcb Fg_ATcb( Pointeur_ATcb P)
    { return P->Fg ; }

  Pointeur_ATcb Fd_ATcb( Pointeur_ATcb P)
    { return P->Fd ; }

  Pointeur_ATcb Pere_ATcb( Pointeur_ATcb P)
    { return P->Pere ; }

  void Aff_info_ATcb ( Pointeur_ATcb P, Typeelem_ATcb Val)
    {
      Typeelem_ATcb _Temp ;
      _Temp = malloc(sizeof(Typestr_Tcb));
      _Temp->Champ1 = malloc(2 * sizeof(string2));
      /* Affectation globale de structure */
      strcpy(_Temp->Champ1, Val->Champ1);
      _Temp->Champ2 = Val->Champ2;
      Val = _Temp ;
       P->Val = Val ;
    }

  void Aff_fg_ATcb( Pointeur_ATcb P, Pointeur_ATcb Q)
    { P->Fg =  Q;  }

  void Aff_fd_ATcb( Pointeur_ATcb P, Pointeur_ATcb Q)
    { P->Fd =  Q ; }

  void Aff_pere_ATcb( Pointeur_ATcb P, Pointeur_ATcb Q)
    { P->Pere =  Q ; }

  void Creernoeud_ATcb( Pointeur_ATcb *P)
    {
      *P = (struct Noeud_ATcb *) malloc( sizeof( struct Noeud_ATcb))   ;
      (*P)->Val = malloc(sizeof(Typestr_Tcb));
      (*P)->Val->Champ1 = malloc( 2 * sizeof(string2));
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_ATcb( Pointeur_ATcb P)
    { free( P ) ; }


  /** Implémentation **\: TABLEAU DE CARACTERES**/

  /** Tableaux **/

  typedef string2 Typeelem_V13c ;
  typedef Typeelem_V13c * Typevect_V13c ;

  Typeelem_V13c Element_V13c ( Typevect_V13c V , int I1  )
    {
      return  *(V + I1-1 ) ;
    }

  void Aff_element_V13c ( Typevect_V13c V  , int I1 ,  Typeelem_V13c Val )
    {
     strcpy( *(V + I1-1 ) , Val );
    }

  /** Pour les variables temporaires **/
  typedef Typeelem_V13c Typetab_V13c[13];

  /** Variables du programme principal **/
  Pointeur_ATcb A;
  Pointeur_ATcb Parent;
  Pointeur_ATcb No;
  string2 Char;
  int M;
  int L;

  /** Fonctions standards **/

  char *Caract ( string255 Ch , int I )
    {
      char *s = malloc(2);
      s[0] = Ch[I-1];
      s[1] = '\0';
      return  s;
    }

  int Longchaine ( string255 Ch  )
    {
      return strlen(Ch);
    }

  int Aleanombre( int N )
    { return ( rand() % N ); }

  char  *Aleachaine ( int N )
    {
      int k;
      char  * Chaine = malloc(N+1);

      char Chr1[26] = "abcdefghijklmnopqrstuvwxyz";
      char Chr2[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

      for (k=0;k<N; k++)
        switch ( rand() % 2 ){
        case 0 :  *(Chaine+k) = Chr1[rand() % 26] ; break ;
        case 1 :  *(Chaine+k) = Chr2[rand() % 26] ; break ;
        }
      Chaine[k] =  '\0' ;

      return (Chaine);
    }


  /** Initialisation d'un tableau **/
  void Init_vect_V13c (  Typevect_V13c T , Typetab_V13c Tab , int N)
    {
      int K=-1;
     int I1 ;
     for (I1=0; I1< 13; ++I1)
        {
          K++;
        strcpy( *(T + I1 ) , Tab [K] );
        }
    }


  /** Prototypes des fonctions **/

  void Inserer (Pointeur_ATcb *Parent , Pointeur_ATcb *Prev , int *J , string255 *Mot);
  string2  Transferer (string2 *Ch) ;
  string2  Character (Pointeur_ATcb *P) ;
  void Search (int *I , Pointeur_ATcb *No , Pointeur_ATcb *Parent , Pointeur_ATcb *Prev , string255 *Word);
  void Creer_arbre (int *M , int *L , Pointeur_ATcb *A);

  /*______________module inserer_________*/
  /*-----les variables-----*/

  void Inserer (Pointeur_ATcb *Parent , Pointeur_ATcb *Prev , int *J , string255 *Mot)
    {
      /** Variables locales **/
      string2 Char;
      Pointeur_ATcb No;
      Pointeur_ATcb P;
      Pointeur_ATcb Tmp;
      Typestr_Tcb S;

      /** Corps du module **/
     Char = malloc(2 * sizeof(string2));
     S = malloc(sizeof(Typestr_Tcb));
     S->Champ1 = malloc(2 * sizeof(string2));
     strcpy (Char,   Caract(*Mot , *J )) ;
     strcpy (Char,   Transferer ( & Char )) ;
     Creernoeud_ATcb(&No ) ;
     Aff_struct1_Tcb(S  , Char ) ;
     Aff_struct2_Tcb(S  , False ) ;
     Aff_info_ATcb(No , S ) ;
     if( ( *Prev == NULL )) {
       if( ( *J == 1 )) {
         Tmp  =  *Prev ;
         Aff_fd_ATcb(No , Tmp ) ;
         A  =  No ;
         }
       else
         {
         Tmp  =  Fg_ATcb(*Parent ) ;
         Aff_fg_ATcb(*Parent , No ) ;
         Aff_fd_ATcb(No , Tmp ) ;

       } ;
       }
     else
       {
       Tmp  =  Fd_ATcb(*Prev ) ;
       Aff_fd_ATcb(*Prev , No ) ;
       Aff_fd_ATcb(No , Tmp ) ;

     } ;
     *J  =  *J + 1 ;
     *Prev  =  No ;
     while( ( *J <= Longchaine(*Mot ) )) {
       Creernoeud_ATcb(&No ) ;
       strcpy (Char,   Caract(*Mot , *J )) ;
       strcpy (Char,   Transferer ( & Char )) ;
       Aff_struct1_Tcb(S  , Char ) ;
       Aff_struct2_Tcb(S  , False ) ;
       Aff_info_ATcb(No , S ) ;
       Aff_fg_ATcb(*Prev , No ) ;
       *Prev  =  No ;
       *J  =  *J + 1 ;

     } ;
     Aff_struct2_Tcb(Info_ATcb(No )  , True ) ;

    }
  /*________________fonction transferer____________________________*/
  /* elle transforme les lettres mjuscules en lettres miniscules_______*/
  string2  Transferer (string2 *Ch)
    {
      /** Variables locales **/
      string2  Transferer2 ;
      Typevect_V13c T1;
      Typevect_V13c T2;
      Typevect_V13c T3;
      Typevect_V13c T4;
      int I;
      int J;
      bool Continu;
      bool Stop;
      string255 Mot;
        Typetab_V13c T_T1;
        Typetab_V13c T_T2;
        Typetab_V13c T_T3;
        Typetab_V13c T_T4;

      /** Corps du module **/
     T1 = malloc(13 * 2  * sizeof(string2));
     int _Izw2;for (_Izw2=0; _Izw2<13; ++_Izw2)
       T1[_Izw2]= malloc(2 * sizeof(string2));
     T2 = malloc(13 * 2  * sizeof(string2));
     int _Izw3;for (_Izw3=0; _Izw3<13; ++_Izw3)
       T2[_Izw3]= malloc(2 * sizeof(string2));
     T3 = malloc(13 * 2  * sizeof(string2));
     int _Izw4;for (_Izw4=0; _Izw4<13; ++_Izw4)
       T3[_Izw4]= malloc(2 * sizeof(string2));
     T4 = malloc(13 * 2  * sizeof(string2));
     int _Izw5;for (_Izw5=0; _Izw5<13; ++_Izw5)
       T4[_Izw5]= malloc(2 * sizeof(string2));
     Mot = malloc(255 * sizeof(string255));
     int _Izw6;for (_Izw6=0; _Izw6<13; ++_Izw6)
       T_T1[_Izw6]= malloc(2 * sizeof(string2));
     int _Izw7;for (_Izw7=0; _Izw7<13; ++_Izw7)
       T_T2[_Izw7]= malloc(2 * sizeof(string2));
     int _Izw8;for (_Izw8=0; _Izw8<13; ++_Izw8)
       T_T3[_Izw8]= malloc(2 * sizeof(string2));
     int _Izw9;for (_Izw9=0; _Izw9<13; ++_Izw9)
       T_T4[_Izw9]= malloc(2 * sizeof(string2));
     Transferer2 = malloc(2 * sizeof(string2));
     strcpy(T_T1 [ 0 ] , "A" );
     strcpy(T_T1 [ 1 ] , "B" );
     strcpy(T_T1 [ 2 ] , "C" );
     strcpy(T_T1 [ 3 ] , "D" );
     strcpy(T_T1 [ 4 ] , "E" );
     strcpy(T_T1 [ 5 ] , "F" );
     strcpy(T_T1 [ 6 ] , "G" );
     strcpy(T_T1 [ 7 ] , "H" );
     strcpy(T_T1 [ 8 ] , "I" );
     strcpy(T_T1 [ 9 ] , "J" );
     strcpy(T_T1 [ 10 ] , "K" );
     strcpy(T_T1 [ 11 ] , "L" );
     strcpy(T_T1 [ 12 ] , "M" );
     Init_vect_V13c ( T1 , T_T1 , 13 )  ;
     strcpy(T_T2 [ 0 ] , "N" );
     strcpy(T_T2 [ 1 ] , "O" );
     strcpy(T_T2 [ 2 ] , "P" );
     strcpy(T_T2 [ 3 ] , "Q" );
     strcpy(T_T2 [ 4 ] , "R" );
     strcpy(T_T2 [ 5 ] , "S" );
     strcpy(T_T2 [ 6 ] , "T" );
     strcpy(T_T2 [ 7 ] , "U" );
     strcpy(T_T2 [ 8 ] , "V" );
     strcpy(T_T2 [ 9 ] , "W" );
     strcpy(T_T2 [ 10 ] , "X" );
     strcpy(T_T2 [ 11 ] , "Y" );
     strcpy(T_T2 [ 12 ] , "Z" );
     Init_vect_V13c ( T2 , T_T2 , 13 )  ;
     strcpy(T_T3 [ 0 ] , "a" );
     strcpy(T_T3 [ 1 ] , "b" );
     strcpy(T_T3 [ 2 ] , "c" );
     strcpy(T_T3 [ 3 ] , "d" );
     strcpy(T_T3 [ 4 ] , "e" );
     strcpy(T_T3 [ 5 ] , "f" );
     strcpy(T_T3 [ 6 ] , "g" );
     strcpy(T_T3 [ 7 ] , "h" );
     strcpy(T_T3 [ 8 ] , "i" );
     strcpy(T_T3 [ 9 ] , "j" );
     strcpy(T_T3 [ 10 ] , "k" );
     strcpy(T_T3 [ 11 ] , "l" );
     strcpy(T_T3 [ 12 ] , "m" );
     Init_vect_V13c ( T3 , T_T3 , 13 )  ;
     strcpy(T_T4 [ 0 ] , "n" );
     strcpy(T_T4 [ 1 ] , "o" );
     strcpy(T_T4 [ 2 ] , "p" );
     strcpy(T_T4 [ 3 ] , "q" );
     strcpy(T_T4 [ 4 ] , "r" );
     strcpy(T_T4 [ 5 ] , "s" );
     strcpy(T_T4 [ 6 ] , "t" );
     strcpy(T_T4 [ 7 ] , "u" );
     strcpy(T_T4 [ 8 ] , "v" );
     strcpy(T_T4 [ 9 ] , "w" );
     strcpy(T_T4 [ 10 ] , "x" );
     strcpy(T_T4 [ 11 ] , "y" );
     strcpy(T_T4 [ 12 ] , "z" );
     Init_vect_V13c ( T4 , T_T4 , 13 )  ;
     I  =  1 ;
     Continu  =  False ;
     while( ( I <= 13 ) && ( Continu == False )) {
       if( (strcmp( *Ch, Element_V13c(T1 , I   )) == 0  )) {
         Continu  =  True ;
         }
       else
         {
         I  =  I + 1 ;

       } ;

     } ;
     J  =  1 ;
     Stop  =  False ;
     if( ( Continu == False )) {
       while( ( J <= 13 ) && ( Stop == False )) {
         if( (strcmp( *Ch, Element_V13c(T2 , J   )) == 0  )) {
           Stop  =  True ;
           }
         else
           {
           J  =  J + 1 ;

         } ;

       } ;

     } ;
     if( ( Continu == True )) {
       strcpy (Transferer2,   Element_V13c(T3 , I   )) ;
       }
     else
       {
       if( ( Stop == True )) {
         strcpy (Transferer2,   Element_V13c(T4 , J   )) ;
         }
       else
         {
         strcpy (Transferer2,   *Ch) ;

       } ;

     } ;

     return Transferer2 ;
    }
  /*_______________________module character____________________________*/
  string2  Character (Pointeur_ATcb *P)
    {
      /** Variables locales **/
      string2  Character2 ;

      /** Corps du module **/
     Character2 = malloc(2 * sizeof(string2));
     strcpy (Character2,   Struct1_Tcb(Info_ATcb(*P )  )) ;

     return Character2 ;
    }
  /*____________________module recherche________________________*/
  /*permet de recherche un caractere dans un mot_____________*/
  void Search (int *I , Pointeur_ATcb *No , Pointeur_ATcb *Parent , Pointeur_ATcb *Prev , string255 *Word)
    {
      /** Variables locales **/
      Pointeur_ATcb P;
      bool Trouv;
      bool Arret;
      string2 Lettre;
      Pointeur_ATcb _Px1;

      /** Corps du module **/
     Lettre = malloc(2 * sizeof(string2));
     if( ( *I != 1 )) {
       P  =  Fg_ATcb(*Parent ); }
     else
       {
       P  =  *Parent ;

     } ;
     Trouv  =  False ;
     Arret  =  False ;
     *No  =  NULL ;
     strcpy (Lettre,   Caract(*Word , *I )) ;
     strcpy (Lettre,   Transferer ( & Lettre )) ;
     while( ( Trouv == False ) && ( Arret == False ) && ( P != NULL )) {
       if( (strcmp( Character ( & P ), Lettre) == 0  )) {
         Trouv  =  True ;
         *No  =  P ;
         }
       else
         {
         if( (strcmp( Character ( & P ), Lettre) > 0  )) {
           Arret  =  True ;
           }
         else
           {
           if( ( Fd_ATcb(P ) == NULL )) {
             Arret  =  True ;
             *Prev  =  P ;
             }
           else
             {
             _Px1 =  Fd_ATcb(P ) ;
             if( (strcmp( Character ( &_Px1), Lettre) > 0  )) {
               Arret  =  True ;
               *Prev  =  P ;
               }
             else
               {
               P  =  Fd_ATcb(P ) ;

             } ;

           } ;

         } ;

       } ;

     } ;

    }
  /*________________creer un arbre_____________________*/
  void Creer_arbre (int *M , int *L , Pointeur_ATcb *A)
    {
      /** Variables locales **/
      int I;
      int J;
      int Deb;
      string255 Mot;
      Pointeur_ATcb Prec;
      Typestr_Tcb S;
      string2 Lettre;
      int _Px1;

      /** Corps du module **/
     Mot = malloc(255 * sizeof(string255));
     S = malloc(sizeof(Typestr_Tcb));
     S->Champ1 = malloc(2 * sizeof(string2));
     Lettre = malloc(2 * sizeof(string2));
     for( I  =  1 ;I <=  *M ; ++I){
       Prec  =  NULL ;
       strcpy (Mot,   Aleachaine(Aleanombre(*L ) + 1 )) ;
       strcpy (Lettre,   Caract(Mot , 1 )) ;
       strcpy (Lettre,   Transferer ( & Lettre )) ;
       if( ( *A == NULL )) {
         Creernoeud_ATcb(&*A ) ;
         Aff_struct1_Tcb(S  , Lettre ) ;
         Aff_struct2_Tcb(S  , False ) ;
         Aff_info_ATcb(*A , S ) ;
         if( Longchaine(Mot ) > 1) {
           _Px1 =  2 ;
           Inserer ( & *A , & Prec , &_Px1, & Mot ) ;
           printf ( " %d", Struct2_Tcb(Info_ATcb(*A)) ) ;
           }
         else
           {
           Aff_struct2_Tcb(Info_ATcb(*A )  , True ) ;
           printf ( " %d", Struct2_Tcb(Info_ATcb(*A)) ) ;

         } ;
         }
       else
         {
         Parent  =  *A ;
         J  =  1 ;
         No  =  *A ;
         while( ( No != NULL ) && ( J <= Longchaine(Mot ) )) {
           Search ( & J , & No , & Parent , & Prec , & Mot ) ;
           if( ( No != NULL )) {
             Parent  =  No ;
             J  =  J + 1 ;

           } ;

         } ;
         if( J > Longchaine(Mot )) {
           strcpy (Lettre,   Caract(Mot , Longchaine(Mot ) )) ;
           Aff_struct1_Tcb(S  , Lettre ) ;
           Aff_struct2_Tcb(S  , True ) ;
           Aff_info_ATcb(No , S ) ;
           }
         else
           {
           Inserer ( & Parent , & Prec , & J , & Mot );
         } ;

       } ;

     } ;

    }

  int main(int argc, char *argv[])
    {
     Char = malloc(2 * sizeof(string2));
     M  =  15 ;
     L  =  10 ;
     Creer_arbre ( & M , & L , & A ) ;


      system("PAUSE");
      return 0;
    }
    printf("Hello world!\n");
    return 0;
}
