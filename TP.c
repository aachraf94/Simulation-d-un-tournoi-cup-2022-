
	/**--------------------------------------------------------**/
	/**       C o n v e r s i o n   Z vers C (Standard)        **/
	/**             Realisee par Pr D.E ZEGOUR                 **/
	/**             E S I - Alger                              **/
	/**             Copywrite 2014                             **/
	/**--------------------------------------------------------**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <_mingw.h>
#include <windows.h>
#include <time.h>

/***************************************************************************************************************************************************/


/* 1234  563 */


/***************************************************************************************************************************************************/



	typedef int bool ;
	typedef char * string255 ;

	#define True 1
	#define False 0

	/** Implementation **\: TABLEAU DE CHAINES DE CARACTERES**/

	/** Tableaux **/

	typedef string255 Typeelem_V198s ;
	typedef Typeelem_V198s * Typevect_V198s ;

	Typeelem_V198s Element_V198s ( Typevect_V198s V , int I1  )
		{
			return  *(V + I1-1 ) ;
		}

	void Aff_element_V198s ( Typevect_V198s V  , int I1 ,  Typeelem_V198s Val )
		{
		 strcpy( *(V + I1-1 ) , Val );
		}


	/** Implementation **\: TABLEAU DE STRUCTURES**/

	/** Structures statiques **/

	typedef struct Tiiii Type_Tiiii  ;
	typedef Type_Tiiii * Typestr_Tiiii ;
	typedef int Type1_Tiiii  ;
	typedef int Type2_Tiiii  ;
	typedef int Type3_Tiiii  ;
	typedef int Type4_Tiiii  ;
	struct Tiiii
		{
			Type1_Tiiii Champ1 ;
			Type2_Tiiii Champ2 ;
			Type3_Tiiii Champ3 ;
			Type4_Tiiii Champ4 ;
		};

	Type1_Tiiii Struct1_Tiiii ( Typestr_Tiiii S)
		{
			return  S->Champ1 ;
		}

	Type2_Tiiii Struct2_Tiiii ( Typestr_Tiiii S)
		{
			return  S->Champ2 ;
		}

	Type3_Tiiii Struct3_Tiiii ( Typestr_Tiiii S)
		{
			return  S->Champ3 ;
		}

	Type4_Tiiii Struct4_Tiiii ( Typestr_Tiiii S)
		{
			return  S->Champ4 ;
		}

	void Aff_struct1_Tiiii ( Typestr_Tiiii S, Type1_Tiiii Val )
		{
			 S->Champ1 = Val ;
		}

	void Aff_struct2_Tiiii ( Typestr_Tiiii S, Type2_Tiiii Val )
		{
			 S->Champ2 = Val ;
		}

	void Aff_struct3_Tiiii ( Typestr_Tiiii S, Type3_Tiiii Val )
		{
			 S->Champ3 = Val ;
		}

	void Aff_struct4_Tiiii ( Typestr_Tiiii S, Type4_Tiiii Val )
		{
			 S->Champ4 = Val ;
		}


	/** Tableaux **/

	typedef Typestr_Tiiii Typeelem_V8Tiiii ;
	typedef Typeelem_V8Tiiii * Typevect_V8Tiiii ;

	Typeelem_V8Tiiii Element_V8Tiiii ( Typevect_V8Tiiii V , int I1  )
		{
			return  *(V + I1-1 ) ;
		}

	void Aff_element_V8Tiiii ( Typevect_V8Tiiii V  , int I1 ,  Typeelem_V8Tiiii Val )
		{
			Typeelem_V8Tiiii _Temp ;
			_Temp = malloc(sizeof(Type_Tiiii));
			/* Affectation globale de structure */
			_Temp->Champ1 = Val->Champ1;
			_Temp->Champ2 = Val->Champ2;
			_Temp->Champ3 = Val->Champ3;
			_Temp->Champ4 = Val->Champ4;
			Val = _Temp ;
			*(V + I1-1 ) = Val ;
		}


	/** Implementation **\: TABLEAU DE LISTES DE STRUCTURES**/

	/** Structures statiques **/

	typedef struct Tii Type_Tii  ;
	typedef Type_Tii * Typestr_Tii ;
	typedef int Type1_Tii  ;
	typedef int Type2_Tii  ;
	struct Tii
		{
			Type1_Tii Champ1 ;
			Type2_Tii Champ2 ;
		};

	Type1_Tii Struct1_Tii ( Typestr_Tii S)
		{
			return  S->Champ1 ;
		}

	Type2_Tii Struct2_Tii ( Typestr_Tii S)
		{
			return  S->Champ2 ;
		}

	void Aff_struct1_Tii ( Typestr_Tii S, Type1_Tii Val )
		{
			 S->Champ1 = Val ;
		}

	void Aff_struct2_Tii ( Typestr_Tii S, Type2_Tii Val )
		{
			 S->Champ2 = Val ;
		}


	/** Listes lin?aires cha?n?es **/

	typedef Typestr_Tii Typeelem_LTii   ;
	typedef struct Maillon_LTii * Pointeur_LTii ;

	struct Maillon_LTii
		{
			Typeelem_LTii  Val ;
			Pointeur_LTii Suiv ;
		} ;

	Pointeur_LTii Allouer_LTii (Pointeur_LTii *P)
		{
			*P = (struct Maillon_LTii *) malloc( sizeof( struct Maillon_LTii)) ;
			(*P)->Val = malloc(sizeof(Type_Tii));
			(*P)->Suiv = NULL;
		}

	void Aff_val_LTii(Pointeur_LTii P, Typeelem_LTii Val)
		{
			Typeelem_LTii _Temp ;
			_Temp = malloc(sizeof(Type_Tii));
			/* Affectation globale de structure */
			_Temp->Champ1 = Val->Champ1;
			_Temp->Champ2 = Val->Champ2;
			Val = _Temp ;
			P->Val = Val ;
		}

	void Aff_adr_LTii( Pointeur_LTii P,  Pointeur_LTii Q)
		{
			P->Suiv = Q ;
		}

	Pointeur_LTii Suivant_LTii(  Pointeur_LTii P)
		{ return( P->Suiv ) ;  }

	Typeelem_LTii Valeur_LTii( Pointeur_LTii P)
		{ return( P->Val) ; }

	void Liberer_LTii ( Pointeur_LTii P)
		{ free (P);}


	/** Tableaux **/

	typedef Pointeur_LTii Typeelem_V8LTii ;
	typedef Typeelem_V8LTii * Typevect_V8LTii ;

	Typeelem_V8LTii Element_V8LTii ( Typevect_V8LTii V , int I1  )
		{
			return  *(V + I1-1 ) ;
		}

	void Aff_element_V8LTii ( Typevect_V8LTii V  , int I1 ,  Typeelem_V8LTii Val )
		{
			*(V + I1-1 ) = Val ;
		}


	/** Implementation **\: TABLEAU DE ENTIERS**/

	/** Tableaux **/

	typedef int Typeelem_V32i ;
	typedef Typeelem_V32i * Typevect_V32i ;

	Typeelem_V32i Element_V32i ( Typevect_V32i V , int I1  )
		{
			return  *(V + I1-1 ) ;
		}

	void Aff_element_V32i ( Typevect_V32i V  , int I1 ,  Typeelem_V32i Val )
		{
			*(V + I1-1 ) = Val ;
		}


	/** Implementation **\: TABLEAU DE STRUCTURES**/

	/** Structures statiques **/

	typedef struct Tisiii Type_Tisiii  ;
	typedef Type_Tisiii * Typestr_Tisiii ;
	typedef int Type1_Tisiii  ;
	typedef string255 Type2_Tisiii  ;
	typedef int Type3_Tisiii  ;
	typedef int Type4_Tisiii  ;
	typedef int Type5_Tisiii  ;
	struct Tisiii
		{
			Type1_Tisiii Champ1 ;
			Type2_Tisiii Champ2 ;
			Type3_Tisiii Champ3 ;
			Type4_Tisiii Champ4 ;
			Type5_Tisiii Champ5 ;
		};

	Type1_Tisiii Struct1_Tisiii ( Typestr_Tisiii S)
		{
			return  S->Champ1 ;
		}

	Type2_Tisiii Struct2_Tisiii ( Typestr_Tisiii S)
		{
			return  S->Champ2 ;
		}

	Type3_Tisiii Struct3_Tisiii ( Typestr_Tisiii S)
		{
			return  S->Champ3 ;
		}
	
	Type4_Tisiii Struct4_Tisiii ( Typestr_Tisiii S)
		{
			return  S->Champ4 ;
		}

	Type5_Tisiii Struct5_Tisiii ( Typestr_Tisiii S)
		{
			return  S->Champ5 ;
		}

	void Aff_struct1_Tisiii ( Typestr_Tisiii S, Type1_Tisiii Val )
		{
			 S->Champ1 = Val ;
		}

	void Aff_struct2_Tisiii ( Typestr_Tisiii S, Type2_Tisiii Val )
		{
			strcpy( S->Champ2 , Val );
		}

	void Aff_struct3_Tisiii ( Typestr_Tisiii S, Type3_Tisiii Val )
		{
			 S->Champ3 = Val ;
		}

	void Aff_struct4_Tisiii ( Typestr_Tisiii S, Type4_Tisiii Val )
		{
			 S->Champ4 = Val ;
		}

	void Aff_struct5_Tisiii ( Typestr_Tisiii S, Type5_Tisiii Val )
		{
			 S->Champ5 = Val ;
		}


	/** Tableaux **/

	typedef Typestr_Tisiii Typeelem_V32Tisiii ;
	typedef Typeelem_V32Tisiii * Typevect_V32Tisiii ;

	Typeelem_V32Tisiii Element_V32Tisiii ( Typevect_V32Tisiii V , int I1  )
		{
			return  *(V + I1-1 ) ;
		}

	void Aff_element_V32Tisiii ( Typevect_V32Tisiii V  , int I1 ,  Typeelem_V32Tisiii Val )
		{
			Typeelem_V32Tisiii _Temp ;
			_Temp = malloc(sizeof(Type_Tisiii));
			_Temp->Champ2 = malloc(255 * sizeof(char));
			/* Affectation globale de structure */
			_Temp->Champ1 = Val->Champ1;
			strcpy(_Temp->Champ2, Val->Champ2);
			_Temp->Champ3 = Val->Champ3;
			_Temp->Champ4 = Val->Champ4;
			_Temp->Champ5 = Val->Champ5;
			Val = _Temp ;
			*(V + I1-1 ) = Val ;
		}


	/** Implementation **\: ARBRE BINAIRE DE STRUCTURES**/

	/** Arbres de recherche binaire **/

	typedef Typestr_Tii Typeelem_ATii   ;
	typedef struct Noeud_ATii * Pointeur_ATii ;

	struct Noeud_ATii
		{
			Typeelem_ATii  Val ;
			Pointeur_ATii Fg ;
			Pointeur_ATii Fd ;
			Pointeur_ATii Pere ;
		 } ;

	Typeelem_ATii Info_ATii( Pointeur_ATii P )
		{ return P->Val;   }

	Pointeur_ATii Fg_ATii( Pointeur_ATii P)
		{ return P->Fg ; }

	Pointeur_ATii Fd_ATii( Pointeur_ATii P)
		{ return P->Fd ; }

	Pointeur_ATii Pere_ATii( Pointeur_ATii P)
		{ return P->Pere ; }

	void Aff_info_ATii ( Pointeur_ATii P, Typeelem_ATii Val)
		{
			Typeelem_ATii _Temp ;
			_Temp = malloc(sizeof(Type_Tii));
			/* Affectation globale de structure */
			_Temp->Champ1 = Val->Champ1;
			_Temp->Champ2 = Val->Champ2;
			Val = _Temp ;
			 P->Val = Val ;
		}

	void Aff_fg_ATii( Pointeur_ATii P, Pointeur_ATii Q)
		{ P->Fg =  Q;  }

	void Aff_fd_ATii( Pointeur_ATii P, Pointeur_ATii Q)
		{ P->Fd =  Q ; }

	void Aff_pere_ATii( Pointeur_ATii P, Pointeur_ATii Q)
		{ P->Pere =  Q ; }

	void Creernoeud_ATii( Pointeur_ATii *P)
		{
			*P = (struct Noeud_ATii *) malloc( sizeof( struct Noeud_ATii))   ;
			(*P)->Val = malloc(sizeof(Type_Tii));
			(*P)->Fg = NULL;
			(*P)->Fd = NULL;
			(*P)->Pere = NULL;
		}

	void Liberernoeud_ATii( Pointeur_ATii P)
		{ free( P ) ; }


	/** Implementation **\: TABLEAU DE ENTIERS**/

	/** Tableaux **/

	typedef int Typeelem_V8i ;
	typedef Typeelem_V8i * Typevect_V8i ;

	Typeelem_V8i Element_V8i ( Typevect_V8i V , int I1  )
		{
			return  *(V + I1-1 ) ;
		}

	void Aff_element_V8i ( Typevect_V8i V  , int I1 ,  Typeelem_V8i Val )
		{
			*(V + I1-1 ) = Val ;
		}


	/** Implementation **\: PILE DE ARBRES BINAIRES DE STRUCTURES**/
	/** Piles **/

	typedef Pointeur_ATii Typeelem_PATii ;
	typedef struct Maillon_PATii * Pointeur_PATii ;
	typedef   Pointeur_PATii  Typepile_PATii  ;

	struct Maillon_PATii
		{
			Typeelem_PATii  Val ;
			Pointeur_PATii Suiv ;
		} ;

	void Creerpile_PATii( Pointeur_PATii *P )
		{ *P = NULL ; }

	bool Pilevide_PATii ( Pointeur_PATii P )
		{ return  (P == NULL ); }

	void Empiler_PATii ( Pointeur_PATii *P,  Typeelem_PATii Val )
		{
			Pointeur_PATii Q;

			Q = (struct Maillon_PATii *) malloc( sizeof( struct Maillon_PATii))   ;
			Q->Val = Val ;
			Q->Suiv = *P;
			*P = Q;
		}

	void Depiler_PATii ( Pointeur_PATii *P,  Typeelem_PATii *Val )
		{
			Pointeur_PATii Sauv;

			if (! Pilevide_PATii (*P) )
				{
					*Val = (*P)->Val ;
					Sauv = *P;
					*P = (*P)->Suiv;
					free(Sauv);
				}
			else printf ("%s \n", "Pile vide");
		}


	/** Implementation **\: FILE DE ARBRES BINAIRES DE STRUCTURES**/
	/** Files d'attente **/

	typedef Pointeur_ATii Typeelem_FATii ;
	typedef  struct Filedattente_FATii * Pointeur_FATii ;
	typedef  struct Maillon_FATii * Ptliste_FATii ;

	struct Maillon_FATii
		{
			Typeelem_FATii Val ;
			Ptliste_FATii Suiv  ;
		};

	struct Filedattente_FATii
		{
			Ptliste_FATii Tete, Queue ;
		};

	void Creerfile_FATii ( Pointeur_FATii *Fil   )
		{
			*Fil = (struct Filedattente_FATii *) malloc( sizeof( struct Filedattente_FATii)) ;
			(*Fil)->Tete = NULL ;
			(*Fil)->Queue = NULL ;
		}

	bool Filevide_FATii (Pointeur_FATii Fil  )
		{ return  Fil->Tete == NULL ;}

	void Enfiler_FATii ( Pointeur_FATii Fil , Typeelem_FATii Val   )
		{
			Ptliste_FATii Q;

			Q = (struct Maillon_FATii *) malloc( sizeof( struct Maillon_FATii))   ;
			Q->Val = Val ;
			Q->Suiv = NULL;
			if ( ! Filevide_FATii(Fil) )
				Fil->Queue->Suiv = Q ;
			else Fil->Tete = Q;
				Fil->Queue = Q;
		}

	void Defiler_FATii (Pointeur_FATii Fil, Typeelem_FATii *Val )
		{
			if (! Filevide_FATii(Fil) )
				{
					*Val = Fil->Tete->Val ;
					Fil->Tete =  Fil->Tete->Suiv;
				}
			else printf ("%s \n", "File d'attente vide");
		}


	/** Implementation **\: TABLEAU DE ENTIERS**/

	/** Tableaux **/

	typedef int Typeelem_V4i ;
	typedef Typeelem_V4i * Typevect_V4i ;

	Typeelem_V4i Element_V4i ( Typevect_V4i V , int I1  )
		{
			return  *(V + I1-1 ) ;
		}

	void Aff_element_V4i ( Typevect_V4i V  , int I1 ,  Typeelem_V4i Val )
		{
			*(V + I1-1 ) = Val ;
		}

	/** Variables du programme principal **/
	Typevect_V198s Fifa;
	Typevect_V198s Fav;
	Typevect_V8Tiiii Groups;
	Typevect_V8LTii Tab_listes;
	Typevect_V32i Participants;
	Typevect_V32Tisiii Equipes;
	Pointeur_ATii Phase_2;
	Typevect_V8i First;
	Typevect_V8i Second;
	Pointeur_PATii Pile_parcours;
	int _Izw;  /** Variable de contrôle **/

	/** Fonctions standards **/

	int Aleanombre( int N )
		{ 
			return ( rand() % N );
		}

	int Mod( int a, int b)
		{ return ( a % b ); }


/***************************************************************************************************************************************************/

/* Ceci est un complement pour la bibliotheque conio qui me permet d'afficher les couleurs */

/***************************************************************************************************************************************************/

#ifndef _CONIO2_H_
#define _CONIO2_H_

#ifdef UNICODE
		#include <windows.h>    // we need wchar_t
#endif

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Colors which you can use in your application.
 */
