// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file verilog_parser.tab.hh
 ** Define the verilog::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_YY_VERILOG_PARSER_TAB_HH_INCLUDED
# define YY_YY_VERILOG_PARSER_TAB_HH_INCLUDED
// "%code requires" blocks.
#line 10 "verilog_parser.yy"

  #include "verilog_data.hpp"

  namespace verilog {
    class ParserVerilogInterface;
    class VerilogScanner;
  }

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif 


#line 68 "verilog_parser.tab.hh"

# include <cassert>
# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif
# include "location.hh"
#include <typeinfo>
#ifndef YY_ASSERT
# include <cassert>
# define YY_ASSERT assert
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

#line 5 "verilog_parser.yy"
namespace verilog {
#line 209 "verilog_parser.tab.hh"




  /// A Bison parser.
  class VerilogParser
  {
  public:
#ifdef YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define YYSTYPE in C++, use %define api.value.type"
# endif
    typedef YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
      , yytypeid_ (YY_NULLPTR)
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
      : yytypeid_ (&typeid (T))
    {
      YY_ASSERT (sizeof (T) <= size);
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {
      YY_ASSERT (!yytypeid_);
    }

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      YY_ASSERT (!yytypeid_);
      YY_ASSERT (sizeof (T) <= size);
      yytypeid_ = & typeid (T);
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == typeid (T));
      YY_ASSERT (sizeof (T) <= size);
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      YY_ASSERT (yytypeid_);
      YY_ASSERT (*yytypeid_ == *that.yytypeid_);
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
      yytypeid_ = YY_NULLPTR;
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // net_by_name
      char dummy1[sizeof (std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>>)];

      // inst_pins
      // nets_by_name
      char dummy2[sizeof (std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>>)];

      // port_type
      char dummy3[sizeof (std::pair<verilog::PortDirection, verilog::ConnectionType>)];

      // NAME
      // ESCAPED_NAME
      // valid_name
      char dummy4[sizeof (std::string)];

      // lhs
      // lhs_concat
      // lhs_exprs
      // lhs_expr
      char dummy5[sizeof (std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>>)];

      // nets_by_position
      char dummy6[sizeof (std::vector<std::vector<verilog::NetConcat>>)];

      // rhs
      // rhs_concat
      // rhs_exprs
      // rhs_expr
      char dummy7[sizeof (std::vector<verilog::NetConcat>)];

      // assignment
      char dummy8[sizeof (verilog::Assignment)];

      // INTEGER
      // BINARY
      // OCTAL
      // DECIMAL
      // HEX
      // REAL
      // EXP
      // constant
      char dummy9[sizeof (verilog::Constant)];

      // instance
      char dummy10[sizeof (verilog::Instance)];

      // net_decl_statements
      // net_decl
      char dummy11[sizeof (verilog::Net)];

      // net_type
      char dummy12[sizeof (verilog::NetType)];

      // port_declarations
      // port_decl
      // port_decl_statements
      char dummy13[sizeof (verilog::Port)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };

    /// Whether the content is built: if defined, the name of the stored type.
    const std::type_info *yytypeid_;
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;

    /// Symbol locations.
    typedef location location_type;

    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const location_type& l, const std::string& m)
        : std::runtime_error (m)
        , location (l)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
        , location (s.location)
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;

