# Computing-Eigenvalues-and-Eigenvectors-by-Normalized-Power-Iteration-Method-with-Deflation

his project provides an implementation of the deflation method and power iteration algorithm for finding eigenvalues and eigenvectors of a square matrix.

The deflation method is used to find subsequent eigenvalues and eigenvectors of a matrix after the first one has been found using power iteration. It involves modifying the original matrix by subtracting the outer product of the converged eigenvector with itself, effectively "deflating" the matrix and removing the influence of the already-found eigenvector.

The power iteration algorithm is an iterative method used to find the dominant eigenvalue and its corresponding eigenvector of a square matrix. It repeatedly multiplies a starting vector by the matrix and normalizes the result until convergence, where the eigenvalue and eigenvector are then obtained.

Compiling method

1.Run the executable with the following command-line arguments:

'./executable_name_without_extension input_file tolerance output_file'


example in my case:

'./project2_final A.txt 1e-6 x.txt'


Requirements

This project requires a C++ compiler and no external libraries are needed.
