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
void RemoveVector(node* remove, vector<node*>& graph, vector<edge*>& edgeList);
vector<node*> deleteEdge(vector<node*>& graph, vector<edge*>& edgecont);
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
      RemoveVector(SearchVector(graph, label4),  graph, edgeList);
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
	  deleteEdge(graph, edgeList);
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
  // void RemoveVector(Node* remove, ){

  //}
}
void RemoveVector(node* remove, vector<node*>& graph, vector<edge*>& edgeList){
  // cout << (*remove).getlabel() << endl;
  vector<edge*>::iterator a;
  vector<node*>::iterator k;
  vector<node*>::iterator p;
  vector<node*>::iterator z;
  // for(a=edgeList.begin(); a!=edgeList.end(); a++){
  // cout << "h1" << endl;
  for(a=edgeList.begin(); a!=edgeList.end(); a++) {
    // cout << (*remove).getlabel() << endl;
    // cout << (*(*(*a)).v1).getlabel() << endl;
    //if((*(*a)).v1 == remove || (*(*a)).v2 == remove){
    //if((*(*(*a)).v1) == (*remove) || (*(*(*a)).v2) == (*remove)){
    //cout << "wowz" << endl;
    
    //if((*(*(*a)).v1).getlabel() != NULL){
      //   if((*(*(*a)).v2).getlabel() != NULL){
    if((*(*(*a)).v1).getlabel() != NULL && strcmp((*(*(*a)).v1).getlabel(), (*remove).getlabel()) == 0 || (*(*(*a)).v2).getlabel() != NULL && strcmp((*(*(*a)).v2).getlabel(), (*remove).getlabel()) == 0){
      //  cout << "inside" << endl;
    edgeList.erase(a);
    break;
    }
    //}
    // }
    
  }
  // cout << "h2" << endl;
    for(k=graph.begin(); k!=graph.end(); k++){ //for entirety of connection list
      //    cout << (*(*k)).getlabel() << " ";
    // cout << endl;
    //  for(a=graph.begin(); a!=graph.end(); k++){
  vector<node*> connection = (*(*k)).getv();
  for(p=connection.begin(); p!=connection.end(); p++){
    //  if((*p) == remove){
    //  if((*(*p)) == (*remove)){
    // if((*p) != NULL){
    if((*p) != NULL && strcmp((*(*p)).getlabel(), (*remove).getlabel()) == 0){
    connection.erase(p);
    break;
    }
    }
  //}
    }
    for(z=graph.begin(); z!=graph.end(); z++){
      // if((*z) == remove){
      //  if((*(*z)) == (*remove)){
      //if((*z) != NULL){
      if((*z) != NULL && strcmp((*(*z)).getlabel(), (*remove).getlabel()) == 0){
      graph.erase(z);
      break;
      //}
      }
    }
    //cout << "h3" << endl;
}
vector<node*> deleteEdge(vector<node*>& graph, vector<edge*>& edgecont) {
  vector<edge*>::const_iterator k;
  vector<node*>::const_iterator i;
  vector<node*>::const_iterator j;
  cout << "Please enter the first node" << endl;
  char* firstnode = new char[80];
  cin.getline(firstnode, 80);
   cout << "Please enter the second node" << endl;
  char* secondnode = new char[80];
  cin.getline(secondnode, 80);
  for(k=edgecont.begin(); k!=edgecont.end(); ++k) {
    if((*k) -> v1 -> getlabel() != NULL) {
      if(strcmp((*k) -> v1 -> getlabel(), firstnode) == 0 || strcmp((*k) -> v2 -> getlabel(), secondnode) == 0) {
	edgecont.erase(k);
	break;
      }
    }
  }
  cout<< "I" << endl;
  for(i=graph.begin(); i!=graph.end(); ++i) {
    if(strcmp((*i) -> getlabel(), firstnode) == 0) {
      vector<node*> connect = (*i) -> getv();
      cout << "a" << endl;
	for(j=connect.begin(); j!=connect.end(); ++j) {
	  cout << (*j) -> getlabel();
	  if((*j) != NULL && strcmp((*j) -> getlabel(), secondnode) == 0) {
	    connect.erase(j);
	    break;
	  }
	}
    }
  }
  return graph;

}
