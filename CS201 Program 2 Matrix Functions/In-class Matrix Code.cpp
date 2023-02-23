/*#include "Matrix.h"

using namespace std;

int main() {
    ifstream inFile;
    inFile.open("text.txt");
    if (!inFile.is_open()) {
        cout << "Unable to open file\n";
        return 1;
    }

    int size = 3;
    int arr[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
    fillMatrix(inFile, arr, size);
    printMatrix(arr, size);

    inFile.close();

    ifstream inFile2;
    inFile2.open("vector.txt");
    if (!inFile2.is_open()) {
        cout << "Unable to open vector file\n";
        return 2;
    }

    vector<vector<int>> v1, v2, sumV1, multV1;
    fillMatrix(inFile2, v1, size);
    fillMatrix(inFile2, v2, size);

    printMatrix(v1, size);
    cout << "The minimum value is : " << minMatrix(v1, size) << endl;

    addMatrix(v1, v2, sumV1, size);
    printMatrix(sumV1, size);

    cout << endl << endl;
    multMatrix(v1, v2, multV1, size);
    printMatrix(multV1, size);

    inFile2.close();
}
*/