// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "verilog_parser.tab.hh"


// Unqualified %code blocks.
#line 32 "verilog_parser.yy"

  #include <iostream>
  #include <cstdlib>
  #include <fstream>
  #include <utility>
  #include <tuple>
  
   /* include for all driver functions */
  #include "verilog_driver.hpp"

#undef yylex
#define yylex scanner.yylex

#line 60 "verilog_parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "verilog_parser.yy"
namespace verilog {
#line 153 "verilog_parser.tab.cc"

  /// Build a parser object.
  VerilogParser::VerilogParser (VerilogScanner &scanner_yyarg, ParserVerilogInterface *driver_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  VerilogParser::~VerilogParser ()
  {}

  VerilogParser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  VerilogParser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_net_by_name: // net_by_name
        value.copy< std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_inst_pins: // inst_pins
      case symbol_kind::S_nets_by_name: // nets_by_name
        value.copy< std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_port_type: // port_type
        value.copy< std::pair<verilog::PortDirection, verilog::ConnectionType> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ESCAPED_NAME: // ESCAPED_NAME
      case symbol_kind::S_valid_name: // valid_name
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lhs: // lhs
      case symbol_kind::S_lhs_concat: // lhs_concat
      case symbol_kind::S_lhs_exprs: // lhs_exprs
      case symbol_kind::S_lhs_expr: // lhs_expr
        value.copy< std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_nets_by_position: // nets_by_position
        value.copy< std::vector<std::vector<verilog::NetConcat>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_rhs: // rhs
      case symbol_kind::S_rhs_concat: // rhs_concat
      case symbol_kind::S_rhs_exprs: // rhs_exprs
      case symbol_kind::S_rhs_expr: // rhs_expr
        value.copy< std::vector<verilog::NetConcat> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.copy< verilog::Assignment > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_BINARY: // BINARY
      case symbol_kind::S_OCTAL: // OCTAL
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_constant: // constant
        value.copy< verilog::Constant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instance: // instance
        value.copy< verilog::Instance > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_net_decl_statements: // net_decl_statements
      case symbol_kind::S_net_decl: // net_decl
        value.copy< verilog::Net > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_net_type: // net_type
        value.copy< verilog::NetType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_port_declarations: // port_declarations
      case symbol_kind::S_port_decl: // port_decl
      case symbol_kind::S_port_decl_statements: // port_decl_statements
        value.copy< verilog::Port > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  VerilogParser::symbol_kind_type
  VerilogParser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  VerilogParser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  VerilogParser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_net_by_name: // net_by_name
        value.move< std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_inst_pins: // inst_pins
      case symbol_kind::S_nets_by_name: // nets_by_name
        value.move< std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_port_type: // port_type
        value.move< std::pair<verilog::PortDirection, verilog::ConnectionType> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ESCAPED_NAME: // ESCAPED_NAME
      case symbol_kind::S_valid_name: // valid_name
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_lhs: // lhs
      case symbol_kind::S_lhs_concat: // lhs_concat
      case symbol_kind::S_lhs_exprs: // lhs_exprs
      case symbol_kind::S_lhs_expr: // lhs_expr
        value.move< std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_nets_by_position: // nets_by_position
        value.move< std::vector<std::vector<verilog::NetConcat>> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_rhs: // rhs
      case symbol_kind::S_rhs_concat: // rhs_concat
      case symbol_kind::S_rhs_exprs: // rhs_exprs
      case symbol_kind::S_rhs_expr: // rhs_expr
        value.move< std::vector<verilog::NetConcat> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.move< verilog::Assignment > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_BINARY: // BINARY
      case symbol_kind::S_OCTAL: // OCTAL
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_constant: // constant
        value.move< verilog::Constant > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_instance: // instance
        value.move< verilog::Instance > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_net_decl_statements: // net_decl_statements
      case symbol_kind::S_net_decl: // net_decl
        value.move< verilog::Net > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_net_type: // net_type
        value.move< verilog::NetType > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_port_declarations: // port_declarations
      case symbol_kind::S_port_decl: // port_decl
      case symbol_kind::S_port_decl_statements: // port_decl_statements
        value.move< verilog::Port > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  VerilogParser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  VerilogParser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  VerilogParser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  VerilogParser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  VerilogParser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  VerilogParser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  VerilogParser::symbol_kind_type
  VerilogParser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  VerilogParser::symbol_kind_type
  VerilogParser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  VerilogParser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  VerilogParser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  VerilogParser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  VerilogParser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  VerilogParser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  VerilogParser::symbol_kind_type
  VerilogParser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  VerilogParser::stack_symbol_type::stack_symbol_type ()
  {}

  VerilogParser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_net_by_name: // net_by_name
        value.YY_MOVE_OR_COPY< std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_inst_pins: // inst_pins
      case symbol_kind::S_nets_by_name: // nets_by_name
        value.YY_MOVE_OR_COPY< std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_port_type: // port_type
        value.YY_MOVE_OR_COPY< std::pair<verilog::PortDirection, verilog::ConnectionType> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ESCAPED_NAME: // ESCAPED_NAME
      case symbol_kind::S_valid_name: // valid_name
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lhs: // lhs
      case symbol_kind::S_lhs_concat: // lhs_concat
      case symbol_kind::S_lhs_exprs: // lhs_exprs
      case symbol_kind::S_lhs_expr: // lhs_expr
        value.YY_MOVE_OR_COPY< std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_nets_by_position: // nets_by_position
        value.YY_MOVE_OR_COPY< std::vector<std::vector<verilog::NetConcat>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_rhs: // rhs
      case symbol_kind::S_rhs_concat: // rhs_concat
      case symbol_kind::S_rhs_exprs: // rhs_exprs
      case symbol_kind::S_rhs_expr: // rhs_expr
        value.YY_MOVE_OR_COPY< std::vector<verilog::NetConcat> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.YY_MOVE_OR_COPY< verilog::Assignment > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_BINARY: // BINARY
      case symbol_kind::S_OCTAL: // OCTAL
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_constant: // constant
        value.YY_MOVE_OR_COPY< verilog::Constant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instance: // instance
        value.YY_MOVE_OR_COPY< verilog::Instance > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_net_decl_statements: // net_decl_statements
      case symbol_kind::S_net_decl: // net_decl
        value.YY_MOVE_OR_COPY< verilog::Net > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_net_type: // net_type
        value.YY_MOVE_OR_COPY< verilog::NetType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_port_declarations: // port_declarations
      case symbol_kind::S_port_decl: // port_decl
      case symbol_kind::S_port_decl_statements: // port_decl_statements
        value.YY_MOVE_OR_COPY< verilog::Port > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  VerilogParser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_net_by_name: // net_by_name
        value.move< std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_inst_pins: // inst_pins
      case symbol_kind::S_nets_by_name: // nets_by_name
        value.move< std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_port_type: // port_type
        value.move< std::pair<verilog::PortDirection, verilog::ConnectionType> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ESCAPED_NAME: // ESCAPED_NAME
      case symbol_kind::S_valid_name: // valid_name
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_lhs: // lhs
      case symbol_kind::S_lhs_concat: // lhs_concat
      case symbol_kind::S_lhs_exprs: // lhs_exprs
      case symbol_kind::S_lhs_expr: // lhs_expr
        value.move< std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_nets_by_position: // nets_by_position
        value.move< std::vector<std::vector<verilog::NetConcat>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_rhs: // rhs
      case symbol_kind::S_rhs_concat: // rhs_concat
      case symbol_kind::S_rhs_exprs: // rhs_exprs
      case symbol_kind::S_rhs_expr: // rhs_expr
        value.move< std::vector<verilog::NetConcat> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.move< verilog::Assignment > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_BINARY: // BINARY
      case symbol_kind::S_OCTAL: // OCTAL
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_constant: // constant
        value.move< verilog::Constant > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_instance: // instance
        value.move< verilog::Instance > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_net_decl_statements: // net_decl_statements
      case symbol_kind::S_net_decl: // net_decl
        value.move< verilog::Net > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_net_type: // net_type
        value.move< verilog::NetType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_port_declarations: // port_declarations
      case symbol_kind::S_port_decl: // port_decl
      case symbol_kind::S_port_decl_statements: // port_decl_statements
        value.move< verilog::Port > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  VerilogParser::stack_symbol_type&
  VerilogParser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_net_by_name: // net_by_name
        value.copy< std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > (that.value);
        break;

      case symbol_kind::S_inst_pins: // inst_pins
      case symbol_kind::S_nets_by_name: // nets_by_name
        value.copy< std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > (that.value);
        break;

      case symbol_kind::S_port_type: // port_type
        value.copy< std::pair<verilog::PortDirection, verilog::ConnectionType> > (that.value);
        break;

      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ESCAPED_NAME: // ESCAPED_NAME
      case symbol_kind::S_valid_name: // valid_name
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_lhs: // lhs
      case symbol_kind::S_lhs_concat: // lhs_concat
      case symbol_kind::S_lhs_exprs: // lhs_exprs
      case symbol_kind::S_lhs_expr: // lhs_expr
        value.copy< std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > (that.value);
        break;

      case symbol_kind::S_nets_by_position: // nets_by_position
        value.copy< std::vector<std::vector<verilog::NetConcat>> > (that.value);
        break;

      case symbol_kind::S_rhs: // rhs
      case symbol_kind::S_rhs_concat: // rhs_concat
      case symbol_kind::S_rhs_exprs: // rhs_exprs
      case symbol_kind::S_rhs_expr: // rhs_expr
        value.copy< std::vector<verilog::NetConcat> > (that.value);
        break;

      case symbol_kind::S_assignment: // assignment
        value.copy< verilog::Assignment > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_BINARY: // BINARY
      case symbol_kind::S_OCTAL: // OCTAL
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_constant: // constant
        value.copy< verilog::Constant > (that.value);
        break;

      case symbol_kind::S_instance: // instance
        value.copy< verilog::Instance > (that.value);
        break;

      case symbol_kind::S_net_decl_statements: // net_decl_statements
      case symbol_kind::S_net_decl: // net_decl
        value.copy< verilog::Net > (that.value);
        break;

      case symbol_kind::S_net_type: // net_type
        value.copy< verilog::NetType > (that.value);
        break;

      case symbol_kind::S_port_declarations: // port_declarations
      case symbol_kind::S_port_decl: // port_decl
      case symbol_kind::S_port_decl_statements: // port_decl_statements
        value.copy< verilog::Port > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  VerilogParser::stack_symbol_type&
  VerilogParser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_net_by_name: // net_by_name
        value.move< std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > (that.value);
        break;

      case symbol_kind::S_inst_pins: // inst_pins
      case symbol_kind::S_nets_by_name: // nets_by_name
        value.move< std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > (that.value);
        break;

      case symbol_kind::S_port_type: // port_type
        value.move< std::pair<verilog::PortDirection, verilog::ConnectionType> > (that.value);
        break;

      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ESCAPED_NAME: // ESCAPED_NAME
      case symbol_kind::S_valid_name: // valid_name
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_lhs: // lhs
      case symbol_kind::S_lhs_concat: // lhs_concat
      case symbol_kind::S_lhs_exprs: // lhs_exprs
      case symbol_kind::S_lhs_expr: // lhs_expr
        value.move< std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > (that.value);
        break;

      case symbol_kind::S_nets_by_position: // nets_by_position
        value.move< std::vector<std::vector<verilog::NetConcat>> > (that.value);
        break;

      case symbol_kind::S_rhs: // rhs
      case symbol_kind::S_rhs_concat: // rhs_concat
      case symbol_kind::S_rhs_exprs: // rhs_exprs
      case symbol_kind::S_rhs_expr: // rhs_expr
        value.move< std::vector<verilog::NetConcat> > (that.value);
        break;

      case symbol_kind::S_assignment: // assignment
        value.move< verilog::Assignment > (that.value);
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_BINARY: // BINARY
      case symbol_kind::S_OCTAL: // OCTAL
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_constant: // constant
        value.move< verilog::Constant > (that.value);
        break;

      case symbol_kind::S_instance: // instance
        value.move< verilog::Instance > (that.value);
        break;

      case symbol_kind::S_net_decl_statements: // net_decl_statements
      case symbol_kind::S_net_decl: // net_decl
        value.move< verilog::Net > (that.value);
        break;

      case symbol_kind::S_net_type: // net_type
        value.move< verilog::NetType > (that.value);
        break;

      case symbol_kind::S_port_declarations: // port_declarations
      case symbol_kind::S_port_decl: // port_decl
      case symbol_kind::S_port_decl_statements: // port_decl_statements
        value.move< verilog::Port > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  VerilogParser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  VerilogParser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  VerilogParser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  VerilogParser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  VerilogParser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  VerilogParser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  VerilogParser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  VerilogParser::debug_level_type
  VerilogParser::debug_level () const
  {
    return yydebug_;
  }

  void
  VerilogParser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  VerilogParser::state_type
  VerilogParser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  VerilogParser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  VerilogParser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  VerilogParser::operator() ()
  {
    return parse ();
  }

  int
  VerilogParser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_net_by_name: // net_by_name
        yylhs.value.emplace< std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ();
        break;

      case symbol_kind::S_inst_pins: // inst_pins
      case symbol_kind::S_nets_by_name: // nets_by_name
        yylhs.value.emplace< std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ();
        break;

      case symbol_kind::S_port_type: // port_type
        yylhs.value.emplace< std::pair<verilog::PortDirection, verilog::ConnectionType> > ();
        break;

      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ESCAPED_NAME: // ESCAPED_NAME
      case symbol_kind::S_valid_name: // valid_name
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_lhs: // lhs
      case symbol_kind::S_lhs_concat: // lhs_concat
      case symbol_kind::S_lhs_exprs: // lhs_exprs
      case symbol_kind::S_lhs_expr: // lhs_expr
        yylhs.value.emplace< std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ();
        break;

      case symbol_kind::S_nets_by_position: // nets_by_position
        yylhs.value.emplace< std::vector<std::vector<verilog::NetConcat>> > ();
        break;

      case symbol_kind::S_rhs: // rhs
      case symbol_kind::S_rhs_concat: // rhs_concat
      case symbol_kind::S_rhs_exprs: // rhs_exprs
      case symbol_kind::S_rhs_expr: // rhs_expr
        yylhs.value.emplace< std::vector<verilog::NetConcat> > ();
        break;

      case symbol_kind::S_assignment: // assignment
        yylhs.value.emplace< verilog::Assignment > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_BINARY: // BINARY
      case symbol_kind::S_OCTAL: // OCTAL
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_constant: // constant
        yylhs.value.emplace< verilog::Constant > ();
        break;

      case symbol_kind::S_instance: // instance
        yylhs.value.emplace< verilog::Instance > ();
        break;

      case symbol_kind::S_net_decl_statements: // net_decl_statements
      case symbol_kind::S_net_decl: // net_decl
        yylhs.value.emplace< verilog::Net > ();
        break;

      case symbol_kind::S_net_type: // net_type
        yylhs.value.emplace< verilog::NetType > ();
        break;

      case symbol_kind::S_port_declarations: // port_declarations
      case symbol_kind::S_port_decl: // port_decl
      case symbol_kind::S_port_decl_statements: // port_decl_statements
        yylhs.value.emplace< verilog::Port > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // valid_name: NAME
#line 95 "verilog_parser.yy"
         { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1140 "verilog_parser.tab.cc"
    break;

  case 3: // valid_name: ESCAPED_NAME
#line 96 "verilog_parser.yy"
                 { yylhs.value.as < std::string > () = yystack_[0].value.as < std::string > (); }
#line 1146 "verilog_parser.tab.cc"
    break;

  case 7: // $@1: %empty
#line 109 "verilog_parser.yy"
    { 
      driver->add_module(std::move(yystack_[1].value.as < std::string > ()));
    }
#line 1154 "verilog_parser.tab.cc"
    break;

  case 9: // $@2: %empty
#line 114 "verilog_parser.yy"
    {
      driver->add_module(std::move(yystack_[3].value.as < std::string > ()));
    }
#line 1162 "verilog_parser.tab.cc"
    break;

  case 11: // $@3: %empty
#line 119 "verilog_parser.yy"
    {
      driver->add_module(std::move(yystack_[4].value.as < std::string > ()));
    }
#line 1170 "verilog_parser.tab.cc"
    break;

  case 13: // $@4: %empty
#line 124 "verilog_parser.yy"
    { 
      driver->add_module(std::move(yystack_[1].value.as < std::string > ())); 
    }
#line 1178 "verilog_parser.tab.cc"
    break;

  case 14: // $@5: %empty
#line 128 "verilog_parser.yy"
    { 
      driver->add_port(std::move(yystack_[1].value.as < verilog::Port > ())); 
    }
#line 1186 "verilog_parser.tab.cc"
    break;

  case 16: // port_names: valid_name
#line 136 "verilog_parser.yy"
               { }
#line 1192 "verilog_parser.tab.cc"
    break;

  case 17: // port_names: port_names ',' valid_name
#line 137 "verilog_parser.yy"
                               { }
#line 1198 "verilog_parser.tab.cc"
    break;

  case 18: // port_type: INPUT
#line 142 "verilog_parser.yy"
               { yylhs.value.as < std::pair<verilog::PortDirection, verilog::ConnectionType> > () = std::make_pair(verilog::PortDirection::INPUT, verilog::ConnectionType::NONE); }
#line 1204 "verilog_parser.tab.cc"
    break;

  case 19: // port_type: INPUT WIRE
#line 143 "verilog_parser.yy"
               { yylhs.value.as < std::pair<verilog::PortDirection, verilog::ConnectionType> > () = std::make_pair(verilog::PortDirection::INPUT, verilog::ConnectionType::WIRE); }
#line 1210 "verilog_parser.tab.cc"
    break;

  case 20: // port_type: OUTPUT
#line 144 "verilog_parser.yy"
               { yylhs.value.as < std::pair<verilog::PortDirection, verilog::ConnectionType> > () = std::make_pair(verilog::PortDirection::OUTPUT,verilog::ConnectionType::NONE); }
#line 1216 "verilog_parser.tab.cc"
    break;

  case 21: // port_type: OUTPUT REG
#line 145 "verilog_parser.yy"
               { yylhs.value.as < std::pair<verilog::PortDirection, verilog::ConnectionType> > () = std::make_pair(verilog::PortDirection::OUTPUT,verilog::ConnectionType::REG);  }
#line 1222 "verilog_parser.tab.cc"
    break;

  case 22: // port_type: INOUT
#line 146 "verilog_parser.yy"
               { yylhs.value.as < std::pair<verilog::PortDirection, verilog::ConnectionType> > () = std::make_pair(verilog::PortDirection::INOUT, verilog::ConnectionType::NONE); }
#line 1228 "verilog_parser.tab.cc"
    break;

  case 23: // port_type: INOUT WIRE
#line 147 "verilog_parser.yy"
               { yylhs.value.as < std::pair<verilog::PortDirection, verilog::ConnectionType> > () = std::make_pair(verilog::PortDirection::INOUT, verilog::ConnectionType::WIRE); }
#line 1234 "verilog_parser.tab.cc"
    break;

  case 24: // port_type: INOUT REG
#line 148 "verilog_parser.yy"
               { yylhs.value.as < std::pair<verilog::PortDirection, verilog::ConnectionType> > () = std::make_pair(verilog::PortDirection::INOUT, verilog::ConnectionType::REG);  }
#line 1240 "verilog_parser.tab.cc"
    break;

  case 25: // port_declarations: port_decl
#line 154 "verilog_parser.yy"
    {
      yylhs.value.as < verilog::Port > () = yystack_[0].value.as < verilog::Port > ();
    }
#line 1248 "verilog_parser.tab.cc"
    break;

  case 26: // port_declarations: port_declarations ',' port_decl
#line 158 "verilog_parser.yy"
    {
      driver->add_port(std::move(yystack_[2].value.as < verilog::Port > ()));
      yylhs.value.as < verilog::Port > () = yystack_[0].value.as < verilog::Port > ();
    }
#line 1257 "verilog_parser.tab.cc"
    break;

  case 27: // port_declarations: port_declarations ',' valid_name
#line 163 "verilog_parser.yy"
    {
      yystack_[2].value.as < verilog::Port > ().names.emplace_back(std::move(yystack_[0].value.as < std::string > ()));    
      yylhs.value.as < verilog::Port > () = yystack_[2].value.as < verilog::Port > ();
    }
#line 1266 "verilog_parser.tab.cc"
    break;

  case 28: // port_decl: port_type valid_name
#line 171 "verilog_parser.yy"
    {
      yylhs.value.as < verilog::Port > ().dir  = std::get<0>(yystack_[1].value.as < std::pair<verilog::PortDirection, verilog::ConnectionType> > ());
      yylhs.value.as < verilog::Port > ().type = std::get<1>(yystack_[1].value.as < std::pair<verilog::PortDirection, verilog::ConnectionType> > ());
      yylhs.value.as < verilog::Port > ().names.emplace_back(std::move(yystack_[0].value.as < std::string > ())); 
    }
#line 1276 "verilog_parser.tab.cc"
    break;

  case 29: // port_decl: port_type '[' INTEGER ':' INTEGER ']' valid_name
#line 177 "verilog_parser.yy"
    {
      yylhs.value.as < verilog::Port > ().dir  = std::get<0>(yystack_[6].value.as < std::pair<verilog::PortDirection, verilog::ConnectionType> > ());
      yylhs.value.as < verilog::Port > ().type = std::get<1>(yystack_[6].value.as < std::pair<verilog::PortDirection, verilog::ConnectionType> > ());
      yylhs.value.as < verilog::Port > ().beg = std::stoi(yystack_[4].value.as < verilog::Constant > ().value);
      yylhs.value.as < verilog::Port > ().end = std::stoi(yystack_[2].value.as < verilog::Constant > ().value);
      yylhs.value.as < verilog::Port > ().names.push_back(std::move(yystack_[0].value.as < std::string > ())); 
    }
#line 1288 "verilog_parser.tab.cc"
    break;

  case 35: // declaration: port_decl_statements ';'
#line 199 "verilog_parser.yy"
                             { driver->add_port(std::move(yystack_[1].value.as < verilog::Port > ())); }
#line 1294 "verilog_parser.tab.cc"
    break;

  case 36: // declaration: net_decl_statements ';'
#line 200 "verilog_parser.yy"
                             { driver->add_net(std::move(yystack_[1].value.as < verilog::Net > ())); }
#line 1300 "verilog_parser.tab.cc"
    break;

  case 37: // port_decl_statements: port_decl
#line 206 "verilog_parser.yy"
    {
      yylhs.value.as < verilog::Port > () = yystack_[0].value.as < verilog::Port > ();
    }
#line 1308 "verilog_parser.tab.cc"
    break;

  case 38: // port_decl_statements: port_decl_statements ',' valid_name
#line 210 "verilog_parser.yy"
    {
      yystack_[2].value.as < verilog::Port > ().names.emplace_back(std::move(yystack_[0].value.as < std::string > ()));    
      yylhs.value.as < verilog::Port > () = yystack_[2].value.as < verilog::Port > ();
    }
#line 1317 "verilog_parser.tab.cc"
    break;

  case 39: // net_type: WIRE
#line 218 "verilog_parser.yy"
             { yylhs.value.as < verilog::NetType > () = verilog::NetType::WIRE;    }
#line 1323 "verilog_parser.tab.cc"
    break;

  case 40: // net_type: WAND
#line 219 "verilog_parser.yy"
             { yylhs.value.as < verilog::NetType > () = verilog::NetType::WAND;    }
#line 1329 "verilog_parser.tab.cc"
    break;

  case 41: // net_type: WOR
#line 220 "verilog_parser.yy"
             { yylhs.value.as < verilog::NetType > () = verilog::NetType::WOR;     }
#line 1335 "verilog_parser.tab.cc"
    break;

  case 42: // net_type: TRI
#line 221 "verilog_parser.yy"
             { yylhs.value.as < verilog::NetType > () = verilog::NetType::TRI;     }
#line 1341 "verilog_parser.tab.cc"
    break;

  case 43: // net_type: TRIOR
#line 222 "verilog_parser.yy"
             { yylhs.value.as < verilog::NetType > () = verilog::NetType::TRIOR;   }
#line 1347 "verilog_parser.tab.cc"
    break;

  case 44: // net_type: TRIAND
#line 223 "verilog_parser.yy"
             { yylhs.value.as < verilog::NetType > () = verilog::NetType::TRIAND;  }
#line 1353 "verilog_parser.tab.cc"
    break;

  case 45: // net_type: SUPPLY0
#line 224 "verilog_parser.yy"
             { yylhs.value.as < verilog::NetType > () = verilog::NetType::SUPPLY0; }
#line 1359 "verilog_parser.tab.cc"
    break;

  case 46: // net_type: SUPPLY1
#line 225 "verilog_parser.yy"
             { yylhs.value.as < verilog::NetType > () = verilog::NetType::SUPPLY1; }
#line 1365 "verilog_parser.tab.cc"
    break;

  case 47: // net_decl_statements: net_decl
#line 230 "verilog_parser.yy"
    {
      yylhs.value.as < verilog::Net > () = yystack_[0].value.as < verilog::Net > ();
    }
#line 1373 "verilog_parser.tab.cc"
    break;

  case 48: // net_decl_statements: net_decl_statements ',' valid_name
#line 234 "verilog_parser.yy"
    {
      yystack_[2].value.as < verilog::Net > ().names.push_back(std::move(yystack_[0].value.as < std::string > ()));
      yylhs.value.as < verilog::Net > () = yystack_[2].value.as < verilog::Net > ();
    }
#line 1382 "verilog_parser.tab.cc"
    break;

  case 49: // net_decl_statements: net_decl_statements ',' assignment
#line 239 "verilog_parser.yy"
    {
      yystack_[2].value.as < verilog::Net > ().names.push_back(std::move(std::get<std::string>(yystack_[0].value.as < verilog::Assignment > ().lhs[0])));
      yylhs.value.as < verilog::Net > () = yystack_[2].value.as < verilog::Net > ();
    }
#line 1391 "verilog_parser.tab.cc"
    break;

  case 50: // net_decl: net_type valid_name
#line 247 "verilog_parser.yy"
    {
      yylhs.value.as < verilog::Net > ().type = yystack_[1].value.as < verilog::NetType > ();
      yylhs.value.as < verilog::Net > ().names.push_back(std::move(yystack_[0].value.as < std::string > ())); 
    }
#line 1400 "verilog_parser.tab.cc"
    break;

  case 51: // net_decl: net_type '[' INTEGER ':' INTEGER ']' valid_name
#line 252 "verilog_parser.yy"
    {
      yylhs.value.as < verilog::Net > ().type = yystack_[6].value.as < verilog::NetType > ();
      yylhs.value.as < verilog::Net > ().beg = std::stoi(yystack_[4].value.as < verilog::Constant > ().value);
      yylhs.value.as < verilog::Net > ().end = std::stoi(yystack_[2].value.as < verilog::Constant > ().value);
      yylhs.value.as < verilog::Net > ().names.push_back(std::move(yystack_[0].value.as < std::string > ())); 
    }
#line 1411 "verilog_parser.tab.cc"
    break;

  case 52: // net_decl: net_type assignment
#line 259 "verilog_parser.yy"
    {
      yylhs.value.as < verilog::Net > ().type = yystack_[1].value.as < verilog::NetType > ();
      yylhs.value.as < verilog::Net > ().names.push_back(std::move(std::get<std::string>(yystack_[0].value.as < verilog::Assignment > ().lhs[0])));
    }
#line 1420 "verilog_parser.tab.cc"
    break;

  case 53: // net_decl: net_type '[' INTEGER ':' INTEGER ']' assignment
#line 264 "verilog_parser.yy"
    {
      yylhs.value.as < verilog::Net > ().type = yystack_[6].value.as < verilog::NetType > ();
      yylhs.value.as < verilog::Net > ().beg = std::stoi(yystack_[4].value.as < verilog::Constant > ().value);
      yylhs.value.as < verilog::Net > ().end = std::stoi(yystack_[2].value.as < verilog::Constant > ().value);
      yylhs.value.as < verilog::Net > ().names.push_back(std::move(std::get<std::string>(yystack_[0].value.as < verilog::Assignment > ().lhs[0])));
    }
#line 1431 "verilog_parser.tab.cc"
    break;

  case 57: // assignment: lhs '=' rhs
#line 283 "verilog_parser.yy"
    {
      yylhs.value.as < verilog::Assignment > ().lhs = yystack_[2].value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > (); 
      yylhs.value.as < verilog::Assignment > ().rhs = yystack_[0].value.as < std::vector<verilog::NetConcat> > ();
      driver->add_assignment(std::move(yylhs.value.as < verilog::Assignment > ()));
      yylhs.value.as < verilog::Assignment > ().lhs = yystack_[2].value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ();
    }
#line 1442 "verilog_parser.tab.cc"
    break;

  case 58: // lhs: valid_name
#line 294 "verilog_parser.yy"
               { yylhs.value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().push_back(std::move(yystack_[0].value.as < std::string > ())); }
#line 1448 "verilog_parser.tab.cc"
    break;

  case 59: // lhs: valid_name '[' INTEGER ']'
#line 296 "verilog_parser.yy"
    { yylhs.value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().emplace_back(verilog::NetBit(std::move(yystack_[3].value.as < std::string > ()), std::stoi(yystack_[1].value.as < verilog::Constant > ().value))); }
#line 1454 "verilog_parser.tab.cc"
    break;

  case 60: // lhs: valid_name '[' INTEGER ':' INTEGER ']'
#line 298 "verilog_parser.yy"
    { yylhs.value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().emplace_back(verilog::NetRange(std::move(yystack_[5].value.as < std::string > ()), std::stoi(yystack_[3].value.as < verilog::Constant > ().value), std::stoi(yystack_[1].value.as < verilog::Constant > ().value))); }
#line 1460 "verilog_parser.tab.cc"
    break;

  case 61: // lhs: lhs_concat
#line 299 "verilog_parser.yy"
               { yylhs.value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > () = yystack_[0].value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > (); }
#line 1466 "verilog_parser.tab.cc"
    break;

  case 62: // lhs_concat: '{' lhs_exprs '}'
#line 303 "verilog_parser.yy"
                      { std::move(yystack_[1].value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().begin(), yystack_[1].value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().end(), std::back_inserter(yylhs.value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ())); }
#line 1472 "verilog_parser.tab.cc"
    break;

  case 63: // lhs_exprs: lhs_expr
#line 307 "verilog_parser.yy"
             { std::move(yystack_[0].value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().begin(), yystack_[0].value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().end(), std::back_inserter(yylhs.value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ())); }
#line 1478 "verilog_parser.tab.cc"
    break;

  case 64: // lhs_exprs: lhs_exprs ',' lhs_expr
#line 309 "verilog_parser.yy"
    { 
      std::move(yystack_[2].value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().begin(), yystack_[2].value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().end(), std::back_inserter(yylhs.value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ()));
      std::move(yystack_[0].value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().begin(), yystack_[0].value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().end(), std::back_inserter(yylhs.value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ()));
    }
#line 1487 "verilog_parser.tab.cc"
    break;

  case 65: // lhs_expr: valid_name
#line 316 "verilog_parser.yy"
               { yylhs.value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().push_back(std::move(yystack_[0].value.as < std::string > ())); }
#line 1493 "verilog_parser.tab.cc"
    break;

  case 66: // lhs_expr: valid_name '[' INTEGER ']'
#line 318 "verilog_parser.yy"
    { yylhs.value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().emplace_back(verilog::NetBit(std::move(yystack_[3].value.as < std::string > ()), std::stoi(yystack_[1].value.as < verilog::Constant > ().value))); }
#line 1499 "verilog_parser.tab.cc"
    break;

  case 67: // lhs_expr: valid_name '[' INTEGER ':' INTEGER ']'
#line 320 "verilog_parser.yy"
    { yylhs.value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().emplace_back(verilog::NetRange(std::move(yystack_[5].value.as < std::string > ()), std::stoi(yystack_[3].value.as < verilog::Constant > ().value), std::stoi(yystack_[1].value.as < verilog::Constant > ().value))); }
#line 1505 "verilog_parser.tab.cc"
    break;

  case 68: // lhs_expr: lhs_concat
#line 322 "verilog_parser.yy"
    { std::move(yystack_[0].value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().begin(), yystack_[0].value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ().end(), std::back_inserter(yylhs.value.as < std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ())); }
#line 1511 "verilog_parser.tab.cc"
    break;

  case 69: // constant: INTEGER
#line 328 "verilog_parser.yy"
             { yylhs.value.as < verilog::Constant > ()=yystack_[0].value.as < verilog::Constant > (); }
#line 1517 "verilog_parser.tab.cc"
    break;

  case 70: // constant: BINARY
#line 329 "verilog_parser.yy"
           { yylhs.value.as < verilog::Constant > ()=yystack_[0].value.as < verilog::Constant > (); }
#line 1523 "verilog_parser.tab.cc"
    break;

  case 71: // constant: OCTAL
#line 330 "verilog_parser.yy"
          { yylhs.value.as < verilog::Constant > ()=yystack_[0].value.as < verilog::Constant > (); }
#line 1529 "verilog_parser.tab.cc"
    break;

  case 72: // constant: DECIMAL
#line 331 "verilog_parser.yy"
            { yylhs.value.as < verilog::Constant > ()=yystack_[0].value.as < verilog::Constant > (); }
#line 1535 "verilog_parser.tab.cc"
    break;

  case 73: // constant: HEX
#line 332 "verilog_parser.yy"
        { yylhs.value.as < verilog::Constant > ()=yystack_[0].value.as < verilog::Constant > (); }
#line 1541 "verilog_parser.tab.cc"
    break;

  case 74: // constant: REAL
#line 333 "verilog_parser.yy"
         { yylhs.value.as < verilog::Constant > ()=yystack_[0].value.as < verilog::Constant > (); }
#line 1547 "verilog_parser.tab.cc"
    break;

  case 75: // constant: EXP
#line 334 "verilog_parser.yy"
         { yylhs.value.as < verilog::Constant > ()=yystack_[0].value.as < verilog::Constant > (); }
#line 1553 "verilog_parser.tab.cc"
    break;

  case 76: // rhs: valid_name
#line 338 "verilog_parser.yy"
               { yylhs.value.as < std::vector<verilog::NetConcat> > ().emplace_back(yystack_[0].value.as < std::string > ()); }
#line 1559 "verilog_parser.tab.cc"
    break;

  case 77: // rhs: valid_name '[' INTEGER ']'
#line 340 "verilog_parser.yy"
    { yylhs.value.as < std::vector<verilog::NetConcat> > ().emplace_back(verilog::NetBit(std::move(yystack_[3].value.as < std::string > ()), std::stoi(yystack_[1].value.as < verilog::Constant > ().value))); }
#line 1565 "verilog_parser.tab.cc"
    break;

  case 78: // rhs: valid_name '[' INTEGER ':' INTEGER ']'
#line 342 "verilog_parser.yy"
    { yylhs.value.as < std::vector<verilog::NetConcat> > ().emplace_back(verilog::NetRange(std::move(yystack_[5].value.as < std::string > ()), std::stoi(yystack_[3].value.as < verilog::Constant > ().value), std::stoi(yystack_[1].value.as < verilog::Constant > ().value))); }
#line 1571 "verilog_parser.tab.cc"
    break;

  case 79: // rhs: constant
#line 343 "verilog_parser.yy"
             { yylhs.value.as < std::vector<verilog::NetConcat> > ().push_back(std::move(yystack_[0].value.as < verilog::Constant > ())); }
#line 1577 "verilog_parser.tab.cc"
    break;

  case 80: // rhs: rhs_concat
#line 344 "verilog_parser.yy"
               { yylhs.value.as < std::vector<verilog::NetConcat> > () = yystack_[0].value.as < std::vector<verilog::NetConcat> > (); }
#line 1583 "verilog_parser.tab.cc"
    break;

  case 81: // rhs_concat: '{' rhs_exprs '}'
#line 348 "verilog_parser.yy"
                      { std::move(yystack_[1].value.as < std::vector<verilog::NetConcat> > ().begin(), yystack_[1].value.as < std::vector<verilog::NetConcat> > ().end(), std::back_inserter(yylhs.value.as < std::vector<verilog::NetConcat> > ())); }
#line 1589 "verilog_parser.tab.cc"
    break;

  case 82: // rhs_exprs: rhs_expr
#line 352 "verilog_parser.yy"
             { std::move(yystack_[0].value.as < std::vector<verilog::NetConcat> > ().begin(), yystack_[0].value.as < std::vector<verilog::NetConcat> > ().end(), std::back_inserter(yylhs.value.as < std::vector<verilog::NetConcat> > ())); }
#line 1595 "verilog_parser.tab.cc"
    break;

  case 83: // rhs_exprs: rhs_exprs ',' rhs_expr
#line 354 "verilog_parser.yy"
    { 
      std::move(yystack_[2].value.as < std::vector<verilog::NetConcat> > ().begin(), yystack_[2].value.as < std::vector<verilog::NetConcat> > ().end(), std::back_inserter(yylhs.value.as < std::vector<verilog::NetConcat> > ()));
      std::move(yystack_[0].value.as < std::vector<verilog::NetConcat> > ().begin(), yystack_[0].value.as < std::vector<verilog::NetConcat> > ().end(), std::back_inserter(yylhs.value.as < std::vector<verilog::NetConcat> > ()));
    }
#line 1604 "verilog_parser.tab.cc"
    break;

  case 84: // rhs_expr: valid_name
#line 361 "verilog_parser.yy"
               { yylhs.value.as < std::vector<verilog::NetConcat> > ().push_back(std::move(yystack_[0].value.as < std::string > ())); }
#line 1610 "verilog_parser.tab.cc"
    break;

  case 85: // rhs_expr: valid_name '[' INTEGER ']'
#line 363 "verilog_parser.yy"
    { yylhs.value.as < std::vector<verilog::NetConcat> > ().emplace_back(verilog::NetBit(std::move(yystack_[3].value.as < std::string > ()), std::stoi(yystack_[1].value.as < verilog::Constant > ().value))); }
#line 1616 "verilog_parser.tab.cc"
    break;

  case 86: // rhs_expr: valid_name '[' INTEGER ':' INTEGER ']'
#line 365 "verilog_parser.yy"
    { yylhs.value.as < std::vector<verilog::NetConcat> > ().emplace_back(verilog::NetRange(std::move(yystack_[5].value.as < std::string > ()), std::stoi(yystack_[3].value.as < verilog::Constant > ().value), std::stoi(yystack_[1].value.as < verilog::Constant > ().value))); }
#line 1622 "verilog_parser.tab.cc"
    break;

  case 87: // rhs_expr: constant
#line 366 "verilog_parser.yy"
             { yylhs.value.as < std::vector<verilog::NetConcat> > ().push_back(std::move(yystack_[0].value.as < verilog::Constant > ())); }
#line 1628 "verilog_parser.tab.cc"
    break;

  case 88: // rhs_expr: rhs_concat
#line 368 "verilog_parser.yy"
    { std::move(yystack_[0].value.as < std::vector<verilog::NetConcat> > ().begin(), yystack_[0].value.as < std::vector<verilog::NetConcat> > ().end(), std::back_inserter(yylhs.value.as < std::vector<verilog::NetConcat> > ())); }
#line 1634 "verilog_parser.tab.cc"
    break;

  case 89: // instance: valid_name valid_name '(' inst_pins ')' ';'
#line 377 "verilog_parser.yy"
    { 
      std::swap(yylhs.value.as < verilog::Instance > ().module_name, yystack_[5].value.as < std::string > ()); 
      std::swap(yylhs.value.as < verilog::Instance > ().inst_name, yystack_[4].value.as < std::string > ()); 
      std::swap(yylhs.value.as < verilog::Instance > ().pin_names, std::get<0>(yystack_[2].value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ()));  
      std::swap(yylhs.value.as < verilog::Instance > ().net_names, std::get<1>(yystack_[2].value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ()));  
      driver->add_instance(std::move(yylhs.value.as < verilog::Instance > ()));
    }
#line 1646 "verilog_parser.tab.cc"
    break;

  case 90: // instance: valid_name parameters valid_name '(' inst_pins ')' ';'
#line 385 "verilog_parser.yy"
    { 
      std::swap(yylhs.value.as < verilog::Instance > ().module_name, yystack_[6].value.as < std::string > ()); 
      std::swap(yylhs.value.as < verilog::Instance > ().inst_name, yystack_[4].value.as < std::string > ()); 
      std::swap(yylhs.value.as < verilog::Instance > ().pin_names, std::get<0>(yystack_[2].value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ()));  
      std::swap(yylhs.value.as < verilog::Instance > ().net_names, std::get<1>(yystack_[2].value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ()));  
      driver->add_instance(std::move(yylhs.value.as < verilog::Instance > ()));
    }
#line 1658 "verilog_parser.tab.cc"
    break;

  case 91: // inst_pins: %empty
#line 395 "verilog_parser.yy"
    { }
#line 1664 "verilog_parser.tab.cc"
    break;

  case 92: // inst_pins: nets_by_position
#line 396 "verilog_parser.yy"
                     { std::swap(std::get<1>(yylhs.value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ()), yystack_[0].value.as < std::vector<std::vector<verilog::NetConcat>> > ()); }
#line 1670 "verilog_parser.tab.cc"
    break;

  case 93: // inst_pins: nets_by_name
#line 398 "verilog_parser.yy"
    {
      std::swap(std::get<0>(yylhs.value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ()), std::get<0>(yystack_[0].value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ()));
      std::swap(std::get<1>(yylhs.value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ()), std::get<1>(yystack_[0].value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ()));
    }
#line 1679 "verilog_parser.tab.cc"
    break;

  case 94: // nets_by_position: rhs
#line 405 "verilog_parser.yy"
        { yylhs.value.as < std::vector<std::vector<verilog::NetConcat>> > ().emplace_back(std::move(yystack_[0].value.as < std::vector<verilog::NetConcat> > ())); }
#line 1685 "verilog_parser.tab.cc"
    break;

  case 95: // nets_by_position: nets_by_position ',' rhs
#line 407 "verilog_parser.yy"
    { 
      std::move(yystack_[2].value.as < std::vector<std::vector<verilog::NetConcat>> > ().begin(), yystack_[2].value.as < std::vector<std::vector<verilog::NetConcat>> > ().end(), std::back_inserter(yylhs.value.as < std::vector<std::vector<verilog::NetConcat>> > ()));   
      yylhs.value.as < std::vector<std::vector<verilog::NetConcat>> > ().push_back(std::move(yystack_[0].value.as < std::vector<verilog::NetConcat> > ()));
    }
#line 1694 "verilog_parser.tab.cc"
    break;

  case 96: // nets_by_name: net_by_name
#line 416 "verilog_parser.yy"
    { 
      std::get<0>(yylhs.value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ()).push_back(std::move(std::get<0>(yystack_[0].value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()))); 
      std::get<1>(yylhs.value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ()).push_back(std::move(std::get<1>(yystack_[0].value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()))); 
    }
#line 1703 "verilog_parser.tab.cc"
    break;

  case 97: // nets_by_name: nets_by_name ',' net_by_name
#line 421 "verilog_parser.yy"
    { 
      auto &pin_names = std::get<0>(yystack_[2].value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ());
      auto &net_names = std::get<1>(yystack_[2].value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ());
      std::move(pin_names.begin(), pin_names.end(), std::back_inserter(std::get<0>(yylhs.value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ())));
      std::move(net_names.begin(), net_names.end(), std::back_inserter(std::get<1>(yylhs.value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ())));

      std::get<0>(yylhs.value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ()).push_back(std::move(std::get<0>(yystack_[0].value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()))); 
      std::get<1>(yylhs.value.as < std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ()).push_back(std::move(std::get<1>(yystack_[0].value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()))); 
    }
#line 1717 "verilog_parser.tab.cc"
    break;

  case 98: // net_by_name: '.' valid_name '(' ')'
#line 435 "verilog_parser.yy"
    { std::get<0>(yylhs.value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()) = yystack_[2].value.as < std::string > (); }
#line 1723 "verilog_parser.tab.cc"
    break;

  case 99: // net_by_name: '.' valid_name '(' valid_name ')'
#line 437 "verilog_parser.yy"
    { 
       std::get<0>(yylhs.value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()) = yystack_[3].value.as < std::string > (); 
       std::get<1>(yylhs.value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()).push_back(std::move(yystack_[1].value.as < std::string > ())); 
    }
#line 1732 "verilog_parser.tab.cc"
    break;

  case 100: // net_by_name: '.' valid_name '(' valid_name '[' INTEGER ']' ')'
#line 442 "verilog_parser.yy"
    { 
      std::get<0>(yylhs.value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()) = yystack_[6].value.as < std::string > (); 
      std::get<1>(yylhs.value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()).emplace_back(verilog::NetBit(std::move(yystack_[4].value.as < std::string > ()), std::stoi(yystack_[2].value.as < verilog::Constant > ().value))); 
    }
#line 1741 "verilog_parser.tab.cc"
    break;

  case 101: // net_by_name: '.' valid_name '(' rhs ')'
#line 448 "verilog_parser.yy"
    { 
      std::get<0>(yylhs.value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()) = yystack_[3].value.as < std::string > (); 
      std::get<1>(yylhs.value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()) = yystack_[1].value.as < std::vector<verilog::NetConcat> > (); 
    }
#line 1750 "verilog_parser.tab.cc"
    break;

  case 102: // net_by_name: '.' valid_name '[' INTEGER ']' '(' ')'
#line 454 "verilog_parser.yy"
    {
      std::get<0>(yylhs.value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()) = verilog::NetBit(std::move(yystack_[5].value.as < std::string > ()), std::stoi(yystack_[3].value.as < verilog::Constant > ().value)); 
    }
#line 1758 "verilog_parser.tab.cc"
    break;

  case 103: // net_by_name: '.' valid_name '[' INTEGER ']' '(' rhs ')'
#line 458 "verilog_parser.yy"
    {
      std::get<0>(yylhs.value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()) = verilog::NetBit(std::move(yystack_[6].value.as < std::string > ()), std::stoi(yystack_[4].value.as < verilog::Constant > ().value)); 
      std::get<1>(yylhs.value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()) = yystack_[1].value.as < std::vector<verilog::NetConcat> > (); 
    }
#line 1767 "verilog_parser.tab.cc"
    break;

  case 104: // net_by_name: '.' valid_name '[' INTEGER ':' INTEGER ']' '(' ')'
#line 464 "verilog_parser.yy"
    {
      std::get<0>(yylhs.value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()) = verilog::NetRange(std::move(yystack_[7].value.as < std::string > ()), std::stoi(yystack_[5].value.as < verilog::Constant > ().value), std::stoi(yystack_[3].value.as < verilog::Constant > ().value)); 
    }
#line 1775 "verilog_parser.tab.cc"
    break;

  case 105: // net_by_name: '.' valid_name '[' INTEGER ':' INTEGER ']' '(' rhs ')'
#line 468 "verilog_parser.yy"
    {
      std::get<0>(yylhs.value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()) = verilog::NetRange(std::move(yystack_[8].value.as < std::string > ()), std::stoi(yystack_[6].value.as < verilog::Constant > ().value), std::stoi(yystack_[4].value.as < verilog::Constant > ().value)); 
      std::get<1>(yylhs.value.as < std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ()) = yystack_[1].value.as < std::vector<verilog::NetConcat> > (); 
    }
#line 1784 "verilog_parser.tab.cc"
    break;


#line 1788 "verilog_parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  VerilogParser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  VerilogParser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  VerilogParser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // VerilogParser::context.
  VerilogParser::context::context (const VerilogParser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  VerilogParser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  VerilogParser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  VerilogParser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char VerilogParser::yypact_ninf_ = -110;

  const signed char VerilogParser::yytable_ninf_ = -59;

  const short
  VerilogParser::yypact_[] =
  {
    -110,    18,     8,  -110,    60,  -110,  -110,  -110,    45,  -110,
       5,  -110,    10,  -110,   114,    53,   238,  -110,    14,    35,
      92,     0,   102,  -110,    31,    60,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,  -110,  -110,     9,     3,  -110,  -110,  -110,
      23,    24,    30,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,    93,  -110,  -110,    98,  -110,  -110,     9,    56,    73,
    -110,    88,  -110,    96,   130,    60,  -110,    60,   141,    74,
    -110,  -110,     9,   262,   120,   136,  -110,  -110,  -110,   135,
    -110,   -15,  -110,   162,  -110,     9,   220,   131,    86,   143,
    -110,   137,    74,  -110,  -110,   185,  -110,   286,   186,     9,
    -110,    83,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
     220,   161,  -110,  -110,  -110,   131,   131,    60,  -110,  -110,
     115,    82,    60,  -110,   164,   165,   167,  -110,    86,   189,
     166,   310,  -110,   116,  -110,   195,  -110,   170,  -110,  -110,
      -7,  -110,   197,  -110,    20,  -110,  -110,   131,   131,   131,
     131,   131,    76,   179,   220,   168,   180,   175,    60,  -110,
     205,  -110,   199,   206,   220,  -110,   118,  -110,    82,   156,
     156,  -110,  -110,   169,   207,  -110,  -110,  -110,   208,     9,
    -110,   200,  -110,   124,  -110,   229,  -110,  -110,    16,   209,
     128,  -110,    74,  -110,  -110,   231,  -110,   204,  -110,   234,
    -110,   239,   215,   212,  -110,   132,   214,   178,  -110,   219,
     221,  -110,   240,  -110,   211,  -110,  -110,   241,  -110
  };

  const signed char
  VerilogParser::yydefact_[] =
  {
       5,     0,     4,     1,     0,     6,     2,     3,     0,     7,
      13,    30,     0,    16,     0,     0,     0,     9,    18,    20,
      22,     0,     0,    25,     0,     0,     8,    39,    40,    41,
      42,    43,    44,    45,    46,     0,     0,    37,    31,    33,
       0,     0,     0,    47,    32,    34,    30,    19,    21,    24,
      23,     0,    28,    14,     0,    11,    17,     0,    58,     0,
      55,     0,    61,     0,     0,     0,    35,     0,     0,    50,
      52,    36,     0,     0,     0,     0,    27,    26,    30,    65,
      68,     0,    63,     0,    54,     0,     0,     0,    91,     0,
      38,     0,    48,    49,    10,     0,    30,     0,     0,     0,
      62,     0,    56,    69,    70,    71,    72,    73,    74,    75,
       0,    76,    79,    57,    80,     0,     0,     0,   109,   111,
       0,   107,     0,    94,     0,    92,    93,    96,    91,     0,
       0,     0,    12,     0,    64,     0,    59,    84,    87,    88,
       0,    82,     0,   112,     0,   110,   106,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,    66,     0,     0,     0,    81,     0,   117,   108,   114,
     113,   115,   116,     0,     0,    89,    95,    97,     0,     0,
      29,     0,    60,     0,    83,     0,    77,    98,     0,     0,
       0,    90,    51,    53,    67,     0,    85,     0,    99,     0,
     101,     0,     0,     0,    78,     0,     0,     0,    86,     0,
       0,   102,     0,   100,     0,   103,   104,     0,   105
  };

  const short
  VerilogParser::yypgoto_[] =
  {
    -110,    -4,  -110,  -110,  -110,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,    -5,   -38,  -110,  -110,  -110,  -110,  -110,
    -110,  -110,  -110,   -39,  -110,   -54,  -110,   158,   -81,   -82,
    -109,  -110,   110,  -110,   147,  -110,  -110,   123,  -110,  -110,
     -73
  };

  const unsigned char
  VerilogParser::yydefgoto_[] =
  {
       0,   118,     1,     2,     5,    11,    46,    78,    14,    75,
      15,    21,    22,    37,    16,    38,    39,    40,    41,    42,
      43,    44,    59,    60,    61,    62,    81,    82,   119,   123,
     114,   140,   141,    45,   124,   125,   126,   127,    65,   120,
     121
  };

  const short
  VerilogParser::yytable_[] =
  {
       8,   139,    70,    80,   113,   112,    13,   112,    73,    23,
       6,     7,    36,     6,     7,     6,     7,    52,     3,     6,
       7,    56,    99,   148,   149,   150,   151,     4,   100,   138,
     164,    58,    64,    93,     6,     7,   165,    69,    51,    47,
      97,    12,   143,   144,    17,    80,   102,   112,    63,    77,
      76,    57,   198,    79,   199,   139,   167,    66,   131,    48,
      67,    89,    68,    90,    71,    55,    57,    72,    92,    36,
       6,     7,   176,   112,   168,   169,   170,   171,   172,     9,
      10,    58,   111,   138,   111,   148,   149,   150,   151,    24,
      25,   189,   112,    36,    83,    79,     6,     7,   103,   104,
     105,   106,   107,   108,   109,    74,   137,    84,     6,     7,
      85,   173,    83,   145,   174,   -58,    49,    50,   152,    18,
      19,    20,   135,   136,   111,   212,   112,    36,   110,    86,
     122,    87,   217,   112,   115,    18,    19,    20,    53,    54,
     193,     6,     7,   103,   104,   105,   106,   107,   108,   109,
     111,   146,   147,    91,   180,   160,   161,   185,   186,    95,
     137,   150,   151,   195,   196,    88,   116,   201,   202,   188,
      96,   185,   209,    98,   101,   192,   129,   117,   128,     6,
       7,   103,   104,   105,   106,   107,   108,   109,     6,     7,
     103,   104,   105,   106,   107,   108,   109,   130,   133,   142,
     153,   157,   154,   111,   155,   187,   158,   162,   163,   166,
     111,   110,   122,   175,   211,   179,   178,   181,   183,   190,
     110,     6,     7,   103,   104,   105,   106,   107,   108,   109,
       6,     7,   103,   104,   105,   106,   107,   108,   109,   182,
     194,   197,   191,   203,   204,   200,   205,   216,     6,     7,
     207,   206,   208,   110,   210,   213,   214,   134,    26,    18,
      19,    20,   110,    27,    28,    29,    30,    31,    32,    33,
      34,    35,     6,     7,   184,   156,   215,   218,   177,     0,
       0,     0,    94,    18,    19,    20,     0,    27,    28,    29,
      30,    31,    32,    33,    34,    35,     6,     7,     0,     0,
       0,     0,     0,     0,     0,     0,   132,    18,    19,    20,
       0,    27,    28,    29,    30,    31,    32,    33,    34,    35,
       6,     7,     0,     0,     0,     0,     0,     0,     0,     0,
     159,    18,    19,    20,     0,    27,    28,    29,    30,    31,
      32,    33,    34,    35
  };

  const short
  VerilogParser::yycheck_[] =
  {
       4,   110,    41,    57,    86,    86,    10,    88,    46,    14,
      10,    11,    16,    10,    11,    10,    11,    21,     0,    10,
      11,    25,    37,     3,     4,     5,     6,    19,    43,   110,
      37,    35,    36,    72,    10,    11,    43,    41,    38,    25,
      78,    36,   115,   116,    34,    99,    85,   128,    45,    54,
      54,    42,    36,    57,    38,   164,    36,    34,    96,    24,
      37,    65,    38,    67,    34,    34,    42,    37,    72,    73,
      10,    11,   154,   154,   147,   148,   149,   150,   151,    34,
      35,    85,    86,   164,    88,     3,     4,     5,     6,    36,
      37,   173,   173,    97,    38,    99,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    12,   110,    34,    10,    11,
      37,    35,    38,   117,    38,    41,    24,    25,   122,    21,
      22,    23,    39,    40,   128,   207,   207,   131,    42,    41,
      44,    35,   214,   214,     3,    21,    22,    23,    36,    37,
     179,    10,    11,    12,    13,    14,    15,    16,    17,    18,
     154,    36,    37,    12,   158,    39,    40,    39,    40,    39,
     164,     5,     6,    39,    40,    35,    35,    39,    40,   173,
      34,    39,    40,    38,    12,   179,    39,    46,    35,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    12,    12,    38,
      36,    12,    37,   207,    37,    36,    40,    12,    38,    12,
     214,    42,    44,    34,    36,    40,    36,    12,    12,    12,
      42,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    40,
      40,    12,    34,    12,    40,    36,    12,    36,    10,    11,
      35,    12,    40,    42,    40,    36,    35,    99,    20,    21,
      22,    23,    42,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    10,    11,   164,   128,    36,    36,   155,    -1,
      -1,    -1,    20,    21,    22,    23,    -1,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    10,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      -1,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      10,    11,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    -1,    25,    26,    27,    28,    29,
      30,    31,    32,    33
  };

  const signed char
  VerilogParser::yystos_[] =
  {
       0,    49,    50,     0,    19,    51,    10,    11,    48,    34,
      35,    52,    36,    48,    55,    57,    61,    34,    21,    22,
      23,    58,    59,    60,    36,    37,    20,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    48,    60,    62,    63,
      64,    65,    66,    67,    68,    80,    53,    25,    24,    24,
      25,    38,    48,    36,    37,    34,    48,    42,    48,    69,
      70,    71,    72,    45,    48,    85,    34,    37,    38,    48,
      70,    34,    37,    61,    12,    56,    48,    60,    54,    48,
      72,    73,    74,    38,    34,    37,    41,    35,    35,    48,
      48,    12,    48,    70,    20,    39,    34,    61,    38,    37,
      43,    12,    70,    12,    13,    14,    15,    16,    17,    18,
      42,    48,    75,    76,    77,     3,    35,    46,    48,    75,
      86,    87,    44,    76,    81,    82,    83,    84,    35,    39,
      12,    61,    20,    12,    74,    39,    40,    48,    75,    77,
      78,    79,    38,    87,    87,    48,    36,    37,     3,     4,
       5,     6,    48,    36,    37,    37,    81,    12,    40,    20,
      39,    40,    12,    38,    37,    43,    12,    36,    87,    87,
      87,    87,    87,    35,    38,    34,    76,    84,    36,    40,
      48,    12,    40,    12,    79,    39,    40,    36,    48,    76,
      12,    34,    48,    70,    40,    39,    40,    12,    36,    38,
      36,    39,    40,    12,    40,    12,    12,    35,    40,    40,
      40,    36,    76,    36,    35,    36,    36,    76,    36
  };

  const signed char
  VerilogParser::yyr1_[] =
  {
       0,    47,    48,    48,    49,    50,    50,    52,    51,    53,
      51,    54,    51,    55,    56,    51,    57,    57,    58,    58,
      58,    58,    58,    58,    58,    59,    59,    59,    60,    60,
      61,    61,    61,    62,    62,    63,    63,    64,    64,    65,
      65,    65,    65,    65,    65,    65,    65,    66,    66,    66,
      67,    67,    67,    67,    68,    69,    69,    70,    71,    71,
      71,    71,    72,    73,    73,    74,    74,    74,    74,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    76,    76,
      76,    77,    78,    78,    79,    79,    79,    79,    79,    80,
      80,    81,    81,    81,    82,    82,    83,    83,    84,    84,
      84,    84,    84,    84,    84,    84,    85,    86,    86,    87,
      87,    87,    87,    87,    87,    87,    87,    87
  };

  const signed char
  VerilogParser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     0,     2,     0,     6,     0,
       8,     0,     9,     0,     0,    10,     1,     3,     1,     2,
       1,     2,     1,     2,     2,     1,     3,     3,     2,     7,
       0,     2,     2,     1,     1,     2,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       2,     7,     2,     7,     3,     1,     3,     3,     1,     4,
       6,     1,     3,     1,     3,     1,     4,     6,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     6,     1,
       1,     3,     1,     3,     1,     4,     6,     1,     1,     6,
       7,     0,     1,     1,     1,     3,     1,     3,     4,     5,
       8,     5,     7,     8,     9,    10,     4,     1,     3,     1,
       2,     1,     2,     3,     3,     3,     3,     3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const VerilogParser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "'-'", "'+'", "'*'",
  "'/'", "UMINUS", "NEWLINE", "UNDEFINED", "NAME", "ESCAPED_NAME",
  "INTEGER", "BINARY", "OCTAL", "DECIMAL", "HEX", "REAL", "EXP", "MODULE",
  "ENDMODULE", "INPUT", "OUTPUT", "INOUT", "REG", "WIRE", "WAND", "WOR",
  "TRI", "TRIOR", "TRIAND", "SUPPLY0", "SUPPLY1", "ASSIGN", "';'", "'('",
  "')'", "','", "'['", "':'", "']'", "'='", "'{'", "'}'", "'.'", "'#'",
  "'`'", "$accept", "valid_name", "design", "modules", "module", "$@1",
  "$@2", "$@3", "$@4", "$@5", "port_names", "port_type",
  "port_declarations", "port_decl", "statements", "statement",
  "declaration", "port_decl_statements", "net_type", "net_decl_statements",
  "net_decl", "statement_assign", "assignments", "assignment", "lhs",
  "lhs_concat", "lhs_exprs", "lhs_expr", "constant", "rhs", "rhs_concat",
  "rhs_exprs", "rhs_expr", "instance", "inst_pins", "nets_by_position",
  "nets_by_name", "net_by_name", "parameters", "param_exprs", "param_expr", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  VerilogParser::yyrline_[] =
  {
       0,    95,    95,    96,   100,   103,   104,   109,   108,   114,
     113,   119,   118,   124,   128,   123,   136,   137,   142,   143,
     144,   145,   146,   147,   148,   153,   157,   162,   170,   176,
     187,   188,   189,   193,   194,   199,   200,   205,   209,   218,
     219,   220,   221,   222,   223,   224,   225,   229,   233,   238,
     246,   251,   258,   263,   274,   277,   278,   282,   294,   295,
     297,   299,   303,   307,   308,   316,   317,   319,   321,   328,
     329,   330,   331,   332,   333,   334,   338,   339,   341,   343,
     344,   348,   352,   353,   361,   362,   364,   366,   367,   376,
     384,   395,   396,   397,   405,   406,   415,   420,   434,   436,
     441,   447,   453,   457,   463,   467,   477,   481,   482,   486,
     487,   488,   489,   490,   491,   492,   493,   494
  };

  void
  VerilogParser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  VerilogParser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  VerilogParser::symbol_kind_type
  VerilogParser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    45,     2,     2,     2,     2,
      35,    36,     5,     4,    37,     3,    44,     6,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    39,    34,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    40,     2,     2,    46,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33
    };
    // Last valid token kind.
    const int code_max = 284;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 5 "verilog_parser.yy"
} // verilog
#line 2481 "verilog_parser.tab.cc"

#line 496 "verilog_parser.yy"


void verilog::VerilogParser::error(const location_type &l, const std::string &err_message) {
  std::cerr << "Parser error: " << err_message  << '\n'
            << "  begin at line " << l.begin.line <<  " col " << l.begin.column  << '\n' 
            << "  end   at line " << l.end.line <<  " col " << l.end.column << "\n";
  std::abort();
}
