/*
Graph Creator by Andrew Thomas 5/17/20 Mr.Galbraith C++ Class. This program can Create Vertex, Create Edge, Remove Vertex, Remove Vertex, Print, Shortest Path, and Quit. Create Vertex will create a vertex, which is a class. Create Edge will create an edge between the Edge which is another class. Remove Vertex and Edge will remove an Vertex and a Edge correspondenly. Shortest Path will find the shortest path between nodes and give the value using Dijkstra's algorithm.
Source:https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm
 */
#include<iostream> // libraries
#include<cstring>
#include<vector>
using namespace std;
class node{ // node class
  char* label;
  //vector<int>& vec; 

   vector<node*> connection;
  //  vector<node*> connection = vector<node*>();

public:
  // MyClass(vector<node*> v) : connection(v) 
  // { 
  //} 
  //  node(vector<int>& arr) 
  //   : vec(arr) 
  // { 
  // } 
  // vector<node*>& connection;
  // vector<node*> connection = vector<node*>();
  void setlabel(char* l);
  char* getlabel();
  vector<node*> getv();
  // void vErase(vector<node*>::const_iterator it);
  /*
  node(vector<node*>& arr) 
        : connection(arr) 
    { 
    } 
  */
  //    void vErase(vector<node*>::const_iterator it) {
  //  connection.erase(it);
  // }

  void vPush(node* v) {//function is in class as otherwise doesnt recognize connect
    connection.push_back(v);
  }
  //   void removeCon(node** v) {//function is in class as otherwise doesnt recognize connect
  //connection.erase(v);
  //}

