#include "Matrix.h"

vector<vector<int>> fillMatrix(ifstream& inFile, vector<vector<int>>& v1, int size) {
    vector <int> tempRow;
    int temp;
    inFile >> size;

    for (int r = 0; r < size; r++) {
        tempRow.clear();
        for (int c = 0; c < size; c++) {
            inFile >> temp;
            tempRow.push_back(temp);
        }
        v1.push_back(tempRow);
    }
    return v1;
}

void printMatrix(vector<vector<int>> v1, int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            cout << setw(5) << right << v1[r][c];
        }
        cout << endl;
    }
    cout << endl << endl;
}

void multMatrix(vector<vector<int>> v1, vector<vector<int>> v2, vector<vector<int>>& multV1, int size) {

    vector <int> tempRow;
    int temp;

    for (int r = 0; r < size; r++) {
        tempRow.clear();
        for (int c = 0; c < size; c++) {
            temp = 0;
            for (int k = 0; k < size; k++) {
                temp += v1[r][k] * v2[k][c];
            }
            tempRow.push_back(temp);
        }
        multV1.push_back(tempRow);
    }
}

void menuChoice1() {
    bool x = true;
    while (x == true) {

        bool trans, reflex, symm;
        string vectorString = "Which vector dimension (2-4) do you prefer? ";
        int vectorSize = vectorChoice(vectorString);
        cout << endl << endl;

        if (vectorSize == 2) {
            vector<vector<int>> x2Matrix = { { 1, 0 }, { 0, 1} };
            cout << "The current matrix is:" << endl;
            printMatrix((vector<vector<int>>(x2Matrix) = { { 1, 0 }, { 0, 1} }), vectorSize);
            reflex = reflexive(x2Matrix, vectorSize);
            isReflexive(reflex);
            symm = symmetric(x2Matrix, vectorSize);
            isSymmetric(symm);
            trans = transitive(x2Matrix, vectorSize);
            isTransitive(trans);
            transitiveClosure(x2Matrix, vectorSize);
            x = false;
            continue;
        }

        else if (vectorSize == 3) {
            vector<vector<int>> x3Matrix = { { 1, 1, 0 }, { 0, 1, 0 },{ 1, 0, 1} };
            cout << "The current matrix is:" << endl;
            printMatrix(x3Matrix, vectorSize);
            reflex = reflexive(x3Matrix, vectorSize);
            isReflexive(reflex);
            symm = symmetric(x3Matrix, vectorSize);
            isSymmetric(symm);
            trans = transitive(x3Matrix, vectorSize);
            isTransitive(trans);
            transitiveClosure(x3Matrix, vectorSize);
            x = false;
            continue;
        }

        else if (vectorSize == 4) {
            vector<vector<int>> x4Matrix = { {1, 1, 1, 0}, {1, 1, 0, 1},
                                            {1, 0, 0, 0},{0, 1, 0, 1} };
            cout << "The current matrix is:" << endl;
            printMatrix(x4Matrix, vectorSize);
            reflex = reflexive(x4Matrix, vectorSize);
            isReflexive(reflex);
            symm = symmetric(x4Matrix, vectorSize);
            isSymmetric(symm);
            trans = transitive(x4Matrix, vectorSize);
            isTransitive(trans);
            transitiveClosure(x4Matrix, vectorSize);
            x = false;
            continue;
        }

        else {
            cout << "Please enter a number from 2-4." << endl;
            continue;
        }
    }
}

void menuChoice2() {
    bool y = true;
    bool trans, reflex, symm;
    int size = 4;

    while (y == true) {
        ifstream inFile;
        inFile.open("vector.txt");
        if (!inFile.is_open()) {
            cout << "Unable to open vector file\n";
            y = false;
            break;
        }
        vector<vector<int>> v1;
        v1 = fillMatrix(inFile, v1, size);
        size = v1.size();
        printMatrix(v1, size);
        reflex = reflexive(v1, size);
        isReflexive(reflex);
        symm = symmetric(v1, size);
        isSymmetric(symm);
        trans = transitive(v1, size);
        isTransitive(trans);
        transitiveClosure(v1, size);

        inFile.close();
        y = false;
    }
}

