/* LA VERSION DU TP .Alg CONTIENT QUE LA SIMULATION DE LA COUPE DU MONDE */

/* LA VERSION .C CONTIENT LA SIMULATION D'AUTRES TOURNOIS D'EQUIPES AU CHOIX */

   SOIENT

       /***************************** LES FONCTION ET PROCEDURES ***********************************/



       /* Remplissage des tableaux fifa et favorites */
       /* Modules Remplissage Tableau classement de la FIFA */
       Aff_eq_fifa1 UNE ACTION ;
       Aff_eq_fifa2 UNE ACTION ;
       Aff_eq_fifa3 UNE ACTION ;
       Aff_eq_fifa4 UNE ACTION ;
       Aff_eq_fifa5 UNE ACTION ;
       /* Modules Remplissage Tableau classement des equipes favorites */
       Aff_eq_fav1 UNE ACTION ;
       Aff_eq_fav2 UNE ACTION ;
       Aff_eq_fav3 UNE ACTION ;
       Aff_eq_fav4 UNE ACTION ;
       Aff_eq_fav5 UNE ACTION ;
       /* Fin du Remplissage des tableaux fifa et favorites */

       Indice_chaine UNE FONCTION ( ENTIER ) ; /* Ret l'indice de la case du nom du pays dans le tab fifa ou fav */

       Indice_id UNE FONCTION ( ENTIER ) ;     /* Ret l'indice de la case du pays dans le tableau des equipes */

       ID_NAME UNE FONCTION ( CHAINE );        /* Ret le nom du pays de l'ID donne */

       Fill_WC_22 UNE ACTION;    /* Si on simule the 22 WC, cette fonction remplit le tableau des equipes */

       Fill_participants UNE ACTION ;  /* Remplit le tableau des equipes particiapntes */

       Create_groups UNE ACTION;    /* Cree les groupes */

       TRI_PT_W UNE ACTION ; /* Trie le tableau temporaire des pts des grps et modifie des grps en parallele */

       Match_nul_p1 UNE ACTION ; /* Modifie le Tableau des Equipes s'il y'a match nul phase 1 */

       Match_won_p1 UNE ACTION ; /* Modifie le Tableau des Equipes s'il y'a un gagnant nul phase 2 */

       Simuler_match_p1 UNE ACTION ; /* Simule un match de la pahse une */

       Simuler_Phase1 UNE ACTION; /* Simule toute la phase 2 */

       Group_Winners UNE ACTION ; /* Organise les gagnants des groupes dans les tableaux First et Second */

       TAB_LISTE_MATCHES UNE ACTION; /* Remplit le Tableau ds listes */

       Qualifies UNE ACTION; /* AFFICHE LES EQUIPES QUALIFIES DE CHAQUE GROUPE */

       Match_P2 UNE ACTION;  /* AFFECTE LES MODIFICATIONS DANS LE TABLEAU DES EQUIPES APRES UN MATCH DE PHASE 2 */

       Simuler_match_p2 UNE ACTION; /* SIMULE UN MATCH DE LA PHASE 2 */

       Simuler_Phase2 UNE ACTION; /* SIMULE TOUTE L PHASE 2 */

       ARBRE_PHASE2 UNE ACTION; /* FONCTION QUI CREE LA RACINE DE L'ARBRE ET APPELLE LA FCT RECURSIVE */

       Creer_Arb_P2 UNE ACTION; /* FOMCTION RECURSIVE QUI CREE L'ARBRE ET A PARTIR D'UN NOEUD EXISTANT */

       Empilage_Arbre UNE ACTION; /* FONCTION QUI EMPILE L'ARBRE DANS UNE PILE POUR LE PARCOURS EN LARGEUR INVERSE */

       REMPLISSAGE_8EME UNE ACTION; /* REMPLIT LES 8 FEUILLES AVEC LES EQUIPES RETENUES DE LA PHASE UNE */


       /***************************** LES VARIABLES ***********************************/

       Fifa UN VECTEUR ( 198 ) DE CHAINE ; /* TABLEAU CLASSEMENT FIFA */

       Fav UN VECTEUR ( 198 ) DE CHAINE ;  /* TABLEAU CLASSEMENT FAVORITES */

       Groups UN VECTEUR (8) DE ( ENTIER , ENTIER , ENTIER , ENTIER ); /* CONTIENT LES ID DE CHAQUE GROUPE */

       TAB_LISTES UN VECTEUR (8) DE LISTE DE (ENTIER , ENTIER); /* CHAQUE ELT CONTIENT UNE LISTE DES MATCHES DU GRP */

       Participants UN VECTEUR ( 32 ) DE ENTIER; /* CONTIENT LES IDs DES DES EQUIPES PARTICIPANTES AU TOURNOI */

       Equipes UN VECTEUR ( 32 ) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER ) ;

       /*    Equipes CONTIENT DANS CHAQUE CASE UNE EQUIPE PARTICIPANTE AU TOURNOI   */
       /* LA STRUCTURE CONTIENT : ID , NOM PAYS , RANK DANS FAV , PTS PH1 , PTS PH2 */

       PHASE_2 UN ARB DE ( ENTIER , ENTIER ); /* ARBRE DANS CHAQUE NOEUD LES EQUIPES PARTICIPANTES DANS L'ORDRE */

       FIRST , SECOND UN VECTEUR ( 8 ) DE ENTIER ; /* TABLEAUX CONTIENNENT PREMIERS ET DEUXIEMES DE CHAQUE GRP */

       PILE_PARCOURS UNE PILE DE ARB DE ( ENTIER , ENTIER ); /* DES NOEUDS DE L'ARBRE EMPILES EN LARGEUR INVERSE */

       Choice UN ENTIER; /* LE CHOIX DE LA CRITERE DE SIMUALTION PHASE UN ET DEUX */

   DEBUT

       /* Remplissage du Tableau de classement de la fifa */
       APPEL Aff_eq_fifa1 ( Fifa ) ;
       APPEL Aff_eq_fifa2 ( Fifa ) ;
       APPEL Aff_eq_fifa3 ( Fifa ) ;
       APPEL Aff_eq_fifa4 ( Fifa ) ;
       APPEL Aff_eq_fifa5 ( Fifa ) ;

       /* Remplissage du Teableau des favoris */
       APPEL Aff_eq_fav1 ( Fav ) ;
       APPEL Aff_eq_fav2 ( Fav ) ;
       APPEL Aff_eq_fav3 ( Fav ) ;
       APPEL Aff_eq_fav4 ( Fav ) ;
       APPEL Aff_eq_fav5 ( Fav ) ;

       /* Remplissages du Tableau des participants a la WC 2022 */
       APPEL Fill_WC_22 (Participants);

       /* Remplissage des participants : favoris , Nom , et ID */
       APPEL Fill_participants ( Participants , Fifa , Fav , Equipes );

       /* Creation des groupes */
       APPEL Create_groups ( Equipes , Groups );

       /* Creation du Tableau des listes */
       APPEL TAB_LISTE_MATCHES ( Groups , TAB_LISTES );

       /* Entree du choix du mode de simulation de la phase 1 */
       ECRIRE('Choix des criteres de simulation de la phase 1 :');
       ECRIRE('1 - Le hasard');
       ECRIRE('2 - Les equipes favorite');
       ECRIRE('3 - Selon le hasard et Les equipes favorite');
       ECRIRE('4 - Selon le classement de la FIFA');

       Choice := 0 ;

       TANTQUE (Choice > 4) OU (Choice <1)
              LIRE(Choice);
       FINTANTQUE;

       ECRIRE ( ' Les  Rencontres de la premiere phase : ' );
       ECRIRE ('');

       /* Simulation de la phase une */
       APPEL Simuler_Phase1 ( Equipes , TAB_LISTES , Choice , FIRST , SECOND );

       /* Affectation des premiers de groupes dans les tableaux */
       APPEL Group_Winners ( Groups , Equipes , FIRST , SECOND );

       /* Affichage des equipes qualifies */
       ECRIRE ( '' );
       ECRIRE ( ' Les equipes Qualifies : ' );
       APPEL Qualifies(FIRST, SECOND , Equipes);

       /* Choix du critere de simulation de la phase deux */
       ECRIRE('Choix des criteres de simulation de la phase 2 :');
       ECRIRE('1 - Le hasard');
       ECRIRE('2 - Les equipes favorite');
       ECRIRE('3 - Selon les resultats de la premiere phase');
       ECRIRE('4 - Selon les resultats de la premiere phase et la deuxieme phase');
       ECRIRE('5 - Selon les resultats de la premiere phase et Les equipes favorite');
       ECRIRE('6 - Selon les resultats de la premiere phase et la deuxieme phase et Les equipes favorite');
       ECRIRE('7 - Selon le classement de la FIFA');

       Choice := 0 ;

       TANTQUE (Choice > 7) OU (Choice <1)
               LIRE(Choice);
       FINTANTQUE;

       /* Creation de l'arbre */
       APPEL ARBRE_PHASE2 ( PHASE_2 );

       /* Empilage de l'arbre pour le parcours par niveau invrse */
       APPEL Empilage_Arbre ( PHASE_2 , PILE_PARCOURS );

       /* Affectation des 8emes */
       APPEL REMPLISSAGE_8EME ( PILE_PARCOURS , FIRST , SECOND );

       /* Simulation de la deuxieme phase */
       APPEL Simuler_Phase2 ( PILE_PARCOURS , Equipes , Choice );

   FIN

   /***************************************************   PHASE 2 ***************************************************/
   /*****************************************************************************************************************/

   ACTION Match_P2 ( Team1 , Team2 , Winner , Tab , Score )
   SOIENT
       E1 , E2 UN ENTIER ;
       Team1 , Team2 , Winner , Score DES ENTIERS ;
       Tab UN VECTEUR ( 32 ) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER ) ;

   DEBUT
       E1 := Indice_id ( Tab , Team1 ) ;
       E2 := Indice_id ( Tab , Team2 ) ;

       /* L'affectation consiste a ajouter a l'equipe gagnante le score du match ainsi
       que les points de la phase 2 de l'adversaire pour simuler le critere 4 */

       Score := Score + STRUCT ( ELEMENT (Tab[E1]) , 5 ) + STRUCT ( ELEMENT (Tab[E2]) , 5 );

       SI Team1 = Winner
            AFF_STRUCT ( ELEMENT (Tab[E1]) , 5 , Score );
       SINON
            AFF_STRUCT ( ELEMENT (Tab[E2]) , 5 , Score );
       FINSI;
   FIN

   /*****************************************************************************************************************/

   ACTION Simuler_match_p2 ( Team1 , Team2 , Winner , Tab , Choice )
   SOIENT
       Team1 , Team2 UN ENTIER ;
       Tab UN VECTEUR ( 32 ) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER ) ;
       Choice , Winner , Nombre1 , Nombre2 , E1 , E2 UN ENTIER ;

   DEBUT
       E1 := Indice_id ( Tab , Team1 ) ;
       E2 := Indice_id ( Tab , Team2 ) ;

       SI Choice = 1
           Nombre1 := ALEANOMBRE ( 10 ) ;
           Nombre2 := ALEANOMBRE ( 10 ) ;
           TANTQUE Nombre1 = Nombre2
                   Nombre1 := ALEANOMBRE ( 10 ) ;
                   Nombre2 := ALEANOMBRE ( 10 ) ;
           FINTANTQUE;
           SI Nombre1 > Nombre2
                APPEL Match_P2( Team1 , Team2 , Team1 , Tab , Nombre1 );
                Winner := Team1;
           SINON
                APPEL Match_P2( Team1 , Team2 , Team2 , Tab , Nombre2 );
                Winner := Team2;
           FINSI;
       SINON
            SI Choice = 2
               Nombre1 := STRUCT ( ELEMENT (Tab[E1]) , 3 );
               Nombre2 := STRUCT ( ELEMENT (Tab[E2]) , 3 );
               SI Nombre1 < Nombre2
                    APPEL Match_P2( Team1 , Team2 , Team1 , Tab , MOD(Nombre1,10) );
                    Winner := Team1;
               SINON
                    APPEL Match_P2( Team1 , Team2 , Team2 , Tab , MOD(Nombre2,10) );
                    Winner := Team2;
               FINSI;
            SINON
                 SI Choice = 3
                    Nombre1 := STRUCT ( ELEMENT(Tab[E1]) , 4 );
                    Nombre2 := STRUCT ( ELEMENT(Tab[E2]) , 4 );
                    TANTQUE Nombre1 = Nombre2
                            Nombre1 := Nombre1 + ALEANOMBRE (5);
                            Nombre1 := Nombre1 + ALEANOMBRE (5);
                    FINTANTQUE;
                    SI Nombre1 > Nombre2
                         APPEL Match_P2( Team1 , Team2 , Team1 , Tab , MOD(Nombre1,10) );
                         Winner := Team1;
                    SINON
                         APPEL Match_P2( Team1 , Team2 , Team2 , Tab , MOD(Nombre2,10) );
                         Winner := Team2;
                    FINSI;
                 SINON
                      SI Choice = 4
                         Nombre1 := STRUCT ( ELEMENT(Tab[E1]) , 4 ) + STRUCT ( ELEMENT(Tab[E1]) , 5 );
                         Nombre2 := STRUCT ( ELEMENT(Tab[E2]) , 4 ) + STRUCT ( ELEMENT(Tab[E2]) , 5 );
                         TANTQUE Nombre1 = Nombre2
                            Nombre1 := Nombre1 + ALEANOMBRE (5);
                            Nombre1 := Nombre1 + ALEANOMBRE (5);
                         FINTANTQUE;
                         SI Nombre1 > Nombre2
                              APPEL Match_P2( Team1 , Team2 , Team1 , Tab , MOD(Nombre1,10) );
                              Winner := Team1;
                         SINON
                              APPEL Match_P2( Team1 , Team2 , Team2 , Tab , MOD(Nombre2,10) );
                              Winner := Team2;
                         FINSI;
                      SINON
                           SI Choice = 5
                              Nombre1 := STRUCT ( ELEMENT(Tab[E1]) , 4 ) + 200 - STRUCT ( ELEMENT(Tab[E1]) , 3 );
                              Nombre2 := STRUCT ( ELEMENT(Tab[E2]) , 4 ) + 200 - STRUCT ( ELEMENT(Tab[E2]) , 3 );
                              TANTQUE Nombre1 = Nombre2
                                      Nombre1 := Nombre1 + ALEANOMBRE (5);
                                      Nombre1 := Nombre1 + ALEANOMBRE (5);
                              FINTANTQUE;
                              SI Nombre1 > Nombre2
                                   APPEL Match_P2( Team1 , Team2 , Team1 , Tab , MOD(Nombre1,10) );
                                   Winner := Team1;
                              SINON
                                   APPEL Match_P2( Team1 , Team2 , Team2 , Tab , MOD(Nombre2,10) );
                                   Winner := Team2;
                              FINSI;
                           SINON
                                SI Choice = 6
                                   Nombre1 := STRUCT ( ELEMENT(Tab[E1]) , 4 ) + STRUCT ( ELEMENT(Tab[E1]) , 5 );
                                   Nombre1 := Nombre1 + 200 - STRUCT ( ELEMENT(Tab[E1]) , 3 );
                                   Nombre2 := STRUCT ( ELEMENT(Tab[E2]) , 4 ) + STRUCT ( ELEMENT(Tab[E2]) , 5 );
                                   Nombre2 := Nombre2 + 200 - STRUCT ( ELEMENT(Tab[E2]) , 3 );
                                   TANTQUE Nombre1 = Nombre2
                                           Nombre1 := Nombre1 + ALEANOMBRE (5);
                                           Nombre1 := Nombre1 + ALEANOMBRE (5);
                                   FINTANTQUE;
                                   SI Nombre1 > Nombre2
                                        APPEL Match_P2( Team1 , Team2 , Team1 , Tab , MOD(Nombre1,10) );
                                        Winner := Team1;
                                   SINON
                                        APPEL Match_P2( Team1 , Team2 , Team2 , Tab , MOD(Nombre2,10) );
                                        Winner := Team2;
                                   FINSI;
                                SINON
                                     SI Choice = 7
                                        SI Team1 > Team2
                                             APPEL Match_P2( Team1 , Team2 , Team1 , Tab , MOD(Team1,10) );
                                             Winner := Team1;
                                        SINON
                                             APPEL Match_P2( Team1 , Team2 , Team2 , Tab , MOD(Team2,10) );
                                             Winner := Team2;
                                        FINSI;
                                     FINSI
                                FINSI
                           FINSI
                      FINSI
                 FINSI
            FINSI
       FINSI
   FIN

   /*****************************************************************************************************************/

   ACTION Empilage_Arbre ( Arbre , P )
   SOIENT
         Arbre , Temp UN ARB DE ( ENTIER , ENTIER );
         P UN PILE DE ARB DE ( ENTIER , ENTIER );
         F UNE FILE DE ARB DE ( ENTIER , ENTIER );
   DEBUT
        CREERFILE(F);
        CREERPILE(P);
        ENFILER(F,Arbre);
        TANTQUE NON FILEVIDE(F)
                DEFILER(F,Temp);
                EMPILER(P,Temp);
                SI FG(Temp) <> NIL
                   ENFILER(F,FG(Temp));
                FINSI;
                SI FD(Temp) <> NIL
                   ENFILER(F,FD(Temp));
                FINSI;
        FINTANTQUE;
   FIN

   /*****************************************************************************************************************/

   ACTION REMPLISSAGE_8EME ( P , FIRST , SECOND )
   SOIENT
         P , PT UNE PILE DE ARB DE ( ENTIER , ENTIER );
         FIRST , SECOND UN VECTEUR (8) DE ENTIER;
         T UN ARB DE ( ENTIER , ENTIER );
         I , K UN ENTIER;
         BET UN ( ENTIER , ENTIER );
   DEBUT
        POUR I:=1,8
             DEPILER ( P , T );
             EMPILER ( PT , T );
        FINPOUR;
        K := 1;
        POUR I:=1,8
             DEPILER ( PT , T );
             AFF_STRUCT ( BET , 1 , ELEMENT ( FIRST[I] ) );
             AFF_STRUCT ( BET , 2 , ELEMENT ( SECOND[I+K] ) );
             AFF_INFO ( T , BET );
             K := K * (-1) ;
             EMPILER ( P , T );
        FINPOUR;
   FIN

   /*****************************************************************************************************************/

   ACTION Simuler_Phase2 ( PILE_PARCOURS , Table , Choice )
   SOIENT
         Temp UN ARB DE ( ENTIER , ENTIER );
         Table UN VECTEUR (32) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER );
         PILE_PARCOURS UN PILE DE ARB DE ( ENTIER , ENTIER );
         I , Choice , Winner UN ENTIER;
         Team1 , Team2 UN ENTIER;
         STR UN (ENTIER , ENTIER);
   DEBUT
        I := 0;
        TANTQUE I <14
                SI I = 0
                   ECRIRE ( '' );
                   ECRIRE (' Huitieme de finale : ');
                   ECRIRE ( '' );
                FINSI;
                SI I = 8
                   ECRIRE ( '' );
                   ECRIRE (' Quart de finale : ');
                   ECRIRE ( '' );
                FINSI;
                SI I = 12
                   ECRIRE ( '' );
                   ECRIRE (' Demi finale : ');
                   ECRIRE ( '' );
                FINSI;
                DEPILER ( PILE_PARCOURS , Temp );
                Team1 := STRUCT ( INFO(Temp) , 1 );
                Team2 := STRUCT ( INFO(Temp) , 2 );
                APPEL Simuler_match_P2 ( Team1 , Team2 , Winner , Table , Choice );
                ECRIRE ( ID_NAME(Table , Team1) , ' VS ' , ID_NAME(Table , Team2) );
                ECRIRE ( ID_NAME(Table , Winner) , ' Gagne ' );
                ECRIRE ( '' );
                AFF_STRUCT ( STR , 1 , Winner );
                DEPILER ( PILE_PARCOURS , Temp );
                Team1 := STRUCT ( INFO(Temp) , 1 );
                Team2 := STRUCT ( INFO(Temp) , 2 );
                APPEL Simuler_match_P2 ( Team1 , Team2 , Winner , Table , Choice );
                ECRIRE ( ID_NAME(Table , Team1) , ' VS ' , ID_NAME(Table , Team2) );
                ECRIRE ( ID_NAME(Table , Winner) , ' Gagne ' );
                ECRIRE ( '' );
                AFF_STRUCT ( STR , 2 , Winner );
                Temp := PERE ( Temp );
                AFF_INFO ( Temp , STR );
                I := I + 2 ;

        FINTANTQUE;
        ECRIRE ( '' );
        ECRIRE (' La finale : ');
        ECRIRE ( '' );
        DEPILER ( PILE_PARCOURS , Temp );
        Team1 := STRUCT ( INFO(Temp) , 1 );
        Team2 := STRUCT ( INFO(Temp) , 2 );
        APPEL Simuler_match_P2 ( Team1 , Team2 , Winner , Table , Choice );
        ECRIRE ( ID_NAME(Table , Team1) , ' VS ' , ID_NAME(Table , Team2) );
        ECRIRE ( ID_NAME(Table , Winner) , ' Gagne ' );
        ECRIRE ( '' );
        ECRIRE ( ID_NAME(Table , Winner) , ' GAGNE LA COUPE DU MONDE ' );
   FIN

   /*****************************************************************************************************************/

   ACTION ARBRE_PHASE2 ( Arbre )
   SOIENT
      Arbre UN ARB DE ( ENTIER , ENTIER );
   DEBUT
        CREERNOEUD ( Arbre );
        APPEL Creer_Arb_P2 ( Arbre , 0 );
   FIN

   /*****************************************************************************************************************/

   ACTION Creer_Arb_P2 ( Arbre , Limit )
   SOIENT
      Arbre UN ARB DE ( ENTIER , ENTIER );
      Limit UN ENTIER;
      D , G UN ARB DE ( ENTIER , ENTIER );
   DEBUT
        SI Limit <= 2
           CREERNOEUD (D);
           CREERNOEUD (G);
           AFF_FD (Arbre,D);
           AFF_FG (Arbre,G);
           AFF_PERE (D,Arbre);
           AFF_PERE (G,Arbre);
           APPEL Creer_Arb_P2 ( FD(Arbre) , Limit + 1 );
           APPEL Creer_Arb_P2 ( FG(Arbre) , Limit + 1 );
        FINSI;
   FIN

   /********************* FIN PHASE 2 *********************/
   /*****************************************************************************************************************/



   /***************************************************   PHASE 1 ***************************************************/
   /*****************************************************************************************************************/

   FONCTION Indice_chaine ( Tab , V ) : ENTIER
   SOIENT
       Tab UN VECTEUR ( 198 ) DE CHAINE ;
       V UNE CHAINE ;
       I UN ENTIER ;
       N UN ENTIER ;
       Found UN BOOLEEN ;

   DEBUT
       Found := FAUX ;
       I := 1 ;
       TANTQUE NON Found
           SI ( ELEMENT ( Tab [ I ] ) = V )
               Found := VRAI ;
               N := I ;

           FINSI ;
           I := I + 1 ;

       FINTANTQUE ;
       Indice_chaine := N ;

   FIN

   /*****************************************************************************************************************/

   FONCTION Indice_id ( Tab , V ) : ENTIER
   SOIENT
       Tab UN VECTEUR ( 32 ) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER ) ;
       V UNE ENTIER ;
       I UN ENTIER ;
       N UN ENTIER ;
       Found UN BOOLEEN ;

   DEBUT
       Found := FAUX ;
       I := 1 ;
       TANTQUE NON Found
           SI ( STRUCT ( ELEMENT ( Tab [ I ] ) , 1 ) = V )
               Found := VRAI ;
               N := I ;

           FINSI ;
           I := I + 1 ;

       FINTANTQUE ;
       Indice_id := N ;

   FIN

   /*****************************************************************************************************************/

   FONCTION ID_NAME ( TAB , ID ) : CHAINE
   SOIENT
          TAB UN VECTEUR (32) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER ) ;
          ID UN ENTIER ;
          I UN ENTIER ;
          TROUVE UN BOOLEEN ;

   DEBUT
      TROUVE:= FAUX ;
      I:= 1 ;

      TANTQUE (( I <33 ) ET (NON TROUVE) )
             SI ( ID = STRUCT ( ELEMENT (TAB[I] ), 1) )
                TROUVE := VRAI ;
             SINON
                  I:=I+1 ;
             FINSI
      FINTANTQUE ;

      SI TROUVE
         ID_NAME := STRUCT ( ELEMENT (TAB[I] ), 2) ;
      SINON
         ID_NAME := '' ;
      FINSI

   FIN

   /*****************************************************************************************************************/

   ACTION Fill_WC_22 (Tab)
   SOIENT
         Tab UN VECTEUR ( 32 ) DE ENTIER ;

   DEBUT
        AFF_ELEMENT ( Tab [ 1 ] , 1 ) ;
        AFF_ELEMENT ( Tab [ 2 ] , 2 ) ;
        AFF_ELEMENT ( Tab [ 3 ] , 3 ) ;
        AFF_ELEMENT ( Tab [ 4 ] , 4 ) ;
        AFF_ELEMENT ( Tab [ 5 ] , 5 ) ;
        AFF_ELEMENT ( Tab [ 6 ] , 7 ) ;
        AFF_ELEMENT ( Tab [ 7 ] , 8 ) ;
        AFF_ELEMENT ( Tab [ 8 ] , 9 ) ;
        AFF_ELEMENT ( Tab [ 9 ] , 10 ) ;
        AFF_ELEMENT ( Tab [ 10 ] , 11 ) ;
        AFF_ELEMENT ( Tab [ 11 ] , 12 ) ;
        AFF_ELEMENT ( Tab [ 12 ] , 13 ) ;
        AFF_ELEMENT ( Tab [ 13 ] , 14 ) ;
        AFF_ELEMENT ( Tab [ 14 ] , 15 ) ;
        AFF_ELEMENT ( Tab [ 15 ] , 16 ) ;
        AFF_ELEMENT ( Tab [ 16 ] , 18 ) ;
        AFF_ELEMENT ( Tab [ 17 ] , 20 ) ;
        AFF_ELEMENT ( Tab [ 18 ] , 21 ) ;
        AFF_ELEMENT ( Tab [ 19 ] , 22 ) ;
        AFF_ELEMENT ( Tab [ 20 ] , 23 ) ;
        AFF_ELEMENT ( Tab [ 21 ] , 24 ) ;
        AFF_ELEMENT ( Tab [ 22 ] , 25 ) ;
        AFF_ELEMENT ( Tab [ 23 ] , 26 ) ;
        AFF_ELEMENT ( Tab [ 24 ] , 29 ) ;
        AFF_ELEMENT ( Tab [ 25 ] , 31 ) ;
        AFF_ELEMENT ( Tab [ 26 ] , 35 ) ;
        AFF_ELEMENT ( Tab [ 27 ] , 38 ) ;
        AFF_ELEMENT ( Tab [ 28 ] , 44 ) ;
        AFF_ELEMENT ( Tab [ 29 ] , 46 ) ;
        AFF_ELEMENT ( Tab [ 30 ] , 49 ) ;
        AFF_ELEMENT ( Tab [ 31 ] , 51 ) ;
        AFF_ELEMENT ( Tab [ 32 ] , 60 ) ;

   FIN

   /*****************************************************************************************************************/

   ACTION Fill_participants ( Equip , Tableau_fifa , Tableau_fav , Tableau_equip )
   SOIENT
       Equip UN VECTEUR ( 32 ) DE ENTIER ;
       Tableau_fav UN VECTEUR ( 198 ) DE CHAINE ;
       Tableau_fifa UN VECTEUR ( 198 ) DE CHAINE ;
       Tableau_equip UN VECTEUR ( 32 ) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER ) ;
       I UN ENTIER ;
       Equipe UN ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER ) ;
       Theone UNE CHAINE ;
       Temp UN ENTIER ;

   DEBUT
       POUR I := 1 , 32
           Temp := Indice_chaine ( Tableau_fav , ELEMENT ( Tableau_fifa [ ELEMENT ( Equip [ I ] ) ] ) ) ;
           AFF_STRUCT ( Equipe , 1 , ELEMENT ( Equip [ I ] ) ) ;
           AFF_STRUCT ( Equipe , 2 , ELEMENT ( Tableau_fifa [ ELEMENT ( Equip [ I ] ) ] ) ) ;
           AFF_STRUCT ( Equipe , 3 , Temp ) ;
           AFF_STRUCT ( Equipe , 4 , 0 ) ;
           AFF_STRUCT ( Equipe , 5 , 0 ) ;
           AFF_ELEMENT ( Tableau_equip [ I ] , Equipe ) ;

       FPOUR
   FIN

   /*****************************************************************************************************************/

   ACTION Create_groups ( T_EQUIPE , T_GROUPE )
   SOIENT
     T_EQUIPE UN VECTEUR (32) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER ) ;
     T_GROUPE UN VECTEUR (8) DE (ENTIER , ENTIER , ENTIER , ENTIER );
     I , K , L DES ENTIERS ;
     VAL UN (ENTIER , ENTIER , ENTIER , ENTIER ) ;
   DEBUT
       K := 0 ;
       L := 0;
       I:= 1 ;
       TANTQUE I<9 :

        L := STRUCT(ELEMENT(T_EQUIPE[I]),1 ) ;
        AFF_STRUCT( VAL , 1 , L ) ;

        L := STRUCT( ELEMENT(T_EQUIPE[8+I]),1) ;
        AFF_STRUCT( VAL , 2 , L ) ;

        L := STRUCT( ELEMENT(T_EQUIPE[16+I]),1) ;
        AFF_STRUCT( VAL , 3 , L ) ;

        L := STRUCT( ELEMENT(T_EQUIPE[24+I]),1) ;
        AFF_STRUCT( VAL , 4 , L ) ;

        AFF_ELEMENT ( T_GROUPE[I], VAL ) ;

        I:= I+1 ;

       FINTANTQUE ;
   FIN

   /*****************************************************************************************************************/

   ACTION TAB_LISTE_MATCHES (TAB_GROUPE , TAB_MATCH )
   SOIENT
        TAB_GROUPE UN VECTEUR (8) DE (ENTIER , ENTIER , ENTIER , ENTIER );
        TAB_MATCH UN VECTEUR (8) DE LISTE DE (ENTIER , ENTIER);
        I , J DES ENTIER ;
        P , Q UN POINTEUR VERS UNE LISTE DE ( ENTIER , ENTIER );
        L UNE LISTE DE ( ENTIER , ENTIER ) ;
        MATCH UN (ENTIER , ENTIER ) ;
   DEBUT
    POUR I:=1 , 8
         ALLOUER ( P ) ;
         AFF_ELEMENT ( TAB_MATCH[I], P ) ;
         AFF_STRUCT ( MATCH, 1, STRUCT ( ELEMENT (TAB_GROUPE[I]), 1) );
         AFF_STRUCT ( MATCH, 2, STRUCT ( ELEMENT (TAB_GROUPE[I]), 2) );
         AFF_VAL( P, MATCH ) ;

         ALLOUER ( Q ) ;
         AFF_ADR ( P, Q ) ;
         AFF_STRUCT ( MATCH, 1, STRUCT ( ELEMENT (TAB_GROUPE[I]), 3) );
         AFF_STRUCT ( MATCH, 2, STRUCT ( ELEMENT (TAB_GROUPE[I]), 4) );
         AFF_VAL( Q, MATCH ) ;

         ALLOUER ( P ) ;
         AFF_ADR ( Q, P ) ;
         AFF_STRUCT ( MATCH, 1, STRUCT ( ELEMENT (TAB_GROUPE[I]), 1) );
         AFF_STRUCT ( MATCH, 2, STRUCT ( ELEMENT (TAB_GROUPE[I]), 3) );
         AFF_VAL( P, MATCH ) ;

         ALLOUER ( Q ) ;
         AFF_ADR ( P, Q ) ;
         AFF_STRUCT ( MATCH, 1, STRUCT ( ELEMENT (TAB_GROUPE[I]), 2) );
         AFF_STRUCT ( MATCH, 2, STRUCT ( ELEMENT (TAB_GROUPE[I]), 4) );
         AFF_VAL( Q, MATCH ) ;

         ALLOUER ( P ) ;
         AFF_ADR ( Q, P ) ;
         AFF_STRUCT ( MATCH, 1, STRUCT ( ELEMENT (TAB_GROUPE[I]), 1) );
         AFF_STRUCT ( MATCH, 2, STRUCT ( ELEMENT (TAB_GROUPE[I]), 4) );
         AFF_VAL( P, MATCH ) ;

         ALLOUER ( Q ) ;
         AFF_ADR ( P, Q ) ;
         AFF_STRUCT ( MATCH, 1, STRUCT ( ELEMENT (TAB_GROUPE[I]), 2) );
         AFF_STRUCT ( MATCH, 2, STRUCT ( ELEMENT (TAB_GROUPE[I]), 3) );
         AFF_VAL( Q, MATCH ) ;
         AFF_ADR ( Q, NIL ) ;
   FINPOUR;
   FIN

   /*****************************************************************************************************************/

   ACTION Match_nul_p1 ( Team1 , Team2 , Tab , Won )
   SOIENT
       Team2 UN ENTIER ;
       Team1 UN ENTIER ;
       Tab UN VECTEUR ( 32 ) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER ) ;
       Won UN ENTIER ;
       E1 , E2 UN ENTIER ;

   DEBUT
       E1 := Indice_id ( Tab , Team1 ) ;
       E2 := Indice_id ( Tab , Team2 ) ;
       Won := 0 ;
       AFF_STRUCT ( ELEMENT ( Tab [ E1 ] ) , 4 , STRUCT ( ELEMENT ( Tab [ E1 ] ) , 4 ) + 1 ) ;
       AFF_STRUCT ( ELEMENT ( Tab [ E2 ] ) , 4 , STRUCT ( ELEMENT ( Tab [ E2 ] ) , 4 ) + 1 ) ;

   FIN

   /*****************************************************************************************************************/

   ACTION Match_won_p1 ( Team , Tab , Won )
   SOIENT
       E UN ENTIER ;
       Team , Won UN ENTIER ;
       Tab UN VECTEUR ( 32 ) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER ) ;

   DEBUT
       E := Indice_id ( Tab , Team ) ;
       Won := Team ;
       AFF_STRUCT ( ELEMENT ( Tab [ E ] ) , 4 , STRUCT ( ELEMENT ( Tab [ E ] ) , 4 ) + 3 ) ;

   FIN

   /*****************************************************************************************************************/

   ACTION Simuler_match_p1 ( Team1 , Team2 , Tab , Won , Choice )
   SOIENT
       Team1 , Team2 UN ENTIER ;
       Tab UN VECTEUR ( 32 ) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER ) ;
       Won UN ENTIER ;
       Choice , Nombre1 , Nombre2 , E1 , E2 UN ENTIER ;

   DEBUT
       E1 := Indice_id ( Tab , Team1 ) ;
       E2 := Indice_id ( Tab , Team2 ) ;
       SI Choice = 1
           Nombre1 := ALEANOMBRE ( 5 ) ;
           Nombre2 := ALEANOMBRE ( 5 ) ;
           SI Nombre1 = Nombre2
               APPEL Match_nul_p1 ( Team1 , Team2 , Tab , Won) ;

           SINON
               SI Nombre1 > Nombre2
                   APPEL Match_won_p1 ( Team1 , Tab , Won ) ;

               SINON
                   APPEL Match_won_p1 ( Team2 , Tab , Won ) ;

               FINSI
           FINSI
       SINON
           SI Choice = 2
               Nombre1 := STRUCT ( ELEMENT ( Tab [ E1 ] ) , 3 ) ;
               Nombre2 := STRUCT ( ELEMENT ( Tab [ E2 ] ) , 3 ) ;
               SI Nombre1 = Nombre2
                   APPEL Match_nul_p1 ( Team1 , Team2 , Tab , Won) ;
               SINON
                   SI Nombre1 < Nombre2
                       APPEL Match_won_p1 ( Team1 , Tab , Won ) ;

                   SINON
                       APPEL Match_won_p1 ( Team2 , Tab , Won ) ;

                   FINSI
               FINSI
           SINON
               SI Choice = 3
                  Nombre1 := 200 - STRUCT ( ELEMENT ( Tab [ E1 ] ) , 3 ) ;
                  Nombre2 := 200 - STRUCT ( ELEMENT ( Tab [ E2 ] ) , 3 ) ;

                   Nombre1 := ALEANOMBRE ( 5 ) + Nombre1 ;
                   Nombre2 := ALEANOMBRE ( 5 ) + Nombre2 ;
                   Nombre1 := MOD ( Nombre1 , 5 ) ;
                   Nombre2 := MOD ( Nombre2 , 5 ) ;
                   SI Nombre1 = Nombre2
                       APPEL Match_nul_p1 ( Team1 , Team2 , Tab , Won ) ;

                   SINON
                       SI Nombre1 > Nombre2
                           APPEL Match_won_p1 ( Team1 , Tab , Won ) ;

                       SINON
                           APPEL Match_won_p1 ( Team2 , Tab , Won ) ;

                       FINSI
                   FINSI
               SINON
                   SI Choice = 4
                       SI Team1 = Team2
                           APPEL Match_nul_p1 ( Team1 , Team2 , Tab , Won ) ;

                       SINON
                           SI Team1 < Team2
                              Nombre1 := mod (Team1,5);
                               APPEL Match_won_p1 ( Team1 , Tab , Won ) ;

                           SINON
                                Nombre2 := mod(Team2,5);
                               APPEL Match_won_p1 ( Team2 , Tab , Won ) ;

                           FINSI
                       FINSI
                   FINSI
               FINSI
           FINSI
       FINSI
   FIN

   /*****************************************************************************************************************/

   ACTION Simuler_Phase1 ( TAB_Equipes , TAB_MATCHES , Choice , Tab_1st , Tab_2nd )
   SOIENT
         TAB_MATCHES UN VECTEUR (8) DE LISTE DE (ENTIER , ENTIER);
         TAB_Equipes UN VECTEUR ( 32 ) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER );
         I , K DES ENTIERS;
         Team1 , Team2 DES ENTIERS;
         P UN POINTEUR VERS UNE LISTE DE ( ENTIER , ENTIER );
         Won , Choice UN ENTIER;
         TAB_1st , TAB_2nd UN VECTEUR (8) DE ENTIER ;
   DEBUT
        POUR I:=1,8
             ECRIRE ( ' Le  ' , I , ' eme Groupe ' );
             ECRIRE ('');
             ECRIRE ('');
             P := ELEMENT ( TAB_MATCHES[I] );

             TANTQUE P<>NIL
                  Team1 := STRUCT ( VALEUR ( P ) , 1 );
                  Team2 := STRUCT ( VALEUR ( P ) , 2 );
                  APPEL Simuler_match_p1 ( Team1 , Team2 , TAB_Equipes , Won , Choice );

                  SI Won = 0
                     ECRIRE( ID_NAME( TAB_Equipes , Team1) , ' VS ' , ID_NAME( TAB_Equipes , Team2 ) );
                     ECRIRE( ' Match NUL' );
                     ECRIRE('');
                  SINON
                     ECRIRE( ID_NAME( TAB_Equipes , Team1) , ' VS ' , ID_NAME( TAB_Equipes , Team2 ) );
                     ECRIRE( ID_NAME( TAB_Equipes , Won ) , 'gagne' );
                     ECRIRE('');
                  FINSI;
                  P := SUIVANT (P);
             FINTANTQUE;
             ECRIRE('');
             ECRIRE('');
             ECRIRE('');
        FINPOUR

   FIN

   /*****************************************************************************************************************/

   ACTION Qualifies ( FIRST , SECOND , TABLE )
   SOIENT
         TABLE UN VECTEUR (32) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER );
         FIRST , SECOND UN VECTEUR (8) DE ENTIER ;
         I UN ENTIER;

   DEBUT
        POUR I:=1,8
             ECRIRE('LE ',I,' eme Groupe');
             ECRIRE('');
             ECRIRE( '1 - ' , ID_NAME( TABLE ,ELEMENT(FIRST[I])) );
             ECRIRE( '2 - ' , ID_name( TABLE ,ELEMENT(SECOND[I])) );
             ECRIRE('');
             ECRIRE('');
        FINPOUR;
   FIN

   /*****************************************************************************************************************/

   ACTION TRI_PT_W ( PT , W )
   SOIENT
         J , K , TEMP DES ENTIERS;
         PT , W UN VECTEUR (4) DE ENTIER ;
   DEBUT
        J := 3;
              TANTQUE J>0
                      POUR K:=1,J
                           SI ELEMENT( PT[K] ) < ELEMENT ( PT[K+1] )
                           TEMP := ELEMENT( PT[K] ) ;
                           AFF_ELEMENT ( PT[K] , ELEMENT ( PT[K+1] ) );
                           AFF_ELEMENT ( PT[K+1] , TEMP );
                           TEMP := ELEMENT( W[K] ) ;
                           AFF_ELEMENT ( W[K] , ELEMENT ( W[K+1] ) );
                           AFF_ELEMENT ( W[K+1] , TEMP );
                      FINSI;
              FINPOUR;
              J := J - 1 ;
        FINTANTQUE;

   FIN

   /*****************************************************************************************************************/

   ACTION Group_Winners ( Tab_groupes , Tab_Participants , FIRST , SECOND )
   SOIENT
         Tab_groupes UN VECTEUR ( 8 ) DE ( ENTIER , ENTIER , ENTIER , ENTIER );
         Tab_Participants UN VECTEUR ( 32 ) DE ( ENTIER , CHAINE , ENTIER , ENTIER , ENTIER );
         INDICE , I , J , TEMP UN ENTIER;
         PT , W DES VECTEURS (4) DE ENTIER ;
         FIRST , SECOND UN VECTEUR ( 8 ) DE ENTIER ;
   DEBUT
         POUR I:=1,8
              INDICE := Indice_ID ( Tab_Participants , STRUCT ( ELEMENT ( Tab_Groupes [I] ) , 1 ) );
              AFF_ELEMENT ( W[1] , STRUCT ( ELEMENT ( Tab_Groupes [I] ) , 1 ) );
              AFF_ELEMENT ( PT[1] , STRUCT (  ELEMENT ( Tab_Participants [ INDICE ] ) , 4 ) );
              INDICE := Indice_ID ( Tab_Participants , STRUCT ( ELEMENT ( Tab_Groupes [I] ) , 2 ) );
              AFF_ELEMENT ( W[2] , STRUCT ( ELEMENT ( Tab_Groupes [I] ) , 2 ) );
              AFF_ELEMENT ( PT[2] , STRUCT (  ELEMENT ( Tab_Participants [ INDICE ] ) , 4 ) );
              INDICE := Indice_ID ( Tab_Participants , STRUCT ( ELEMENT ( Tab_Groupes [I] ) , 3 ) );
              AFF_ELEMENT ( W[3] , STRUCT ( ELEMENT ( Tab_Groupes [I] ) , 3 ) );
              AFF_ELEMENT ( PT[3] , STRUCT (  ELEMENT ( Tab_Participants [ INDICE ] ) , 4 ) );
              INDICE := Indice_ID ( Tab_Participants , STRUCT ( ELEMENT ( Tab_Groupes [I] ) , 4 ) );
              AFF_ELEMENT ( W[4] , STRUCT ( ELEMENT ( Tab_Groupes [I] ) , 4 ) );
              AFF_ELEMENT ( PT[4] , STRUCT (  ELEMENT ( Tab_Participants [ INDICE ] ) , 4 ) );
              APPEL TRI_PT_W ( PT , W );
              AFF_ELEMENT ( FIRST[I] , ELEMENT ( W[1] ) );
              AFF_ELEMENT ( SECOND[I] , ELEMENT ( W[2] ) );
              /* LE CONCEPT DU TIRAGE AU SORT N'EST PAS FAIT AVEC LA FONCTION ALEA */
              /* L'EQUIPE QUI PASSE EST GENEREE DU TABLEAU TRIEE DES EQUIPES : LE TRI MODIFIE SANS AUCUNE CDT */
         FINPOUR;
   FIN

   /*****************************************************************************************************************/

   ACTION Aff_eq_fifa1 ( Tab )
   SOIENT
       Tab UN VECTEUR ( 198 ) DE CHAINE ;

   DEBUT
       AFF_ELEMENT ( Tab [ 1 ] , 'Bresil' ) ;
       AFF_ELEMENT ( Tab [ 2 ] , 'Belgique' ) ;
       AFF_ELEMENT ( Tab [ 3 ] , 'France' ) ;
       AFF_ELEMENT ( Tab [ 4 ] , 'Argentine' ) ;
       AFF_ELEMENT ( Tab [ 5 ] , 'Angleterre' ) ;
       AFF_ELEMENT ( Tab [ 6 ] , 'Italie' ) ;
       AFF_ELEMENT ( Tab [ 7 ] , 'Espagne' ) ;
       AFF_ELEMENT ( Tab [ 8 ] , 'Portugal' ) ;
       AFF_ELEMENT ( Tab [ 9 ] , 'Mexique' ) ;
       AFF_ELEMENT ( Tab [ 10 ] , 'Pays Bas' ) ;
       AFF_ELEMENT ( Tab [ 11 ] , 'Denmark' ) ;
       AFF_ELEMENT ( Tab [ 12 ] , 'Allemagne' ) ;
       AFF_ELEMENT ( Tab [ 13 ] , 'Uruguay' ) ;
       AFF_ELEMENT ( Tab [ 14 ] , 'Suisse' ) ;
       AFF_ELEMENT ( Tab [ 15 ] , 'Etats Unis' ) ;
       AFF_ELEMENT ( Tab [ 16 ] , 'Croatie' ) ;
       AFF_ELEMENT ( Tab [ 17 ] , 'Colombie' ) ;
       AFF_ELEMENT ( Tab [ 18 ] , 'Pays de Galles' ) ;
       AFF_ELEMENT ( Tab [ 19 ] , 'Suède' ) ;
       AFF_ELEMENT ( Tab [ 20 ] , 'Sénégal' ) ;
       AFF_ELEMENT ( Tab [ 21 ] , 'Iran' ) ;
       AFF_ELEMENT ( Tab [ 22 ] , 'Pérou' ) ;
       AFF_ELEMENT ( Tab [ 23 ] , 'Japon' ) ;
       AFF_ELEMENT ( Tab [ 24 ] , 'Maroc' ) ;
       AFF_ELEMENT ( Tab [ 25 ] , 'Serbie' ) ;
       AFF_ELEMENT ( Tab [ 26 ] , 'Pologne' ) ;
       AFF_ELEMENT ( Tab [ 27 ] , 'Ukraine' ) ;
       AFF_ELEMENT ( Tab [ 28 ] , 'Chili' ) ;
       AFF_ELEMENT ( Tab [ 29 ] , 'Corée du Sud' ) ;
       AFF_ELEMENT ( Tab [ 30 ] , 'Nigeria' ) ;
       AFF_ELEMENT ( Tab [ 31 ] , 'Costa Rica' ) ;
       AFF_ELEMENT ( Tab [ 32 ] , 'Egypte' ) ;
       AFF_ELEMENT ( Tab [ 33 ] , 'Tchèque' ) ;
       AFF_ELEMENT ( Tab [ 34 ] , 'Autriche' ) ;
       AFF_ELEMENT ( Tab [ 35 ] , 'Tunisie' ) ;
       AFF_ELEMENT ( Tab [ 36 ] , 'Russie' ) ;
       AFF_ELEMENT ( Tab [ 37 ] , 'Cameroun' ) ;
       AFF_ELEMENT ( Tab [ 38 ] , 'Canada' ) ;
       AFF_ELEMENT ( Tab [ 39 ] , 'Ecosse' ) ;
       AFF_ELEMENT ( Tab [ 40 ] , 'Hongrie' ) ;
       AFF_ELEMENT ( Tab [ 41 ] , 'Norvège' ) ;
       AFF_ELEMENT ( Tab [ 42 ] , 'Australie' ) ;
       AFF_ELEMENT ( Tab [ 43 ] , 'Turquie' ) ;
       AFF_ELEMENT ( Tab [ 44 ] , 'Algérie' ) ;
       AFF_ELEMENT ( Tab [ 45 ] , 'Slovaquie' ) ;
       AFF_ELEMENT ( Tab [ 46 ] , 'Equateur' ) ;
       AFF_ELEMENT ( Tab [ 47 ] , 'Irlande' ) ;

   FIN

   /*****************************************************************************************************************/

   ACTION Aff_eq_fifa2 ( Tab )
   SOIENT
       Tab UN VECTEUR ( 198 ) DE CHAINE ;

   DEBUT
       AFF_ELEMENT ( Tab [ 49 ] , 'Arabie Saoudite' ) ;
       AFF_ELEMENT ( Tab [ 50 ] , 'Paraguay' ) ;
       AFF_ELEMENT ( Tab [ 51 ] , 'Qatar' ) ;
       AFF_ELEMENT ( Tab [ 52 ] , 'Mali' ) ;
       AFF_ELEMENT ( Tab [ 53 ] , 'Côte dIvoire' ) ;
       AFF_ELEMENT ( Tab [ 54 ] , 'Irlande du Nord' ) ;
       AFF_ELEMENT ( Tab [ 55 ] , 'Grèce' ) ;
       AFF_ELEMENT ( Tab [ 56 ] , 'Burkina Faso' ) ;
       AFF_ELEMENT ( Tab [ 57 ] , 'Finlande' ) ;
       AFF_ELEMENT ( Tab [ 58 ] , 'Venezuela' ) ;
       AFF_ELEMENT ( Tab [ 59 ] , 'BosnieHerzégovine' ) ;
       AFF_ELEMENT ( Tab [ 60 ] , 'Ghana' ) ;
       AFF_ELEMENT ( Tab [ 61 ] , 'Panama' ) ;
       AFF_ELEMENT ( Tab [ 62 ] , 'Macédoine du Nord' ) ;
       AFF_ELEMENT ( Tab [ 63 ] , 'Islande' ) ;
       AFF_ELEMENT ( Tab [ 64 ] , 'Jamaïque' ) ;
       AFF_ELEMENT ( Tab [ 65 ] , 'Slovénie' ) ;
       AFF_ELEMENT ( Tab [ 66 ] , 'Albanie' ) ;
       AFF_ELEMENT ( Tab [ 67 ] , 'RD Congo' ) ;
       AFF_ELEMENT ( Tab [ 68 ] , 'Emirats Arabes Unis' ) ;
       AFF_ELEMENT ( Tab [ 69 ] , 'Afrique du Sud' ) ;
       AFF_ELEMENT ( Tab [ 70 ] , 'Montenegro' ) ;
       AFF_ELEMENT ( Tab [ 48 ] , 'Roumanie' ) ;
       AFF_ELEMENT ( Tab [ 71 ] , 'Cap vert' ) ;
       AFF_ELEMENT ( Tab [ 72 ] , 'Iraq' ) ;
       AFF_ELEMENT ( Tab [ 73 ] , 'Bulgarie' ) ;
       AFF_ELEMENT ( Tab [ 74 ] , 'Salvador' ) ;
       AFF_ELEMENT ( Tab [ 75 ] , 'Oman' ) ;
       AFF_ELEMENT ( Tab [ 76 ] , 'Chine' ) ;
       AFF_ELEMENT ( Tab [ 77 ] , 'Bolivie' ) ;
       AFF_ELEMENT ( Tab [ 78 ] , 'Curacao' ) ;
       AFF_ELEMENT ( Tab [ 79 ] , 'Guinée' ) ;
       AFF_ELEMENT ( Tab [ 80 ] , 'Gabon' ) ;
       AFF_ELEMENT ( Tab [ 81 ] , 'Honduras' ) ;
       AFF_ELEMENT ( Tab [ 82 ] , 'Ouzbékistan' ) ;
       AFF_ELEMENT ( Tab [ 83 ] , 'Bénin' ) ;
       AFF_ELEMENT ( Tab [ 84 ] , 'Géorgie' ) ;
       AFF_ELEMENT ( Tab [ 85 ] , 'Ouganda' ) ;
       AFF_ELEMENT ( Tab [ 86 ] , 'Zambie' ) ;
       AFF_ELEMENT ( Tab [ 87 ] , 'Syrie' ) ;
       AFF_ELEMENT ( Tab [ 88 ] , 'Bahrein' ) ;
       AFF_ELEMENT ( Tab [ 89 ] , 'Haïti' ) ;
       AFF_ELEMENT ( Tab [ 90 ] , 'Jordanie' ) ;
       AFF_ELEMENT ( Tab [ 91 ] , 'Arménie' ) ;
       AFF_ELEMENT ( Tab [ 92 ] , 'Biélorussie' ) ;
       AFF_ELEMENT ( Tab [ 93 ] , 'Luxembourg' ) ;

   FIN

   /*****************************************************************************************************************/

   ACTION Aff_eq_fifa3 ( Tab )
   SOIENT
       Tab UN VECTEUR ( 198 ) DE CHAINE ;

   DEBUT
       AFF_ELEMENT ( Tab [ 94 ] , 'Kirghizistan' ) ;
       AFF_ELEMENT ( Tab [ 95 ] , 'Vietnam' ) ;
       AFF_ELEMENT ( Tab [ 96 ] , 'Congo' ) ;
       AFF_ELEMENT ( Tab [ 97 ] , 'Guinée Equatoriale' ) ;
       AFF_ELEMENT ( Tab [ 98 ] , 'Palestine' ) ;
       AFF_ELEMENT ( Tab [ 99 ] , 'NouvelleZélande' ) ;
       AFF_ELEMENT ( Tab [ 100 ] , 'Madagascar' ) ;
       AFF_ELEMENT ( Tab [ 101 ] , 'TrinitéetTobago' ) ;
       AFF_ELEMENT ( Tab [ 102 ] , 'Kenya' ) ;
       AFF_ELEMENT ( Tab [ 103 ] , 'Chypre' ) ;
       AFF_ELEMENT ( Tab [ 104 ] , 'Inde' ) ;
       AFF_ELEMENT ( Tab [ 105 ] , 'Sierra Leone' ) ;
       AFF_ELEMENT ( Tab [ 106 ] , 'Corée du Nord' ) ;
       AFF_ELEMENT ( Tab [ 107 ] , 'Estonie' ) ;
       AFF_ELEMENT ( Tab [ 108 ] , 'Thaïlande' ) ;
       AFF_ELEMENT ( Tab [ 109 ] , 'Namibie' ) ;
       AFF_ELEMENT ( Tab [ 110 ] , 'Mauritanie' ) ;
       AFF_ELEMENT ( Tab [ 111 ] , 'Tadjikistan' ) ;
       AFF_ELEMENT ( Tab [ 112 ] , 'Guinée Bissau' ) ;
       AFF_ELEMENT ( Tab [ 113 ] , 'Niger' ) ;
       AFF_ELEMENT ( Tab [ 114 ] , 'Libye' ) ;
       AFF_ELEMENT ( Tab [ 115 ] , 'Guatemala' ) ;
       AFF_ELEMENT ( Tab [ 116 ] , 'Mozambique' ) ;
       AFF_ELEMENT ( Tab [ 117 ] , 'Malawi' ) ;
       AFF_ELEMENT ( Tab [ 118 ] , 'Togo' ) ;
       AFF_ELEMENT ( Tab [ 119 ] , 'Zimbabwe' ) ;
       AFF_ELEMENT ( Tab [ 120 ] , 'Gambie' ) ;
       AFF_ELEMENT ( Tab [ 121 ] , 'Kazakhstan' ) ;
       AFF_ELEMENT ( Tab [ 122 ] , 'Angola' ) ;
       AFF_ELEMENT ( Tab [ 123 ] , 'Antigua' ) ;
       AFF_ELEMENT ( Tab [ 124 ] , 'Comores' ) ;
       AFF_ELEMENT ( Tab [ 125 ] , 'Azerbaïdjan' ) ;
       AFF_ELEMENT ( Tab [ 126 ] , 'Tanzanie' ) ;
       AFF_ELEMENT ( Tab [ 127 ] , 'Rép. Centrafricaine' ) ;
       AFF_ELEMENT ( Tab [ 128 ] , 'Soudan' ) ;
       AFF_ELEMENT ( Tab [ 129 ] , 'Philippines' ) ;
       AFF_ELEMENT ( Tab [ 130 ] , 'Turkménistan' ) ;
       AFF_ELEMENT ( Tab [ 131 ] , 'Lettonie' ) ;
       AFF_ELEMENT ( Tab [ 132 ] , 'Rwanda' ) ;
       AFF_ELEMENT ( Tab [ 133 ] , 'Lituanie' ) ;
       AFF_ELEMENT ( Tab [ 134 ] , 'Burundi' ) ;
       AFF_ELEMENT ( Tab [ 135 ] , 'Ethiopie' ) ;
       AFF_ELEMENT ( Tab [ 136 ] , 'Surinam' ) ;
       AFF_ELEMENT ( Tab [ 137 ] , 'SaintKitts et Nevis' ) ;
       AFF_ELEMENT ( Tab [ 138 ] , 'Swaziland' ) ;
       AFF_ELEMENT ( Tab [ 139 ] , 'Lesotho' ) ;
       AFF_ELEMENT ( Tab [ 140 ] , 'Koweit' ) ;

   FIN

   /*****************************************************************************************************************/

   ACTION Aff_eq_fifa4 ( Tab )
   SOIENT
       Tab UN VECTEUR ( 198 ) DE CHAINE ;

   DEBUT
       AFF_ELEMENT ( Tab [ 141 ] , 'HongKong' ) ;
       AFF_ELEMENT ( Tab [ 142 ] , 'Botswana' ) ;
       AFF_ELEMENT ( Tab [ 143 ] , 'Liberia' ) ;
       AFF_ELEMENT ( Tab [ 144 ] , 'Afghanistan' ) ;
       AFF_ELEMENT ( Tab [ 145 ] , 'Yémen' ) ;
       AFF_ELEMENT ( Tab [ 146 ] , 'Myanmar' ) ;
       AFF_ELEMENT ( Tab [ 147 ] , 'Andorre' ) ;
       AFF_ELEMENT ( Tab [ 148 ] , 'Malaisie' ) ;
       AFF_ELEMENT ( Tab [ 149 ] , 'République Dominicaine' ) ;
       AFF_ELEMENT ( Tab [ 150 ] , 'Maldives' ) ;
       AFF_ELEMENT ( Tab [ 151 ] , 'Taïwan' ) ;
       AFF_ELEMENT ( Tab [ 152 ] , 'Indonésie' ) ;
       AFF_ELEMENT ( Tab [ 153 ] , 'NouvelleCalédonie' ) ;
       AFF_ELEMENT ( Tab [ 154 ] , 'Soudan du sud' ) ;
       AFF_ELEMENT ( Tab [ 155 ] , 'PapouasieNouvelle Guinée' ) ;
       AFF_ELEMENT ( Tab [ 156 ] , 'Barbade' ) ;
       AFF_ELEMENT ( Tab [ 157 ] , 'Tahiti' ) ;
       AFF_ELEMENT ( Tab [ 158 ] , 'Fidji' ) ;
       AFF_ELEMENT ( Tab [ 159 ] , 'Vanuatu' ) ;
       AFF_ELEMENT ( Tab [ 160 ] , 'Bermudes' ) ;
       AFF_ELEMENT ( Tab [ 161 ] , 'Népal' ) ;
       AFF_ELEMENT ( Tab [ 162 ] , 'Malte' ) ;
       AFF_ELEMENT ( Tab [ 163 ] , 'Grenade' ) ;
       AFF_ELEMENT ( Tab [ 164 ] , 'Cambodge' ) ;
       AFF_ELEMENT ( Tab [ 165 ] , 'Porto Rico' ) ;
       AFF_ELEMENT ( Tab [ 166 ] , 'Belize' ) ;
       AFF_ELEMENT ( Tab [ 167 ] , 'Guyana' ) ;
       AFF_ELEMENT ( Tab [ 168 ] , 'Saint Vincent' ) ;
       AFF_ELEMENT ( Tab [ 169 ] , 'Sainte Lucie' ) ;
       AFF_ELEMENT ( Tab [ 170 ] , 'Cuba' ) ;
       AFF_ELEMENT ( Tab [ 171 ] , 'Montserrat' ) ;
       AFF_ELEMENT ( Tab [ 172 ] , 'Moldavie' ) ;
       AFF_ELEMENT ( Tab [ 173 ] , 'Tchad' ) ;
       AFF_ELEMENT ( Tab [ 174 ] , 'Macao' ) ;
       AFF_ELEMENT ( Tab [ 175 ] , 'Sao Tomé et Principe' ) ;
       AFF_ELEMENT ( Tab [ 176 ] , 'Dominique' ) ;
       AFF_ELEMENT ( Tab [ 177 ] , 'Laos' ) ;
       AFF_ELEMENT ( Tab [ 178 ] , 'Mongolie' ) ;
       AFF_ELEMENT ( Tab [ 179 ] , 'Bhoutan' ) ;
       AFF_ELEMENT ( Tab [ 180 ] , 'Bangladesh' ) ;
       AFF_ELEMENT ( Tab [ 181 ] , 'Samoa Américaines' ) ;
       AFF_ELEMENT ( Tab [ 182 ] , 'Bruneï' ) ;
       AFF_ELEMENT ( Tab [ 183 ] , 'Liechtenstein' ) ;
       AFF_ELEMENT ( Tab [ 184 ] , 'Samoa' ) ;
       AFF_ELEMENT ( Tab [ 185 ] , 'Djibouti' ) ;
       AFF_ELEMENT ( Tab [ 186 ] , 'Seychelles' ) ;
       AFF_ELEMENT ( Tab [ 187 ] , 'Pakistan' ) ;

   FIN

   /*****************************************************************************************************************/

   ACTION Aff_eq_fifa5 ( Tab )
   SOIENT
       Tab UN VECTEUR ( 198 ) DE CHAINE ;

   DEBUT
       AFF_ELEMENT ( Tab [ 188 ] , 'Timor Oriental' ) ;
       AFF_ELEMENT ( Tab [ 189 ] , 'Tonga' ) ;
       AFF_ELEMENT ( Tab [ 190 ] , 'Aruba' ) ;
       AFF_ELEMENT ( Tab [ 191 ] , 'Bahamas' ) ;
       AFF_ELEMENT ( Tab [ 192 ] , 'Somalie' ) ;
       AFF_ELEMENT ( Tab [ 193 ] , 'Erythrée' ) ;
       AFF_ELEMENT ( Tab [ 194 ] , 'Sri Lanka' ) ;
       AFF_ELEMENT ( Tab [ 195 ] , 'Turks et Caicos' ) ;
       AFF_ELEMENT ( Tab [ 196 ] , 'Guam' ) ;
       AFF_ELEMENT ( Tab [ 197 ] , 'Anguilla' ) ;
       AFF_ELEMENT ( Tab [ 198 ] , 'SaintMarin' ) ;

   FIN

   /*****************************************************************************************************************/

  ACTION Aff_eq_fav1 ( Tab )
   SOIENT
       Tab UN VECTEUR ( 198 ) DE CHAINE ;

   DEBUT
       AFF_ELEMENT ( Tab [10 ] , 'Bresil' ) ;
       AFF_ELEMENT ( Tab [ 4 ] , 'Belgique' ) ;
       AFF_ELEMENT ( Tab [ 2 ] , 'France' ) ;
       AFF_ELEMENT ( Tab [ 3 ] , 'Argentine' ) ;
       AFF_ELEMENT ( Tab [ 8 ] , 'Angleterre' ) ;
       AFF_ELEMENT ( Tab [ 12 ] , 'Italie' ) ;
       AFF_ELEMENT ( Tab [ 6 ] , 'Espagne' ) ;
       AFF_ELEMENT ( Tab [ 5 ] , 'Portugal' ) ;
       AFF_ELEMENT ( Tab [ 51 ] , 'Mexique' ) ;
       AFF_ELEMENT ( Tab [ 44 ] , 'Pays Bas' ) ;
       AFF_ELEMENT ( Tab [ 26 ] , 'Denmark' ) ;
       AFF_ELEMENT ( Tab [ 7 ] , 'Allemagne' ) ;
       AFF_ELEMENT ( Tab [ 23 ] , 'Uruguay' ) ;
       AFF_ELEMENT ( Tab [ 14 ] , 'Suisse' ) ;
       AFF_ELEMENT ( Tab [ 11 ] , 'Etats Unis' ) ;
       AFF_ELEMENT ( Tab [ 9 ] , 'Croatie' ) ;
       AFF_ELEMENT ( Tab [ 32 ] , 'Colombie' ) ;
       AFF_ELEMENT ( Tab [ 35 ] , 'Pays de Galles' ) ;
       AFF_ELEMENT ( Tab [ 19 ] , 'Suède' ) ;
       AFF_ELEMENT ( Tab [ 20 ] , 'Sénégal' ) ;
       AFF_ELEMENT ( Tab [ 43 ] , 'Iran' ) ;
       AFF_ELEMENT ( Tab [ 22 ] , 'Pérou' ) ;
       AFF_ELEMENT ( Tab [ 13 ] , 'Japon' ) ;
       AFF_ELEMENT ( Tab [ 24 ] , 'Maroc' ) ;
       AFF_ELEMENT ( Tab [ 38 ] , 'Serbie' ) ;
       AFF_ELEMENT ( Tab [ 15 ] , 'Pologne' ) ;
       AFF_ELEMENT ( Tab [ 27 ] , 'Ukraine' ) ;
       AFF_ELEMENT ( Tab [ 36 ] , 'Chili' ) ;
       AFF_ELEMENT ( Tab [ 29 ] , 'Corée du Sud' ) ;
       AFF_ELEMENT ( Tab [ 30 ] , 'Nigeria' ) ;
       AFF_ELEMENT ( Tab [ 31 ] , 'Costa Rica' ) ;
       AFF_ELEMENT ( Tab [ 18 ] , 'Egypte' ) ;
       AFF_ELEMENT ( Tab [ 33 ] , 'Tchèque' ) ;
       AFF_ELEMENT ( Tab [ 40 ] , 'Autriche' ) ;
       AFF_ELEMENT ( Tab [ 17 ] , 'Tunisie' ) ;
       AFF_ELEMENT ( Tab [ 47 ] , 'Russie' ) ;
       AFF_ELEMENT ( Tab [ 37 ] , 'Cameroun' ) ;
       AFF_ELEMENT ( Tab [ 25 ] , 'Canada' ) ;
       AFF_ELEMENT ( Tab [ 39 ] , 'Ecosse' ) ;
       AFF_ELEMENT ( Tab [ 34 ] , 'Hongrie' ) ;
       AFF_ELEMENT ( Tab [ 41 ] , 'Norvège' ) ;
       AFF_ELEMENT ( Tab [ 42 ] , 'Australie' ) ;
       AFF_ELEMENT ( Tab [ 62 ] , 'Turquie' ) ;
       AFF_ELEMENT ( Tab [ 1 ] , 'Algérie' ) ;
       AFF_ELEMENT ( Tab [ 28 ] , 'Slovaquie' ) ;
       AFF_ELEMENT ( Tab [ 46 ] , 'Equateur' ) ;
       AFF_ELEMENT ( Tab [ 55 ] , 'Irlande' ) ;

   FIN

   /*****************************************************************************************************************/

   ACTION Aff_eq_fav2 ( Tab )
   SOIENT
       Tab UN VECTEUR ( 198 ) DE CHAINE ;

   DEBUT
       AFF_ELEMENT ( Tab [ 49 ] , 'Arabie Saoudite' ) ;
       AFF_ELEMENT ( Tab [ 68 ] , 'Paraguay' ) ;
       AFF_ELEMENT ( Tab [ 16 ] , 'Qatar' ) ;
       AFF_ELEMENT ( Tab [ 52 ] , 'Mali' ) ;
       AFF_ELEMENT ( Tab [ 53 ] , 'Côte dIvoire' ) ;
       AFF_ELEMENT ( Tab [ 54 ] , 'Irlande du Nord' ) ;
       AFF_ELEMENT ( Tab [ 45 ] , 'Grèce' ) ;
       AFF_ELEMENT ( Tab [ 56 ] , 'Burkina Faso' ) ;
       AFF_ELEMENT ( Tab [ 60 ] , 'Finlande' ) ;
       AFF_ELEMENT ( Tab [ 71 ] , 'Venezuela' ) ;
       AFF_ELEMENT ( Tab [ 59 ] , 'BosnieHerzégovine' ) ;
       AFF_ELEMENT ( Tab [ 57 ] , 'Ghana' ) ;
       AFF_ELEMENT ( Tab [ 61 ] , 'Panama' ) ;
       AFF_ELEMENT ( Tab [ 21 ] , 'Macédoine du Nord' ) ;
       AFF_ELEMENT ( Tab [ 63 ] , 'Islande' ) ;
       AFF_ELEMENT ( Tab [ 72 ] , 'Jamaïque' ) ;
       AFF_ELEMENT ( Tab [ 65 ] , 'Slovénie' ) ;
       AFF_ELEMENT ( Tab [ 66 ] , 'Albanie' ) ;
       AFF_ELEMENT ( Tab [ 67 ] , 'RD Congo' ) ;
       AFF_ELEMENT ( Tab [ 82 ] , 'Emirats Arabes Unis' ) ;
       AFF_ELEMENT ( Tab [ 69 ] , 'Afrique du Sud' ) ;
       AFF_ELEMENT ( Tab [ 70 ] , 'Montenegro' ) ;
       AFF_ELEMENT ( Tab [ 48 ] , 'Roumanie' ) ;
       AFF_ELEMENT ( Tab [ 58 ] , 'Cap vert' ) ;
       AFF_ELEMENT ( Tab [ 88 ] , 'Iraq' ) ;
       AFF_ELEMENT ( Tab [ 73 ] , 'Bulgarie' ) ;
       AFF_ELEMENT ( Tab [ 74 ] , 'Salvador' ) ;
       AFF_ELEMENT ( Tab [ 93 ] , 'Oman' ) ;
       AFF_ELEMENT ( Tab [ 76 ] , 'Chine' ) ;
       AFF_ELEMENT ( Tab [ 77 ] , 'Bolivie' ) ;
       AFF_ELEMENT ( Tab [ 78 ] , 'Curacao' ) ;
       AFF_ELEMENT ( Tab [ 79 ] , 'Guinée' ) ;
       AFF_ELEMENT ( Tab [ 80 ] , 'Gabon' ) ;
       AFF_ELEMENT ( Tab [ 81 ] , 'Honduras' ) ;
       AFF_ELEMENT ( Tab [ 103 ] , 'Ouzbékistan' ) ;
       AFF_ELEMENT ( Tab [ 83 ] , 'Bénin' ) ;
       AFF_ELEMENT ( Tab [ 100] , 'Géorgie' ) ;
       AFF_ELEMENT ( Tab [ 85 ] , 'Ouganda' ) ;
       AFF_ELEMENT ( Tab [ 86 ] , 'Zambie' ) ;
       AFF_ELEMENT ( Tab [ 87 ] , 'Syrie' ) ;
       AFF_ELEMENT ( Tab [ 64 ] , 'Bahrein' ) ;
       AFF_ELEMENT ( Tab [ 89 ] , 'Haïti' ) ;
       AFF_ELEMENT ( Tab [ 84 ] , 'Jordanie' ) ;
       AFF_ELEMENT ( Tab [ 91 ] , 'Arménie' ) ;
       AFF_ELEMENT ( Tab [ 92 ] , 'Biélorussie' ) ;
       AFF_ELEMENT ( Tab [ 75 ] , 'Luxembourg' ) ;

   FIN

   /*****************************************************************************************************************/

   ACTION Aff_eq_fav3 ( Tab )
   SOIENT
       Tab UN VECTEUR ( 198 ) DE CHAINE ;

   DEBUT
       AFF_ELEMENT ( Tab [ 129 ] , 'Kirghizistan' ) ;
       AFF_ELEMENT ( Tab [ 95 ] , 'Vietnam' ) ;
       AFF_ELEMENT ( Tab [ 96 ] , 'Congo' ) ;
       AFF_ELEMENT ( Tab [ 97 ] , 'Guinée Equatoriale' ) ;
       AFF_ELEMENT ( Tab [ 98 ] , 'Palestine' ) ;
       AFF_ELEMENT ( Tab [ 99 ] , 'NouvelleZélande' ) ;
       AFF_ELEMENT ( Tab [ 90 ] , 'Madagascar' ) ;
       AFF_ELEMENT ( Tab [ 101 ] , 'TrinitéetTobago' ) ;
       AFF_ELEMENT ( Tab [ 102 ] , 'Kenya' ) ;
       AFF_ELEMENT ( Tab [ 50 ] , 'Chypre' ) ;
       AFF_ELEMENT ( Tab [ 134 ] , 'Inde' ) ;
       AFF_ELEMENT ( Tab [ 139 ] , 'Sierra Leone' ) ;
       AFF_ELEMENT ( Tab [ 106 ] , 'Corée du Nord' ) ;
       AFF_ELEMENT ( Tab [ 107 ] , 'Estonie' ) ;
       AFF_ELEMENT ( Tab [ 108 ] , 'Thaïlande' ) ;
       AFF_ELEMENT ( Tab [ 109 ] , 'Namibie' ) ;
       AFF_ELEMENT ( Tab [ 132 ] , 'Mauritanie' ) ;
       AFF_ELEMENT ( Tab [ 136 ] , 'Tadjikistan' ) ;
       AFF_ELEMENT ( Tab [ 112 ] , 'Guinée Bissau' ) ;
       AFF_ELEMENT ( Tab [ 113 ] , 'Niger' ) ;
       AFF_ELEMENT ( Tab [ 114 ] , 'Libye' ) ;
       AFF_ELEMENT ( Tab [ 140 ] , 'Guatemala' ) ;
       AFF_ELEMENT ( Tab [ 116 ] , 'Mozambique' ) ;
       AFF_ELEMENT ( Tab [ 117 ] , 'Malawi' ) ;
       AFF_ELEMENT ( Tab [ 118 ] , 'Togo' ) ;
       AFF_ELEMENT ( Tab [ 119 ] , 'Zimbabwe' ) ;
       AFF_ELEMENT ( Tab [ 188 ] , 'Gambie' ) ;
       AFF_ELEMENT ( Tab [ 121 ] , 'Kazakhstan' ) ;
       AFF_ELEMENT ( Tab [ 186 ] , 'Angola' ) ;
       AFF_ELEMENT ( Tab [ 143 ] , 'Antigua' ) ;
       AFF_ELEMENT ( Tab [ 148 ] , 'Comores' ) ;
       AFF_ELEMENT ( Tab [ 125 ] , 'Azerbaïdjan' ) ;
       AFF_ELEMENT ( Tab [ 194 ] , 'Tanzanie' ) ;
       AFF_ELEMENT ( Tab [ 127 ] , 'Rép. Centrafricaine' ) ;
       AFF_ELEMENT ( Tab [ 128 ] , 'Soudan' ) ;
       AFF_ELEMENT ( Tab [ 94  ] , 'Philippines' ) ;
       AFF_ELEMENT ( Tab [ 130 ] , 'Turkménistan' ) ;
       AFF_ELEMENT ( Tab [ 131 ] , 'Lettonie' ) ;
       AFF_ELEMENT ( Tab [ 110 ] , 'Rwanda' ) ;
       AFF_ELEMENT ( Tab [ 133 ] , 'Lituanie' ) ;
       AFF_ELEMENT ( Tab [ 104 ] , 'Burundi' ) ;
       AFF_ELEMENT ( Tab [ 135 ] , 'Ethiopie' ) ;
       AFF_ELEMENT ( Tab [ 111 ] , 'Surinam' ) ;
       AFF_ELEMENT ( Tab [ 137 ] , 'SaintKitts et Nevis' ) ;
       AFF_ELEMENT ( Tab [ 138 ] , 'Swaziland' ) ;
       AFF_ELEMENT ( Tab [ 105] , 'Lesotho' ) ;
       AFF_ELEMENT ( Tab [ 115 ] , 'Koweit' ) ;

   FIN

   /*****************************************************************************************************************/

   ACTION Aff_eq_fav4 ( Tab )
   SOIENT
       Tab UN VECTEUR ( 198 ) DE CHAINE ;

   DEBUT
       AFF_ELEMENT ( Tab [ 141 ] , 'HongKong' ) ;
       AFF_ELEMENT ( Tab [ 142 ] , 'Botswana' ) ;
       AFF_ELEMENT ( Tab [ 123 ] , 'Liberia' ) ;
       AFF_ELEMENT ( Tab [ 144 ] , 'Afghanistan' ) ;
       AFF_ELEMENT ( Tab [ 145 ] , 'Yémen' ) ;
       AFF_ELEMENT ( Tab [ 146 ] , 'Myanmar' ) ;
       AFF_ELEMENT ( Tab [ 147 ] , 'Andorre' ) ;
       AFF_ELEMENT ( Tab [ 124 ] , 'Malaisie' ) ;
       AFF_ELEMENT ( Tab [ 149 ] , 'République Dominicaine' ) ;
       AFF_ELEMENT ( Tab [ 150 ] , 'Maldives' ) ;
       AFF_ELEMENT ( Tab [ 151 ] , 'Taïwan' ) ;
       AFF_ELEMENT ( Tab [ 122 ] , 'Indonésie' ) ;
       AFF_ELEMENT ( Tab [ 153 ] , 'NouvelleCalédonie' ) ;
       AFF_ELEMENT ( Tab [ 154 ] , 'Soudan du sud' ) ;
       AFF_ELEMENT ( Tab [ 155 ] , 'PapouasieNouvelle Guinée' ) ;
       AFF_ELEMENT ( Tab [ 156 ] , 'Barbade' ) ;
       AFF_ELEMENT ( Tab [ 157 ] , 'Tahiti' ) ;
       AFF_ELEMENT ( Tab [ 158 ] , 'Fidji' ) ;
       AFF_ELEMENT ( Tab [ 183 ] , 'Vanuatu' ) ;
       AFF_ELEMENT ( Tab [ 192 ] , 'Bermudes' ) ;
       AFF_ELEMENT ( Tab [ 161 ] , 'Népal' ) ;
       AFF_ELEMENT ( Tab [ 162 ] , 'Malte' ) ;
       AFF_ELEMENT ( Tab [ 175 ] , 'Grenade' ) ;
       AFF_ELEMENT ( Tab [ 164 ] , 'Cambodge' ) ;
       AFF_ELEMENT ( Tab [ 191 ] , 'Porto Rico' ) ;
       AFF_ELEMENT ( Tab [ 180 ] , 'Belize' ) ;
       AFF_ELEMENT ( Tab [ 167 ] , 'Guyana' ) ;
       AFF_ELEMENT ( Tab [ 168 ] , 'Saint Vincent' ) ;
       AFF_ELEMENT ( Tab [ 169 ] , 'Sainte Lucie' ) ;
       AFF_ELEMENT ( Tab [ 182 ] , 'Cuba' ) ;
       AFF_ELEMENT ( Tab [ 171 ] , 'Montserrat' ) ;
       AFF_ELEMENT ( Tab [ 172 ] , 'Moldavie' ) ;
       AFF_ELEMENT ( Tab [ 173 ] , 'Tchad' ) ;
       AFF_ELEMENT ( Tab [ 174 ] , 'Macao' ) ;
       AFF_ELEMENT ( Tab [ 163 ] , 'Sao Tomé et Principe' ) ;
       AFF_ELEMENT ( Tab [ 176 ] , 'Dominique' ) ;
       AFF_ELEMENT ( Tab [ 190 ] , 'Laos' ) ;
       AFF_ELEMENT ( Tab [ 178 ] , 'Mongolie' ) ;
       AFF_ELEMENT ( Tab [ 179 ] , 'Bhoutan' ) ;
       AFF_ELEMENT ( Tab [ 166 ] , 'Bangladesh' ) ;
       AFF_ELEMENT ( Tab [ 181 ] , 'Samoa Américaines' ) ;
       AFF_ELEMENT ( Tab [ 170 ] , 'Bruneï' ) ;
       AFF_ELEMENT ( Tab [ 159 ] , 'Liechtenstein' ) ;
       AFF_ELEMENT ( Tab [ 184 ] , 'Samoa' ) ;
       AFF_ELEMENT ( Tab [ 185 ] , 'Djibouti' ) ;
       AFF_ELEMENT ( Tab [ 152 ] , 'Seychelles' ) ;
       AFF_ELEMENT ( Tab [ 198 ] , 'Pakistan' ) ;

   FIN

   /*****************************************************************************************************************/

   ACTION Aff_eq_fav5 ( Tab )
   SOIENT
       Tab UN VECTEUR ( 198 ) DE CHAINE ;

   DEBUT
       AFF_ELEMENT ( Tab [ 193 ] , 'Timor Oriental' ) ;
       AFF_ELEMENT ( Tab [ 189 ] , 'Tonga' ) ;
       AFF_ELEMENT ( Tab [ 177 ] , 'Aruba' ) ;
       AFF_ELEMENT ( Tab [ 165 ] , 'Bahamas' ) ;
       AFF_ELEMENT ( Tab [ 160 ] , 'Somalie' ) ;
       AFF_ELEMENT ( Tab [ 120 ] , 'Erythrée' ) ;
       AFF_ELEMENT ( Tab [ 126 ] , 'Sri Lanka' ) ;
       AFF_ELEMENT ( Tab [ 195 ] , 'Turks et Caicos' ) ;
       AFF_ELEMENT ( Tab [ 196 ] , 'Guam' ) ;
       AFF_ELEMENT ( Tab [ 197 ] , 'Anguilla' ) ;
       AFF_ELEMENT ( Tab [ 187 ] , 'SaintMarin' ) ;

   FIN


   /********************* FIN PHASE 1 *********************/
   /*****************************************************************************************************************/

