#pragma once

#include <Token.h>
#include <string>

class Lexer {
private:
  std::string data;

  /// current buffer position and next read position correspondingly
  /// position == read_position - 1 at any point of time.
  size_t position{0}, read_position{0};

  char ch{0};

public:
  Lexer(std::string&& data);

  char ReadChar();

  Token NextToken();

  Token ReadIdentifier();
};