typedef enum
{
		BLACK,          /**< black color */
		BLUE,           /**< blue color */
		GREEN,          /**< green color */
		CYAN,           /**< cyan color */
		RED,            /**< red color */
		MAGENTA,        /**< magenta color */
		BROWN,          /**< brown color */
		LIGHTGRAY,      /**< light gray color */
		DARKGRAY,       /**< dark gray color */
		LIGHTBLUE,      /**< light blue color */
		LIGHTGREEN,     /**< light green color */
		LIGHTCYAN,      /**< light cyan color */
		LIGHTRED,       /**< light red color */
		LIGHTMAGENTA,   /**< light magenta color */
		YELLOW,         /**< yellow color */
		WHITE           /**< white color */
} COLORS;

/*@{*/
/**
 * This defines enables you to use all MinGW conio.h functions without
 * underscore.
 */
#define cgets   _cgets
#define cprintf _cprintf
#define cputs   _cputs
#define cscanf  _cscanf

#ifdef UNICODE
		#define cgetws   _cgetws
		#define getwch   _getwch
		#define getwche  _getwche
		#define putwch   _putwch
		#define ungetwch _ungetwch
		#define cputws   _cputws
		#define cwprintf _cwprintf
		#define cwscanf  _cwscanf
#endif
/*@}*/

/**
 * Define alias for _conio_gettext.
 * If you want to use gettext function from some other library
 * (e.g. GNU gettext) you have to define _CONIO_NO_GETTEXT_ so you won't get
 * name conflict.
 */
#ifndef _CONIO_NO_GETTEXT_
	#define gettext _conio_gettext
#endif

#define ScreenClear clrscr

/**
 * @anchor cursortypes
 * @name Cursor types
 * Predefined cursor types. */
/*@{*/
#define _NOCURSOR 0         /**< no cursor */
#define _SOLIDCURSOR 100    /**< cursor filling whole cell */
#define _NORMALCURSOR 20    /**< cursor filling 20 percent of cell height */
/*@}*/

/**
 * Structure holding information about screen.
 * @see gettextinfo
 * @see inittextinfo
 */
struct text_info {
		unsigned char curx;          /**< cursor coordinate x */
		unsigned char cury;          /**< cursor coordinate y */
		unsigned short attribute;    /**< current text attribute */
		unsigned short normattr;     /**< original value of text attribute after
																			start of the application. If you don't
																			called the <TT>inittextinfo</TT> on the
																			beginning of the application, this always
																			will be black background and light gray
																			foreground */
		unsigned char screenwidth;   /**< screen width */
		unsigned char screenheight;  /**< screen height */
};

/**
 * Structure used by gettext/puttext.
 * @see _conio_gettext
 * @see puttext
 */
struct char_info {
#ifdef UNICODE
		wchar_t letter;        /**< character value */
#else
		char letter;           /**< character value */
#endif
		unsigned short attr;   /**< attribute value */
};

/**
 * Returns information of the screen.
 * @see text_info
 */
void gettextinfo (struct text_info * info);

/**
 * Call this if you need real value of normattr attribute in the text_info
 * structure.
 * @see text_info
 */
void inittextinfo (void);

/**
 * Clears rest of the line from cursor position to the end of line without
 * moving the cursor.
 */
void clreol (void);

/**
 * Clears whole screen.
 */
void clrscr (void);

/**
 * Delete the current line (line on which is cursor) and then moves all lines
 * below one line up. Lines below the line are moved one line up.
 */
void delline (void);

/**
 * Insert blank line at the cursor position.
 * Original content of the line and content of lines below moves one line down.
 * The last line is deleted.
 */
void insline (void);

/**
 * Gets text from the screen. If you haven't defined <TT>_CONIO_NO_GETTEXT_</TT>
 * prior to including <TT>conio2.h</TT> you can use this function also under
 * the <TT>gettext</TT> name.
 * @see char_info
 * @see puttext
 * @param left Left coordinate of the rectangle, inclusive, starting from 1.
 * @param top Top coordinate of the rectangle, inclusive, starting from 1.
 * @param right Right coordinate of the rectangle, inclusive, starting from 1.
 * @param bottom Bottom coordinate of the rectangle, inclusive, starting from 1.
 * @param buf You have to pass buffer of size
 * <TT>(right - left + 1) * (bottom - top + 1) * sizeof(char_info)</TT>.
 */
void _conio_gettext (int left, int top, int right, int bottom,
										 struct char_info * buf);

/**
 * Puts text back to the screen.
 * @see char_info
 * @see _conio_gettext
 * @param left Left coordinate of the rectangle, inclusive, starting from 1.
 * @param top Top coordinate of the rectangle, inclusive, starting from 1.
 * @param right Right coordinate of the rectangle, inclusive, starting from 1.
 * @param bottom Bottom coordinate of the rectangle, inclusive, starting from 1.
 * @param buf You have to pass buffer of size
 * <TT>(right - left + 1) * (bottom - top + 1) * sizeof(char_info)</TT>.
 */
void puttext (int left, int top, int right, int bottom, struct char_info * buf);

/**
 * Copies text.
 * @param left Left coordinate of the rectangle, inclusive, starting from 1.
 * @param top Top coordinate of the rectangle, inclusive, starting from 1.
 * @param right Right coordinate of the rectangle, inclusive, starting from 1.
 * @param bottom Bottom coordinate of the rectangle, inclusive, starting from 1.
 * @param destleft Left coordinate of the destination rectangle.
 * @param desttop Top coordinate of the destination rectangle.
 */
void movetext (int left, int top, int right, int bottom, int destleft,
							int desttop);

/**
 * Moves cursor to the specified position.
 * @param x horizontal position
 * @param y vertical position
 */
void gotoxy(int x, int y);

/**
 * Puts string at the specified position.
 * @param x horizontal position
 * @param y vertical position
 * @param str string
 */
void cputsxy (int x, int y, char * str);

/**
 * Puts char at the specified position.
 * @param x horizontal position
 * @param y vertical position
 * @param ch char
 */
void putchxy (int x, int y, char ch);

/**
 * Sets the cursor type.
 * @see @ref cursortypes
 * @param type cursor type, under Win32 it is height of the cursor in percents
 */
void _setcursortype (int type);

/**
 * Sets attribute of text.
 * @param _attr new text attribute
 */
void textattr (int _attr);

/**
 * Sets text attribute back to value it had after program start.
 * It uses text_info's normattr value.
 * @see text_info
 */
void normvideo (void);

/**
 * Sets text background color.
 * @see COLORS
 * @param color new background color
 */
void textbackground (int color);

/**
 * Sets text foreground color.
 * @see COLORS
 * @param color new foreground color
 */
void textcolor (int color);

/**
 * Reads the cursor X position.
 * @returns cursor X position
 */
int wherex (void);

/**
 * Reads the cursor Y position.
 * @returns cursor Y position
 */
int wherey (void);

/**
 * Reads password. This function behaves like cgets.
 *
 * @see cgets
 * @param prompt prompt which will be displayed to user
 * @param str string for the password. <TT>str[0]</TT> have to contain
 * length of the <TT>str</TT> - 3
 * @returns <TT>&str[2]</TT>, the password will be stored in <TT>str</TT>
 * beginning at <TT>str[2]</TT>, in <TT>str[1]</TT> will be length of the
 * string without <TT>\\0</TT>, at <TT>str[2 + str[1]]</TT> will be \\0.
 */
char * getpass (const char * prompt, char * str);

/**
 * Makes foreground colors light.
 * If the current foreground color is less than <TT>DARKGRAY</TT> adds
 * 8 to the its value making dark colors light.
 * @see COLORS
 * @see lowvideo
 */
void highvideo (void);

/**
 * Makes foreground colors dark.
 * If the current foreground color is higher than <TT>LIGHTGRAY</TT> substracts
 * 8 from its value making light colors dark.
 * @see COLORS
 * @see highvideo
 */
void lowvideo (void);

/*@{*/
/** Link with libmsvcr70.a or libmsvcr70d.a or libmsvcr71.a or libmsvcr71d.a
 *  if you want any of these functions. */
#ifdef UNICODE
_CRTIMP wchar_t * __cdecl         _cgetws(wchar_t *);
_CRTIMP unsigned short __cdecl    _getwch(void);
_CRTIMP unsigned short __cdecl    _getwche(void);
_CRTIMP unsigned short __cdecl    _putwch(wchar_t);
_CRTIMP unsigned short __cdecl    _ungetwch(unsigned short);
_CRTIMP int __cdecl               _cputws(const wchar_t *);
_CRTIMP int __cdecl               _cwprintf(const wchar_t *, ...);
_CRTIMP int __cdecl               _cwscanf(const wchar_t *, ...);
#endif
/*@}*/

#ifdef __cplusplus
}
#endif

#endif /* _CONIO2_H_ */


#ifdef __cplusplus
extern "C" {
#endif

static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;
static struct text_info __text_info = {
		1, 1,
		LIGHTGRAY + (BLACK << 4),
		LIGHTGRAY + (BLACK << 4),
		80, 25
};
static int __CONIO_TOP = 0;
static int __CONIO_LEFT = 0;

static void
__fill_text_info (void)
{
		CONSOLE_SCREEN_BUFFER_INFO info;

		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
		__CONIO_LEFT = info.srWindow.Left;
		__CONIO_TOP = info.srWindow.Top;
		__text_info.curx = info.dwCursorPosition.X - __CONIO_LEFT + 1;
		__text_info.cury = info.dwCursorPosition.Y - __CONIO_TOP  + 1;
		__text_info.attribute = info.wAttributes;
		__text_info.screenwidth  = info.srWindow.Right - info.srWindow.Left + 1;
		__text_info.screenheight = info.srWindow.Bottom - info.srWindow.Top + 1;
}

void
gettextinfo (struct text_info * info)
{
		__fill_text_info();
		*info = __text_info;
}

void
inittextinfo (void)
{
		CONSOLE_SCREEN_BUFFER_INFO info;

		GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &info);
		__text_info.normattr = info.wAttributes;
}

void
clrscr (void)
{
		DWORD written;
		int i;

		__fill_text_info();
		for (i = __CONIO_TOP; i < __CONIO_TOP + __text_info.screenheight; i++) {
			FillConsoleOutputAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
				__FOREGROUND + (__BACKGROUND << 4), __text_info.screenwidth,
				(COORD) {__CONIO_LEFT, i},
				&written);
			FillConsoleOutputCharacter (GetStdHandle(STD_OUTPUT_HANDLE), ' ',
				__text_info.screenwidth,
				(COORD) {__CONIO_LEFT, i},
				&written);
		}
		gotoxy (1, 1);
}


void
clreol (void)
{
		COORD coord;
		DWORD written;

		__fill_text_info();
		coord.X = __CONIO_LEFT + __text_info.curx - 1;
		coord.Y = __CONIO_TOP  + __text_info.cury - 1;

		FillConsoleOutputCharacter (GetStdHandle (STD_OUTPUT_HANDLE),
			' ', __text_info.screenwidth - __text_info.curx + 1, coord, &written);
		gotoxy (__text_info.curx, __text_info.cury);
}


void
delline (void)
{
		COORD coord;
		SMALL_RECT rect;
		CHAR_INFO fillchar;

		__fill_text_info();
		coord.X = __CONIO_LEFT;
		coord.Y = __CONIO_TOP + __text_info.cury - 1;
		rect.Left = __CONIO_LEFT;
		rect.Top = __CONIO_TOP + __text_info.cury;
		rect.Right = __CONIO_LEFT + __text_info.screenwidth - 1;
		rect.Bottom = __CONIO_TOP + __text_info.screenheight - 1;
		fillchar.Attributes = __FOREGROUND + (__BACKGROUND << 4);
#ifdef UNICODE
		fillchar.Char.UnicodeChar = L' ';
		ScrollConsoleScreenBufferW (GetStdHandle (STD_OUTPUT_HANDLE),
			&rect, NULL, coord, &fillchar);
#else
		fillchar.Char.AsciiChar = ' ';
		ScrollConsoleScreenBufferA (GetStdHandle (STD_OUTPUT_HANDLE),
			&rect, NULL, coord, &fillchar);
#endif


		gotoxy (__text_info.curx, __text_info.cury);
}

void
insline (void)
{
		COORD coord;
		SMALL_RECT rect;
		CHAR_INFO fillchar;

		__fill_text_info();
		coord.X = __CONIO_LEFT;
		coord.Y = __CONIO_TOP + __text_info.cury;
		rect.Left = __CONIO_LEFT;
		rect.Top = __CONIO_TOP + __text_info.cury - 1;
		rect.Right = __CONIO_LEFT + __text_info.screenwidth - 1;
		rect.Bottom = __CONIO_TOP + __text_info.screenheight - 2;
		fillchar.Attributes = __FOREGROUND + (__BACKGROUND << 4);
#ifdef UNICODE
		fillchar.Char.UnicodeChar = L' ';
		ScrollConsoleScreenBufferW (GetStdHandle (STD_OUTPUT_HANDLE),
			&rect, NULL, coord, &fillchar);
#else
		fillchar.Char.AsciiChar = ' ';
		ScrollConsoleScreenBufferA (GetStdHandle (STD_OUTPUT_HANDLE),
			&rect, NULL, coord, &fillchar);
#endif

		gotoxy (__text_info.curx, __text_info.cury);
}

void
movetext (int left, int top, int right, int bottom, int destleft, int desttop)
{
		struct char_info * buffer;

		buffer = malloc ((right - left + 1) * (bottom - top + 1) * sizeof(struct char_info));
		gettext (left, top, right, bottom, buffer);
		puttext (destleft, desttop, destleft + right - left, desttop + bottom - top, buffer);
		free(buffer);
}

#define __CALC_POS(i, j) (i * size.X + j)

void
_conio_gettext (int left, int top, int right, int bottom,
	struct char_info * buf)
{
		int i, j, n;
		SMALL_RECT r;
		CHAR_INFO* buffer;
		COORD size;
		
		__fill_text_info();
		r = (SMALL_RECT) {__CONIO_LEFT + left - 1, __CONIO_TOP + top - 1,
			__CONIO_LEFT + right - 1, __CONIO_TOP + bottom - 1};
		size.X = right - left + 1;
		size.Y = bottom - top + 1;
		buffer = malloc (size.X * size.Y * sizeof(CHAR_INFO));

		ReadConsoleOutput (GetStdHandle (STD_OUTPUT_HANDLE),
			(PCHAR_INFO) buffer, size, (COORD) {0, 0}, &r);

		for (i = n = 0; i < size.Y; i++)
		for (j = 0; j < size.X; j++)
		{
#ifdef UNICODE
				buf[n].letter = buffer[__CALC_POS(i, j)].Char.UnicodeChar;
#else
				buf[n].letter = buffer[__CALC_POS(i, j)].Char.AsciiChar;
#endif
				buf[n].attr = buffer[__CALC_POS(i, j)].Attributes;
				n++;
		}
		free (buffer);
}

void
puttext (int left, int top, int right, int bottom, struct char_info * buf)
{ 
		int i, j, n;
		SMALL_RECT r;
		CHAR_INFO* buffer;
		COORD size;

		__fill_text_info();
		r = (SMALL_RECT) {__CONIO_LEFT + left - 1, __CONIO_TOP + top - 1,
			__CONIO_LEFT + right - 1, __CONIO_TOP + bottom - 1};
		size.X = right - left + 1;
		size.Y = bottom - top + 1;
		buffer = malloc (size.X * size.Y * sizeof(CHAR_INFO));

		for (i = n = 0; i < size.Y; i++)
		for (j = 0; j < size.X; j++)
		{
#ifdef UNICODE
				buffer[__CALC_POS(i, j)].Char.UnicodeChar = buf[n].letter;
#else
				buffer[__CALC_POS(i, j)].Char.AsciiChar = buf[n].letter;
#endif
				buffer[__CALC_POS(i, j)].Attributes = buf[n].attr;
				n++;
		}

		WriteConsoleOutput (GetStdHandle (STD_OUTPUT_HANDLE),
			buffer, size, (COORD) {0, 0}, &r);
		free (buffer);
}

void
gotoxy(int x, int y)
{
	COORD c;

	c.X = __CONIO_LEFT + x - 1;
	c.Y = __CONIO_TOP  + y - 1;
	SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void
cputsxy (int x, int y, char * str)
{
		gotoxy (x, y);
		cputs (str);
}

void
putchxy (int x, int y, char ch)
{
		gotoxy (x, y);
		putch (ch);
}

void
_setcursortype (int type)
{
		CONSOLE_CURSOR_INFO Info;

		if (type == 0) {
				Info.bVisible = FALSE;
		} else {
			Info.dwSize = type;
			Info.bVisible = TRUE;
		}
		SetConsoleCursorInfo (GetStdHandle (STD_OUTPUT_HANDLE),
			&Info);
}


void
textattr (int _attr)
{
		__FOREGROUND = _attr & 0xF;
		__BACKGROUND = _attr >> 4;
		SetConsoleTextAttribute (GetStdHandle(STD_OUTPUT_HANDLE), _attr);
}

void
normvideo (void)
{
		textattr (__text_info.normattr);
}

void
textbackground (int color)
{
		__BACKGROUND = color;
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
			__FOREGROUND + (color << 4));
}


void
textcolor (int color)
{
		__FOREGROUND = color;
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),
			color + (__BACKGROUND << 4));
}


int
wherex (void)
{
		__fill_text_info();
		return __text_info.curx;
}


int
wherey (void)
{
		__fill_text_info();
		return __text_info.cury;
}

char *
getpass (const char * prompt, char * str)
{
		int maxlength = str[0];
		int length = 0;
		int ch = 0;
		int x, y;

		cputs(prompt);
		__fill_text_info();
		x = __text_info.curx;
		y = __text_info.cury;

		while (ch != '\r') {
				ch = getch();
				switch (ch) {
						case '\r' : /* enter */
								break;
						case '\b' : /* backspace */
								if (length > 0) putchxy (x + --length, y, ' ');
								gotoxy (x + length, y);
								break;
						default:
								if (length < maxlength) {
										putchxy (x + length, y, '*');
										str[2 + length++] = ch;
								}
				}
		}
		
		str[1] = length;
		str[2 + length] = '\0';
		return &str[2];
}

