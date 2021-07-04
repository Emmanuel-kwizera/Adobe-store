#include<iostream>
#include <fstream>
#include<cstring>
#include <bits/stdc++.h>
using namespace std;

struct Node {
	string name;
	int record_position;
	Node *left, *right;
} *first;

struct Node * createNode(string name, int pos){
	struct Node * temp=new Node();
	temp->name=name;
	temp->record_position=pos;
	temp->left=NULL;
	temp->right=NULL;
return temp;
}

int pos=0;

void inorderTraversal(Node * tree_node) {
  if (tree_node == NULL)
    return;
  inorderTraversal(tree_node -> left);
  std::cout << tree_node -> name << endl;
  inorderTraversal(tree_node -> right);
}

bool checkNode( Node *tree_node, string name ) {
	if ( tree_node == NULL ) {
		return false;
	}
	else if ( name == tree_node->name ) {
		pos=tree_node->record_position;
		return true;
	}
	else if ( name < tree_node->name ) {
		return checkNode( tree_node->left, name );
	}
	else {
		return checkNode( tree_node->right, name );
	}
	
}

void insert(Node *&first, string name, int pos) {
	if ( first == NULL ) {
		first = createNode(name,pos) ;
		return;
	}
	else if ( name < first->name ) {
		insert( first->left, name, pos );
	}
	else {
		insert( first->right, name, pos );
	}
}

void createTree(){
	string name;
	ifstream infile;
	string line;
	infile.open("software.txt");
	string fin1,fin2,fin3,fin4,fin5,fin6;
	int i;
	while(getline(infile, line)){
		istringstream iss(line);
		fin5="\0";
		fin6="\0";
		iss>> fin1>>fin2>>fin3>>fin4>>fin5>>fin6;
		if(fin6.empty()){
			if(fin5.empty()){
				name=fin1+" "+fin2;
			}else{
				name=fin1+" "+fin2+" "+fin3;
			}
		}else{
			name=fin1+" "+fin2+" "+fin3+" "+fin4;
		}
		insert(first,name, i);
		i++;
	}
	infile.close();
}

void InsertNewSoftware(){
	string software, quantity,name;
	bool found;
	string fin1,fin2,fin3,fin4,fin5,fin6;
	std::cout<<"Enter the software";
	cin.ignore();
	getline(cin,software);
	istringstream iss(software);
	iss>> fin1>>fin2>>fin3>>fin4>>fin5>>fin6;
	if(fin6.empty()){
		if(fin5.empty()){
			name=fin1+" "+fin2;
		}else{
			name=fin1+" "+fin2+" "+fin3;
		}
	}else{
		name=fin1+" "+fin2+" "+fin3+" "+fin4;
	}
	found=checkNode(first,name);
	ifstream infile;
	string line;
	if(found==true){
		if(fin6.empty()){
			if(fin5.empty()){
			}else{
				quantity=fin4;
			}
		}else{
			quantity=fin5;
		}
		string soft[100];
		string str;
		int k=0;
		infile.open("software.txt");
		for (int lineno = 0; getline (infile,line)!=NULL ; lineno++){
			if (lineno == pos){
				istringstream iss(line);
				iss>> fin1>>fin2>>fin3>>fin4>>fin5>>fin6;
					if(fin6.empty()){
						if(fin5.empty()){
							fin3=quantity;
						}else{
							fin4=quantity;
						}
					}else{
						fin5=quantity;
					}
					line= fin1+" "+fin2+" "+fin3+" "+fin4+" "+fin5+ " "+fin6;
				}
				soft[k]=line;
				k++;
		}
			ofstream out;
			out.open("software.txt", ios::out);
			for(int i=0;i<100;i++){
				if(i==k-1)
					out;
				else
					out;
			}
	}else{
		ofstream out;
		out.open("software.txt", ios::app);
		out;
		out.close();
		first=NULL;		
	}
	createTree();
	cout<<"The inorder traversal of the tree after inserting new software is";
	inorderTraversal(first);
}