int vectorChoice(string outString) {
    string choiceVectorSize = "";
    while (choiceVectorSize != "2" && choiceVectorSize != "3" && choiceVectorSize != "4") {
        cout << outString;
        cin >> choiceVectorSize;
        if (choiceVectorSize == "2" || choiceVectorSize == "3" || choiceVectorSize == "4") {
            break;
        }
        else {
            continue;
        }
    }
    int choice = stoi(choiceVectorSize);
    return choice;
}

bool reflexive(vector<vector<int>> matrix, int size) {
    for (int i = 0; i < size; ++i) {
        if (matrix[i][i] != 1)
            return false;
    }
    return true;
}

void isReflexive(bool result) {
    if (result == false) {
        cout << "The matrix is not reflexive" << endl;
    }
    else {
        cout << "The matrix is reflexive" << endl;
    }
}


bool symmetric(vector<vector<int>> matrix, int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (matrix[r][c] == 1 && matrix[c][r] != 1 && c != r) {
                return false;
            }
        }
    }
    return true;
}

void isSymmetric(bool result) {
    if (result == false) {
        cout << "The matrix is not symmetric" << endl;
    }
    else {
        cout << "The matrix is symmetric" << endl;
    }
}

bool transitive(vector<vector<int>> matrix, int size) {
    string notTrans = "The matrix is not transitive";
    string trans = "The matrix is transitive";
    vector<vector<int>> newMatrix(size, vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                newMatrix[i][j] += matrix[i][k] * matrix[k][j];
            }
        }
    }
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (newMatrix[r][c] == 1 && matrix[r][c] == 0) {
                return false;
            }
        }
    }
    return true;
}

void isTransitive(bool result) {
    if (result == false) {
        cout << "The matrix is not transitive" << endl << endl;
    }
    else {
        cout << "The matrix is transitive" << endl << endl;
    }
}

void transitiveClosure(vector<vector<int>> matrix, int size) {
    vector<vector<int>> multipliedMatrix(size, vector<int>(size));
    vector<vector<int>> transitiveMatrix(size, vector<int>(size));
    vector<vector<int>> tempMatrix(size, vector<int>(size));
    multipliedMatrix = matrix;
    int powerCount = 2;

    while (true) {
        transitiveMatrix = multipliedMatrix;
        tempMatrix = multipliedMatrix;
        multipliedMatrix.clear();
        multipliedMatrix.resize(size, vector<int>(size));
        for (int r = 0; r < size; r++) {                        //Code used in CS201 Handout
            for (int c = 0; c < size; c++) {
                for (int k = 0; k < size; k++) {
                    multipliedMatrix[r][c] += matrix[r][k] * tempMatrix[k][c];
                    if (multipliedMatrix[r][c] > 0) {
                        multipliedMatrix[r][c] = 1;
                    }
                    else {
                        multipliedMatrix[r][c] = 0;
                    }
                }
            }
        }

        if (transitiveMatrix == multipliedMatrix) {
            cout << "The transitive closure is: " << endl;
            printMatrix(transitiveMatrix, size);
            cout << endl;
            break;
        }
        else {
            cout << "The result of the matrix to the power of " << powerCount << " is:" << endl;
            printMatrix(multipliedMatrix, size);
            powerCount += 1;
            continue;
        }
    }
}

vector<vector<int>> transClosure(vector<vector<int>> &matrix, int size) {
    vector<vector<int>> result(size, vector<int>(size));
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            result[i][j] = matrix[i][j]; 
    for (int k = 0; k < size; k++)
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                result[i][j] = result[i][j];
    return result;
}
