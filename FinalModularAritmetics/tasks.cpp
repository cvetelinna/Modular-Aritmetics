#include <iostream>
#include "tasks.h"

int inputN(bool acceptZero) {
	int n;
	while (true) {
		std::cout << "n = ";
		std::cin >> n;
		if (n < 0) {
			if (acceptZero) {
				std::cerr << "inputN(): n must be >= 0\n";
			}
			else {
				std::cerr << "inputN(): n must be > 0\n";
			}
		}
		else if (n > 0) {
			return n;
		}
		else if (n == 0 && acceptZero) {
			return n;
		}
	}
	return n;
}

int inputN() {
	return inputN(false);
}

bool isPrime(int n) {
	if (n == 0) {
		return true;
	}

	for (int i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int* task_one() {
	int n = inputN();
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		std::cout << i << " ";
		arr[i] = i;
	}
	std::cout << "\n";
	return arr;
}

int task_two() {
	int n = inputN();
	int a, b;
	while (1) {
		std::cout << "number 1 = ";
		std::cin >> a;
		if (a >= 0 && a < n)
			break;
		std::cout << "not from Z";

	}
	while (1) {
		std::cout << "number 2 = ";
		std::cin >> b;
		if (b >= 0 && b < n)
			break;
		std::cout << "not from Z";
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << i << " + " << j << " = " << (i + j) % n << "\n";
		}
	}

	std::cout << "\n******************\n" << a << " + " << b << " = "
		<< (a + b) % n << "\n******************\n";
	return 0;
}

int task_three() {
	int n = inputN();
	int a, b;
	int ans;
	while (1) {
		std::cout << "number 1 = ";
		std::cin >> a;
		if (a >= 0 && a < n)
			break;
		std::cout << "not from Z";

	}
	while (1) {
		std::cout << "number 2 = ";
		std::cin >> b;
		if (b >= 0 && b < n)
			break;
		std::cout << "not from Z";
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = i - j;
			if (ans < 0) {
				ans += n;
			}
			else
				ans %= n;
			std::cout << i << " - " << j << " = " << ans << "\n";
		}
	}
	ans = a - b;
	if (ans < 0) {
		ans += n;
	}
	else
		ans %= n;

	std::cout << "\n******************\n" << a << " - " << b << " = " << ans
		<< "\n******************\n";

	return 0;
}

int task_four() {
	int n = inputN();
	int a, b;

	while (1) {
		std::cout << "number 1 = ";
		std::cin >> a;
		if (a >= 0 && a < n)
			break;
		std::cout << "not from Z";

	}
	while (1) {
		std::cout << "number 2 = ";
		std::cin >> b;
		if (b >= 0 && b < n)
			break;
		std::cout << "not from Z";
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << i << " * " << j << " = " << (i * j) % n << "\n";

		}
	}

	std::cout << "\n******************\n" << a << " * " << b << " = "
		<< (a * b) % n << "\n******************\n";
	return 0;
}



int** task_five(int a) {
	int n = inputN();
	int r = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i * j) % n == 1)
				r++;
		}
	}
	int** Matrix = new int* [2];
	Matrix[0] = new int[r + 1];
	Matrix[1] = new int[r + 1];
	//this is information for function 6 to know the lenght of the columns
	Matrix[0][0] = r;
	r = 0;
	

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if ((i * j) % n == 1) {
				Matrix[0][r + 1] = i;
				Matrix[1][r + 1] = j;
				r++;
			}
		}
	}
	std::cout << "\n";
	if (a) {
		for (int i = 0; i < 2; ++i) {
			for (int j = 1; j < r + 1; j++) {
				std::cout << Matrix[i][j] << "  ";
			}
			std::cout << "\n";
		}
	}
	std::cout << "\n";
	return Matrix;
}

int task_six() {
	int** Matrix = task_five(0);
	int r = Matrix[0][0] + 1;
	for (int i = 1; i < r; ++i)
		std::cout << Matrix[0][i] << " = " << Matrix[1][i] << "\n";

	return 0;
	

}

int task_seven() {




	int n = inputN();
	int element;
	int flag = 0;
	while (1) {
		std::cout << "element = ";
		std::cin >> element;
		if (element > 0 && element < n)
			break;
		else
			std::cout << "Wrong answer\n";
	}

	for (int i = 0; i < n; i++) {
		if ((i * element) % n == 1) {
			flag = 1;
			std::cout << "1/" << element << " = " << i << "\n";
			break;
		}
	}
	if (flag == 0)
		std::cout << "1/" << element << " does not exist\n";
	std::cout << "\n";
	return 0;
	
}

int task_eight() {

	int n = inputN();
	int* array = new int[n];
	memset(array, -1, n);
	//запълва масива със стойности, в случая -1;

	for (int i = 1; i < n; i++) {
		for (int k = 1; k < n; k++) {
			if ((i * k) % n == 1)
				array[i] = k;
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < n; ++k) {
			std::cout << i << " / " << k << " = "
				<< ((array[k] == -1) ? -1 : ((i * array[k]) % n)) << "\n";
		}
	}
	std::cout << "\n";
	return 0;
}