struct Node * leftMostValue(struct Node* Tree_node){
	struct Node* p = Tree_node;
	while (p->left != NULL)
		p = p->left;
	return p;
}

struct Node* nodeDeletion(struct Node* tree_node, string name){
	if (tree_node == NULL)
		return first;
	if (name < tree_node->name)
		tree_node->left = nodeDeletion(tree_node->left, name);
	else if (name > tree_node->name)	
		tree_node->right = nodeDeletion(tree_node->right, name);
	else{
		if (tree_node->left == NULL){
			struct Node *temp = tree_node->right;
			free(tree_node);
			return temp;
		}else if (tree_node->right == NULL){
			struct Node *temp = tree_node->left;
			free(tree_node);
			return temp;
		}
		struct Node* temp = leftMostValue(tree_node-> right);
		tree_node->name = temp->name;
	}
}

//void sell() {
//    string product;
//    int copies;
//    bool found;
//    ifstream infile;
//    string line;
//    string quantity;
//    string soft[100];
//    string fin1, fin2, fin3, fin4, fin5, fin6;
//    int k = 0;
//    std::cout << "Enter the product to be sold" <
//      cin.ignore();
//    getline(cin, product);
//    std::cout << "Enter the quantities to be sold" <
//      cin >> copies;
//    infile.open("input.txt");
//    found = checkNode(first, product);
//    if (found == true) {
//      for (int lineno = 0; getline(infile, line) != NULL; lineno++) {
//        if (lineno == pos) {
//          stringstream iss(line);
//          if (fin6.empty()) {
//            if (fin5.empty()) {
//              quantity = fin3;
//            } else {
//              quantity = fin4;
//            }
//          } else {
//            quantity = fin5;
//          }
//          copies = stoi(quantity) - copies;
//          std::stringstream outs;
//          string remaining;
//          outs << copies;
//          remaining = outs.str();
//          if (copies >= 0) {
//            if (copies == 0) {
//              first = nodeDeletion(first, product);
//              cout << "After the product is sold out the inorder traversal of the tree is" <
//                inOrderTraversal(first);
//              if (fin6.empty()) {
//                if (fin5.empty()) {
//                  fin3 = "0";
//                } else {
//                  fin4 = "0";
//                }
//              } else {
//                fin5 = "0";
//              }
//            } else {
//              if (fin6.empty()) {
//                if (fin5.empty()) {
//                  fin3 = remaining;
//                } else {
//                  fin4 = remaining;
//                }
//              } else {
//                fin5 = remaining;
//              }
//            }
//          } else
//        }
//        line = fin1 + " " + fin2 + " " + fin3 + " " + fin4 + " " + fin5 + " " + fin6;
//      }
//      soft[k] = line;
//      k++;
//    }
//    infile.close();
//    ofstream out;
//    out.open("input.txt", ios::out);
//    for (int i = 0; i {
//        if (i == k - 1)
//          out <
//          else
//            out <
//      }
//      out.close();
//    }
//}

int main(){
	int ch;
	char input='Y';
	createTree();
	cout<<"The inorder traversal of the initial tree is"<<endl;
	inorderTraversal(first);
	while(input=='Y'){
	std::cout<
		std::cout<<"1: Insert new software"<<endl;
		std::cout<<"2: Sell the software"<<endl;
		std::cout<<"3: Exit"<<endl;
		std::cout<<"Enter the choice";	
		cin>>ch;
		switch(ch){
			case 1:
				InsertNewSoftware();
				break;
//			case 2:
//				sell();
//				break;
//			case 3:
//				clean();
//				break;
			default:
				std::cout<<"Error, bad input, quitting\n";
				break;		
		}
		std::cout<<"Do you want to continue?";
		cin>>input;
	}
system("pause");
return 0;
}
