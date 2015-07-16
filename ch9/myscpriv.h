#ifndef _myscpriv_h
#define _myscpriv_h

string buffer; // Buffer string containing tokens
int len; // lenght of the buffer string
int cp;  // index positiong on buffer
spaceOptionT spaceOption; // space option setting

void skipSpaces(); // Skip the cp - index to next alphanumeric character
int scanToEndOfIdentifier();

#endif
