//created by gravitorious

#include <bits/stdc++.h>

using namespace std;


//return the size of digits from the number with the most digits
int returnMostDigits(deque<long long> &dx, deque<long long> &dy){
	if(dx.size() >= dy.size()) return dx.size();
	else return dy.size();
}



void convertIntToDeque(deque<long long> &dx, long long x){
	int digit;
	while(x > 0){
		digit = x % 10;
		x = x / 10;
		dx.push_front(digit);
	}
}

void printDeque(deque<long long> &dx){
	
	for(long long &x : dx){
		cout << x << "\n";
	}
	cout << "\n";
}

// we append zeros in the beggining of each number so the number of digits
// be equal and in the power of 2.
int appendZeros(deque<long long> &dx, deque<long long> &dy, int mostDigits){
	
	//solve the inequality: mostDigits <= 2^x
	int powerOfTwo = ceil(log2(mostDigits));
	int dxNeed = pow(2, powerOfTwo) - dx.size();
	int dyNeed = pow(2, powerOfTwo) - dy.size();
	for(int i = 0; i < dxNeed; i++){
		dx.push_front(0);
	}
	for(int i = 0; i < dyNeed; i++){
		dy.push_front(0);
	}
	return pow(2, powerOfTwo); //new size
}


deque<long long> firstHalf(deque<long long> &dx, int size){
	deque<long long> r;
	
	for(int i = 0; i < (size/2); i++){
		r.push_back(dx[i]);
	}
	return r;
}

deque<long long> secondHalf(deque<long long> &dx, int size){
	deque<long long> r;
	
	for(int i = (size/2); i < size; i++){
		r.push_back(dx[i]);
	}
	return r;
}


long long dequeToInt(deque<long long> dx, int size){
	long long x = 0;
	for(int i = 0; i < size; i++){
		x = x * 10 + dx[i];
	}
	return x;
	
}




deque<long long> addTwoNumbers(deque<long long> dx, deque<long long> dy, int size){
	//1) we will convert each deque to int
	//2) do the addition
	//3) convert the result back to deque
	long long dxInt = dequeToInt(dx, size);
	long long dyInt = dequeToInt(dy, size);
	long long result = dxInt + dyInt;
	deque<long long> addition_result;
	convertIntToDeque(addition_result, result);
	return addition_result;
	
}


long long karatsubaProduct(deque<long long> dx, deque<long long> dy, int size){
	if(size == 1){
		return (dx[0] * dy[0]);
	}
	
	deque<long long> first_dx = firstHalf(dx, size);
	deque<long long> second_dx = secondHalf(dx, size);
	deque<long long> first_dy = firstHalf(dy, size);
	deque<long long> second_dy = secondHalf(dy, size);
	deque<long long> p = addTwoNumbers(first_dx, second_dx, size/2);
	deque<long long> q = addTwoNumbers(first_dy, second_dy, size/2);
	//Now we maybe need to add zeros but there is a possibility that 
	//the addition added one more digit. If the addition adds one more digit
	//we may need to increase the size.
	int mostDigits2 = returnMostDigits(p, q);
	int mostDigits = appendZeros(p, q, mostDigits2);

	long long ac = karatsubaProduct(first_dx, first_dy, size/2);
	long long bd = karatsubaProduct(second_dx, second_dy, size/2);
	long long pq = karatsubaProduct(p, q, mostDigits);
	long long adbc = pq - ac - bd;
	//we are using the function pow now to append zeros to avoid convert again to deque
	//but we could do that.
	return pow(10, size) * ac + pow(10, size/2) * adbc + bd;
	
}



int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	
	long long x, y;
	cin >> x; //first number
	cin >> y; //second number
	deque<long long> dx;
	deque<long long> dy;
	convertIntToDeque(dx, x);
	convertIntToDeque(dy, y);
	int mostDigits = returnMostDigits(dx, dy);
	mostDigits = appendZeros(dx, dy, mostDigits); //size is changing because we append zeros
	long long mult_result = karatsubaProduct(dx, dy, mostDigits);
	cout << "the result is: " << mult_result << "\n";
}
