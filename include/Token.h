#pragma once

#include <string>

enum TokenKind {
  INT,
  CHAR,
  ASSIGN,
  SEMICOLON,
  LPAREN,
  RPAREN,
  COMMA,
  PLUS,
  MINUS,
  LBRACE,
  RBRACE,
  TEOF,
  DEFAULT,
  IDENTIFIER,
  ILLEGAL,
  /* other: TODO */
};

class Token {
public:
  TokenKind kind{DEFAULT};
  std::string literal;

public:
  Token(TokenKind kind = DEFAULT, std::string literal = "");
};
