#include <iostream>
#include <vector> 
using namespace std;

// Function to check if two vectors are parallel
bool areParallel(const vector<double>& u, const vector<double>& v) {
    double ratio = 0.0;
    bool firstNonZeroFound = false;
    for (size_t i = 0; i < u.size(); ++i) {
        if (v[i] != 0) {
            if (!firstNonZeroFound) {
                ratio = u[i] / v[i];
                firstNonZeroFound = true;
            } else if (u[i] / v[i] != ratio) {
                return false;
            }
        } else if (u[i] != 0) {
            return false;
        }
    }
    return true;
}

// Function to check if two vectors are identical
bool areIdentical(const vector<double>& u, const vector<double>& v) {
    for (size_t i = 0; i < u.size(); ++i) {
        if (u[i] != v[i]) {
            return false;
        }
    }
    return true;
}

// Function to check if two vectors are orthogonal
bool areOrthogonal(const vector<double>& u, const vector<double>& v) {
    double dotProduct = 0.0;
    for (size_t i = 0; i < u.size(); ++i) {
        dotProduct += u[i] * v[i];
    }
    return dotProduct == 0.0;
}

int main() {
    size_t n;
    cout << "Enter the dimension of the vectors: ";
    cin >> n;

    vector<double> u(n), v(n); //khai báo 2 loai vetor la u & v 
    cout << "Enter the components of vector u:\n";
    for (size_t i = 0; i < n; ++i) {
        cin >> u[i];
    }
    cout << "Enter the components of vector v:\n";
    for (size_t i = 0; i < n; ++i) { // 'size_t' dung de khai bao i trong vong lap for -> dam bao cac so lieu cua vetor khong bi sai
        cin >> v[i];
    }

    if (areIdentical(u, v)) {
        cout << "The vectors are identical.\n";
    } else if (areParallel(u, v)) {
        cout << "The vectors are parallel.\n";
    } else if (areOrthogonal(u, v)) {
        cout << "The vectors are orthogonal.\n";
    } else {
        cout << "The vectors are neither parallel, identical, nor orthogonal.\n";
    }

    return 0;
}

