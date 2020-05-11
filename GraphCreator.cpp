#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
class node{
  char* label;
vector<node*> connection;
public:
  void setlabel(char* l);
  char* getlabel();
  vector<node*> getv();
  void vPush(node* v) {//function is in class as otherwise doesnt recognize connect
    connection.push_back(v);
  }
  
  void vErase(vector<node*>::const_iterator it) {
    connection.erase(it);
  }

};
void node::setlabel(char* l){
  label = l;
  }
char* node::getlabel(){
    return label;
  }
vector<node*> node::getv() {
  return connection;
}


struct edge{
  node* v1 = NULL;
  node* v2 = NULL;
  int* weight = new int;

};
void Print(vector<node*>& graph, vector<edge*>& edgeList);
void AddVertex(vector<node*>& graph, node* add); 
bool SearchVectorExists(vector<node*>& graph, char* name);
node* SearchVector(vector<node*>& graph, char* name);
void AddEdge(vector<edge*>& edgeList, node* n1, node* n2, int* weight);
int main(){
       bool* exists = new bool;
       (*exists) = false;
       vector<node*> graph = vector<node*>();
  vector<edge*> edgeList = vector<edge*>();
  char* funct = new char[20];
  //char* label = new char[20];
  //      char* label2 = new char[20];
  //    char* label3 = new char[20];
           char* label4 = new char[20];
      char* label5 = new char[20];
       char* label6 = new char[20];

       //int* weight = new int;
       bool exit;
  exit = false;
  cout << "Welcome to Graph Creator By Andrew Thomas" << endl;
  //    cin.get(funct, 20);
  //cin.clear()
  // cin.ignore();
  //cin.clear()
         do{
        cout << "Please do an action. Add Vertex, Add Edge, Remove Vertex, Remove Edge, Print, Shortest Path, or Exit." << endl;
        //cin
    cin.get(funct, 20);
    cin.ignore();
    cin.clear();
      if(strcmp(funct, "Add Vertex") == 0){
        cout << "Please eneter a label for the vertex you want to add" << endl;
	     char* label = new char[20];
	cin.get(label, 20);
    cin.ignore();
    cin.clear();
    // cout << label << endl;
    node* add = new node;
    // cout << "h1" << endl;
    (*add).setlabel(label);
    //  cout << "h1" << endl;
    AddVertex( graph,  add);
        //      cout << "please"
    cout << "added " << label << endl; 
      }
      else if(strcmp(funct, "Add Edge") == 0){
        cout << "please enter two node names and a weight" << endl;
	      char* label2 = new char[20];
       char* label3 = new char[20];
       int* weight = new int;
	cin.get(label2, 20);
    cin.ignore();
    cin.clear();
        cin.get(label3, 20);
    cin.ignore();
    cin.clear();
    //cin.get(, 20);
    cin >> (*weight);
    cin.ignore();
    cin.clear();
    //cout << label2 << endl;
    //cout << label3 << endl;
    //cout << (*weight) << endl;
    //vector<> ar = { 1, 2, 3, 4, 5 };  
    if(SearchVectorExists(graph, label2) && SearchVectorExists(graph, label3) && (*label3) != (*label2)){
      AddEdge(edgeList, SearchVector(graph, label2), SearchVector(graph, label3), weight);
      cout << "added edge" << endl;
    }
    else{
      cout << "invalid node input" << endl;
      if((*label3) == (*label2)){
	cout << "you cannot connect a vertex to itself" << endl;
      }
    }
      }
          else if(strcmp(funct, "Remove Vertex") == 0){
            cout << "Please eneter a label for the vertex you want to remove" << endl;
               cin.get(label4, 20);
    cin.ignore();
    cin.clear();
    if(SearchVectorExists(graph, label4)){
      cout << "vertex removed" << endl;
    }
    else{
      cout << "vertex " << label4 << " does not exist" << endl;
    }
    //  cout << label2 << endl;
    // cout << label3 << endl;
    //cout << (*weight) << endl;
      }
  	  else if(strcmp(funct, "Print") == 0){
	    Print(graph, edgeList);
	  }
	  else if(strcmp(funct, "Shortest Path") == 0){

	  }
      
          else if(strcmp(funct, "Remove Edge") == 0){
            cout << "please enter two node names" << endl;
            cin.get(label5, 20);
    cin.ignore();
    cin.clear();
        cin.get(label6, 20);
    cin.ignore();

    //     cout << label5 << endl;
    //cout << label6 << endl;
        if(SearchVectorExists(graph, label5) && SearchVectorExists(graph, label6)){
  
      cout << "removed edge" << endl;
    }
    else{
      cout << "invalid node input" << endl;
    }

     }
          else if(strcmp(funct, "Exit") == 0){
            exit = true;
          }
          else{
            cout << "That is not a valid input." << endl;
          }

         }
      while(exit == false);

    return 0;
}
void AddVertex(vector<node*>& graph, node* add){
  //cout << "here" << endl;
  graph.push_back(add);
  //cout << "wow" << endl;
}