void
highvideo (void)
{
		if (__FOREGROUND < DARKGRAY) textcolor(__FOREGROUND + 8);
}

void
lowvideo (void)
{
		if (__FOREGROUND > LIGHTGRAY) textcolor(__FOREGROUND - 8);
}

#ifdef __cplusplus
}
#endif


/***************************************************************************************************************************************************/

/* Fin de la declaration de la bibliotheque conio */

/***************************************************************************************************************************************************/


	/** Prototypes des fonctions **/
	void print_dash (int num);
	void Match_p2 (int *Team1 , int *Team2 , int *Winner , Typevect_V32Tisiii *Tab , int *Score);
	void Simuler_match_p2 (int *Team1 , int *Team2 , int *Winner , Typevect_V32Tisiii *Tab , int *Choice);
	void Empilage_arbre (Pointeur_ATii *Arbre , Pointeur_PATii *P);
	void Remplissage_8eme (Pointeur_PATii *P , Typevect_V8i *First , Typevect_V8i *Second);
	void Simuler_phase2 (Pointeur_PATii *Pile_parcours , Typevect_V32Tisiii *Table , int *Choice);
	void Arbre_phase2 (Pointeur_ATii *Arbre);
	void Creer_arb_p2 (Pointeur_ATii *Arbre , int *Limit);
	int  Indice_chaine (Typevect_V198s *Tab , string255 *V) ;
	int  Indice_id (Typevect_V32Tisiii *Tab , int *V) ;
	string255  Id_name (Typevect_V32Tisiii *Tab , int *Id) ;
	void Fill_wc_22 (Typevect_V32i *Tab);
	void Fill_participants (Typevect_V32i *Equip , Typevect_V198s *Tableau_fifa , Typevect_V198s *Tableau_fav , Typevect_V32Tisiii *Tableau_equip);
	void Create_groups (Typevect_V32Tisiii *T_equipe , Typevect_V8Tiiii *T_groupe);
	void Tab_liste_matches (Typevect_V8Tiiii *Tab_groupe , Typevect_V8LTii *Tab_match);
	void Match_nul_p1 (int *Team1 , int *Team2 , Typevect_V32Tisiii *Tab , int *Won);
	void Match_won_p1 (int *Team , Typevect_V32Tisiii *Tab , int *Won);
	void Simuler_match_p1 (int *Team1 , int *Team2 , Typevect_V32Tisiii *Tab , int *Won , int *Choice);
	void Simuler_phase1 (Typevect_V32Tisiii *Tab_equipes , Typevect_V8LTii *Tab_matches , int *Choice , Typevect_V8i *Tab_1st , Typevect_V8i *Tab_2nd);
	void Qualifies (Typevect_V8i *First , Typevect_V8i *Second , Typevect_V32Tisiii *Table);
	void Tri_pt_w (Typevect_V4i *Pt , Typevect_V4i *W);
	void Group_winners (Typevect_V8Tiiii *Tab_groupes , Typevect_V32Tisiii *Tab_participants , Typevect_V8i *First , Typevect_V8i *Second);
	void Aff_eq_fifa1 (Typevect_V198s *Tab);
	void Aff_eq_fifa2 (Typevect_V198s *Tab);
	void Aff_eq_fifa3 (Typevect_V198s *Tab);
	void Aff_eq_fifa4 (Typevect_V198s *Tab);
	void Aff_eq_fifa5 (Typevect_V198s *Tab);
	void Aff_eq_fav1 (Typevect_V198s *Tab);
	void Aff_eq_fav2 (Typevect_V198s *Tab);
	void Aff_eq_fav3 (Typevect_V198s *Tab);
	void Aff_eq_fav4 (Typevect_V198s *Tab);
	void Aff_eq_fav5 (Typevect_V198s *Tab);

	/***************************************************    PHASE 2 ***************************************************/
	/*****************************************************************************************************************/
	void Match_p2 (int *Team1 , int *Team2 , int *Winner , Typevect_V32Tisiii *Tab , int *Score)
		{
			/** Variables locales **/
			int E1;
			int E2;

			/** Corps du module **/
		 E1  =  Indice_id ( & *Tab , & *Team1 ) ;
		 E2  =  Indice_id ( & *Tab , & *Team2 ) ;
		/* L'affectation consiste a ajouter a l'equipe gagnante le score du match ainsi 
			 que les points de la phase 2 de l'adversaire pour simuler le critere 4 */
		 *Score  =  *Score + Struct5_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  ) + Struct5_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  ) ;
		 if( *Team1 == *Winner) {
			 Aff_struct5_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  , *Score ) ;
			 }
		 else
			 {
			 Aff_struct5_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  , *Score ) ;
			
		 } ;
		
		}
	/*****************************************************************************************************************/
	void Simuler_match_p2 (int *Team1 , int *Team2 , int *Winner , Typevect_V32Tisiii *Tab , int *Choice)
		{
			/** Variables locales **/
			int Nombre1;
			int Nombre2;
			int E1;
			int E2;
			int _Px1;
			int _Px2;
			int _Px3;
			int _Px4;
			int _Px5;
			int _Px6;
			int _Px7;
			int _Px8;
			int _Px9;
			int _Px10;
			int _Px11;
			int _Px12;

			/** Corps du module **/
		 E1  =  Indice_id ( & *Tab , & *Team1 ) ;
		 E2  =  Indice_id ( & *Tab , & *Team2 ) ;
		 if( *Choice == 1) {
			 Nombre1  =  Aleanombre(10 ) ;
			 Nombre2  =  Aleanombre(10 ) ;
			 while( Nombre1 == Nombre2) {
				 Nombre1  =  Aleanombre(10 ) ;
				 Nombre2  =  Aleanombre(10 ) ;
				
			 } ;
			 if( Nombre1 > Nombre2) {
				 Match_p2 ( & *Team1 , & *Team2 , & *Team1 , & *Tab , & Nombre1 ) ;
				 *Winner  =  *Team1 ;
				 }
			 else
				 {
				 Match_p2 ( & *Team1 , & *Team2 , & *Team2 , & *Tab , & Nombre2 ) ;
				 *Winner  =  *Team2 ;
				
			 } ;
			 }
		 else
			 {
			 if( *Choice == 2) {
				 Nombre1  =  Struct3_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  ) ;
				 Nombre2  =  Struct3_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  ) ;
				 if( Nombre1 < Nombre2) {
					 _Px1 =  Mod ( Nombre1 , 10 ) ;
					 Match_p2 ( & *Team1 , & *Team2 , & *Team1 , & *Tab , &_Px1) ;
					 *Winner  =  *Team1 ;
					 }
				 else
					 {
					 _Px2 =  Mod ( Nombre2 , 10 ) ;
					 Match_p2 ( & *Team1 , & *Team2 , & *Team2 , & *Tab , &_Px2) ;
					 *Winner  =  *Team2 ;
					
				 } ;
				 }
			 else
				 {
				 if( *Choice == 3) {
					 Nombre1  =  Struct4_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  ) ;
					 Nombre2  =  Struct4_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  ) ;
					 while( Nombre1 == Nombre2) {
						 Nombre1  =  Nombre1 + Aleanombre(5 ) ;
						 Nombre1  =  Nombre1 + Aleanombre(5 ) ;
						
					 } ;
					 if( Nombre1 > Nombre2) {
						 _Px3 =  Mod ( Nombre1 , 10 ) ;
						 Match_p2 ( & *Team1 , & *Team2 , & *Team1 , & *Tab , &_Px3) ;
						 *Winner  =  *Team1 ;
						 }
					 else
						 {
						 _Px4 =  Mod ( Nombre2 , 10 ) ;
						 Match_p2 ( & *Team1 , & *Team2 , & *Team2 , & *Tab , &_Px4) ;
						 *Winner  =  *Team2 ;
						
					 } ;
					 }
				 else
					 {
					 if( *Choice == 4) {
						 Nombre1  =  Struct4_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  ) + Struct5_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  ) ;
						 Nombre2  =  Struct4_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  ) + Struct5_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  ) ;
						 while( Nombre1 == Nombre2) {
							 Nombre1  =  Nombre1 + Aleanombre(5 ) ;
							 Nombre1  =  Nombre1 + Aleanombre(5 ) ;
							
						 } ;
						 if( Nombre1 > Nombre2) {
							 _Px5 =  Mod ( Nombre1 , 10 ) ;
							 Match_p2 ( & *Team1 , & *Team2 , & *Team1 , & *Tab , &_Px5) ;
							 *Winner  =  *Team1 ;
							 }
						 else
							 {
							 _Px6 =  Mod ( Nombre2 , 10 ) ;
							 Match_p2 ( & *Team1 , & *Team2 , & *Team2 , & *Tab , &_Px6) ;
							 *Winner  =  *Team2 ;
							
						 } ;
						 }
					 else
						 {
						 if( *Choice == 5) {
							 Nombre1  =  Struct4_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  ) + 200 - Struct3_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  ) ;
							 Nombre2  =  Struct4_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  ) + 200 - Struct3_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  ) ;
							 while( Nombre1 == Nombre2) {
								 Nombre1  =  Nombre1 + Aleanombre(5 ) ;
								 Nombre1  =  Nombre1 + Aleanombre(5 ) ;
								
							 } ;
							 if( Nombre1 > Nombre2) {
								 _Px7 =  Mod ( Nombre1 , 10 ) ;
								 Match_p2 ( & *Team1 , & *Team2 , & *Team1 , & *Tab , &_Px7) ;
								 *Winner  =  *Team1 ;
								 }
							 else
								 {
								 _Px8 =  Mod ( Nombre2 , 10 ) ;
								 Match_p2 ( & *Team1 , & *Team2 , & *Team2 , & *Tab , &_Px8) ;
								 *Winner  =  *Team2 ;
								
							 } ;
							 }
						 else
							 {
							 if( *Choice == 6) {
								 Nombre1  =  Struct4_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  ) + Struct5_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  ) ;
								 Nombre1  =  Nombre1 + 200 - Struct3_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  ) ;
								 Nombre2  =  Struct4_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  ) + Struct5_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  ) ;
								 Nombre2  =  Nombre2 + 200 - Struct3_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  ) ;
								 while( Nombre1 == Nombre2) {
									 Nombre1  =  Nombre1 + Aleanombre(5 ) ;
									 Nombre1  =  Nombre1 + Aleanombre(5 ) ;
									
								 } ;
								 if( Nombre1 > Nombre2) {
									 _Px9 =  Mod ( Nombre1 , 10 ) ;
									 Match_p2 ( & *Team1 , & *Team2 , & *Team1 , & *Tab , &_Px9) ;
									 *Winner  =  *Team1 ;
									 }
								 else
									 {
									 _Px10 =  Mod ( Nombre2 , 10 ) ;
									 Match_p2 ( & *Team1 , & *Team2 , & *Team2 , & *Tab , &_Px10) ;
									 *Winner  =  *Team2 ;
									
								 } ;
								 }
							 else
								 {
								 if( *Choice == 7) {
									 if( *Team1 < *Team2) {
										 _Px11 =  Mod ( *Team1 , 10 ) ;
										 Match_p2 ( & *Team1 , & *Team2 , & *Team1 , & *Tab , &_Px11) ;
										 *Winner  =  *Team1 ;
										 }
									 else
										 {
										 _Px12 =  Mod ( *Team2 , 10 ) ;
										 Match_p2 ( & *Team1 , & *Team2 , & *Team2 , & *Tab , &_Px12) ;
										 *Winner  =  *Team2 ;
										
									 } ;
									
								 }
							 }
						 }
					 }
				 }
			 }
		 }
		}
	/*****************************************************************************************************************/
	void Empilage_arbre (Pointeur_ATii *Arbre , Pointeur_PATii *P)
		{
			/** Variables locales **/
			Pointeur_ATii Temp;
			Pointeur_FATii F;

			/** Corps du module **/
		 Creerfile_FATii (& F ) ;
		 Creerpile_PATii (& *P ) ;
		 Enfiler_FATii ( F , *Arbre ) ;
		 while( ! Filevide_FATii ( F )) {
			 Defiler_FATii ( F , &Temp ) ;
			 Empiler_PATii (& *P , Temp ) ;
			 if( Fg_ATii ( Temp ) != NULL) {
				 Enfiler_FATii ( F , Fg_ATii ( Temp ) ) ;
				
			 } ;
			 if( Fd_ATii ( Temp ) != NULL) {
				 Enfiler_FATii ( F , Fd_ATii ( Temp ) ) ;
				
			 } ;
			
		 } ;
		
		}
	/*****************************************************************************************************************/
	void Remplissage_8eme (Pointeur_PATii *P , Typevect_V8i *First , Typevect_V8i *Second)
		{
			/** Variables locales **/
			Pointeur_PATii Pt;
			Pointeur_ATii T;
			int I;
			int K;
			Typestr_Tii Bet;

			/** Corps du module **/
		 Bet = malloc(sizeof(Type_Tii));
		 for( I  =  1 ;I <=  8 ; ++I){
			 Depiler_PATii (& *P , &T ) ;
			 Empiler_PATii (& Pt , T ) ;
			
		 } ;
		 K  =  1 ;
		 for( I  =  1 ;I <=  8 ; ++I){
			 Depiler_PATii (& Pt , &T ) ;
			 Aff_struct1_Tii ( Bet  , Element_V8i ( *First , I   ) ) ;
			 Aff_struct2_Tii ( Bet  , Element_V8i ( *Second , I + K   ) ) ;
			 Aff_info_ATii ( T , Bet ) ;
			 K  =  K * ( - 1 ) ;
			 Empiler_PATii (& *P , T ) ;
			
		 } ;
		
		}
	/*****************************************************************************************************************/
	void Simuler_phase2 (Pointeur_PATii *Pile_parcours , Typevect_V32Tisiii *Table , int *Choice)
		{
			/** Variables locales **/
			Pointeur_ATii Temp;
			int I;
			int Winner;
			int Team1;
			int Team2;
			Typestr_Tii Str;
				gotoxy(58,2);
			
				printf("Simulation de la phase 1");

				gotoxy(wherex(),4);
			/** Corps du module **/
		 Str = malloc(sizeof(Type_Tii));
		 I  =  0 ;
		 while( I < 8)
		 {
			 Depiler_PATii (& *Pile_parcours , &Temp ) ;
			 Team1  =  Struct1_Tii ( Info_ATii ( Temp )  ) ;
			 Team2  =  Struct2_Tii ( Info_ATii ( Temp )  ) ;
			 Simuler_match_p2 ( & Team1 , & Team2 , & Winner , & *Table , & *Choice ) ;
			 
			 gotoxy(5,wherey());
			 printf ( " %s ", Id_name(&*Table,&Team1) );
			 print_dash( 20 - strlen(Id_name(&*Table,&Team1) ) );
			 gotoxy(5,wherey()+2);
			 printf ( " %s ", Id_name(&*Table,&Team2) ) ;
			 print_dash( 20 - strlen(Id_name(&*Table,&Team2) ) );
			 gotoxy(wherex(),wherey()+3);

			 Aff_struct1_Tii ( Str  , Winner ) ;
			 Depiler_PATii (& *Pile_parcours , &Temp ) ;
			 Team1  =  Struct1_Tii ( Info_ATii ( Temp )  ) ;
			 Team2  =  Struct2_Tii ( Info_ATii ( Temp )  ) ;
			 Simuler_match_p2 ( & Team1 , & Team2 , & Winner , & *Table , & *Choice ) ;
			 gotoxy(5,wherey());
			 printf ( " %s ", Id_name(&*Table,&Team1) );
			 print_dash( 20 - strlen(Id_name(&*Table,&Team1) ) );
			 gotoxy(5,wherey()+2);
			 printf ( " %s ", Id_name(&*Table,&Team2) ) ;
			 print_dash( 20 - strlen(Id_name(&*Table,&Team2) ) );
			 Aff_struct2_Tii ( Str  , Winner ) ;
			 Temp  =  Pere_ATii ( Temp ) ;
			 Aff_info_ATii ( Temp , Str ) ;
			 I  =  I + 2 ;
			 if (I != 7)
			 {gotoxy(wherex(),wherey()+3);}
			
		 } ;
		 
		 gotoxy(30,5); 
		 gotoxy(27,wherey());
		 print_dash(3);
		 gotoxy(27,wherey()+5);
		 print_dash(3);
		 gotoxy(27,wherey()+5);
		 print_dash(3);
		 gotoxy(27,wherey()+5);
		 print_dash(3);
		 gotoxy(27,wherey()+5);
		 print_dash(3);
		 gotoxy(27,wherey()+5);
		 print_dash(3);
		 gotoxy(27,wherey()+5);
		 print_dash(3);
		 gotoxy(27,wherey()+5);
		 print_dash(3);
		 
			
		 gotoxy(95,40);

		 sleep(1);

		 gotoxy(1,1);
		 
		 while( I < 12)
		 {
			 Depiler_PATii (& *Pile_parcours , &Temp ) ;
			 Team1  =  Struct1_Tii ( Info_ATii ( Temp )  ) ;
			 Team2  =  Struct2_Tii ( Info_ATii ( Temp )  ) ;
			 Simuler_match_p2 ( & Team1 , & Team2 , & Winner , & *Table , & *Choice ) ;
			 
			 gotoxy(30,wherey()+5);
			 if (I == 8)
			 {
				gotoxy(wherex(),wherey()-1);
			 }
			 printf ( " %s ", Id_name(&*Table,&Team1) );
			 print_dash (26 - strlen(Id_name(&*Table,&Team1)));
			 gotoxy(30,wherey()+5);
			 printf ( " %s ", Id_name(&*Table,&Team2) ) ;
			 print_dash (26 - strlen(Id_name(&*Table,&Team2)));
			 


			 Aff_struct1_Tii ( Str  , Winner ) ;
			 Depiler_PATii (& *Pile_parcours , &Temp ) ;
			 Team1  =  Struct1_Tii ( Info_ATii ( Temp )  ) ;
			 Team2  =  Struct2_Tii ( Info_ATii ( Temp )  ) ;
			 Simuler_match_p2 ( & Team1 , & Team2 , & Winner , & *Table , & *Choice ) ;
			 gotoxy(30,wherey()+5);
			 printf ( " %s ", Id_name(&*Table,&Team1) );
			 print_dash (26 - strlen(Id_name(&*Table,&Team1)));
			 gotoxy(30,wherey()+5);
			 printf ( " %s ", Id_name(&*Table,&Team2) ) ;
			 print_dash (26 - strlen(Id_name(&*Table,&Team2)));
			 Aff_struct2_Tii ( Str  , Winner ) ;
			 Temp  =  Pere_ATii ( Temp ) ;
			 Aff_info_ATii ( Temp , Str ) ;
			 I  =  I + 2 ;
			
		 } ;
		 textcolor(BLUE);
		 gotoxy(57,6); 
		 printf("|");gotoxy(57,7); 
		 print_dash(3);
		 textcolor(BLUE);
		 gotoxy(57,8);printf("|"); 
		 gotoxy(57,9);printf("|"); 
		 textcolor(BLUE);
		 gotoxy(57,wherey()+7);printf("|");
		 gotoxy(57,wherey()+1);print_dash(3);
		 textcolor(BLUE);
		 gotoxy(57,wherey()+1);printf("|"); 
		 gotoxy(57,wherey()+1);printf("|"); 
		 
		 gotoxy(57,wherey()+7);printf("|");
		 gotoxy(57,wherey()+1);print_dash(3);
		 textcolor(BLUE);
		 gotoxy(57,wherey()+1);printf("|"); 
		 gotoxy(57,wherey()+1);printf("|"); 
		 gotoxy(57,wherey()+7);printf("|");
		 gotoxy(57,wherey()+1);print_dash(3);
		 textcolor(BLUE);
		 gotoxy(57,wherey()+1);printf("|"); 
		 gotoxy(57,wherey()+1);printf("|"); 

		 gotoxy(95,40);
		 sleep(1);
 
		 textcolor(WHITE);
		 gotoxy(1,1);
		 
		 while( I < 14)
		 {
			 Depiler_PATii (& *Pile_parcours , &Temp ) ;
			 Team1  =  Struct1_Tii ( Info_ATii ( Temp )  ) ;
			 Team2  =  Struct2_Tii ( Info_ATii ( Temp )  ) ;
			 Simuler_match_p2 ( & Team1 , & Team2 , & Winner , & *Table , & *Choice ) ;
			 
			 gotoxy(60,wherey()+10);
			 if (I == 12)
			 {
				gotoxy(wherex(),wherey()-4);
			 }
			 printf ( " %s ", Id_name(&*Table,&Team1) );
			 print_dash( 26 - strlen(Id_name(&*Table,&Team1)) );
			 gotoxy(60,wherey()+10);
			 printf ( " %s ", Id_name(&*Table,&Team2) ) ;
			 print_dash( 26 - strlen(Id_name(&*Table,&Team2)) );

			 


			 Aff_struct1_Tii ( Str  , Winner ) ;
			 Depiler_PATii (& *Pile_parcours , &Temp ) ;
			 Team1  =  Struct1_Tii ( Info_ATii ( Temp )  ) ;
			 Team2  =  Struct2_Tii ( Info_ATii ( Temp )  ) ;
			 Simuler_match_p2 ( & Team1 , & Team2 , & Winner , & *Table , & *Choice ) ;
			 gotoxy(60,wherey()+10);
			 printf ( " %s ", Id_name(&*Table,&Team1) );
			 print_dash( 26 - strlen(Id_name(&*Table,&Team1)) );
			 gotoxy(60,wherey()+10);
			 printf ( " %s ", Id_name(&*Table,&Team2) ) ;
			 print_dash( 26 - strlen(Id_name(&*Table,&Team2)) );
			 Aff_struct2_Tii ( Str  , Winner ) ;
			 Temp  =  Pere_ATii ( Temp ) ;
			 Aff_info_ATii ( Temp , Str ) ;
			 I  =  I + 2 ;
		 } ;
			textcolor(BLUE);
		 gotoxy(87,8);printf("|");
		 gotoxy(87,9);printf("|");
		 gotoxy(87,10);printf("|");
		 gotoxy(87,11);printf("|");
		 gotoxy(87,13);printf("|");
		 gotoxy(87,14);printf("|");
		 gotoxy(87,15);printf("|");
		 gotoxy(87,16);printf("|");
		 textcolor(WHITE);
		 gotoxy(87,12);print_dash(3);
		 textcolor(BLUE);
		 gotoxy(87,28);printf("|");
		 gotoxy(87,29);printf("|");
		 gotoxy(87,30);printf("|");
		 gotoxy(87,31);printf("|");
		 gotoxy(87,33);printf("|");
		 gotoxy(87,34);printf("|");
		 gotoxy(87,35);printf("|");
		 gotoxy(87,36);printf("|");
		 textcolor(WHITE);
		 gotoxy(87,32);print_dash(3);



		 gotoxy(95,40);
		 textcolor(BLUE);
		 sleep(1);
		 textcolor(WHITE);
		 gotoxy(1,1);     
		 
		 Depiler_PATii (& *Pile_parcours , &Temp ) ;
			Team1  =  Struct1_Tii ( Info_ATii ( Temp )  ) ;
			Team2  =  Struct2_Tii ( Info_ATii ( Temp )  ) ;
			Simuler_match_p2 ( & Team1 , & Team2 , & Winner , & *Table , & *Choice ) ;

			gotoxy(90,wherey()+11);
			printf ( " %s ", Id_name(&*Table,&Team1) );
			print_dash( 20 - strlen(Id_name(&*Table,&Team1)) );
			gotoxy(90,wherey()+20);
			printf ( " %s ", Id_name(&*Table,&Team2) ) ;
			print_dash( 20 - strlen(Id_name(&*Table,&Team2)) );

			textcolor(BLUE);
			gotoxy(111,13);
			printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);
			print_dash(3);
			textcolor(BLUE);
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			gotoxy(111,wherey()+1);printf("|");
			textcolor(WHITE);
			sleep(1);

			gotoxy(115,22);
			printf ( " %s", Id_name(&*Table,&Winner) ) ;

			sleep(3);
			clrscr();
			
			for ( int i = 1 ; i<=45 ; i++ )
			{
					gotoxy(i,i);
					textcolor(RED);
					printf("\\\\\\\\\\");
					gotoxy(140-5-i,i);
					textcolor(RED);  
					printf("/////");
					gotoxy(140-5-i,46-i);
					textcolor(YELLOW);
					printf("\\\\\\\\\\");
					gotoxy(i,46-i);
					textcolor(YELLOW);
					printf("/////");  
			}
			int k = 52 ;
			int y = 2;
			textbackground(BLUE);
			gotoxy(k+6,y);printf("  ");
			gotoxy(k+6,y+1);printf("  ");
			gotoxy(k+6,y+2);printf("  ");
			gotoxy(k+6,y+3);printf("  ");
			gotoxy(k+6,y+4);printf("  ");
			gotoxy(k+6,y+5);printf("            ");
			gotoxy(k+5+6,y+3);printf("  ");
			gotoxy(k+5+6,y+4);printf("  ");
			gotoxy(k+6,y);printf("  ");
			gotoxy(k+6+10,y);printf("  ");
			gotoxy(k+6+10,y+1);printf("  ");
			gotoxy(k+6+10,y+2);printf("  ");
			gotoxy(k+6+10,y+3);printf("  ");
			gotoxy(k+6+10,y+4);printf("  ");
			gotoxy(k+6+14,y);printf("          ");
			gotoxy(k+6+14,y+1);printf("  ");
			gotoxy(k+6+14,y+2);printf("  ");
			gotoxy(k+6+14,y+3);printf("  ");
			gotoxy(k+6+14,y+4);printf("  ");
			gotoxy(k+6+14,y+5);printf("          ");
			y = 10;
			k = 53 ;
			gotoxy(k+6,y);printf("          ");
			gotoxy(k+14,y+1);printf("  ");
			gotoxy(k+14,y+2);printf("  ");
			gotoxy(k+6,y+3);printf("          ");
			gotoxy(k+6,y+4);printf("  ");
			gotoxy(k+6,y+5);printf("  ");
			gotoxy(k+6,y+6);printf("          ");
			k = 66;
			gotoxy(k+6,y);printf("          ");
			gotoxy(k+14,y+1);printf("  ");
			gotoxy(k+14,y+2);printf("  ");
			gotoxy(k+6,y+3);printf("          ");
			gotoxy(k+6,y+4);printf("  ");
			gotoxy(k+6,y+5);printf("  ");
			gotoxy(k+6,y+6);printf("          ");

			
			
			textbackground(BLACK);
			gotoxy(40,18);
			textcolor(BLUE);
			int x = 140 - strlen(Id_name(&*Table,&Winner));
			x = x / 2 ;
			gotoxy(x,22);
			printf("%s", Id_name(&*Table,&Winner));
			textcolor(WHITE);
			gotoxy(58,25);
			printf("Gagne La Coupe du Monde 2022");
			sleep(4);
			getch();
		}
	/*****************************************************************************************************************/
	void Arbre_phase2 (Pointeur_ATii *Arbre)
		{
			/** Variables locales **/
			int _Px1;

			/** Corps du module **/
		 Creernoeud_ATii (& *Arbre ) ;
		 _Px1 =  0 ;
		 Creer_arb_p2 ( & *Arbre , &_Px1) ;
		
		}
	/*****************************************************************************************************************/
	void Creer_arb_p2 (Pointeur_ATii *Arbre , int *Limit)
		{
			/** Variables locales **/
			Pointeur_ATii D;
			Pointeur_ATii G;
			Pointeur_ATii _Px1;
			int _Px2;
			Pointeur_ATii _Px3;
			int _Px4;

			/** Corps du module **/
		 if( *Limit <= 2) {
			 Creernoeud_ATii (& D ) ;
			 Creernoeud_ATii (& G ) ;
			 Aff_fd_ATii ( *Arbre , D ) ;
			 Aff_fg_ATii ( *Arbre , G ) ;
			 Aff_pere_ATii ( D , *Arbre ) ;
			 Aff_pere_ATii ( G , *Arbre ) ;
			 _Px1 =  Fd_ATii ( *Arbre ) ;
			 _Px2 =  *Limit + 1 ;
			 Creer_arb_p2 ( &_Px1, &_Px2) ;
			 _Px3 =  Fg_ATii ( *Arbre ) ;
			 _Px4 =  *Limit + 1 ;
			 Creer_arb_p2 ( &_Px3, &_Px4) ;
			
		 } ;
		
		}
	/*********************  FIN PHASE 2 *********************/
	/*****************************************************************************************************************/
	/***************************************************    PHASE 1 ***************************************************/
	/*****************************************************************************************************************/
	int  Indice_chaine (Typevect_V198s *Tab , string255 *V) 
		{
			/** Variables locales **/
			int  Indice_chaine2 ;
			int I;
			int N;
			bool Found;

			/** Corps du module **/
		 Found  =  False ;
		 I  =  1 ;
		 while( ! Found) {
			 if( (strcmp( Element_V198s ( *Tab , I   ), *V) == 0  )) {
				 Found  =  True ;
				 N  =  I ;
				
			 } ;
			 I  =  I + 1 ;
			
		 } ;
		 Indice_chaine2  =  N ;
		
		 return Indice_chaine2 ;
		}
	/*****************************************************************************************************************/
	int  Indice_id (Typevect_V32Tisiii *Tab , int *V) 
		{
			/** Variables locales **/
			int  Indice_id2 ;
			int I;
			int N;
			bool Found;

			/** Corps du module **/
		 Found  =  False ;
		 I  =  1 ;
		 while( ! Found) {
			 if( ( Struct1_Tisiii ( Element_V32Tisiii ( *Tab , I   )  ) == *V )) {
				 Found  =  True ;
				 N  =  I ;
				
			 } ;
			 I  =  I + 1 ;
			
		 } ;
		 Indice_id2  =  N ;
		
		 return Indice_id2 ;
		}
	/*****************************************************************************************************************/
	string255  Id_name (Typevect_V32Tisiii *Tab , int *Id) 
		{
			/** Variables locales **/
			string255  Id_name2 ;
			int I;
			bool Trouve;

			/** Corps du module **/
		 Id_name2 = malloc(255 * sizeof(char));
		 Trouve  =  False ;
		 I  =  1 ;
		 while( ( ( I < 33 ) && ( ! Trouve ) )) {
			 if( ( *Id == Struct1_Tisiii ( Element_V32Tisiii ( *Tab , I   )  ) )) {
				 Trouve  =  True ;
				 }
			 else
				 {
				 I  =  I + 1 ;
				
			 }
		 } ;
		 if( Trouve) {
			 strcpy (Id_name2,   Struct2_Tisiii ( Element_V32Tisiii ( *Tab , I   )  )) ;
			 }
		 else
			 {
			 strcpy (Id_name2,   "") ;
			
		 }
		 return Id_name2 ;
		}
	/*****************************************************************************************************************/
	void Fill_wc_22 (Typevect_V32i *Tab)
		{

			/** Corps du module **/
		 Aff_element_V32i ( *Tab , 1   , 1 ) ;
		 Aff_element_V32i ( *Tab , 2   , 2 ) ;
		 Aff_element_V32i ( *Tab , 3   , 3 ) ;
		 Aff_element_V32i ( *Tab , 4   , 4 ) ;
		 Aff_element_V32i ( *Tab , 5   , 5 ) ;
		 Aff_element_V32i ( *Tab , 6   , 7 ) ;
		 Aff_element_V32i ( *Tab , 7   , 8 ) ;
		 Aff_element_V32i ( *Tab , 8   , 9 ) ;
		 Aff_element_V32i ( *Tab , 9   , 10 ) ;
		 Aff_element_V32i ( *Tab , 10   , 11 ) ;
		 Aff_element_V32i ( *Tab , 11   , 12 ) ;
		 Aff_element_V32i ( *Tab , 12   , 13 ) ;
		 Aff_element_V32i ( *Tab , 13   , 14 ) ;
		 Aff_element_V32i ( *Tab , 14   , 15 ) ;
		 Aff_element_V32i ( *Tab , 15   , 16 ) ;
		 Aff_element_V32i ( *Tab , 16   , 18 ) ;
		 Aff_element_V32i ( *Tab , 17   , 20 ) ;
		 Aff_element_V32i ( *Tab , 18   , 21 ) ;
		 Aff_element_V32i ( *Tab , 19   , 22 ) ;
		 Aff_element_V32i ( *Tab , 20   , 23 ) ;
		 Aff_element_V32i ( *Tab , 21   , 24 ) ;
		 Aff_element_V32i ( *Tab , 22   , 25 ) ;
		 Aff_element_V32i ( *Tab , 23   , 26 ) ;
		 Aff_element_V32i ( *Tab , 24   , 29 ) ;
		 Aff_element_V32i ( *Tab , 25   , 31 ) ;
		 Aff_element_V32i ( *Tab , 26   , 35 ) ;
		 Aff_element_V32i ( *Tab , 27   , 38 ) ;
		 Aff_element_V32i ( *Tab , 28   , 44 ) ;
		 Aff_element_V32i ( *Tab , 29   , 46 ) ;
		 Aff_element_V32i ( *Tab , 30   , 49 ) ;
		 Aff_element_V32i ( *Tab , 31   , 51 ) ;
		 Aff_element_V32i ( *Tab , 32   , 60 ) ;
		
		}
	/*****************************************************************************************************************/
	void Fill_participants (Typevect_V32i *Equip , Typevect_V198s *Tableau_fifa , Typevect_V198s *Tableau_fav , Typevect_V32Tisiii *Tableau_equip)
		{
			/** Variables locales **/
			int I;
			Typestr_Tisiii Equipe;
			string255 Theone;
			int Temp;
			string255 _Px1;

			/** Corps du module **/
		 Equipe = malloc(sizeof(Type_Tisiii));
		 Equipe->Champ2 = malloc(255 * sizeof(char));
		 Theone = malloc(255 * sizeof(char));
		 _Px1 = malloc(255 * sizeof(char));
		 for( I  =  1 ;I <=  32 ; ++I){
			 strcpy(_Px1,  Element_V198s ( *Tableau_fifa , Element_V32i ( *Equip , I   )   ) );
			 Temp  =  Indice_chaine ( & *Tableau_fav , &_Px1) ;
			 Aff_struct1_Tisiii ( Equipe  , Element_V32i ( *Equip , I   ) ) ;
			 Aff_struct2_Tisiii ( Equipe  , Element_V198s ( *Tableau_fifa , Element_V32i ( *Equip , I   )   ) ) ;
			 Aff_struct3_Tisiii ( Equipe  , Temp ) ;
			 Aff_struct4_Tisiii ( Equipe  , 0 ) ;
			 Aff_struct5_Tisiii ( Equipe  , 0 ) ;
			 Aff_element_V32Tisiii ( *Tableau_equip , I   , Equipe ) ;
			
		 }
		}
	/*****************************************************************************************************************/
	void Create_groups (Typevect_V32Tisiii *T_equipe , Typevect_V8Tiiii *T_groupe)
		{
			/** Variables locales **/
			int I;
			int K;
			int L;
			Typestr_Tiiii Val;

			/** Corps du module **/
		 Val = malloc(sizeof(Type_Tiiii));
		 K  =  0 ;
		 L  =  0 ;
		 I  =  1 ;
		 while( I < 9)  {
			 L  =  Struct1_Tisiii ( Element_V32Tisiii ( *T_equipe , I   )  ) ;
			 Aff_struct1_Tiiii ( Val  , L ) ;
			 L  =  Struct1_Tisiii ( Element_V32Tisiii ( *T_equipe , 8 + I   )  ) ;
			 Aff_struct2_Tiiii ( Val  , L ) ;
			 L  =  Struct1_Tisiii ( Element_V32Tisiii ( *T_equipe , 16 + I   )  ) ;
			 Aff_struct3_Tiiii ( Val  , L ) ;
			 L  =  Struct1_Tisiii ( Element_V32Tisiii ( *T_equipe , 24 + I   )  ) ;
			 Aff_struct4_Tiiii ( Val  , L ) ;
			 Aff_element_V8Tiiii ( *T_groupe , I   , Val ) ;
			 I  =  I + 1 ;
			
		 } ;
		
		}
	/*****************************************************************************************************************/
	void Tab_liste_matches (Typevect_V8Tiiii *Tab_groupe , Typevect_V8LTii *Tab_match)
		{
			/** Variables locales **/
			int I;
			int J;
			Pointeur_LTii P;
			Pointeur_LTii Q;
			Pointeur_LTii L;
			Typestr_Tii Match;

			/** Corps du module **/
		 Match = malloc(sizeof(Type_Tii));
		 for( I  =  1 ;I <=  8 ; ++I){
			 Allouer_LTii (& P ) ;
			 Aff_element_V8LTii ( *Tab_match , I   , P ) ;
			 Aff_struct1_Tii ( Match  , Struct1_Tiiii ( Element_V8Tiiii ( *Tab_groupe , I   )  ) ) ;
			 Aff_struct2_Tii ( Match  , Struct2_Tiiii ( Element_V8Tiiii ( *Tab_groupe , I   )  ) ) ;
			 Aff_val_LTii ( P , Match ) ;
			 Allouer_LTii (& Q ) ;
			 Aff_adr_LTii ( P , Q ) ;
			 Aff_struct1_Tii ( Match  , Struct3_Tiiii ( Element_V8Tiiii ( *Tab_groupe , I   )  ) ) ;
			 Aff_struct2_Tii ( Match  , Struct4_Tiiii ( Element_V8Tiiii ( *Tab_groupe , I   )  ) ) ;
			 Aff_val_LTii ( Q , Match ) ;
			 Allouer_LTii (& P ) ;
			 Aff_adr_LTii ( Q , P ) ;
			 Aff_struct1_Tii ( Match  , Struct1_Tiiii ( Element_V8Tiiii ( *Tab_groupe , I   )  ) ) ;
			 Aff_struct2_Tii ( Match  , Struct3_Tiiii ( Element_V8Tiiii ( *Tab_groupe , I   )  ) ) ;
			 Aff_val_LTii ( P , Match ) ;
			 Allouer_LTii (& Q ) ;
			 Aff_adr_LTii ( P , Q ) ;
			 Aff_struct1_Tii ( Match  , Struct2_Tiiii ( Element_V8Tiiii ( *Tab_groupe , I   )  ) ) ;
			 Aff_struct2_Tii ( Match  , Struct4_Tiiii ( Element_V8Tiiii ( *Tab_groupe , I   )  ) ) ;
			 Aff_val_LTii ( Q , Match ) ;
			 Allouer_LTii (& P ) ;
			 Aff_adr_LTii ( Q , P ) ;
			 Aff_struct1_Tii ( Match  , Struct1_Tiiii ( Element_V8Tiiii ( *Tab_groupe , I   )  ) ) ;
			 Aff_struct2_Tii ( Match  , Struct4_Tiiii ( Element_V8Tiiii ( *Tab_groupe , I   )  ) ) ;
			 Aff_val_LTii ( P , Match ) ;
			 Allouer_LTii (& Q ) ;
			 Aff_adr_LTii ( P , Q ) ;
			 Aff_struct1_Tii ( Match  , Struct2_Tiiii ( Element_V8Tiiii ( *Tab_groupe , I   )  ) ) ;
			 Aff_struct2_Tii ( Match  , Struct3_Tiiii ( Element_V8Tiiii ( *Tab_groupe , I   )  ) ) ;
			 Aff_val_LTii ( Q , Match ) ;
			 Aff_adr_LTii ( Q , NULL ) ;
			
		 } ;
		
		}
	/*****************************************************************************************************************/
	void Match_nul_p1 (int *Team1 , int *Team2 , Typevect_V32Tisiii *Tab , int *Won)
		{
			/** Variables locales **/
			int E1;
			int E2;

			/** Corps du module **/
		 E1  =  Indice_id ( & *Tab , & *Team1 ) ;
		 E2  =  Indice_id ( & *Tab , & *Team2 ) ;
		 *Won  =  0 ;
		 Aff_struct4_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  , Struct4_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  ) + 1 ) ;
		 Aff_struct4_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  , Struct4_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  ) + 1 ) ;
		
		}
	/*****************************************************************************************************************/
	void Match_won_p1 (int *Team , Typevect_V32Tisiii *Tab , int *Won)
		{
			/** Variables locales **/
			int E;

			/** Corps du module **/
		 E  =  Indice_id ( Tab , Team ) ;
		 *Won  =  *Team ;
		 Aff_struct4_Tisiii ( Element_V32Tisiii ( *Tab , E   )  , Struct4_Tisiii ( Element_V32Tisiii ( *Tab , E   )  ) + 3 ) ;
		
		}
	/*****************************************************************************************************************/
	void Simuler_match_p1 (int *Team1 , int *Team2 , Typevect_V32Tisiii *Tab , int *Won , int *Choice)
		{
			/** Variables locales **/
			int Nombre1;
			int Nombre2;
			int E1;
			int E2;

			/** Corps du module **/
			E1  =  Indice_id ( Tab , Team1 ) ;
			E2  =  Indice_id ( Tab , Team2 ) ;
		 if( *Choice == 1) {
			 Nombre1  =  Aleanombre(5 ) ;
			 Nombre2  =  Aleanombre(5 ) ;
			 if( Nombre1 == Nombre2) {
				 Match_nul_p1 ( & *Team1 , & *Team2 , & *Tab , & *Won ) ;
				 }
			 else
				 {
				 if( Nombre1 > Nombre2) {
					 Match_won_p1 ( & *Team1 , & *Tab , & *Won ) ;
					 }
				 else
					 {
					 Match_won_p1 ( & *Team2 , & *Tab , & *Won ) ;
					
				 }
			 } }
		 else
			 {
			 if( *Choice == 2) {
				 Nombre1  =  Struct3_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  ) ;
				 Nombre2  =  Struct3_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  ) ;
				 if( Nombre1 == Nombre2) {
					 Match_nul_p1 ( & *Team1 , & *Team2 , & *Tab , & *Won ) ;
					 }
				 else
					 {
					 if( Nombre1 < Nombre2) {
						 Match_won_p1 ( & *Team1 , & *Tab , & *Won ) ;
						 }
					 else
						 {
						 Match_won_p1 ( & *Team2 , & *Tab , & *Won ) ;
						
					 }
				 } }
			 else
				 {
				 if( *Choice == 3) {
					 Nombre1  =  200 - Struct3_Tisiii ( Element_V32Tisiii ( *Tab , E1   )  ) ;
					 Nombre2  =  200 - Struct3_Tisiii ( Element_V32Tisiii ( *Tab , E2   )  ) ;
					 Nombre1  =  Aleanombre(5 ) + Nombre1 ;
					 Nombre2  =  Aleanombre(5 ) + Nombre2 ;
					 Nombre1  =  Mod ( Nombre1 , 5 ) ;
					 Nombre2  =  Mod ( Nombre2 , 5 ) ;
					 if( Nombre1 == Nombre2) {
						 Match_nul_p1 ( & *Team1 , & *Team2 , & *Tab , & *Won ) ;
						 }
					 else
						 {
						 if( Nombre1 > Nombre2) {
							 Match_won_p1 ( & *Team1 , & *Tab , & *Won ) ;
							 }
						 else
							 {
							 Match_won_p1 ( & *Team2 , & *Tab , & *Won ) ;
							
						 }
					 } }
				 else
					 {
					 if( *Choice == 4) {
						 if( *Team1 == *Team2) {
							 Match_nul_p1 ( & *Team1 , & *Team2 , & *Tab , & *Won ) ;
							 }
						 else
							 {
							 if( *Team1 < *Team2) {
								 Nombre1  =  Mod ( *Team1 , 5 ) ;
								 Match_won_p1 ( & *Team1 , & *Tab , & *Won ) ;
								 }
							 else
								 {
								 Nombre2  =  Mod ( *Team2 , 5 ) ;
								 Match_won_p1 ( & *Team2 , & *Tab , & *Won ) ;
								
							 }
						 }
					 }
				 }
			 }
		 }
		}
	/*****************************************************************************************************************/
	void Simuler_phase1 (Typevect_V32Tisiii *Tab_equipes , Typevect_V8LTii *Tab_matches , int *Choice , Typevect_V8i *Tab_1st , Typevect_V8i *Tab_2nd)  
		{
			/** Variables locales **/
			int I;
			int K;
			int Team1;
			int Team2;
			Pointeur_LTii P;
			int Won = 0 ;

			/** Corps du module **/
			for( I  =  1 ;I <=  8 ; ++I){
				 gotoxy(58,2);
			
				printf("Simulation de la phase 1");

			 if (I == 1)
				{
					gotoxy(37,6);  
					textcolor(BLUE);  
					printf("Appuyez sur une touche pour afficher les resultats du 1 er Groupe");
					getch();
					textcolor(WHITE);
				}
				else
				{
					gotoxy(37,6);
					textcolor(BLUE);  
					printf("Appuyez sur une touche pour afficher les resultats du %d eme Groupe",I);
					getch();
					textcolor(WHITE);
				}
				int number = 1 ;
			 P  =  Element_V8LTii ( *Tab_matches , I   ) ;
			 while( P != NULL) 
			 {
					if ( number == 1 )
					{
						gotoxy(5,10);
						printf("La 1 ere rencontre : ");
					}
					else
					{ 
						gotoxy(5,wherey()+2);
						printf("La %d eme rencontre : ",number);
					}
					Team1  =  Struct1_Tii ( Valeur_LTii ( P )  ) ;
					Team2  =  Struct2_Tii ( Valeur_LTii ( P )  ) ;
					Simuler_match_p1 ( & Team1 , & Team2 , Tab_equipes , &Won , Choice ) ;
					if( Won == 0) 
					{
						gotoxy(30,wherey()+1);
						printf ( " %s  ", Id_name(&*Tab_equipes,&Team1) );
						gotoxy(50,wherey());
						printf("VS   %s    ",Id_name(&*Tab_equipes,&Team2));
						gotoxy(80,wherey()+1);
						printf(":    Match NUL");
					}
				 else
					 {
						gotoxy(30,wherey()+1);
						printf ( " %s  ", Id_name(&*Tab_equipes,&Team1) );
						gotoxy(50,wherey());
						printf ( "VS  %s    ", Id_name(&*Tab_equipes,&Team2));
						gotoxy(80,wherey()+1);
						printf (":    %s Gagne",Id_name(&*Tab_equipes,&Won));
				 } ;
				 P  =  Suivant_LTii ( P ) ;
				number++;
				
			 } ;
			 if ( I == 8 )
				{
					gotoxy(52,wherey()+3);
					textcolor(BLUE);
					printf("Appuyez sur une touche pour afficher les equipes qualifies de chaque groupe...");
					textcolor(WHITE);
					getch();
				}
				else
				{
					textcolor(BLUE);
					gotoxy(64,wherey()+3);
					printf("Appuyez sur une touche pour passer au groupe suivant...");
					textcolor(WHITE);
					getch();
				}
				clrscr();
			 printf ( " %s", "" ) ;
			 printf ( " %s", "" ) ;
			 printf ( " %s", "" ) ;
		 }
		}
	/*****************************************************************************************************************/
	void Qualifies (Typevect_V8i *First , Typevect_V8i *Second , Typevect_V32Tisiii *Table)
		{
			/** Variables locales **/
			int I;
			int _Px1;
			int _Px2;

			gotoxy(58,2);
			printf("Simulation de la phase 1");
			gotoxy(wherex(),wherey()+3);
			textcolor(BLACK);
			textbackground(LIGHTBLUE);
			gotoxy(45,wherey());
			printf("   Les equipes qualifies a la deuxieme phase :   ");
			textbackground(BLACK);
			textcolor(WHITE);
			gotoxy(wherex(),wherey()+1);
			/** Corps du module **/
		 for( I  =  1 ;I <=  8 ; ++I){
			 gotoxy(20,wherey()+2);
			 if ( I == 1   )
			 {
				printf( "Le 1 er groupe : " ); 
			 }
			 else
			 {
				printf( "Le %d eme groupe : ", I );
				}

			 _Px1 =  Element_V8i ( *First , I ) ;
			 gotoxy(40,wherey()+1);
			 printf ( " 1 --- %s", Id_name(&*Table,&_Px1) ) ;
			 _Px2 =  Element_V8i ( *Second , I   ) ;
			 gotoxy(60,wherey()+1);
			 printf ( " 2 --- %s", Id_name(&*Table,&_Px2) ) ;
			 
		 } ;

			gotoxy(65,wherey()+3);
			textcolor(BLUE);
			printf("Appuyez sur une touche pour simuler la phase 2 ...");
			textcolor(WHITE);
			getch();
		
		}
	/*****************************************************************************************************************/
	void Tri_pt_w (Typevect_V4i *Pt , Typevect_V4i *W)
		{
			/** Variables locales **/
			int J;
			int K;
			int Temp;

			/** Corps du module **/
		 J  =  3 ;
		 while( J > 0) {
			 for( K  =  1 ;K <=  J ; ++K){
				 if( Element_V4i ( *Pt , K   ) < Element_V4i ( *Pt , K + 1   )) {
					 Temp  =  Element_V4i ( *Pt , K   ) ;
					 Aff_element_V4i ( *Pt , K   , Element_V4i ( *Pt , K + 1   ) ) ;
					 Aff_element_V4i ( *Pt , K + 1   , Temp ) ;
					 Temp  =  Element_V4i ( *W , K   ) ;
					 Aff_element_V4i ( *W , K   , Element_V4i ( *W , K + 1   ) ) ;
					 Aff_element_V4i ( *W , K + 1   , Temp ) ;
					
				 } ;
				
			 } ;
			 J  =  J - 1 ;
			
		 } ;
		
		}
	/*****************************************************************************************************************/
	void Group_winners (Typevect_V8Tiiii *Tab_groupes , Typevect_V32Tisiii *Tab_participants , Typevect_V8i *First , Typevect_V8i *Second)
		{
			/** Variables locales **/
			int Indice;
			int I;
			int J;
			int Temp;
			Typevect_V4i Pt;
			Typevect_V4i W;
			int _Px1;
			int _Px2;
			int _Px3;
			int _Px4;

			/** Corps du module **/
		 Pt = malloc(4 * sizeof(int));
		 W = malloc(4 * sizeof(int));
		 for( I  =  1 ;I <=  8 ; ++I){
			 _Px1 =  Struct1_Tiiii ( Element_V8Tiiii ( *Tab_groupes , I   )  ) ;
			 Indice  =  Indice_id ( & *Tab_participants , &_Px1) ;
			 Aff_element_V4i ( W , 1   , Struct1_Tiiii ( Element_V8Tiiii ( *Tab_groupes , I   )  ) ) ;
			 Aff_element_V4i ( Pt , 1   , Struct4_Tisiii ( Element_V32Tisiii ( *Tab_participants , Indice   )  ) ) ;
			 _Px2 =  Struct2_Tiiii ( Element_V8Tiiii ( *Tab_groupes , I   )  ) ;
			 Indice  =  Indice_id ( & *Tab_participants , &_Px2) ;
			 Aff_element_V4i ( W , 2   , Struct2_Tiiii ( Element_V8Tiiii ( *Tab_groupes , I   )  ) ) ;
			 Aff_element_V4i ( Pt , 2   , Struct4_Tisiii ( Element_V32Tisiii ( *Tab_participants , Indice   )  ) ) ;
			 _Px3 =  Struct3_Tiiii ( Element_V8Tiiii ( *Tab_groupes , I   )  ) ;
			 Indice  =  Indice_id ( & *Tab_participants , &_Px3) ;
			 Aff_element_V4i ( W , 3   , Struct3_Tiiii ( Element_V8Tiiii ( *Tab_groupes , I   )  ) ) ;
			 Aff_element_V4i ( Pt , 3   , Struct4_Tisiii ( Element_V32Tisiii ( *Tab_participants , Indice   )  ) ) ;
			 _Px4 =  Struct4_Tiiii ( Element_V8Tiiii ( *Tab_groupes , I   )  ) ;
			 Indice  =  Indice_id ( & *Tab_participants , &_Px4) ;
			 Aff_element_V4i ( W , 4   , Struct4_Tiiii ( Element_V8Tiiii ( *Tab_groupes , I   )  ) ) ;
			 Aff_element_V4i ( Pt , 4   , Struct4_Tisiii ( Element_V32Tisiii ( *Tab_participants , Indice   )  ) ) ;
			 Tri_pt_w ( & Pt , & W ) ;
			 Aff_element_V8i ( *First , I   , Element_V4i ( W , 1   ) ) ;
			 Aff_element_V8i ( *Second , I   , Element_V4i ( W , 2   ) ) ;
			/* LE CONCEPT DU TIRAGE AU SORT N'EST PAS FAIT AVEC LA FONCTION ALEA */
			/* L'EQUIPE QUI PASSE EST GENEREE DU TABLEAU TRIEE DES EQUIPES : LE TRI MODIFIE SANS AUCUNE CDT */
			
		 } ;
		
		}
	/*****************************************************************************************************************/
	void Aff_eq_fifa1 (Typevect_V198s *Tab)
		{

			/** Corps du module **/
		 Aff_element_V198s ( *Tab , 1   , "Bresil" ) ;
		 Aff_element_V198s ( *Tab , 2   , "Belgique" ) ;
		 Aff_element_V198s ( *Tab , 3   , "France" ) ;
		 Aff_element_V198s ( *Tab , 4   , "Argentine" ) ;
		 Aff_element_V198s ( *Tab , 5   , "Angleterre" ) ;
		 Aff_element_V198s ( *Tab , 6   , "Italie" ) ;
		 Aff_element_V198s ( *Tab , 7   , "Espagne" ) ;
		 Aff_element_V198s ( *Tab , 8   , "Portugal" ) ;
		 Aff_element_V198s ( *Tab , 9   , "Mexique" ) ;
		 Aff_element_V198s ( *Tab , 10   , "Pays Bas" ) ;
		 Aff_element_V198s ( *Tab , 11   , "Denmark" ) ;
		 Aff_element_V198s ( *Tab , 12   , "Allemagne" ) ;
		 Aff_element_V198s ( *Tab , 13   , "Uruguay" ) ;
		 Aff_element_V198s ( *Tab , 14   , "Suisse" ) ;
		 Aff_element_V198s ( *Tab , 15   , "Etats Unis" ) ;
		 Aff_element_V198s ( *Tab , 16   , "Croatie" ) ;
		 Aff_element_V198s ( *Tab , 17   , "Colombie" ) ;
		 Aff_element_V198s ( *Tab , 18   , "Pays de Galles" ) ;
		 Aff_element_V198s ( *Tab , 19   , "Suede" ) ;
		 Aff_element_V198s ( *Tab , 20   , "Senegal" ) ;
		 Aff_element_V198s ( *Tab , 21   , "Iran" ) ;
		 Aff_element_V198s ( *Tab , 22   , "Perou" ) ;
		 Aff_element_V198s ( *Tab , 23   , "Japon" ) ;
		 Aff_element_V198s ( *Tab , 24   , "Maroc" ) ;
		 Aff_element_V198s ( *Tab , 25   , "Serbie" ) ;
		 Aff_element_V198s ( *Tab , 26   , "Pologne" ) ;
		 Aff_element_V198s ( *Tab , 27   , "Ukraine" ) ;
		 Aff_element_V198s ( *Tab , 28   , "Chili" ) ;
		 Aff_element_V198s ( *Tab , 29   , "Coree du Sud" ) ;
		 Aff_element_V198s ( *Tab , 30   , "Nigeria" ) ;
		 Aff_element_V198s ( *Tab , 31   , "Costa Rica" ) ;
		 Aff_element_V198s ( *Tab , 32   , "Egypte" ) ;
		 Aff_element_V198s ( *Tab , 33   , "Tcheque" ) ;
		 Aff_element_V198s ( *Tab , 34   , "Autriche" ) ;
		 Aff_element_V198s ( *Tab , 35   , "Tunisie" ) ;
		 Aff_element_V198s ( *Tab , 36   , "Russie" ) ;
		 Aff_element_V198s ( *Tab , 37   , "Cameroun" ) ;
		 Aff_element_V198s ( *Tab , 38   , "Canada" ) ;
		 Aff_element_V198s ( *Tab , 39   , "Ecosse" ) ;
		 Aff_element_V198s ( *Tab , 40   , "Hongrie" ) ;
		 Aff_element_V198s ( *Tab , 41   , "Norvege" ) ;
		 Aff_element_V198s ( *Tab , 42   , "Australie" ) ;
		 Aff_element_V198s ( *Tab , 43   , "Turquie" ) ;
		 Aff_element_V198s ( *Tab , 44   , "Algerie" ) ;
		 Aff_element_V198s ( *Tab , 45   , "Slovaquie" ) ;
		 Aff_element_V198s ( *Tab , 46   , "Equateur" ) ;
		 Aff_element_V198s ( *Tab , 47   , "Irlande" ) ;
		
		}
	/*****************************************************************************************************************/
	void Aff_eq_fifa2 (Typevect_V198s *Tab)
		{

			/** Corps du module **/
		 Aff_element_V198s ( *Tab , 49   , "Arabie Saoudite" ) ;
		 Aff_element_V198s ( *Tab , 50   , "Paraguay" ) ;
		 Aff_element_V198s ( *Tab , 51   , "Qatar" ) ;
		 Aff_element_V198s ( *Tab , 52   , "Mali" ) ;
		 Aff_element_V198s ( *Tab , 53   , "Cote dIvoire" ) ;
		 Aff_element_V198s ( *Tab , 54   , "Irlande du Nord" ) ;
		 Aff_element_V198s ( *Tab , 55   , "Grece" ) ;
		 Aff_element_V198s ( *Tab , 56   , "Burkina Faso" ) ;
		 Aff_element_V198s ( *Tab , 57   , "Finlande" ) ;
		 Aff_element_V198s ( *Tab , 58   , "Venezuela" ) ;
		 Aff_element_V198s ( *Tab , 59   , "Bosnie Herzegovine" ) ;
		 Aff_element_V198s ( *Tab , 60   , "Ghana" ) ;
		 Aff_element_V198s ( *Tab , 61   , "Panama" ) ;
		 Aff_element_V198s ( *Tab , 62   , "Macedoine du Nord" ) ;
		 Aff_element_V198s ( *Tab , 63   , "Islande" ) ;
		 Aff_element_V198s ( *Tab , 64   , "Jamaique" ) ;
		 Aff_element_V198s ( *Tab , 65   , "Slovenie" ) ;
		 Aff_element_V198s ( *Tab , 66   , "Albanie" ) ;
		 Aff_element_V198s ( *Tab , 67   , "RD Congo" ) ;
		 Aff_element_V198s ( *Tab , 68   , "Emirats Arabes Unis" ) ;
		 Aff_element_V198s ( *Tab , 69   , "Afrique du Sud" ) ;
		 Aff_element_V198s ( *Tab , 70   , "Montenegro" ) ;
		 Aff_element_V198s ( *Tab , 48   , "Roumanie" ) ;
		 Aff_element_V198s ( *Tab , 71   , "Cap vert" ) ;
		 Aff_element_V198s ( *Tab , 72   , "Iraq" ) ;
		 Aff_element_V198s ( *Tab , 73   , "Bulgarie" ) ;
		 Aff_element_V198s ( *Tab , 74   , "Salvador" ) ;
		 Aff_element_V198s ( *Tab , 75   , "Oman" ) ;
		 Aff_element_V198s ( *Tab , 76   , "Chine" ) ;
		 Aff_element_V198s ( *Tab , 77   , "Bolivie" ) ;
		 Aff_element_V198s ( *Tab , 78   , "Curacao" ) ;
		 Aff_element_V198s ( *Tab , 79   , "Guinee" ) ;
		 Aff_element_V198s ( *Tab , 80   , "Gabon" ) ;
		 Aff_element_V198s ( *Tab , 81   , "Honduras" ) ;
		 Aff_element_V198s ( *Tab , 82   , "Ouzbekistan" ) ;
		 Aff_element_V198s ( *Tab , 83   , "Benin" ) ;
		 Aff_element_V198s ( *Tab , 84   , "Georgie" ) ;
		 Aff_element_V198s ( *Tab , 85   , "Ouganda" ) ;
		 Aff_element_V198s ( *Tab , 86   , "Zambie" ) ;
		 Aff_element_V198s ( *Tab , 87   , "Syrie" ) ;
		 Aff_element_V198s ( *Tab , 88   , "Bahrein" ) ;
		 Aff_element_V198s ( *Tab , 89   , "Haiti" ) ;
		 Aff_element_V198s ( *Tab , 90   , "Jordanie" ) ;
		 Aff_element_V198s ( *Tab , 91   , "Armenie" ) ;
		 Aff_element_V198s ( *Tab , 92   , "Bielorussie" ) ;
		 Aff_element_V198s ( *Tab , 93   , "Luxembourg" ) ;
		
		}
	/*****************************************************************************************************************/
	void Aff_eq_fifa3 (Typevect_V198s *Tab)
		{

			/** Corps du module **/
		 Aff_element_V198s ( *Tab , 94   , "Kirghizistan" ) ;
		 Aff_element_V198s ( *Tab , 95   , "Vietnam" ) ;
		 Aff_element_V198s ( *Tab , 96   , "Congo" ) ;
		 Aff_element_V198s ( *Tab , 97   , "Guinee Equatoriale" ) ;
		 Aff_element_V198s ( *Tab , 98   , "Palestine" ) ;
		 Aff_element_V198s ( *Tab , 99   , "Nouvelle Zelande" ) ;
		 Aff_element_V198s ( *Tab , 100   , "Madagascar" ) ;
		 Aff_element_V198s ( *Tab , 101   , "TriniteetTobago" ) ;
		 Aff_element_V198s ( *Tab , 102   , "Kenya" ) ;
		 Aff_element_V198s ( *Tab , 103   , "Chypre" ) ;
		 Aff_element_V198s ( *Tab , 104   , "Inde" ) ;
		 Aff_element_V198s ( *Tab , 105   , "Sierra Leone" ) ;
		 Aff_element_V198s ( *Tab , 106   , "Coree du Nord" ) ;
		 Aff_element_V198s ( *Tab , 107   , "Estonie" ) ;
		 Aff_element_V198s ( *Tab , 108   , "Thailande" ) ;
		 Aff_element_V198s ( *Tab , 109   , "Namibie" ) ;
		 Aff_element_V198s ( *Tab , 110   , "Mauritanie" ) ;
		 Aff_element_V198s ( *Tab , 111   , "Tadjikistan" ) ;
		 Aff_element_V198s ( *Tab , 112   , "Guinee Bissau" ) ;
		 Aff_element_V198s ( *Tab , 113   , "Niger" ) ;
		 Aff_element_V198s ( *Tab , 114   , "Libye" ) ;
		 Aff_element_V198s ( *Tab , 115   , "Guatemala" ) ;
		 Aff_element_V198s ( *Tab , 116   , "Mozambique" ) ;
		 Aff_element_V198s ( *Tab , 117   , "Malawi" ) ;
		 Aff_element_V198s ( *Tab , 118   , "Togo" ) ;
		 Aff_element_V198s ( *Tab , 119   , "Zimbabwe" ) ;
		 Aff_element_V198s ( *Tab , 120   , "Gambie" ) ;
		 Aff_element_V198s ( *Tab , 121   , "Kazakhstan" ) ;
		 Aff_element_V198s ( *Tab , 122   , "Angola" ) ;
		 Aff_element_V198s ( *Tab , 123   , "Antigua" ) ;
		 Aff_element_V198s ( *Tab , 124   , "Comores" ) ;
		 Aff_element_V198s ( *Tab , 125   , "Azerbaidjan" ) ;
		 Aff_element_V198s ( *Tab , 126   , "Tanzanie" ) ;
		 Aff_element_V198s ( *Tab , 127   , "Rep. Centrafricaine" ) ;
		 Aff_element_V198s ( *Tab , 128   , "Soudan" ) ;
		 Aff_element_V198s ( *Tab , 129   , "Philippines" ) ;
		 Aff_element_V198s ( *Tab , 130   , "Turkmenistan" ) ;
		 Aff_element_V198s ( *Tab , 131   , "Lettonie" ) ;
		 Aff_element_V198s ( *Tab , 132   , "Rwanda" ) ;
		 Aff_element_V198s ( *Tab , 133   , "Lituanie" ) ;
		 Aff_element_V198s ( *Tab , 134   , "Burundi" ) ;
		 Aff_element_V198s ( *Tab , 135   , "Ethiopie" ) ;
		 Aff_element_V198s ( *Tab , 136   , "Surinam" ) ;
		 Aff_element_V198s ( *Tab , 137   , "SaintKitts et Nevis" ) ;
		 Aff_element_V198s ( *Tab , 138   , "Swaziland" ) ;
		 Aff_element_V198s ( *Tab , 139   , "Lesotho" ) ;
		 Aff_element_V198s ( *Tab , 140   , "Koweit" ) ;
		
		}
	/*****************************************************************************************************************/
	void Aff_eq_fifa4 (Typevect_V198s *Tab)
		{

			/** Corps du module **/
		 Aff_element_V198s ( *Tab , 141   , "HongKong" ) ;
		 Aff_element_V198s ( *Tab , 142   , "Botswana" ) ;
		 Aff_element_V198s ( *Tab , 143   , "Liberia" ) ;
		 Aff_element_V198s ( *Tab , 144   , "Afghanistan" ) ;
		 Aff_element_V198s ( *Tab , 145   , "Yemen" ) ;
		 Aff_element_V198s ( *Tab , 146   , "Myanmar" ) ;
		 Aff_element_V198s ( *Tab , 147   , "Andorre" ) ;
		 Aff_element_V198s ( *Tab , 148   , "Malaisie" ) ;
		 Aff_element_V198s ( *Tab , 149   , "Republique Dominicaine" ) ;
		 Aff_element_V198s ( *Tab , 150   , "Maldives" ) ;
		 Aff_element_V198s ( *Tab , 151   , "Taiwan" ) ;
		 Aff_element_V198s ( *Tab , 152   , "Indonesie" ) ;
		 Aff_element_V198s ( *Tab , 153   , "Nouvelle Caledonie" ) ;
		 Aff_element_V198s ( *Tab , 154   , "Soudan du sud" ) ;
		 Aff_element_V198s ( *Tab , 155   , "Papouasie Nv Guinee" ) ;
		 Aff_element_V198s ( *Tab , 156   , "Barbade" ) ;
		 Aff_element_V198s ( *Tab , 157   , "Tahiti" ) ;
		 Aff_element_V198s ( *Tab , 158   , "Fidji" ) ;
		 Aff_element_V198s ( *Tab , 159   , "Vanuatu" ) ;
		 Aff_element_V198s ( *Tab , 160   , "Bermudes" ) ;
		 Aff_element_V198s ( *Tab , 161   , "Nepal" ) ;
		 Aff_element_V198s ( *Tab , 162   , "Malte" ) ;
		 Aff_element_V198s ( *Tab , 163   , "Grenade" ) ;
		 Aff_element_V198s ( *Tab , 164   , "Cambodge" ) ;
		 Aff_element_V198s ( *Tab , 165   , "Porto Rico" ) ;
		 Aff_element_V198s ( *Tab , 166   , "Belize" ) ;
		 Aff_element_V198s ( *Tab , 167   , "Guyana" ) ;
		 Aff_element_V198s ( *Tab , 168   , "Saint Vincent" ) ;
		 Aff_element_V198s ( *Tab , 169   , "Sainte Lucie" ) ;
		 Aff_element_V198s ( *Tab , 170   , "Cuba" ) ;
		 Aff_element_V198s ( *Tab , 171   , "Montserrat" ) ;
		 Aff_element_V198s ( *Tab , 172   , "Moldavie" ) ;
		 Aff_element_V198s ( *Tab , 173   , "Tchad" ) ;
		 Aff_element_V198s ( *Tab , 174   , "Macao" ) ;
		 Aff_element_V198s ( *Tab , 175   , "Sao Tome et Principe" ) ;
		 Aff_element_V198s ( *Tab , 176   , "Dominique" ) ;
		 Aff_element_V198s ( *Tab , 177   , "Laos" ) ;
		 Aff_element_V198s ( *Tab , 178   , "Mongolie" ) ;
		 Aff_element_V198s ( *Tab , 179   , "Bhoutan" ) ;
		 Aff_element_V198s ( *Tab , 180   , "Bangladesh" ) ;
		 Aff_element_V198s ( *Tab , 181   , "Samoa Americaines" ) ;
		 Aff_element_V198s ( *Tab , 182   , "Brunei" ) ;
		 Aff_element_V198s ( *Tab , 183   , "Liechtenstein" ) ;
		 Aff_element_V198s ( *Tab , 184   , "Samoa" ) ;
		 Aff_element_V198s ( *Tab , 185   , "Djibouti" ) ;
		 Aff_element_V198s ( *Tab , 186   , "Seychelles" ) ;
		 Aff_element_V198s ( *Tab , 187   , "Pakistan" ) ;
		
		}
	/*****************************************************************************************************************/
	void Aff_eq_fifa5 (Typevect_V198s *Tab)
		{

			/** Corps du module **/
		 Aff_element_V198s ( *Tab , 188   , "Timor Oriental" ) ;
		 Aff_element_V198s ( *Tab , 189   , "Tonga" ) ;
		 Aff_element_V198s ( *Tab , 190   , "Aruba" ) ;
		 Aff_element_V198s ( *Tab , 191   , "Bahamas" ) ;
		 Aff_element_V198s ( *Tab , 192   , "Somalie" ) ;
		 Aff_element_V198s ( *Tab , 193   , "Erythree" ) ;
		 Aff_element_V198s ( *Tab , 194   , "Sri Lanka" ) ;
		 Aff_element_V198s ( *Tab , 195   , "Turks et Caicos" ) ;
		 Aff_element_V198s ( *Tab , 196   , "Guam" ) ;
		 Aff_element_V198s ( *Tab , 197   , "Anguilla" ) ;
		 Aff_element_V198s ( *Tab , 198   , "SaintMarin" ) ;
		
		}
	/*****************************************************************************************************************/
	void Aff_eq_fav1 (Typevect_V198s *Tab)
		{

			/** Corps du module **/
		 Aff_element_V198s ( *Tab , 10   , "Bresil" ) ;
		 Aff_element_V198s ( *Tab , 4   , "Belgique" ) ;
		 Aff_element_V198s ( *Tab , 2   , "France" ) ;
		 Aff_element_V198s ( *Tab , 3   , "Argentine" ) ;
		 Aff_element_V198s ( *Tab , 8   , "Angleterre" ) ;
		 Aff_element_V198s ( *Tab , 12   , "Italie" ) ;
		 Aff_element_V198s ( *Tab , 6   , "Espagne" ) ;
		 Aff_element_V198s ( *Tab , 5   , "Portugal" ) ;
		 Aff_element_V198s ( *Tab , 51   , "Mexique" ) ;
		 Aff_element_V198s ( *Tab , 44   , "Pays Bas" ) ;
		 Aff_element_V198s ( *Tab , 26   , "Denmark" ) ;
		 Aff_element_V198s ( *Tab , 7   , "Allemagne" ) ;
		 Aff_element_V198s ( *Tab , 23   , "Uruguay" ) ;
		 Aff_element_V198s ( *Tab , 14   , "Suisse" ) ;
		 Aff_element_V198s ( *Tab , 11   , "Etats Unis" ) ;
		 Aff_element_V198s ( *Tab , 9   , "Croatie" ) ;
		 Aff_element_V198s ( *Tab , 32   , "Colombie" ) ;
		 Aff_element_V198s ( *Tab , 35   , "Pays de Galles" ) ;
		 Aff_element_V198s ( *Tab , 19   , "Suede" ) ;
		 Aff_element_V198s ( *Tab , 20   , "Senegal" ) ;
		 Aff_element_V198s ( *Tab , 43   , "Iran" ) ;
		 Aff_element_V198s ( *Tab , 22   , "Perou" ) ;
		 Aff_element_V198s ( *Tab , 13   , "Japon" ) ;
		 Aff_element_V198s ( *Tab , 24   , "Maroc" ) ;
		 Aff_element_V198s ( *Tab , 38   , "Serbie" ) ;
		 Aff_element_V198s ( *Tab , 15   , "Pologne" ) ;
		 Aff_element_V198s ( *Tab , 27   , "Ukraine" ) ;
		 Aff_element_V198s ( *Tab , 36   , "Chili" ) ;
		 Aff_element_V198s ( *Tab , 29   , "Coree du Sud" ) ;
		 Aff_element_V198s ( *Tab , 30   , "Nigeria" ) ;
		 Aff_element_V198s ( *Tab , 31   , "Costa Rica" ) ;
		 Aff_element_V198s ( *Tab , 18   , "Egypte" ) ;
		 Aff_element_V198s ( *Tab , 33   , "Tcheque" ) ;
		 Aff_element_V198s ( *Tab , 40   , "Autriche" ) ;
		 Aff_element_V198s ( *Tab , 17   , "Tunisie" ) ;
		 Aff_element_V198s ( *Tab , 47   , "Russie" ) ;
		 Aff_element_V198s ( *Tab , 37   , "Cameroun" ) ;
		 Aff_element_V198s ( *Tab , 25   , "Canada" ) ;
		 Aff_element_V198s ( *Tab , 39   , "Ecosse" ) ;
		 Aff_element_V198s ( *Tab , 34   , "Hongrie" ) ;
		 Aff_element_V198s ( *Tab , 41   , "Norvege" ) ;
		 Aff_element_V198s ( *Tab , 42   , "Australie" ) ;
		 Aff_element_V198s ( *Tab , 62   , "Turquie" ) ;
		 Aff_element_V198s ( *Tab , 1   , "Algerie" ) ;
		 Aff_element_V198s ( *Tab , 28   , "Slovaquie" ) ;
		 Aff_element_V198s ( *Tab , 46   , "Equateur" ) ;
		 Aff_element_V198s ( *Tab , 55   , "Irlande" ) ;
		
		}
	/*****************************************************************************************************************/
	void Aff_eq_fav2 (Typevect_V198s *Tab)
		{

			/** Corps du module **/
		 Aff_element_V198s ( *Tab , 49   , "Arabie Saoudite" ) ;
		 Aff_element_V198s ( *Tab , 68   , "Paraguay" ) ;
		 Aff_element_V198s ( *Tab , 16   , "Qatar" ) ;
		 Aff_element_V198s ( *Tab , 52   , "Mali" ) ;
		 Aff_element_V198s ( *Tab , 53   , "Cote dIvoire" ) ;
		 Aff_element_V198s ( *Tab , 54   , "Irlande du Nord" ) ;
		 Aff_element_V198s ( *Tab , 45   , "Grece" ) ;
		 Aff_element_V198s ( *Tab , 56   , "Burkina Faso" ) ;
		 Aff_element_V198s ( *Tab , 60   , "Finlande" ) ;
		 Aff_element_V198s ( *Tab , 71   , "Venezuela" ) ;
		 Aff_element_V198s ( *Tab , 59   , "Bosnie Herzegovine" ) ;
		 Aff_element_V198s ( *Tab , 57   , "Ghana" ) ;
		 Aff_element_V198s ( *Tab , 61   , "Panama" ) ;
		 Aff_element_V198s ( *Tab , 21   , "Macedoine du Nord" ) ;
		 Aff_element_V198s ( *Tab , 63   , "Islande" ) ;
		 Aff_element_V198s ( *Tab , 72   , "Jamaique" ) ;
		 Aff_element_V198s ( *Tab , 65   , "Slovenie" ) ;
		 Aff_element_V198s ( *Tab , 66   , "Albanie" ) ;
		 Aff_element_V198s ( *Tab , 67   , "RD Congo" ) ;
		 Aff_element_V198s ( *Tab , 82   , "Emirats Arabes Unis" ) ;
		 Aff_element_V198s ( *Tab , 69   , "Afrique du Sud" ) ;
		 Aff_element_V198s ( *Tab , 70   , "Montenegro" ) ;
		 Aff_element_V198s ( *Tab , 48   , "Roumanie" ) ;
		 Aff_element_V198s ( *Tab , 58   , "Cap vert" ) ;
		 Aff_element_V198s ( *Tab , 88   , "Iraq" ) ;
		 Aff_element_V198s ( *Tab , 73   , "Bulgarie" ) ;
		 Aff_element_V198s ( *Tab , 74   , "Salvador" ) ;
		 Aff_element_V198s ( *Tab , 93   , "Oman" ) ;
		 Aff_element_V198s ( *Tab , 76   , "Chine" ) ;
		 Aff_element_V198s ( *Tab , 77   , "Bolivie" ) ;
		 Aff_element_V198s ( *Tab , 78   , "Curacao" ) ;
		 Aff_element_V198s ( *Tab , 79   , "Guinee" ) ;
		 Aff_element_V198s ( *Tab , 80   , "Gabon" ) ;
		 Aff_element_V198s ( *Tab , 81   , "Honduras" ) ;
		 Aff_element_V198s ( *Tab , 103   , "Ouzbekistan" ) ;
		 Aff_element_V198s ( *Tab , 83   , "Benin" ) ;
		 Aff_element_V198s ( *Tab , 100   , "Georgie" ) ;
		 Aff_element_V198s ( *Tab , 85   , "Ouganda" ) ;
		 Aff_element_V198s ( *Tab , 86   , "Zambie" ) ;
		 Aff_element_V198s ( *Tab , 87   , "Syrie" ) ;
		 Aff_element_V198s ( *Tab , 64   , "Bahrein" ) ;
		 Aff_element_V198s ( *Tab , 89   , "Haiti" ) ;
		 Aff_element_V198s ( *Tab , 84   , "Jordanie" ) ;
		 Aff_element_V198s ( *Tab , 91   , "Armenie" ) ;
		 Aff_element_V198s ( *Tab , 92   , "Bielorussie" ) ;
		 Aff_element_V198s ( *Tab , 75   , "Luxembourg" ) ;
		
		}
	/*****************************************************************************************************************/
	void Aff_eq_fav3 (Typevect_V198s *Tab)
		{

			/** Corps du module **/
		 Aff_element_V198s ( *Tab , 129   , "Kirghizistan" ) ;
		 Aff_element_V198s ( *Tab , 95   , "Vietnam" ) ;
		 Aff_element_V198s ( *Tab , 96   , "Congo" ) ;
		 Aff_element_V198s ( *Tab , 97   , "Guinee Equatoriale" ) ;
		 Aff_element_V198s ( *Tab , 98   , "Palestine" ) ;
		 Aff_element_V198s ( *Tab , 99   , "Nouvelle Zelande" ) ;
		 Aff_element_V198s ( *Tab , 90   , "Madagascar" ) ;
		 Aff_element_V198s ( *Tab , 101   , "TriniteetTobago" ) ;
		 Aff_element_V198s ( *Tab , 102   , "Kenya" ) ;
		 Aff_element_V198s ( *Tab , 50   , "Chypre" ) ;
		 Aff_element_V198s ( *Tab , 134   , "Inde" ) ;
		 Aff_element_V198s ( *Tab , 139   , "Sierra Leone" ) ;
		 Aff_element_V198s ( *Tab , 106   , "Coree du Nord" ) ;
		 Aff_element_V198s ( *Tab , 107   , "Estonie" ) ;
		 Aff_element_V198s ( *Tab , 108   , "Thailande" ) ;
		 Aff_element_V198s ( *Tab , 109   , "Namibie" ) ;
		 Aff_element_V198s ( *Tab , 132   , "Mauritanie" ) ;
		 Aff_element_V198s ( *Tab , 136   , "Tadjikistan" ) ;
		 Aff_element_V198s ( *Tab , 112   , "Guinee Bissau" ) ;
		 Aff_element_V198s ( *Tab , 113   , "Niger" ) ;
		 Aff_element_V198s ( *Tab , 114   , "Libye" ) ;
		 Aff_element_V198s ( *Tab , 140   , "Guatemala" ) ;
		 Aff_element_V198s ( *Tab , 116   , "Mozambique" ) ;
		 Aff_element_V198s ( *Tab , 117   , "Malawi" ) ;
		 Aff_element_V198s ( *Tab , 118   , "Togo" ) ;
		 Aff_element_V198s ( *Tab , 119   , "Zimbabwe" ) ;
		 Aff_element_V198s ( *Tab , 188   , "Gambie" ) ;
		 Aff_element_V198s ( *Tab , 121   , "Kazakhstan" ) ;
		 Aff_element_V198s ( *Tab , 186   , "Angola" ) ;
		 Aff_element_V198s ( *Tab , 143   , "Antigua" ) ;
		 Aff_element_V198s ( *Tab , 148   , "Comores" ) ;
		 Aff_element_V198s ( *Tab , 125   , "Azerbaidjan" ) ;
		 Aff_element_V198s ( *Tab , 194   , "Tanzanie" ) ;
		 Aff_element_V198s ( *Tab , 127   , "Rep. Centrafricaine" ) ;
		 Aff_element_V198s ( *Tab , 128   , "Soudan" ) ;
		 Aff_element_V198s ( *Tab , 94   , "Philippines" ) ;
		 Aff_element_V198s ( *Tab , 130   , "Turkmenistan" ) ;
		 Aff_element_V198s ( *Tab , 131   , "Lettonie" ) ;
		 Aff_element_V198s ( *Tab , 110   , "Rwanda" ) ;
		 Aff_element_V198s ( *Tab , 133   , "Lituanie" ) ;
		 Aff_element_V198s ( *Tab , 104   , "Burundi" ) ;
		 Aff_element_V198s ( *Tab , 135   , "Ethiopie" ) ;
		 Aff_element_V198s ( *Tab , 111   , "Surinam" ) ;
		 Aff_element_V198s ( *Tab , 137   , "SaintKitts et Nevis" ) ;
		 Aff_element_V198s ( *Tab , 138   , "Swaziland" ) ;
		 Aff_element_V198s ( *Tab , 105   , "Lesotho" ) ;
		 Aff_element_V198s ( *Tab , 115   , "Koweit" ) ;
		
		}
	/*****************************************************************************************************************/
	void Aff_eq_fav4 (Typevect_V198s *Tab)
		{

			/** Corps du module **/
		 Aff_element_V198s ( *Tab , 141   , "HongKong" ) ;
		 Aff_element_V198s ( *Tab , 142   , "Botswana" ) ;
		 Aff_element_V198s ( *Tab , 123   , "Liberia" ) ;
		 Aff_element_V198s ( *Tab , 144   , "Afghanistan" ) ;
		 Aff_element_V198s ( *Tab , 145   , "Yemen" ) ;
		 Aff_element_V198s ( *Tab , 146   , "Myanmar" ) ;
		 Aff_element_V198s ( *Tab , 147   , "Andorre" ) ;
		 Aff_element_V198s ( *Tab , 124   , "Malaisie" ) ;
		 Aff_element_V198s ( *Tab , 149   , "Republique Dominicaine" ) ;
		 Aff_element_V198s ( *Tab , 150   , "Maldives" ) ;
		 Aff_element_V198s ( *Tab , 151   , "Taiwan" ) ;
		 Aff_element_V198s ( *Tab , 122   , "Indonesie" ) ;
		 Aff_element_V198s ( *Tab , 153   , "Nouvelle Caledonie" ) ;
		 Aff_element_V198s ( *Tab , 154   , "Soudan du sud" ) ;
		 Aff_element_V198s ( *Tab , 155   , "Papouasie Nv Guinee" ) ;
		 Aff_element_V198s ( *Tab , 156   , "Barbade" ) ;
		 Aff_element_V198s ( *Tab , 157   , "Tahiti" ) ;
		 Aff_element_V198s ( *Tab , 158   , "Fidji" ) ;
		 Aff_element_V198s ( *Tab , 183   , "Vanuatu" ) ;
		 Aff_element_V198s ( *Tab , 192   , "Bermudes" ) ;
		 Aff_element_V198s ( *Tab , 161   , "Nepal" ) ;
		 Aff_element_V198s ( *Tab , 162   , "Malte" ) ;
		 Aff_element_V198s ( *Tab , 175   , "Grenade" ) ;
		 Aff_element_V198s ( *Tab , 164   , "Cambodge" ) ;
		 Aff_element_V198s ( *Tab , 191   , "Porto Rico" ) ;
		 Aff_element_V198s ( *Tab , 180   , "Belize" ) ;
		 Aff_element_V198s ( *Tab , 167   , "Guyana" ) ;
		 Aff_element_V198s ( *Tab , 168   , "Saint Vincent" ) ;
		 Aff_element_V198s ( *Tab , 169   , "Sainte Lucie" ) ;
		 Aff_element_V198s ( *Tab , 182   , "Cuba" ) ;
		 Aff_element_V198s ( *Tab , 171   , "Montserrat" ) ;
		 Aff_element_V198s ( *Tab , 172   , "Moldavie" ) ;
		 Aff_element_V198s ( *Tab , 173   , "Tchad" ) ;
		 Aff_element_V198s ( *Tab , 174   , "Macao" ) ;
		 Aff_element_V198s ( *Tab , 163   , "Sao Tome et Principe" ) ;
		 Aff_element_V198s ( *Tab , 176   , "Dominique" ) ;
		 Aff_element_V198s ( *Tab , 190   , "Laos" ) ;
		 Aff_element_V198s ( *Tab , 178   , "Mongolie" ) ;
		 Aff_element_V198s ( *Tab , 179   , "Bhoutan" ) ;
		 Aff_element_V198s ( *Tab , 166   , "Bangladesh" ) ;
		 Aff_element_V198s ( *Tab , 181   , "Samoa Americaines" ) ;
		 Aff_element_V198s ( *Tab , 170   , "Brunei" ) ;
		 Aff_element_V198s ( *Tab , 159   , "Liechtenstein" ) ;
		 Aff_element_V198s ( *Tab , 184   , "Samoa" ) ;
		 Aff_element_V198s ( *Tab , 185   , "Djibouti" ) ;
		 Aff_element_V198s ( *Tab , 152   , "Seychelles" ) ;
		 Aff_element_V198s ( *Tab , 198   , "Pakistan" ) ;
		
		}
	/*****************************************************************************************************************/
	void Aff_eq_fav5 (Typevect_V198s *Tab)
		{

			/** Corps du module **/
		 Aff_element_V198s ( *Tab , 193   , "Timor Oriental" ) ;
		 Aff_element_V198s ( *Tab , 189   , "Tonga" ) ;
		 Aff_element_V198s ( *Tab , 177   , "Aruba" ) ;
		 Aff_element_V198s ( *Tab , 165   , "Bahamas" ) ;
		 Aff_element_V198s ( *Tab , 160   , "Somalie" ) ;
		 Aff_element_V198s ( *Tab , 120   , "Erythree" ) ;
		 Aff_element_V198s ( *Tab , 126   , "Sri Lanka" ) ;
		 Aff_element_V198s ( *Tab , 195   , "Turks et Caicos" ) ;
		 Aff_element_V198s ( *Tab , 196   , "Guam" ) ;
		 Aff_element_V198s ( *Tab , 197   , "Anguilla" ) ;
		 Aff_element_V198s ( *Tab , 187   , "SaintMarin" ) ;
		
		}

	/***************************************************************************************************************************************************/
