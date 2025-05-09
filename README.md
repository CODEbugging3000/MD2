# Questão 9 da Prova 1 de Matemática Discreta 2
Desenvolvimento de uma função de segurança para validar acessos em um sistema. Essa função baseia
se na ideia de "verificação modular", utilizando os conceitos de congruência, primalidade, coprimalidade, Pequeno
 Teorema de Fermat, Teorema de Euler e exponenciação modular eficiente.

 ## Como compilar e executar o código

1. Clone o repositório:
   ```bash
   git clone https://github.com/CODEbugging3000/MD2_P1.git
2. Compile:
    ```bash
    gcc main.c -o executavel
    ```
3. Execute:
    ```
    ./executavel
    ```

## Fluxo de uso

Dados de entrada: 
-  três números inteiros positivos ``H``, ``G`` e ``n``, usados para calcular a base `a` com operação modular: ``H⊘G`` em ``Zn``
-  um expoente `x`
-  um módulo `n1`

Função:
- CALCULAR: ``a^x mod n1``

Retorno:
- ``(H⊘G mod n)^x mod n1`` 

##### Autor : Gabriel Alves de Araujo 
##### Matrícula : 241025523
