#include "menu.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string.h>
using namespace std;

void changeColor(int c){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

    MenuItem::MenuItem(){
        action = nullptr;
        submenuCount = 0;
        chosenItem = 0;
        chosenSubmenuItem = -1;
        name = new char[60];
        name[0]='\0';
        indent = 0;
        for(int i = 0; i < 10; i++) submenu[i]=nullptr;
        parent = nullptr;
    }
    MenuItem::MenuItem(char *s){
        action = nullptr;
        submenuCount = 0;
        chosenItem = 0;
        chosenSubmenuItem = -1;
        name = new char[60];
        strcpy(name,s);
        indent = 0;
        for(int i = 0; i < 10; i++) submenu[i]=nullptr;
        parent = nullptr;
    }
    void MenuItem::addItem(char *s){
        if(submenuCount >= 10) return;
        submenu[submenuCount]=new MenuItem(s);
        submenu[submenuCount]->parent=this;
        submenu[submenuCount]->indent=indent+3;
        submenuCount++;
    }
    MenuItem* MenuItem::getItem(int i){
        if(i >= submenuCount) return nullptr;
        return submenu[i];
    }
    MenuItem* MenuItem::getParent(){
        return parent;
    }
    int MenuItem::chooseItem(){
        if(submenuCount==0) return 1;
        chosenItem = 1;
        chosenSubmenuItem = 0;
        return 0;
    }
    void MenuItem::unchooseItem(){
        chosenItem = 0;
        chosenSubmenuItem = -1;
    }
    int MenuItem::checkIfChosen(){
        return chosenItem;
    }
    void MenuItem::downArrow(){
        if(chosenSubmenuItem!=-1) chosenSubmenuItem = (chosenSubmenuItem+1)%submenuCount;
    }
    void MenuItem::upArrow(){
        if(chosenSubmenuItem!=-1) chosenSubmenuItem = (chosenSubmenuItem-1+submenuCount)%submenuCount;
    }
    void MenuItem::addAction(Action* act){
        action = act;
    }
    void MenuItem::print(int color = 0){
        for(int i = 0; i < indent; i++) cout << ' ';
        if(color && chosenSubmenuItem==-1){
            cout << ">";
            changeColor(0x47);
        }
        else if(color && parent){
            changeColor(0x0a);
        }
        cout << name << '\n';
        changeColor(0x07);
        if(checkIfChosen()){
            for(int i = 0; i < submenuCount; i++){
                if(i==chosenSubmenuItem) submenu[i]->print(1);
                else submenu[i]->print();
            }
        }
    }
    char MenuItem::printOption(){
        if(parent!=nullptr){
            parent->printOption();
        }
        cout << name;
        if(submenuCount) cout << "/";
        return '\0';
    }
    void MenuItem::start(){

        chooseItem();
        MenuItem* curr=this;

        while(true){
            system("cls");
            cout << "Current selection: " << curr->printOption() << '\n';
            print(1);
            char c = getch();
            if(c==13){//enter
                int idx = curr->chosenSubmenuItem;
                if(idx==-1) continue;
                curr = curr->getItem(idx);
                int done = curr->chooseItem();
                if(done){
                    system("cls");
                    cout << "Option selected: ";
                    curr->printOption();
                    cout << "\n\n";
                    if(curr->action!=nullptr){
                        curr->action->execute();
                    }
                    cout << "\nPress any key to continue...";
                    curr = curr->getParent();
                    getch();
                    continue;
                }
            }
            else if(c==8){
                if(curr->getParent()==nullptr) continue;
                curr->unchooseItem();
                curr=curr->getParent();
            }
            else if(c==-32){
                c=getch();
                if(c==80){ // down
                    curr->downArrow();
                }
                else if(c==72){ // up
                    curr->upArrow();
                }
            }
        }
    }
