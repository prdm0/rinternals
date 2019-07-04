# rinternals
Exemplos do uso da API C de R

```
library(pryr)
library(inline)


retorna_f <-
  cfunction(
    sig = c(f = "SEXP", x = "SEXP", rho = "SEXP"),
    body = "
     SEXP  = PROTECT(LCONS(f, LCONS(x, R_NilValue)));
     SEXP val = R_forceAndCall(call, 1, rho);
     UNPROTECT(1);
     return val;

    "
  )


# Exemplo de uso: retorna_f(f = function(x) x^2, 5.0, environment())


retorna_f1 <-
  cfunction(
    sig = c(f = "SEXP", x = "SEXP", rho = "SEXP"),
    body = "
       SEXP R_fcall = PROTECT(lang2(f, x));
       SEXP ans = eval(R_fcall, rho);
       UNPROTECT(1);
       return ans;
")

# Exemplo de uso: retorna_f1(f = function(x) x^2, 5.0, environment())
```
