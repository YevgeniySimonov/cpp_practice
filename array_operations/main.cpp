#include <iostream>

#define M 4
#define N 5
#define P 3

// using namespace std;
using std::cout;

void create_single_pointer_2d_array(void) {

    // dynamically allocate memory of M x N matrix
    int* A = new int[M * N];
    unsigned int i, j;

    cout << "\nCreating single-pointer " << M << "x" << N << " array\n";

    // assign values to the allocated array
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            *(A + i*N + j) = rand() % 100;
        }
    }

    // print matrix
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            cout << *(A + i*N + j) << " "; // or (A + i*N)[j]
        }
        cout << "\n";
    }

    // deallocate memory
    delete[] A;

}

void create_array_of_pointers_2d_array(void) {

    // dynamically create array of pointers of size M
    int** A = new int*[M];
    unsigned int i, j;

    cout << "\nCreating double-pointer " << M << "x" << N << " array\n";

    // dynamically allocate memory of size N for each row
    for (i = 0; i < M; i++) {
        A[i] = new int[N];
    }

    // assign values to allocated memory
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            A[i][j] = rand() % 100;
        }
    }

    // print 2d array
    // print matrix
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            cout << A[i][j] << " "; 
        }
        cout << "\n";
    }

    // deallocate memory
    for (i = 0; i < M; i++) {
        delete[] A[i];
    }
    delete[] A;
}

void create_array_of_pointers_3d_array(void) {

    // dynamically create array of pointers of size M
    int*** A = new int**[M];
    unsigned int i, j, k;

    cout << "\nCreating double-pointer " << M << "x" << N << "x" << P << " array\n";

    // dynamically allocate memory of size N for each row
    for (i = 0; i < M; i++) {
        A[i] = new int*[N];
        for (j = 0; j < N; j++) {
            A[i][j] = new int[P]; 
        }
    }

    // assign values to allocated memory
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < P; k++) {
                A[i][j][k] = rand() % 100;
            }
        }
    }

    // print 3d array
    // print matrix
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < P; k++) {
                cout << A[i][j][k] << " "; 
            }
            cout << "\n";
        }
        cout << "\n";
    }

    // deallocate memory
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++) {
            delete[] A[i][j];
        }
        delete[] A[i];
    }
    delete[] A;
}

int main() {

    create_single_pointer_2d_array();
    create_array_of_pointers_2d_array();
    create_array_of_pointers_3d_array();

    return EXIT_SUCCESS;
}