      location_type location;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        YYEMPTY = -2,
    END = 0,                       // "end of file"
    YYerror = 256,                 // error
    YYUNDEF = 257,                 // "invalid token"
    UMINUS = 258,                  // UMINUS
    NEWLINE = 259,                 // NEWLINE
    UNDEFINED = 260,               // UNDEFINED
    NAME = 261,                    // NAME
    ESCAPED_NAME = 262,            // ESCAPED_NAME
    INTEGER = 263,                 // INTEGER
    BINARY = 264,                  // BINARY
    OCTAL = 265,                   // OCTAL
    DECIMAL = 266,                 // DECIMAL
    HEX = 267,                     // HEX
    REAL = 268,                    // REAL
    EXP = 269,                     // EXP
    MODULE = 270,                  // MODULE
    ENDMODULE = 271,               // ENDMODULE
    INPUT = 272,                   // INPUT
    OUTPUT = 273,                  // OUTPUT
    INOUT = 274,                   // INOUT
    REG = 275,                     // REG
    WIRE = 276,                    // WIRE
    WAND = 277,                    // WAND
    WOR = 278,                     // WOR
    TRI = 279,                     // TRI
    TRIOR = 280,                   // TRIOR
    TRIAND = 281,                  // TRIAND
    SUPPLY0 = 282,                 // SUPPLY0
    SUPPLY1 = 283,                 // SUPPLY1
    ASSIGN = 284                   // ASSIGN
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 47, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_3_ = 3,                                // '-'
        S_4_ = 4,                                // '+'
        S_5_ = 5,                                // '*'
        S_6_ = 6,                                // '/'
        S_UMINUS = 7,                            // UMINUS
        S_NEWLINE = 8,                           // NEWLINE
        S_UNDEFINED = 9,                         // UNDEFINED
        S_NAME = 10,                             // NAME
        S_ESCAPED_NAME = 11,                     // ESCAPED_NAME
        S_INTEGER = 12,                          // INTEGER
        S_BINARY = 13,                           // BINARY
        S_OCTAL = 14,                            // OCTAL
        S_DECIMAL = 15,                          // DECIMAL
        S_HEX = 16,                              // HEX
        S_REAL = 17,                             // REAL
        S_EXP = 18,                              // EXP
        S_MODULE = 19,                           // MODULE
        S_ENDMODULE = 20,                        // ENDMODULE
        S_INPUT = 21,                            // INPUT
        S_OUTPUT = 22,                           // OUTPUT
        S_INOUT = 23,                            // INOUT
        S_REG = 24,                              // REG
        S_WIRE = 25,                             // WIRE
        S_WAND = 26,                             // WAND
        S_WOR = 27,                              // WOR
        S_TRI = 28,                              // TRI
        S_TRIOR = 29,                            // TRIOR
        S_TRIAND = 30,                           // TRIAND
        S_SUPPLY0 = 31,                          // SUPPLY0
        S_SUPPLY1 = 32,                          // SUPPLY1
        S_ASSIGN = 33,                           // ASSIGN
        S_34_ = 34,                              // ';'
        S_35_ = 35,                              // '('
        S_36_ = 36,                              // ')'
        S_37_ = 37,                              // ','
        S_38_ = 38,                              // '['
        S_39_ = 39,                              // ':'
        S_40_ = 40,                              // ']'
        S_41_ = 41,                              // '='
        S_42_ = 42,                              // '{'
        S_43_ = 43,                              // '}'
        S_44_ = 44,                              // '.'
        S_45_ = 45,                              // '#'
        S_46_ = 46,                              // '`'
        S_YYACCEPT = 47,                         // $accept
        S_valid_name = 48,                       // valid_name
        S_design = 49,                           // design
        S_modules = 50,                          // modules
        S_module = 51,                           // module
        S_52_1 = 52,                             // $@1
        S_53_2 = 53,                             // $@2
        S_54_3 = 54,                             // $@3
        S_55_4 = 55,                             // $@4
        S_56_5 = 56,                             // $@5
        S_port_names = 57,                       // port_names
        S_port_type = 58,                        // port_type
        S_port_declarations = 59,                // port_declarations
        S_port_decl = 60,                        // port_decl
        S_statements = 61,                       // statements
        S_statement = 62,                        // statement
        S_declaration = 63,                      // declaration
        S_port_decl_statements = 64,             // port_decl_statements
        S_net_type = 65,                         // net_type
        S_net_decl_statements = 66,              // net_decl_statements
        S_net_decl = 67,                         // net_decl
        S_statement_assign = 68,                 // statement_assign
        S_assignments = 69,                      // assignments
        S_assignment = 70,                       // assignment
        S_lhs = 71,                              // lhs
        S_lhs_concat = 72,                       // lhs_concat
        S_lhs_exprs = 73,                        // lhs_exprs
        S_lhs_expr = 74,                         // lhs_expr
        S_constant = 75,                         // constant
        S_rhs = 76,                              // rhs
        S_rhs_concat = 77,                       // rhs_concat
        S_rhs_exprs = 78,                        // rhs_exprs
        S_rhs_expr = 79,                         // rhs_expr
        S_instance = 80,                         // instance
        S_inst_pins = 81,                        // inst_pins
        S_nets_by_position = 82,                 // nets_by_position
        S_nets_by_name = 83,                     // nets_by_name
        S_net_by_name = 84,                      // net_by_name
        S_parameters = 85,                       // parameters
        S_param_exprs = 86,                      // param_exprs
        S_param_expr = 87                        // param_expr
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value and location.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
        , location ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
        , location (std::move (that.location))
      {
        switch (this->kind ())
    {
      case symbol_kind::S_net_by_name: // net_by_name
        value.move< std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > (std::move (that.value));
        break;

      case symbol_kind::S_inst_pins: // inst_pins
      case symbol_kind::S_nets_by_name: // nets_by_name
        value.move< std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > (std::move (that.value));
        break;

      case symbol_kind::S_port_type: // port_type
        value.move< std::pair<verilog::PortDirection, verilog::ConnectionType> > (std::move (that.value));
        break;

      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ESCAPED_NAME: // ESCAPED_NAME
      case symbol_kind::S_valid_name: // valid_name
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_lhs: // lhs
      case symbol_kind::S_lhs_concat: // lhs_concat
      case symbol_kind::S_lhs_exprs: // lhs_exprs
      case symbol_kind::S_lhs_expr: // lhs_expr
        value.move< std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > (std::move (that.value));
        break;

      case symbol_kind::S_nets_by_position: // nets_by_position
        value.move< std::vector<std::vector<verilog::NetConcat>> > (std::move (that.value));
        break;

      case symbol_kind::S_rhs: // rhs
      case symbol_kind::S_rhs_concat: // rhs_concat
      case symbol_kind::S_rhs_exprs: // rhs_exprs
      case symbol_kind::S_rhs_expr: // rhs_expr
        value.move< std::vector<verilog::NetConcat> > (std::move (that.value));
        break;

      case symbol_kind::S_assignment: // assignment
        value.move< verilog::Assignment > (std::move (that.value));
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_BINARY: // BINARY
      case symbol_kind::S_OCTAL: // OCTAL
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_constant: // constant
        value.move< verilog::Constant > (std::move (that.value));
        break;

      case symbol_kind::S_instance: // instance
        value.move< verilog::Instance > (std::move (that.value));
        break;

      case symbol_kind::S_net_decl_statements: // net_decl_statements
      case symbol_kind::S_net_decl: // net_decl
        value.move< verilog::Net > (std::move (that.value));
        break;

      case symbol_kind::S_net_type: // net_type
        value.move< verilog::NetType > (std::move (that.value));
        break;

      case symbol_kind::S_port_declarations: // port_declarations
      case symbol_kind::S_port_decl: // port_decl
      case symbol_kind::S_port_decl_statements: // port_decl_statements
        value.move< verilog::Port > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, location_type&& l)
        : Base (t)
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const location_type& l)
        : Base (t)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::pair<verilog::PortDirection, verilog::ConnectionType>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::pair<verilog::PortDirection, verilog::ConnectionType>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<std::vector<verilog::NetConcat>>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<std::vector<verilog::NetConcat>>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<verilog::NetConcat>&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<verilog::NetConcat>& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, verilog::Assignment&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const verilog::Assignment& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, verilog::Constant&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const verilog::Constant& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, verilog::Instance&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const verilog::Instance& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, verilog::Net&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const verilog::Net& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, verilog::NetType&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const verilog::NetType& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, verilog::Port&& v, location_type&& l)
        : Base (t)
        , value (std::move (v))
        , location (std::move (l))
      {}
