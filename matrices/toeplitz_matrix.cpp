#include<iostream>

using namespace std;

class ToeplitzMatrix{
    private:
        int *A;
        int n;
    public:
        ToeplitzMatrix(){
            n = 3;
            A = new int[3+2];
        }
        
        ToeplitzMatrix(int n){
            this->n = n;
            A = new int[(n-1)+n];
        }

        ~ToeplitzMatrix(){
            cout << "Destructer called. Deallocated the array memory.\n";
            delete []A;
        }

        void set(int i, int j, int val);
        int get(int i, int j);
        void display_matrix();
};

void ToeplitzMatrix::set(int i, int j, int val){
    if(i<=j) // for the row, that means the element belongs to the upper triangular part (that includes main diagonal)
        A[j-i] = val;
    else if(i>j) // for the column, that means the element belongs to the lower triangular part (that does not include main diagonal)
        A[n+(i-j-1)] = val;
}

int ToeplitzMatrix::get(int i, int j){
    if(i<=j)
        return A[j-i];
    else if(i>j)
        return A[n+(i-j-1)];
    
    return -1;
}

void ToeplitzMatrix::display_matrix(){
    int i, j;

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i<=j)
                cout << A[j-i] << " ";
            else if(i>j)
                cout << A[n+(i-j-1)] << " ";
        }
        cout << endl;
    }
}

int main(){
    int i, j, n, val;
    n = 4;
    ToeplitzMatrix tm(n);

    cout << "Enter all elements: \n";
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin >> val;
            tm.set(i, j, val);
        }
    }
    cout << endl << endl;

    tm.display_matrix();

    cout << "Value at location [2, 4] in the toeplitz matrix: " << tm.get(2, 4) << endl;
    cout << "Value at location [3, 3] in the toeplitz matrix: " << tm.get(3, 3) << endl;
    cout << "Value at location [4, 1] in the toeplitz matrix: " << tm.get(4, 1) << endl;
    
    return 0;
}