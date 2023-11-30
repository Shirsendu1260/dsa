#include<iostream>

using namespace std;

class DiagonalMatrix{
    private:
        int *A;
        int n;
    public:
        DiagonalMatrix(){
            n = 2;
            A = new int[2];
        }
        
        DiagonalMatrix(int n){
            this->n = n;
            A = new int[n];
        }

        ~DiagonalMatrix(){
            delete []A;
        }

        void set(int i, int j, int val);
        int get(int i, int j);
        void display_matrix();
};

void DiagonalMatrix::set(int i, int j, int val){
    if(i == j)
        A[i-1] = val;
}

int DiagonalMatrix::get(int i, int j){
    if(i == j)
        return A[i-1];
    else
        return 0;
}

void DiagonalMatrix::display_matrix(){
    int i, j;

    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            if(i == j)
                cout << A[i-1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main(){
    DiagonalMatrix d(4);

    d.set(1, 1, 5);
    d.set(2, 2, 8);
    d.set(3, 3, 9);
    d.set(4, 4, 12);

    d.display_matrix();

    cout << "Value at location [2, 4] in the diagonal matrix: " << d.get(2, 4) << endl;
    cout << "Value at location [3, 3] in the diagonal matrix: " << d.get(3, 3) << endl;
    
    return 0;
}