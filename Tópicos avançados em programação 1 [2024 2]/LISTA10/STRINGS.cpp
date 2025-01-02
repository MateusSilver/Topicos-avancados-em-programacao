#include <bits/stdc++.h>
using namespace std;

int main(){
    // string sempre pode ser considerada uma cadeia de caracteres
    // é um container
    // string sempre termina com \0

    // um laço pode ser i = 0; while(s[i]){i++;} para percorrer toda string
    // o \0 é considerado falso em while
    string s0 ("Initial string");

    // constructors used in the same order as described above:
    string s1;
    string s2 (s0);//s2 = s0
    string s3 (s0, 8, 3);// pega a s0 de 3 até 8
    string s4 ("A character sequence");// cria com essa sequencia
    string s5 ("Another character sequence", 12);// cria com essa sequencia ate 12
    string s6a (10, 'x');//cria com tamanho 10 e preenche com x
    string s6b (10, 42);      // 42 is the ASCII code for '*'
    string s7 (s0.begin(), s0.begin()+7);
    string s8 = s0 + s2;
    //if(s1<s2) {}// analisa primeiro lexicografico e depois o tamanho
    // A = 'z' > B = 'aabb'
    string s9 = s0.substr(1,3);// substring começando em i = 1, de tamanho 3
    // se não usar o segundo parametro ele criará de i até o final
    string s10 = s0.substr(2);

    cout << "s1: " << s1 << "\ns2: " << s2 << "\ns3: " << s3;
    cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
    cout << "\ns6b: " << s6b << "\ns7: " << s7 << "\ns8: " << s8 << "\ns9: " << s9 << "\ns10: " << s10;
    return 0;

}
