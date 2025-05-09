#include <stdio.h>

//Função para saber se os números são coprimos
long long alg_euclides(long long G, long long n){
    long long resto = G % n;
    if (resto != 0){
        alg_euclides(n, resto);
    }
    else{
        return n;
    }
}

int ehPrimo(long long n) {
    if (n <= 1) return 0; // Não é primo
    for(long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0) return 0; // não é primo        
    }
    return 1; // eh primo]
}

long long div_sucessivas(long long g, long long n) { // usando n = G ___ + ___ para achar G^-1 em Zn
    long long t = 0, novo_t = 1;
    long long r = n, novo_r = g;

    while (novo_r != 0) {
        long long q = r / novo_r;
        long long temp = t;
        t = novo_t;
        novo_t = temp - q * novo_t;

        temp = r;
        r = novo_r;
        novo_r = temp - q * novo_r;
    }

    if (r > 1) return -1; // G não tem inverso modular
    if (t < 0) t += n; // Pega a equivalência caso for negativo
    return t; // Retorna o inverso
}

long long totiente(long long n) { // função  totiente de Euler (Nº de inteiros positivos que são menores ou iguais a n que são coprimos de n )
    long long resultado = n; // Começa com todos 
    for (long long p = 2; p * p <= n; p++) 
    {
        if (n % p == 0) {
            while (n % p == 0){
                n /= p;
            }
            resultado -= resultado / p; // Diminui a cada loop pra cada vez que o resto de n/p for 0
        }
    }
    if (n > 1)
        resultado -= resultado / n;
    return resultado;
}

long long exp_mod(long long a, long long x, long long n) { // Exponenciação modular: a^x mod n
    long long resultado = 1;
    a = a % n;
    while (x > 0) {
        if (x % 2 == 1)
            resultado = (resultado * a) % n;
        x = x / 2;
        a = (a * a) % n;
    }
    return resultado;
}

int main(){
    long long H, G, n, x, n1;
    printf("Digite três números inteiros positivos H, G e n: ");
    scanf("%lld %lld %lld", &H, &G, &n);

    printf("\nDigite um expoente x e o módulo n1: ");
    scanf(" %lld %lld", &x, &n1);

    printf("Verificando possibilidade da divisao...\n");
    long long mdc_entre_Gen = alg_euclides(G,n);

    if (mdc_entre_Gen != 1){
        printf("Desculpe, %lld nao eh divisivel por %lld em Z%lld\n", H, G, n);
        return 0;
    }
    printf("%lld eh divisivel por %lld em Z%lld\n", H, G, n);

    //Ver se existe g^-1 em Zn
    //Teorema do bézout g .x + n . y = mdc(G,n) = 1
    long long Ginverso = div_sucessivas(G, n); // acha o inverso de G para calcular o mod
    if (Ginverso == -1){ // Não há inverso em Zn
        printf("%lld nao tem inverso em Z%lld\n", G, n);
        return 0;
    }

    long long a = (H*Ginverso) % n; //  a = (H * G⁻¹) mod n
    printf("Base a = %lld\n", a);
    long long MDCaen1 = alg_euclides(a, n1);
    if (MDCaen1 == 1){
        long long x1;
        if (ehPrimo(n1)){ // usa fermat
            printf("n1 é primo. Aplicando o Pequeno Teorema de Fermat.\n");
            x1 = n1 - 1;
        }else { // usa Euler 
            printf("n1 não é primo. Aplicando o Teorema de Euler.\n");
            x1 = totiente(n1);
            printf("φ(n1) = %lld\n", x1);
        }
        x = x % x1; // Reduzir o expoente x

    }else{
        printf("a e n1 não são coprimos. Fermat/Euler não podem/precisam ser aplicados.\n");
    }
    
    long long resultado = exp_mod(a, x, n1);
    printf("Resultado final: %lld^%lld mod %lld = %lld\n", a, x, n1, resultado);
    return 0;
}

