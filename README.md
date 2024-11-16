# Menu class

This project provides a class that simplifies creating console applications with interactive menus by managing the complexities of menu display and control, enabling developers to focus entirely on their application’s functionality.

# Download and setup (Two options)

### Option 1 - Download 'new_project' file

Simply download and uncompress the `new_project` file to get a ready-to-use project.

### Option 2 - Add menu class to your project

Download the `menu.cpp` and `menu.h` files, and add them to your project
</br>
Make sure to include `menu.h` in your main file.

```cpp
#include "menu.h"
```

# How to use it

### 1- Create a `MenuItem` object using a pointer.
To get started, simply create an object of the `MenuItem` class. This object will contain all your menu information and serve as the starting point for your application.
```cpp
MenuItem* myMenu = new MenuItem();
```

### 2- Add options to your menu.
Use the `addItem` function to add main options to your menu, providing the option name for each.
```cpp
myMenu->addItem("File");
myMenu->addItem("Edit");
myMenu->addItem("View");
```

### 3- Add sub-options to each option
To add a sub-option, use the `getItem` function and specify an index. The options are indexed starting from zero, based on the order in which they were added.
</br>
Ensure the index is valid, as an invalid one may cause a runtime error.
```cpp
// adding three sub-options to the File option (index 0) 
myMenu->getItem(0)->addItem("Option1");
myMenu->getItem(0)->addItem("Option2");
myMenu->getItem(0)->addItem("Option3");
```
For simplicity, you can create a pointer to an option and add items to it.
```cpp
// adding two sub-options to the Edit option (index 1)
MenuItem* EditOption = myMenu->getItem(1);
EditOption->addItem("Option1"); 
EditOption->addItem("Option2"); 
```
For a simpler use case, you can predefine options in a string array and loop through them to add the options.
```cpp
// adding four sub-options to the View option (index 2)
char strs[4][10]={"Option1","Option2","Option3","Option4"};
for(int i = 0; i < 4; i++){
  myMenu->getItem(2)->addItem(strs[i]);
}
```

### 4- Display your menu
Once you've set up your menu, use the `start` function to display it.
```cpp
myMenu->start();
```
Your menu now should be structured like this

```
File
  Option1
  Option2
  Option3
Edit
  Option1
  Option2
View
  Option1
  Option2
  Option3
  Option4
```
