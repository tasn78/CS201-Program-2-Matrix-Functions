
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

vector<vector<int>> fillMatrix(ifstream& inFile, vector<vector<int>>& v1, int size);
void printMatrix(vector<vector<int>>, int size);
void multMatrix(vector<vector<int>> v1, vector<vector<int>> v2, vector<vector<int>>& multV1, int size);
void menuChoice1();
int vectorChoice(string outString);
bool reflexive(vector<vector<int>> matrix, int size);
void isReflexive(bool result);
bool symmetric(vector<vector<int>> matrix, int size);
void isSymmetric(bool result);
bool transitive(vector<vector<int>> matrix, int size);
void isTransitive(bool result);
void transitiveClosure(vector<vector<int>> matrix, int size);
vector<vector<int>> transClosure(vector<vector<int>>& matrix, int size);

void menuChoice2();