  // void vErase(iterator k) {
  //connection.erase(k);
  //}

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
//  void vErase(vector<node*>::const_iterator it) {
//  connection.erase(it);
// }

struct edge{ // structure edge
  node* v1 = NULL;
  node* v2 = NULL;
  int* weight = new int;

};
void Print(vector<node*>& graph, vector<edge*>& edgeList); // functions
void AddVertex(vector<node*>& graph, node* add); 
bool SearchVectorExists(vector<node*>& graph, char* name);
node* SearchVector(vector<node*>& graph, char* name);
void AddEdge(vector<edge*>& edgeList, node* n1, node* n2, int* weight);
void RemoveVector(node* remove, vector<node*>& graph, vector<edge*>& edgeList);
//vector<node*> deleteEdge(vector<node*>& graph, vector<edge*>& edgecont);
void deleteEdge(vector<node*>& graph, vector<edge*>& edgeList, vector<node*>& connection, node* Vertex1, node* Vertex2);
//void ShortestPath(vector<node*>& graph , vector<edge*>& edgeList);
void ShortestPath(vector<node*>& graph , vector<edge*>& edgeList, node* Vertex1, node* Vertex2);
void iterate( vector<node*> connection, node* Vertex2, int* counter,int* pathSet, int* pathWeight);
int* getWeight(vector<edge*>& edgeList, node* Vertex1, node* Vertex2);
void iterate( vector<node*> connection, node* Vertex2, int* counter, int*& pathSet, int*& pathWeight, vector<edge*>& edgeList, node* previous, vector<node*> graph, vector<node*>& path, vector<vector<node*>>& collection, node* Vertex1);
int main(){ // main
  bool* exists = new bool; // initializing variables
       (*exists) = false;
       vector<node*> connection = vector<node*>();
       vector<node*> graph = vector<node*>();
  vector<edge*> edgeList = vector<edge*>();
  char* funct = new char[20];
  //char* label = new char[20];
  //      char* label2 = new char[20];
  //    char* label3 = new char[20];
           char* label4 = new char[20];
      char* label5 = new char[20];
       char* label6 = new char[20];
             char* label7 = new char[20];
       char* label8 = new char[20];
       // vector<node*> test = vector<node*>();
       //int* weight = new int;
       bool exit;
  exit = false;
  cout << "Welcome to Graph Creator By Andrew Thomas" << endl;
  //    cin.get(funct, 20);
  //cin.clear()
  // cin.ignore();
  //cin.clear()
         do{
	   cout << "Please do an action. Add Vertex, Add Edge, Remove Vertex, Remove Edge, Print, Shortest Path, or Exit." << endl; // introduces functions
        //cin
	cin.get(funct, 20); // gets a function input
    cin.ignore();
    cin.clear();
    if(strcmp(funct, "Add Vertex") == 0){ // Add vertex
        cout << "Please eneter a label for the vertex you want to add" << endl;
	     char* label = new char[20];
	cin.get(label, 20);
    cin.ignore();
    cin.clear();
    // cout << label << endl;
    node* add = new node;
    // cout << "h1" << endl;
    (*add).setlabel(label); // creates vertex and puts the label on the vertex. Then the function addds it to the list Graph
    //  cout << "h1" << endl;
    AddVertex( graph,  add);
        //      cout << "please"
    cout << "added " << label << endl; 
      }
    else if(strcmp(funct, "Add Edge") == 0){ // Add Edge
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
    if(SearchVectorExists(graph, label2) && SearchVectorExists(graph, label3) && (*label3) != (*label2)){ // make sure that the two vertex exist in the graph
      AddEdge(edgeList, SearchVector(graph, label2), SearchVector(graph, label3), weight); // creates the stuture of edge and adds to list
      cout << "added edge" << endl;
    }
    else{
      cout << "invalid node input" << endl; // the nodes do not exist in the graph
      if((*label3) == (*label2)){
	cout << "you cannot connect a vertex to itself" << endl;
      }
    }
      }
    else if(strcmp(funct, "Remove Vertex") == 0){ // remove the vertex
            cout << "Please eneter a label for the vertex you want to remove" << endl;
               cin.get(label4, 20);
    cin.ignore();
    cin.clear();
    if(SearchVectorExists(graph, label4)){ // checks if the vertex exists in the graph
      RemoveVector(SearchVector(graph, label4),  graph, edgeList); // removes the vector from the graph
      cout << "vertex removed" << endl;
    }
    else{
      cout << "vertex " << label4 << " does not exist" << endl;
    }
    //  cout << label2 << endl;
    // cout << label3 << endl;
    //cout << (*weight) << endl;
      }
    else if(strcmp(funct, "Print") == 0){ // Prints the directional conection
	    Print(graph, edgeList);
	  }
    else if(strcmp(funct, "Shortest Path") == 0){ // finds the shortest path
	                cout << "please enter two node names" << endl;
            cin.get(label7, 20);
    cin.ignore();
    cin.clear();
        cin.get(label8, 20);
    cin.ignore();

    //     cout << label5 << endl;
    //cout << label6 << endl;
    // vector<node*> connection = (*Vertex1).getv();
    //  vector<node*> connection = (*SearchVector(graph, label5)).getv();
    // connection = (*SearchVector(graph, label5)).getv();
    if(SearchVectorExists(graph, label7) && SearchVectorExists(graph, label8) && (*label7) != (*label8)){ // checks if the two vertex exists in the graph

      ShortestPath(graph , edgeList, SearchVector(graph, label7), SearchVector(graph, label8)); // finds the shortest path
	  }
     else{
       cout << "invalid node input" << endl; // the nodes do not exist
      //  if((*label7) == (*label8)){
      //	cout << "you cannot connect a vertex to itself" << endl;
      // }
     }
	  }
      
    else if(strcmp(funct, "Remove Edge") == 0){ // removes edge
            cout << "please enter two node names" << endl;
            cin.get(label5, 20);
    cin.ignore();
    cin.clear();
        cin.get(label6, 20);
    cin.ignore();

    //     cout << label5 << endl;
    //cout << label6 << endl;
    // vector<node*> connection = (*Vertex1).getv();
    //  vector<node*> connection = (*SearchVector(graph, label5)).getv();
    connection = (*SearchVector(graph, label5)).getv();
    if(SearchVectorExists(graph, label5) && SearchVectorExists(graph, label6)){ // checks if the nodes exist in the graph
	  deleteEdge(graph, edgeList, connection , SearchVector(graph, label5), SearchVector(graph, label6));
    
	  /*fixing the connection issue
	   */
	  //connection = (*SearchVector(graph, label5)).getv();
	  /*
	  vector<node*>::iterator k;
	  cout << "here" << endl;
	    for(k=connection.begin(); k!=connection.end(); k++){ // goes through connection
      cout << "h3" << endl;
       cout << (*(*k)).getlabel() << endl;
      if((*k) != NULL && strcmp((*(*k)).getlabel(), (*SearchVector(graph, label6)).getlabel()) == 0){ 
	cout << "h4" << endl;
	
	cout << (*(*k)).getlabel() << endl;
	cout << "this" << endl;
	connection.erase(k); // remove the connection because there is no more edge
	cout << "that" << endl;
	connection.erase(k);		
	cout << "there" << endl;
		break;
	//return;
	//(*Vertex1).getv().erase(k);
	//(*Vertex1).vErase(k);
	//	break; 
      }
	    }

    
	  */

	  
	  // vector<node*> connection = (*Vertex1).getv();
      cout << "removed edge" << endl;
    }
    else{
      cout << "invalid node input" << endl; // the nodes do not exist in the graph
    }
    /*
temp
     */
    /*
    	  connection = (*SearchVector(graph, label5)).getv();
	  vector<node*>::iterator k;
	  cout << "here" << endl;
	    for(k=connection.begin(); k!=connection.end(); k++){ // goes through connection
      cout << "h3" << endl;
       cout << (*(*k)).getlabel() << endl;
      if((*k) != NULL && strcmp((*(*k)).getlabel(), (*SearchVector(graph, label6)).getlabel()) == 0){ 
	cout << "h4" << endl;
	
	cout << (*(*k)).getlabel() << endl;
	cout << "this" << endl;
	connection.erase(k); // remove the connection because there is no more edge
	cout << "that" << endl;
	//connection.erase(k);		
	cout << "there" << endl;
		break;
	//return;
	//(*Vertex1).getv().erase(k);
	//(*Vertex1).vErase(k);
	//	break; 
      }
	    }
    */    
}
    else if(strcmp(funct, "Exit") == 0){ // terminates the program
      exit = true; // the user wants to exit
          }
    else{ // that is not a function
            cout << "That is not a valid input." << endl;
          }

         }
	 while(exit == false); // continues to ask for functions until the user wants to exit

    return 0;
}
void AddVertex(vector<node*>& graph, node* add){ // adds a vertex into the graph
  //cout << "here" << endl;
  graph.push_back(add); // pushes the new vertex into the graph vector
  //cout << "wow" << endl;
}

void AddEdge(vector<edge*>& edgeList, node* n1, node* n2, int* weight){ // adds an edge to the edgeList
  edge* add = new edge(); // creates new edge
  (*n1).vPush(n2); // connects N1 to N2
  (*add).weight = weight; // puts Weight
  (*add).v1 = n1; //sets the first vertex
  (*add).v2 = n2; // sets the second vertex
  edgeList.push_back(add); // pushes the add
  //(*n1).vPush(n2);
  
}

bool SearchVectorExists(vector<node*>& graph, char* name){ // checks if the vertex is in teh graph
  //bool* SearchVectorExists(char* name){
  vector<node*>::iterator j; //iterator for edge vector
  for(j=graph.begin(); j!=graph.end(); j++){ //for entirety of graph list
    //cout << ";)" << endl;
    // cout << "star" << endl;
    //cout << (*(*(*j)).getlabel()) << endl;
    //cout << (*name) << endl;
    if((*(*(*j)).getlabel()) == (*name)){ // the vertex is in the graph
      // (*exists) = true;
      //  cout << "here" << endl;
      return true;
    }
   
}
  //  cout << "herez" << endl;
  return false;
}
node* SearchVector(vector<node*>& graph, char* name){ // returns the vertex from the graph
  vector<node*>::iterator j; //iterator for edge vector
  for(j=graph.begin(); j!=graph.end(); j++){ //for entirety of graph list
    //cout << ";)" << endl;
    // cout << "star" << endl;
    //cout << (*(*(*j)).getlabel()) << endl;
    //cout << (*name) << endl;
    if((*(*(*j)).getlabel()) == (*name)){ // this is the vertex
      return (*j); // return the vertex
    }
  }

}
void Print(vector<node*>& graph, vector<edge*>& edgeList){ // prints the connecion grdi
  vector<node*>::iterator a;
  vector<node*>::iterator k;
  vector<node*>::iterator z;
  vector<node*>::iterator p;
  vector<node*>::iterator j; //iterators for node vectors
  bool fal = new bool;
  fal = false;
  cout << "  ";
  for(j=graph.begin(); j!=graph.end(); j++){ //for entirety of graph list
    cout << (*(*j)).getlabel() << " "; // creates a horiziontal grid of the vertexs
  }
  
  cout << endl;
  for(k=graph.begin(); k!=graph.end(); k++){ //for entirety of graph list
    cout << (*(*k)).getlabel() << " "; // craetes a vertical grid
    // cout << endl;
    //  for(a=graph.begin(); a!=graph.end(); k++){
  vector<node*> connection = (*(*k)).getv();
    //   for(k=graph.begin(); k!=graph.end(); k++)
       for(a=graph.begin(); a!=graph.end(); a++){

	 for(p=connection.begin(); p!=connection.end(); p++){ // checks if connected
	   // cout << (*(*p)).getlabel();
	   // for(z=graph.begin(); z!=graph.end(); k++){
	if((*p) == (*a)){
	  fal = true; // connected
	  cout << "T"; // print that it is connected
	}
	
	//  cout << "F";
	//	}
	//	cout << " ";
	 }
	 if(fal == false){
	   cout << "F"; // its not conencted
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
void RemoveVector(node* remove, vector<node*>& graph, vector<edge*>& edgeList){ // remove vertex from graph vector
  // cout << (*remove).getlabel() << endl;
  vector<edge*>::iterator a;
  vector<node*>::iterator k;
  vector<node*>::iterator p;
  vector<node*>::iterator z; // node and edge iterators
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
      edgeList.erase(a); // removes any edge that contains the vertex
    break;
    }
    //}
    // }
    
  }
  // cout << "h2" << endl;
    for(k=graph.begin(); k!=graph.end(); k++){ //for entirety of graph list
      //    cout << (*(*k)).getlabel() << " ";
    // cout << endl;
    //  for(a=graph.begin(); a!=graph.end(); k++){
  vector<node*> connection = (*(*k)).getv();
  for(p=connection.begin(); p!=connection.end(); p++){ // for entirety of connection list
    //  if((*p) == remove){
    //  if((*(*p)) == (*remove)){
    // if((*p) != NULL){
    if((*p) != NULL && strcmp((*(*p)).getlabel(), (*remove).getlabel()) == 0){
      connection.erase(p); // if connected to this vertex remove the connection
    break;
    }
    }
  //}
    }
    for(z=graph.begin(); z!=graph.end(); z++){ // for entirety of graph list
      // if((*z) == remove){
      //  if((*(*z)) == (*remove)){
      //if((*z) != NULL){
      if((*z) != NULL && strcmp((*(*z)).getlabel(), (*remove).getlabel()) == 0){
	graph.erase(z); // erase the vertex from the graph list
      break;
      //}
      }
    }
    //cout << "h3" << endl;
}
void deleteEdge(vector<node*>& graph , vector<edge*>& edgeList,vector<node*>& connection, node* Vertex1, node* Vertex2) { // remove edge
  vector<edge*>::iterator a;
    vector<node*>::iterator k;
    vector<node*>::iterator p; // edge and node iterator
      vector<node*>::iterator j;

      // cout << "start" << endl;
  for(a=edgeList.begin(); a!=edgeList.end(); a++) { // goes through edge list
    //cout << "h1" << endl;
    if((*(*(*a)).v1).getlabel() != NULL && strcmp((*(*(*a)).v1).getlabel(), (*Vertex1).getlabel()) == 0 && (*(*(*a)).v2).getlabel() != NULL && strcmp((*(*(*a)).v2).getlabel(), (*Vertex2).getlabel()) == 0){ // this is the edge
      //  cout << "inside" << endl;
      // cout << "h2" << endl;
      //	cout << (*(*(*a)).v1).getlabel() << endl;
      //	cout << (*(*(*a)).v2).getlabel() << endl;
      //	cout << (*(*(*a)).weight) << endl;
	edgeList.erase(a);  // remove the edge
    break;
    }
    
    //}
    // }
    //     for(k=graph.begin(); k!=graph.end(); k++){ //for entirety of connection list
      //    cout << (*(*k)).getlabel() << " ";
    // cout << endl;
    //  for(a=graph.begin(); a!=graph.end(); k++){
  }
  //vector<node*> connection = (*Vertex1).getv();
   // for(k=(*Vertex1).getv().begin(); k!=(*Vertex1).getv().end(); k++){
   for(k=connection.begin(); k!=connection.end(); k++){ // goes through connection
     //cout << "h3" << endl;
     // cout << (*(*k)).getlabel() << endl;
      if((*k) != NULL && strcmp((*(*k)).getlabel(), (*Vertex2).getlabel()) == 0){ 
	//	cout << "h4" << endl;
	
	//cout << (*(*k)).getlabel() << endl;
	//cout << "this" << endl;
	//	vErase(k);
	//vErase(k)
	//vErase(k);
	connection.erase(k); // remove the connection because there is no more edge
	//cout << "that" << endl;
	//connection.assign(k, connection.end()-1);
	///connection.erase(k);		
	//	connection.erase(Vertex2);
	//connection.clear();
	//cout << "there" << endl;
	break;
	//return;
	//(*Vertex1).getv().erase(k);
	//(*Vertex1).vErase(k);
	//	break; 
    }
    }
  
  /*
  vector<node*> connect = (*Vertex1).getv();
      for(j = connect.begin(); j!=connect.end(); ++j)
      {
	if((*j) != NULL && strcmp((*j) -> getlabel(), (*Vertex2).getlabel()) == 0)
  {
	  connect.erase(j);
	  break;
	}
      }
  */
  // for(p=connection.begin(); p!=connection.end(); p++){
    //  if((*p) == remove){
    //  if((*(*p)) == (*remove)){
    // if((*p) != NULL){
  //  if((*p) != NULL && strcmp((*(*p)).getlabel(), (*Vertex1).getlabel()) == 0){
  /// connection.erase(p);
  //  break;
  // }
  // }
  //}
  //}

  

}
void ShortestPath(vector<node*>& graph , vector<edge*>& edgeList, node* Vertex1, node* Vertex2){ // finds the shortest path
  vector<node*>::iterator k;
  vector<node*>::iterator p;
  vector<node*>::iterator z;
  vector<node*>::iterator c;
  //vector<node*>vector<vector<node*>>::iterator d;
  vector<vector<node*>>::iterator d; // iterators
  int* counter = new int;
  int* pathSet = new int[100];
  int* pathWeight = new int;
  int* shortest = new int;
  vector<node*> path = vector<node*>();
  vector<vector<node*>> collection = vector<vector<node*>>();
  int* collectionNumber = new int;
  int* counterTwo = new int; // local varaibles
  (*collectionNumber) = 0;
  (*counterTwo) = 0;
  (*shortest) = 100000;
  (*pathWeight) = 0;
  (*counter) = 0;
  for(k=graph.begin(); k!=graph.end(); k++){ //goes through garph
    if((*k) != NULL && strcmp((*(*k)).getlabel(), (*Vertex1).getlabel()) == 0){ // this the is begining node
       vector<node*> connection2 = (*(*k)).getv();
       // pathWeight =+ getWeight(edgeList,  previous, SearchVector(graph, (*(*p)).getlabel()));
       path.push_back(Vertex1);
       iterate(connection2,  Vertex2, counter, pathSet, pathWeight, edgeList, SearchVector(graph, (*(*k)).getlabel()), graph, path, collection, Vertex1); // goes to the connections of the first vector and iteratres that process
       /*
         for(p=connection.begin(); p!=connection.end(); p++){
	   // cout << "h3" << endl;
	   //    cout << (*(*k)).getlabel() << endl;
      if((*p) != NULL && strcmp((*(*p)).getlabel(), (*Vertex2).getlabel()) == 0){
	cout << "path" << endl;
      }
	 }
       */
	//	cout << "h4endl;
    //  cout << (*(*k)).getlabel() << " ";
    // cout << endl;
    //  for(a=graph.begin(); a!=graph.end(); k++){
    //vector<node*> connection = (*(*k)).getv();
       //      if((*counter) == 0){
       // cout << "there is no path between " << (*Vertex1).getlabel()) << " and " << (*Vertex2).getlabel()) << endl;
  
    }
  }
  if((*counter) == 0){ // there was no path
	 cout << "there is no path between " << (*Vertex1).getlabel() << " and " << (*Vertex2).getlabel() << endl;
}
  else{ // there is path
	 //cout << sizeof((*pathSet)) << endl;
	 // cout << (*counter) << endl;
	 //	 cout << "here" << endl;
	 
    for(int i = 0; i < (*counter); i++){ // sorts through the length list
	   // cout << pathSet[i] << endl;
	   if(pathSet[i] < (*shortest)){
	     (*shortest) = pathSet[i];
	   }
	 }
    for(int i = 0; i < (*counter); i++){ // figuress out which one of the values were the least
	      //   cout << pathSet[i] << endl;
	   if(pathSet[i] == (*shortest)){
	     (*collectionNumber) = i+1;
	   }
	    }
	    // cout << "counters: ";
	    // cout << (*counterTwo);
	    //cout << " " << (*collectionNumber) << endl;
	    for(d=collection.begin(); d!=collection.end(); d++){
	      (*counterTwo)++;
	      if((*collectionNumber) == (*counterTwo)){ // this is the shortest path
		//	 cout << "counters: ";
		//cout << (*counterTwo);
		//cout << " " << (*collectionNumber) << endl;
		cout << "The shortest Path is " << (*shortest) << " units long" << endl; // gives the shortest length
	 cout << "the path goes ";
	 vector<node*> Npath = vector<node*>();
	 Npath = (*d);
	 // for(c=path.begin(); c!=path.end(); c++){
	 for(c=Npath.begin(); c!=Npath.end(); c++){ // finds the path from the path list and runs through the path and prints the nodes
	   cout << "to " << (*(*c)).getlabel() << " ";
	 }
	 cout << endl;

	    }
	    }
	    
       }
}
void iterate( vector<node*> connection, node* Vertex2, int* counter, int*& pathSet, int*& pathWeight, vector<edge*>& edgeList, node* previous, vector<node*> graph, vector<node*>& path, vector<vector<node*>>& collection, node* Vertex1){ // goes through teh connections until reaches the end vectdor
vector<node*>::iterator p;
 vector<node*>::iterator z;
  vector<node*>::iterator c;
 //vector<node*>::iterator c;
  for(p=connection.begin(); p!=connection.end(); p++){ // goes through conneciton
	   // cout << "h3" << endl;
	   //    cout << (*(*k)).getlabel() << endl;
    if((*p) != NULL && strcmp((*(*p)).getlabel(), (*Vertex2).getlabel()) == 0){ // end vector
	//	cout << "path" << endl;
	//	(*counter)++;
	(*pathWeight) = (*pathWeight) + (*getWeight(edgeList,  previous, SearchVector(graph, (*(*p)).getlabel())));
	
	int* newPath = new int;
	(*newPath) = (*pathWeight); // save path weight
	//	cout << (*pathWeight) << endl;
	(*pathWeight) = 0;
	pathSet[(*counter)] = (*newPath);
	(*counter)++;
	path.push_back(Vertex2);
	 vector<node*> pathCopy = vector<node*>();
	 for(z=path.begin(); z!=path.end(); z++){ // copy the path
	   pathCopy.push_back(SearchVector(graph, (*(*z)).getlabel()));
	 }
	 collection.push_back(pathCopy);  // save path
	 //  for(c=pathCopy.begin(); c!=pathCopy.end(); c++){
	 //  cout << "to " << (*(*c)).getlabel() << " ";
	 // }
	 path.clear();
	 path.push_back(Vertex1); // reset the variable
	 
//vector<node*> anotherpath = vector<node*>();
      }
    else{ // not the end
      (*pathWeight) = (*pathWeight) + (*getWeight(edgeList,  previous, SearchVector(graph, (*(*p)).getlabel()))); // add to the weight
	//cout << (*pathWeight) << endl;
      vector<node*> connection3 = (*(*p)).getv(); // iterates through that connection
	path.push_back(SearchVector(graph, (*(*p)).getlabel()));
	iterate(connection3,  Vertex2, counter, pathSet, pathWeight, edgeList, SearchVector(graph, (*(*p)).getlabel()), graph, path, collection, Vertex1); // recureses
      }
	    }

  }
int* getWeight(vector<edge*>& edgeList, node* Vertex1, node* Vertex2){ // gets the weight between two vvector
vector<edge*>::iterator a;
 for(a=edgeList.begin(); a!=edgeList.end(); a++) { // goes through the edgelist
    // cout << "h1" << endl;
    if((*(*(*a)).v1).getlabel() != NULL && strcmp((*(*(*a)).v1).getlabel(), (*Vertex1).getlabel()) == 0 && (*(*(*a)).v2).getlabel() != NULL && strcmp((*(*(*a)).v2).getlabel(), (*Vertex2).getlabel()) == 0){ // this is the egde
      return (*(*a)).weight; // the weight
    }
 }
}