void cursor_effect(int command) /* 0 hide else show*/
{
	if (command == 0)
	{ printf("\e[?25l"); }
	else
	{ printf("\e[?25h"); }
}

void print_dash (int num)
{
	textcolor(BLUE);
	for ( int i = 0 ; i<num ; i++ )
	printf("-");
	textcolor(WHITE);
}

void Interface (void)
{
		clrscr();
		cursor_effect(0);
		system("mode con cols=140 lines=45");
		textbackground(WHITE);
		for (int i = 1 ; i <= 140 ; i++ ) {printf(" ");}
		for (int i = 1 ; i <= 32 ; i++  )
		{
			gotoxy(1,i);
			printf("  ");
			gotoxy(139,i);
			printf("  ");
		}
		textbackground(BLACK);
		printf("\n\n\n");
		

		gotoxy(45,3);
		printf("================== [ Welcome ] ==================\n\n\n\n");
		textbackground(BLUE);
		gotoxy(48,wherey());printf("          ");gotoxy(65,wherey());printf("          ");gotoxy(79,wherey());printf("            \n");
		gotoxy(48,wherey());printf("  ");gotoxy(64,wherey());printf("  ");gotoxy(84,wherey());printf("  \n");
		gotoxy(48,wherey());printf("  ");gotoxy(64,wherey());printf("  ");gotoxy(84,wherey());printf("  \n");
		gotoxy(48,wherey());printf("          ");gotoxy(65,wherey());printf("          ");gotoxy(84,wherey());printf("  \n");
		gotoxy(48,wherey());printf("  ");gotoxy(74,wherey());printf("  ");gotoxy(84,wherey());printf("  \n");
		gotoxy(48,wherey());printf("  ");gotoxy(74,wherey());printf("  ");gotoxy(84,wherey());printf("  \n");
		gotoxy(48,wherey());printf("          ");gotoxy(65,wherey());printf("          ");gotoxy(79,wherey());printf("            \n\n\n");
			
		textbackground(BLACK);
		textcolor(WHITE);
		gotoxy(46,wherey());
		printf("TP2 ALSDD : Simulation d'un tournoi de football");
		printf("\n\n\n");
		gotoxy(39,wherey());
		printf("Nom :");
		gotoxy(66,wherey());
		printf("Merhab");
		gotoxy(91,wherey());
		printf("Abdelkebir");
		printf("\n\n");
		printf("\t\t\t");
		gotoxy(37,wherey());
		printf("Prenom :");
		gotoxy(64,wherey());
		printf("Abderraouf");
		gotoxy(93,wherey());
		printf("Achraf");
		printf("\n\n\n");
		textbackground(BLUE);
		gotoxy(48,wherey());
		printf("                                           ");
		textbackground(BLACK);
		printf("\n\n");
		gotoxy(53,wherey());
		printf("Groupe :");
		gotoxy(76,wherey());
		printf("1CPI  A-02");
		printf("\n\n");
		gotoxy(47,wherey());
		printf("Sous la supervisation de Monsieur D.E. Zegour");
		printf("\n\n");
		gotoxy(49,wherey());
		printf("Appuyez sur une touche pour continuer ...");
		printf("\n\n");
		textbackground(WHITE);
		for (int i = 1 ; i <= 140 ; i++ ) {printf(" ");}
		textbackground(BLACK);
		gotoxy(90,wherey()-2);
		fflush(stdin);
		getch();
}
	