void AddEdge(vector<edge*>& edgeList, node* n1, node* n2, int* weight){
  edge* add = new edge();
  (*n1).vPush(n2);
  (*add).weight = weight;
    (*add).v1 = n1;
  (*add).v2 = n2;
  edgeList.push_back(add);
  //(*n1).vPush(n2);
  
}

bool SearchVectorExists(vector<node*>& graph, char* name){
  //bool* SearchVectorExists(char* name){
  vector<node*>::iterator j; //iterator for edge vector
  for(j=graph.begin(); j!=graph.end(); j++){ //for entirety of connection list
    //cout << ";)" << endl;
    // cout << "star" << endl;
    //cout << (*(*(*j)).getlabel()) << endl;
    //cout << (*name) << endl;
    if((*(*(*j)).getlabel()) == (*name)){
      // (*exists) = true;
      //  cout << "here" << endl;
      return true;
    }
   
}
  //  cout << "herez" << endl;
  return false;
}
node* SearchVector(vector<node*>& graph, char* name){
  vector<node*>::iterator j; //iterator for edge vector
  for(j=graph.begin(); j!=graph.end(); j++){ //for entirety of connection list
    //cout << ";)" << endl;
    // cout << "star" << endl;
    //cout << (*(*(*j)).getlabel()) << endl;
    //cout << (*name) << endl;
    if((*(*(*j)).getlabel()) == (*name)){
      return (*j);
    }
  }

}
void Print(vector<node*>& graph, vector<edge*>& edgeList){
  vector<node*>::iterator a;
  vector<node*>::iterator k;
  vector<node*>::iterator z;
  vector<node*>::iterator p;
  vector<node*>::iterator j; //iterator for edge vector
  bool fal = new bool;
  fal = false;
  cout << "  ";
  for(j=graph.begin(); j!=graph.end(); j++){ //for entirety of connection list
    cout << (*(*j)).getlabel() << " ";
  }
  
  cout << endl;
  for(k=graph.begin(); k!=graph.end(); k++){ //for entirety of connection list
    cout << (*(*k)).getlabel() << " ";
    // cout << endl;
    //  for(a=graph.begin(); a!=graph.end(); k++){
  vector<node*> connection = (*(*k)).getv();
    //   for(k=graph.begin(); k!=graph.end(); k++)
       for(a=graph.begin(); a!=graph.end(); a++){

	 for(p=connection.begin(); p!=connection.end(); p++){
	   // for(z=graph.begin(); z!=graph.end(); k++){
	if((*p) == (*a)){
	  fal = true;
	    cout << "T";
	}
	
	//  cout << "F";
	//	}
	//	cout << " ";
	 }
	 if(fal == false){
	   cout << "F";
	 }
	 else{
	   fal = false;
	 }
	 cout << " ";
       }
    cout << endl;
  }
}
