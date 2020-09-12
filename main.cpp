#include <iostream>
#include <fstream>

using namespace std;

#include <vector>

#include <carro.h>
#include <house.h>
#include <house2.h>
#include <obj2.h>
#include <obj3.h>

vector<Objeto*> objetos;
int posSelecionado = -1;

void desenha() {
    GUI::displayInit();

    GUI::setLight(1,1,3,5,true,false);
    GUI::setLight(2,-1.5,0.5,-1,true,false);

    GUI::drawOrigin(1);

    GUI::setColor(0,1,0);
    GUI::drawFloor(10,10);

    for (int i = 0; i < objetos.size(); ++i) {
        glPushMatrix();
            objetos[i]->desenha();
        glPopMatrix();
    }

    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->t.x += glutGUI::dtx;
        objetos[posSelecionado]->t.y += glutGUI::dty;
        objetos[posSelecionado]->t.z += glutGUI::dtz;

        objetos[posSelecionado]->a.x += glutGUI::dax;
        objetos[posSelecionado]->a.y += glutGUI::day;
        objetos[posSelecionado]->a.z += glutGUI::daz;

        objetos[posSelecionado]->s.x += glutGUI::dsx;
        objetos[posSelecionado]->s.y += glutGUI::dsy;
        objetos[posSelecionado]->s.z += glutGUI::dsz;
    }

    GUI::displayEnd();
}

bool incluirObjeto = false;

void teclado(unsigned char key, int x, int y) {
    GUI::keyInit(key,x,y);

    switch (key) {
    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;
    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    case 'a':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado++;
        posSelecionado = posSelecionado%objetos.size();
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;
    case 'd':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = false;
        }
        posSelecionado--;
        if (posSelecionado < 0) {
            posSelecionado = objetos.size()-1;
        }
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->selecionado = true;
        }
        break;

    case 'D':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()){
            objetos.erase(objetos.begin()+posSelecionado);
            posSelecionado = -1;
        }
        break;
    case 'n':
        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->desenhar_sist_coord = !objetos[posSelecionado]->desenhar_sist_coord;
        }
        break;
    case 'f':
        objetos.pop_back();
        posSelecionado = -1;
        break;

    case 'i':
        incluirObjeto = !incluirObjeto;
        break;

    case '1':
        if (incluirObjeto) {
            objetos.push_back( new Carro() );
        }
        break;
    case '2':
        if (incluirObjeto) {
            objetos.push_back( new house() );
        }
        break;
    case '3':
        if (incluirObjeto) {
            objetos.push_back( new house2() );
        }
        break;
    case '4':
        if (incluirObjeto) {
            objetos.push_back( new obj2() );
        }
        break;
    case '5':
        if (incluirObjeto) {
            objetos.push_back( new obj3() );
        }
        break;
    case 'w':
    {
        ofstream save ("cenario.txt");
        if (save.is_open()){
            for(Objeto * obj : objetos){
                save<<obj->nome<<endl;
                save<<obj->t.x<<endl;
                save<<obj->t.y<<endl;
                save<<obj->t.z<<endl;
                save<<obj->a.x<<endl;
                save<<obj->a.y<<endl;
                save<<obj->a.z<<endl;
                save<<obj->s.x<<endl;
                save<<obj->s.y<<endl;
                save<<obj->s.z<<endl;
            }
            save.close();
        }else{
            cout << "Não foi possível abrir o arquivo";
        }
        break;
    }
    case 'r':
    {
        string linha;
        ifstream load ("cenario.txt");
        if(load.is_open()){
            while(getline(load,linha)){
                if(linha == "carro"){
                    Carro* temp = new Carro();
                    getline(load,linha);
                    temp->t.x = stof(linha);
                    getline(load,linha);
                    temp->t.y = stof(linha);
                    getline(load,linha);
                    temp->t.z = stof(linha);
                    getline(load,linha);
                    temp->a.x = stof(linha);
                    getline(load,linha);
                    temp->a.y = stof(linha);
                    getline(load,linha);
                    temp->a.z = stof(linha);
                    getline(load,linha);
                    temp->s.x = stof(linha);
                    getline(load,linha);
                    temp->s.y = stof(linha);
                    getline(load,linha);
                    temp->s.z = stof(linha);
                    objetos.push_back(temp);
                }else if(linha == "house"){
                    house* temp = new house();
                    getline(load,linha);
                    temp->t.x = stof(linha);
                    getline(load,linha);
                    temp->t.y = stof(linha);
                    getline(load,linha);
                    temp->t.z = stof(linha);
                    getline(load,linha);
                    temp->a.x = stof(linha);
                    getline(load,linha);
                    temp->a.y = stof(linha);
                    getline(load,linha);
                    temp->a.z = stof(linha);
                    getline(load,linha);
                    temp->s.x = stof(linha);
                    getline(load,linha);
                    temp->s.y = stof(linha);
                    getline(load,linha);
                    temp->s.z = stof(linha);
                    objetos.push_back(temp);
                }else if(linha == "obj2"){
                    obj2* temp = new obj2();
                    getline(load,linha);
                    temp->t.x = stof(linha);
                    getline(load,linha);
                    temp->t.y = stof(linha);
                    getline(load,linha);
                    temp->t.z = stof(linha);
                    getline(load,linha);
                    temp->a.x = stof(linha);
                    getline(load,linha);
                    temp->a.y = stof(linha);
                    getline(load,linha);
                    temp->a.z = stof(linha);
                    getline(load,linha);
                    temp->s.x = stof(linha);
                    getline(load,linha);
                    temp->s.y = stof(linha);
                    getline(load,linha);
                    temp->s.z = stof(linha);
                    objetos.push_back(temp);
                }else if(linha == "obj3"){
                    obj3* temp = new obj3();
                    getline(load,linha);
                    temp->t.x = stof(linha);
                    getline(load,linha);
                    temp->t.y = stof(linha);
                    getline(load,linha);
                    temp->t.z = stof(linha);
                    getline(load,linha);
                    temp->a.x = stof(linha);
                    getline(load,linha);
                    temp->a.y = stof(linha);
                    getline(load,linha);
                    temp->a.z = stof(linha);
                    getline(load,linha);
                    temp->s.x = stof(linha);
                    getline(load,linha);
                    temp->s.y = stof(linha);
                    getline(load,linha);
                    temp->s.z = stof(linha);
                    objetos.push_back(temp);
                }else if(linha == "house2"){
                    house2* temp = new house2();
                    getline(load,linha);
                    temp->t.x = stof(linha);
                    getline(load,linha);
                    temp->t.y = stof(linha);
                    getline(load,linha);
                    temp->t.z = stof(linha);
                    getline(load,linha);
                    temp->a.x = stof(linha);
                    getline(load,linha);
                    temp->a.y = stof(linha);
                    getline(load,linha);
                    temp->a.z = stof(linha);
                    getline(load,linha);
                    temp->s.x = stof(linha);
                    getline(load,linha);
                    temp->s.y = stof(linha);
                    getline(load,linha);
                    temp->s.z = stof(linha);
                    objetos.push_back(temp);
                }
            }
            load.close();
        }
        break;
    }
    default:
        break;
    }
}

