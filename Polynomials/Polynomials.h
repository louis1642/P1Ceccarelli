//
// PolynomialsCLion
// Polynomials.h
// Created by Luigi Catello on 20/04/21.
// 
//

#ifndef POLYNOMIALSCLION__POLYNOMIALS_H_
#define POLYNOMIALSCLION__POLYNOMIALS_H_

#include <iostream>

class Polynomials {
  friend bool operator==(const Polynomials &lhs, const Polynomials &rhs);
  friend Polynomials operator*(const Polynomials &lhs, const Polynomials &rhs);

 private:
  int size;       // grado+1
  double *coefs;  // coefficienti
 public:
  // costruttori
  Polynomials();                                        // default
  Polynomials(const double coefficients[], int _size);  // completo
  Polynomials(const Polynomials &rhs);                  // costruttore copia
  explicit Polynomials(double const_term);              // grado 0

  ~Polynomials();  // distruttore

  int degree() const;                               // grado del polinomio
  void print(std::ostream &out = std::cout) const;  // stampa a video

  // operatori di assegnazione
  Polynomials &operator=(const Polynomials &rhs);
  Polynomials operator+=(const Polynomials &rhs);
  Polynomials operator*=(double rhs);
};

// operatori
Polynomials operator+(const Polynomials &lhs, const Polynomials &rhs);

Polynomials operator*(const Polynomials &lhs, double rhs);
Polynomials operator*(double lhs, const Polynomials &rhs);
// il prodotto tra due polinomi deve essere friend - quindi non è qui

std::ostream &operator<<(std::ostream &out, const Polynomials &rhs);

#endif //POLYNOMIALSCLION__POLYNOMIALS_H_
