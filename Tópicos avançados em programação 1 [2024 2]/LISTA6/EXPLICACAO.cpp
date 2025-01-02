/**manipulação de bits**/


and
a&b
alta prioridade nos ifs, faz o calculo primeiro a<b & c<d == b&c

or
a|b

xor: tem que ser diferente v f ou f v
a^b

not: altera tudo de v pra f e de f pra v
~a

deslocamento de bits:
    a<<2
    desloca duas casas a esquerda: a elevado a 2

verificando a quantidade de bits de um numero:
    brian kernighan
    __builtin_popcount(n);
    while(n)
    n = n&(n-1)
    quant++;

// porque?
 1001000 // 1 mais a direita n
&1000111 // n-1
---------
 1000000
usando and entre n e n-1 nós sempre vamos conseguir excluir o bit ativo mais a direita
fazemos isso até n == 0, excluimos todos os ativos

i | i-1
 1001000
|1000111
--------
1001111

verifica se o i digito esta ativo:
1000100 quero saber se o digito 3 esta ativo


    1000100
&   0000100
-------------
    0000100
se for diferente de 0 é ativo

    10000100
&   00001000
--------------
    00000000
