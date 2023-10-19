#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <array>
int matrix_size;

using namespace std;

array<array<int, 100>, 201> read_file(string file_name);
array<array<int, 100>, 100> build_matrix(int start_line, array<array<int, 100>, 201> file_matrix);
void print_matrix(array<array<int, 100>, 100> matrix);
array<array<int, 100>, 100> add_matrix(array<array<int, 100>, 100> matrix_A, array<array<int, 100>, 100> matrix_B);
array<array<int, 100>, 100> mult_matrix(array<array<int, 100>, 100> matrix_A, array<array<int, 100>, 100> matrix_B);
array<array<int, 100>, 100> sub_matrix(array<array<int, 100>, 100> matrix_A, array<array<int, 100>, 100> matrix_B);
int num_length(int num);

int main() {
	string file_name = "matrix_input.txt";
	array<array<int, 100>, 201> file_matrix = read_file(file_name);
	
	array<array<int, 100>, 100> matrix_A = build_matrix(0, file_matrix);
	array<array<int, 100>, 100> matrix_B = build_matrix(matrix_size, file_matrix);
	array<array<int, 100>, 100> matrix_sum = add_matrix(matrix_A, matrix_B);
	array<array<int, 100>, 100> matrix_prod = mult_matrix(matrix_A, matrix_B);
	array<array<int, 100>, 100> matrix_diff = sub_matrix(matrix_A, matrix_B);


	printf("Jacob Kice\n");
	printf("Lab #6: Matrix Manipulation\n");
	printf("\nMatrix A:\n");
	print_matrix(matrix_A);
	printf("\nMatrix B:\n");
	print_matrix(matrix_B);
	printf("\nMatrix Sum (A + B):\n");
	print_matrix(matrix_sum);
	printf("\nMatrix Product (A * B):\n");
	print_matrix(matrix_prod);
	printf("\nMatrix Difference (A - B):\n");
	print_matrix(matrix_diff);

	return 0;
}

array<array<int, 100>, 201> read_file(string file_name) {
	ifstream myfile(file_name);
	array<array<int, 100>, 201> my_matrix;
	if (myfile.is_open()) {
		myfile >> matrix_size;
		for (int i = 0; i <= (matrix_size * 2 - 1); i++) {
			for (int j = 0; j <= (matrix_size - 1); j++) {
				myfile >> my_matrix[i][j];
			}
		}

	}
	return my_matrix;
}

array<array<int, 100>, 100> build_matrix(int start_line, array<array<int, 100>, 201> file_matrix) {
	array<array<int, 100>, 100> built_matrix;
	for (int i = 0; i <= (matrix_size - 1); i++) {
		for (int j = 0; j <= (matrix_size - 1); j++) {
			built_matrix[i][j] = file_matrix[start_line + i][j];
		}
	}
	return built_matrix;
}

void print_matrix(array<array<int, 100>, 100> matrix) {
	int most_digits = num_length(matrix[0][0]);					//Determines the number of digits, or 'characters', in each number
	for (int i = 0; i <= (matrix_size - 1); i++) {				//and saves the largest number of digits to use for column width formatting.
		for (int j = 0; j <= (matrix_size - 1); j++) {
			if (num_length(matrix[i][j]) > most_digits) {
				most_digits = num_length(matrix[i][j]);
			}
		}
	}
	for (int i = 0; i <= (matrix_size - 1); i++) {
		for (int j = 0; j <= (matrix_size - 1); j++) {
			//printf("%4d ", matrix[i][j]);		//Original printf, forces each column to a minimum width of 4
			printf("%*d ", most_digits, matrix[i][j]);	//Modified printf, adjusts column width based on greatest number of digits in the numbers, including '-'
		}
		printf("\n");
	}
}

array<array<int, 100>, 100> add_matrix(array<array<int, 100>, 100> matrix_A, array<array<int, 100>, 100> matrix_B) {
	array<array<int, 100>, 100> sum_matrix;
	for (int i = 0; i <= (matrix_size - 1); i++) {
		for (int j = 0; j <= (matrix_size - 1); j++) {
			sum_matrix[i][j] = matrix_A[i][j] + matrix_B[i][j];
		}
	}
	return sum_matrix;
}

array<array<int, 100>, 100> mult_matrix(array<array<int, 100>, 100> matrix_A, array<array<int, 100>, 100> matrix_B) {
	array<array<int, 100>, 100> prod_matrix;
	for (int i = 0; i <= (matrix_size - 1); i++) {
		for (int j = 0; j <= (matrix_size - 1); j++) {
			int sum = 0;
			for (int x = 0; x <= (matrix_size - 1); x++) {
				sum += matrix_A[i][x] * matrix_B[x][j];
			}
			prod_matrix[i][j] = sum;
		}
	}
	return prod_matrix;
}

array<array<int, 100>, 100> sub_matrix(array<array<int, 100>, 100> matrix_A, array<array<int, 100>, 100> matrix_B) {
	array<array<int, 100>, 100> diff_matrix;
	for (int i = 0; i <= (matrix_size - 1); i++) {
		for (int j = 0; j <= (matrix_size - 1); j++) {
			diff_matrix[i][j] = matrix_A[i][j] - matrix_B[i][j];
		}
	}
	return diff_matrix;
}

int num_length(int num) {
	int length = 0;

	if (num <= 0) {
		num *= -1;
		length = 1;
		while (num != 0) {
			length++;
			num /= 10;
		}
	}
	else {
		while (num != 0) {
			length++;
			num /= 10;
		}	
	}
	
	return length;
}