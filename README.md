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

### 2- Add items to your menu.
Use the `addItem` function to add the main items to your menu, providing the item name for each.
```cpp
myMenu->addItem("File");
myMenu->addItem("Edit");
myMenu->addItem("View");
```

### 3- Add options to each item
To add an option, use the `getItem` function and specify an index. The items are indexed starting from zero, based on the order in which they were added.
</br>
Ensure the index is valid, as an invalid one may cause a runtime error.
```cpp
// adding three options to the File item (index 0) 
myMenu->getItem(0)->addItem("Option1");
myMenu->getItem(0)->addItem("Option2");
myMenu->getItem(0)->addItem("Option3");
```
For simplicity, you can create a pointer to an option and add items to it.
```cpp
// adding two options to the Edit item (index 1)
MenuItem* EditOption = myMenu->getItem(1);
EditOption->addItem("Option1"); 
EditOption->addItem("Option2"); 
```
For a simpler use case, you can predefine options in a string array and loop through them to add the options.
```cpp
// adding four options to the View item (index 2)
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

# How to control it

When you run the application, the menu will display only the main items with the first item highlighted.
</br>
For example, the output will look something like this:
```diff
+File
Edit
View
```
You can navigate through the items using the ***up*** and ***down*** arrows.
</br>
For example, pressing the down arrow will produce an output like this:
```diff
File
+Edit
View
```
To view the options for a particular selection (Expand this selection), press the ***Enter*** key.
</br>
For instance, pressing Enter on the second item `Edit` will produce output like this:
```diff
File
Edit
+  Option1
  Option2
View
```
Now you can navigate through `Option1` and `Option2` of the `Edit` selection
</br>
**Pressing the Enter key on an option with no sub-options will trigger an `action` (which will be explained in more detail in the next section).**
</br>
To go back to the main items (go back up one level), press the ***Backspace*** key.

### To summarize

***Up arrow*** - move up
</br>
***Down arrow*** - move down
</br>
***Enter key*** - Expand selection / Confirm selection
</br>
***Backspace*** - Go back up one level
</br>

### Adding functionality (Actions)

Your menu is now looking good and almost ready to go, but it still lacks functionality.
</br>
Let me walk you through an example to demonstrate how to add functionality to the menu.
</br>
</br>
Consider a program that functions as a calculator, offering options to add, subtract, multiply, or divide two numbers.
</br>
Here's how to build the menu for this application.
```cpp
MenuItem* calculator = new MenuItem();
calculator->addItem("Add");
calculator->addItem("Subtract");
calculator->addItem("Multiply");
calculator->addItem("Divide");
```

