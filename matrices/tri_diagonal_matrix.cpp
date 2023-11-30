#include<iostream>

using namespace std;

class TriDiagonalMatrix{
    private:
        int *A;
        int n;
    public:
        TriDiagonalMatrix(){
            n = 3;
            A = new int[2+3+2];
        }
        
        TriDiagonalMatrix(int n){
            this->n = n;
            A = new int[(n-1)+n+(n-1)];
        }

        ~TriDiagonalMatrix(){
            cout << "Destructer called. Deallocated the array memory.\n";
            delete []A;
        }

        void set(int i, int j, int val);
        int get(int i, int j);
        void display_matrix();
};

void TriDiagonalMatrix::set(int i, int j, int val){
    if((i-j) == 1) // for lower diagonal
        A[i-2] = val;
    else if((i-j) == 0) // for main diagonal
        A[(n-1)+(i-1)] = val;
    else if((i-j) == -1) // for upper diagonal
        A[(2*n-1)+(i-1)] = val;
}

int TriDiagonalMatrix::get(int i, int j){
    if((i-j) == 1) // for lower diagonal
        return A[i-2];
    else if((i-j) == 0) // for main diagonal
        return A[(n-1)+(i-1)];
    else if((i-j) == -1) // for upper diagonal
        return A[(2*n-1)+(i-1)];
    else
        return 0;
}

void TriDiagonalMatrix::display_matrix(){
    int i, j;

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if((i-j) == 1) // for lower diagonal
                cout << A[i-2] << " ";
            else if((i-j) == 0) // for main diagonal
                cout << A[(n-1)+(i-1)] << " ";
            else if((i-j) == -1) // for upper diagonal
                cout << A[(2*n-1)+(i-1)] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main(){
    int i, j, n, val;
    n = 4;
    TriDiagonalMatrix tdm(n);

    cout << "Enter all elements: \n";
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin >> val;
            tdm.set(i, j, val);
        }
    }
    cout << endl << endl;

    tdm.display_matrix();

    cout << "Value at location [2, 4] in the tri-diagonal matrix: " << tdm.get(2, 4) << endl;
    cout << "Value at location [3, 3] in the tri-diagonal matrix: " << tdm.get(3, 3) << endl;
    cout << "Value at location [4, 1] in the tri-diagonal matrix: " << tdm.get(4, 1) << endl;
    
    return 0;
}