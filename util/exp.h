/* A Bison parser, made by GNU Bison 1.875a.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_EXPORT = 258,
     T_RECORD = 259,
     T_STRUCT = 260,
     T_UNION = 261,
     T_IN = 262,
     T_IDENT = 263,
     T_STRING = 264
   };
#endif
#define T_EXPORT 258
#define T_RECORD 259
#define T_STRUCT 260
#define T_UNION 261
#define T_IN 262
#define T_IDENT 263
#define T_STRING 264




#if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
#line 119 "exp.y"
typedef union YYSTYPE {
	char  	s[IDENT_LEN+1];
} YYSTYPE;
/* Line 1240 of yacc.c.  */
#line 59 "y.tab.h"
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;