int Choix_du_tournoi(void)
{
	cursor_effect(0);
		
		char rep = 0 ;
		char rep1;
		clrscr();
		textbackground(BLACK);
		textcolor(BLUE);
		gotoxy(58,3);
		printf("=== Choix du tournoi ===");
		gotoxy(18,wherey()+5);
		textbackground(LIGHTBLUE);
		textcolor(BLACK);
		printf("  --- Simuler la coupe du monde 2022  "); // y = 8
		textbackground(BLACK);
		textcolor(WHITE);
		gotoxy(18,wherey()+2);
		printf("  --- Simuler un tournoi avec des equipes au choix  ");// y = 10
		gotoxy(18,wherey()+2);
		printf("  --- Quitter  ");//y = 12
		gotoxy(58,8);

		while ( 1 )
		{
			rep = getch();
			if (  rep == 13 ) { goto Here; };
			if ( rep == (-32) )
			{
				rep1 = getch();
				if ( rep1 == 80 ) /* down */
				{
					gotoxy(18,wherey());
					switch ( wherey() )
					{
					case 8:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Simuler la coupe du monde 2022  ");
						gotoxy(18,10);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Simuler un tournoi avec des equipes au choix  ");
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 10:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Simuler un tournoi avec des equipes au choix  ");
						gotoxy(18,12);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Quitter  ");
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 12:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Quitter  ");
						gotoxy(18,8);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Simuler la coupe du monde 2022  ");
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					default:
						break;
					}
				}
				else if ( rep1 == 72 ) /* up */
				{
					gotoxy(18,wherey());
					switch ( wherey() )
					{
					case 8:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Simuler la coupe du monde 2022  ");
						gotoxy(18,12);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Quitter  ");
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 10:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Simuler un tournoi avec des equipes au choix  ");
						gotoxy(18,8);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Simuler la coupe du monde 2022  ");
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 12:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Quitter  ");
						gotoxy(18,10);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Simuler un tournoi avec des equipes au choix  ");
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					default:
						break;
					}
				} 
			}  
			

		}
Here:
		
		switch ( wherey() )
			{
			case 8:
				return 1;
				break;
			case 10:
				return 2;
				break;
			case 12:
				return 3;
				break;
			
			default:
				break;
			}
}

