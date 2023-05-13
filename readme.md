# Project: Simple Point Of Sale System

## Introduction

This project is an items management system that could be used by any business selling
or storing non-perishable and perishable items. The list of features are:

- Import a list of items from a CSV file;
- See the list of items in the system;
- Add an item in the catalogue using the system;
- Remove an item from the catalogue using the system;
- Increase or decrease the stock of an item using the system;
- Export the list after the changes for a CSV file

## How to run

```cpp
g++ -Wall -std=c++11 -g -o exec *.cpp && ./exec 
```

## Modules

### Error

That module is present in all the other structures on this project. Because we use it to define if the object is in a good state. If not, it will have an error message inside it.

### Date

This module's responsibility is to create a data structure that will be used for Perishable items.
The date is composed of integer numbers and could be with or without time.
The operators overloaded in this class allow the programmer to increase efficiency when programming on the other system's part. With them, we could compare dates and also get the date from a cin or cout directly for the object.

### PosIO

PosIO is an abstract class that will enforce methods of save, write, load and read for the derived classes, and the only implementation here is using those methods inside the operators overloading >> and << for files or using the prompt.

### Item

Item is a class derived from PosIO, and that is also an abstract class because it has at least one pure virtual function. After, it will be used as a base for Perishable and NonPerishable classes. That is the core structure of the system. For this implementation, we had to override operators and also methods to access the private data members.

### Perishable and NonPerishable

Practically the same implementation for both. It's derived from Item. Perishable has a date as a data member and that makes it has more methods to deal with this logic.

### PosApp

The menu will control the system it implements and request all the actions from the user.
