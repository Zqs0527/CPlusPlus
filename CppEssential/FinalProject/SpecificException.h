#pragma once
#include <exception>

namespace CppEsstial {
class SpecificException : public std::exception {
private:
  const char *msg; 
public : SpecificException(const char *s) : msg(s){};
  const char *what() const noexcept(true) { return msg; }
  ~SpecificException();
};
}