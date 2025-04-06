
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MainPrgm = 258,
     idf = 259,
     pnt_virgul = 260,
     var = 261,
     BeginPg = 262,
     accolade_ouvr = 263,
     accolade_ferm = 264,
     EndPg = 265,
     let = 266,
     deux_pnts = 267,
     constante = 268,
     egal = 269,
     virgul = 270,
     reel = 271,
     entier = 272,
     entier_pos = 273,
     corechet_ouvr = 274,
     corechet_ferm = 275,
     entier_neg = 276,
     reel_pos = 277,
     reel_neg = 278,
     affect = 279,
     chaine = 280,
     if_cond = 281,
     then = 282,
     parenthese_ferm = 283,
     parenthese_ouvr = 284,
     lire = 285,
     output = 286,
     add = 287,
     soustract = 288,
     division = 289,
     multipl = 290,
     inf = 291,
     sup = 292,
     inf_ou_egal = 293,
     sup_ou_egal = 294,
     neg = 295,
     and = 296,
     or = 297,
     diff = 298,
     boucle_for = 299,
     from = 300,
     to = 301,
     step = 302,
     boucle_do = 303,
     boucle_while = 304,
     else_cond = 305,
     identiq = 306
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


