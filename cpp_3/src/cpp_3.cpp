//============================================================================
// Name        : cpp_3.cpp
// Author      : Siddhartha Baidya
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <locale>
#include <vector>
#include <string>
#include <random>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int number_of_questions = 0;
int number_of_correct = 0;

const string yes("y");
const string no("n");
const string yesOrNo(" [y/n]");
const string quit("quit");

bool checkAnswer(string answer) {
	string choice;
	cin >> choice;
	number_of_questions++;
	if(choice == quit)
	{
		exit(0);
	}
	if(choice == answer)
	{
		number_of_correct++;
		cout << "Good!! [" << number_of_correct<<"/"<< number_of_questions<<"]"<< endl;
		return true;
	}
	cout << "Wrong!! [" << number_of_correct<<"/"<< number_of_questions<<"]"<< endl;
	return false;
}
bool checkAnswer(initializer_list<string> answers) {
	string choice;
	cin >> choice;
	number_of_questions++;
	if(choice == quit)
	{
		exit(0);
	}
	for (string answer : answers)
	{
		if(choice == answer)
		{
			number_of_correct++;
			cout << "Good!! [" << number_of_correct<<"/"<< number_of_questions<<"]"<< endl;
			return true;
		}
	}
	cout << "Wrong!! [" << number_of_correct<<"/"<< number_of_questions<<"]"<< endl;
	return false;
}
bool checkAnswers(string prefix, initializer_list<string> answers) {
	string choice;
	int i = 0;
	bool allCorrect = true;
	for (string answer : answers)
	{
		cout << prefix << " " << ++i << ": ";
		cin >> choice;
		number_of_questions++;
		if(choice == quit)
		{
			exit(0);
		}
		if(choice == answer)
		{
			number_of_correct++;
			cout << "Good!! [" << number_of_correct<<"/"<< number_of_questions<<"]"<< endl;
			allCorrect = allCorrect && true;
		}
		else
		{
			cout << "Wrong!! [" << number_of_correct<<"/"<< number_of_questions<<"]"<< endl;
			allCorrect = allCorrect && false;
		}
	}
	return allCorrect;
}
void generate_question_sequence(std::unordered_set<int> &question_num_set, const int min_question_num, const int max_question_num)
{
	std::pair<std::unordered_set<int>::iterator,bool> ret;
	// Seed with a real random value, if available
	std::random_device r;
	// Choose a random number between min_question_num and max_question_num
	std::default_random_engine e1(r());
	std::uniform_int_distribution<int> uniform_dist(min_question_num, max_question_num);
	for (int i = min_question_num; i <= max_question_num; i++)
	{
		int random_num = uniform_dist(e1);
		question_num_set.insert(random_num);
	}
	cout << "size:" << question_num_set.size() <<" > ";
	for (int question_num : question_num_set)
		cout << question_num << ", ";
	cout << endl;
	//Filling remaining
	int min = min_question_num;
	int max = max_question_num;
	//This strange algo preserves better randomness
	while (min < max)
	{
		for (int i = min; i <= max; i++)
		{
			ret = question_num_set.insert(i);
			min = i+1;
			if(ret.second==true)
				break;
		}
		for (int i = max; i >= min; i--)
		{
			ret = question_num_set.insert(i);
			max = i-1;
			if(ret.second==true)
				break;
		}
	}

	cout << "size:" << question_num_set.size() <<" > ";
	for (int question_num : question_num_set)
		cout << question_num << ", ";
	cout << endl;
}

void register_question(std::unordered_map<int, void (*) ()> &registered_questions, int key, void (*fn_ptr) ( ))
{
	std::pair<int, void (*) ()> key_value_pair (key, fn_ptr);
	if((registered_questions.insert(key_value_pair)).second == false)
	{
		cout << "Unable to register function number " << key << endl;
		exit(1);
	}
}
// Forward declarations
void question_01();
void question_02();
void question_03();
void question_04();
void question_05();
void question_06();
void question_07();
void question_08();
void question_09();
void question_10();
void question_11();
void question_12();
void question_13();
void question_14();
void question_15();
void question_16();
void question_17();
void question_18();
void question_19s_answer();
void question_19();
void question_20s_answer();
void question_20();
void question_21s_answer();
void question_21();
void question_22();
void question_23();
void question_24();
void question_25();
void question_26();
void question_27();
void question_28();
void question_29();
void question_30();
void question_31();
void question_32();
void question_33();