#else
      basic_symbol (typename Base::kind_type t, const verilog::Port& v, const location_type& l)
        : Base (t)
        , value (v)
        , location (l)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_net_by_name: // net_by_name
        value.template destroy< std::pair<std::variant<std::string, NetBit, NetRange>, std::vector<verilog::NetConcat>> > ();
        break;

      case symbol_kind::S_inst_pins: // inst_pins
      case symbol_kind::S_nets_by_name: // nets_by_name
        value.template destroy< std::pair<std::vector<std::variant<std::string, NetBit, NetRange>>, std::vector<std::vector<verilog::NetConcat>>> > ();
        break;

      case symbol_kind::S_port_type: // port_type
        value.template destroy< std::pair<verilog::PortDirection, verilog::ConnectionType> > ();
        break;

      case symbol_kind::S_NAME: // NAME
      case symbol_kind::S_ESCAPED_NAME: // ESCAPED_NAME
      case symbol_kind::S_valid_name: // valid_name
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_lhs: // lhs
      case symbol_kind::S_lhs_concat: // lhs_concat
      case symbol_kind::S_lhs_exprs: // lhs_exprs
      case symbol_kind::S_lhs_expr: // lhs_expr
        value.template destroy< std::vector<std::variant<std::string, verilog::NetBit, verilog::NetRange>> > ();
        break;

      case symbol_kind::S_nets_by_position: // nets_by_position
        value.template destroy< std::vector<std::vector<verilog::NetConcat>> > ();
        break;

      case symbol_kind::S_rhs: // rhs
      case symbol_kind::S_rhs_concat: // rhs_concat
      case symbol_kind::S_rhs_exprs: // rhs_exprs
      case symbol_kind::S_rhs_expr: // rhs_expr
        value.template destroy< std::vector<verilog::NetConcat> > ();
        break;

      case symbol_kind::S_assignment: // assignment
        value.template destroy< verilog::Assignment > ();
        break;

      case symbol_kind::S_INTEGER: // INTEGER
      case symbol_kind::S_BINARY: // BINARY
      case symbol_kind::S_OCTAL: // OCTAL
      case symbol_kind::S_DECIMAL: // DECIMAL
      case symbol_kind::S_HEX: // HEX
      case symbol_kind::S_REAL: // REAL
      case symbol_kind::S_EXP: // EXP
      case symbol_kind::S_constant: // constant
        value.template destroy< verilog::Constant > ();
        break;

      case symbol_kind::S_instance: // instance
        value.template destroy< verilog::Instance > ();
        break;

      case symbol_kind::S_net_decl_statements: // net_decl_statements
      case symbol_kind::S_net_decl: // net_decl
        value.template destroy< verilog::Net > ();
        break;

      case symbol_kind::S_net_type: // net_type
        value.template destroy< verilog::NetType > ();
        break;

      case symbol_kind::S_port_declarations: // port_declarations
      case symbol_kind::S_port_decl: // port_decl
      case symbol_kind::S_port_decl_statements: // port_decl_statements
        value.template destroy< verilog::Port > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return VerilogParser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

      /// The location.
      location_type location;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, location_type l)
        : super_type (token_kind_type (tok), std::move (l))
