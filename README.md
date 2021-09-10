# Adobe-store

Implementetion of BS Trees with C++ and storing in files

> ```Problem statement
> ## Problem to be solved:
> Implement a menu-driven program for managing a software store. All information about the
> available software is stored in a file software. This information includes the name, version,
> quantity, and price of each package. When it is invoked, the program automatically creates a
> binary search tree with one node corresponding to one software package and includes as its key
> the name of the package and its version. Another field in this node should include the position of
> the record in the file software. The only access to the information stored in software should be
> through this tree.
> The program should allow the file and tree to be updated when new software packages arrive at
> the store and when some packages are sold. The tree is updated in the usual way. All packages
> are entry ordered in the file software; if a new package arrives, then it is put at the end of the file.
> If the package already has an entry in the tree (and the file), then only the quantity field is
> updated. If a package is sold out, the corresponding node is deleted from the tree, and the
> quantity field in the file is changed to 0.
> ```

- Language : C++
- Actions : CRUD on applications
