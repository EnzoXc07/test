#include <iostream>
#include <string.h>

using namespace std;

void limpartela(){
    system ("cls");
    }


int main (){

    

    int chute, tentativas=0, tentativasMax;
    const int PALAVRA_SECRETA = 57;
    bool acerto = false;
    char escolha='s';
    double pontos=1000.0;


    cout << " --------------JOGO DA ADVINHACAO, SEJA BEM VINDO ---------------\n" << endl;
    

    while (escolha == 's'){ 

    char Dificuldade;
    cout << "escolha um nível de difilcudade: " << endl;
    cout << "\033[32mFacil (F)\033[0m " "\033[33m Medio (M)\033[0m " "\033[31m Dificil(D)\033[0m" << endl;
    cin >> Dificuldade;

    limpartela();

    if(Dificuldade == 'F'){
    
        tentativasMax = 15;
    
    }else if(Dificuldade == 'M'){
        tentativasMax = 10;

    }else{
        tentativasMax = 5;
    }

    while (!acerto &&  tentativasMax > 1) { 

    tentativas++;
    tentativasMax --;
    
    cout << "\033[32mTentativas Restantes: \033[0m" << tentativasMax << endl << endl;

    cout << "tentativa " << tentativas << endl; 

    cout << "chute um numero aleatorio: ";
    cin >> chute;

    limpartela();

        if (chute == PALAVRA_SECRETA){
            cout << "parabens, vc acertou a palavra escondida!\n ";
            acerto = true;

        }else if(chute > PALAVRA_SECRETA){

            cout << " seu chute foi maior que a palavra secreta. Tente novamente. \n" << endl;
        }
        else {
            cout << "seu chute foi menor que a palavra secreta. Tente Novamente\n" << endl;
        }

         double pontos_perdidos = abs(PALAVRA_SECRETA - chute /2 + tentativas);
         pontos = pontos - pontos_perdidos;

    }

    cout.precision(2);
    cout << fixed;
    if(acerto){ 
        cout << "sua pontuacao foi: " << pontos << endl;
    }else{
        cout <<"Voce perdeu, tente novamente" << endl;
        cout <<" A palavra secreta era: " << PALAVRA_SECRETA << endl << endl;
    }
    cout << "O jogo acabou, deseja continuar? s/n: ";
    cin >> escolha;

    limpartela();

    if (escolha == 's'){
        acerto = false;
        tentativas = 0;
    }

    }

    return 0;
}