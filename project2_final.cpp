#include <iostream>
#include <fstream>
#include <string>
#include<cmath>
using namespace std;

int n;


double normFind(double* x){
    double o_anki=0;
    for(int i=0; i<n; i++){
       if (x[i]>o_anki){
        o_anki=x[i];
       }
    }
    return o_anki;
}

int normFind_index(double* x, int n) {
    double maxVal = x[0];
    int maxIndex = 0;

    for (int i = 1; i < n; ++i) {
        if (x[i] > maxVal) {
            maxVal = x[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

double powerIteration(double** A, double* x, double* y, int lim, double lambdaThreshold, double* convergedEigenvector,double lambda) {
    lim = 1000; // You can adjust the iteration limit as needed
    double prevLambda = 0.0;
    lambda = 1.0;
    for (int k = 0; k < lim; k++) {
        double divider;
        divider = normFind(y);
        for (int i = 0; i < n; i++) {
            y[i] = 0; // Reset y vector before calculating the new values
            for (int j = 0; j < n; j++) {
                y[i] += x[j] * A[i][j];
            }
        }
        prevLambda = lambda;
        lambda = normFind(y) / divider;
        cout << lambda << "\n";

        // Normalize y vector
        for (int i = 0; i < n; i++) {
            y[i] /= divider;
        }
        //Update x vector with normalized y
        for (int i = 0; i < n; i++) {
            x[i] = y[i];
        }

        // Check for convergence
        if (abs(lambda - prevLambda) < lambdaThreshold) {
            cout << "Converged after " << k + 1 << " iterations.\n";
            for (int i = 0; i < n; i++) {
                convergedEigenvector[i] = y[i]/normFind(y);
                cout << convergedEigenvector[i]<<"\n";
            }
            return lambda ;
        }
    }

    //deflation part

}
void deflasyon(double*u1, double* convergedEigenvector, double** A){
    //cout<<normFind_index(convergedEigenvector,n)<<" zzzzzzzzzzz"<<endl;
    for (int i = 0; i < n; i++) {
        u1[i]=0;
        u1[i] += A[normFind_index(convergedEigenvector,n)][i];
    }
    //for (int i = 0; i < n; i++) {
      //  cout<<u1[i]<<" ";
    //}

    for (int i = 0; i < n; i++) {
        for (int j = 0 ; j<n ; j++){
            A[i][j]= A[i][j]-convergedEigenvector[i]*u1[j];
        }
    }
}
//cout << "Did not converge within " << lim << " iterations.\n";



int main (int argc, char *argv[])
{
    double lambda;
    double eig1;
    double eig2;
    double* convergedEigenvector = new double[n];
   //controlling the number of inputs

   if(argc!=4){
       cout << "Wrong number of inputs!";
       return 0;
    }

    ifstream myf (argv[1]);
    double tolerance = atof (argv[2]);
    ofstream cikti (argv[3]);
    string mystr;

    n = 0;

   //finding the dimension of the matrices

   if(myf.is_open()){
       while(getline(myf,mystr)){
           n++;
       }
    }
   
   //reset the open file

   myf.clear();
   myf.seekg(0);

   //dynamically creating 2-dimensional matrix and fill it with the values inside A.txt

   double** A;
   A = new double* [n];
   for (int i=0; i<n; i++){
       A[i] = new double[n];
       for (int j=0; j<n; j++){
           myf >> A[i][j];
        }
    }
    // Initialize x vector
    double* x = new double[n];
    x[0]=1;x[1]=1;x[2]=1; x[3]=1;
    // Initialize y vector
    double* y = new double[n];
    y[0]=11;y[1]=0;y[2]=0;y[3]=0;
    double* u1 = new double[n];
    // Call powerIteration function
    
    eig1 = powerIteration(A, x, y, 1000,tolerance, convergedEigenvector,lambda); 
    cout<< eig1<<"xxxxxxxxxxxxxxx1";
    cikti << eig1<<"\n";
    for (int i = 0;i<n;i++){
        cikti<<convergedEigenvector[i]<<"\n";
    }
    deflasyon(u1, convergedEigenvector, A);
    eig2= powerIteration(A, x, y, 1000,tolerance, convergedEigenvector,lambda);
    cikti<<eig2;
    cout<< eig2<<"nnnnnn2";
    cikti.close();

    return 0;
}