int dumpMatrix(int** matrix, int rows, int cols) {
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; j++) {
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << "\n";
	}
	//принтира двумерен масив
	return 0;
}

int* idArr(int** M, int rows, int cols) {
	//  получава като параметър матрица , 
	//и колко е голяма и връща масив от уникалните и стойности , т.е. да не се повтарят.
	bool isId = 0;
	int* id = new int[rows];
	for (int r = 0; r < rows; ++r) {
		id[r] = 1;
	}
	for (int r = 0; r < rows; ++r) {
		for (int c = 0; c < cols; ++c) {
			for (int k = 0; k < c; k++) {
				if (M[r][c] == M[r][k]) {
					id[r] = 0;
					isId = 1;
					break;
				}
			}
			if (isId) {
				isId = 0;
				break;
			}
		}
	}
	return id;
}

int* root(int n, bool dump, int* characteristics) {
	//примитивен корен е когато на реда няма повтаряемост
	int kk;
	if (n == 1 || !isPrime(n)) {
		std::cout << "not a field \n";
		return NULL;
	}

	int* roots = new int[n - 1];
	int** matrix = new int* [n - 1];
	for (int i = 0; i < n - 1; ++i)
		matrix[i] = new int[n - 1];

	for (int i = 1; i < n; ++i) {
		kk = i;
		for (int j = 0; j < n - 1; ++j) {
			matrix[i - 1][j] = kk % n;
			kk *= i;
		}
	}
	if (dump) {
		dumpMatrix(matrix, n - 1, n - 1);
	}

	roots = idArr(matrix, n - 1, n - 1);

	if (characteristics) {
		if (roots[characteristics[1] - 1] == 1) {
			if (characteristics[2] != 0) {
				characteristics[0] =
					matrix[characteristics[1] - 1][characteristics[2] - 1];
			}
			else {
				characteristics[0] = -1;
			}

		}
	}
	//това парче код отговаря за стойностите демек от реда който сме модулно разделено на n;
	//след това се умножава тази променлива пак по реда
	//	3 - тия параметър в тази функция го използваме само за функция 14:
	//така разграничавам отстанилите функции от 14 задача :
	//	ако е NULL значи не съм на 14.
	//	използвам масива като трети аргумент на тази функция за да го променям.
	//	резултата се получава след като съм проверил че със сигурност characteristics 
	//е примитивен корен, ако не е означава че не е възможно да се получи дискретен логаритъм.
	//	след това на charactersitics[0] му връщам стойността която е
	//конкретната за дискретния логаритъм от матрицата.




	// delete matrix
	for (int i = 0; i < n - 1; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
	return roots;
}

int task_nine() {
	int n = inputN();
	int a, m, k = 1;
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "\n" << "m = ";
	std::cin >> m;

	int firstA = a;
	while (firstA % n != 1) {
		k++;
		firstA *= a;
	}

	int mod = m % k;
	firstA = a;

	for (int i = 0; i < mod - 1; i++) {
		firstA *= a;
	}
	std::cout << a << " ^ " << m << " = " << firstA % n << "\n\n";
	return 0;
}

int task_ten() {
	return task_nine();

}

int task_eleven() {
	std::cout << "n " << ((isPrime(inputN())) ? "IS" : "IS NOT")
		<< " a field\n";
	return 0;
}

int task_twelve() {
	int n, x;
	while (1) {
		n = inputN(true);
		if (isPrime(n)) {
			break;
		}
		else {
			std::cerr << "task_twelve(): n is >=0, but not prime!\n";
		}
	}
	while (true) {
		std::cout << "x = ";
		std::cin >> x;
		if (x > 0 && x < n) {
			break;
		}
		else {
			std::cout << "not from Z";
		}
	}
	int* roots = root(n, 1, NULL);
	std::cout << "\n " << ((roots[x - 1]) ? "IS" : "IS NOT") << "primitive root"
		<< "\n\n";
	return 0;
}

int task_fourteen() {
	int n = inputN();
	int a, k, element;
	std::cout << "a = ";
	std::cin >> a;
	std::cout << "element = ";
	std::cin >> element;
	if (a > 0 && a < n && element >= 0 && element < n) {
		int* characteristics = new int[3];
		characteristics[0] = 1;
		characteristics[1] = a;
		characteristics[2] = element;
		root(n, 0, characteristics);
		if (characteristics[0] == -1) {
			std::cout << "(-1) Not possible\n";
			return -1;

		}
		std::cout << "dlog = " << characteristics[0] << "\n";
		return characteristics[0];


		//тук търсим дисктретен логаритъм
		//трябва да въведем пръстен, основа и елемент
		//а е основата
		//element е елемента.
		//този път обаче построяваме един масив, 
		//и слагаме стойностите в него, те са 3,
		//нулевата - в нея ще имаме резултата от изпълнението, 
		//който иначе няма как да предадем, които през root функцията може да променим, 
		//тези условия са специфични за тази задача.
		//резултатът който искаме да получим се намира в този въпосен масив на нулевата позиция, 
		//който масив е модифициран от функцията root.

	}

}
