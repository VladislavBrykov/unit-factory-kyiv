#include "./inc/header.h"

bool mx_isspace(char c) {
  if ( c == ' ' || c == '\n' || c == '\t' || c == '\v'
       || c == '\r' || c == '\f' || c == '\b') {
    return true;
  } else {
    return false;
  }
}
