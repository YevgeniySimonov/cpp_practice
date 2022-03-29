#include <iostream>
// #include </omp.h> // TODO

#define M 4
#define N 5
#define P 3
#define THREAD_NUM 4

// compillation
// clang++ -dynamiclib $LDFLAGS -fopenmp main.cpp -lomp -std=c++11

// using namespace std;
using std::cout, std::endl;

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

void matrix_multiplication(void) {

    // matrix dimensions
    const int X = 5;
    const int Y = 7;
    const int Z = 8;

    // matrix declaration
    int** A = new int*[X]; // size X x Y
    int** B = new int*[Y]; // size Y x Z
    int** C = new int*[X]; // size X x Z

    // iteration indices
    unsigned int i, j, k;

    int result_slot;

    // allocate memory
    for (i = 0; i < X; i++) {
        A[i] = new int[Y];

        // result array
        C[i] = new int[Z];
    }

    for (j = 0; j < Y; j++) {
        B[j] = new int[Z];
    }

    // assign random values
    srand(10);
    for (i = 0; i < X; i++) {
        for (j = 0; j < Y; j++) {
            A[i][j] = rand() % 7;
        }
    }
    for (i = 0; i < Y; i++) {
        for (j = 0; j < Z; j++) {
            B[i][j] = rand() % 7;
        }
    }

    // perform matrix multiplication
    for (i = 0; i < X; i++) {
        for (j = 0; j < Z; j++) {
            result_slot = 0;
            for (k = 0; k < Y; k++) {
                result_slot += A[i][k] * B[k][j];
            }
            C[i][j] = result_slot;
        }
    }

    // print result
    cout << "Result of multiplying A[X by Y] and B[Y by Z]: " << endl;
    for (i = 0; i < X; i++) {
        for (j = 0; j < Z; j++) {
            cout << C[i][j] << " "; 
        }
        cout << "\n";
    }

    // deallocate memory
    for (i = 0; i < X; i++) {
        delete[] A[i];
        delete[] C[i];
    } 
    delete[] A;
    delete[] C;

    for (j = 0; j < Y; j++) {
        delete[] B[j];
    }
    delete[] B;

}

int main(void) {

    create_single_pointer_2d_array();
    create_array_of_pointers_2d_array();
    create_array_of_pointers_3d_array();
    matrix_multiplication();

    return EXIT_SUCCESS;
}