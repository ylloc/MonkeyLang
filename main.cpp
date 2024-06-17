#include <iostream>
#include <Lexer.h>

int main() {
  std::string code = "==+{}()++,,,";

  Lexer lexer(std::move(code));

  Token token{TokenKind::DEFAULT, ""};
  while (token.kind != TEOF) {
    std::cout << token.kind << ' ' << token.literal << std::endl;
    token = lexer.NextToken();
  }
}