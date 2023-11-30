#include<iostream>

using namespace std;

class UpperTriangularMatrix{
    private:
        int *A;
        int n;
    public:
        UpperTriangularMatrix(){
            n = 2;
            A = new int[2*(2+1)/2];
        }
        
        UpperTriangularMatrix(int n){
            this->n = n;
            A = new int[n*(n+1)/2];
        }

        ~UpperTriangularMatrix(){
            delete []A;
        }

        void set(int i, int j, int val);
        int get(int i, int j);
        void display_matrix();
};

void UpperTriangularMatrix::set(int i, int j, int val){
    if(i <= j)
        A[(j*(j-1)/2)+(i-1)] = val; // using column-major mapping
}

int UpperTriangularMatrix::get(int i, int j){
    if(i <= j)
        return A[(j*(j-1)/2)+(i-1)]; // using column-major mapping
    else
        return 0;
}

void UpperTriangularMatrix::display_matrix(){
    int i, j;

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i <= j)
                cout << A[(j*(j-1)/2)+(i-1)] << " "; // using column-major mapping
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main(){
    int i, j, n, val;
    n = 4;
    UpperTriangularMatrix utm(n);

    cout << "Enter all elements: \n";
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin >> val;
            utm.set(i, j, val);
        }
    }
    cout << endl << endl;

    utm.display_matrix();

    cout << "Value at location [4, 2] in the upper triangular matrix: " << utm.get(4, 2) << endl;
    cout << "Value at location [3, 3] in the upper triangular matrix: " << utm.get(3, 3) << endl;
    cout << "Value at location [2, 3] in the upper triangular matrix: " << utm.get(2, 3) << endl;
    
    return 0;
}