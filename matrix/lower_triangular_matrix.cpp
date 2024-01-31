#include<iostream>

using namespace std;

class LowerTriangularMatrix{
    private:
        int *A;
        int n;
    public:
        LowerTriangularMatrix(){
            n = 2;
            A = new int[2*(2+1)/2];
        }
        
        LowerTriangularMatrix(int n){
            this->n = n;
            A = new int[n*(n+1)/2];
        }

        ~LowerTriangularMatrix(){
            delete []A;
        }

        void set(int i, int j, int val);
        int get(int i, int j);
        void display_matrix();
};

void LowerTriangularMatrix::set(int i, int j, int val){
    if(i >= j)
        A[(i*(i-1)/2)+(j-1)] = val; // using row-major mapping
}

int LowerTriangularMatrix::get(int i, int j){
    if(i >= j)
        return A[(i*(i-1)/2)+(j-1)]; // using row-major mapping
    else
        return 0;
}

void LowerTriangularMatrix::display_matrix(){
    int i, j;

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i >= j)
                cout << A[(i*(i-1)/2)+(j-1)] << " "; // using row-major mapping
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main(){
    int i, j, n, val;
    n = 4;
    LowerTriangularMatrix ltm(n);

    cout << "Enter all elements: \n";
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin >> val;
            ltm.set(i, j, val);
        }
    }
    cout << endl << endl;

    ltm.display_matrix();

    cout << "Value at location [2, 4] in the lower triangular matrix: " << ltm.get(2, 4) << endl;
    cout << "Value at location [3, 3] in the lower triangular matrix: " << ltm.get(3, 3) << endl;
    cout << "Value at location [4, 1] in the lower triangular matrix: " << ltm.get(4, 1) << endl;
    
    return 0;
}