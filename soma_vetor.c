#include<R.h>
#include<Rinternals.h>
#include<stdio.h>

/*void soma_vetor(double *vetor, int *n, double *soma) {
  for(int i = 0; i < *n; i++){
     *soma += vetor[i];
  }
  
  printf("Fim\n");
}*/

SEXP soma_vetor(SEXP vetor) {
  R_xlen_t n = xlength(vetor);
  
  SEXP soma = PROTECT(allocVector(REALSXP,1));
  
  for(R_xlen_t i = 0; i < n; i++){
    REAL(soma)[0] += REAL(vetor)[i]; 
  }
  
  UNPROTECT(1);
  
  return soma;
}