int Critere_Phase1(void)
{
		clrscr();
		cursor_effect(0);
		textbackground(BLACK);
		textcolor(BLUE);
		gotoxy(43,3);
		printf("=== Choix des criteres de simulation de la phase 1 ===");
		printf("\n\n\n\n\n");
		textcolor(WHITE);
		gotoxy(18,8);
		textbackground(LIGHTBLUE);
		textcolor(BLACK);
		printf("  --- Le hasard  ");//8
		textbackground(BLACK);
		textcolor(WHITE);
		gotoxy(18,10);
		printf("  --- Les equipes favorite  ");//10
		gotoxy(18,12);
		printf("  --- Selon le hasard et Les equipes favorite  ");//12
		gotoxy(18,14);
		printf("  --- Selon le classement de la FIFA  ");//14
		gotoxy(58,8);
		char rep , rep1;
		while ( 1 )
		{
			rep = getch();
			if (  rep == 13 ) { goto Here; };
			if ( rep == (-32) )
			{
				rep1 = getch();
				if ( rep1 == 80 ) /* down */
				{
					gotoxy(18,wherey());
					switch ( wherey() )
					{
					case 8:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Le hasard  ");//8
						gotoxy(18,10);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Les equipes favorite  ");//10
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 10:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Les equipes favorite  ");//10
						gotoxy(18,12);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon le hasard et Les equipes favorite  ");//12
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 12:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon le hasard et Les equipes favorite  ");//12
						gotoxy(18,14);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon le classement de la FIFA  ");//14
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 14:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon le classement de la FIFA  ");//14
						gotoxy(18,8);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Le hasard  ");//8
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					default:
						break;
					}
				}
				else if ( rep1 == 72 ) /* up */
				{
					gotoxy(18,wherey());
					switch ( wherey() )
					{
					case 8:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Le hasard  ");
						gotoxy(18,14);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon le classement de la FIFA  ");//14
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 10:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Les equipes favorite  ");//10
						gotoxy(18,8);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Le hasard  ");//8
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 12:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon le hasard et Les equipes favorite  ");//12
						gotoxy(18,10);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Les equipes favorite  ");//10
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 14:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon le classement de la FIFA  ");//14
						gotoxy(18,12);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon le hasard et Les equipes favorite  ");//12
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					default:
						break;
					}
				} 
			}  
			

		}
Here:

		switch ( wherey() )
			{
			case 8:
				return 1;
				break;
			case 10:
				return 2;
				break;
			case 12:
				return 3;
				break;
			case 14:
				return 4;
				break;
			
			default:
				break;
			}

		
}