int main() {
//	{
//		std::wcout << "User-preferred locale setting is [" << std::locale("ISO-8859-1").name().c_str() << "]" << endl;
//		std::locale loc = std::locale(); // user's preferred locale
//		std::cout << "Your currency string is ["
//		              << std::use_facet<std::moneypunct<char, true>>(loc).curr_symbol() << "]" <<endl;
//	}
	{
		const long precision = 10000000000;
		float val = 0.0, old_val = 0.0, fraction = 0.0;
		int i = 0;
		// Seed with a real random value, if available
		std::random_device r;
		// Choose a random number between min_question_num and max_question_num
		std::default_random_engine e1(r());
		std::uniform_int_distribution<int> uniform_dist(500, 1000);
		cout.precision(20);
		cout << "val = " << val << endl;
		do {
			++i;
			cout << "At iteration: " << i;
			int random_num = uniform_dist(e1);
			//cout << "Random number = " << random_num << endl;
			fraction = 1.0/random_num;
			cout << "\tFraction = " << fraction;
			old_val = val;
			val += fraction;
			//cout << "\tval + fraction = " << val << endl;
			cout << "\tDiff = " << (int)((val - old_val)*(precision)) << " | " << (int)(fraction*precision) << endl;
		} while ((int)((val - old_val)*(precision)) == (int)(fraction*precision));
		cout << endl << "*At iteration: " << i << endl;
		cout << "*Val = " << old_val << endl;
		cout << "*fraction = " << fraction << endl;
		cout << "*Val + fraction = " << val << endl;
		cout << "*Difference = " << val - old_val << endl;
	}


	//return 0;

	std::unordered_set<int> question_secquence;
	std::unordered_map<int, void (*) ()> registered_questions;

	register_question(registered_questions, 33, question_33);
	register_question(registered_questions, 32, question_32);
	register_question(registered_questions, 31, question_31);
	register_question(registered_questions, 30, question_30);
	register_question(registered_questions, 29, question_29);
	register_question(registered_questions, 28, question_28); // TODO
	register_question(registered_questions, 27, question_27); // TODO
	register_question(registered_questions, 26, question_26);
	register_question(registered_questions, 25, question_25);
	register_question(registered_questions, 24, question_24);
	register_question(registered_questions, 23, question_23);
	register_question(registered_questions, 22, question_22);
	register_question(registered_questions, 21, question_21);
	register_question(registered_questions, 20, question_20);
	register_question(registered_questions, 19, question_19);
	register_question(registered_questions, 18, question_18);
	register_question(registered_questions, 17, question_17);
	register_question(registered_questions, 16, question_16);
	register_question(registered_questions, 15, question_15);
	register_question(registered_questions, 14, question_14);
	register_question(registered_questions, 13, question_13);
	register_question(registered_questions, 12, question_12);
	register_question(registered_questions, 11, question_11);
	register_question(registered_questions, 10, question_10);
	register_question(registered_questions, 9, question_09);
	register_question(registered_questions, 8, question_08);
	register_question(registered_questions, 7, question_07);
	register_question(registered_questions, 6, question_06);
	register_question(registered_questions, 5, question_05);
	register_question(registered_questions, 4, question_04);
	register_question(registered_questions, 3, question_03);
	register_question(registered_questions, 2, question_02);
	register_question(registered_questions, 1, question_01);

	generate_question_sequence(question_secquence, 1, registered_questions.size());

	for( int question_num : question_secquence)
	{
		registered_questions[question_num]();
	}


	return 0;
}

