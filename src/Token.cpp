#include <Token.h>

Token::Token(TokenKind kind, std::string literal)
  : kind(kind), literal(std::move(literal)) {}