int Critere_Phase2(void)  
{
		cursor_effect(0);
		clrscr();
		textbackground(BLACK);
		textcolor(BLUE);
		gotoxy(43,3);
		printf("=== Choix des criteres de simulation de la phase 2 ===");
		printf("\n\n\n\n\n");
		textcolor(WHITE);

		gotoxy(18,8);
		textbackground(LIGHTBLUE);
		textcolor(BLACK);
		printf("  --- Le hasard  ");  //8
		textbackground(BLACK);
		textcolor(WHITE);
		gotoxy(18,10);
		printf("  --- Les equipes favorite  ");//10
		gotoxy(18,12);
		printf("  --- Selon les resultats de la premiere phase  ");//12
		gotoxy(18,14);
		printf("  --- Selon les resultats de la premiere phase et la deuxieme phase  ");//14
		gotoxy(18,16);
		printf("  --- Selon les resultats de la premiere phase et Les equipes favorite  ");//16
		gotoxy(18,18);
		printf("  --- Selon les resultats de la premiere phase et la deuxieme phase et Les equipes favorite  ");//18
		gotoxy(18,20);
		printf("  --- Selon le classement de la FIFA  ");//20


		gotoxy(58,8);
		char rep , rep1;
		while ( 1 )
		{
			rep = getch();
			if (  rep == 13 ) { goto Here; };
			if ( rep == (-32) )
			{
				rep1 = getch();
				if ( rep1 == 80 ) /* down */
				{
					gotoxy(18,wherey());
					switch ( wherey() )
					{
					case 8:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Le hasard  ");//8
						gotoxy(18,10);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Les equipes favorite  ");//10
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 10:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Les equipes favorite  ");//10
						gotoxy(18,12);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon les resultats de la premiere phase  ");//12
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 12:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon les resultats de la premiere phase  ");//12
						gotoxy(18,14);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon les resultats de la premiere phase et la deuxieme phase  ");//14
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 14:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon les resultats de la premiere phase et la deuxieme phase  ");//14
						gotoxy(18,16);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon les resultats de la premiere phase et Les equipes favorite  ");//16
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 16:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon les resultats de la premiere phase et Les equipes favorite  ");//16
						gotoxy(18,18);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon les resultats de la premiere phase et la deuxieme phase et Les equipes favorite  ");//18
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 18:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon les resultats de la premiere phase et la deuxieme phase et Les equipes favorite  ");//18
						gotoxy(18,20);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon le classement de la FIFA  ");//20
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 20:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon le classement de la FIFA  ");//14
						gotoxy(18,8);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Le hasard  ");//8
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					default:
						break;
					}
				}
				else if ( rep1 == 72 ) /* up */
				{
					gotoxy(18,wherey());
					
					gotoxy(18,wherey());
					switch ( wherey() )
					{
					case 8:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Le hasard  ");//8
						gotoxy(18,20);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon le classement de la FIFA  ");//14
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 10:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Les equipes favorite  ");//10
						gotoxy(18,8);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Le hasard  ");//8
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 12:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon les resultats de la premiere phase  ");//12
						gotoxy(18,10);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Les equipes favorite  ");//10
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 14:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon les resultats de la premiere phase et la deuxieme phase  ");//14
						gotoxy(18,12);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon les resultats de la premiere phase  ");//12
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 16:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon les resultats de la premiere phase et Les equipes favorite  ");//16
						gotoxy(18,14);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon les resultats de la premiere phase et la deuxieme phase  ");//14
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 18:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon les resultats de la premiere phase et la deuxieme phase et Les equipes favorite  ");//18
						gotoxy(18,16);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon les resultats de la premiere phase et Les equipes favorite  ");//16
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					case 20:
						textbackground(BLACK);
						textcolor(WHITE);
						printf("  --- Selon le classement de la FIFA  ");//14
						gotoxy(18,18);
						textbackground(LIGHTBLUE);
						textcolor(BLACK);
						printf("  --- Selon les resultats de la premiere phase et la deuxieme phase et Les equipes favorite  ");//18
						textbackground(BLACK);
						textcolor(WHITE);
						break;
					default:
						break;
					}
			}  
			
			}   
		}
Here:

		switch ( wherey() )
			{
			case 8:
				return 1;
				break;
			case 10:
				return 2;
				break;
			case 12:
				return 3;
				break;
			case 14:
				return 4;
				break;
			case 16:
				return 5;
				break;
			case 18:
				return 6;
				break;
			case 20:
				return 7;
				break;
			
			default:
				break;
			}
		
}

