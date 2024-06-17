#include <Lexer.h>
#include <iostream>

Lexer::Lexer(std::string &&data): data(std::move(data)) { ReadChar(); }

char Lexer::ReadChar() {
  if (position >= data.size()) { [[unlikely]]
    ch = '\0';
  } else {
    ch = data[read_position];
  }
  position = read_position++;
  return ch;
}

Token Lexer::NextToken() {
  Token token{};

  switch (ch) {
    case '=':
      token = Token{ASSIGN, "="};
    case ';':
      token = Token{SEMICOLON, ";"};
    case '(':
      token = Token{LPAREN, "("};
    case ')':
      token = Token{RPAREN, ")"};
    case ',':
      token = Token{COMMA, ","};
    case '+':
      token = Token{PLUS, "+"};
    case '-':
      token = Token{MINUS, "-"};
    case '{':
      token = Token{LBRACE, "{"};
    case '}':
      token = Token{RBRACE, "}"};

    default:
      if (isalpha(ch)) {
        token = ReadIdentifier();
      } else {
        return Token{ILLEGAL, &"" [ ch]};
      }
  }

  ReadChar();
  return token;
}

Token Lexer::ReadIdentifier() {
  std::string name;
  char c{};
  while (isalpha(c)) {
    name += (c = ReadChar());
  }
  return Token{IDENTIFIER, name};
}