#else
      symbol_type (int tok, const location_type& l)
        : super_type (token_kind_type (tok), l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT (tok == token::END
                   || (token::YYerror <= tok && tok <= token::YYUNDEF)
                   || tok == 45
                   || tok == 43
                   || tok == 42
                   || tok == 47
                   || (token::UMINUS <= tok && tok <= token::UNDEFINED)
                   || (token::MODULE <= tok && tok <= token::ASSIGN)
                   || tok == 59
                   || (40 <= tok && tok <= 41)
                   || tok == 44
                   || tok == 91
                   || tok == 58
                   || tok == 93
                   || tok == 61
                   || tok == 123
                   || tok == 125
                   || tok == 46
                   || tok == 35
                   || tok == 96);
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const std::string& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::NAME <= tok && tok <= token::ESCAPED_NAME));
#endif
      }
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, verilog::Constant v, location_type l)
        : super_type (token_kind_type (tok), std::move (v), std::move (l))
#else
      symbol_type (int tok, const verilog::Constant& v, const location_type& l)
        : super_type (token_kind_type (tok), v, l)
#endif
      {
#if !defined _MSC_VER || defined __clang__
        YY_ASSERT ((token::INTEGER <= tok && tok <= token::EXP));
#endif
      }
    };

    /// Build a parser object.
    VerilogParser (VerilogScanner &scanner_yyarg, ParserVerilogInterface *driver_yyarg);
    virtual ~VerilogParser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    VerilogParser (const VerilogParser&) = delete;
    /// Non copyable.
    VerilogParser& operator= (const VerilogParser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param loc    where the syntax error is found.
    /// \param msg    a description of the syntax error.
    virtual void error (const location_type& loc, const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_END (location_type l)
      {
        return symbol_type (token::END, std::move (l));
      }
#else
      static
      symbol_type
      make_END (const location_type& l)
      {
        return symbol_type (token::END, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYerror (location_type l)
      {
        return symbol_type (token::YYerror, std::move (l));
      }
#else
      static
      symbol_type
      make_YYerror (const location_type& l)
      {
        return symbol_type (token::YYerror, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYUNDEF (location_type l)
      {
        return symbol_type (token::YYUNDEF, std::move (l));
      }
#else
      static
      symbol_type
      make_YYUNDEF (const location_type& l)
      {
        return symbol_type (token::YYUNDEF, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UMINUS (location_type l)
      {
        return symbol_type (token::UMINUS, std::move (l));
      }
#else
      static
      symbol_type
      make_UMINUS (const location_type& l)
      {
        return symbol_type (token::UMINUS, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NEWLINE (location_type l)
      {
        return symbol_type (token::NEWLINE, std::move (l));
      }
#else
      static
      symbol_type
      make_NEWLINE (const location_type& l)
      {
        return symbol_type (token::NEWLINE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_UNDEFINED (location_type l)
      {
        return symbol_type (token::UNDEFINED, std::move (l));
      }
#else
      static
      symbol_type
      make_UNDEFINED (const location_type& l)
      {
        return symbol_type (token::UNDEFINED, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NAME (std::string v, location_type l)
      {
        return symbol_type (token::NAME, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_NAME (const std::string& v, const location_type& l)
      {
        return symbol_type (token::NAME, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ESCAPED_NAME (std::string v, location_type l)
      {
        return symbol_type (token::ESCAPED_NAME, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_ESCAPED_NAME (const std::string& v, const location_type& l)
      {
        return symbol_type (token::ESCAPED_NAME, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INTEGER (verilog::Constant v, location_type l)
      {
        return symbol_type (token::INTEGER, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_INTEGER (const verilog::Constant& v, const location_type& l)
      {
        return symbol_type (token::INTEGER, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_BINARY (verilog::Constant v, location_type l)
      {
        return symbol_type (token::BINARY, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_BINARY (const verilog::Constant& v, const location_type& l)
      {
        return symbol_type (token::BINARY, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OCTAL (verilog::Constant v, location_type l)
      {
        return symbol_type (token::OCTAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_OCTAL (const verilog::Constant& v, const location_type& l)
      {
        return symbol_type (token::OCTAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DECIMAL (verilog::Constant v, location_type l)
      {
        return symbol_type (token::DECIMAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_DECIMAL (const verilog::Constant& v, const location_type& l)
      {
        return symbol_type (token::DECIMAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_HEX (verilog::Constant v, location_type l)
      {
        return symbol_type (token::HEX, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_HEX (const verilog::Constant& v, const location_type& l)
      {
        return symbol_type (token::HEX, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REAL (verilog::Constant v, location_type l)
      {
        return symbol_type (token::REAL, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_REAL (const verilog::Constant& v, const location_type& l)
      {
        return symbol_type (token::REAL, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXP (verilog::Constant v, location_type l)
      {
        return symbol_type (token::EXP, std::move (v), std::move (l));
      }
#else
      static
      symbol_type
      make_EXP (const verilog::Constant& v, const location_type& l)
      {
        return symbol_type (token::EXP, v, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MODULE (location_type l)
      {
        return symbol_type (token::MODULE, std::move (l));
      }
#else
      static
      symbol_type
      make_MODULE (const location_type& l)
      {
        return symbol_type (token::MODULE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ENDMODULE (location_type l)
      {
        return symbol_type (token::ENDMODULE, std::move (l));
      }
#else
      static
      symbol_type
      make_ENDMODULE (const location_type& l)
      {
        return symbol_type (token::ENDMODULE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INPUT (location_type l)
      {
        return symbol_type (token::INPUT, std::move (l));
      }
#else
      static
      symbol_type
      make_INPUT (const location_type& l)
      {
        return symbol_type (token::INPUT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_OUTPUT (location_type l)
      {
        return symbol_type (token::OUTPUT, std::move (l));
      }
#else
      static
      symbol_type
      make_OUTPUT (const location_type& l)
      {
        return symbol_type (token::OUTPUT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INOUT (location_type l)
      {
        return symbol_type (token::INOUT, std::move (l));
      }
#else
      static
      symbol_type
      make_INOUT (const location_type& l)
      {
        return symbol_type (token::INOUT, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_REG (location_type l)
      {
        return symbol_type (token::REG, std::move (l));
      }
#else
      static
      symbol_type
      make_REG (const location_type& l)
      {
        return symbol_type (token::REG, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WIRE (location_type l)
      {
        return symbol_type (token::WIRE, std::move (l));
      }
#else
      static
      symbol_type
      make_WIRE (const location_type& l)
      {
        return symbol_type (token::WIRE, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WAND (location_type l)
      {
        return symbol_type (token::WAND, std::move (l));
      }
#else
      static
      symbol_type
      make_WAND (const location_type& l)
      {
        return symbol_type (token::WAND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_WOR (location_type l)
      {
        return symbol_type (token::WOR, std::move (l));
      }
#else
      static
      symbol_type
      make_WOR (const location_type& l)
      {
        return symbol_type (token::WOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRI (location_type l)
      {
        return symbol_type (token::TRI, std::move (l));
      }
#else
      static
      symbol_type
      make_TRI (const location_type& l)
      {
        return symbol_type (token::TRI, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRIOR (location_type l)
      {
        return symbol_type (token::TRIOR, std::move (l));
      }
#else
      static
      symbol_type
      make_TRIOR (const location_type& l)
      {
        return symbol_type (token::TRIOR, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TRIAND (location_type l)
      {
        return symbol_type (token::TRIAND, std::move (l));
      }
#else
      static
      symbol_type
      make_TRIAND (const location_type& l)
      {
        return symbol_type (token::TRIAND, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUPPLY0 (location_type l)
      {
        return symbol_type (token::SUPPLY0, std::move (l));
      }
#else
      static
      symbol_type
      make_SUPPLY0 (const location_type& l)
      {
        return symbol_type (token::SUPPLY0, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SUPPLY1 (location_type l)
      {
        return symbol_type (token::SUPPLY1, std::move (l));
      }
#else
      static
      symbol_type
      make_SUPPLY1 (const location_type& l)
      {
        return symbol_type (token::SUPPLY1, l);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASSIGN (location_type l)
      {
        return symbol_type (token::ASSIGN, std::move (l));
      }
#else
      static
      symbol_type
      make_ASSIGN (const location_type& l)
      {
        return symbol_type (token::ASSIGN, l);
      }
#endif


    class context
    {
    public:
      context (const VerilogParser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      const location_type& location () const YY_NOEXCEPT { return yyla_.location; }

      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const VerilogParser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    VerilogParser (const VerilogParser&);
    /// Non copyable.
    VerilogParser& operator= (const VerilogParser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const unsigned char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const short yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 343,     ///< Last index in yytable_.
      yynnts_ = 41,  ///< Number of nonterminal symbols.
      yyfinal_ = 3 ///< Termination state number.
    };


    // User arguments.
    VerilogScanner &scanner;
    ParserVerilogInterface *driver;

  };


#line 5 "verilog_parser.yy"
} // verilog
#line 2063 "verilog_parser.tab.hh"




#endif // !YY_YY_VERILOG_PARSER_TAB_HH_INCLUDED