int Look_Eqp ( Typevect_V32i Table , int val )
{
	for ( int i = 0 ; i < 32 ; i++ )
	{
		if ( Table[i] == val )
		{
			return 1 ;
		}
	}
	return 0;
}

void Equipes_choix ( Typevect_V32i Equipes , string255 *Table )
{
	for (int i = 0 ; i < 32 ; i++)
	{
		Equipes[i] = 0;
	}	
	cursor_effect(1);
	int x , y , k;

	gotoxy(46,1);
	printf("== Choix des Equipes participantes au tournoi ==");
	y = 2;

	for ( int i = 1 ; i<=198 ; i++ )
	{
		switch ( (i-1)%5 )
		{
		case 0:
			x = 2;
			break;
		case 1:
			x = 29;
			break;
		case 2:
			x = 56;
			break;
		case 3:
			x = 85;
			break;
		case 4:
			x = 114;
			break;
		default:
			break;
		}
		
		if ( (i-1)%5 == 0 )
		{
			y++;
		}
		gotoxy(x,y);
		printf("%d - %s",i,Table[i-1]);
		if ( i % 5 == 0)
		{
			k++;
		}


	}
	int rep;
	for ( int i = 1 ; i <= 32 ; i++ )
	{
Error:
		gotoxy(60,44);
		printf("                                                                                ");
		gotoxy(1,45);
		printf("                                                                                ");
		gotoxy(60,44);
		if ( i == 1 )
		{
			printf("Entrez l'indexe de la 1 ere equipe : ");
		}
		else
		{
			printf("Entrez l'indexe le la %d eme equipe : ",i);

		}
		scanf("%d",&rep);
		if ( (Look_Eqp ( Equipes , rep ) == 1) || ( rep > 198 ) || ( rep < 0 ) )
		{
			goto Error;
		}
		Equipes[i-1] = rep ;
	}
	
}

int main(int argc, char *argv[])
		{
			cursor_effect(0);	
			srand(time(0));
			system("mode con cols=140 lines=45");
			Fifa = malloc(198 * 255  * sizeof(char));
			int _Izw2;for (_Izw2=0; _Izw2<198; ++_Izw2)
			Fifa[_Izw2]= malloc(255 * sizeof(char));
			Fav = malloc(198 * 255  * sizeof(char));
			int _Izw3;for (_Izw3=0; _Izw3<198; ++_Izw3)
			Fav[_Izw3]= malloc(255 * sizeof(char));
			Groups = malloc(8 * sizeof(Typestr_Tiiii));
			int _Izw4;for (_Izw4=0; _Izw4<8; ++_Izw4)
			Groups[_Izw4] = malloc( sizeof(Type_Tiiii ));
			Tab_listes = malloc(8 * sizeof(Pointeur_LTii));
			int _Izw5;for (_Izw5=0; _Izw5<8; ++_Izw5)
			Tab_listes[_Izw5] = malloc( sizeof(Pointeur_LTii ));
			Participants = malloc(32 * sizeof(int));
			
			Equipes = malloc(32 * sizeof(Typestr_Tisiii));
			int _Izw6;for (_Izw6=0; _Izw6<32; ++_Izw6)
			Equipes[_Izw6] = malloc( sizeof(Type_Tisiii ));
			int _Izw7;for (_Izw7=0; _Izw7<32; ++_Izw7){
			Equipes[_Izw7]->Champ2= malloc(255 * sizeof(char));}
			First = malloc(8 * sizeof(int));
			Second = malloc(8 * sizeof(int));
			
			/* Remplissage du Teableau FIFA */
			Aff_eq_fifa1 ( & Fifa ) ;
			Aff_eq_fifa2 ( & Fifa ) ;
			Aff_eq_fifa3 ( & Fifa ) ;
			Aff_eq_fifa4 ( & Fifa ) ;
			Aff_eq_fifa5 ( & Fifa ) ;
			/* Remplissage du Teableau des favoris */
			Aff_eq_fav1 ( & Fav ) ;
			Aff_eq_fav2 ( & Fav ) ;
			Aff_eq_fav3 ( & Fav ) ;
			Aff_eq_fav4 ( & Fav ) ;
			Aff_eq_fav5 ( & Fav ) ;
			/* Remplissages du Tableau des participants a la WC 2022 */
			
			Interface();
			clrscr();
			int choice ;
Tournoi:
			choice = Choix_du_tournoi();
			clrscr();
			



			if (choice == 3  )
			{
				goto End;
			}
			else if ( choice == 2 )
			{
				Equipes_choix(Participants,Fifa);
			}
			else
			{
				Fill_wc_22 ( & Participants ) ;
			}
			
			/* Remplissage des participants : favoris , Nom , et ID */
			Fill_participants ( & Participants , & Fifa , & Fav , & Equipes ) ;
			/* Creation des groupes */
			Create_groups ( & Equipes , & Groups ) ;
			/* Creation du Tableau des listes */
			Tab_liste_matches ( & Groups , & Tab_listes ) ;
			/* Entree du choix du mode de simulation de la phase 1 */
		 
			choice = Critere_Phase1 () ;
			clrscr();
			

			
		 
			/* Simulation de la phase une */
			Simuler_phase1 ( & Equipes , & Tab_listes , & choice , & First , & Second ) ;
			/* Affectation des premiers de groupes dans les tableaux */
			Group_winners ( & Groups , & Equipes , & First , & Second ) ;
			/* Affichage des equipes qualifies */
			Qualifies ( & First , & Second , & Equipes ) ;
			cursor_effect(1);
			choice = Critere_Phase2 ();
			clrscr();

			/* Creation de l'arbre */
			Arbre_phase2 ( & Phase_2 ) ;
			/* Empilage de l'arbre pour le parcours par niveau invrse */
			Empilage_arbre ( & Phase_2 , & Pile_parcours ) ;
			/* Affectation des 8emes */
			Remplissage_8eme ( & Pile_parcours , & First , & Second ) ;
			/* Simulation de la deuxieme phase */
			Simuler_phase2 ( & Pile_parcours , & Equipes , & choice ) ;
			goto Tournoi;
End:
			return 0;
}