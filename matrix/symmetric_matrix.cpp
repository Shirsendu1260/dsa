#include<iostream>

using namespace std;

// Considering the lower triangular part of the symmetric matrix for storing the required elements in the one-dimension array.
// Thus process is almost similar to the lower triangular matrix.
class SymmetricMatrix{
    private:
        int *A;
        int n;
    public:
        SymmetricMatrix(){
            n = 2;
            A = new int[2*(2+1)/2];
        }
        
        SymmetricMatrix(int n){
            this->n = n;
            A = new int[n*(n+1)/2];
        }

        ~SymmetricMatrix(){
            delete []A;
        }

        void set(int i, int j, int val);
        int get(int i, int j);
        void display_matrix();
};

void SymmetricMatrix::set(int i, int j, int val){
    if(i >= j)
        A[(i*(i-1)/2)+(j-1)] = val; // using row-major mapping
}

int SymmetricMatrix::get(int i, int j){
    if(i >= j)
        return A[(i*(i-1)/2)+(j-1)]; // using row-major mapping
    else
        return 0;
}

void SymmetricMatrix::display_matrix(){
    int i, j;

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i >= j)
                cout << A[(i*(i-1)/2)+(j-1)] << " "; // using row-major mapping
            else
                cout << A[(j*(j-1)/2)+(i-1)] << " ";
        }
        cout << endl;
    }
}

int main(){
    int i, j, n, val;
    n = 4;
    SymmetricMatrix sm(n);

    cout << "Enter all elements: \n";
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin >> val;
            sm.set(i, j, val);
        }
    }
    cout << endl << endl;

    sm.display_matrix();

    cout << "Value at location [2, 4] in the symmetric matrix: " << sm.get(2, 4) << endl;
    cout << "Value at location [3, 3] in the symmetric matrix: " << sm.get(3, 3) << endl;
    cout << "Value at location [4, 1] in the symmetric matrix: " << sm.get(4, 1) << endl;
    
    return 0;
}