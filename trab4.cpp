#include <iostream>
#include <string>

using namespace std;

class Cartao{
    private:
        string destinatario;

    public:
        Cartao(string d) : destinatario(d){};
        Cartao() : destinatario("nome"){};
        virtual void mensagem() = 0;

        string getDestinatario(){return destinatario;}
        void setDestinatario(string d){ destinatario = d;}
};

class CartaoNatal : public Cartao{
    public:
        CartaoNatal(string d) : Cartao(d){};
        CartaoNatal() : Cartao(){};

        void mensagem() override{
            cout << getDestinatario() + " Feliz Natal" << endl;
        }  

    friend istream &operator>>(istream &is, CartaoNatal &cn);
};

class CartaoAniversario : public Cartao{
    public:
        CartaoAniversario(string d) : Cartao(d){};
        CartaoAniversario() : Cartao(){};

        void mensagem() override{
            cout << getDestinatario() + " Feliz Aniversario" << endl;
        }  

    friend istream &operator>>(istream &is, CartaoAniversario &ca);
};

istream &operator>>(istream &is, CartaoNatal &cn){
    string dest;
    is >> dest;
    if(is){
        cn.setDestinatario(dest);
    }
    return is;
}

istream &operator>>(istream &is, CartaoAniversario &ca){
    string dest;
    is >> dest;
    if(is){
        ca.setDestinatario(dest);
    }
    return is;
}

int main(){
    CartaoNatal cn;
    CartaoAniversario ca;

    bool s = true;
    int n;
    char dec;

    while(s){
        cout << "(1) para criar cartao de natal.\n(2) para criar cartao de aniversario." << endl;
        cin >> n;
        if(n == 1){
            cout << "\nEntre com o nome para o cartão de natal: " << endl;
            cin >> cn;
            cout << "\nCartao criado com sucesso.\n\n";
            cn.mensagem();
        } else if(n == 2){
            cout << "\nEntre com o nome para o cartão de aniversario: " << endl;
            cin >> ca;
            cout << "\nCartao criado com sucesso.\n\n";
            ca.mensagem();
        } else {
            cout << "Insira um numero valido." << endl;
        }
        cout << "\nDeseja criar mais cartoes?\n(S) para continuar\n(N) para sair" << endl;
        cin >> dec;
        if(dec == 'N'){ s = false;}
        cout << endl;
    }
}