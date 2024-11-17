
class Action{
public:
    virtual void execute()=0;
};

class MenuItem{
    char* name;
    MenuItem* submenu[10];
    int submenuCount;
    int indent;
    Action* action;
    int chosenItem;
    int chosenSubmenuItem;
    MenuItem* parent;
    MenuItem* getParent();
    int chooseItem();
    void unchooseItem();
    int checkIfChosen();
    void downArrow();
    void upArrow();
    void print(int color);
    char printOption();
public:
    MenuItem();
    MenuItem(char *s);
    MenuItem* getItem(int i);
    void addItem(char *s);
    void addAction(Action* act);
    void start();
};