void question_33()
{
	cout << "what is the output?\n";
	cout << "\tchar a; short s; int i; float f; double d; long l;\n";
	cout << "\tcout << sizeof(a) << sizeof(s) << sizeof(i);\n";
	cout <<	"\tcout << sizeof(f) << sizeof(d) << sizeof(l) << endl;\n";
	checkAnswer("124488");
	char a; short s; int i; float f; double d; long l;
	cout << "Size of char = " << sizeof(a) << endl;
	cout << "Size of short = " << sizeof(s) << endl;
	cout << "Size of int = " << sizeof(i) << endl;
	cout << "Size of float = " << sizeof(f) << endl;
	cout << "Size of double = " << sizeof(d) << endl;
	cout << "Size of long = " << sizeof(l) << endl;
	cout << endl;
}
void question_32()
{
	cout << "What function you can use to convert decimals to hexadecimal while printing?" << endl;
	checkAnswer("setbase(16)");
	cout << "Use setbase() from <iomanip>; see below example:" << endl;
	cout << "\tint i = 255;\n\tcout << \"Decimal(\" << i << \") = 0x\";\n\tcout << setbase(16);\n";
	cout << "\tcout << i << endl;\n\tcout << setbase(10);";
	cout << endl;
}
void question_31()
{
	cout << "To make below function call, what should be the signature of the function? [a/b]" << endl;
	cout << "find_char(\"Hello World\", 'o', ctr);" << endl;
	cout << "a.\tstring::size_type find_char(string &s, char c, string::size_type &occurs);" << endl;
	cout << "b.\tstring::size_type find_char(const string &s, char c, string::size_type &occurs);" << endl;
	checkAnswer("b");
}
void question_30()
{
	cout << "Will this code produce compile time error or run time error or no error? [c/r/n]" << endl;
	cout << "void print(int &i)\n{\n\tcout << i;\n}" << endl;
	cout << "int main() {\n\tconst int i = 10;\n\tprint(i);\n}" << endl;
	checkAnswer("c");
	cout << "This code will produce compile time error." << endl;
	cout << "error: no matching function for call to \'print\'" << endl;
	cout << "note: candidate function not viable: 1st argument ('const int') would lose const qualifier" << endl;
	cout << endl;
}
void question_29()
{
	// Sum of all n x n matrix of floating point variables
	// Keeping speed and accuracy in mind
}
void question_28()
{
	// What can make an object move around in memory without your knowledge
	// How can we stop an object being moved around in memory (overriding move())
}
void question_27()
{
	cout << "What is the time complexity of Bubble sort?" << endl;
	checkAnswer({"O(n^2)", "n^2", "o(n^2)"});
	cout << "Best and Average time complexities: O(n) & O(n^2)" << endl;
	cout << "Worst case time complexity : O(n^2)" << endl;
	cout << endl;
}
void question_26()
{
	cout << "What is the time complexity of Selection sort?" << endl;
	checkAnswer({"O(n^2)", "n^2", "o(n^2)"});
	cout << "Best and Average time complexities: O(n^2) & O(n^2)" << endl;
	cout << "Worst case time complexity : O(n^2)" << endl;
	cout << endl;
}
void question_25()
{
	cout << "What is the time complexity of Merge sort?" << endl;
	checkAnswer({"O(n.log(n))", "nlogn", "n.log(n)", "o(n.log(n))", "nlog(n)", "o(nlog(n))", "O(nlog(n))"});
	cout << "Best and Average time complexities: O(n.log(n)) & O(n.log(n))" << endl;
	cout << "Worst case time complexity : O(n.log(n))" << endl;
	cout << endl;
}
void question_24()
{
	// Find time complexity of these algorithms
	// Quick Sort
	// Merge Sort
	// Modified Quick Sort for finding nth largest attribute
	// Insertion Sort
	cout << "What is the time complexity of Quick sort?" << endl;
	checkAnswer({"O(n.log(n))", "nlogn", "n.log(n)", "o(n.log(n))", "nlog(n)", "o(nlog(n))", "O(nlog(n))"});
	cout << "Best and Average time complexities: O(n.log(n)) & O(n.log(n))" << endl;
	cout << "Worst case time complexity : O(n^2)" << endl;
	cout << endl;
}
void question_23()
{
	cout << "What will be the output of below code?" << endl;
	cout << "class A {\npublic:\n\tA() { cout << \"A\"; }\n\t~A() { cout << \"a\"; }\n};" << endl;
	cout << "class B {\npublic:\n\tB() { cout << \"B\"; }\n\t~B() { cout << \"b\"; }\n\tA a;\n};" << endl;
	cout << "\nint main() {\n\tB b;\n\treturn 0;\n}" << endl;
	cout << "Type output: ";
	checkAnswer("ABba");
	cout << "At destructon, 1st it will complete the execution block of derived class" << endl;
	cout << "then destroy all objects it created internally and" << endl;
	cout << "then try to destroy base class" << endl;
	cout << endl;
}
void question_22()
{
	cout << "What will be the output of below code?" << endl;
	cout << "class A {\npublic:\n\tA() { cout << \"A\"; }\n\t~A() { cout << \"a\"; }\n};" << endl;
	cout << "class B {\npublic:\n\tB() { cout << \"B\"; }\n\t~B() { cout << \"b\"; }\n};" << endl;
	cout << "class C {\npublic:\n\tC() { cout << \"C\"; }\n\t~C() { cout << \"c\"; }\n};\n" << endl;
	cout << "A a;\nint main() {\n\tB b;\n\tC c;\n\treturn 0;\n}" << endl;
	cout << "Type output: ";
	checkAnswer("ABCcba");
	cout << "At construction, the objects are placed in stack." << endl
			<< "So destruction is based on stack pop sequence" << endl;
	cout << endl;
}
void question_21()
{
	cout << "What will be the output of below code?" << endl;
	cout << "class AA {\npublic:\n\tAA() { cout<< \"AA|\"; }\n\tAA(const AA& a) {\n\t\tcout << \"AAcc|\"; //AA's copy constructor\n\t}" << endl;
	cout << "\tvirtual void run() const { cout << \"iAmA\" << endl; }\n};" << endl;
	cout << "class BB: public AA {\npublic:\n\tBB():AA() {cout<< \"BB|\"; }\n\tBB(const BB& a):AA(a) {" << endl;
	cout << "\t\tcout << \"BBcc|\"; //'BB' copy constructor\n\t}" << endl;
	cout << "\tvirtual void run() const { cout << \"iAmB\" << endl; }\n}" << endl;
	cout << endl << "void g(AA a) { a.run(); }\nvoid h(AA &a) { a.run(); }" << endl;
	cout << "int main() {\n\t{ BB b; g(b); }\n\t{ BB b; h(b); }\n\treturn 0;\n}" << endl;
	checkAnswers("Type output", {"AA|BB|AAcc|iAmA", "AA|BB|iAmB"});
	cout << "The correct answers are:" << endl;
	question_21s_answer();
	cout << endl;
}
void question_21s_answer() {
	class AA {
	public:
	    AA() { cout<< "AA|"; }
	    AA(const AA& a) {
	        cout << "AAcc|"; //'AA' copy constructor
	    }
	    virtual void run() const { cout << "iAmA" << endl; }
	};
	class BB: public AA {
	public:
	    BB():AA() {cout<< "BB|"; }
	    BB(const BB& a):AA(a) {
	        cout << "BBcc|"; //'BB' copy constructor
	    }
	    virtual void run() const { cout << "iAmB" << endl; }
	};
	//void g(const AA a) { a.run(); }
	//void h(const AA & a) { a.run(); }
	{ // simulating call to g()
			const AA a = BB();
			a.run(); // AA|BB|AAcc|iAmA
		}
	{ // simulating call to h()
		const AA &a = BB();
		a.run(); // AA|BB|iAmB
	}

	cout << endl;
}
void question_20() {
	cout << "What will be the output of below code?" << endl;
	cout << "class Base {\npublic:\n\tvoid f(int) { cout << \"i\"; }\n};" << endl;
	cout << "class Derived: public Base {\npublic:\n\tvoid f(double) { cout << \"d\"; }\n};" << endl;
	cout << "int main() {\n\tDerived d;\n\tint i = 0;\n\td.f(i);\n\td.Base::f(i);\n\treturn 0;\n}" << endl;
	checkAnswer("di");
	cout << "Correct answer is: "; question_20s_answer();
	cout << "As method f() is not virtual, method f() of Derived overrides the method from Base. Call to f()" << endl;
	cout << "using derive will always invoke Derived class's method f(). To call Base class's method f() we" << endl;
	cout << "need to use d.Base::f(i) i.e. we need to tell compiler explicitly." << endl;
	cout << endl;
}
void question_20s_answer() {
	class Base {
	public:
		void f(int) { cout << "i"; }
	};
	class Derived: public Base {
	public:
		void f(double) { cout << "d"; }
	};
	Derived d;
	int i = 0;
	d.f(i);
	d.Base::f(i);
	cout << endl;
}
void question_19() {
	cout << "What is the output of below code?" << endl;
	cout << "class A {\npublic:\n\tvirtual void f() { cout << \"A\"; }\n};" << endl;
	cout << "class B: public A {\npublic:\n\tvoid f() { cout << \"B\"; }\n};" << endl;
	cout << "void g(A a) { a.f(); }\nvoid h(A& a) { a.f(); }" << endl;
	cout << "int main() {\n\tB b;\n\tg(b);\n\th(b);\n\treturn 0;\n}" << endl;
	checkAnswer("AB");
	cout << "Correct answer is: "; question_19s_answer();
	cout << "From the call g(b), A gets printed because of slicing, we did pass by value" << endl;
	cout << "From the call h(b), B gets printed as we did a pass by reference and f() is virtual in a" << endl;
	cout << endl;
}
void question_19s_answer() {
	class A
	{
	public:
		virtual void f() { cout << "A"; }
	};

	class B: public A
	{
	public:
		void f() { cout << "B"; }
	};
	B b;
	{ // similar to void g(A a) { a.f(); }
		A a=b;
		a.f();
	} // similar to void h(A& a) { a.f(); }
	A& a = b;
	a.f();
	cout << endl;
}
void question_18() {
	cout << "Will this code work? " << yesOrNo << endl;
	cout << "\tint errNumb = 0;\n\tint *const curErr = &errNumb;\n\tconst double pi = 3.14159;\n\tconst double *const pip = &pi;" << endl;
	checkAnswer("y");
	cout << "curErr is constant pointer that will always point to errNumb" << endl;
	cout << "pip is a const pointer to a const object; nothing can be changed" << endl;
	cout << endl;
}
void question_17() {
	cout << "Which lines are incorrect?" << endl;
	cout << "1:\tdouble pi = 3.14;\n2:\tconst double cpi = 3.14;\n3:\tdouble *ptr = &pi;" << endl;
	cout << "4:\tdouble *ptr1 = &cpi;\n5:\tconst double *ptr2 = &cpi;\n6:\tconst double *ptr3 = &pi;" << endl;
	cout << "7:\t*ptr3 = 3.0;\n8:\tptr3 = &cpi;\n9:\tconst int *p;" << endl;
	checkAnswer("47");
	cout << "4: error - ptr1 is a plain pointer, cannot keep address of const variable" << endl;
	cout << "5: ok - const pointer to const varable" << endl;
	cout << "6: ok - address of regular variable can be stored in const pointer" << endl;
	cout << "7: error - cannot change value using const pointer \"read-only variable is not assignable\"" <<endl;
	cout << "8: ok - Using const pointers one cannot change the data at address, but one can make " << endl
		 << "        it point to another address" << endl;
	cout << "9: ok - We can have uninitialized pointers to constant" << endl;
	cout << endl;
}
void question_16() {
	cout << "Which lines are incorrect?" << endl;
	cout << "1:\tint l = 42;\n2:\tconst int &r3 = l;\n3:\tconst int &r4 = 42;\n4:\tint &r6 = 2;" << endl;
	checkAnswer("4");
	cout << "2:  const int &r3 = l;  // we can bind a const int& to a plain int object" << endl;
	cout << "3:  const int &r4 = 42; // ok: r4 is a reference to const" << endl;
	cout << "4:  int &r6 = 2;        // error: r6 is a plain, non const reference" << endl;
	cout << endl;
}
void question_15() {
	cout << "Which lines are incorrect?" << endl;
	cout << "1:\tconst int buffSize = 512;\n2:\tbuffSize = 2;\n3:\tconst int i = getOne();\n4:\tconst int j;\n5:\tconst int k = buffSize;" << endl;
	checkAnswer("24");
	cout << "2:  buffSize = 2; //error: cannot assign to variable 'buffSize' with const-qualified type 'const int'" << endl;
	cout << "4:  const int j;  //error: default initialization of an object of const type 'const int'" << endl;
	cout << endl;
}
void question_14() {
    cout << "How many ways are there to create functions with variable arguments?" << endl;
    checkAnswer("2");
    cout << "1. Using initializer_list Parameters: Example" << endl;
    cout << "   void error_msg(int e, initializer_list<string> il) {\n\tcout << e << \": \";" << endl;
    cout << "\tfor (const auto &elem : il)\n\t\tcout << elem << \" \";\n\tcout << endl;\n   }" << endl;
    cout << "   int main() {\n\terror_msg(11, {\"abc\", \"xyz\"});\n   }" << endl;
    cout << "2. Using Ellipsis Parameters: Ellipsis parameters should be used only for types that are common to both C " << endl
    	 <<	"   and C++. In particular, objects of most class types are not copied properly when passed to an ellipsis" << endl
    	 << "   parameter." << endl;
    cout << endl;
}
void question_13() {
	cout << "a.\tint (*matrix)[10];\nb.\tint *matrix[10];" << endl;
	cout << "Which one is \"array of ten pointers\" and which one is \"pointer to an array of ten ints\"?" << " [ab|ba]" << endl;
	checkAnswer("ba");
	cout << "\tint (*matrix)[10]; // pointer to an array of ten ints \n\tint *matrix[10]; //array of ten pointers" << endl;
	cout << endl;
}
void question_12() {
    cout << "Can we change the value of constant variable i, in the way shown below?" << yesOrNo << endl;
    cout << "const int i = 10;\nconst int *pci = &i;\nint *pi = const_cast<int *>(pci);\n*pi = 5;\ncout << i <<endl;" << endl;
    checkAnswer(no);
    cout << "Using a const_cast in order to write to a const object is undefined." << endl;
    cout << "Note, that the above code compiles successfully." << endl;
    cout << endl;
}
void question_11() {
    cout << "How many types of casting are present in C++?" << endl;
    checkAnswer("4");
    cout << "1. static_cast, 2, dynamic_cast, 3. const_cast, and 4. reinterpret_cast" << endl;
    cout << endl;
}
void question_10() {
    cout << "Will this code work? " << yesOrNo << endl;
    cout << "int ia[3][4];\nfor (auto row : ia)\n\tfor (auto col : row)\n\t\tcol = 5;" << endl;
    checkAnswer(no);
    cout << "Compilation error: invalid range expression of type \'int *\'; no viable \'begin\' function available" << endl;
    cout << "Here is the correct code:\nfor (auto &row : ia)\n\tfor (auto &col : row)\n\t\tcol = 5;" << endl;
    cout << "Define the control variable of the outer loop as a reference. We do so in order to avoid the normal array" << endl
    		<< "to pointer conversion. NOTE:To use a multidimensional array in a range for, the loop control variable" << endl
    		<< "for all but the innermost array must be references." << endl;
    cout << endl;
}
void question_09() {
    cout << "for ( auto c : \"Sidd\" )\n\tcout << c << endl;" << endl;
    cout << "Will the code compile? " << yesOrNo << endl;
    checkAnswer(yes);
    cout << "The code will compile and print all characters of the string. This is called a \"Range-based for loop\"" << endl;
    cout << endl;
}
void question_08() {
    cout << "int int_arr[] = {0, 1, 2, 3, 4, 5};\nvector<int> ivec(begin(int_arr), end(int_arr));\ncout<< ivec[5];" << endl
    		<< "What is the output?" << endl;
    checkAnswer("5");
    cout << endl;
}
void question_07() {
    cout << "Is this true?" << yesOrNo << endl;
    cout << "The iterator returned by end() is an iterator positioned “one past the end” of the associated container" << endl <<
    		"(or string). This iterator denotes a nonexistent element “off the end” of the container." << endl;
    checkAnswer(yes);
    cout << endl;
}
void question_06() {
    cout << "vector<string> v8{10, \"hi\"}" << endl
    		<< "Will the code compile?" << yesOrNo << endl;
    checkAnswer(yes);
    cout << "When we use curly braces, {...}, we’re saying that, if possible, we want to list initialize the object. " << endl
    		<< "Only if it is not possible to list initialize the object will the other ways to initialize the object" << endl
    		<< "be considered. In this case it is not possible to list initialize so the vector is initialized with 10" << endl
    		<< "strings having value \"hi\"" << endl;
    cout << endl;
}
void question_05() {
    cout << "vector<int> v3(10, 1)" << endl
    	 << "What is the size of this vector?" << endl;
    checkAnswer("10");
    cout << "The will create an vector of 10 int elements and assign them to 1" << endl;
    cout << endl;
}
void question_04() {
    cout << "vector<int> v4{10, 1}" << endl
         << "What is the size of the vector?" << endl;
    checkAnswer("2");
    cout << "The will create an vector of 2 int elements with value 10 and 1; this method is called list initialization" << endl
         << "The same statement can also be written as: vector<int> v4 = {10, 1} // this is same as v4{10, 1}" << endl;
    cout << endl;
}
void question_03() {
    cout << "Can there be an array of reference?" << yesOrNo << endl;
    checkAnswer(no);
    cout << "References are not objects. They don't have storage of their own, they just reference existing objects." << endl
    	 << "For this reason it doesn't make sense to have arrays of references. Similarly one cannot have vector of" << endl
    	 << "references" << endl;
    cout << endl;
}
void question_02() {
	cout << "Can virtual functions be inlined?" << yesOrNo << endl;
	checkAnswer(no);
	cout << "By default all the functions defined inside the class are implicitly or automatically considered" <<endl;
	cout << "as inline except virtual functions." << endl;
	cout << "Whenever virtual function is called using base class reference or pointer it cannot be inlined " << endl;
	cout << "(because call is resolved at runtime), but whenever called using the object (without reference" << endl;
	cout <<	"or pointer) of that class, can be inlined because compiler knows the exact class of the object" << endl
			<< "at compile time." << endl;
	cout << endl;
}
void question_01() {
	cout << "Can virtual functions be private in C++?" << yesOrNo << endl;
	checkAnswer(yes);
	cout << "In C++, virtual functions can be private and can be overridden by the derived class."<< endl;
	cout << "For example, the following program compiles and runs fine." <<endl;
	cout << "class Base {\nprivate:\n\tvirtual void fun() { cout << \"Base Fun\"; }\n\tfriend int main();\n};" << endl;
    cout << "class Derived: public Base {\npublic:\n\tvoid fun() { cout << \"Derived Fun\"; }\n};" << endl;
    cout << "int main() {\n\tBase *ptr = new Derived;\n\tptr->fun();\n}" << endl;
    cout << "NOTE: As Base class function is private, we are not allowed to call it using Base classes pointer." << endl;
    cout << "As main() is friend of Base, it allowed main to access base classes private method and due to" << endl;
    cout << "virtual C++ executed Derived classes method." << endl;
    cout << endl;
}