void infos(){
    cout<<"--------------Comandos do Modelador--------------"<<endl;
    cout<<"i - Habilitar/Desabilitar a inclusao de objetos na Cena"<<endl;
    cout<<"a - Selecionar Proximo superior no vetor de objetos"<<endl;
    cout<<"d - Selecionar Proximo inferior no vetor de objetos"<<endl;
    cout<<"D - Deletar objeto selecionado"<<endl;
    cout<<"f - Deletar ultimo objeto no vetor de objetos"<<endl;
    cout<<"r - Carregar Cenario"<<endl;
    cout<<"w - Salvar Cenario"<<endl;
    cout<<"C - Alterna entre as posicoes diferentes de camera (incluindo o estado salvo)"<<endl;
    cout<<"c - Restaura para a camera original - modo distante"<<endl;
    cout<<"s - Salvar posicao atual da camera"<<endl;
    cout<<"j - Restaura para a camera original - modo jogo"<<endl;
    cout<<"z/Z - Zoom in/Zoom out"<<endl;
    cout<<"x/X - Rotacao de 90 indo e voltando no eixo x"<<endl;
    cout<<"y/Y - Rotacao de 90 indo e voltando no eixo y"<<endl;
    cout<<"t - Habilitar translacao/rotaçao/escala objeto"<<endl;
    cout<<"l - Habilitar translacao do ponto de luz"<<endl;
    cout<<"n - Desenhar eixos locais"<<endl;
    cout<<"q - Sair"<<endl;
    cout<<"--------------Objetos Na Cena---------------------"<<endl;
    cout<<"1 - Incluir Carro"<<endl;
    cout<<"2 - Incluir Casa"<<endl;
    cout<<"3 - Incluir Casa 2"<<endl;
    cout<<"4 - Incluir Casa Modelada opengl"<<endl;
    cout<<"5 - Incluir Torre Modelada opengl"<<endl;
}

int main()
{
    infos();
    GUI gui = GUI(800,600,desenha,teclado);
}
